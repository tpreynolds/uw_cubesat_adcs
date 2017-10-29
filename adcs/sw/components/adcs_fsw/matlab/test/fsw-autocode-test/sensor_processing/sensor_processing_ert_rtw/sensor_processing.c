/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sensor_processing.c
 *
 * Code generated for Simulink model 'sensor_processing'.
 *
 * Model version                  : 1.173
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sat Oct 28 15:31:19 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->MSP430
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "sensor_processing.h"
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
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);

/* Forward declaration for local functions */
static real_T norm(const real_T x[3]);
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
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
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

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static real_T norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
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

/* Model step function for TID0 */
void sensor_processing_step0(void)     /* Sample time: [0.01s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void sensor_processing_step1(void)     /* Sample time: [0.02s, 0.0s] */
{
  int16_T i;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.02s, 0.0s] to Sample time: [0.1s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID1_3)++;
  if ((rtM->Timing.RateInteraction.TID1_3) > 4) {
    rtM->Timing.RateInteraction.TID1_3 = 0;
  }

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.02s, 0.0s] to Sample time: [0.5s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID1_5)++;
  if ((rtM->Timing.RateInteraction.TID1_5) > 24) {
    rtM->Timing.RateInteraction.TID1_5 = 0;
  }

  /* RateTransition: '<S1>/Rate Transition9' incorporates:
   *  Inport: '<Root>/omega_radps_gyro'
   */
  if (rtM->Timing.RateInteraction.TID1_3 == 1) {
    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/Constant1'
     *  Inport: '<Root>/omega_radps_gyro'
     *  Sum: '<S3>/Sum'
     */
    for (i = 0; i < 3; i++) {
      rtDW.RateTransition9[i] = rtConstP.pooled1[i + 6] * rtU.omega_radps_gyro[2]
        + (rtConstP.pooled1[i + 3] * rtU.omega_radps_gyro[1] +
           rtConstP.pooled1[i] * rtU.omega_radps_gyro[0]);
    }

    /* End of Product: '<S3>/Product' */
    rtDW.RateTransition9[3] = rtU.omega_radps_gyro[3];
  }

  /* End of RateTransition: '<S1>/Rate Transition9' */

  /* RateTransition: '<S1>/Rate Transition2' incorporates:
   *  Inport: '<Root>/mag_body_T'
   */
  rtDW.RateTransition2_Buffer[(rtDW.RateTransition2_semaphoreTaken == 0) << 2] =
    rtU.mag_body_T[0];
  rtDW.RateTransition2_Buffer[1 + ((rtDW.RateTransition2_semaphoreTaken == 0) <<
    2)] = rtU.mag_body_T[1];
  rtDW.RateTransition2_Buffer[2 + ((rtDW.RateTransition2_semaphoreTaken == 0) <<
    2)] = rtU.mag_body_T[2];
  rtDW.RateTransition2_Buffer[3 + ((rtDW.RateTransition2_semaphoreTaken == 0) <<
    2)] = rtU.mag_body_T[3];
  rtDW.RateTransition2_ActiveBufIdx = (int8_T)
    (rtDW.RateTransition2_semaphoreTaken == 0);

  /* RateTransition: '<S1>/Rate Transition1' incorporates:
   *  Inport: '<Root>/sun_body_unit_sunsensor'
   */
  if (rtM->Timing.RateInteraction.TID1_3 == 1) {
    rtDW.RateTransition1[0] = rtU.sun_body_unit_sunsensor[0];
    rtDW.RateTransition1[1] = rtU.sun_body_unit_sunsensor[1];
    rtDW.RateTransition1[2] = rtU.sun_body_unit_sunsensor[2];
    rtDW.RateTransition1[3] = rtU.sun_body_unit_sunsensor[3];
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */

  /* RateTransition: '<S1>/Rate Transition' incorporates:
   *  Inport: '<Root>/sun_body_unit_photodiode'
   */
  if (rtM->Timing.RateInteraction.TID1_5 == 1) {
    rtDW.RateTransition[0] = rtU.sun_body_unit_photodiode[0];
    rtDW.RateTransition[1] = rtU.sun_body_unit_photodiode[1];
    rtDW.RateTransition[2] = rtU.sun_body_unit_photodiode[2];
  }

  /* End of RateTransition: '<S1>/Rate Transition' */
}

/* Model step function for TID2 */
void sensor_processing_step2(void)     /* Sample time: [0.05s, 0.0s] */
{
  int16_T tmp;
  int16_T i;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.05s, 0.0s] to Sample time: [0.1s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID2_3)++;
  if ((rtM->Timing.RateInteraction.TID2_3) > 1) {
    rtM->Timing.RateInteraction.TID2_3 = 0;
  }

  /* RateTransition: '<S1>/Rate Transition2' */
  rtDW.RateTransition2_semaphoreTaken = rtDW.RateTransition2_ActiveBufIdx;

  /* RateTransition: '<S1>/Rate Transition6' incorporates:
   *  RateTransition: '<S1>/Rate Transition2'
   */
  if (rtM->Timing.RateInteraction.TID2_3 == 1) {
    /* RateTransition: '<S1>/Rate Transition2' */
    tmp = rtDW.RateTransition2_ActiveBufIdx << 2;

    /* Product: '<S4>/Product' incorporates:
     *  Constant: '<S4>/Constant1'
     *  RateTransition: '<S1>/Rate Transition2'
     *  Sum: '<S4>/Sum'
     */
    for (i = 0; i < 3; i++) {
      rtDW.RateTransition6[i] = rtConstP.pooled1[i + 6] *
        rtDW.RateTransition2_Buffer[2 + tmp] + (rtConstP.pooled1[i + 3] *
        rtDW.RateTransition2_Buffer[1 + tmp] + rtConstP.pooled1[i] *
        rtDW.RateTransition2_Buffer[tmp]);
    }

    /* End of Product: '<S4>/Product' */
    rtDW.RateTransition6[3] = rtDW.RateTransition2_Buffer
      [(rtDW.RateTransition2_ActiveBufIdx << 2) + 3];
  }

  /* End of RateTransition: '<S1>/Rate Transition6' */
}

/* Model step function for TID3 */
void sensor_processing_step3(void)     /* Sample time: [0.1s, 0.0s] */
{
  int16_T i;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.1s, 0.0s] to Sample time: [0.5s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID3_5)++;
  if ((rtM->Timing.RateInteraction.TID3_5) > 4) {
    rtM->Timing.RateInteraction.TID3_5 = 0;
  }

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.1s, 0.0s] to Sample time: [1.0s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID3_6)++;
  if ((rtM->Timing.RateInteraction.TID3_6) > 9) {
    rtM->Timing.RateInteraction.TID3_6 = 0;
  }

  /* Outport: '<Root>/omega_radps' */
  rtY.omega_radps[0] = rtDW.RateTransition9[0];

  /* Outport: '<Root>/mag_body_Tb' */
  rtY.mag_body_Tb[0] = rtDW.RateTransition6[0];

  /* Outport: '<Root>/omega_radps' */
  rtY.omega_radps[1] = rtDW.RateTransition9[1];

  /* Outport: '<Root>/mag_body_Tb' */
  rtY.mag_body_Tb[1] = rtDW.RateTransition6[1];

  /* Outport: '<Root>/omega_radps' */
  rtY.omega_radps[2] = rtDW.RateTransition9[2];

  /* Outport: '<Root>/mag_body_Tb' */
  rtY.mag_body_Tb[2] = rtDW.RateTransition6[2];

  /* Outport: '<Root>/omega_radps' */
  rtY.omega_radps[3] = rtDW.RateTransition9[3];

  /* Outport: '<Root>/mag_body_Tb' */
  rtY.mag_body_Tb[3] = rtDW.RateTransition6[3];

  /* RateTransition: '<S1>/Rate Transition7' */
  if (rtM->Timing.RateInteraction.TID3_6 == 1) {
    memcpy(&rtDW.RateTransition7[0], &rtDW.RateTransition7_Buffer0[0], 9U *
           sizeof(real_T));
  }

  /* End of RateTransition: '<S1>/Rate Transition7' */
  for (i = 0; i < 3; i++) {
    /* Outport: '<Root>/sun_body_sunsensor' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Product: '<S6>/Product'
     *  Sum: '<S6>/Sum'
     */
    rtY.sun_body_sunsensor[i] = rtConstP.pooled1[i + 6] * rtDW.RateTransition1[2]
      + (rtConstP.pooled1[i + 3] * rtDW.RateTransition1[1] + rtConstP.pooled1[i]
         * rtDW.RateTransition1[0]);
  }

  /* Outport: '<Root>/sun_body_sunsensor' */
  rtY.sun_body_sunsensor[3] = rtDW.RateTransition1[3];

  /* Outport: '<Root>/orbit_tle' */
  memcpy(&rtY.orbit_tle[0], &rtDW.RateTransition7[0], 9U * sizeof(real_T));

  /* RateTransition: '<S1>/Rate Transition5' */
  if (rtM->Timing.RateInteraction.TID3_5 == 1) {
    rtDW.RateTransition5[0] = rtDW.RateTransition5_Buffer0[0];
    rtDW.RateTransition5[1] = rtDW.RateTransition5_Buffer0[1];
    rtDW.RateTransition5[2] = rtDW.RateTransition5_Buffer0[2];
  }

  /* End of RateTransition: '<S1>/Rate Transition5' */

  /* RateTransition: '<S1>/Rate Transition8' */
  if (rtM->Timing.RateInteraction.TID3_6 == 1) {
    rtDW.RateTransition8[0] = rtDW.RateTransition8_Buffer0[0];
    rtDW.RateTransition8[1] = rtDW.RateTransition8_Buffer0[1];
  }

  /* End of RateTransition: '<S1>/Rate Transition8' */

  /* Outport: '<Root>/cur_gps_time' */
  rtY.cur_gps_time[0] = rtDW.RateTransition8[0];
  rtY.cur_gps_time[1] = rtDW.RateTransition8[1];

  /* Outport: '<Root>/sc-face-in-sun_body_unit' */
  rtY.scfaceinsun_body_unit[0] = rtDW.RateTransition5[0];
  rtY.scfaceinsun_body_unit[1] = rtDW.RateTransition5[1];
  rtY.scfaceinsun_body_unit[2] = rtDW.RateTransition5[2];
}

