/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sgp4_lib_fsw0.c
 *
 * Code generated for Simulink model 'sgp4_lib_fsw0'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Mar 29 15:15:33 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (8-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "sgp4_lib_fsw0.h"
#define NumBitsPerChar                 8U

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

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
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
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
        y = 1.0;
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

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u0_0;
  int16_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void sgp4_lib_fsw0_step(void)
{
  real_T QOMS4;
  real_T i_o;
  real_T w_o;
  real_T M_o;
  real_T n_o;
  real_T tsince_JD;
  real_T a_1;
  real_T d_1;
  real_T d_o;
  int16_T lowAlt;
  real_T s_star;
  real_T xi;
  real_T b_o;
  real_T eta;
  real_T C_5;
  real_T D_2;
  real_T D_3;
  real_T D_4;
  real_T IL3;
  real_T IL4;
  real_T IL5;
  real_T M_DF;
  real_T d_w;
  real_T d_M;
  boolean_T rEQ0;
  real_T M_idx_0;
  real_T C_1_tmp;
  real_T C_1_tmp_0;
  real_T C_1_tmp_1;
  real_T M_DF_tmp;
  real_T M_DF_tmp_0;
  real_T M_DF_tmp_tmp;
  real_T C_1_tmp_tmp;
  real_T C_1_tmp_2;

  /* MATLAB Function: '<S1>/MATLAB Function' */
  QOMS4 = 1.88027916E-9;
  s_star = 1.01222928;

  /* Outport: '<Root>/SGP4_FLAG' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  rtY.SGP4_FLAG = 0.0;

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Inport: '<Root>/JD_J2000_utc'
   *  Inport: '<Root>/orbit_tle'
   */
  i_o = rtU.orbit_tle[3] * 0.0174532925;
  w_o = rtU.orbit_tle[6] * 0.0174532925;
  M_o = rtU.orbit_tle[7] * 0.0174532925;
  n_o = rtU.orbit_tle[8] * 2.0 * 3.1415926535897931 / 1440.0;
  if ((rtU.orbit_tle[5] >= 1.0) || (rtU.orbit_tle[5] <= 0.0)) {
    w_o = 6378.137;
    IL3 = 0.0;
    d_1 = 6378.137;
    s_star = 0.0;
    QOMS4 = 6878.137;
    i_o = 0.0;

    /* Outport: '<Root>/SGP4_FLAG' */
    rtY.SGP4_FLAG = -1.0;
  } else if (n_o == 0.0) {
    w_o = 6378.137;
    IL3 = 0.0;
    d_1 = 6378.137;
    s_star = 0.0;
    QOMS4 = 6878.137;
    i_o = 0.0;

    /* Outport: '<Root>/SGP4_FLAG' */
    rtY.SGP4_FLAG = -1.0;
  } else {
    tsince_JD = rtU.JD_utc_J2000 - rtU.orbit_tle[1];
    if (fabs(tsince_JD) < 1.0E-8) {
      tsince_JD = 0.0;
    } else {
      if (tsince_JD < 0.0) {
        tsince_JD = 0.0;
      }
    }

    tsince_JD *= 1440.0;
    a_1 = rt_powd_snf(0.0743669161 / n_o, 0.66666666666666663);
    M_idx_0 = cos(i_o);
    d_w = 1.0 - rtU.orbit_tle[5] * rtU.orbit_tle[5];
    d_1 = (M_idx_0 * M_idx_0 * 3.0 - 1.0) / rt_powd_snf(d_w, 1.5) * (0.000541308
      / (a_1 * a_1) * 1.5);
    a_1 *= ((1.0 - 0.33333333333333331 * d_1) - d_1 * d_1) - 1.654320987654321 *
      rt_powd_snf(d_1, 3.0);
    d_o = (M_idx_0 * M_idx_0 * 3.0 - 1.0) / rt_powd_snf(1.0 - rtU.orbit_tle[5] *
      rtU.orbit_tle[5], 1.5) * (0.000541308 / (a_1 * a_1) * 1.5);
    d_1 = n_o / (1.0 + d_o);
    d_o = a_1 / (1.0 - d_o);
    IL3 = (1.0 - rtU.orbit_tle[5]) * d_o;
    n_o = (IL3 - 1.0) * 6378.137;
    if (IL3 < 1.0344928307435228) {
      lowAlt = 1;

      /* Outport: '<Root>/SGP4_FLAG' */
      rtY.SGP4_FLAG = 1.0;
    } else {
      lowAlt = 0;
    }

    if ((n_o >= 98.0) && (n_o <= 156.0)) {
      s_star = (IL3 - 1.01222928) + 1.0;
      QOMS4 = rt_powd_snf(1.0188142770258546 - ((IL3 - 1.01222928) + 1.0), 4.0);
    } else {
      if (n_o < 98.0) {
        QOMS4 = 6.0426196528035638E-8;
        s_star = 1.0031357118857749;
      }
    }

    xi = 1.0 / (d_o - s_star);
    b_o = sqrt(d_w);
    eta = d_o * rtU.orbit_tle[5] * xi;
    if (eta == 1.0) {
      w_o = 6378.137;
      IL3 = 0.0;
      d_1 = 6378.137;
      s_star = 0.0;
      QOMS4 = 6878.137;
      i_o = 0.0;

      /* Outport: '<Root>/SGP4_FLAG' */
      rtY.SGP4_FLAG = -1.0;
    } else {
      C_1_tmp = eta * eta;
      d_M = rt_powd_snf(xi, 4.0);
      C_1_tmp_0 = rt_powd_snf(1.0 - eta * eta, -3.5);
      C_1_tmp_tmp = rt_powd_snf(eta, 3.0);
      C_1_tmp_1 = rtU.orbit_tle[5] * C_1_tmp_tmp;
      C_1_tmp_2 = C_1_tmp * 1.5;
      n_o = ((((C_1_tmp_2 + 1.0) + 4.0 * rtU.orbit_tle[5] * eta) + C_1_tmp_1) *
             d_o + (M_idx_0 * M_idx_0 * 1.5 + -0.5) * (0.00081196200000000006 *
              xi) * ((C_1_tmp * 24.0 + 8.0) + 3.0 * rt_powd_snf(eta, 4.0)) /
             (1.0 - C_1_tmp)) * (QOMS4 * d_M * d_1 * C_1_tmp_0) * rtU.orbit_tle
        [2];
      C_5 = 0.0;
      D_2 = 0.0;
      D_3 = 0.0;
      D_4 = 0.0;
      IL3 = 0.0;
      IL4 = 0.0;
      IL5 = 0.0;
      if (lowAlt == 0) {
        C_5 = 2.0 * QOMS4 * d_M * d_o * (b_o * b_o) * C_1_tmp_0 * ((2.75 * eta *
          (eta + rtU.orbit_tle[5]) + 1.0) + C_1_tmp_1);
        d_w = n_o * n_o;
        D_2 = 4.0 * d_o * xi * d_w;
        IL4 = rt_powd_snf(n_o, 3.0);
        D_3 = 1.3333333333333333 * d_o * (xi * xi) * (17.0 * d_o + s_star) * IL4;
        a_1 = rt_powd_snf(n_o, 4.0);
        D_4 = 0.66666666666666663 * d_o * rt_powd_snf(xi, 3.0) * (221.0 * d_o +
          31.0 * s_star) * a_1;
        IL3 = d_w * 2.0 + D_2;
        IL4 = ((12.0 * n_o * D_2 + 3.0 * D_3) + 10.0 * IL4) * 0.25;
        IL5 = ((((12.0 * n_o * D_3 + 3.0 * D_4) + D_2 * D_2 * 6.0) + d_w * 30.0 *
                D_2) + 15.0 * a_1) * 0.2;
      }

      a_1 = rt_powd_snf(M_idx_0, 4.0);
      M_DF_tmp_tmp = rt_powd_snf(d_o, 4.0);
      M_DF_tmp = 16.0 * M_DF_tmp_tmp;
      s_star = d_o * d_o;
      M_DF_tmp_0 = s_star * 2.0 * rt_powd_snf(b_o, 3.0);
      M_DF = (((M_idx_0 * M_idx_0 * 3.0 - 1.0) * 0.0016239240000000001 /
               M_DF_tmp_0 + 1.0) + ((13.0 - M_idx_0 * M_idx_0 * 78.0) + 137.0 *
               a_1) * 8.7904305259200008E-7 / (M_DF_tmp * rt_powd_snf(b_o, 7.0)))
        * d_1 * tsince_JD + M_o;
      d_w = rt_powd_snf(b_o, 8.0);
      a_1 = ((((7.0 - M_idx_0 * M_idx_0 * 114.0) + 395.0 * a_1) *
              8.7904305259200008E-7 / (M_DF_tmp * d_w) + (1.0 - M_idx_0 *
               M_idx_0 * 5.0) * -0.0016239240000000001 / M_DF_tmp_0) + ((3.0 -
               M_idx_0 * M_idx_0 * 36.0) + 49.0 * a_1) * 3.1049437500000002E-6 /
             (4.0 * M_DF_tmp_tmp * d_w)) * d_1 * tsince_JD + w_o;
      d_w *= 2.0 * M_DF_tmp_tmp;
      M_DF_tmp = tsince_JD * tsince_JD;
      M_DF_tmp_tmp = M_idx_0 * M_idx_0 * 7.0;
      s_star = ((((4.0 * M_idx_0 - 19.0 * rt_powd_snf(M_idx_0, 3.0)) *
                  8.7904305259200008E-7 / d_w + -0.0016239240000000001 * M_idx_0
                  / (s_star * rt_powd_snf(b_o, 4.0))) + (3.0 - M_DF_tmp_tmp) *
                 (3.1049437500000002E-6 * M_idx_0) / d_w) * d_1 * tsince_JD +
                rtU.orbit_tle[4] * 0.0174532925) - d_1 * 0.000541308 * M_idx_0 /
        (s_star * (b_o * b_o)) * 10.5 * n_o * M_DF_tmp;
      if (lowAlt == 0) {
        d_w = QOMS4 * rt_powd_snf(xi, 5.0) * 2.538815E-6 * d_1 * sin(i_o) /
          (0.000541308 * rtU.orbit_tle[5]) * rtU.orbit_tle[2] * cos(w_o) *
          tsince_JD;
        d_M = -0.66666666666666663 * QOMS4 * rtU.orbit_tle[2] * d_M * (1.0 /
          (rtU.orbit_tle[5] * eta)) * (rt_powd_snf(eta * cos(M_DF) + 1.0, 3.0) -
          rt_powd_snf(eta * cos(M_o) + 1.0, 3.0));
        M_DF = (M_DF + d_w) + d_M;
        a_1 = (a_1 - d_w) - d_M;
        QOMS4 = (rtU.orbit_tle[5] - ((((rtU.orbit_tle[5] * eta + 1.0) * (2.0 *
          eta) + 0.5 * rtU.orbit_tle[5]) + 0.5 * rt_powd_snf(eta, 3.0)) -
                  ((((1.0 - eta * eta * 1.5) - 2.0 * rtU.orbit_tle[5] * eta) -
                    0.5 * rtU.orbit_tle[5] * rt_powd_snf(eta, 3.0)) * ((1.0 -
          M_idx_0 * M_idx_0 * 3.0) * 3.0) + ((eta * eta * 2.0 - rtU.orbit_tle[5]
          * eta) - rtU.orbit_tle[5] * rt_powd_snf(eta, 3.0)) * ((1.0 - M_idx_0 *
          M_idx_0) * 0.75) * cos(2.0 * w_o)) * (0.001082616 * xi / ((1.0 - eta *
          eta) * d_o))) * (2.0 * d_1 * QOMS4 * rt_powd_snf(xi, 4.0) * d_o * (b_o
                   * b_o) * C_1_tmp_0) * rtU.orbit_tle[2] * tsince_JD) -
          rtU.orbit_tle[2] * C_5 * (sin(M_DF) - sin(M_o));
        C_5 = rt_powd_snf(tsince_JD, 3.0);
        w_o = rt_powd_snf(tsince_JD, 4.0);
        M_o = (((1.0 - n_o * tsince_JD) - M_DF_tmp * D_2) - D_3 * C_5) - D_4 *
          w_o;
        M_o = M_o * M_o * d_o;
        d_o = (((1.5 * n_o * M_DF_tmp + IL3 * C_5) + IL4 * w_o) + IL5 *
               rt_powd_snf(tsince_JD, 5.0)) * d_1 + ((M_DF + a_1) + s_star);
      } else {
        C_5 = 1.0 - n_o * tsince_JD;
        M_o = C_5 * C_5 * d_o;
        IL3 = rtU.orbit_tle[5] * eta;
        QOMS4 = rtU.orbit_tle[5] - ((((IL3 + 1.0) * (2.0 * eta) + 0.5 *
          rtU.orbit_tle[5]) + 0.5 * C_1_tmp_tmp) - ((((1.0 - C_1_tmp_2) - 2.0 *
          rtU.orbit_tle[5] * eta) - 0.5 * rtU.orbit_tle[5] * C_1_tmp_tmp) *
          ((1.0 - M_idx_0 * M_idx_0 * 3.0) * 3.0) + ((C_1_tmp * 2.0 - IL3) -
          C_1_tmp_1) * ((1.0 - M_idx_0 * M_idx_0) * 0.75) * cos(2.0 * w_o)) *
          (0.001082616 * xi / ((1.0 - eta * eta) * d_o))) * (2.0 * d_1 * QOMS4 *
          d_M * d_o * (b_o * b_o) * C_1_tmp_0) * rtU.orbit_tle[2] * tsince_JD;
        d_o = 1.5 * n_o * d_1 * M_DF_tmp + ((M_DF + a_1) + s_star);
      }

      if ((M_o == 0.0) || (QOMS4 >= 1.0)) {
        w_o = 6378.137;
        IL3 = 0.0;
        d_1 = 6378.137;
        s_star = 0.0;
        QOMS4 = 6878.137;
        i_o = 0.0;

        /* Outport: '<Root>/SGP4_FLAG' */
        rtY.SGP4_FLAG = -1.0;
      } else {
        n_o = sqrt(1.0 - QOMS4 * QOMS4);
        tsince_JD = cos(a_1);
        w_o = QOMS4 * tsince_JD;
        IL3 = n_o * n_o;
        n_o = 2.538815E-6 * sin(i_o);
        d_1 = n_o / (0.002165232 * M_o * IL3) + QOMS4 * sin(a_1);
        QOMS4 = (n_o / (0.004330464 * M_o * IL3) * QOMS4 * tsince_JD * ((5.0 *
                   M_idx_0 + 3.0) / (1.0 + M_idx_0)) + d_o) - s_star;
        if ((!rtIsInf(QOMS4)) && (!rtIsNaN(QOMS4))) {
          if (QOMS4 == 0.0) {
            a_1 = 0.0;
          } else {
            a_1 = fmod(QOMS4, 6.2831853071795862);
            rEQ0 = (a_1 == 0.0);
            if (!rEQ0) {
              d_o = fabs(QOMS4 / 6.2831853071795862);
              rEQ0 = (fabs(d_o - floor(d_o + 0.5)) <= 2.2204460492503131E-16 *
                      d_o);
            }

            if (rEQ0) {
              a_1 = 0.0;
            } else {
              if (QOMS4 < 0.0) {
                a_1 += 6.2831853071795862;
              }
            }
          }
        } else {
          a_1 = (rtNaN);
        }

        d_o = a_1;
        QOMS4 = 0.0;
        lowAlt = 0;
        while ((fabs(d_o - QOMS4) > 1.0E-8) && (lowAlt < 10)) {
          d_o = QOMS4;
          QOMS4 += (((a_1 - d_1 * cos(QOMS4)) + w_o * sin(QOMS4)) - QOMS4) /
            ((-d_1 * sin(QOMS4) - w_o * cos(QOMS4)) + 1.0);
          lowAlt++;
        }

        C_1_tmp = cos(QOMS4);
        d_M = sin(QOMS4);
        n_o = w_o * d_M - d_1 * C_1_tmp;
        IL3 = sqrt(w_o * w_o + d_1 * d_1);
        d_w = 1.0 - IL3 * IL3;
        a_1 = d_w * M_o;
        d_o = (1.0 - (w_o * C_1_tmp + d_1 * d_M)) * M_o;
        if ((d_o == 0.0) || (a_1 == 0.0)) {
          w_o = 6378.137;
          IL3 = 0.0;
          d_1 = 6378.137;
          s_star = 0.0;
          QOMS4 = 6878.137;
          i_o = 0.0;

          /* Outport: '<Root>/SGP4_FLAG' */
          rtY.SGP4_FLAG = -1.0;
        } else {
          d_w = sqrt(d_w);
          IL3 = M_o / d_o;
          d_1 = rt_atan2d_snf(((d_M - d_1) - w_o * n_o / (d_w + 1.0)) * IL3,
                              (d_1 * n_o / (d_w + 1.0) + (C_1_tmp - w_o)) * IL3);
          IL3 = a_1 * a_1;
          xi = cos(2.0 * d_1);
          QOMS4 = (1.0 - d_w * 0.00081196200000000006 * (M_idx_0 * M_idx_0 * 3.0
                    - 1.0) / IL3) * d_o + 0.000541308 / (2.0 * a_1) * (1.0 -
            M_idx_0 * M_idx_0) * xi;
          tsince_JD = sin(2.0 * d_1);
          w_o = -(0.000541308 / (IL3 * 4.0)) * (M_DF_tmp_tmp - 1.0) * tsince_JD
            + d_1;
          d_w = 0.0016239240000000001 * M_idx_0 / (IL3 * 2.0);
          s_star += d_w * tsince_JD;
          IL3 = d_w * sin(i_o) * xi + i_o;
          d_1 = 0.000541308 * (0.0743669161 / rt_powd_snf(M_o, 1.5)) / a_1;
          i_o = -d_1 * (1.0 - M_idx_0 * M_idx_0) * tsince_JD + 0.0743669161 *
            sqrt(M_o) * n_o / d_o;
          n_o = ((1.0 - M_idx_0 * M_idx_0) * xi - (1.0 - M_idx_0 * M_idx_0 * 3.0)
                 * 1.5) * d_1 + 0.0743669161 * sqrt(a_1) / d_o;
          d_1 = cos(IL3);
          M_o = sin(s_star);
          M_idx_0 = -M_o * d_1;
          d_o = cos(s_star);
          tsince_JD = d_o * d_1;
          a_1 = sin(IL3);
          d_w = sin(w_o);
          C_5 = cos(w_o);
          xi = M_idx_0 * d_w + d_o * C_5;
          w_o = QOMS4 * xi * 6378.137;
          IL3 = xi;
          xi = tsince_JD * d_w + M_o * C_5;
          d_1 = QOMS4 * xi * 6378.137;
          s_star = xi;
          xi = a_1 * d_w + 0.0 * C_5;
          QOMS4 = QOMS4 * xi * 6378.137;
          IL3 = ((M_idx_0 * C_5 - d_o * d_w) * n_o + i_o * IL3) *
            106.30228333333334;
          s_star = ((tsince_JD * C_5 - M_o * d_w) * n_o + i_o * s_star) *
            106.30228333333334;
          i_o = ((a_1 * C_5 - 0.0 * d_w) * n_o + i_o * xi) * 106.30228333333334;
        }
      }
    }
  }

  for (lowAlt = 0; lowAlt < 3; lowAlt++) {
    /* Product: '<S1>/Product' incorporates:
     *  Inport: '<Root>/teme_2_eci'
     *  Product: '<S1>/Product1'
     */
    M_o = rtU.teme_to_gcrf[lowAlt + 3];
    M_idx_0 = rtU.teme_to_gcrf[lowAlt + 6];

    /* Outport: '<Root>/pos_eci_m' incorporates:
     *  Gain: '<S1>/Gain'
     *  Inport: '<Root>/teme_2_eci'
     *  Product: '<S1>/Product'
     */
    rtY.pos_eci_m[lowAlt] = 1000.0 * (M_idx_0 * QOMS4 + (M_o * d_1 +
      rtU.teme_to_gcrf[lowAlt] * w_o));

    /* Outport: '<Root>/vel_eci_mps' incorporates:
     *  Gain: '<S1>/Gain1'
     *  Inport: '<Root>/teme_2_eci'
     *  Product: '<S1>/Product1'
     */
    rtY.vel_eci_mps[lowAlt] = 1000.0 * (M_idx_0 * i_o + (M_o * s_star +
      rtU.teme_to_gcrf[lowAlt] * IL3));
  }
}

/* Model initialize function */
void sgp4_lib_fsw0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
