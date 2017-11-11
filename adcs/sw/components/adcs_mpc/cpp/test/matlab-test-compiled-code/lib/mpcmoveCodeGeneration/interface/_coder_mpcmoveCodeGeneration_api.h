/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mpcmoveCodeGeneration_api.h
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 02-Nov-2017 18:25:03
 */

#ifndef _CODER_MPCMOVECODEGENERATION_API_H
#define _CODER_MPCMOVECODEGENERATION_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_mpcmoveCodeGeneration_api.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T Plant[7];
  real_T LastMove[3];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T ym[7];
  real_T ref[7];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  struct3_T signals;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct7_T
#define typedef_struct7_T

typedef struct {
  real_T Uopt[63];
  real_T Yopt[147];
  real_T Xopt[147];
  real_T Topt[21];
  real_T Slack;
  real_T Iterations;
  char_T QPCode[8];
  real_T Cost;
} struct7_T;

#endif                                 /*typedef_struct7_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void mpcmoveCodeGeneration(struct1_T *mpcmovestate, struct2_T mpcmovedata,
  real_T u[3], struct7_T *Info);
extern void mpcmoveCodeGeneration_api(const mxArray * const prhs[3], const
  mxArray *plhs[3]);
extern void mpcmoveCodeGeneration_atexit(void);
extern void mpcmoveCodeGeneration_initialize(void);
extern void mpcmoveCodeGeneration_terminate(void);
extern void mpcmoveCodeGeneration_xil_terminate(void);

#endif

/*
 * File trailer for _coder_mpcmoveCodeGeneration_api.h
 *
 * [EOF]
 */