/* Model step function for TID4 */
void sensor_processing_step4(void)     /* Sample time: [0.2s, 0.0s] */
{
  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.2s, 0.0s] to Sample time: [1.0s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID4_6)++;
  if ((rtM->Timing.RateInteraction.TID4_6) > 4) {
    rtM->Timing.RateInteraction.TID4_6 = 0;
  }

  /* RateTransition: '<S1>/Rate Transition3' incorporates:
   *  Inport: '<Root>/GPS'
   */
  if (rtM->Timing.RateInteraction.TID4_6 == 1) {
    memcpy(&rtDW.RateTransition3[0], &rtU.GPS[0], 9U * sizeof(real_T));
  }

  /* End of RateTransition: '<S1>/Rate Transition3' */
}

/* Model step function for TID5 */
void sensor_processing_step5(void)     /* Sample time: [0.5s, 0.0s] */
{
  real_T dot_prods[5];
  real_T mtmp;
  int16_T itmp;
  int16_T ixstart;
  int16_T ix;
  static const int8_T body_vecs[15] = { 1, 0, 0, -1, 0, 0, 1, 0, 0, -1, 0, 0, 1,
    0, 0 };

  int8_T rtb_sc_face_in_sun[3];
  boolean_T exitg1;

  /* MATLAB Function: '<S5>/MATLAB Function' */
  /* MATLAB Function 'photodiode_processing_lib/MATLAB Function': '<S16>:1' */
  /* '<S16>:1:3' body_vecs   = [ 1  0  0; */
  /* '<S16>:1:4'                 0  1  0; */
  /* '<S16>:1:5'                 0  0  1; */
  /* '<S16>:1:6'                -1  0  0; */
  /* '<S16>:1:7'                 0 -1  0 ]; */
  /* '<S16>:1:9' num_faces = 5; */
  /* '<S16>:1:10' dot_prods   = zeros(1,5); */
  /* '<S16>:1:12' for i = 1:num_faces */
  for (ixstart = 0; ixstart < 5; ixstart++) {
    /* '<S16>:1:13' dot_prods(i)    = dot(sun_body_unit,body_vecs(i,:)); */
    dot_prods[ixstart] = ((real_T)body_vecs[ixstart + 5] * rtDW.RateTransition[1]
                          + rtDW.RateTransition[0] * (real_T)body_vecs[ixstart])
      + (real_T)body_vecs[ixstart + 10] * rtDW.RateTransition[2];
  }

  /* '<S16>:1:16' [val,axis] = max(dot_prods); */
  ixstart = 1;
  mtmp = dot_prods[0];
  itmp = 0;
  if (rtIsNaN(dot_prods[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 6)) {
      ixstart = ix;
      if (!rtIsNaN(dot_prods[ix - 1])) {
        mtmp = dot_prods[ix - 1];
        itmp = ix - 1;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 5) {
    while (ixstart + 1 < 6) {
      if (dot_prods[ixstart] > mtmp) {
        mtmp = dot_prods[ixstart];
        itmp = ixstart;
      }

      ixstart++;
    }
  }

  /* '<S16>:1:18' if val < 0 */
  if (mtmp < 0.0) {
    /*  this is only the case if the PPT is pointing right at the sun */
    /* '<S16>:1:20' sc_face_in_sun = [ 0 0 -1 ]'; */
    rtb_sc_face_in_sun[0] = 0;
    rtb_sc_face_in_sun[1] = 0;
    rtb_sc_face_in_sun[2] = -1;
  } else {
    /* '<S16>:1:21' else */
    /* '<S16>:1:22' sc_face_in_sun  = body_vecs(axis,:)'; */
    rtb_sc_face_in_sun[0] = body_vecs[itmp];
    rtb_sc_face_in_sun[1] = body_vecs[itmp + 5];
    rtb_sc_face_in_sun[2] = body_vecs[itmp + 10];
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* Update for RateTransition: '<S1>/Rate Transition5' */
  rtDW.RateTransition5_Buffer0[0] = rtb_sc_face_in_sun[0];
  rtDW.RateTransition5_Buffer0[1] = rtb_sc_face_in_sun[1];
  rtDW.RateTransition5_Buffer0[2] = rtb_sc_face_in_sun[2];
}

/* Model step function for TID6 */
void sensor_processing_step6(void)     /* Sample time: [1.0s, 0.0s] */
{
  real_T JD_days_gps;
  real_T T1900;
  real_T days;
  real_T dayofyear;
  real_T day;
  real_T day_num;
  static const int8_T b[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  real_T M_moon;
  real_T M_sun;
  real_T u_moon;
  real_T D_sun;
  real_T deps_1980;
  real_T tod_to_mod[9];
  static const real_T nc[300] = { 1.0, 9.0, 31.0, 2.0, 10.0, 32.0, 11.0, 33.0,
    34.0, 12.0, 35.0, 13.0, 36.0, 38.0, 37.0, 40.0, 39.0, 41.0, 14.0, 3.0, 42.0,
    45.0, 43.0, 44.0, 46.0, 15.0, 47.0, 16.0, 18.0, 48.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, -1.0, 1.0, 0.0, -1.0, -1.0, 1.0, 2.0,
    -2.0, 0.0, 2.0, 2.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 2.0, 0.0,
    0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 0.0, 0.0, 2.0, 0.0, 2.0, 0.0,
    2.0, 2.0, 2.0, 0.0, 2.0, 2.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, 0.0,
    0.0, 0.0, -2.0, 0.0, 0.0, -2.0, -2.0, -2.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0,
    -2.0, 0.0, 2.0, 0.0, 0.0, -2.0, 0.0, -2.0, 0.0, 0.0, -2.0, 2.0, 1.0, 2.0,
    2.0, 2.0, 0.0, 0.0, 2.0, 1.0, 2.0, 2.0, 0.0, 1.0, 2.0, 1.0, 0.0, 2.0, 1.0,
    1.0, 0.0, 1.0, 2.0, 2.0, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0, 2.0, 1.0, -171996.0,
    -13187.0, -2274.0, 2062.0, 1426.0, 712.0, -517.0, -386.0, -301.0, 217.0,
    -158.0, 129.0, 123.0, 63.0, 63.0, -59.0, -58.0, -51.0, 48.0, 46.0, -38.0,
    -31.0, 29.0, 29.0, 26.0, -22.0, 21.0, 17.0, -16.0, 16.0, -174.2, -1.6, -0.2,
    0.2, -3.4, 0.1, 1.2, -0.4, 0.0, -0.5, 0.0, 0.1, 0.0, 0.1, 0.0, 0.0, -0.1,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.1, 0.1, 0.0, 92025.0,
    5736.0, 977.0, -895.0, 54.0, -7.0, 224.0, 200.0, 129.0, -95.0, -1.0, -70.0,
    -53.0, -33.0, -2.0, 26.0, 32.0, 27.0, 1.0, -24.0, 16.0, 13.0, -1.0, -12.0,
    -1.0, 0.0, -10.0, 0.0, 7.0, -8.0, 8.9, -3.1, -0.5, 0.5, -0.1, 0.0, -0.6, 0.0,
    -0.1, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T c[3] = { 1, 0, 0 };

  static const int8_T d[3] = { 0, 0, 1 };

  static const int8_T e[3] = { 0, 1, 0 };

  real_T rr2[3];
  real_T vv2[3];
  real_T vk[3];
  real_T pos_eci_m[3];
  real_T hv[3];
  real_T vxh[3];
  real_T rk;
  real_T rdotk;
  real_T rfdotk;
  real_T uk;
  real_T xinck;
  real_T xn;
  real_T temp1;
  real_T temp2;
  real_T cosio;
  real_T sinio;
  real_T sin2u;
  real_T theta2;
  real_T x3thm1;
  real_T r;
  real_T beta;
  real_T ayn;
  real_T cosepw;
  real_T c_0;
  real_T rtb_cur_gps_time[2];
  real_T rtb_time_vec_ut1[6];
  real_T rtb_teme_to_gcrf[9];
  real_T rtb_MathFunction[9];
  real_T rtb_mod_to_gcrf[9];
  int16_T i;
  real_T tmp[9];
  real_T c_1[9];
  int16_T i_0;
  real_T rtb_MultiportSwitch1_idx_0;
  real_T rtb_MultiportSwitch1_idx_1;
  real_T rtb_MultiportSwitch1_idx_2;
  real_T rtb_MultiportSwitch2_idx_0;
  real_T rtb_MultiportSwitch2_idx_1;
  real_T rtb_MultiportSwitch2_idx_2;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;

  /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
   *  UnitDelay: '<S2>/Unit Delay'
   */
  if ((int16_T)rtDW.RateTransition3[8] == 0) {
    rtb_cur_gps_time[0] = rtDW.UnitDelay_DSTATE[0];
    rtb_cur_gps_time[1] = rtDW.UnitDelay_DSTATE[1];
  } else {
    rtb_cur_gps_time[0] = rtDW.RateTransition3[6];
    rtb_cur_gps_time[1] = rtDW.RateTransition3[7];
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch' */

  /* MultiPortSwitch: '<S2>/Multiport Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay2'
   */
  if ((int16_T)rtDW.RateTransition3[8] == 0) {
    rtb_MultiportSwitch1_idx_0 = rtDW.UnitDelay2_DSTATE[0];
    rtb_MultiportSwitch1_idx_1 = rtDW.UnitDelay2_DSTATE[1];
    rtb_MultiportSwitch1_idx_2 = rtDW.UnitDelay2_DSTATE[2];
  } else {
    rtb_MultiportSwitch1_idx_0 = rtDW.RateTransition3[0];
    rtb_MultiportSwitch1_idx_1 = rtDW.RateTransition3[1];
    rtb_MultiportSwitch1_idx_2 = rtDW.RateTransition3[2];
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch1' */

  /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if ((int16_T)rtDW.RateTransition3[8] == 0) {
    rtb_MultiportSwitch2_idx_0 = rtDW.UnitDelay1_DSTATE[0];
    rtb_MultiportSwitch2_idx_1 = rtDW.UnitDelay1_DSTATE[1];
    rtb_MultiportSwitch2_idx_2 = rtDW.UnitDelay1_DSTATE[2];
  } else {
    rtb_MultiportSwitch2_idx_0 = rtDW.RateTransition3[3];
    rtb_MultiportSwitch2_idx_1 = rtDW.RateTransition3[4];
    rtb_MultiportSwitch2_idx_2 = rtDW.RateTransition3[5];
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch2' */

  /* MATLAB Function: '<S12>/Translate to UT1' */
  /*  ------ Prelim Stuff ------ % */
  /*  Account for \Delta UT1 to get closest estimate to UT1 */
  /*    \Delta UT1 obtained from: */
  /*        http://maia.usno.navy.mil/ser7/finals.daily */
  /*    on Feb 24, 2017: 0.5236028 */
  /* MATLAB Function 'gps_to_ut1/Translate to UT1': '<S15>:1' */
  /*  Account for leap seconds GPS --> UT1 */
  /* '<S15>:1:11' dut1 = -0.07; */
  /*  estimated for Oct 1, 2018 */
  /* '<S15>:1:12' gps2ut1     = dut1 - 18; */
  /*  sec --> JD conversion */
  /* '<S15>:1:15' sec2JD  = (0.0001/8.64); */
  /*  JD/sec */
  /* '<S15>:1:17' feb = 28; */
  /* '<S15>:1:18' cal_days = [31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; */
  /* '<S15>:1:20' sec_in = cur_gps(1); */
  /* '<S15>:1:20' week_in = cur_gps(2); */
  /*  --------------------------- % */
  /*  Translate GPS w-s to JD and Gregorian ymd-hms */
  /* '<S15>:1:25' JD_jan61980 = 2.444244500000000e+06; */
  /* '<S15>:1:26' JD_J2000    = 2451545; */
  /* '<S15>:1:28' JD_days_gps     = JD_jan61980 + 7*week_in + sec_in/3600/24; */
  JD_days_gps = (7.0 * rtb_cur_gps_time[1] + 2.4442445E+6) + rtb_cur_gps_time[0]
    / 3600.0 / 24.0;

  /* '<S15>:1:29' JD_days_ut1     = JD_days_gps; */
  /* + sec2JD*gps2ut1; */
  /* '<S15>:1:31' JD_ut1_J2000_days       = JD_days_ut1 - JD_J2000; */
  /* '<S15>:1:32' JD_ut1_J2000_century    = (JD_days_ut1 - 2451545)/36525; */
  /* '<S15>:1:34' T1900   = (JD_days_ut1 - 2415019.5)/365.25; */
  T1900 = (JD_days_gps - 2.4150195E+6) / 365.25;

  /* '<S15>:1:36' year    = 1900 + floor(T1900); */
  day = floor(T1900);
  T1900 = 1900.0 + floor(T1900);

  /* '<S15>:1:38' leapyrs     = floor((year - 1900 - 1)*0.25); */
  /* '<S15>:1:39' days    = (JD_days_ut1 - 2415019.5) - ((year - 1900)*365 + leapyrs ); */
  days = (JD_days_gps - 2.4150195E+6) - (floor((((1900.0 + day) - 1900.0) - 1.0)
    * 0.25) + ((1900.0 + day) - 1900.0) * 365.0);

  /* '<S15>:1:41' if days < 1 */
  if (days < 1.0) {
    /* '<S15>:1:42' year = year - 1; */
    T1900 = (1900.0 + day) - 1.0;

    /* '<S15>:1:43' leapyrs = floor((year - 1900 - 1)*0.25); */
    /* '<S15>:1:44' days    = (JD_days_ut1 - 2415019.5) - ((year - 1900)*365 + leapyrs ); */
    days = (JD_days_gps - 2.4150195E+6) - (floor(((((1900.0 + day) - 1.0) -
      1900.0) - 1.0) * 0.25) + (((1900.0 + day) - 1.0) - 1900.0) * 365.0);
  }

  /* '<S15>:1:47' if mod(year,4) == 0 */
  /* '<S15>:1:51' dayofyear   = floor(days); */
  dayofyear = floor(days);

  /* '<S15>:1:53' day     = 0; */
  day = 0.0;

  /* '<S15>:1:54' i       = 0; */
  days = 0.0;

  /* '<S15>:1:56' while day < dayofyear */
  while (day < dayofyear) {
    /* '<S15>:1:57' i   = i + 1; */
    days++;

    /* '<S15>:1:58' day = day + cal_days(i); */
    day += (real_T)b[(int16_T)days - 1];
  }

  /* '<S15>:1:61' month   = i - 1; */
  /* '<S15>:1:63' day_num = 0; */
  day_num = 0.0;

  /* '<S15>:1:64' for i = 1:month */
  for (i = 0; i < (int16_T)(days - 1.0); i++) {
    /* '<S15>:1:65' day_num = day_num + cal_days(i); */
    day_num += (real_T)b[i];
  }

  /* '<S15>:1:68' day     = day - day_num; */
  day -= day_num;

  /* '<S15>:1:70' tau     = 24*( day - dayofyear ); */
  dayofyear = (day - dayofyear) * 24.0;

  /* '<S15>:1:72' hour    = floor( tau ); */
  /* '<S15>:1:73' min     = floor( 60*(tau - hour) ); */
  day_num = (dayofyear - dayofyear) * 60.0;

  /* '<S15>:1:74' sec     = 3600*( tau - hour - (min/60) ); */
  /*  % Account for leap seconds GPS --> UT1 */
  /*  sec = sec + gps2ut1; */
  /*   */
  /*  if sec < 0 */
  /*      sec = mod(sec,60); */
  /*      min = min - 1; */
  /*  end */
  /*   */
  /*  if min < 0 */
  /*      min = mod(min,60); */
  /*      hour = hour - 1; */
  /*  end */
  /*   */
  /*  if hour < 0 */
  /*      hour = mod(hour,24); */
  /*      day = day - 1; */
  /*  end */
  /*   */
  /*  if day < 0 */
  /*      month = month - 1; */
  /*      if month < 0 */
  /*          month = 12; */
  /*          year = year - 1; */
  /*      end */
  /*  end */
  /* '<S15>:1:102' time_vec_ut1 = [year,month,day,hour,min,sec]; */
  rtb_time_vec_ut1[0] = T1900;
  rtb_time_vec_ut1[1] = days - 1.0;
  rtb_time_vec_ut1[2] = day;
  rtb_time_vec_ut1[3] = dayofyear;
  rtb_time_vec_ut1[4] = day_num;
  rtb_time_vec_ut1[5] = ((dayofyear - dayofyear) - day_num / 60.0) * 3600.0;
  T1900 = (JD_days_gps - 2.451545E+6) / 36525.0;

  /* MATLAB Function: '<S11>/Translate to TT' */
  /*  ------ Prelim Stuff ------ % */
  /*  Account for \Delta UT1 to get closest estimate to UT1 */
  /*    \Delta UT1 obtained from: */
  /*        http://maia.usno.navy.mil/ser7/finals.daily */
  /*    on Feb 24, 2017: 0.5236028 */
  /* MATLAB Function 'gps_to_tt/Translate to TT': '<S14>:1' */
  /*  Account for leap seconds GPS --> TT */
  /* '<S14>:1:11' gps2tt     = 32.184 + (19); */
  /*  sec --> JD conversion */
  /* '<S14>:1:14' sec2JD  = (0.0001/8.64); */
  /*  JD/sec */
  /* '<S14>:1:16' feb = 28; */
  /* '<S14>:1:17' cal_days = [31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; */
  /* '<S14>:1:19' sec_in = cur_gps(1); */
  /* '<S14>:1:19' week_in = cur_gps(2); */
  /*  Translate GPS w-s to JD and Gregorian ymd-hms */
  /* '<S14>:1:23' JD_jan61980 = 2.444244500000000e+06; */
  /* '<S14>:1:24' JD_J2000    = 2451545; */
  /* '<S14>:1:26' JD_days_gps     = JD_jan61980 + 7*week_in + sec_in/3600/24; */
  /* '<S14>:1:27' JD_days_TT     = JD_days_gps + sec2JD*gps2tt; */
  /* '<S14>:1:29' JD_TT_J2000_days       = JD_days_TT - JD_J2000; */
  /* '<S14>:1:30' JD_TT_J2000_century    = (JD_days_TT - 2451545)/36525; */
  /* '<S14>:1:32' T1900   = (JD_days_TT - 2415019.5)/365.25; */
  /* '<S14>:1:34' year    = 1900 + floor(T1900); */
  /* '<S14>:1:36' leapyrs     = floor((year - 1900 - 1)*0.25); */
  /* '<S14>:1:37' days    = (JD_days_TT - 2415019.5) - ((year - 1900)*365 + leapyrs ); */
  /* '<S14>:1:39' if days < 1 */
  /* '<S14>:1:45' if mod(year,4) == 0 */
  /* '<S14>:1:49' dayofyear   = floor(days); */
  /* '<S14>:1:51' day     = 0; */
  /* '<S14>:1:52' i       = 0; */
  /* '<S14>:1:54' while day < dayofyear */
  /* '<S14>:1:59' month   = i - 1; */
  /* '<S14>:1:61' day_num = 0; */
  /* '<S14>:1:62' for i = 1:month */
  /* '<S14>:1:66' day     = day - day_num; */
  /* '<S14>:1:68' tau     = 24*( day - dayofyear ); */
  /* '<S14>:1:70' hour    = floor( tau ); */
  /* '<S14>:1:71' min     = floor( 60*(tau - hour) ); */
  /* '<S14>:1:72' sec     = 3600*( tau - hour - (min/60) ); */
  /*  % Account for leap seconds GPS --> UT1 */
  /*  sec = sec + gps2ut1; */
  /*   */
  /*  if sec < 0 */
  /*      sec = mod(sec,60); */
  /*      min = min - 1; */
  /*  end */
  /*   */
  /*  if min < 0 */
  /*      min = mod(min,60); */
  /*      hour = hour - 1; */
  /*  end */
  /*   */
  /*  if hour < 0 */
  /*      hour = mod(hour,24); */
  /*      day = day - 1; */
  /*  end */
  /*   */
  /*  if day < 0 */
  /*      month = month - 1; */
  /*      if month < 0 */
  /*          month = 12; */
  /*          year = year - 1; */
  /*      end */
  /*  end */
  /* '<S14>:1:100' time_vec_TT = [year,month,day,hour,min,sec]; */
  day_num = ((((7.0 * rtb_cur_gps_time[1] + 2.4442445E+6) + rtb_cur_gps_time[0] /
               3600.0 / 24.0) + 0.00059240740740740738) - 2.451545E+6) / 36525.0;

  /* MATLAB Function: '<S10>/MATLAB Function' */
  /*  */
  /*  UW HuskySat-1, ADCS Subsystem */
  /*    Courtesy: Krish Kaycee 9.11.17 */
  /*  */
  /*  COORD_ROTATIONS excludes the polar motion transformation. Hence it */
  /*  includes the Precession, Nutation, and Sidereal Time rotation matrices. */
  /* MATLAB Function 'coord_rotations_lib/MATLAB Function': '<S13>:1' */
  /*  UPDATED: Excluding polar motion since it would need to be updated ~1 per */
  /*  week to keep accurate. For our mission duration and requirements, */
  /*  accounting for polar motion is not necessary. -T. Reynolds, 9.11.17 */
  /*  Constants */
  /*  Everything should be precomputed in radians */
  /* '<S13>:1:16' deg2rad = pi/180; */
  /* '<S13>:1:17' asec2rad = 1/3600*deg2rad; */
  /* '<S13>:1:18' o_prec = 7.292115146706979e-5; */
  /*  Evaluate Delaunay parameters */
  /* '<S13>:1:21' epsb_1980 = deg2rad * ( 23.439291 ... */
  /* '<S13>:1:22'                         - 0.0130042 * jd_tt_j2000_century ... */
  /* '<S13>:1:23'                         - 1.64e-7 * jd_tt_j2000_century^2 ... */
  /* '<S13>:1:24'                         + 5.04e-7 * jd_tt_j2000_century^3); */
  day = (((23.439291 - 0.0130042 * day_num) - day_num * day_num * 1.64E-7) +
         5.04E-7 * rt_powd_snf(day_num, 3.0)) * 0.017453292519943295;

  /*  Evaluate Delaunay parameters (correct equations from 4e errata) */
  /* '<S13>:1:27' M_moon	=   deg2rad * ( 134.96298139 ... */
  /* '<S13>:1:28'                         + (1325 * 360 + 198.8673981) * jd_tt_j2000_century ... */
  /* '<S13>:1:29'                       	+ 0.0086972 * jd_tt_j2000_century^2 ... */
  /* '<S13>:1:30'                        	+ 1.78e-5 * jd_tt_j2000_century^3); */
  M_moon = (((477198.8673981 * day_num + 134.96298139) + day_num * day_num *
             0.0086972) + 1.78E-5 * rt_powd_snf(day_num, 3.0)) *
    0.017453292519943295;

  /* '<S13>:1:31' M_sun	=   deg2rad * ( 357.52772333 ... */
  /* '<S13>:1:32'                         + (99 * 360 + 359.0503400) * jd_tt_j2000_century ... */
  /* '<S13>:1:33'                       	- 0.0001603 * jd_tt_j2000_century^2 ... */
  /* '<S13>:1:34'                      	- 3.3e-6 * jd_tt_j2000_century^3); */
  M_sun = (((35999.05034 * day_num + 357.52772333) - day_num * day_num *
            0.0001603) - 3.3E-6 * rt_powd_snf(day_num, 3.0)) *
    0.017453292519943295;

  /* '<S13>:1:35' u_moon	=   deg2rad * ( 93.27191028 ... */
  /* '<S13>:1:36'                         + (1342 * 360 + 82.0175381) * jd_tt_j2000_century ... */
  /* '<S13>:1:37'                       	- 0.0036825 * jd_tt_j2000_century^2 ... */
  /* '<S13>:1:38'                         + 3.1e-6 * jd_tt_j2000_century^3); */
  u_moon = (((483202.0175381 * day_num + 93.27191028) - day_num * day_num *
             0.0036825) + 3.1E-6 * rt_powd_snf(day_num, 3.0)) *
    0.017453292519943295;

  /* '<S13>:1:39' D_sun	=   deg2rad * ( 297.85036306 ... */
  /* '<S13>:1:40'                         + (1236 * 360 + 307.1114800) * jd_tt_j2000_century ... */
  /* '<S13>:1:41'                         - 0.0019142 * jd_tt_j2000_century^2 ... */
  /* '<S13>:1:42'                      	+ 5.3e-6 * jd_tt_j2000_century^3); */
  D_sun = (((445267.11148 * day_num + 297.85036306) - day_num * day_num *
            0.0019142) + 5.3E-6 * rt_powd_snf(day_num, 3.0)) *
    0.017453292519943295;

  /* '<S13>:1:43' O_moon	=   deg2rad * ( 125.04452222 ... */
  /* '<S13>:1:44'                         - (5 * 360 + 134.1362608) * jd_tt_j2000_century ... */
  /* '<S13>:1:45'                     	+ 0.0020708 * jd_tt_j2000_century^2 ... */
  /* '<S13>:1:46'                         + 2.2e-6 * jd_tt_j2000_century^3); */
  days = (((125.04452222 - 1934.1362608 * day_num) + day_num * day_num *
           0.0020708) + 2.2E-6 * rt_powd_snf(day_num, 3.0)) *
    0.017453292519943295;

  /*  Largest Nutation coefficents (out of 106)                     */
  /* '<S13>:1:49' nc = [ ... */
  /* '<S13>:1:50' 1   0   0   0   0   1   -171996 -174.2  92025   8.9 */
  /* '<S13>:1:51' 9   0   0   2   -2  2   -13187  -1.6    5736    -3.1 */
  /* '<S13>:1:52' 31  0   0   2   0   2   -2274   -0.2    977     -0.5 */
  /* '<S13>:1:53' 2   0   0   0   0   2   2062    0.2     -895    0.5 */
  /* '<S13>:1:54' 10  0   1   0  	0   0   1426    -3.4    54      -0.1 */
  /* '<S13>:1:55' 32  1   0   0   0   0   712     0.1     -7      0.0 */
  /* '<S13>:1:56' 11  0   1   2   -2  2   -517    1.2     224     -0.6 */
  /* '<S13>:1:57' 33  0   0   2   0   1   -386    -0.4    200     0.0 */
  /* '<S13>:1:58' 34  1   0   2   0   2   -301    0.0     129     -0.1 */
  /* '<S13>:1:59' 12  0   -1  2   -2  2   217     -0.5    -95     0.3 */
  /* '<S13>:1:60' 35  1   0   0   -2  0   -158    0.0     -1      0.0 */
  /* '<S13>:1:61' 13  0   0   2   -2  1   129     0.1     -70     0.0  */
  /* '<S13>:1:62' 36  -1  0   2   0   2   123     0.0     -53     0.0  */
  /* '<S13>:1:63' 38  1   0   0   0   1   63      0.1     -33     0.0 */
  /* '<S13>:1:64' 37  0   0   0   2   0   63      0.0     -2      0.0 */
  /* '<S13>:1:65' 40  -1  0   2   2   2   -59     0.0     26      0.0 */
  /* '<S13>:1:66' 39  -1  0   0   0   1   -58     -0.1    32      0.0 */
  /* '<S13>:1:67' 41  1   0   2   0   1   -51     0.0     27      0.0 */
  /* '<S13>:1:68' 14  2   0   0   -2  0   48      0.0     1       0.0 */
  /* '<S13>:1:69' 3   -2  0   2   0   1   46      0.0     -24     0.0 */
  /* '<S13>:1:70' 42  0   0   2   2   2   -38     0.0     16      0.0 */
  /* '<S13>:1:71' 45  2   0   2   0   2   -31     0.0     13      0.0 */
  /* '<S13>:1:72' 43  2   0   0   0   0   29      0.0     -1      0.0 */
  /* '<S13>:1:73' 44  1   0   2   -2  2   29      0.0     -12     0.0 */
  /* '<S13>:1:74' 46  0   0   2   0   0   26      0.0     -1      0.0 */
  /* '<S13>:1:75' 15  0   0   2   -2  0   -22     0.0     0       0.0 */
  /* '<S13>:1:76' 47  -1  0   2   0   1   21      0.0     -10     0.0 */
  /* '<S13>:1:77' 16  0   2   0   0   0   17      -0.1    0       0.0 */
  /* '<S13>:1:78' 18  0   2   2   -2  2   -16     0.1     7       0.0 */
  /* '<S13>:1:79' 48  -1  0   0   2   1   16      0.0     -8      0.0 ... */
  /* '<S13>:1:80' ]; */
  /*  Map coefficients to radians (this should be embedded in the data) */
  /*  nc(:,end-3:end) = nc(:,end-3:end) * 0.0001 * asec2rad; */
  /*  Compute nutation in longitude (psi), and latitude (eps) */
  /* '<S13>:1:86' dpsi_1980 = 0; */
  dayofyear = 0.0;

  /* '<S13>:1:86' deps_1980 = 0; */
  deps_1980 = 0.0;

  /* '<S13>:1:87' for i = 1:size(nc,1) */
  for (i = 0; i < 30; i++) {
    /* '<S13>:1:88' api         =   nc(i,2) * M_moon + nc(i,3) * M_sun + nc(i,4) * u_moon + nc(i,5) * D_sun + nc(i,6) * O_moon; */
    temp1 = (((nc[30 + i] * M_moon + nc[60 + i] * M_sun) + nc[90 + i] * u_moon)
             + nc[120 + i] * D_sun) + nc[150 + i] * days;

    /* '<S13>:1:89' dpsi_1980   =   0.0001 * (nc(i,7) + nc(i,8) * jd_tt_j2000_century) * sin(api) + dpsi_1980; */
    dayofyear += (nc[210 + i] * day_num + nc[180 + i]) * 0.0001 * sin(temp1);

    /* '<S13>:1:90' deps_1980   =   0.0001 * (nc(i,9) + nc(i,10) * jd_tt_j2000_century) * cos(api) + deps_1980; */
    deps_1980 += (nc[270 + i] * day_num + nc[240 + i]) * 0.0001 * cos(temp1);
  }

  /* '<S13>:1:93' eps_1980 = epsb_1980 + asec2rad * deps_1980; */
  M_moon = 4.84813681109536E-6 * deps_1980 + day;

  /* '<S13>:1:94' tod_to_mod = rot1(-epsb_1980) * rot3(asec2rad * dpsi_1980) * rot1(eps_1980); */
  /* '<S13>:1:132' y = [1 0 0; 0 cos(u) sin(u); 0 -sin(u) cos(u)]; */
  deps_1980 = 4.84813681109536E-6 * dayofyear;

  /* '<S13>:1:140' y = [cos(u) sin(u) 0; -sin(u) cos(u) 0; 0 0 1]; */
  /* '<S13>:1:132' y = [1 0 0; 0 cos(u) sin(u); 0 -sin(u) cos(u)]; */
  rtb_mod_to_gcrf[1] = 0.0;
  rtb_mod_to_gcrf[4] = cos(-day);
  rtb_mod_to_gcrf[7] = sin(-day);
  rtb_mod_to_gcrf[2] = 0.0;
  rtb_mod_to_gcrf[5] = -sin(-day);
  rtb_mod_to_gcrf[8] = cos(-day);
  tmp[0] = cos(deps_1980);
  tmp[3] = sin(deps_1980);
  tmp[6] = 0.0;
  tmp[1] = -sin(deps_1980);
  tmp[4] = cos(deps_1980);
  tmp[7] = 0.0;
  rtb_mod_to_gcrf[0] = 1.0;
  tmp[2] = 0.0;
  rtb_mod_to_gcrf[3] = 0.0;
  tmp[5] = 0.0;
  rtb_mod_to_gcrf[6] = 0.0;
  tmp[8] = 1.0;
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      c_1[i + 3 * i_0] = 0.0;
      c_1[i + 3 * i_0] += tmp[3 * i_0] * rtb_mod_to_gcrf[i];
      c_1[i + 3 * i_0] += tmp[3 * i_0 + 1] * rtb_mod_to_gcrf[i + 3];
      c_1[i + 3 * i_0] += tmp[3 * i_0 + 2] * rtb_mod_to_gcrf[i + 6];
    }

    rtb_MathFunction[3 * i] = c[i];
  }

  rtb_MathFunction[1] = 0.0;
  rtb_MathFunction[4] = cos(M_moon);
  rtb_MathFunction[7] = sin(M_moon);
  rtb_MathFunction[2] = 0.0;
  rtb_MathFunction[5] = -sin(M_moon);
  rtb_MathFunction[8] = cos(M_moon);

  /*  Generate Precession matrix */
  /* '<S13>:1:97' zeta    =   asec2rad * (2306.2181 * jd_tt_j2000_century + 0.30188 * jd_tt_j2000_century^2 + 0.017998 * jd_tt_j2000_century^3); */
  M_moon = ((day_num * day_num * 0.30188 + 2306.2181 * day_num) + 0.017998 *
            rt_powd_snf(day_num, 3.0)) * 4.84813681109536E-6;

  /* '<S13>:1:98' theta   =   asec2rad * (2004.3109 * jd_tt_j2000_century - 0.42665 * jd_tt_j2000_century^2 - 0.041833 * jd_tt_j2000_century^3); */
  /* '<S13>:1:99' z       =   asec2rad * (2306.2181 * jd_tt_j2000_century + 1.09468 * jd_tt_j2000_century^2 + 0.018203 * jd_tt_j2000_century^3); */
  M_sun = ((day_num * day_num * 1.09468 + 2306.2181 * day_num) + 0.018203 *
           rt_powd_snf(day_num, 3.0)) * 4.84813681109536E-6;

  /* '<S13>:1:101' mod_to_gcrf = rot3(zeta) * rot2(-theta) * rot3(z); */
  /* '<S13>:1:140' y = [cos(u) sin(u) 0; -sin(u) cos(u) 0; 0 0 1]; */
  day_num = -(((2004.3109 * day_num - day_num * day_num * 0.42665) - 0.041833 *
               rt_powd_snf(day_num, 3.0)) * 4.84813681109536E-6);

  /* '<S13>:1:136' y = [cos(u) 0 -sin(u); 0 1 0; sin(u) 0 cos(u)]; */
  /* '<S13>:1:140' y = [cos(u) sin(u) 0; -sin(u) cos(u) 0; 0 0 1]; */
  tmp[0] = cos(M_moon);
  tmp[3] = sin(M_moon);
  tmp[6] = 0.0;
  tmp[1] = -sin(M_moon);
  tmp[4] = cos(M_moon);
  tmp[7] = 0.0;
  rtb_mod_to_gcrf[0] = cos(day_num);
  rtb_mod_to_gcrf[3] = 0.0;
  rtb_mod_to_gcrf[6] = -sin(day_num);
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      tod_to_mod[i + 3 * i_0] = 0.0;
      tod_to_mod[i + 3 * i_0] += rtb_MathFunction[3 * i_0] * c_1[i];
      tod_to_mod[i + 3 * i_0] += rtb_MathFunction[3 * i_0 + 1] * c_1[i + 3];
      tod_to_mod[i + 3 * i_0] += rtb_MathFunction[3 * i_0 + 2] * c_1[i + 6];
    }

    tmp[2 + 3 * i] = d[i];
    rtb_mod_to_gcrf[1 + 3 * i] = e[i];
  }

  rtb_mod_to_gcrf[2] = sin(day_num);
  rtb_mod_to_gcrf[5] = 0.0;
  rtb_mod_to_gcrf[8] = cos(day_num);
  rtb_MathFunction[0] = cos(M_sun);
  rtb_MathFunction[3] = sin(M_sun);
  rtb_MathFunction[6] = 0.0;
  rtb_MathFunction[1] = -sin(M_sun);
  rtb_MathFunction[4] = cos(M_sun);
  rtb_MathFunction[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      c_1[i + 3 * i_0] = 0.0;
      c_1[i + 3 * i_0] += rtb_mod_to_gcrf[3 * i_0] * tmp[i];
      c_1[i + 3 * i_0] += rtb_mod_to_gcrf[3 * i_0 + 1] * tmp[i + 3];
      c_1[i + 3 * i_0] += rtb_mod_to_gcrf[3 * i_0 + 2] * tmp[i + 6];
    }

    rtb_MathFunction[2 + 3 * i] = d[i];
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_mod_to_gcrf[i_0 + 3 * i] = 0.0;
      rtb_mod_to_gcrf[i_0 + 3 * i] += rtb_MathFunction[3 * i] * c_1[i_0];
      rtb_mod_to_gcrf[i_0 + 3 * i] += rtb_MathFunction[3 * i + 1] * c_1[i_0 + 3];
      rtb_mod_to_gcrf[i_0 + 3 * i] += rtb_MathFunction[3 * i + 2] * c_1[i_0 + 6];
    }
  }

  /*  Compute equation of Equinoxes */
  /* '<S13>:1:104' eqe_1980 = asec2rad * (dpsi_1980  * cos(epsb_1980) + 0.00264 * sin(O_moon) + 0.000063 * sin(2 * O_moon)); */
  days = ((dayofyear * cos(day) + 0.00264 * sin(days)) + sin(2.0 * days) *
          6.3E-5) * 4.84813681109536E-6;

  /* '<S13>:1:105' teme_to_tod = rot3(-eqe_1980); */
  /* '<S13>:1:140' y = [cos(u) sin(u) 0; -sin(u) cos(u) 0; 0 0 1]; */
  /*  Compute sidereal rotation */
  /*  GMST_1982 = asec2rad * (67310.54841 ... */
  /*                          + (876600 * 3600 + 8640184.812866) * jd_ut1_j2000_century ... */
  /*                          + 0.093104 * jd_ut1_j2000_century^2 ... */
  /*                          - 6.2e-6 * jd_ut1_j2000_century^3); */
  /* '<S13>:1:112' GMST_1982 = (67310.54841 ... */
  /* '<S13>:1:113'                         + (876600 * 3600 + 8640184.812866) * jd_ut1_j2000_century ... */
  /* '<S13>:1:114'                         + 0.093104 * jd_ut1_j2000_century^2 ... */
  /* '<S13>:1:115'                         - 6.2e-6 * jd_ut1_j2000_century^3); */
  day = ((3.1644001848128662E+9 * T1900 + 67310.54841) + T1900 * T1900 *
         0.093104) - 6.2E-6 * rt_powd_snf(T1900, 3.0);

  /* '<S13>:1:116' GMST_1982 = mod(GMST_1982,sign(GMST_1982)*86400) / 240; */
  if (day < 0.0) {
    dayofyear = -1.0;
  } else if (day > 0.0) {
    dayofyear = 1.0;
  } else if (day == 0.0) {
    dayofyear = 0.0;
  } else {
    dayofyear = day;
  }

  rk = dayofyear * 86400.0;
  if (!(rk == 0.0)) {
    if (rk == rk) {
      day -= floor(day / rk) * rk;
    } else {
      day /= rk;
      if (fabs(day - rt_roundd_snf(day)) <= 2.2204460492503131E-16 * fabs(day))
      {
        day = 0.0;
      } else {
        day = (day - floor(day)) * rk;
      }
    }
  }

  day /= 240.0;

  /* '<S13>:1:117' GMST_1982 = deg2rad * mod(GMST_1982, 360); */
  day = (day - floor(day / 360.0) * 360.0) * 0.017453292519943295;

  /* '<S13>:1:118' GAST_1982 = GMST_1982 + eqe_1980; */
  /*  Compute rotation from pseudo-Earth fixed frame (does not include polar */
  /*  motion) */
  /* '<S13>:1:122' pef_to_tod = rot3(-GAST_1982); */
  day = -(day + days);

  /* '<S13>:1:140' y = [cos(u) sin(u) 0; -sin(u) cos(u) 0; 0 0 1]; */
  /*  Compute composite rotations */
  /* '<S13>:1:125' teme_to_gcrf = mod_to_gcrf * tod_to_mod * teme_to_tod; */
  /* '<S13>:1:126' itrf_to_gcrf = mod_to_gcrf * tod_to_mod * pef_to_tod; */
  /*  for vecef */
  /* '<S13>:1:127' ppef_to_vgcrf = itrf_to_gcrf * skew([0; 0; o_prec]); */
  /*  for w x recef */
  tmp[0] = cos(-days);
  tmp[3] = sin(-days);
  tmp[6] = 0.0;
  tmp[1] = -sin(-days);
  tmp[4] = cos(-days);
  tmp[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      c_1[i + 3 * i_0] = 0.0;
      c_1[i + 3 * i_0] += tod_to_mod[3 * i_0] * rtb_mod_to_gcrf[i];
      c_1[i + 3 * i_0] += tod_to_mod[3 * i_0 + 1] * rtb_mod_to_gcrf[i + 3];
      c_1[i + 3 * i_0] += tod_to_mod[3 * i_0 + 2] * rtb_mod_to_gcrf[i + 6];
    }

    tmp[2 + 3 * i] = d[i];
  }

  for (i = 0; i < 3; i++) {
    /* Math: '<S7>/Math Function' */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_teme_to_gcrf[i + 3 * i_0] = 0.0;
      rtb_teme_to_gcrf[i + 3 * i_0] += tmp[3 * i_0] * c_1[i];
      rtb_teme_to_gcrf[i + 3 * i_0] += tmp[3 * i_0 + 1] * c_1[i + 3];
      rtb_teme_to_gcrf[i + 3 * i_0] += tmp[3 * i_0 + 2] * c_1[i + 6];
      rtb_MathFunction[i_0 + 3 * i] = rtb_teme_to_gcrf[3 * i_0 + i];
    }

    /* End of Math: '<S7>/Math Function' */
  }

  /* MATLAB Function: '<S7>/MATLAB Function' */
  /*  convert osculating position and velocity vectors */
  /*  to components of two line element set (TLE) */
  /*    UW HuskySat-1, ADCS Subsystem */
  /*    Updated: T. Reynolds 8.18.17 */
  /* MATLAB Function 'eci_2_TLE_lib/MATLAB Function': '<S8>:1' */
  /*  Input */
  /*   pos_eci_m = eci position vector (meters) */
  /*   veci = eci velocity vector (meters/second) */
  /*  Output */
  /*   eo     = orbital eccentricity (non-dimensional) */
  /*   xno    = mean motion (orbits per day) */
  /*   xmo    = mean anomaly (degrees) */
  /*   xincl  = orbital inclination (degrees) */
  /*   omegao = argument of perigee (degrees) */
  /*   xnodeo = right ascension of ascending node (degrees) */
  /*  Reference: Scott Campbell's Satellite Orbit Determination */
  /*             web site www.satelliteorbitdetermination.com */
  /*  ----- Constants ----- % */
  /* '<S8>:1:27' pi2 = 2.0 * pi; */
  /* '<S8>:1:29' RAD2DEG     = 180/pi; */
  /* '<S8>:1:31' xke = 0.0743669161331734132; */
  /* '<S8>:1:32' xj3 = -2.53881e-6; */
  /* '<S8>:1:34' req = 6378.135; */
  /* '<S8>:1:36' ck2 = 5.413079e-4; */
  /* '<S8>:1:38' a3ovk2 = -xj3 / ck2; */
  /* '<S8>:1:40' xM2KM = 1e-3; */
  /*  ---------------------- % */
  /*  convert position vector to earth radii */
  /*  and velocity vector to earth radii per minute */
  /*  initialize everything */
  /* '<S8>:1:47' rr2     = zeros(size(pos_teme_m)); */
  /* '<S8>:1:48' vv2     = zeros(size(vel_teme_mps)); */
  /* '<S8>:1:49' vk      = zeros(size(vel_teme_mps)); */
  /* '<S8>:1:50' vy      = zeros(size(vel_teme_mps)); */
  /* '<S8>:1:51' vz      = zeros(size(vel_teme_mps)); */
  /* '<S8>:1:52' vec     = zeros(size(vel_teme_mps)); */
  /* '<S8>:1:53' xincl   = 0; */
  days = 0.0;

  /* '<S8>:1:54' xnodeo  = 0; */
  dayofyear = 0.0;

  /* '<S8>:1:55' eo      = 0; */
  deps_1980 = 0.0;

  /* '<S8>:1:56' omegao  = 0; */
  day_num = 0.0;

  /* '<S8>:1:57' xmo     = 0; */
  temp1 = 0.0;

  /* '<S8>:1:58' xno     = 0; */
  u_moon = 0.0;

  /*  convert to KM and KMPS */
  /* '<S8>:1:61' pos_eci_m = pos_teme_m*xM2KM; */
  /* '<S8>:1:62' vel_teme_mps = vel_teme_mps*xM2KM; */
  /* '<S8>:1:64' for i = 1:3 */
  for (i = 0; i < 3; i++) {
    /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
     *  Product: '<S7>/Product'
     *  Product: '<S7>/Product1'
     */
    /* '<S8>:1:65' rr2(i) = pos_eci_m(i) / req; */
    rr2[i] = (rtb_MathFunction[i + 6] * rtb_MultiportSwitch1_idx_2 +
              (rtb_MathFunction[i + 3] * rtb_MultiportSwitch1_idx_1 +
               rtb_MathFunction[i] * rtb_MultiportSwitch1_idx_0)) * 0.001 /
      6378.135;

    /* '<S8>:1:67' vv2(i) = 60.0d0 * vel_teme_mps(i) / req; */
    M_moon = 60.0 * ((rtb_MathFunction[i + 6] * rtb_MultiportSwitch2_idx_2 +
                      (rtb_MathFunction[i + 3] * rtb_MultiportSwitch2_idx_1 +
                       rtb_MathFunction[i] * rtb_MultiportSwitch2_idx_0)) *
                     0.001) / 6378.135;

    /* '<S8>:1:69' vk(i) = vv2(i) / xke; */
    vk[i] = M_moon / 0.074366916133173408;
    vv2[i] = M_moon;
  }

  /* MATLAB Function: '<S7>/MATLAB Function' */
  /* '<S8>:1:72' hv = cross(rr2, vk); */
  hv[0] = rr2[1] * vk[2] - rr2[2] * vk[1];
  hv[1] = rr2[2] * vk[0] - rr2[0] * vk[2];
  hv[2] = rr2[0] * vk[1] - rr2[1] * vk[0];

  /* '<S8>:1:74' pl = dot(hv, hv); */
  M_sun = (hv[0] * hv[0] + hv[1] * hv[1]) + hv[2] * hv[2];

  /* '<S8>:1:76' vz(1) = 0.0d0; */
  /* '<S8>:1:77' vz(2) = 0.0d0; */
  /* '<S8>:1:78' vz(3) = 1.0d0; */
  /* '<S8>:1:80' vxh = cross(vz, hv); */
  vxh[0] = 0.0 * hv[2] - hv[1];
  vxh[1] = hv[0] - 0.0 * hv[2];
  vxh[2] = 0.0 * hv[1] - 0.0 * hv[0];

  /* '<S8>:1:82' if (vxh(1) == 0.0d0 && vxh(2) == 0.0d0) */
  if ((vxh[0] == 0.0) && (vxh[1] == 0.0)) {
    /* '<S8>:1:83' vxh(1) = 1.0d0; */
    vxh[0] = 1.0;
  }

  /* '<S8>:1:86' vxhhat = vxh / norm(vxh); */
  M_moon = norm(vxh);
  vxh[0] /= M_moon;
  vxh[1] /= M_moon;
  D_sun = vxh[2] / M_moon;

  /* '<S8>:1:88' rk = norm(rr2); */
  rk = norm(rr2);

  /* '<S8>:1:90' rdotv = dot(rr2, vv2); */
  /* '<S8>:1:92' rdotk = rdotv / rk; */
  rdotk = ((rr2[0] * vv2[0] + rr2[1] * vv2[1]) + rr2[2] * vv2[2]) / rk;

  /* '<S8>:1:94' hmag = norm(hv); */
  /* '<S8>:1:96' rfdotk = hmag * xke / rk; */
  rfdotk = norm(hv) * 0.074366916133173408 / rk;

  /* '<S8>:1:98' vwrk = dot(rr2, vxhhat); */
  /* '<S8>:1:100' temp = vwrk / rk; */
  /* '<S8>:1:102' uk = acos(temp); */
  uk = acos(((rr2[0] * vxh[0] + rr2[1] * vxh[1]) + rr2[2] * D_sun) / rk);

  /* '<S8>:1:104' if (rr2(2) < 0.0d0) */
  if (rr2[1] < 0.0) {
    /* '<S8>:1:105' uk = pi2 - uk; */
    uk = 6.2831853071795862 - uk;
  }

  /* '<S8>:1:108' vz = cross(vk, hv); */
  /* '<S8>:1:110' for i = 1:3 */
  /* '<S8>:1:114' for i = 1:3 */
  /* '<S8>:1:111' vy(i) = -1.0d0 * rr2(i) / rk; */
  /* '<S8>:1:115' vec(i) = vz(i) + vy(i); */
  pos_eci_m[0] = (vk[1] * hv[2] - vk[2] * hv[1]) + -rr2[0] / rk;

  /* '<S8>:1:111' vy(i) = -1.0d0 * rr2(i) / rk; */
  /* '<S8>:1:115' vec(i) = vz(i) + vy(i); */
  pos_eci_m[1] = (vk[2] * hv[0] - vk[0] * hv[2]) + -rr2[1] / rk;

  /* '<S8>:1:111' vy(i) = -1.0d0 * rr2(i) / rk; */
  /* '<S8>:1:115' vec(i) = vz(i) + vy(i); */
  pos_eci_m[2] = (vk[0] * hv[1] - vk[1] * hv[0]) + -rr2[2] / rk;

  /* '<S8>:1:118' ek = norm(vec); */
  M_moon = norm(pos_eci_m);

  /* '<S8>:1:120' if (ek >= 1.0d0) */
  if (!(M_moon >= 1.0)) {
    /* '<S8>:1:124' xnodek = atan3(vxhhat(2), vxhhat(1)); */
    /*  four quadrant inverse tangent */
    /*  input */
    /*   a = sine of angle */
    /*   b = cosine of angle */
    /*  output */
    /*   y = angle (radians; 0 =< c <= 2 * pi) */
    /*  Orbital Mechanics with MATLAB */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* 'atan3:18' epsilon = 0.0000000001; */
    /* 'atan3:20' pidiv2 = 0.5 * pi; */
    /* 'atan3:22' if (abs(a) < epsilon) */
    if (fabs(vxh[1]) < 1.0E-10) {
      /* 'atan3:23' y = (1 - sign(b)) * pidiv2; */
      if (vxh[0] < 0.0) {
        days = -1.0;
      } else if (vxh[0] > 0.0) {
        days = 1.0;
      } else if (vxh[0] == 0.0) {
        days = 0.0;
      } else {
        days = vxh[0];
      }

      c_0 = (1.0 - days) * 1.5707963267948966;
    } else {
      /* 'atan3:25' else */
      /* 'atan3:26' c = (2 - sign(a)) * pidiv2; */
      if (vxh[1] < 0.0) {
        days = -1.0;
      } else if (vxh[1] > 0.0) {
        days = 1.0;
      } else if (vxh[1] == 0.0) {
        days = 0.0;
      } else {
        days = vxh[1];
      }

      c_0 = (2.0 - days) * 1.5707963267948966;

      /* 'atan3:29' if (abs(b) < epsilon) */
      if (!(fabs(vxh[0]) < 1.0E-10)) {
        /* 'atan3:32' else */
        /* 'atan3:33' y = c + sign(a) * sign(b) * (abs(atan(a / b)) - pidiv2); */
        if (vxh[1] < 0.0) {
          days = -1.0;
        } else if (vxh[1] > 0.0) {
          days = 1.0;
        } else if (vxh[1] == 0.0) {
          days = 0.0;
        } else {
          days = vxh[1];
        }

        if (vxh[0] < 0.0) {
          day_num = -1.0;
        } else if (vxh[0] > 0.0) {
          day_num = 1.0;
        } else if (vxh[0] == 0.0) {
          day_num = 0.0;
        } else {
          day_num = vxh[0];
        }

        c_0 += (fabs(atan(vxh[1] / vxh[0])) - 1.5707963267948966) * (days *
          day_num);
      } else {
        /* 'atan3:30' y = c; */
      }
    }

    /* '<S8>:1:126' temp = sqrt(hv(1) * hv(1) + hv(2) * hv(2)); */
    /* '<S8>:1:128' xinck = atan2(temp, hv(3)); */
    xinck = rt_atan2d_snf(sqrt(hv[0] * hv[0] + hv[1] * hv[1]), hv[2]);

    /* '<S8>:1:130' vwrk = dot(vec, vxhhat); */
    /* '<S8>:1:132' temp = vwrk / ek; */
    D_sun = ((pos_eci_m[0] * vxh[0] + pos_eci_m[1] * vxh[1]) + pos_eci_m[2] *
             D_sun) / M_moon;

    /* '<S8>:1:134' wk = acos(temp); */
    day_num = acos(D_sun);

    /* '<S8>:1:136' if (vec(3) < 0.0d0) */
    if (pos_eci_m[2] < 0.0) {
      /* '<S8>:1:137' wk = mod(pi2 - wk, pi2); */
      day_num = (6.2831853071795862 - day_num) / 6.2831853071795862;
      if (fabs(day_num - rt_roundd_snf(day_num)) <= 2.2204460492503131E-16 *
          fabs(day_num)) {
        day_num = 0.0;
      } else {
        day_num = (day_num - floor(day_num)) * 6.2831853071795862;
      }
    }

    /* '<S8>:1:140' aodp = pl / (1.0d0 - ek * ek); */
    u_moon = M_sun / (1.0 - M_moon * M_moon);

    /*  right here - ek causes aodp to be negative, inducing complex numbers */
    /*  throughout the rest of the code. Should have ek < 1. Fix here. */
    /* '<S8>:1:142' aodp = real(aodp); */
    /* '<S8>:1:144' xn = xke * aodp^(-1.5); */
    xn = 0.074366916133173408 * rt_powd_snf(u_moon, -1.5);

    /*  in the first loop the osculating elements rk, uk, xnodek, xinck, rdotk, */
    /*  and rfdotk are used as anchors to find the corresponding final sgp4 */
    /*  mean elements r, u, xnodeo, xincl, rdot, and rfdot. several other final */
    /*  mean values based on these are also found: betal, cosio, sinio, theta2, */
    /*  cos2u, sin2u, x3thm1, x7thm1, x1mth2. in addition, the osculating values */
    /*  initially held by aodp, pl, and xn are replaced by intermediate */
    /*  (not osculating and not mean) values used by sgp4. the loop converges */
    /*  on the value of pl in about four iterations. */
    /*  seed value for first loop */
    /* '<S8>:1:158' xincl = xinck; */
    days = xinck;

    /* '<S8>:1:160' u = uk; */
    deps_1980 = uk;

    /* '<S8>:1:162' for i = 1:1:20 */
    i = 0;
    exitg3 = false;
    while ((!exitg3) && (i < 20)) {
      /* '<S8>:1:164' a2 = pl; */
      M_moon = M_sun;

      /* '<S8>:1:166' betal = sqrt(pl / aodp); */
      /* '<S8>:1:168' temp1 = ck2 / pl; */
      temp1 = 0.0005413079 / M_sun;

      /* '<S8>:1:170' temp2 = temp1 / pl; */
      temp2 = temp1 / M_sun;

      /* '<S8>:1:172' cosio = cos(xincl); */
      cosio = cos(days);

      /* '<S8>:1:174' sinio = sin(xincl); */
      sinio = sin(days);

      /* '<S8>:1:176' sin2u = sin(2.0d0 * u); */
      sin2u = sin(2.0 * deps_1980);

      /* '<S8>:1:178' cos2u = cos(2.0d0 * u); */
      D_sun = cos(2.0 * deps_1980);

      /* '<S8>:1:180' theta2 = cosio * cosio; */
      theta2 = cosio * cosio;

      /* '<S8>:1:182' x3thm1 = 3.0d0 * theta2 - 1.0d0; */
      x3thm1 = 3.0 * theta2 - 1.0;

      /* '<S8>:1:184' x1mth2 = 1.0d0 - theta2; */
      /* '<S8>:1:186' x7thm1 = 7.0d0 * theta2 - 1.0d0; */
      /* '<S8>:1:188' r = (rk - 0.5d0 * temp1 * x1mth2 * cos2u) ... */
      /* '<S8>:1:189'         / (1.0d0 - 1.5d0 * temp2 * betal * x3thm1); */
      r = (rk - 0.5 * temp1 * (1.0 - theta2) * D_sun) / (1.0 - 1.5 * temp2 *
        sqrt(M_sun / u_moon) * x3thm1);

      /* '<S8>:1:191' u = uk + 0.25d0 * temp2 * x7thm1 * sin2u; */
      deps_1980 = (7.0 * theta2 - 1.0) * (0.25 * temp2) * sin2u + uk;

      /* '<S8>:1:193' xnodeo = xnodek - 1.5d0 * temp2 * cosio * sin2u; */
      dayofyear = c_0 - 1.5 * temp2 * cosio * sin2u;

      /* '<S8>:1:195' xincl = xinck - 1.5d0 * temp2 * cosio * sinio * cos2u; */
      days = xinck - 1.5 * temp2 * cosio * sinio * D_sun;

      /* '<S8>:1:197' rdot = rdotk + xn * temp1 * x1mth2 * sin2u; */
      temp2 = xn * temp1 * (1.0 - theta2) * sin2u + rdotk;

      /* '<S8>:1:199' rfdot = rfdotk - xn * temp1 * (x1mth2 * cos2u + 1.5d0 * x3thm1); */
      u_moon = rfdotk - ((1.0 - theta2) * D_sun + 1.5 * x3thm1) * (xn * temp1);

      /* '<S8>:1:201' temp = r * rfdot / xke; */
      D_sun = r * u_moon / 0.074366916133173408;

      /* '<S8>:1:203' pl = temp * temp; */
      M_sun = D_sun * D_sun;

      /* '<S8>:1:205' temp = 2.0d0 / r - (rdot * rdot + rfdot * rfdot) / (xke * xke); */
      D_sun = 2.0 / r - (temp2 * temp2 + u_moon * u_moon) / 0.005530438215158447;

      /* '<S8>:1:207' aodp = 1.0d0 / temp; */
      u_moon = 1.0 / D_sun;

      /* '<S8>:1:209' xn = xke * aodp ^ (-1.5d0); */
      xn = 0.074366916133173408 * rt_powd_snf(u_moon, -1.5);

      /* '<S8>:1:211' if (abs(a2 - pl) < 1.0e-13) */
      if (fabs(M_moon - M_sun) < 1.0E-13) {
        exitg3 = true;
      } else {
        /*      if (i == 20) */
        /*          fprintf('\n20 iterations in first loop'); */
        /*      end */
        i++;
      }
    }

    /*  the next values are calculated from constants and a combination of mean */
    /*  and intermediate quantities from the first loop. these values all remain */
    /*  fixed and are used in the second loop. */
    /*  preliminary values for the second loop */
    /* '<S8>:1:226' ecose = 1.0d0 - r / aodp; */
    rk = r / u_moon;
    rdotk = 1.0 - r / u_moon;

    /* '<S8>:1:228' esine = r * rdot / (xke * sqrt(aodp)); */
    temp2 = r * temp2 / (0.074366916133173408 * sqrt(u_moon));

    /* '<S8>:1:230' elsq = 1.0d0 - pl / aodp; */
    /* '<S8>:1:232' xlcof = 0.125d0 * a3ovk2 * sinio * (3.0d0 + 5.0d0 * cosio) / (1.0d0 + cosio); */
    /* '<S8>:1:234' aycof = 0.25d0 * a3ovk2 * sinio; */
    rfdotk = 0.0011725350766172082 * sinio;

    /* '<S8>:1:236' temp1 = esine / (1.0d0 + sqrt(1.0d0 - elsq)); */
    temp1 = temp2 / (sqrt(1.0 - (1.0 - M_sun / u_moon)) + 1.0);

    /* '<S8>:1:238' cosu = cos(u); */
    uk = cos(deps_1980);

    /* '<S8>:1:240' sinu = sin(u); */
    c_0 = sin(deps_1980);

    /*  the second loop normally converges in about six iterations to the final */
    /*  mean value for the eccentricity, eo. the mean perigee, omegao, is also */
    /*  determined. cosepw and sinepw are found to twelve decimal places and */
    /*  are used to calculate an intermediate value for the eccentric anomaly, */
    /*  temp2. temp2 is then used in kepler's equation to find an intermediate */
    /*  value for the true longitude, capu. */
    /*  seed values for loop */
    /* '<S8>:1:251' eo = sqrt(elsq); */
    deps_1980 = sqrt(1.0 - M_sun / u_moon);

    /* '<S8>:1:253' omegao = wk; */
    /* '<S8>:1:255' axn = eo * cos(omegao); */
    M_sun = deps_1980 * cos(day_num);

    /* '<S8>:1:257' for i = 1:1:20 */
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 20)) {
      /* '<S8>:1:259' a2 = eo; */
      M_moon = deps_1980;

      /* '<S8>:1:261' beta = 1.0d0 - eo * eo; */
      beta = 1.0 - deps_1980 * deps_1980;

      /* '<S8>:1:263' temp = 1.0d0 / (aodp * beta); */
      D_sun = 1.0 / (u_moon * beta);

      /* '<S8>:1:265' aynl = temp * aycof; */
      xinck = D_sun * rfdotk;

      /* '<S8>:1:267' ayn = eo * sin(omegao) + aynl; */
      ayn = deps_1980 * sin(day_num) + xinck;

      /* '<S8>:1:269' cosepw = r * cosu / aodp + axn - ayn * temp1; */
      cosepw = (r * uk / u_moon + M_sun) - ayn * temp1;

      /* '<S8>:1:271' sinepw = r * sinu / aodp + ayn + axn * temp1; */
      ayn = (r * c_0 / u_moon + ayn) + M_sun * temp1;

      /* '<S8>:1:273' axn = cosepw * ecose + sinepw * esine; */
      M_sun = (1.0 - rk) * cosepw + ayn * temp2;

      /* '<S8>:1:275' ayn = sinepw * ecose - cosepw * esine; */
      /* '<S8>:1:277' omegao = mod(atan2(ayn - aynl, axn), pi2); */
      day_num = rt_atan2d_snf((ayn * rdotk - cosepw * temp2) - xinck, M_sun) /
        6.2831853071795862;
      if (fabs(day_num - rt_roundd_snf(day_num)) <= 2.2204460492503131E-16 *
          fabs(day_num)) {
        day_num = 0.0;
      } else {
        day_num = (day_num - floor(day_num)) * 6.2831853071795862;
      }

      /* '<S8>:1:279' if (eo > 0.5d0) */
      if (deps_1980 > 0.5) {
        /* '<S8>:1:280' eo = 0.9d0 * eo + 0.1d0 * (axn / cos(omegao)); */
        deps_1980 = M_sun / cos(day_num) * 0.1 + 0.9 * deps_1980;
      } else {
        /* '<S8>:1:281' else */
        /* '<S8>:1:282' eo = axn / cos(omegao); */
        deps_1980 = M_sun / cos(day_num);
      }

      /* '<S8>:1:285' if (eo > 0.999d0) */
      if (deps_1980 > 0.999) {
        /* '<S8>:1:286' eo = 0.999d0; */
        deps_1980 = 0.999;
      }

      /* '<S8>:1:289' if (abs(a2 - eo) < 1.0e-9) */
      if (fabs(M_moon - deps_1980) < 1.0E-9) {
        exitg2 = true;
      } else {
        /*      if (i == 20) */
        /*          fprintf('\n20 iterations in second loop'); */
        /*      end */
        i++;
      }
    }

    /* '<S8>:1:298' temp2 = atan2(sinepw, cosepw); */
    /* '<S8>:1:300' capu = temp2 - esine; */
    /* '<S8>:1:302' xll = temp * xlcof * axn; */
    /*  xll adjusts the intermediate true longitude */
    /*  capu, to the mean true longitude, xl */
    /* '<S8>:1:307' xl = capu - xll; */
    /* '<S8>:1:309' xmo = mod(xl - omegao, pi2); */
    temp1 = (((rt_atan2d_snf(ayn, cosepw) - temp2) - (5.0 * cosio + 3.0) *
              (0.00058626753830860409 * sinio) / (1.0 + cosio) * D_sun * M_sun)
             - day_num) / 6.2831853071795862;
    if (fabs(temp1 - rt_roundd_snf(temp1)) <= 2.2204460492503131E-16 * fabs
        (temp1)) {
      temp1 = 0.0;
    } else {
      temp1 = (temp1 - floor(temp1)) * 6.2831853071795862;
    }

    /*  the third loop usually converges after three iterations to the */
    /*  mean semi-major axis, a1, which is then used to find the mean motion, xno */
    /* '<S8>:1:314' a0 = aodp; */
    cosio = u_moon;

    /* '<S8>:1:316' a1 = a0; */
    sinio = u_moon;

    /* '<S8>:1:318' beta2 = sqrt(beta); */
    /* '<S8>:1:320' temp = 1.5d0 * ck2 * x3thm1 / (beta * beta2); */
    D_sun = 0.00081196185 * x3thm1 / (beta * sqrt(beta));

    /* '<S8>:1:322' for i = 1:1:20 */
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 20)) {
      /* '<S8>:1:324' a2 = a1; */
      M_moon = sinio;

      /* '<S8>:1:326' d0 = temp / (a0 * a0); */
      /* '<S8>:1:328' a0 = aodp * (1.0d0 - d0); */
      cosio = (1.0 - D_sun / (cosio * cosio)) * u_moon;

      /* '<S8>:1:330' d1 = temp / (a1 * a1); */
      x3thm1 = D_sun / (sinio * sinio);

      /* '<S8>:1:332' a1 = a0 / (1.0d0 - d1 / 3.0d0 - d1 * d1 - 134.0d0 * d1 * d1 * d1 / 81.0d0); */
      sinio = cosio / (((1.0 - x3thm1 / 3.0) - x3thm1 * x3thm1) - 134.0 * x3thm1
                       * x3thm1 * x3thm1 / 81.0);

      /* '<S8>:1:334' if (abs(a2 - a1) < 1.0e-13) */
      if (fabs(M_moon - sinio) < 1.0E-13) {
        exitg1 = true;
      } else {
        /*      if (i == 20) */
        /*          fprintf('\n20 iterations in third loop'); */
        /*      end */
        i++;
      }
    }

    /* '<S8>:1:343' xno = xke * a1 ^ (-1.5d0); */
    /* '<S8>:1:345' xno = xno / (pi2 / 1440.0d0); */
    u_moon = 0.074366916133173408 * rt_powd_snf(sinio, -1.5) /
      0.0043633231299858239;

    /*  Convert to right units */
    /* '<S8>:1:348' xmo     = RAD2DEG*xmo; */
    temp1 *= 57.295779513082323;

    /* '<S8>:1:349' xincl   = RAD2DEG*xincl; */
    days *= 57.295779513082323;

    /* '<S8>:1:350' omegao  = RAD2DEG*omegao; */
    day_num *= 57.295779513082323;

    /* '<S8>:1:351' xnodeo  = RAD2DEG*xnodeo; */
    dayofyear *= 57.295779513082323;
  }

  /* Outport: '<Root>/Outport2' */
  /*  function */
  rtY.Outport2 = T1900;

  /* MATLAB Function: '<S10>/MATLAB Function' */
  tmp[0] = cos(day);
  tmp[3] = sin(day);
  tmp[6] = 0.0;
  tmp[1] = -sin(day);
  tmp[4] = cos(day);
  tmp[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      c_1[i + 3 * i_0] = 0.0;
      c_1[i + 3 * i_0] += tod_to_mod[3 * i_0] * rtb_mod_to_gcrf[i];
      c_1[i + 3 * i_0] += tod_to_mod[3 * i_0 + 1] * rtb_mod_to_gcrf[i + 3];
      c_1[i + 3 * i_0] += tod_to_mod[3 * i_0 + 2] * rtb_mod_to_gcrf[i + 6];
    }

    tmp[2 + 3 * i] = d[i];
  }

  /* Outport: '<Root>/Outport3' incorporates:
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtY.Outport3[i_0 + 3 * i] = 0.0;
      rtY.Outport3[i_0 + 3 * i] += tmp[3 * i] * c_1[i_0];
      rtY.Outport3[i_0 + 3 * i] += tmp[3 * i + 1] * c_1[i_0 + 3];
      rtY.Outport3[i_0 + 3 * i] += tmp[3 * i + 2] * c_1[i_0 + 6];
    }
  }

  /* End of Outport: '<Root>/Outport3' */

  /* Outport: '<Root>/Outport4' */
  for (i = 0; i < 6; i++) {
    rtY.Outport4[i] = rtb_time_vec_ut1[i];
  }

  /* End of Outport: '<Root>/Outport4' */

  /* Outport: '<Root>/Outport5' incorporates:
   *  MATLAB Function: '<S12>/Translate to UT1'
   */
  rtY.Outport5 = JD_days_gps - 2.451545E+6;

  /* Outport: '<Root>/Outport6' */
  memcpy(&rtY.Outport6[0], &rtb_teme_to_gcrf[0], 9U * sizeof(real_T));

  /* Update for RateTransition: '<S1>/Rate Transition7' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  MATLAB Function: '<S12>/Translate to UT1'
   *  MATLAB Function: '<S7>/MATLAB Function'
   *  Sum: '<S7>/Sum'
   */
  rtDW.RateTransition7_Buffer0[0] = rtb_time_vec_ut1[0] - 2000.0;
  rtDW.RateTransition7_Buffer0[1] = JD_days_gps;
  rtDW.RateTransition7_Buffer0[2] = 3.2923E-5;
  rtDW.RateTransition7_Buffer0[3] = days;
  rtDW.RateTransition7_Buffer0[4] = dayofyear;
  rtDW.RateTransition7_Buffer0[5] = deps_1980;
  rtDW.RateTransition7_Buffer0[6] = day_num;
  rtDW.RateTransition7_Buffer0[7] = temp1;
  rtDW.RateTransition7_Buffer0[8] = u_moon;

  /* Update for RateTransition: '<S1>/Rate Transition8' */
  rtDW.RateTransition8_Buffer0[0] = rtb_cur_gps_time[0];
  rtDW.RateTransition8_Buffer0[1] = rtb_cur_gps_time[1];

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  rtDW.UnitDelay_DSTATE[0] = rtb_cur_gps_time[0];
  rtDW.UnitDelay_DSTATE[1] = rtb_cur_gps_time[1];

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE[0] = rtb_MultiportSwitch1_idx_0;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[0] = rtb_MultiportSwitch2_idx_0;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE[1] = rtb_MultiportSwitch1_idx_1;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[1] = rtb_MultiportSwitch2_idx_1;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE[2] = rtb_MultiportSwitch1_idx_2;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE[2] = rtb_MultiportSwitch2_idx_2;
}

/* Model initialize function */
void sensor_processing_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void sensor_processing_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
