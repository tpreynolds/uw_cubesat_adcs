/* 
PREAMBLE
*/

#define S_FUNCTION_NAME test
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include "../../../c/ecos/include/ecos.h"

static void mdlInitializeSizes(SimStruct *S)
{
	ssSetNumSFcnParams(S,0);
	if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
		return; // error check
	}

	if (!ssSetNumInputPorts(S,1)) return;
	ssSetInputPortWidth(S,0,DYNAMICALLY_SIZED);
	// ssSetInputPortWidth(S,1,1); // n
	// ssSetInputPortWidth(S,2,1); // m
	// ssSetInputPortWidth(S,3,1); // p
	// ssSetInputPortWidth(S,4,1); // l
	// ssSetInputPortWidth(S,5,1); // ncones
	// ssSetInputPortWidth(S,6,3); // q
	// ssSetInputPortWidth(S,7,1); // e
	// ssSetInputPortWidth(S,8,DYNAMICALLY_SIZED); // Gpr
	// ssSetInputPortWidth(S,9,DYNAMICALLY_SIZED); // Gjc
	// ssSetInputPortWidth(S,10,DYNAMICALLY_SIZED); // Gir
	// ssSetInputPortWidth(S,11,DYNAMICALLY_SIZED); // Apr
	// ssSetInputPortWidth(S,12,DYNAMICALLY_SIZED); // Ajc
	// ssSetInputPortWidth(S,13,DYNAMICALLY_SIZED); // Air
	// ssSetInputPortWidth(S,14,DYNAMICALLY_SIZED); // c
	// ssSetInputPortWidth(S,15,DYNAMICALLY_SIZED); // h
	// ssSetInputPortWidth(S,16,DYNAMICALLY_SIZED); // b
	ssSetInputPortDirectFeedThrough(S,0,1);

	if (!ssSetNumOutputPorts(S,2)) return;
	ssSetOutputPortWidth(S,0,DYNAMICALLY_SIZED);
	ssSetOutputPortWidth(S,1,1);
	ssSetNumSampleTimes(S,1);

	ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
	ssSetSampleTime(S,0,INHERITED_SAMPLE_TIME);
	ssSetOffsetTime(S,0,0.0);
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
	/* Pointers to input singals */
	// InputRealPtrsType nPtr = ssGetInputPortRealSignalPtrs(S,1);
	// InputRealPtrsType mPtr = ssGetInputPortRealSignalPtrs(S,2);
	// InputRealPtrsType pPtr = ssGetInputPortRealSignalPtrs(S,3);
	// InputRealPtrsType lPtr = ssGetInputPortRealSignalPtrs(S,4);
	// InputRealPtrsType nconesPtr = ssGetInputPortRealSignalPtrs(S,5);
	// InputRealPtrsType qPtr = ssGetInputPortRealSignalPtrs(S,6);
	// InputRealPtrsType ePtr = ssGetInputPortRealSignalPtrs(S,7);
	// InputRealPtrsType GprPtr = ssGetInputPortRealSignalPtrs(S,8);
	// InputRealPtrsType GjcPtr = ssGetInputPortRealSignalPtrs(S,9);
	// InputRealPtrsType GirPtr = ssGetInputPortRealSignalPtrs(S,10);
	// InputRealPtrsType AprPtr = ssGetInputPortRealSignalPtrs(S,11);
	// InputRealPtrsType AjcPtr = ssGetInputPortRealSignalPtrs(S,12);
	// InputRealPtrsType AirPtr = ssGetInputPortRealSignalPtrs(S,13);
	// InputRealPtrsType cPtr = ssGetInputPortRealSignalPtrs(S,14);
	// InputRealPtrsType hPtr = ssGetInputPortRealSignalPtrs(S,15);
	// InputRealPtrsType bPtr = ssGetInputPortRealSignalPtrs(S,16);

	/* Declare and fill ecos variables */
	idxint n = 0;
	idxint m = 0;
	idxint p = 0;
	idxint l = 0;
	idxint ncones = 0;
	idxint e = 0;
	pfloat *c = NULL;
	idxint *Gjc = NULL;
	idxint *Gir = NULL;
	pfloat *Gpr = NULL;
	pfloat *h = NULL;
	idxint *q = NULL;
	idxint *Ajc = NULL;
	idxint *Air = NULL;
	pfloat *Apr = NULL;
	pfloat *b = NULL;

	// idxint n = 2;
	// idxint m = 3;
	// idxint p = 2;
	// idxint l = 3;
	// idxint ncones = 0;
	// idxint e = 0;
	// pfloat c[2] = {1.0,1.0};
	// idxint Gjc[3] = {0,2,4};
	// idxint Gir[4] = {0,2,1,2};
	// pfloat Gpr[4] = {1.0,1.0,1.0,1.0};
	// pfloat h[3] = {5.0,5.0,7.0};
	// idxint *q = NULL;
	// idxint Ajc[3] = {0,2,4};
	// idxint Air[4] = {0,1,0,1};
	// pfloat Apr[4]= {2.0,-1.0,1.0,3.0};
	// pfloat b[2] = {4.0,5.0};

	// pfloat *c_p[2];
	// idxint *Gjc_p[3];
	// idxint *Gir_p[4];
	// pfloat *Gpr_p[4];
	// pfloat *h_p[3];
	// // idxint *q_p;
	// idxint *Ajc_p[3];
	// idxint *Air_p[4];
	// pfloat *Apr_p[4];
	// pfloat *b_p[2];

	// c_p[0] = &c[0];
	// c_p[1] = &c[1];
	// Gjc_p[0] = &Gjc[0];
	// Gjc_p[1] = &Gjc[1];
	// Gjc_p[2] = &Gjc[2];
	// Gir_p[0] = &Gir[0];
	// Gir_p[1] = &Gir[1];
	// Gir_p[2] = &Gir[2];
	// Gir_p[3] = &Gir[3];
	// Gpr_p[0] = &Gpr[0];
	// Gpr_p[1] = &Gpr[1];
	// Gpr_p[2] = &Gpr[2];
	// Gpr_p[3] = &Gpr[3];
	// h_p[0] = &h[0];
	// h_p[1] = &h[1];
	// h_p[2] = &h[2];
	// // q_p = &q;
	// Ajc_p[0] = &Ajc[0];
	// Ajc_p[1] = &Ajc[1];
	// Ajc_p[2] = &Ajc[2];
	// Air_p[0] = &Air[0];
	// Air_p[1] = &Air[1];
	// Air_p[2] = &Air[2];
	// Apr_p[0] = &Apr[0];
	// Apr_p[1] = &Apr[1];
	// Apr_p[2] = &Apr[2];
	// Apr_p[3] = &Apr[3];
	// b_p[0] = &b[0];
	// b_p[1] = &b[1];
 
	pwork *mywork;
	idxint exitflag;
 
	/* set up data */
	mywork = ECOS_setup(n, m, p, l, ncones, q, e, Gpr, Gjc, Gir, Apr, Ajc, Air, c, h, b);
	// mywork = ECOS_setup(n, m, p, l, ncones, q, e, Gpr_p, Gjc_p, Gir_p, Apr_p, Ajc_p, Air_p, c_p, h_p, b_p);

	/* solve */
	if ( mywork != NULL )
	{
		exitflag = ECOS_solve(mywork); 
	} else {
		exitflag = ECOS_FATAL;
	}
 
	/* clean up memory */
	ECOS_cleanup(mywork, 0);

	int_T i;
	InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,0);
	real_T *y = ssGetOutputPortRealSignal(S,0);
	real_T *exitcode = ssGetOutputPortRealSignal(S,1);
	int_T width = ssGetOutputPortWidth(S,0);

	for (int i = 0; i < width; i++)
	{
		*y++ = 2.0 * (*uPtrs[i]);
	}
	*exitcode = exitflag;
}

static void mdlTerminate(SimStruct *S)
{

}

#ifdef MATLAB_MEX_FILE 
#include "simulink.c"
#else
#include "cg_sfun.h"
#endif

