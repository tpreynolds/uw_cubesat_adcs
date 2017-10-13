/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Estimation_EKF.c
 *
 * Code generated for Simulink model 'Estimation_EKF'.
 *
 * Model version                  : 1.147
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Oct 13 16:08:40 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->MSP430
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Estimation_EKF.h"
#define NumBitsPerChar                 8U

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_powd_snf(real_T u0, real_T u1);

/* Forward declaration for local functions */
static void mrdivide(real_T A[36], const real_T B_0[36]);
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
}

/* Function for MATLAB Function: '<S10>/kalman_gain' */
static void mrdivide(real_T A[36], const real_T B_0[36])
{
  int16_T jp;
  real_T temp;
  real_T b_A[36];
  int8_T ipiv[6];
  int16_T j;
  int16_T ix;
  real_T s;
  int16_T c_ix;
  int16_T d;
  int16_T ijA;
  int16_T b_jAcol;
  int16_T b_kBcol;
  memcpy(&b_A[0], &B_0[0], 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    ipiv[j] = (int8_T)(1 + j);
  }

  for (j = 0; j < 5; j++) {
    jp = j * 7;
    b_jAcol = 0;
    ix = jp;
    temp = fabs(b_A[jp]);
    for (b_kBcol = 2; b_kBcol <= 6 - j; b_kBcol++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > temp) {
        b_jAcol = b_kBcol - 1;
        temp = s;
      }
    }

    if (b_A[jp + b_jAcol] != 0.0) {
      if (b_jAcol != 0) {
        ipiv[j] = (int8_T)((j + b_jAcol) + 1);
        ix = j;
        b_jAcol += j;
        for (b_kBcol = 0; b_kBcol < 6; b_kBcol++) {
          temp = b_A[ix];
          b_A[ix] = b_A[b_jAcol];
          b_A[b_jAcol] = temp;
          ix += 6;
          b_jAcol += 6;
        }
      }

      b_jAcol = (jp - j) + 6;
      for (ix = jp + 1; ix + 1 <= b_jAcol; ix++) {
        b_A[ix] /= b_A[jp];
      }
    }

    b_jAcol = jp;
    ix = jp + 6;
    for (b_kBcol = 1; b_kBcol <= 5 - j; b_kBcol++) {
      temp = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = jp + 1;
        d = (b_jAcol - j) + 12;
        for (ijA = 7 + b_jAcol; ijA + 1 <= d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -temp;
          c_ix++;
        }
      }

      ix += 6;
      b_jAcol += 6;
    }
  }

  for (j = 0; j < 6; j++) {
    jp = 6 * j;
    b_jAcol = 6 * j;
    for (ix = 1; ix <= j; ix++) {
      b_kBcol = (ix - 1) * 6;
      if (b_A[(ix + b_jAcol) - 1] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          A[c_ix + jp] -= b_A[(ix + b_jAcol) - 1] * A[c_ix + b_kBcol];
        }
      }
    }

    temp = 1.0 / b_A[j + b_jAcol];
    for (b_jAcol = 0; b_jAcol < 6; b_jAcol++) {
      A[b_jAcol + jp] *= temp;
    }
  }

  for (j = 5; j >= 0; j += -1) {
    jp = 6 * j;
    b_jAcol = 6 * j - 1;
    for (ix = j + 2; ix < 7; ix++) {
      b_kBcol = (ix - 1) * 6;
      if (b_A[ix + b_jAcol] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          A[c_ix + jp] -= b_A[ix + b_jAcol] * A[c_ix + b_kBcol];
        }
      }
    }
  }

  for (j = 4; j >= 0; j += -1) {
    if (j + 1 != ipiv[j]) {
      jp = ipiv[j] - 1;
      for (b_jAcol = 0; b_jAcol < 6; b_jAcol++) {
        temp = A[6 * j + b_jAcol];
        A[b_jAcol + 6 * j] = A[6 * jp + b_jAcol];
        A[b_jAcol + 6 * jp] = temp;
      }
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function for TID0 */
void Estimation_EKF_step0(void)        /* Sample time: [0.1s, 0.0s] */
{
  real_T w_n;
  int8_T Phi_22[9];
  int8_T I[9];
  real_T b;
  real_T c_c;
  static const int8_T a[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T b_a[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T b_0[16] = { 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0
  };

  static const int8_T a_0[16] = { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0
  };

  static const int8_T b_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T rotation_matrix[9];
  real_T scale;
  int16_T k;
  real_T KHI[36];
  int8_T I_0[36];
  real_T rtb_Switch[3];
  real_T rtb_q_min_k1[4];
  real_T rtb_sqrt;
  real_T rtb_Product2_m;
  real_T rtb_body_est[6];
  real_T rtb_MatrixMultiply[6];
  real_T rtb_Merge[4];
  real_T rtb_Merge2[36];
  real_T rtb_K[36];
  real_T rtb_Merge2_0[36];
  int16_T i;
  real_T tmp[6];
  real_T rtb_Merge2_1[36];
  real_T tmp_0[6];
  real_T KHI_0[36];
  real_T rtb_K_0[36];
  real_T rotation_matrix_0[9];
  real_T rotation_matrix_1[9];
  int16_T i_0;
  real_T tmp_1[9];
  real_T scale_0[16];
  real_T a_1[16];
  real_T a_2[16];
  real_T r_idx_1;
  real_T r_idx_2;
  real_T rtb_UnitDelay1_idx_0;
  real_T rtb_UnitDelay1_idx_1;
  real_T rtb_UnitDelay1_idx_2;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.1s, 0.0s] to Sample time: [0.2s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 1) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition: '<S1>/ 11' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    rtDW.u1[0] = rtDW.u1_Buffer0[0];

    /* RateTransition: '<S1>/ 5' */
    rtDW.u[0] = rtDW.u_Buffer0[0];
    rtDW.u1[1] = rtDW.u1_Buffer0[1];

    /* RateTransition: '<S1>/ 5' */
    rtDW.u[1] = rtDW.u_Buffer0[1];
    rtDW.u1[2] = rtDW.u1_Buffer0[2];

    /* RateTransition: '<S1>/ 5' */
    rtDW.u[2] = rtDW.u_Buffer0[2];
  }

  /* End of RateTransition: '<S1>/ 11' */

  /* UnitDelay: '<S1>/Unit Delay1' */
  rtb_UnitDelay1_idx_0 = rtDW.UnitDelay1_DSTATE[0];
  rtb_UnitDelay1_idx_1 = rtDW.UnitDelay1_DSTATE[1];
  rtb_UnitDelay1_idx_2 = rtDW.UnitDelay1_DSTATE[2];

  /* If: '<S4>/If' incorporates:
   *  Inport: '<Root>/valid_mag'
   *  Inport: '<Root>/valid_sun '
   *  Inport: '<S11>/cov_min'
   *  Inport: '<S11>/q_min'
   *  Logic: '<S1>/Logical Operator'
   *  MATLAB Function: '<S10>/update_state '
   *  SignalConversion: '<S10>/OutportBufferForbias_plus'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  if (rtU.valid_mag && rtU.valid_sun) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* MATLAB Function: '<S10>/convert_inertial_body' incorporates:
     *  SignalConversion: '<S12>/TmpSignal ConversionAt SFunction Inport2'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    /* MATLAB Function 'Estimation_EKF /Update Step /If Action Subsystem/convert_inertial_body': '<S12>:1' */
    /* '<S12>:1:3' rotation_matrix = att(q_min); */
    /* '<S12>:1:9' dcm = [q(1)^2 + q(2)^2 - q(3)^2 - q(4)^2,   2*(q(2)*q(3)+q(1)*q(4)),    2*(q(2)*q(4) - q(1)*q(3)); */
    /* '<S12>:1:10'         2*(q(2)*q(3) - q(1)*q(4)),          q(1)^2-q(2)^2+q(3)^2-q(4)^2,    2*(q(3)*q(4) + q(1)*q(2)); */
    /* '<S12>:1:11'         2*(q(2)*q(4)+q(1)*q(3)),            2*(q(3)*q(4)-q(1)*q(2)),        q(1)^2-q(2)^2-q(3)^2+q(4)^2]; */
    rotation_matrix[0] = ((rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[0] +
      rtDW.UnitDelay_DSTATE[1] * rtDW.UnitDelay_DSTATE[1]) -
                          rtDW.UnitDelay_DSTATE[2] * rtDW.UnitDelay_DSTATE[2]) -
      rtDW.UnitDelay_DSTATE[3] * rtDW.UnitDelay_DSTATE[3];
    rotation_matrix[3] = (rtDW.UnitDelay_DSTATE[1] * rtDW.UnitDelay_DSTATE[2] +
                          rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[3]) *
      2.0;
    rotation_matrix[6] = (rtDW.UnitDelay_DSTATE[1] * rtDW.UnitDelay_DSTATE[3] -
                          rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[2]) *
      2.0;
    rotation_matrix[1] = (rtDW.UnitDelay_DSTATE[1] * rtDW.UnitDelay_DSTATE[2] -
                          rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[3]) *
      2.0;
    rotation_matrix[4] = ((rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[0] -
      rtDW.UnitDelay_DSTATE[1] * rtDW.UnitDelay_DSTATE[1]) +
                          rtDW.UnitDelay_DSTATE[2] * rtDW.UnitDelay_DSTATE[2]) -
      rtDW.UnitDelay_DSTATE[3] * rtDW.UnitDelay_DSTATE[3];
    rotation_matrix[7] = (rtDW.UnitDelay_DSTATE[2] * rtDW.UnitDelay_DSTATE[3] +
                          rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[1]) *
      2.0;
    rotation_matrix[2] = (rtDW.UnitDelay_DSTATE[1] * rtDW.UnitDelay_DSTATE[3] +
                          rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[2]) *
      2.0;
    rotation_matrix[5] = (rtDW.UnitDelay_DSTATE[2] * rtDW.UnitDelay_DSTATE[3] -
                          rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[1]) *
      2.0;
    rotation_matrix[8] = ((rtDW.UnitDelay_DSTATE[0] * rtDW.UnitDelay_DSTATE[0] -
      rtDW.UnitDelay_DSTATE[1] * rtDW.UnitDelay_DSTATE[1]) -
                          rtDW.UnitDelay_DSTATE[2] * rtDW.UnitDelay_DSTATE[2]) +
      rtDW.UnitDelay_DSTATE[3] * rtDW.UnitDelay_DSTATE[3];

    /* '<S12>:1:4' body_est = blkdiag(rotation_matrix,rotation_matrix)*meas_eci; */
    memset(&KHI[0], 0, 36U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      KHI[6 * i] = rotation_matrix[3 * i];
      KHI[3 + 6 * (3 + i)] = rotation_matrix[3 * i];
      KHI[1 + 6 * i] = rotation_matrix[3 * i + 1];
      KHI[4 + 6 * (3 + i)] = rotation_matrix[3 * i + 1];
      KHI[2 + 6 * i] = rotation_matrix[3 * i + 2];
      KHI[5 + 6 * (3 + i)] = rotation_matrix[3 * i + 2];

      /* SignalConversion: '<S12>/TmpSignal ConversionAt SFunction Inport2' */
      tmp[i] = rtDW.u[i];
      tmp[i + 3] = rtDW.u1[i];
    }

    for (i = 0; i < 6; i++) {
      rtb_body_est[i] = 0.0;
      for (k = 0; k < 6; k++) {
        rtb_body_est[i] += KHI[6 * k + i] * tmp[k];
      }
    }

    /* End of MATLAB Function: '<S10>/convert_inertial_body' */

    /* MATLAB Function: '<S10>/observation_matrix' */
    /* MATLAB Function 'Estimation_EKF /Update Step /If Action Subsystem/observation_matrix': '<S15>:1' */
    /* '<S15>:1:3' H = [  skew(body_est(1:3))     zeros(3); */
    /* '<S15>:1:4'        skew(body_est(4:6))     zeros(3)]; */
    /* '<S15>:1:9' S = [0  -v(3)   v(2); */
    /* '<S15>:1:10'     v(3)    0   -v(1); */
    /* '<S15>:1:11'     -v(2)   v(1)    0]; */
    /* '<S15>:1:9' S = [0  -v(3)   v(2); */
    /* '<S15>:1:10'     v(3)    0   -v(1); */
    /* '<S15>:1:11'     -v(2)   v(1)    0]; */
    rtb_Merge2[0] = 0.0;
    rtb_Merge2[6] = -rtb_body_est[2];
    rtb_Merge2[12] = rtb_body_est[1];
    rtb_Merge2[1] = rtb_body_est[2];
    rtb_Merge2[7] = 0.0;
    rtb_Merge2[13] = -rtb_body_est[0];
    rtb_Merge2[2] = -rtb_body_est[1];
    rtb_Merge2[8] = rtb_body_est[0];
    rtb_Merge2[14] = 0.0;
    rtb_Merge2[3] = 0.0;
    rtb_Merge2[9] = -rtb_body_est[5];
    rtb_Merge2[15] = rtb_body_est[4];
    rtb_Merge2[4] = rtb_body_est[5];
    rtb_Merge2[10] = 0.0;
    rtb_Merge2[16] = -rtb_body_est[3];
    rtb_Merge2[5] = -rtb_body_est[4];
    rtb_Merge2[11] = rtb_body_est[3];
    rtb_Merge2[17] = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Merge2[6 * (i + 3)] = 0.0;
      rtb_Merge2[3 + 6 * (i + 3)] = 0.0;
      rtb_Merge2[1 + 6 * (i + 3)] = 0.0;
      rtb_Merge2[4 + 6 * (i + 3)] = 0.0;
      rtb_Merge2[2 + 6 * (i + 3)] = 0.0;
      rtb_Merge2[5 + 6 * (i + 3)] = 0.0;
    }

    /* End of MATLAB Function: '<S10>/observation_matrix' */

    /* MATLAB Function: '<S10>/kalman_gain' incorporates:
     *  Inport: '<Root>/meas_cov'
     *  Inport: '<Root>/valid_gyro'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    /* MATLAB Function 'Estimation_EKF /Update Step /If Action Subsystem/kalman_gain': '<S14>:1' */
    /* '<S14>:1:3' K = cov_min*H'/(H*cov_min*H' + meas_cov); */
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 6; k++) {
        rtb_K[i + 6 * k] = 0.0;
        rtb_Merge2_1[i + 6 * k] = 0.0;
        for (i_0 = 0; i_0 < 6; i_0++) {
          rtb_K[i + 6 * k] += rtDW.UnitDelay2_DSTATE[6 * i_0 + i] * rtb_Merge2[6
            * i_0 + k];
          rtb_Merge2_1[i + 6 * k] += rtb_Merge2[6 * i_0 + i] *
            rtDW.UnitDelay2_DSTATE[6 * k + i_0];
        }
      }

      for (k = 0; k < 6; k++) {
        w_n = 0.0;
        for (i_0 = 0; i_0 < 6; i_0++) {
          w_n += rtb_Merge2_1[6 * i_0 + i] * rtb_Merge2[6 * i_0 + k];
        }

        rtb_Merge2_0[i + 6 * k] = rtU.meas_cov[6 * k + i] + w_n;
      }
    }

    mrdivide(rtb_K, rtb_Merge2_0);

    /*  zero off part of gain if gyro reading is invalid */
    /* '<S14>:1:7' if valid_gyro == 0 */
    if (rtU.valid_gyro == 0.0) {
      /* '<S14>:1:8' K(4:6,:) = zeros(3,6); */
      for (i = 0; i < 6; i++) {
        rtb_K[3 + 6 * i] = 0.0;
        rtb_K[4 + 6 * i] = 0.0;
        rtb_K[5 + 6 * i] = 0.0;
      }
    }

    /* End of MATLAB Function: '<S10>/kalman_gain' */

    /* Sum: '<S10>/Sum' incorporates:
     *  Inport: '<Root>/mag_body'
     *  Inport: '<Root>/sun_body'
     *  Product: '<S10>/Matrix Multiply'
     */
    tmp_0[0] = rtU.mag_body[0];
    tmp_0[3] = rtU.sun_body[0];
    tmp_0[1] = rtU.mag_body[1];
    tmp_0[4] = rtU.sun_body[1];
    tmp_0[2] = rtU.mag_body[2];
    tmp_0[5] = rtU.sun_body[2];
    for (i = 0; i < 6; i++) {
      tmp[i] = tmp_0[i] - rtb_body_est[i];
    }

    /* End of Sum: '<S10>/Sum' */

    /* Product: '<S10>/Matrix Multiply' */
    for (i = 0; i < 6; i++) {
      rtb_MatrixMultiply[i] = 0.0;
      for (k = 0; k < 6; k++) {
        rtb_MatrixMultiply[i] += rtb_K[6 * k + i] * tmp[k];
      }
    }

    /* MATLAB Function: '<S10>/update_state ' */
    /*  select out bias */
    /* MATLAB Function 'Estimation_EKF /Update Step /If Action Subsystem/update_state ': '<S16>:1' */
    /* '<S16>:1:5' bias_plu = bias_min + del_x_plu(4:6); */
    /* '<S16>:1:7' q_plu = quat_update(del_x_plu(1:3,1),q_min); */
    /* '<S16>:1:15' q_hat_pk = quat_multiply([sqrt(1 - norm(del_apk/2)^2); del_apk/2], q_hat_mk); */
    scale = 2.2250738585072014E-308;
    rtb_Product2_m = fabs(rtb_MatrixMultiply[0] / 2.0);
    if (rtb_Product2_m > 2.2250738585072014E-308) {
      w_n = 1.0;
      scale = rtb_Product2_m;
    } else {
      rtb_sqrt = rtb_Product2_m / 2.2250738585072014E-308;
      w_n = rtb_sqrt * rtb_sqrt;
    }

    r_idx_1 = rtb_MatrixMultiply[0] / 2.0;
    rtb_UnitDelay1_idx_0 += rtb_MatrixMultiply[3];

    /* MATLAB Function: '<S10>/update_state ' incorporates:
     *  SignalConversion: '<S10>/OutportBufferForbias_plus'
     */
    rtb_Product2_m = fabs(rtb_MatrixMultiply[1] / 2.0);
    if (rtb_Product2_m > scale) {
      rtb_sqrt = scale / rtb_Product2_m;
      w_n = w_n * rtb_sqrt * rtb_sqrt + 1.0;
      scale = rtb_Product2_m;
    } else {
      rtb_sqrt = rtb_Product2_m / scale;
      w_n += rtb_sqrt * rtb_sqrt;
    }

    r_idx_2 = rtb_MatrixMultiply[1] / 2.0;
    rtb_UnitDelay1_idx_1 += rtb_MatrixMultiply[4];

    /* MATLAB Function: '<S10>/update_state ' incorporates:
     *  SignalConversion: '<S10>/OutportBufferForbias_plus'
     */
    rtb_Product2_m = fabs(rtb_MatrixMultiply[2] / 2.0);
    if (rtb_Product2_m > scale) {
      rtb_sqrt = scale / rtb_Product2_m;
      w_n = w_n * rtb_sqrt * rtb_sqrt + 1.0;
      scale = rtb_Product2_m;
    } else {
      rtb_sqrt = rtb_Product2_m / scale;
      w_n += rtb_sqrt * rtb_sqrt;
    }

    rtb_Product2_m = rtb_MatrixMultiply[2] / 2.0;
    rtb_UnitDelay1_idx_2 += rtb_MatrixMultiply[5];

    /* MATLAB Function: '<S10>/update_state ' incorporates:
     *  SignalConversion: '<S10>/OutportBufferForbias_plus'
     */
    w_n = scale * sqrt(w_n);

    /* '<S16>:1:22' q2 = quatmultiply(q1',dq')'; */
    scale = sqrt(1.0 - w_n * w_n);

    /* MATLAB Function: '<S10>/covariance_update' incorporates:
     *  Inport: '<Root>/meas_cov'
     *  UnitDelay: '<S1>/Unit Delay2'
     */
    /* MATLAB Function 'Estimation_EKF /Update Step /If Action Subsystem/covariance_update': '<S13>:1' */
    /* '<S13>:1:4' KHI = (K*H - eye(6)); */
    for (i = 0; i < 36; i++) {
      I_0[i] = 0;
    }

    for (k = 0; k < 6; k++) {
      I_0[k + 6 * k] = 1;
    }

    /* '<S13>:1:5' cov_plus = KHI*cov_min*KHI' + K*meas_cov*K'; */
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 6; k++) {
        w_n = 0.0;
        for (i_0 = 0; i_0 < 6; i_0++) {
          w_n += rtb_K[6 * i_0 + i] * rtb_Merge2[6 * k + i_0];
        }

        KHI[i + 6 * k] = w_n - (real_T)I_0[6 * k + i];
      }

      for (k = 0; k < 6; k++) {
        rtb_Merge2_0[i + 6 * k] = 0.0;
        rtb_Merge2_1[i + 6 * k] = 0.0;
        for (i_0 = 0; i_0 < 6; i_0++) {
          rtb_Merge2_0[i + 6 * k] += KHI[6 * i_0 + i] * rtDW.UnitDelay2_DSTATE[6
            * k + i_0];
          rtb_Merge2_1[i + 6 * k] += rtb_K[6 * i_0 + i] * rtU.meas_cov[6 * k +
            i_0];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (k = 0; k < 6; k++) {
        KHI_0[i + 6 * k] = 0.0;
        rtb_K_0[i + 6 * k] = 0.0;
        for (i_0 = 0; i_0 < 6; i_0++) {
          KHI_0[i + 6 * k] += rtb_Merge2_0[6 * i_0 + i] * KHI[6 * i_0 + k];
          rtb_K_0[i + 6 * k] += rtb_Merge2_1[6 * i_0 + i] * rtb_K[6 * i_0 + k];
        }
      }
    }

    /* SignalConversion: '<S10>/OutportBufferForcov_plus' incorporates:
     *  MATLAB Function: '<S10>/covariance_update'
     */
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 6; k++) {
        rtb_Merge2[k + 6 * i] = KHI_0[6 * i + k] + rtb_K_0[6 * i + k];
      }
    }

    /* End of SignalConversion: '<S10>/OutportBufferForcov_plus' */

    /* SignalConversion: '<S10>/OutportBufferForq_plus' incorporates:
     *  MATLAB Function: '<S10>/update_state '
     *  UnitDelay: '<S1>/Unit Delay'
     */
    rtb_Merge[0] = ((rtDW.UnitDelay_DSTATE[0] * scale - rtDW.UnitDelay_DSTATE[1]
                     * r_idx_1) - rtDW.UnitDelay_DSTATE[2] * r_idx_2) -
      rtDW.UnitDelay_DSTATE[3] * rtb_Product2_m;
    rtb_Merge[1] = (rtDW.UnitDelay_DSTATE[0] * r_idx_1 + scale *
                    rtDW.UnitDelay_DSTATE[1]) + (rtDW.UnitDelay_DSTATE[2] *
      rtb_Product2_m - rtDW.UnitDelay_DSTATE[3] * r_idx_2);
    rtb_Merge[2] = (rtDW.UnitDelay_DSTATE[0] * r_idx_2 + scale *
                    rtDW.UnitDelay_DSTATE[2]) + (rtDW.UnitDelay_DSTATE[3] *
      r_idx_1 - rtDW.UnitDelay_DSTATE[1] * rtb_Product2_m);
    rtb_Merge[3] = (rtDW.UnitDelay_DSTATE[0] * rtb_Product2_m + scale *
                    rtDW.UnitDelay_DSTATE[3]) + (rtDW.UnitDelay_DSTATE[1] *
      r_idx_2 - rtDW.UnitDelay_DSTATE[2] * r_idx_1);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    rtb_Merge[0] = rtDW.UnitDelay_DSTATE[0];
    rtb_Merge[1] = rtDW.UnitDelay_DSTATE[1];
    rtb_Merge[2] = rtDW.UnitDelay_DSTATE[2];
    rtb_Merge[3] = rtDW.UnitDelay_DSTATE[3];
    memcpy(&rtb_Merge2[0], &rtDW.UnitDelay2_DSTATE[0], 36U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
  }

  /* End of If: '<S4>/If' */

  /* Switch: '<S3>/Switch' incorporates:
   *  Inport: '<Root>/valid_gyro'
   *  Inport: '<Root>/w_body_radps'
   *  Sum: '<S3>/Sum'
   */
  if (rtU.valid_gyro >= 0.0) {
    rtb_Switch[0] = rtU.w_body_radps[0] - rtb_UnitDelay1_idx_0;
    rtb_Switch[1] = rtU.w_body_radps[1] - rtb_UnitDelay1_idx_1;
    rtb_Switch[2] = rtU.w_body_radps[2] - rtb_UnitDelay1_idx_2;
  } else {
    rtb_Switch[0] = 0.0;
    rtb_Switch[1] = 0.0;
    rtb_Switch[2] = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* MATLAB Function: '<S3>/state_transition' */
  /* MATLAB Function 'Estimation_EKF /Propagate Step /state_transition': '<S7>:1' */
  /* '<S7>:1:3' Phi = state_transition_matrix(w_plu,dt); */
  /* '<S7>:1:10' w_n = norm(w); */
  scale = 2.2250738585072014E-308;

  /* Outport: '<Root>/w_body_hat_radps' */
  rtY.w_body_hat_radps[0] = rtb_Switch[0];

  /* MATLAB Function: '<S3>/state_transition' */
  rtb_Product2_m = fabs(rtb_Switch[0]);
  if (rtb_Product2_m > 2.2250738585072014E-308) {
    w_n = 1.0;
    scale = rtb_Product2_m;
  } else {
    rtb_sqrt = rtb_Product2_m / 2.2250738585072014E-308;
    w_n = rtb_sqrt * rtb_sqrt;
  }

  /* Outport: '<Root>/w_body_hat_radps' */
  rtY.w_body_hat_radps[1] = rtb_Switch[1];

  /* MATLAB Function: '<S3>/state_transition' */
  rtb_Product2_m = fabs(rtb_Switch[1]);
  if (rtb_Product2_m > scale) {
    rtb_sqrt = scale / rtb_Product2_m;
    w_n = w_n * rtb_sqrt * rtb_sqrt + 1.0;
    scale = rtb_Product2_m;
  } else {
    rtb_sqrt = rtb_Product2_m / scale;
    w_n += rtb_sqrt * rtb_sqrt;
  }

  /* Outport: '<Root>/w_body_hat_radps' */
  rtY.w_body_hat_radps[2] = rtb_Switch[2];

  /* MATLAB Function: '<S3>/state_transition' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_Product2_m = fabs(rtb_Switch[2]);
  if (rtb_Product2_m > scale) {
    rtb_sqrt = scale / rtb_Product2_m;
    w_n = w_n * rtb_sqrt * rtb_sqrt + 1.0;
    scale = rtb_Product2_m;
  } else {
    rtb_sqrt = rtb_Product2_m / scale;
    w_n += rtb_sqrt * rtb_sqrt;
  }

  w_n = scale * sqrt(w_n);

  /* '<S7>:1:11' w_skew = skew(w); */
  /* '<S7>:1:31' S = [0  -v(3)   v(2); */
  /* '<S7>:1:32'     v(3)    0   -v(1); */
  /* '<S7>:1:33'     -v(2)   v(1)    0]; */
  rotation_matrix[0] = 0.0;
  rotation_matrix[3] = -rtb_Switch[2];
  rotation_matrix[6] = rtb_Switch[1];
  rotation_matrix[1] = rtb_Switch[2];
  rotation_matrix[4] = 0.0;
  rotation_matrix[7] = -rtb_Switch[0];
  rotation_matrix[2] = -rtb_Switch[1];
  rotation_matrix[5] = rtb_Switch[0];
  rotation_matrix[8] = 0.0;

  /* '<S7>:1:13' if w_n < 1e-14 */
  if (w_n < 1.0E-14) {
    /* '<S7>:1:14' phi = [ eye(3) -eye(3)*dt; */
    /* '<S7>:1:15'             zeros(3,3) eye(3)]; */
    memset(&rotation_matrix[0], 0, 9U * sizeof(real_T));
    for (i = 0; i < 9; i++) {
      I[i] = 0;
    }

    I[0] = 1;
    I[4] = 1;
    I[8] = 1;
    for (k = 0; k < 3; k++) {
      rotation_matrix[k + 3 * k] = 1.0;
      rtb_K[6 * k] = I[3 * k];
      rtb_K[6 * (k + 3)] = (real_T)a[3 * k] * 0.1;
      rtb_K[3 + 6 * k] = 0.0;
      rtb_K[1 + 6 * k] = I[3 * k + 1];
      rtb_K[1 + 6 * (k + 3)] = (real_T)a[3 * k + 1] * 0.1;
      rtb_K[4 + 6 * k] = 0.0;
      rtb_K[2 + 6 * k] = I[3 * k + 2];
      rtb_K[2 + 6 * (k + 3)] = (real_T)a[3 * k + 2] * 0.1;
      rtb_K[5 + 6 * k] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      rtb_K[3 + 6 * (i + 3)] = rotation_matrix[3 * i];
      rtb_K[4 + 6 * (i + 3)] = rotation_matrix[3 * i + 1];
      rtb_K[5 + 6 * (i + 3)] = rotation_matrix[3 * i + 2];
    }
  } else {
    /* '<S7>:1:16' else */
    /* '<S7>:1:17' Phi_11 = eye(3) - w_skew*sin(w_n*dt)/w_n + w_skew^2*(1 - cos(w_n*dt))/w_n^2; */
    for (i = 0; i < 9; i++) {
      I[i] = 0;
      Phi_22[i] = 0;
    }

    I[0] = 1;
    I[4] = 1;
    I[8] = 1;
    scale = sin(w_n * 0.1);
    rtb_Product2_m = cos(w_n * 0.1);
    rtb_sqrt = w_n * w_n;

    /* '<S7>:1:19' Phi_12 = w_skew*(1 - cos(w_n*dt))/w_n^2 - eye(3)*dt - w_skew^2*(w_n*dt - sin(w_n*dt))/w_n^3; */
    r_idx_1 = cos(w_n * 0.1);
    r_idx_2 = w_n * w_n;
    b = w_n * 0.1 - sin(w_n * 0.1);
    c_c = rt_powd_snf(w_n, 3.0);

    /* '<S7>:1:21' Phi_21 = zeros(3,3); */
    /* '<S7>:1:23' Phi_22 = eye(3); */
    /* '<S7>:1:25' phi = [ Phi_11 Phi_12; */
    /* '<S7>:1:26'             Phi_21 Phi_22]; */
    for (k = 0; k < 3; k++) {
      Phi_22[k + 3 * k] = 1;
      for (i = 0; i < 3; i++) {
        rotation_matrix_0[k + 3 * i] = 0.0;
        rotation_matrix_1[k + 3 * i] = 0.0;
        rotation_matrix_0[k + 3 * i] += rotation_matrix[3 * i] *
          rotation_matrix[k];
        rotation_matrix_1[k + 3 * i] += rotation_matrix[3 * i] *
          rotation_matrix[k];
        rotation_matrix_0[k + 3 * i] += rotation_matrix[3 * i + 1] *
          rotation_matrix[k + 3];
        rotation_matrix_1[k + 3 * i] += rotation_matrix[3 * i + 1] *
          rotation_matrix[k + 3];
        rotation_matrix_0[k + 3 * i] += rotation_matrix[3 * i + 2] *
          rotation_matrix[k + 6];
        rotation_matrix_1[k + 3 * i] += rotation_matrix[3 * i + 2] *
          rotation_matrix[k + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      rtb_K[6 * i] = ((real_T)I[3 * i] - rotation_matrix[3 * i] * scale / w_n) +
        rotation_matrix_0[3 * i] * (1.0 - rtb_Product2_m) / rtb_sqrt;
      rtb_K[6 * (i + 3)] = (rotation_matrix[3 * i] * (1.0 - r_idx_1) / r_idx_2 -
                            (real_T)b_a[3 * i] * 0.1) - rotation_matrix_1[3 * i]
        * b / c_c;
      rtb_K[3 + 6 * i] = 0.0;
      rtb_K[3 + 6 * (i + 3)] = Phi_22[3 * i];
      rtb_K[1 + 6 * i] = ((real_T)I[3 * i + 1] - rotation_matrix[3 * i + 1] *
                          scale / w_n) + rotation_matrix_0[3 * i + 1] * (1.0 -
        rtb_Product2_m) / rtb_sqrt;
      rtb_K[1 + 6 * (i + 3)] = (rotation_matrix[3 * i + 1] * (1.0 - r_idx_1) /
        r_idx_2 - (real_T)b_a[3 * i + 1] * 0.1) - rotation_matrix_1[3 * i + 1] *
        b / c_c;
      rtb_K[4 + 6 * i] = 0.0;
      rtb_K[4 + 6 * (i + 3)] = Phi_22[3 * i + 1];
      rtb_K[2 + 6 * i] = ((real_T)I[3 * i + 2] - rotation_matrix[3 * i + 2] *
                          scale / w_n) + rotation_matrix_0[3 * i + 2] * (1.0 -
        rtb_Product2_m) / rtb_sqrt;
      rtb_K[2 + 6 * (i + 3)] = (rotation_matrix[3 * i + 2] * (1.0 - r_idx_1) /
        r_idx_2 - (real_T)b_a[3 * i + 2] * 0.1) - rotation_matrix_1[3 * i + 2] *
        b / c_c;
      rtb_K[5 + 6 * i] = 0.0;
      rtb_K[5 + 6 * (i + 3)] = Phi_22[3 * i + 2];
    }
  }

  /* Product: '<S3>/Product' incorporates:
   *  Math: '<S3>/Math Function'
   */
  for (i = 0; i < 6; i++) {
    for (k = 0; k < 6; k++) {
      rtb_Merge2_0[i + 6 * k] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        rtb_Merge2_0[i + 6 * k] += rtb_Merge2[6 * i_0 + i] * rtb_K[6 * i_0 + k];
      }
    }
  }

  /* Sum: '<S3>/Add' incorporates:
   *  Product: '<S3>/Product'
   */
  for (i = 0; i < 6; i++) {
    for (k = 0; k < 6; k++) {
      w_n = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        w_n += rtb_K[6 * i_0 + k] * rtb_Merge2_0[6 * i + i_0];
      }

      rtb_Merge2[k + 6 * i] = rtConstB.Product1[6 * i + k] + w_n;
    }
  }

  /* End of Sum: '<S3>/Add' */

  /* MATLAB Function: '<S3>/propagate_quat' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  /* MATLAB Function 'Estimation_EKF /Propagate Step /propagate_quat': '<S6>:1' */
  /* '<S6>:1:3' q_min_k1 = omega_matrix(w_plu,dt)*q_plu; */
  /* '<S6>:1:8' w_n = norm(w); */
  scale = 2.2250738585072014E-308;
  rtb_Product2_m = fabs(rtb_Switch[0]);
  if (rtb_Product2_m > 2.2250738585072014E-308) {
    w_n = 1.0;
    scale = rtb_Product2_m;
  } else {
    rtb_sqrt = rtb_Product2_m / 2.2250738585072014E-308;
    w_n = rtb_sqrt * rtb_sqrt;
  }

  rtb_Product2_m = fabs(rtb_Switch[1]);
  if (rtb_Product2_m > scale) {
    rtb_sqrt = scale / rtb_Product2_m;
    w_n = w_n * rtb_sqrt * rtb_sqrt + 1.0;
    scale = rtb_Product2_m;
  } else {
    rtb_sqrt = rtb_Product2_m / scale;
    w_n += rtb_sqrt * rtb_sqrt;
  }

  rtb_Product2_m = fabs(rtb_Switch[2]);
  if (rtb_Product2_m > scale) {
    rtb_sqrt = scale / rtb_Product2_m;
    w_n = w_n * rtb_sqrt * rtb_sqrt + 1.0;
    scale = rtb_Product2_m;
  } else {
    rtb_sqrt = rtb_Product2_m / scale;
    w_n += rtb_sqrt * rtb_sqrt;
  }

  w_n = scale * sqrt(w_n);

  /* '<S6>:1:10' if w_n < 1e-14 */
  if (w_n < 1.0E-14) {
    /* '<S6>:1:11' Psi = 0*w; */
    rtb_Switch[0] *= 0.0;
    rtb_Switch[1] *= 0.0;
    rtb_Switch[2] *= 0.0;
  } else {
    /* '<S6>:1:12' else */
    /* '<S6>:1:13' Psi = sin(1/2*w_n*dt)/w_n*w; */
    scale = sin(0.5 * w_n * 0.1) / w_n;
    rtb_Switch[0] *= scale;
    rtb_Switch[1] *= scale;
    rtb_Switch[2] *= scale;
  }

  /* '<S6>:1:16' Psi_skew = skew(Psi); */
  /* '<S6>:1:28' S = [0  -v(3)   v(2); */
  /* '<S6>:1:29'     v(3)    0   -v(1); */
  /* '<S6>:1:30'     -v(2)   v(1)    0]; */
  /* '<S6>:1:18' omega = [cos(1/2*w_n*dt)*eye(3) - Psi_skew      Psi; */
  /* '<S6>:1:19'         -Psi'                                   cos(1/2*w_n*dt)]; */
  scale = cos(0.5 * w_n * 0.1);

  /* '<S6>:1:21' T = [zeros(3,1) eye(3); */
  /* '<S6>:1:22'     1       zeros(1,3)]; */
  /* '<S6>:1:24' omega = T'*omega*T; */
  tmp_1[0] = 0.0;
  tmp_1[3] = -rtb_Switch[2];
  tmp_1[6] = rtb_Switch[1];
  tmp_1[1] = rtb_Switch[2];
  tmp_1[4] = 0.0;
  tmp_1[7] = -rtb_Switch[0];
  tmp_1[2] = -rtb_Switch[1];
  tmp_1[5] = rtb_Switch[0];
  tmp_1[8] = 0.0;
  for (i = 0; i < 3; i++) {
    scale_0[i << 2] = (real_T)b_b[3 * i] * scale - tmp_1[3 * i];
    scale_0[1 + (i << 2)] = (real_T)b_b[3 * i + 1] * scale - tmp_1[3 * i + 1];
    scale_0[2 + (i << 2)] = (real_T)b_b[3 * i + 2] * scale - tmp_1[3 * i + 2];
    scale_0[12 + i] = rtb_Switch[i];
    scale_0[3 + (i << 2)] = -rtb_Switch[i];
  }

  scale_0[15] = cos(0.5 * w_n * 0.1);
  for (i = 0; i < 4; i++) {
    for (k = 0; k < 4; k++) {
      a_1[i + (k << 2)] = 0.0;
      a_1[i + (k << 2)] += scale_0[k << 2] * (real_T)a_0[i];
      a_1[i + (k << 2)] += scale_0[(k << 2) + 1] * (real_T)a_0[i + 4];
      a_1[i + (k << 2)] += scale_0[(k << 2) + 2] * (real_T)a_0[i + 8];
      a_1[i + (k << 2)] += scale_0[(k << 2) + 3] * (real_T)a_0[i + 12];
    }

    rtb_q_min_k1[i] = 0.0;
    for (k = 0; k < 4; k++) {
      a_2[i + (k << 2)] = 0.0;
      a_2[i + (k << 2)] += (real_T)b_0[k << 2] * a_1[i];
      a_2[i + (k << 2)] += (real_T)b_0[(k << 2) + 1] * a_1[i + 4];
      a_2[i + (k << 2)] += (real_T)b_0[(k << 2) + 2] * a_1[i + 8];
      a_2[i + (k << 2)] += (real_T)b_0[(k << 2) + 3] * a_1[i + 12];
      rtb_q_min_k1[i] += a_2[(k << 2) + i] * rtb_Merge[k];
    }
  }

  /* End of MATLAB Function: '<S3>/propagate_quat' */

  /* Sqrt: '<S8>/sqrt' incorporates:
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   *  Sum: '<S9>/Sum'
   */
  rtb_sqrt = sqrt(((rtb_q_min_k1[0] * rtb_q_min_k1[0] + rtb_q_min_k1[1] *
                    rtb_q_min_k1[1]) + rtb_q_min_k1[2] * rtb_q_min_k1[2]) +
                  rtb_q_min_k1[3] * rtb_q_min_k1[3]);

  /* Product: '<S5>/Product' */
  w_n = rtb_q_min_k1[0] / rtb_sqrt;

  /* Product: '<S5>/Product1' */
  scale = rtb_q_min_k1[1] / rtb_sqrt;

  /* Product: '<S5>/Product2' */
  rtb_Product2_m = rtb_q_min_k1[2] / rtb_sqrt;

  /* Product: '<S5>/Product3' */
  rtb_sqrt = rtb_q_min_k1[3] / rtb_sqrt;

  /* Outport: '<Root>/quat_hat' */
  rtY.quat_hat[0] = w_n;
  rtY.quat_hat[1] = scale;
  rtY.quat_hat[2] = rtb_Product2_m;
  rtY.quat_hat[3] = rtb_sqrt;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  /* MATLAB Function 'Estimation_EKF /3_sig_bnd ': '<S2>:1' */
  /* '<S2>:1:3' bnd = cov; */
  rtDW.UnitDelay_DSTATE[0] = w_n;
  rtDW.UnitDelay_DSTATE[1] = scale;
  rtDW.UnitDelay_DSTATE[2] = rtb_Product2_m;
  rtDW.UnitDelay_DSTATE[3] = rtb_sqrt;

  /* Outport: '<Root>/bias_hat' */
  rtY.bias_hat[0] = rtb_UnitDelay1_idx_0;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[0] = rtb_UnitDelay1_idx_0;

  /* Outport: '<Root>/bias_hat' */
  rtY.bias_hat[1] = rtb_UnitDelay1_idx_1;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[1] = rtb_UnitDelay1_idx_1;

  /* Outport: '<Root>/bias_hat' */
  rtY.bias_hat[2] = rtb_UnitDelay1_idx_2;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[2] = rtb_UnitDelay1_idx_2;

  /* Outport: '<Root>/3sigma' incorporates:
   *  MATLAB Function: '<S1>/3_sig_bnd '
   */
  memcpy(&rtY.usigma[0], &rtb_Merge2[0], 36U * sizeof(real_T));

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  memcpy(&rtDW.UnitDelay2_DSTATE[0], &rtb_Merge2[0], 36U * sizeof(real_T));
}

