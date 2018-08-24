/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mpcmoveCodeGeneration_mex.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 02-Nov-2017 18:25:03
 */

/* Include Files */
#include "_coder_mpcmoveCodeGeneration_api.h"
#include "_coder_mpcmoveCodeGeneration_mex.h"

/* Function Declarations */
static void c_mpcmoveCodeGeneration_mexFunc(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
static void c_mpcmoveCodeGeneration_mexFunc(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *inputs[3];
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs < 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooFewInputsConstants", 9, 4, 21,
                        "mpcmoveCodeGeneration", 4, 21, "mpcmoveCodeGeneration",
                        4, 21, "mpcmoveCodeGeneration");
  }

  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        21, "mpcmoveCodeGeneration");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "mpcmoveCodeGeneration");
  }

  /* Temporary copy for mex inputs. */
  if (0 <= nrhs - 1) {
    memcpy((void *)&inputs[0], (void *)&prhs[0], (uint32_T)(nrhs * (int32_T)
            sizeof(const mxArray *)));
  }

  /* Call the function. */
  mpcmoveCodeGeneration_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  mpcmoveCodeGeneration_terminate();
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(mpcmoveCodeGeneration_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  mpcmoveCodeGeneration_initialize();

  /* Dispatch the entry-point. */
  c_mpcmoveCodeGeneration_mexFunc(nlhs, plhs, nrhs, prhs);
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_mpcmoveCodeGeneration_mex.c
 *
 * [EOF]
 */
