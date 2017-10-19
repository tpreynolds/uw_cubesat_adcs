/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mag_vector.c
 *
 * Code generated for Simulink model 'mag_vector'.
 *
 * Model version                  : 1.153
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Oct 19 12:03:49 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->MSP430
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "mag_vector.h"
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
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo);
int32_T mul_s32_sat(int32_T a, int32_T b);
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
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);

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

void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0L ? ~(uint32_T)in0 + 1UL : (uint32_T)in0;
  absIn1 = in1 < 0L ? ~(uint32_T)in1 + 1UL : (uint32_T)in1;
  in0Hi = absIn0 >> 16UL;
  in0Lo = absIn0 & 65535UL;
  in1Hi = absIn1 >> 16UL;
  absIn0 = absIn1 & 65535UL;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0UL;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16UL) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1UL;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16UL;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16UL) + (productHiLo >> 16UL)) + in0Hi * in1Hi) +
    absIn1;
  if (!((in0 == 0L) || ((in1 == 0L) || ((in0 > 0L) == (in1 > 0L))))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0UL) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0L) || ((u32_chi == 0UL) && (u32_clo >= 2147483648UL)))
  {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1L) || (((int32_T)u32_chi == -1L) && (u32_clo <
    2147483648UL))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
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
void mag_vector_step(void)
{
  int8_T Lmonth[12];
  static const int8_T b[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  real_T rtb_sqrt;
  int8_T s10_iter;
  real_T rtb_VectorConcatenate[9];
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_LogicalOperator;
  real_T rtb_MatrixMultiply2[3];
  real_T rtb_MathFunction[3];
  real_T rtb_Switch_g;
  real_T rtb_sincos_o1_n;
  real_T rtb_sincos_o2_m;
  real_T rtb_TrigonometricFunction4;
  int16_T s87_iter;
  int16_T s46_iter;
  real_T rtb_Assignment[11];
  real_T rtb_Assignment1[11];
  int32_T rtb_Sum1_iz;
  real_T rtb_TmpSignalConversionAtppnInp[13];
  real_T rtb_tc_old[169];
  real_T Assignment[169];
  real_T Assignment2[169];
  real_T rtb_VectorConcatenate_0[3];
  int16_T i;
  real_T rtb_UnitConversion_idx_0;
  real_T rtb_sincos_o1_l_idx_0;
  real_T rtb_sincos_o1_l_idx_1;
  real_T UnitDelay2_DSTATE_idx_3;
  real_T rtb_sincos_o1_idx_0;
  real_T rtb_UnitConversion_idx_1;
  real_T rtb_sincos_o2_jg_idx_0;
  real_T rtb_sincos_o2_idx_0;
  real_T rtb_Sum1_o_idx_3;
  real_T rtb_Sum1_o_idx_1;
  real_T rtb_Sum1_o_idx_0;
  real_T rtb_Sum1_o_idx_2;
  real_T UnitDelay2_DSTATE_idx_2;
  int16_T qY;
  int16_T qY_0;
  int16_T qY_1;
  int16_T qY_2;
  int32_T rtb_Sum1_m;

  /* Sqrt: '<S8>/sqrt' incorporates:
   *  Inport: '<Root>/pos_ecef_m'
   *  Product: '<S8>/Product2'
   *  Product: '<S8>/Product3'
   *  Sum: '<S8>/Sum2'
   */
  rtb_sqrt = sqrt(rtU.pos_ecef_m[0] * rtU.pos_ecef_m[0] + rtU.pos_ecef_m[1] *
                  rtU.pos_ecef_m[1]);

  /* Outputs for Iterator SubSystem: '<S2>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S10>/While Iterator'
   */
  s10_iter = 1;
  do {
    rtb_Switch_g = rtDW.Memory_PreviousInput;
    if (!(s10_iter > 0)) {
      rtb_Switch_g = rt_atan2d_snf(rtU.pos_ecef_m[2], 0.99664718933525254 *
        rtb_sqrt);
    }

    rtb_sincos_o1_n = sin(rtb_Switch_g);
    rtb_sincos_o2_m = cos(rtb_Switch_g);
    rtb_TrigonometricFunction4 = rt_atan2d_snf(42841.31151331366 *
      rtb_sincos_o1_n * rtb_sincos_o1_n * rtb_sincos_o1_n + rtU.pos_ecef_m[2],
      rtb_sqrt - rtb_sincos_o2_m * rtb_sincos_o2_m * rtb_sincos_o2_m *
      0.00669437999014133 * 6.378137E+6);
    rtb_sincos_o1_n = rt_atan2d_snf(0.99664718933525254 * sin
      (rtb_TrigonometricFunction4), cos(rtb_TrigonometricFunction4));
    rtDW.Memory_PreviousInput = rtb_sincos_o1_n;
    s10_iter++;
  } while ((rtb_Switch_g != rtb_sincos_o1_n) && (s10_iter <= 5));

  /* End of Outputs for SubSystem: '<S2>/While Iterator Subsystem' */

  /* UnitConversion: '<S7>/Unit Conversion' incorporates:
   *  Inport: '<Root>/pos_ecef_m'
   *  Trigonometry: '<S2>/Trigonometric Function2'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_UnitConversion_idx_0 = 57.295779513082323 * rtb_TrigonometricFunction4;
  rtb_UnitConversion_idx_1 = 57.295779513082323 * rt_atan2d_snf(rtU.pos_ecef_m[1],
    rtU.pos_ecef_m[0]);

  /* UnitConversion: '<S26>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtb_Switch_g = 0.017453292519943295 * rtb_UnitConversion_idx_0;

  /* Trigonometry: '<S3>/sincos' */
  rtb_sincos_o1_n = cos(rtb_Switch_g);
  rtb_Switch_g = sin(rtb_Switch_g);
  rtb_sincos_o1_l_idx_0 = rtb_sincos_o1_n;

  /* UnitConversion: '<S26>/Unit Conversion' */
  rtb_sincos_o2_jg_idx_0 = rtb_Switch_g;
  rtb_Switch_g = 0.017453292519943295 * rtb_UnitConversion_idx_1;

  /* Trigonometry: '<S3>/sincos' */
  rtb_sincos_o1_n = cos(rtb_Switch_g);
  rtb_Switch_g = sin(rtb_Switch_g);

  /* UnaryMinus: '<S17>/Unary Minus' incorporates:
   *  Product: '<S17>/u(1)*u(4)'
   *  Trigonometry: '<S3>/sincos'
   */
  rtb_VectorConcatenate[0] = -(rtb_sincos_o2_jg_idx_0 * rtb_sincos_o1_n);

  /* UnaryMinus: '<S20>/Unary Minus' */
  rtb_VectorConcatenate[1] = -rtb_Switch_g;

  /* UnaryMinus: '<S23>/Unary Minus' incorporates:
   *  Product: '<S23>/u(3)*u(4)'
   *  Trigonometry: '<S3>/sincos'
   */
  rtb_VectorConcatenate[2] = -(rtb_sincos_o1_l_idx_0 * rtb_sincos_o1_n);

  /* UnaryMinus: '<S18>/Unary Minus' incorporates:
   *  Product: '<S18>/u(1)*u(2)'
   */
  rtb_VectorConcatenate[3] = -(rtb_sincos_o2_jg_idx_0 * rtb_Switch_g);

  /* SignalConversion: '<S27>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S3>/sincos'
   */
  rtb_VectorConcatenate[4] = rtb_sincos_o1_n;

  /* UnaryMinus: '<S24>/Unary Minus' incorporates:
   *  Product: '<S24>/u(2)*u(3)'
   */
  rtb_VectorConcatenate[5] = -(rtb_Switch_g * rtb_sincos_o1_l_idx_0);

  /* SignalConversion: '<S27>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_VectorConcatenate[6] = rtb_sincos_o1_l_idx_0;

  /* SignalConversion: '<S27>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S22>/Constant'
   */
  rtb_VectorConcatenate[7] = 0.0;

  /* UnaryMinus: '<S25>/Unary Minus' */
  rtb_VectorConcatenate[8] = -rtb_sincos_o2_jg_idx_0;

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Inport: '<Root>/time_vec'
   */
  /*  UW HuskySat 1, ADCS Subsystem */
  /*    T. Reynolds, Updated: 8.24.17 */
  /* MATLAB Function 'mag_vector/MATLAB Function': '<S4>:1' */
  /*  Converts a time vector into a decimal year number. See Vallado pp 200-201 */
  /*  for reference algorithms. */
  /* '<S4>:1:9' year    = time_vec(1); */
  /* '<S4>:1:10' month   = time_vec(2); */
  /* '<S4>:1:11' day     = time_vec(3); */
  /* '<S4>:1:12' hour    = time_vec(4); */
  /* '<S4>:1:13' min     = time_vec(5); */
  /* '<S4>:1:14' sec     = time_vec(6); */
  /*  find day of year - valid until 2100 */
  /* '<S4>:1:17' Lmonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; */
  for (s87_iter = 0; s87_iter < 12; s87_iter++) {
    Lmonth[s87_iter] = b[s87_iter];
  }

  /* '<S4>:1:18' days_in_year    = 365.25; */
  rtb_Switch_g = 365.25;

  /* '<S4>:1:20' if mod(year,4) == 0 */
  if (rtU.time_vec[0] - floor(rtU.time_vec[0] / 4.0) * 4.0 == 0.0) {
    /* '<S4>:1:21' Lmonth(2) = 29; */
    Lmonth[1] = 29;

    /* '<S4>:1:22' days_in_year    = 366; */
    rtb_Switch_g = 366.0;
  }

  /* '<S4>:1:25' day_of_year = 0; */
  rtb_sincos_o1_n = 0.0;

  /* '<S4>:1:26' for i = 1:month-1 */
  for (s87_iter = 0; s87_iter < (int16_T)(rtU.time_vec[1] - 1.0); s87_iter++) {
    /* '<S4>:1:27' day_of_year = day_of_year + Lmonth(i); */
    rtb_sincos_o1_n += (real_T)Lmonth[s87_iter];
  }

  /*  Add number of days into the month */
  /* '<S4>:1:31' day_of_year = day_of_year + day; */
  rtb_sincos_o1_n += rtU.time_vec[2];

  /*  Add HMS info to the day of year */
  /* '<S4>:1:34' day_of_year    = day_of_year + hour/24 + min/1440 + sec/86400; */
  rtb_sincos_o1_n = ((rtU.time_vec[3] / 24.0 + rtb_sincos_o1_n) + rtU.time_vec[4]
                     / 1440.0) + rtU.time_vec[5] / 86400.0;

  /*  Find the year fraction represented by day_of_year */
  /* '<S4>:1:37' day_frac    = day_of_year/days_in_year; */
  /*  Sum to get total decimal year */
  /* '<S4>:1:40' dec_year = year + day_frac; */
  rtb_Switch_g = rtb_sincos_o1_n / rtb_Switch_g + rtU.time_vec[0];

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* RelationalOperator: '<S44>/Relational Operator' incorporates:
   *  Memory: '<S44>/otime'
   */
  rtb_RelationalOperator = (rtb_Switch_g != rtDW.otime_PreviousInput);

  /* Saturate: '<S6>/+//- 180 deg' */
  if (rtb_UnitConversion_idx_1 > 180.0) {
    rtb_sincos_o1_n = 180.0;
  } else if (rtb_UnitConversion_idx_1 < -180.0) {
    rtb_sincos_o1_n = -180.0;
  } else {
    rtb_sincos_o1_n = rtb_UnitConversion_idx_1;
  }

  /* End of Saturate: '<S6>/+//- 180 deg' */

  /* Saturate: '<S6>/+//- 90 deg' */
  if (rtb_UnitConversion_idx_0 > 90.0) {
    rtb_sincos_o2_m = 90.0;
  } else if (rtb_UnitConversion_idx_0 < -90.0) {
    rtb_sincos_o2_m = -90.0;
  } else {
    rtb_sincos_o2_m = rtb_UnitConversion_idx_0;
  }

  /* End of Saturate: '<S6>/+//- 90 deg' */

  /* UnitConversion: '<S88>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtb_sincos_o1_l_idx_0 = 0.017453292519943295 * rtb_sincos_o1_n;
  rtb_sincos_o1_l_idx_1 = 0.017453292519943295 * rtb_sincos_o2_m;

  /* Trigonometry: '<S41>/sincos' */
  rtb_sincos_o1_idx_0 = sin(rtb_sincos_o1_l_idx_0);
  rtb_sincos_o2_idx_0 = cos(rtb_sincos_o1_l_idx_0);
  rtb_sincos_o2_jg_idx_0 = sin(rtb_sincos_o1_l_idx_1);
  rtb_sincos_o1_l_idx_1 = cos(rtb_sincos_o1_l_idx_1);

  /* Outputs for Enabled SubSystem: '<S36>/Convert from geodetic to  spherical coordinates ' incorporates:
   *  EnablePort: '<S40>/Enable'
   */
  /* RelationalOperator: '<S43>/Relational Operator' incorporates:
   *  Memory: '<S43>/olon'
   */
  if (rtb_sincos_o1_n != rtDW.olon_PreviousInput) {
    /* Outputs for Iterator SubSystem: '<S40>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S87>/For Iterator'
     */
    for (s87_iter = 1; s87_iter < 12; s87_iter++) {
      /* Switch: '<S87>/cp[m-1] sp[m-1]' incorporates:
       *  Inport: '<S40>/cp[2]'
       *  Inport: '<S40>/sp[2]'
       *  UnitDelay: '<S87>/Unit Delay1'
       */
      if (s87_iter > 1) {
        rtb_UnitConversion_idx_0 = rtDW.UnitDelay1_DSTATE[0];
        rtb_UnitConversion_idx_1 = rtDW.UnitDelay1_DSTATE[1];
      } else {
        rtb_UnitConversion_idx_0 = rtb_sincos_o2_idx_0;
        rtb_UnitConversion_idx_1 = rtb_sincos_o1_idx_0;
      }

      /* End of Switch: '<S87>/cp[m-1] sp[m-1]' */

      /* Sum: '<S87>/Sum2' incorporates:
       *  Inport: '<S40>/cp[2]'
       *  Inport: '<S40>/sp[2]'
       *  Product: '<S87>/Product1'
       *  Product: '<S87>/Product2'
       */
      rtb_sincos_o1_l_idx_0 = rtb_UnitConversion_idx_0 * rtb_sincos_o1_idx_0 +
        rtb_UnitConversion_idx_1 * rtb_sincos_o2_idx_0;

      /* Assignment: '<S87>/Assignment' incorporates:
       *  Assignment: '<S87>/Assignment1'
       *  Constant: '<S87>/Constant'
       *  Constant: '<S87>/Constant1'
       */
      if (s87_iter == 1) {
        memcpy(&rtb_Assignment[0], &rtConstP.pooled11[0], 11U * sizeof(real_T));
        memcpy(&rtb_Assignment1[0], &rtConstP.pooled11[0], 11U * sizeof(real_T));
      }

      rtb_Assignment[s87_iter - 1] = rtb_sincos_o1_l_idx_0;

      /* End of Assignment: '<S87>/Assignment' */

      /* Sum: '<S87>/Sum1' incorporates:
       *  Inport: '<S40>/cp[2]'
       *  Inport: '<S40>/sp[2]'
       *  Product: '<S87>/Product3'
       *  Product: '<S87>/Product8'
       */
      rtb_UnitConversion_idx_0 = rtb_UnitConversion_idx_0 * rtb_sincos_o2_idx_0
        - rtb_UnitConversion_idx_1 * rtb_sincos_o1_idx_0;

      /* Assignment: '<S87>/Assignment1' */
      rtb_Assignment1[s87_iter - 1] = rtb_UnitConversion_idx_0;

      /* Update for UnitDelay: '<S87>/Unit Delay1' */
      rtDW.UnitDelay1_DSTATE[0] = rtb_UnitConversion_idx_0;
      rtDW.UnitDelay1_DSTATE[1] = rtb_sincos_o1_l_idx_0;
    }

    /* End of Outputs for SubSystem: '<S40>/For Iterator Subsystem' */

    /* SignalConversion: '<S40>/OutportBufferForcp[13]' incorporates:
     *  Constant: '<S40>/cp[1]'
     *  Inport: '<S40>/cp[2]'
     */
    rtDW.OutportBufferForcp13[0] = 1.0;
    rtDW.OutportBufferForcp13[1] = rtb_sincos_o2_idx_0;

    /* SignalConversion: '<S40>/OutportBufferForsp[13]' incorporates:
     *  Constant: '<S40>/sp[1]'
     *  Inport: '<S40>/sp[2]'
     */
    rtDW.OutportBufferForsp13[0] = 0.0;
    rtDW.OutportBufferForsp13[1] = rtb_sincos_o1_idx_0;

    /* SignalConversion: '<S40>/OutportBufferForcp[13]' */
    memcpy(&rtDW.OutportBufferForcp13[2], &rtb_Assignment1[0], 11U * sizeof
           (real_T));

    /* SignalConversion: '<S40>/OutportBufferForsp[13]' */
    memcpy(&rtDW.OutportBufferForsp13[2], &rtb_Assignment[0], 11U * sizeof
           (real_T));
  }

  /* End of RelationalOperator: '<S43>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S36>/Convert from geodetic to  spherical coordinates ' */

  /* Trigonometry: '<S9>/sincos' */
  rtb_sincos_o1_idx_0 = sin(rtb_TrigonometricFunction4);

  /* Product: '<S9>/Product2' */
  rtb_UnitConversion_idx_1 = rtb_sincos_o1_idx_0 * 0.00669437999014133;

  /* Product: '<S9>/Product3' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/f'
   *  Product: '<S9>/Product1'
   *  Sqrt: '<S9>/sqrt'
   *  Sum: '<S9>/Sum'
   */
  rtb_UnitConversion_idx_0 = 6.378137E+6 / sqrt(1.0 - rtb_UnitConversion_idx_1 *
    rtb_sincos_o1_idx_0);

  /* Sum: '<S9>/Sum3' incorporates:
   *  Inport: '<Root>/pos_ecef_m'
   *  Product: '<S9>/Product4'
   *  Product: '<S9>/Product5'
   *  Product: '<S9>/Product6'
   *  Sum: '<S9>/Sum2'
   *  Trigonometry: '<S9>/sincos'
   */
  rtb_UnitConversion_idx_0 = ((rtb_UnitConversion_idx_1 *
    rtb_UnitConversion_idx_0 + rtU.pos_ecef_m[2]) * rtb_sincos_o1_idx_0 -
    rtb_UnitConversion_idx_0) + cos(rtb_TrigonometricFunction4) * rtb_sqrt;

  /* Saturate: '<S6>/0 to 1,000,000 m' */
  if (rtb_UnitConversion_idx_0 > 1.0E+6) {
    rtb_UnitConversion_idx_0 = 1.0E+6;
  } else {
    if (rtb_UnitConversion_idx_0 < 0.0) {
      rtb_UnitConversion_idx_0 = 0.0;
    }
  }

  /* End of Saturate: '<S6>/0 to 1,000,000 m' */

  /* Gain: '<S6>/Gain' */
  rtb_sqrt = 0.001 * rtb_UnitConversion_idx_0;

  /* Logic: '<S42>/Logical Operator' incorporates:
   *  Memory: '<S42>/oalt'
   *  Memory: '<S42>/olat'
   *  RelationalOperator: '<S42>/Relational Operator'
   *  RelationalOperator: '<S42>/Relational Operator1'
   */
  rtb_LogicalOperator = ((rtb_sincos_o2_m != rtDW.olat_PreviousInput) ||
    (rtb_sqrt != rtDW.oalt_PreviousInput));

  /* Product: '<S41>/Product' */
  rtb_TrigonometricFunction4 = rtb_sincos_o2_jg_idx_0 * rtb_sincos_o2_jg_idx_0;

  /* Product: '<S41>/Product1' */
  rtb_UnitConversion_idx_0 = rtb_sincos_o1_l_idx_1 * rtb_sincos_o1_l_idx_1;

  /* Outputs for Enabled SubSystem: '<S36>/Convert from geodetic to  spherical coordinates' incorporates:
   *  EnablePort: '<S39>/Enable'
   */
  if (rtb_LogicalOperator) {
    /* Sqrt: '<S82>/sqrt' incorporates:
     *  Product: '<S82>/Product'
     *  Sum: '<S82>/Sum'
     */
    rtb_sincos_o1_idx_0 = sqrt(4.0680631590768993E+7 -
      rtb_TrigonometricFunction4 * 272331.60668193549);

    /* Product: '<S39>/Product1' */
    rtb_UnitConversion_idx_1 = rtb_sincos_o1_idx_0 * rtb_sqrt;

    /* Sqrt: '<S81>/sqrt' incorporates:
     *  Product: '<S81>/Product10'
     *  Product: '<S81>/Product9'
     *  Sum: '<S81>/Sum7'
     */
    rtb_sincos_o2_idx_0 = sqrt(rtb_UnitConversion_idx_0 * 4.0680631590768993E+7
      + 4.0408299984087057E+7 * rtb_TrigonometricFunction4);

    /* Sqrt: '<S39>/sqrt' incorporates:
     *  Gain: '<S84>/Gain'
     *  Product: '<S84>/Product1'
     *  Product: '<S84>/Product6'
     *  Product: '<S84>/Product7'
     *  Product: '<S84>/Product8'
     *  Sum: '<S84>/Sum5'
     *  Sum: '<S84>/Sum6'
     */
    rtDW.sqrt_i = sqrt((1.6549137866238722E+15 - 2.208307901990225E+13 *
                        rtb_TrigonometricFunction4) / (rtb_sincos_o1_idx_0 *
      rtb_sincos_o1_idx_0) + (2.0 * rtb_UnitConversion_idx_1 + rtb_sqrt *
      rtb_sqrt));

    /* Product: '<S79>/Product11' incorporates:
     *  Sum: '<S79>/Sum8'
     */
    rtDW.Product11 = (rtb_sqrt + rtb_sincos_o2_idx_0) / rtDW.sqrt_i;

    /* Sum: '<S83>/Sum2' */
    rtb_sincos_o1_idx_0 = 4.0680631590768993E+7 + rtb_UnitConversion_idx_1;

    /* Sum: '<S83>/Sum1' */
    rtb_UnitConversion_idx_1 += 4.0408299984087057E+7;

    /* Product: '<S80>/Product4' incorporates:
     *  Product: '<S80>/Product3'
     *  Product: '<S83>/Product1'
     *  Product: '<S83>/Product2'
     *  Sqrt: '<S80>/sqrt'
     *  Sum: '<S80>/Sum3'
     */
    rtDW.Product4 = rtb_sincos_o2_jg_idx_0 / sqrt(rtb_sincos_o1_idx_0 *
      rtb_sincos_o1_idx_0 / (rtb_UnitConversion_idx_1 * rtb_UnitConversion_idx_1)
      * rtb_UnitConversion_idx_0 + rtb_TrigonometricFunction4);

    /* Product: '<S85>/Product12' incorporates:
     *  Product: '<S85>/Product1'
     */
    rtDW.Product12 = 272331.60668193549 / (rtDW.sqrt_i * rtb_sincos_o2_idx_0) *
      rtb_sincos_o1_l_idx_1 * rtb_sincos_o2_jg_idx_0;

    /* Sqrt: '<S86>/sqrt' incorporates:
     *  Constant: '<S86>/Constant'
     *  Product: '<S86>/Product5'
     *  Sum: '<S86>/Sum4'
     */
    rtDW.sqrt_p = sqrt(1.0 - rtDW.Product4 * rtDW.Product4);
  }

  /* End of Outputs for SubSystem: '<S36>/Convert from geodetic to  spherical coordinates' */

  /* Product: '<S36>/aor' incorporates:
   *  Constant: '<S36>/re'
   */
  rtb_TrigonometricFunction4 = 6371.2 / rtDW.sqrt_i;

  /* Product: '<S36>/ar' */
  rtb_UnitConversion_idx_0 = rtb_TrigonometricFunction4 *
    rtb_TrigonometricFunction4;

  /* Outputs for Iterator SubSystem: '<S36>/Compute magnetic vector in spherical coordinates' incorporates:
   *  ForIterator: '<S38>/For Iterator'
   */
  /* InitializeConditions for UnitDelay: '<S38>/Unit Delay' */
  rtb_sincos_o1_idx_0 = 0.0;

  /* InitializeConditions for UnitDelay: '<S38>/Unit Delay2' */
  rtb_sincos_o2_jg_idx_0 = 0.0;
  rtb_sincos_o1_l_idx_1 = 0.0;
  UnitDelay2_DSTATE_idx_2 = 0.0;
  UnitDelay2_DSTATE_idx_3 = 0.0;
  for (s87_iter = 1; s87_iter < 13; s87_iter++) {
    /* Switch: '<S38>/ar(n)' */
    if (!(s87_iter > 1)) {
      rtb_sincos_o1_idx_0 = rtb_UnitConversion_idx_0;
    }

    /* End of Switch: '<S38>/ar(n)' */

    /* Product: '<S38>/Product8' */
    rtb_sincos_o1_idx_0 *= rtb_TrigonometricFunction4;

    /* Sum: '<S38>/Sum' */
    qY = s87_iter + 1;

    /* Outputs for Iterator SubSystem: '<S38>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S46>/For Iterator'
     */
    if (rtDW.ForIterator_IterationMarker[4] != 0) {
      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay1' */
      rtDW.UnitDelay1_DSTATE_h = 0.0;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay3' */
      rtDW.UnitDelay3_DSTATE = 0.0;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay2' */
      rtDW.UnitDelay2_DSTATE_i = 0.0;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay4' */
      rtDW.UnitDelay4_DSTATE = 0.0;
    }

    for (i = 0; i < 7; i++) {
      rtDW.ForIterator_IterationMarker[i] = 1U;
    }

    /* Sum: '<S38>/Sum' incorporates:
     *  Constant: '<S53>/Constant'
     *  Constant: '<S53>/Constant1'
     *  Logic: '<S53>/Logical Operator'
     *  RelationalOperator: '<S53>/Relational Operator'
     *  RelationalOperator: '<S53>/Relational Operator1'
     *  Sum: '<S46>/Sum1'
     */
    for (s46_iter = 1; s46_iter <= qY; s46_iter++) {
      /* Sum: '<S46>/Sum1' */
      qY_2 = s46_iter - 1;

      /* Outputs for Enabled SubSystem: '<S46>/Time adjust the gauss coefficients' incorporates:
       *  EnablePort: '<S49>/Enable'
       */
      if (rtb_RelationalOperator) {
        /* Outputs for Atomic SubSystem: '<S49>/If Action Subsystem' */
        /* Sum: '<S75>/Sum1' incorporates:
         *  Sum: '<S46>/Sum1'
         */
        i = qY_2 + 1;

        /* Sum: '<S75>/Sum2' */
        qY_1 = s87_iter + 1;

        /* End of Outputs for SubSystem: '<S49>/If Action Subsystem' */

        /* Assignment: '<S49>/Assignment' incorporates:
         *  Constant: '<S36>/epoch'
         *  Constant: '<S49>/c[maxdef][maxdef]'
         *  Constant: '<S49>/cd[maxdef][maxdef]'
         *  Product: '<S75>/Product'
         *  Selector: '<S75>/c[m][n]'
         *  Selector: '<S75>/cd[m][n]'
         *  Sum: '<S36>/Sum'
         *  Sum: '<S75>/Sum'
         *  Sum: '<S75>/Sum1'
         *  Sum: '<S75>/Sum2'
         *  UnitDelay: '<S49>/Unit Delay'
         */
        if (rtDW.ForIterator_IterationMarker[5] < 2) {
          rtDW.ForIterator_IterationMarker[5L] = 2U;
          memcpy(&Assignment[0], &rtDW.UnitDelay_DSTATE_m[0], 169U * sizeof
                 (real_T));
        }

        /* Outputs for Atomic SubSystem: '<S49>/If Action Subsystem' */
        Assignment[(i + 13 * (qY_1 - 1)) - 1] = rtConstP.cdmaxdefmaxdef_Value
          [((qY_1 - 1) * 13 + i) - 1] * (rtb_Switch_g - 2015.0) +
          rtConstP.cmaxdefmaxdef_Value[((qY_1 - 1) * 13 + i) - 1];

        /* End of Assignment: '<S49>/Assignment' */
        /* End of Outputs for SubSystem: '<S49>/If Action Subsystem' */

        /* Switch: '<S76>/tc_old' incorporates:
         *  UnitDelay: '<S76>/Unit Delay'
         */
        for (i = 0; i < 169; i++) {
          if (s87_iter > 1) {
            rtb_tc_old[i] = rtDW.UnitDelay_DSTATE_j[i];
          } else {
            rtb_tc_old[i] = 0.0;
          }
        }

        /* End of Switch: '<S76>/tc_old' */

        /* If: '<S76>/If' incorporates:
         *  Sum: '<S46>/Sum1'
         */
        if (qY_2 != 0) {
          /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S77>/Action Port'
           */
          /* Sum: '<S77>/Sum2' */
          i = s87_iter + 1;

          /* Assignment: '<S77>/Assignment2' incorporates:
           *  Constant: '<S36>/epoch'
           *  Constant: '<S49>/c[maxdef][maxdef]'
           *  Constant: '<S49>/cd[maxdef][maxdef]'
           *  Product: '<S77>/Product'
           *  Selector: '<S77>/c[m][n]'
           *  Selector: '<S77>/cd[m][n]'
           *  Sum: '<S36>/Sum'
           *  Sum: '<S77>/Sum'
           *  Sum: '<S77>/Sum2'
           */
          if (rtDW.ForIterator_IterationMarker[6] < 2) {
            rtDW.ForIterator_IterationMarker[6L] = 2U;
            memcpy(&Assignment2[0], &rtb_tc_old[0], 169U * sizeof(real_T));
          }

          Assignment2[(i + 13 * (qY_2 - 1)) - 1] =
            rtConstP.cdmaxdefmaxdef_Value[((qY_2 - 1) * 13 + i) - 1] *
            (rtb_Switch_g - 2015.0) + rtConstP.cmaxdefmaxdef_Value[((qY_2 - 1) *
            13 + i) - 1];

          /* End of Assignment: '<S77>/Assignment2' */

          /* Gain: '<S77>/Gain' */
          memcpy(&rtb_tc_old[0], &Assignment2[0], 169U * sizeof(real_T));

          /* End of Outputs for SubSystem: '<S76>/If Action Subsystem1' */
        }

        /* End of If: '<S76>/If' */
        for (i = 0; i < 169; i++) {
          /* Sum: '<S49>/Sum2' */
          rtDW.Sum2_b[i] = Assignment[i] + rtb_tc_old[i];

          /* Update for UnitDelay: '<S49>/Unit Delay' */
          rtDW.UnitDelay_DSTATE_m[i] = Assignment[i];

          /* Update for UnitDelay: '<S76>/Unit Delay' */
          rtDW.UnitDelay_DSTATE_j[i] = rtb_tc_old[i];
        }
      }

      /* End of Outputs for SubSystem: '<S46>/Time adjust the gauss coefficients' */

      /* If: '<S52>/If' incorporates:
       *  Sum: '<S46>/Sum1'
       */
      if (qY_2 == 0) {
        /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem' incorporates:
         *  ActionPort: '<S58>/Action Port'
         */
        /* Gain: '<S58>/Gain1' incorporates:
         *  Constant: '<S52>/Constant1'
         *  Constant: '<S58>/Constant'
         *  Product: '<S58>/Product'
         *  Selector: '<S52>/cp[m+1]'
         *  Selector: '<S58>/Selector'
         *  Sum: '<S52>/Sum4'
         *  Sum: '<S58>/Sum'
         */
        rtb_UnitConversion_idx_1 = rtDW.Sum2_b[((s87_iter + 1) - 1) * 13] *
          rtDW.OutportBufferForcp13[(qY_2 + 1) - 1];

        /* Gain: '<S58>/Gain2' incorporates:
         *  Constant: '<S52>/Constant1'
         *  Constant: '<S58>/Constant'
         *  Product: '<S58>/Product'
         *  Selector: '<S52>/sp[m+1]'
         *  Selector: '<S58>/Selector'
         *  Sum: '<S52>/Sum4'
         *  Sum: '<S58>/Sum'
         */
        rtb_sincos_o2_idx_0 = rtDW.Sum2_b[((s87_iter + 1) - 1) * 13] *
          rtDW.OutportBufferForsp13[(qY_2 + 1) - 1];

        /* End of Outputs for SubSystem: '<S52>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S59>/Action Port'
         */
        /* Sum: '<S59>/Sum' incorporates:
         *  Constant: '<S52>/Constant1'
         *  Constant: '<S60>/Constant'
         *  Product: '<S59>/Product'
         *  Product: '<S59>/Product1'
         *  Selector: '<S52>/cp[m+1]'
         *  Selector: '<S52>/sp[m+1]'
         *  Selector: '<S59>/Selector'
         *  Selector: '<S59>/Selector1'
         *  Sum: '<S52>/Sum4'
         *  Sum: '<S60>/Sum'
         */
        rtb_UnitConversion_idx_1 = rtDW.Sum2_b[(((s87_iter + 1) - 1) * 13 +
          (qY_2 + 1)) - 1] * rtDW.OutportBufferForcp13[(qY_2 + 1) - 1] +
          rtDW.Sum2_b[(qY_2 - 1) * 13 + s87_iter] * rtDW.OutportBufferForsp13
          [(qY_2 + 1) - 1];

        /* Sum: '<S59>/Sum1' incorporates:
         *  Constant: '<S52>/Constant1'
         *  Constant: '<S60>/Constant'
         *  Product: '<S59>/Product'
         *  Product: '<S59>/Product1'
         *  Selector: '<S52>/cp[m+1]'
         *  Selector: '<S52>/sp[m+1]'
         *  Selector: '<S59>/Selector'
         *  Selector: '<S59>/Selector1'
         *  Sum: '<S52>/Sum4'
         *  Sum: '<S60>/Sum'
         */
        rtb_sincos_o2_idx_0 = rtDW.Sum2_b[(((s87_iter + 1) - 1) * 13 + (qY_2 + 1))
          - 1] * rtDW.OutportBufferForsp13[(qY_2 + 1) - 1] - rtDW.Sum2_b[(qY_2 -
          1) * 13 + s87_iter] * rtDW.OutportBufferForcp13[(qY_2 + 1) - 1];

        /* End of Outputs for SubSystem: '<S52>/If Action Subsystem1' */
      }

      /* End of If: '<S52>/If' */

      /* Outputs for Enabled SubSystem: '<S46>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' incorporates:
       *  EnablePort: '<S48>/Enable'
       */
      if (rtb_LogicalOperator) {
        /* If: '<S48>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' incorporates:
         *  Sum: '<S46>/Sum1'
         */
        if (s87_iter == qY_2) {
          /* Outputs for IfAction SubSystem: '<S48>/If Action Subsystem' incorporates:
           *  ActionPort: '<S62>/Action Port'
           */
          /* Gain: '<S66>/Gain' incorporates:
           *  Sum: '<S66>/Sum2'
           */
          rtb_Sum1_iz = mul_s32_sat(13L, qY_2 - 1);

          /* Selector: '<S62>/Selector' incorporates:
           *  Sum: '<S66>/Sum1'
           */
          if (rtb_Sum1_iz > MAX_int32_T - s87_iter) {
            rtb_Sum1_m = MAX_int32_T;
            rtb_Sum1_iz = MAX_int32_T;
          } else {
            rtb_Sum1_m = s87_iter + rtb_Sum1_iz;
            rtb_Sum1_iz += s87_iter;
          }

          /* Product: '<S62>/Product1' incorporates:
           *  Selector: '<S62>/Selector'
           *  UnitDelay: '<S48>/Unit Delay1'
           */
          rtDW.Merge_a = rtDW.UnitDelay1_DSTATE_p[(int16_T)rtb_Sum1_m - 1] *
            rtDW.sqrt_p;

          /* Sum: '<S62>/Sum' incorporates:
           *  Product: '<S62>/Product'
           *  Product: '<S62>/Product2'
           *  Selector: '<S62>/Selector'
           *  Selector: '<S62>/Selector1'
           *  UnitDelay: '<S48>/Unit Delay'
           *  UnitDelay: '<S48>/Unit Delay1'
           */
          rtDW.Merge1_e = rtDW.UnitDelay_DSTATE_l[((s87_iter - 1) * 13 + qY_2) -
            1] * rtDW.sqrt_p + rtDW.UnitDelay1_DSTATE_p[(int16_T)rtb_Sum1_iz - 1]
            * rtDW.Product4;

          /* End of Outputs for SubSystem: '<S48>/If Action Subsystem' */
        } else if ((s87_iter == 1) && (qY_2 == 0)) {
          /* Outputs for IfAction SubSystem: '<S48>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S63>/Action Port'
           */
          /* Selector: '<S63>/Selector' incorporates:
           *  Gain: '<S68>/Gain'
           *  Sum: '<S68>/Sum1'
           */
          rtb_Sum1_iz = mul_s32_sat(13L, 0L);
          if (rtb_Sum1_iz > 2147483646L) {
            rtb_Sum1_iz = MAX_int32_T;
          } else {
            rtb_Sum1_iz++;
          }

          /* Product: '<S63>/Product3' incorporates:
           *  Selector: '<S63>/Selector'
           *  UnitDelay: '<S48>/Unit Delay1'
           */
          rtDW.Merge_a = rtDW.UnitDelay1_DSTATE_p[(int16_T)rtb_Sum1_iz - 1] *
            rtDW.Product4;

          /* Selector: '<S63>/Selector' incorporates:
           *  Gain: '<S68>/Gain'
           *  Sum: '<S68>/Sum1'
           */
          rtb_Sum1_iz = mul_s32_sat(13L, 0L);
          if (rtb_Sum1_iz > 2147483646L) {
            rtb_Sum1_iz = MAX_int32_T;
          } else {
            rtb_Sum1_iz++;
          }

          /* Sum: '<S63>/Sum' incorporates:
           *  Product: '<S63>/Product'
           *  Product: '<S63>/Product2'
           *  Selector: '<S63>/Selector'
           *  Selector: '<S63>/Selector1'
           *  UnitDelay: '<S48>/Unit Delay'
           *  UnitDelay: '<S48>/Unit Delay1'
           */
          rtDW.Merge1_e = rtDW.Product4 * rtDW.UnitDelay_DSTATE_l[0] -
            rtDW.UnitDelay1_DSTATE_p[(int16_T)rtb_Sum1_iz - 1] * rtDW.sqrt_p;

          /* End of Outputs for SubSystem: '<S48>/If Action Subsystem1' */
        } else {
          if ((s87_iter > 1) && (s87_iter != qY_2)) {
            /* Outputs for IfAction SubSystem: '<S48>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S64>/Action Port'
             */
            /* Sum: '<S72>/Sum' */
            i = qY_2 + 1;

            /* Sum: '<S71>/Sum' */
            qY_1 = s87_iter + 1;
            qY_0 = qY_2 + 1;

            /* Gain: '<S70>/Gain' */
            rtb_Sum1_iz = mul_s32_sat(13L, qY_2);

            /* Selector: '<S64>/Selector' incorporates:
             *  Sum: '<S70>/Sum1'
             */
            if (rtb_Sum1_iz > MAX_int32_T - s87_iter) {
              rtb_Sum1_m = MAX_int32_T;
            } else {
              rtb_Sum1_m = s87_iter + rtb_Sum1_iz;
            }

            /* Switch: '<S64>/Switch' incorporates:
             *  Constant: '<S64>/Constant'
             *  DataTypeConversion: '<S73>/Data Type Conversion'
             *  RelationalOperator: '<S73>/Relational Operator'
             *  Selector: '<S64>/Selector1'
             *  Sum: '<S72>/Sum'
             *  Sum: '<S73>/Sum2'
             *  UnitDelay: '<S48>/Unit Delay'
             */
            if ((s87_iter - 2 >= qY_2) > 0.5) {
              rtb_Sum1_o_idx_3 = rtDW.UnitDelay_DSTATE_l[((s87_iter - 2) * 13 +
                i) - 1];
            } else {
              rtb_Sum1_o_idx_3 = 0.0;
            }

            /* End of Switch: '<S64>/Switch' */

            /* Sum: '<S64>/Sum' incorporates:
             *  Constant: '<S64>/k[13][13]'
             *  Product: '<S64>/Product'
             *  Product: '<S64>/Product1'
             *  Product: '<S64>/Product4'
             *  Selector: '<S64>/Selector'
             *  Selector: '<S64>/Selector1'
             *  Selector: '<S64>/Selector2'
             *  Sum: '<S71>/Sum'
             *  Sum: '<S72>/Sum'
             *  UnitDelay: '<S48>/Unit Delay'
             *  UnitDelay: '<S48>/Unit Delay1'
             */
            rtDW.Merge1_e = (rtDW.UnitDelay_DSTATE_l[((s87_iter - 1) * 13 + i) -
                             1] * rtDW.Product4 - rtDW.UnitDelay1_DSTATE_p
                             [(int16_T)rtb_Sum1_m - 1] * rtDW.sqrt_p) -
              rtConstP.pooled5[((qY_1 - 1) * 13 + qY_0) - 1] * rtb_Sum1_o_idx_3;

            /* Switch: '<S64>/Switch1' incorporates:
             *  Constant: '<S64>/Constant1'
             *  DataTypeConversion: '<S74>/Data Type Conversion'
             *  RelationalOperator: '<S74>/Relational Operator'
             *  Selector: '<S64>/Selector'
             *  Sum: '<S74>/Sum2'
             *  UnitDelay: '<S48>/Unit Delay1'
             */
            if ((s87_iter - 2 >= qY_2) > 0.5) {
              /* Selector: '<S64>/Selector' incorporates:
               *  Sum: '<S70>/Sum1'
               *  Sum: '<S70>/Sum2'
               */
              i = s87_iter - 1;
              if (rtb_Sum1_iz > MAX_int32_T - i) {
                rtb_Sum1_m = MAX_int32_T;
              } else {
                rtb_Sum1_m = i + rtb_Sum1_iz;
              }

              rtb_Sum1_o_idx_3 = rtDW.UnitDelay1_DSTATE_p[(int16_T)rtb_Sum1_m -
                1];
            } else {
              rtb_Sum1_o_idx_3 = 0.0;
            }

            /* End of Switch: '<S64>/Switch1' */

            /* Selector: '<S64>/Selector' incorporates:
             *  Sum: '<S70>/Sum1'
             */
            if (rtb_Sum1_iz > MAX_int32_T - s87_iter) {
              rtb_Sum1_iz = MAX_int32_T;
            } else {
              rtb_Sum1_iz += s87_iter;
            }

            /* Sum: '<S64>/Sum1' incorporates:
             *  Constant: '<S64>/k[13][13]'
             *  Product: '<S64>/Product2'
             *  Product: '<S64>/Product3'
             *  Selector: '<S64>/Selector'
             *  Selector: '<S64>/Selector2'
             *  Sum: '<S71>/Sum'
             *  UnitDelay: '<S48>/Unit Delay1'
             */
            rtDW.Merge_a = rtDW.UnitDelay1_DSTATE_p[(int16_T)rtb_Sum1_iz - 1] *
              rtDW.Product4 - rtConstP.pooled5[((qY_1 - 1) * 13 + qY_0) - 1] *
              rtb_Sum1_o_idx_3;

            /* End of Outputs for SubSystem: '<S48>/If Action Subsystem2' */
          }
        }

        /* End of If: '<S48>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' */

        /* Sum: '<S48>/Sum' incorporates:
         *  Sum: '<S46>/Sum1'
         */
        i = s87_iter + 1;
        qY_1 = qY_2 + 1;

        /* Assignment: '<S48>/Assignment' incorporates:
         *  Sum: '<S48>/Sum'
         *  UnitDelay: '<S48>/Unit Delay'
         */
        if (rtDW.ForIterator_IterationMarker[2] < 2) {
          rtDW.ForIterator_IterationMarker[2L] = 2U;
          memcpy(&rtDW.Assignment_h[0], &rtDW.UnitDelay_DSTATE_l[0], 169U *
                 sizeof(real_T));
        }

        rtDW.Assignment_h[(qY_1 + 13 * (i - 1)) - 1] = rtDW.Merge1_e;

        /* End of Assignment: '<S48>/Assignment' */

        /* Assignment: '<S48>/Assignment_snorm' incorporates:
         *  Gain: '<S65>/Gain'
         *  Sum: '<S48>/Sum'
         *  Sum: '<S65>/Sum1'
         *  Sum: '<S65>/Sum2'
         *  UnitDelay: '<S48>/Unit Delay1'
         */
        if (rtDW.ForIterator_IterationMarker[3] < 2) {
          rtDW.ForIterator_IterationMarker[3L] = 2U;
          memcpy(&rtDW.Assignment_snorm[0], &rtDW.UnitDelay1_DSTATE_p[0], 169U *
                 sizeof(real_T));
        }

        rtDW.Assignment_snorm[(int16_T)((real_T)i + (real_T)mul_s32_sat(13L,
          qY_1 - 1)) - 1] = rtDW.Merge_a;

        /* End of Assignment: '<S48>/Assignment_snorm' */

        /* Update for UnitDelay: '<S48>/Unit Delay' */
        memcpy(&rtDW.UnitDelay_DSTATE_l[0], &rtDW.Assignment_h[0], 169U * sizeof
               (real_T));

        /* Update for UnitDelay: '<S48>/Unit Delay1' */
        memcpy(&rtDW.UnitDelay1_DSTATE_p[0], &rtDW.Assignment_snorm[0], 169U *
               sizeof(real_T));
      }

      /* End of Outputs for SubSystem: '<S46>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

      /* Selector: '<S47>/snorm[n+m*13]' incorporates:
       *  Gain: '<S51>/Gain'
       *  Sum: '<S46>/Sum1'
       *  Sum: '<S51>/Sum1'
       */
      i = 1 + s87_iter;
      rtb_Sum1_iz = mul_s32_sat(13L, qY_2);
      if (rtb_Sum1_iz > MAX_int32_T - i) {
        rtb_Sum1_iz = MAX_int32_T;
      } else {
        rtb_Sum1_iz += i;
      }

      /* Product: '<S47>/par' incorporates:
       *  Selector: '<S47>/snorm[n+m*13]'
       */
      rtb_sincos_o1_l_idx_0 = rtDW.Assignment_snorm[(int16_T)rtb_Sum1_iz - 1] *
        rtb_sincos_o1_idx_0;

      /* Outputs for Enabled SubSystem: '<S47>/Special case - North//South Geographic Pole' incorporates:
       *  EnablePort: '<S50>/Enable'
       */
      if ((rtDW.sqrt_p == 0.0) && (1 == qY_2)) {
        if (!rtDW.SpecialcaseNorthSouthGeographic) {
          rtDW.SpecialcaseNorthSouthGeographic = true;
        }

        /* If: '<S50>/n ==1' incorporates:
         *  Assignment: '<S55>/Assignment2'
         */
        if (s87_iter == 1) {
          /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* Assignment: '<S54>/Assignment2' incorporates:
           *  Selector: '<S54>/pp[n-1]'
           *  UnitDelay: '<S50>/Unit Delay1'
           */
          if (rtDW.ForIterator_IterationMarker[0] < 2) {
            rtDW.ForIterator_IterationMarker[0L] = 2U;
            memcpy(&rtDW.Assignment2_e[0], &rtDW.UnitDelay1_DSTATE_b[0], 13U *
                   sizeof(real_T));
          }

          rtDW.Assignment2_e[1] = rtDW.UnitDelay1_DSTATE_b[0];

          /* End of Assignment: '<S54>/Assignment2' */
          /* End of Outputs for SubSystem: '<S50>/If Action Subsystem1' */
        } else {
          /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem2' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          if (rtDW.ForIterator_IterationMarker[1] < 2) {
            /* Assignment: '<S55>/Assignment2' incorporates:
             *  UnitDelay: '<S50>/Unit Delay1'
             */
            rtDW.ForIterator_IterationMarker[1L] = 2U;
            memcpy(&rtDW.Assignment2_a[0], &rtDW.UnitDelay1_DSTATE_b[0], 13U *
                   sizeof(real_T));
          }

          /* Assignment: '<S55>/Assignment2' incorporates:
           *  Constant: '<S55>/k[13][13]'
           *  Product: '<S55>/Product1'
           *  Product: '<S55>/Product2'
           *  Selector: '<S55>/Selector2'
           *  Selector: '<S55>/pp[n-2] pp[n-1]'
           *  Sum: '<S55>/Sum1'
           *  UnitDelay: '<S50>/Unit Delay1'
           */
          rtDW.Assignment2_a[s87_iter] = rtDW.UnitDelay1_DSTATE_b[s87_iter - 1] *
            rtDW.Product4 - rtConstP.pooled5[s87_iter * 13 + 1] *
            rtDW.UnitDelay1_DSTATE_b[s87_iter - 2];

          /* End of Outputs for SubSystem: '<S50>/If Action Subsystem2' */
        }

        /* End of If: '<S50>/n ==1' */

        /* SignalConversion: '<S50>/TmpSignal ConversionAtpp[n]Inport1' incorporates:
         *  UnitDelay: '<S50>/Unit Delay1'
         */
        rtb_TmpSignalConversionAtppnInp[0] = rtDW.UnitDelay1_DSTATE_b[0];
        rtb_TmpSignalConversionAtppnInp[1] = rtDW.Assignment2_e[1];
        memcpy(&rtb_TmpSignalConversionAtppnInp[2], &rtDW.Assignment2_a[2], 11U *
               sizeof(real_T));

        /* Product: '<S50>/Product2' incorporates:
         *  Selector: '<S50>/pp[n]'
         */
        rtDW.Product2 = rtb_sincos_o1_idx_0 *
          rtb_TmpSignalConversionAtppnInp[s87_iter] * rtb_sincos_o2_idx_0;

        /* Update for UnitDelay: '<S50>/Unit Delay1' */
        memcpy(&rtDW.UnitDelay1_DSTATE_b[0], &rtb_TmpSignalConversionAtppnInp[0],
               13U * sizeof(real_T));
      } else {
        if (rtDW.SpecialcaseNorthSouthGeographic) {
          /* Disable for Outport: '<S50>/bpp' */
          rtDW.Product2 = 0.0;
          rtDW.SpecialcaseNorthSouthGeographic = false;
        }
      }

      /* End of Outputs for SubSystem: '<S47>/Special case - North//South Geographic Pole' */

      /* Sum: '<S47>/Sum1' incorporates:
       *  Constant: '<S53>/Constant'
       *  Constant: '<S53>/Constant1'
       *  Logic: '<S53>/Logical Operator'
       *  Product: '<S47>/Product'
       *  RelationalOperator: '<S53>/Relational Operator'
       *  RelationalOperator: '<S53>/Relational Operator1'
       *  Selector: '<S47>/dp[n][m]'
       *  Sum: '<S46>/Sum1'
       *  UnitDelay: '<S47>/Unit Delay1'
       */
      rtDW.Sum1 = rtDW.UnitDelay1_DSTATE_h - rtDW.Assignment_h[s87_iter * 13 +
        qY_2] * rtb_UnitConversion_idx_1 * rtb_sincos_o1_idx_0;

      /* Sum: '<S47>/Sum2' incorporates:
       *  Constant: '<S47>/fm'
       *  Product: '<S47>/Product1'
       *  Selector: '<S47>/fm[m]'
       *  Sum: '<S46>/Sum1'
       *  UnitDelay: '<S47>/Unit Delay3'
       */
      rtDW.Sum2 = rtConstP.fm_Value[qY_2] * rtb_sincos_o1_l_idx_0 *
        rtb_sincos_o2_idx_0 + rtDW.UnitDelay3_DSTATE;

      /* Sum: '<S47>/Sum3' incorporates:
       *  Constant: '<S47>/fn'
       *  Product: '<S47>/Product2'
       *  Selector: '<S47>/fn[m]'
       *  UnitDelay: '<S47>/Unit Delay2'
       */
      rtDW.Sum3 = rtConstP.fn_Value[s87_iter] * rtb_sincos_o1_l_idx_0 *
        rtb_UnitConversion_idx_1 + rtDW.UnitDelay2_DSTATE_i;

      /* Sum: '<S47>/Sum5' incorporates:
       *  UnitDelay: '<S47>/Unit Delay4'
       */
      rtDW.Sum5 = rtDW.UnitDelay4_DSTATE + rtDW.Product2;

      /* Update for UnitDelay: '<S47>/Unit Delay1' */
      rtDW.UnitDelay1_DSTATE_h = rtDW.Sum1;

      /* Update for UnitDelay: '<S47>/Unit Delay3' */
      rtDW.UnitDelay3_DSTATE = rtDW.Sum2;

      /* Update for UnitDelay: '<S47>/Unit Delay2' */
      rtDW.UnitDelay2_DSTATE_i = rtDW.Sum3;

      /* Update for UnitDelay: '<S47>/Unit Delay4' */
      rtDW.UnitDelay4_DSTATE = rtDW.Sum5;
    }

    /* End of Outputs for SubSystem: '<S38>/For Iterator Subsystem' */

    /* Sum: '<S38>/Sum1' incorporates:
     *  UnitDelay: '<S38>/Unit Delay2'
     */
    rtb_Sum1_o_idx_0 = rtb_sincos_o2_jg_idx_0 + rtDW.Sum1;
    rtb_Sum1_o_idx_1 = rtb_sincos_o1_l_idx_1 + rtDW.Sum2;
    rtb_Sum1_o_idx_2 = UnitDelay2_DSTATE_idx_2 + rtDW.Sum3;
    rtb_Sum1_o_idx_3 = UnitDelay2_DSTATE_idx_3 + rtDW.Sum5;

    /* Update for UnitDelay: '<S38>/Unit Delay2' */
    rtb_sincos_o2_jg_idx_0 = rtb_Sum1_o_idx_0;
    rtb_sincos_o1_l_idx_1 = rtb_Sum1_o_idx_1;
    UnitDelay2_DSTATE_idx_2 = rtb_Sum1_o_idx_2;
    UnitDelay2_DSTATE_idx_3 = rtb_Sum1_o_idx_3;
  }

  /* End of Outputs for SubSystem: '<S36>/Compute magnetic vector in spherical coordinates' */

  /* Switch: '<S90>/Switch' incorporates:
   *  Product: '<S90>/Product'
   */
  if (rtDW.sqrt_p != 0.0) {
    rtb_UnitConversion_idx_0 = rtb_Sum1_o_idx_1 / rtDW.sqrt_p;
  } else {
    rtb_UnitConversion_idx_0 = rtb_Sum1_o_idx_3;
  }

  /* End of Switch: '<S90>/Switch' */

  /* Sum: '<S89>/Sum1' incorporates:
   *  Product: '<S89>/Product1'
   *  Product: '<S89>/Product4'
   */
  rtb_UnitConversion_idx_1 = (0.0 - rtDW.Product11 * rtb_Sum1_o_idx_0) -
    rtb_Sum1_o_idx_2 * rtDW.Product12;

  /* UnitConversion: '<S94>/Unit Conversion' incorporates:
   *  Trigonometry: '<S92>/Trigonometric Function1'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_sincos_o1_idx_0 = 57.295779513082323 * rt_atan2d_snf
    (rtb_UnitConversion_idx_0, rtb_UnitConversion_idx_1);

  /* Sum: '<S91>/Sum1' incorporates:
   *  Product: '<S91>/Product1'
   *  Product: '<S91>/Product4'
   */
  rtb_TrigonometricFunction4 = rtDW.Product12 * rtb_Sum1_o_idx_0 -
    rtb_Sum1_o_idx_2 * rtDW.Product11;

  /* Sum: '<S92>/Sum' incorporates:
   *  Product: '<S92>/Product'
   *  Product: '<S92>/Product1'
   */
  rtb_UnitConversion_idx_0 = rtb_UnitConversion_idx_0 * rtb_UnitConversion_idx_0
    + rtb_UnitConversion_idx_1 * rtb_UnitConversion_idx_1;

  /* UnitConversion: '<S37>/Unit Conversion' incorporates:
   *  Sqrt: '<S92>/sqrt1'
   *  Trigonometry: '<S92>/Trigonometric Function'
   *  UnitConversion: '<S93>/Unit Conversion'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  rtb_sincos_o1_l_idx_0 = 0.017453292519943295 * rtb_sincos_o1_idx_0;
  rtb_sincos_o1_l_idx_1 = 57.295779513082323 * rt_atan2d_snf
    (rtb_TrigonometricFunction4, sqrt(rtb_UnitConversion_idx_0)) *
    0.017453292519943295;

  /* Trigonometry: '<S31>/sincos' */
  rtb_sincos_o2_jg_idx_0 = cos(rtb_sincos_o1_l_idx_0);
  rtb_sincos_o1_l_idx_0 = sin(rtb_sincos_o1_l_idx_0);

  /* Sum: '<S92>/Sum1' incorporates:
   *  Product: '<S92>/Product2'
   */
  rtb_UnitConversion_idx_0 += rtb_TrigonometricFunction4 *
    rtb_TrigonometricFunction4;

  /* Sqrt: '<S92>/sqrt' */
  rtb_UnitConversion_idx_0 = sqrt(rtb_UnitConversion_idx_0);

  /* Product: '<S31>/h1' incorporates:
   *  Trigonometry: '<S31>/sincos'
   */
  rtb_TrigonometricFunction4 = cos(rtb_sincos_o1_l_idx_1) *
    rtb_UnitConversion_idx_0;

  /* Product: '<S31>/x1' */
  rtb_UnitConversion_idx_1 = rtb_sincos_o2_jg_idx_0 * rtb_TrigonometricFunction4;

  /* Product: '<S31>/y1' */
  rtb_TrigonometricFunction4 *= rtb_sincos_o1_l_idx_0;

  /* Product: '<S31>/z1' incorporates:
   *  Trigonometry: '<S31>/sincos'
   */
  rtb_UnitConversion_idx_0 *= sin(rtb_sincos_o1_l_idx_1);

  /* Gain: '<S1>/nT2T' */
  rtb_Sum1_o_idx_3 = 1.0E-9 * rtb_UnitConversion_idx_1;
  rtb_TrigonometricFunction4 *= 1.0E-9;
  rtb_Sum1_o_idx_1 = 1.0E-9 * rtb_UnitConversion_idx_0;

  /* Product: '<S1>/Matrix Multiply1' incorporates:
   *  Math: '<S1>/Math Function'
   *  Product: '<S1>/Matrix Multiply2'
   */
  for (s87_iter = 0; s87_iter < 3; s87_iter++) {
    rtb_VectorConcatenate_0[s87_iter] = rtb_VectorConcatenate[3 * s87_iter + 2] *
      rtb_Sum1_o_idx_1 + (rtb_VectorConcatenate[3 * s87_iter + 1] *
                          rtb_TrigonometricFunction4 + rtb_VectorConcatenate[3 *
                          s87_iter] * rtb_Sum1_o_idx_3);
  }

  /* End of Product: '<S1>/Matrix Multiply1' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S1>/Matrix Multiply2' incorporates:
     *  Inport: '<Root>/eci_to_ecef'
     */
    rtb_TrigonometricFunction4 = rtU.eci_to_ecef[i + 6] *
      rtb_VectorConcatenate_0[2] + (rtU.eci_to_ecef[i + 3] *
      rtb_VectorConcatenate_0[1] + rtU.eci_to_ecef[i] * rtb_VectorConcatenate_0
      [0]);

    /* Math: '<S5>/Math Function' */
    rtb_MathFunction[i] = rtb_TrigonometricFunction4 *
      rtb_TrigonometricFunction4;

    /* Product: '<S1>/Matrix Multiply2' */
    rtb_MatrixMultiply2[i] = rtb_TrigonometricFunction4;
  }

  /* Sum: '<S5>/Sum of Elements' */
  rtb_TrigonometricFunction4 = (rtb_MathFunction[0] + rtb_MathFunction[1]) +
    rtb_MathFunction[2];

  /* Math: '<S5>/Math Function1'
   *
   * About '<S5>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_TrigonometricFunction4 < 0.0) {
    rtb_TrigonometricFunction4 = -sqrt(fabs(rtb_TrigonometricFunction4));
  } else {
    rtb_TrigonometricFunction4 = sqrt(rtb_TrigonometricFunction4);
  }

  /* End of Math: '<S5>/Math Function1' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  Product: '<S5>/Product'
   */
  if (rtb_TrigonometricFunction4 > 0.0) {
    rtb_sincos_o2_jg_idx_0 = rtb_MatrixMultiply2[0];
    rtb_sincos_o1_l_idx_1 = rtb_MatrixMultiply2[1];
    UnitDelay2_DSTATE_idx_2 = rtb_MatrixMultiply2[2];
    UnitDelay2_DSTATE_idx_3 = rtb_TrigonometricFunction4;
  } else {
    rtb_sincos_o2_jg_idx_0 = rtb_MatrixMultiply2[0] * 0.0;
    rtb_sincos_o1_l_idx_1 = rtb_MatrixMultiply2[1] * 0.0;
    UnitDelay2_DSTATE_idx_2 = rtb_MatrixMultiply2[2] * 0.0;
    UnitDelay2_DSTATE_idx_3 = 1.0;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Outport: '<Root>/mag_unit_vector_eci' incorporates:
   *  Product: '<S5>/Divide'
   */
  rtY.mag_unit_vector_eci[0] = rtb_sincos_o2_jg_idx_0 / UnitDelay2_DSTATE_idx_3;

  /* Outport: '<Root>/mag_vector_eci_T' */
  rtY.mag_vector_eci_T[0] = rtb_MatrixMultiply2[0];

  /* Outport: '<Root>/mag_unit_vector_eci' incorporates:
   *  Product: '<S5>/Divide'
   */
  rtY.mag_unit_vector_eci[1] = rtb_sincos_o1_l_idx_1 / UnitDelay2_DSTATE_idx_3;

  /* Outport: '<Root>/mag_vector_eci_T' */
  rtY.mag_vector_eci_T[1] = rtb_MatrixMultiply2[1];

  /* Outport: '<Root>/mag_unit_vector_eci' incorporates:
   *  Product: '<S5>/Divide'
   */
  rtY.mag_unit_vector_eci[2] = UnitDelay2_DSTATE_idx_2 / UnitDelay2_DSTATE_idx_3;

  /* Outport: '<Root>/mag_vector_eci_T' */
  rtY.mag_vector_eci_T[2] = rtb_MatrixMultiply2[2];

  /* Update for Memory: '<S44>/otime' */
  rtDW.otime_PreviousInput = rtb_Switch_g;

  /* Update for Memory: '<S43>/olon' */
  rtDW.olon_PreviousInput = rtb_sincos_o1_n;

  /* Update for Memory: '<S42>/olat' */
  rtDW.olat_PreviousInput = rtb_sincos_o2_m;

  /* Update for Memory: '<S42>/oalt' */
  rtDW.oalt_PreviousInput = rtb_sqrt;
}