/* Model step function for TID1 */
void Estimation_EKF_step1(void)        /* Sample time: [0.2s, 0.0s] */
{
  /* Update for RateTransition: '<S1>/ 11' incorporates:
   *  Update for Inport: '<Root>/sun_eci_est'
   */
  rtDW.u1_Buffer0[0] = rtU.sc2sun_unit[0];
  rtDW.u1_Buffer0[1] = rtU.sc2sun_unit[1];
  rtDW.u1_Buffer0[2] = rtU.sc2sun_unit[2];

  /* Update for RateTransition: '<S1>/ 5' incorporates:
   *  Update for Inport: '<Root>/mag_eci_est'
   */
  rtDW.u_Buffer0[0] = rtU.mag_eci_est[0];
  rtDW.u_Buffer0[1] = rtU.mag_eci_est[1];
  rtDW.u_Buffer0[2] = rtU.mag_eci_est[2];
}

/* Model initialize function */
void Estimation_EKF_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  rtDW.UnitDelay_DSTATE[0] = 1.0;
  rtDW.UnitDelay_DSTATE[1] = 0.0;
  rtDW.UnitDelay_DSTATE[2] = 0.0;
  rtDW.UnitDelay_DSTATE[3] = 0.0;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
  memcpy(&rtDW.UnitDelay2_DSTATE[0], &rtConstP.UnitDelay2_InitialCondition[0],
         36U * sizeof(real_T));
}

/* Model terminate function */
void Estimation_EKF_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
