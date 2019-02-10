/*
DQPDG 	Dual Quaternion Powered Descent Guidance

T. P. Reynolds -- RAIN Lab
*/
#include "stdint.h"
#include "stdio.h"
#include <math.h>

#ifdef NAN
/* NaN is supported */
#endif

#define pi 3.1415926536

enum sizes{N=10, Nx=7, Nq=4, Nw=3, Nu=3, Nt=N*(3*Nx+Nu)+1, Ni=Nx+Nx*Nx+Nx*Nu+Nx*Nu+Nx+Nx, Nsub=15};
enum ids{id_x=0, id_u=N*Nx, id_s=id_u+N*Nu, id_v=id_s+1, id_ev=id_v+N*Nx};

typedef int bool;
enum { false, true };

typedef struct {
	double t0;
	double tf;
	double x[Nx][N];
	double u[Nu][N];
	uint8_t slv_status;
	bool feasible;
} sol_T;

typedef struct {
	double J[3][3];
	double T_max;
	double w_max;
	double s_min;
	double s_max;
	double ME[4][4];
	double w_vc;
	sol_T sol;
	double EH[N*Nx][N*Nx];
	double BE[N*Nx][N*Nu];
	double ES[N*Nx][1];
	double AR[N*Nx][1];
} OAC_T;

typedef struct {
	double q0[4];
	double w0[3];
	double qf[4];
	double wf[3];
	double ME[4][4];
} input_T;

typedef struct {
	double c[1][Nt];
	double A[Nx*(N+2)][Nt];
	double b[Nx*(N+2)][1];
	double G[262][Nt];
	double h[262][1];
} my_ecos_T;

typedef struct {
	double u_k[3];
	double u_kp1[3];
	double tau_k;
	double tau_kp1;
	double dtau;
} foh_T;


void printOACinfo(OAC_T OAC, int flag);
int init_OAC(OAC_T *OAC, input_T *input);
// void constraint_M(double x[3], double y[3], double amax, double M[4][4]);
int Q_slerp(double q0[4], double q1[4], double qt[4][N]);
void foh(OAC_T *OAC);
void rk4(OAC_T *OAC, foh_T *params, double P[Ni][1]);
void derivs(const foh_T *params, const double tau, const double P[Ni][1], double dP[Ni][1]);
