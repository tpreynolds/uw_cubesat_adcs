/*
OAC 	SOC-i Optimal Attitude Control

T. P. Reynolds -- RAIN Lab
*/

#include "OAC.h"

int Q_slerp(double q0[4], double q1[4], double qt[4][N]){
/* Quaternion Spherical Linear Interpolation
	Interpolates between two quaternions and places the result in qt.
*/

// Compute tspan within [ 0 , 1 ]
double tspan[N] = {0};
for (int k = 0; k < N; k++)
{
	tspan[k] = k/(N-1.0);
}

// Find angle between inputs
double ang;
ang = acos(q0[0]*q1[0]+q0[1]*q1[1]+q0[2]*q1[2]+q0[3]*q1[3]);
if( ang > pi ){
    return -1;
}

// perform the interpolation
double sang = sin(ang);
double c1,c2;
for (int k = 0; k < N; k++)
{
	c1 = (sin((1-tspan[k])*ang)/sang);
	c2 = (sin(tspan[k]*ang)/sang);
	for (int i = 0; i < 4; i++)
	{
		qt[i][k] = c1*q0[i] + c2*q1[i];
	}
}
return 0;
}

void rk4(OAC_T *OAC, foh_T *params, double P[Ni][1]){
	/* RK4 numerical integration scheme
		Integrates the quaternion kinematics/dynamics over one sub-interval. 
		Stores the result in P.
	*/
	double tau = (*params).tau_k;
	double h = (*params).dtau/(Nsub-1);
	double k1[Ni][1] = {{0}};
	double k2[Ni][1] = {{0}};
	double k3[Ni][1] = {{0}};
	double k4[Ni][1] = {{0}};
	for (int k = 0; k < N-1; k++)
	{
		derivs(params,tau      ,P         ,k1);
		// derivs(params,tau+0.5*h,P+0.5*h*k1,k2);
		// derivs(params,tau+0.5*h,(*P)+0.5*h*(*k2),k3);
		// derivs(params,tau+h    ,(*P)+h*(*k3)    ,k4);

		tau += h;
		for (int i = 0; i < Ni; i++)
		{
			P[i][0] += (h/6.0)*(k1[i][0]);// + 2.0*k2[0][0]  + 2.0*k3[0][0] + k4[0][0]);
		}
	}
}

void derivs(const foh_T *params, const double tau, const double P[Ni][1], double dP[Ni][1]){

	double lam_min = ((*params).tau_kp1 - tau)/(*params).dtau;
	double lam_plu = (tau - (*params).tau_k)/(*params).dtau;
	double u_tau[3];
	for (int i = 0; i < 3; i++)
	{
		u_tau[i] = lam_min * (*params).u_k[i] + lam_plu * (*params).u_kp1[i];
	}

	for (int i = 0; i < Ni; i++)
	{
		dP[i][0] = 1.0;
	}
}

// void constraint_M(double x[3], double y[3], double amax, double M[4][4]){
// 	M[0][0] = y[0]*x[0] - y[1]*x[1] - y[2]*x[2] - cos(amax) + 2.0;
// 	M[0][1] = y[0]*x[1] + y[1]*x[0];
// 	M[0][2] = y[0]*x[2] + y[2]*x[0];
// 	M[0][3] = y[2]*x[1] - y[1]*x[2]; 
// 	M[1][0] = y[0]*x[1] + y[1]*x[0];
// 	M[1][1] = y[1]*x[1] - y[0]*x[0] - y[2]*x[2] - cos(amax) + 2.0;
// 	M[1][2] = y[1]*x[2] + y[2]*x[1];
// 	M[1][3] = y[0]*x[2] - y[2]*x[0];
// 	M[2][0] = y[0]*x[2] + y[2]*x[0];
// 	M[2][1] = y[1]*x[2] + y[2]*x[1];
// 	M[2][2] = y[2]*x[2] - y[1]*x[1] - y[0]*x[0] - cos(amax) + 2.0;
// 	M[2][3] = y[1]*x[0] - y[0]*x[1];
// 	M[3][0] = y[2]*x[1] - y[1]*x[2];
// 	M[3][1] = y[0]*x[2] - y[2]*x[0];
// 	M[3][2] = y[1]*x[0] - y[0]*x[1];
// 	M[3][3] = y[0]*x[0] + y[1]*x[1] + y[2]*x[2] - cos(amax) + 2.0;
// }