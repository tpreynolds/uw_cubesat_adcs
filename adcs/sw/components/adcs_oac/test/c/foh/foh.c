/*
 * File : timestwo.c
 * Abstract:
 *       An example C-file S-function for multiplying an input by 2,
 *       y  = 2*u
 *
 * Simulink Coder note:
 *   This file can be used as is (noninlined) with Simulink Coder
 *   C rapid prototyping targets, or it can be inlined using the Target 
 *   Language Compiler technology and used with any target. See 
 *     matlabroot/toolbox/simulink/simdemos/simfeatures/tlc_c/timestwo.tlc   
 *   the TLC code to inline the S-function.
 *
 * Copyright 1990-2013 The MathWorks, Inc.
 */


#define S_FUNCTION_NAME  foh
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

enum Sizes {N=2, Nx=2, Nu=2};

static void rk4(real_T y, const real_T u);

/*================*
 * Build checking *
 *================*/


/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

	int_T nInputPorts = 1;
	int_T nOutputPorts = 2;
	int_T needsInput = 1;

	/* Register the number and type of states the S-Function uses */
    ssSetNumContStates(S, 0);   /* number of continuous states */
    ssSetNumDiscStates(S, 0);   /* number of discrete states */

    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    if (!ssSetNumInputPorts(S, nInputPorts)) return;
    ssSetInputPortWidth(S, 0, 1);
    // ssSetInputPortMatrixDimensions(S, 0, 2, 2);
    ssSetInputPortDirectFeedThrough(S, 0, 1); // if you need the input in mdlOutputs

    if (!ssSetNumOutputPorts(S,nOutputPorts)) return;
    ssSetOutputPortWidth(S, 0, 1);
    // ssSetOutputPortMatrixDimensions(S, 0, 2, 2);
    ssSetOutputPortWidth(S, 1, 1);
    ssSetNumSampleTimes(S, 1);

    /* specify the sim state compliance to be same as a built-in block */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    ssSetOptions(S,
                 SS_OPTION_WORKS_WITH_CODE_REUSE |
                 SS_OPTION_EXCEPTION_FREE_CODE |
                 SS_OPTION_USE_TLC_WITH_ACCELERATOR);
}


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy that we inherit our sample time from the driving block.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
    ssSetModelReferenceSampleTimeDefaultInheritance(S); 
}

/* Function: mdlOutputs =======================================================
 * Abstract:
 *    y = 2*u
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    int_T             i;
    int_T 			  j;
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,0);
    real_T            *y    = ssGetOutputPortRealSignal(S,0);
    real_T 			  *flag = ssGetOutputPortRealSignal(S,1);
    int_T             width = ssGetOutputPortWidth(S,0);

    for (i=0; i<width; i++) {
        /*
         * This example does not implement complex signal handling.
         * To find out see an example about how to handle complex signal in 
         * S-function, see sdotproduct.c for details.
         */
    	// y[i] = 2.0 * (*uPtrs[i]); 
    	rk4(y[i],(*uPtrs[i]));
    }
    flag[0] = 0;
}

static void rk4(real_T y, const real_T u)
{
	y = 2.0 * u;
  // double tau  = param.tauk;
  
  // vNIx1 k1 = vNIx1::Zero();
  // vNIx1 k2 = vNIx1::Zero();
  // vNIx1 k3 = vNIx1::Zero();
  // vNIx1 k4 = vNIx1::Zero();

  // for (uint32_t k=0; k<Nsub-1; ++k)
  // {
  //   derivs(param,tau            ,X               ,k1);
  //   derivs(param,tau+0.5*param.h,X+0.5*param.h*k1,k2);
  //   derivs(param,tau+0.5*param.h,X+0.5*param.h*k2,k3);
  //   derivs(param,tau+    param.h,X+    param.h*k3,k4);
    
  //   tau += param.h;
  //   X += (param.h/6.0)*(k1+2.0*k2+2.0*k3+k4);
  // }
}


/* Function: mdlTerminate =====================================================
 * Abstract:
 *    No termination needed, but we are required to have this routine.
 */
static void mdlTerminate(SimStruct *S)
{
}



#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif

