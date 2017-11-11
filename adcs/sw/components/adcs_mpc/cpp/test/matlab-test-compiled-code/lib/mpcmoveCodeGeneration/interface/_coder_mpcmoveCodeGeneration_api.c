/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mpcmoveCodeGeneration_api.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 02-Nov-2017 18:25:03
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_mpcmoveCodeGeneration_api.h"
#include "_coder_mpcmoveCodeGeneration_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "mpcmoveCodeGeneration",             /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static const mxArray *b_emlrt_marshallOut(const struct1_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7]);
static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const struct7_T *
  u);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *mpcmovestate,
  const char_T *identifier, struct1_T *y);
static const mxArray *emlrt_marshallOut(const real_T u[3]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *mpcmovedata,
  const char_T *identifier, struct2_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7]);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : void
 */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct1_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[6] = { "Plant", "Disturbance", "Noise",
    "LastMove", "Covariance", "iA" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 6, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Plant";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "Plant")),
                     &thisId, y->Plant);
  thisId.fIdentifier = "Disturbance";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "Disturbance")), &thisId);
  thisId.fIdentifier = "Noise";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "Noise")),
                     &thisId);
  thisId.fIdentifier = "LastMove";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "LastMove")),
                     &thisId, y->LastMove);
  thisId.fIdentifier = "Covariance";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "Covariance")), &thisId);
  thisId.fIdentifier = "iA";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "iA")),
                     &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const struct1_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const struct1_T *u)
{
  const mxArray *y;
  static const char * sv0[6] = { "Plant", "Disturbance", "Noise", "LastMove",
    "Covariance", "iA" };

  const mxArray *b_y;
  const mxArray *m1;
  static const int32_T iv2[1] = { 7 };

  real_T *pData;
  int32_T i;
  static const int32_T iv3[1] = { 0 };

  static const int32_T iv4[1] = { 0 };

  static const int32_T iv5[1] = { 3 };

  static const int32_T iv6[2] = { 0, 0 };

  static const int32_T iv7[1] = { 0 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 6, sv0));
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, iv2, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m1);
  for (i = 0; i < 7; i++) {
    pData[i] = u->Plant[i];
  }

  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "Plant", b_y, 0);
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, iv3, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "Disturbance", b_y, 1);
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, iv4, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "Noise", b_y, 2);
  b_y = NULL;
  m1 = emlrtCreateNumericArray(1, iv5, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)emlrtMxGetPr(m1);
  for (i = 0; i < 3; i++) {
    pData[i] = u->LastMove[i];
  }

  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "LastMove", b_y, 3);
  b_y = NULL;
  m1 = emlrtCreateNumericArray(2, iv6, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "Covariance", b_y, 4);
  b_y = NULL;
  m1 = emlrtCreateLogicalArray(1, iv7);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "iA", b_y, 5);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[7]
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7])
{
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const struct7_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const struct7_T *
  u)
{
  const mxArray *y;
  static const char * sv1[8] = { "Uopt", "Yopt", "Xopt", "Topt", "Slack",
    "Iterations", "QPCode", "Cost" };

  const mxArray *b_y;
  const mxArray *m2;
  static const int32_T iv8[2] = { 21, 3 };

  real_T (*pData)[63];
  int32_T i;
  int32_T b_i;
  static const int32_T iv9[2] = { 21, 7 };

  real_T (*b_pData)[147];
  static const int32_T iv10[2] = { 21, 7 };

  static const int32_T iv11[1] = { 21 };

  real_T *c_pData;
  char_T b_u[8];
  static const int32_T iv12[2] = { 1, 8 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, sv1));
  b_y = NULL;
  m2 = emlrtCreateNumericArray(2, iv8, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T (*)[63])emlrtMxGetPr(m2);
  for (i = 0; i < 3; i++) {
    for (b_i = 0; b_i < 21; b_i++) {
      (*pData)[b_i + 21 * i] = u->Uopt[b_i + 21 * i];
    }
  }

  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "Uopt", b_y, 0);
  b_y = NULL;
  m2 = emlrtCreateNumericArray(2, iv9, mxDOUBLE_CLASS, mxREAL);
  b_pData = (real_T (*)[147])emlrtMxGetPr(m2);
  for (i = 0; i < 7; i++) {
    for (b_i = 0; b_i < 21; b_i++) {
      (*b_pData)[b_i + 21 * i] = u->Yopt[b_i + 21 * i];
    }
  }

  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "Yopt", b_y, 1);
  b_y = NULL;
  m2 = emlrtCreateNumericArray(2, iv10, mxDOUBLE_CLASS, mxREAL);
  b_pData = (real_T (*)[147])emlrtMxGetPr(m2);
  for (i = 0; i < 7; i++) {
    for (b_i = 0; b_i < 21; b_i++) {
      (*b_pData)[b_i + 21 * i] = u->Xopt[b_i + 21 * i];
    }
  }

  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "Xopt", b_y, 2);
  b_y = NULL;
  m2 = emlrtCreateNumericArray(1, iv11, mxDOUBLE_CLASS, mxREAL);
  c_pData = (real_T *)emlrtMxGetPr(m2);
  for (i = 0; i < 21; i++) {
    c_pData[i] = u->Topt[i];
  }

  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "Topt", b_y, 3);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(u->Slack);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "Slack", b_y, 4);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(u->Iterations);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "Iterations", b_y, 5);
  for (i = 0; i < 8; i++) {
    b_u[i] = u->QPCode[i];
  }

  b_y = NULL;
  m2 = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 8, m2, &b_u[0]);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "QPCode", b_y, 6);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(u->Cost);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "Cost", b_y, 7);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[3]
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *mpcmovestate
 *                const char_T *identifier
 *                struct1_T *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *mpcmovestate,
  const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(mpcmovestate), &thisId, y);
  emlrtDestroyArray(&mpcmovestate);
}

