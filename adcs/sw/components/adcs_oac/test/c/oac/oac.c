/*
DQPDG 	Dual Quaternion Powered Descent Guidance

T. P. Reynolds -- RAIN Lab
*/

#include <stdio.h>
#include "OAC.h"

void printOACinfo(OAC_T OAC, int flag)
{
   // print results of the simulation
   printf("%d\n",flag);
}

int init_OAC(OAC_T *OAC, input_T *input){

	// constraint parameters
	(*OAC).s_min = 4.0;  	// s
	(*OAC).s_max = 10.0; 	// s
	(*OAC).T_max = 0.01; 	// Nm
	(*OAC).w_max = 0.3; 	// rad/s
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			(*OAC).ME[i][j] = (*input).ME[i][j];
		}
	}

	// inertia matrix [kg m2]
	(*OAC).J[0][0] = 0.0338;
	(*OAC).J[0][1] = -0.00004884;
	(*OAC).J[0][2] = -0.00007393;
	(*OAC).J[1][0] = -0.00004884;
	(*OAC).J[1][1] = 0.0346;
	(*OAC).J[1][2] = 0.000007124;
	(*OAC).J[2][0] = -0.00007393;
	(*OAC).J[2][1] = 0.000007124;
	(*OAC).J[2][2] = 0.0075;

	// algorithm weights
	(*OAC).w_vc = 100;

	// linearized matrices
	for (int i = 0; i < Nx; i++)
	{
		for (int j = 0; j < Nx; j++)
		{
			if (i==j)
			{
				(*OAC).EH[i][j] = 1.0;
			} 
		}
	}

	// initial guess
	double q_interp[4][N];
	int flag;
	flag = Q_slerp((*input).q0,(*input).qf,q_interp);
	if (flag!=0)
	{
		return -1;
	}
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < Nq; i++)
		{
			(*OAC).sol.x[i][k] = q_interp[i][k];
		}
		(*OAC).sol.x[4][k] = 0.0;
		(*OAC).sol.x[5][k] = 0.0;
		(*OAC).sol.x[6][k] = 0.0;
		(*OAC).sol.u[0][k] = 0.0;
		(*OAC).sol.u[1][k] = 0.0;
		(*OAC).sol.u[2][k] = 0.0;
	}
	return 0;
} // end init_OAC

void my_init_ecos(OAC_T *OAC, my_ecos_T *my_ecos){
	
	double Hx[N*Nx][Nt] = {{0}};
	double Hw[N*3][Nt] = {{0}};
	double Hu[N*Nu][Nt] = {{0}};
	double Hv[N*Nx][Nt] = {{0}};
	double Hs[1][Nt] = {{0}};
	double Hev[N*Nx][Nt] = {{0}};
	// need to finish filling these up!

	// for (int i = 0; i < SIZE ; ++i)
	// {
 //  	  	eye[i][i] = 1;
	// }
} // end my_init_ecos

void foh(OAC_T *OAC){
	// write foh!
	foh_T params;
	double P0[Ni][1];
	// set initial condition
	for (int i = 0; i < Nx; i++)
	{
		P0[Nx+Nx*i][0] = 1.0; 
	}
	params.dtau = 1.0/(N-1.0);
	params.tau_k = 0.0;
	params.tau_kp1 = params.dtau;

	// main loop
	for (int k = 0; k < N-1; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			params.u_k[i] = (*OAC).sol.u[i][k];
			params.u_kp1[i] = (*OAC).sol.u[i][k+1];
		}
		rk4(OAC,&params,P0);
	}

	// write to outputs
	for (int i = 0; i < Nx; i++)
	{
		for (int j = 0; j < Nx; j++)
		{
			(*OAC).EH[i][j] = P0[i][0];
		}
	}

}