/* Model initialize function */
void mag_vector_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int16_T i;

    /* InitializeConditions for Memory: '<S44>/otime' */
    rtDW.otime_PreviousInput = -1000.0;

    /* InitializeConditions for Memory: '<S43>/olon' */
    rtDW.olon_PreviousInput = -1000.0;

    /* InitializeConditions for Memory: '<S42>/olat' */
    rtDW.olat_PreviousInput = -1000.0;

    /* InitializeConditions for Memory: '<S42>/oalt' */
    rtDW.oalt_PreviousInput = -1000.0;

    /* SystemInitialize for Enabled SubSystem: '<S36>/Convert from geodetic to  spherical coordinates ' */
    /* SystemInitialize for Outport: '<S40>/sp[13]' */
    memcpy(&rtDW.OutportBufferForsp13[0], &rtConstP.sp13_Y0[0], 13U * sizeof
           (real_T));

    /* SystemInitialize for Outport: '<S40>/cp[13]' */
    memcpy(&rtDW.OutportBufferForcp13[0], &rtConstP.cp13_Y0[0], 13U * sizeof
           (real_T));

    /* End of SystemInitialize for SubSystem: '<S36>/Convert from geodetic to  spherical coordinates ' */

    /* SystemInitialize for Enabled SubSystem: '<S36>/Convert from geodetic to  spherical coordinates' */
    /* SystemInitialize for Outport: '<S39>/r' */
    rtDW.sqrt_i = 6378.137;

    /* SystemInitialize for Outport: '<S39>/ct' */
    rtDW.Product4 = 1.0;

    /* End of SystemInitialize for SubSystem: '<S36>/Convert from geodetic to  spherical coordinates' */

    /* SystemInitialize for Iterator SubSystem: '<S36>/Compute magnetic vector in spherical coordinates' */
    /* SystemInitialize for Iterator SubSystem: '<S38>/For Iterator Subsystem' */
    /* SystemInitialize for Enabled SubSystem: '<S46>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */
    /* InitializeConditions for UnitDelay: '<S48>/Unit Delay1' */
    memcpy(&rtDW.UnitDelay1_DSTATE_p[0], &rtConstP.pooled8[0], 169U * sizeof
           (real_T));

    /* SystemInitialize for Outport: '<S48>/snorm[169]' */
    memcpy(&rtDW.Assignment_snorm[0], &rtConstP.pooled8[0], 169U * sizeof(real_T));

    /* End of SystemInitialize for SubSystem: '<S46>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

    /* SystemInitialize for Enabled SubSystem: '<S47>/Special case - North//South Geographic Pole' */
    /* SystemInitialize for IfAction SubSystem: '<S50>/If Action Subsystem2' */
    /* SystemInitialize for IfAction SubSystem: '<S50>/If Action Subsystem1' */
    for (i = 0; i < 13; i++) {
      /* InitializeConditions for UnitDelay: '<S50>/Unit Delay1' */
      rtDW.UnitDelay1_DSTATE_b[i] = 1.0;

      /* SystemInitialize for Outport: '<S54>/pp[13]' */
      rtDW.Assignment2_e[i] = 1.0;

      /* SystemInitialize for Outport: '<S55>/pp[13]' */
      rtDW.Assignment2_a[i] = 1.0;
    }

    /* End of SystemInitialize for SubSystem: '<S50>/If Action Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<S50>/If Action Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S47>/Special case - North//South Geographic Pole' */
    /* End of SystemInitialize for SubSystem: '<S38>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S36>/Compute magnetic vector in spherical coordinates' */
  }
}

/* Model terminate function */
void mag_vector_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