/*
 * Arguments    : const real_T u[3]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[3])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  static const int32_T iv1[1] = { 3 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv1, 1);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *mpcmovedata
 *                const char_T *identifier
 *                struct2_T *y
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *mpcmovedata,
  const char_T *identifier, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  i_emlrt_marshallIn(sp, emlrtAlias(mpcmovedata), &thisId, y);
  emlrtDestroyArray(&mpcmovedata);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct2_T *y
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[4] = { "signals", "weights", "limits",
    "customconstraints" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 4, fieldNames, 0U, &dims);
  thisId.fIdentifier = "signals";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "signals")),
                     &thisId, &y->signals);
  thisId.fIdentifier = "weights";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "weights")),
                     &thisId);
  thisId.fIdentifier = "limits";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "limits")),
                     &thisId);
  thisId.fIdentifier = "customconstraints";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "customconstraints")), &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct3_T *y
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[5] = { "ym", "ref", "md", "mvTarget",
    "externalMV" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, &dims);
  thisId.fIdentifier = "ym";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "ym")),
                     &thisId, y->ym);
  thisId.fIdentifier = "ref";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "ref")),
                     &thisId, y->ref);
  thisId.fIdentifier = "md";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "md")),
                     &thisId);
  thisId.fIdentifier = "mvTarget";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "mvTarget")),
                     &thisId);
  thisId.fIdentifier = "externalMV";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "externalMV")), &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[7]
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[7])
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[4] = { "y", "u", "du", "ecr" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 4, fieldNames, 0U, &dims);
  thisId.fIdentifier = "y";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "y")),
                     &thisId);
  thisId.fIdentifier = "u";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "u")),
                     &thisId);
  thisId.fIdentifier = "du";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "du")),
                     &thisId);
  thisId.fIdentifier = "ecr";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "ecr")),
                     &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[4] = { "ymin", "ymax", "umin", "umax" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 4, fieldNames, 0U, &dims);
  thisId.fIdentifier = "ymin";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "ymin")),
                     &thisId);
  thisId.fIdentifier = "ymax";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "ymax")),
                     &thisId);
  thisId.fIdentifier = "umin";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "umin")),
                     &thisId);
  thisId.fIdentifier = "umax";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "umax")),
                     &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[4] = { "E", "F", "G", "S" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 4, fieldNames, 0U, &dims);
  thisId.fIdentifier = "E";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "E")),
                     &thisId);
  thisId.fIdentifier = "F";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "F")),
                     &thisId);
  thisId.fIdentifier = "G";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "G")),
                     &thisId);
  thisId.fIdentifier = "S";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "S")),
                     &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[7]
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7])
{
  static const int32_T dims[1] = { 7 };

  int32_T i0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  for (i0 = 0; i0 < 7; i0++) {
    ret[i0] = (*(real_T (*)[7])emlrtMxGetData(src))[i0];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : void
 */
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[1] = { 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[3]
 * Return Type  : void
 */
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims[1] = { 3 };

  int32_T i1;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  for (i1 = 0; i1 < 3; i1++) {
    ret[i1] = (*(real_T (*)[3])emlrtMxGetData(src))[i1];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : void
 */
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : void
 */
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[1] = { 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 1U, dims);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[7]
 * Return Type  : void
 */
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[7])
{
  static const int32_T dims[2] = { 1, 7 };

  int32_T i2;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  for (i2 = 0; i2 < 7; i2++) {
    ret[i2] = (*(real_T (*)[7])emlrtMxGetData(src))[i2];
  }

  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : void
 */
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 1, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : void
 */
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void mpcmoveCodeGeneration_api(const mxArray * const prhs[3], const mxArray
  *plhs[3])
{
  real_T (*u)[3];
  static const uint32_T mpcmovestruct[4] = { 229955587U, 1417024330U,
    2419312324U, 2394178202U };

  struct1_T mpcmovestate;
  struct2_T mpcmovedata;
  struct7_T Info;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  u = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));

  /* Check constant function inputs */
  emlrtCheckArrayChecksumR2014a(&st, "mpcmovestruct", mpcmovestruct, prhs[0],
    false);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "mpcmovestate", &mpcmovestate);
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "mpcmovedata", &mpcmovedata);

  /* Invoke the target function */
  mpcmoveCodeGeneration(&mpcmovestate, mpcmovedata, *u, &Info);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*u);
  plhs[1] = b_emlrt_marshallOut(&mpcmovestate);
  plhs[2] = c_emlrt_marshallOut(&st, &Info);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void mpcmoveCodeGeneration_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  mpcmoveCodeGeneration_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void mpcmoveCodeGeneration_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void mpcmoveCodeGeneration_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_mpcmoveCodeGeneration_api.c
 *
 * [EOF]
 */
