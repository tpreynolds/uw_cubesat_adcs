/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: estimate_eci_vectors.c
 *
 * Code generated for Simulink model 'estimate_eci_vectors'.
 *
 * Model version                  : 1.177
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sat Oct 28 16:15:32 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->MSP430
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "estimate_eci_vectors.h"
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
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo);
int32_T mul_s32_sat(int32_T a, int32_T b);

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

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
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

/* Model step function for TID0 */
void estimate_eci_vectors_step0(void)  /* Sample time: [0.1s, 0.0s] */
{
  real_T mean_anom_sun_rad;
  real_T long_eclp_rad;
  real_T oblq_rad;
  real_T r;
  real_T c;
  real_T b_s;
  real_T b_c;
  real_T c_s;
  real_T c_c;
  static const real_T a[9] = { 1.0, 0.0, 0.0, 0.0, 0.91748214306524178,
    0.397776969112606, 0.0, -0.397776969112606, 0.91748214306524178 };

  static const int8_T b[3] = { 1, 0, 0 };

  static const int8_T d[3] = { 0, 0, 1 };

  real_T d_o;
  int16_T lowAlt;
  real_T xi;
  real_T b_o;
  real_T eta;
  real_T C_1;
  real_T C_4;
  real_T C_5;
  real_T D_2;
  real_T D_3;
  real_T D_4;
  real_T IL2;
  real_T IL3;
  real_T IL4;
  real_T IL5;
  real_T M_DF;
  real_T sc_pos_eci_km[3];
  int8_T Lmonth[12];
  static const int8_T b_0[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  real_T rtb_Gain[3];
  int8_T s13_iter;
  real_T rtb_VectorConcatenate[9];
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_LogicalOperator;
  int16_T s49_iter;
  real_T rtb_sun_vector_eci_km[3];
  real_T rtb_Assignment[11];
  real_T rtb_Assignment1[11];
  int32_T rtb_Sum1_m;
  real_T rtb_TmpSignalConversionAtppnInp[13];
  real_T rtb_tc_old[169];
  real_T Assignment[169];
  real_T Assignment2[169];
  real_T rtb_sun_vector_eci_km_0[3];
  real_T c_c_0[9];
  real_T a_0[9];
  real_T b_1[9];
  real_T c_0[9];
  int16_T i;
  real_T rtb_Sum1_j_idx_3;
  real_T rtb_Sum1_j_idx_1;
  real_T rtb_Sum1_j_idx_0;
  real_T rtb_Sum1_j_idx_2;
  int16_T qY;
  int16_T qY_0;
  int16_T qY_1;
  int16_T qY_2;
  int32_T rtb_Sum1_a;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.1s, 0.0s] to Sample time: [1.0s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 9) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition: '<S1>/Rate Transition4' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    rtDW.RateTransition4 = rtDW.RateTransition4_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition4' */

  /* MATLAB Function: '<S4>/MATLAB Function' */
  /*  Constants */
  /* MATLAB Function 'sun_vector_lib/MATLAB Function': '<S99>:1' */
  /* '<S99>:1:4' AU2KM  = 149597870.700; */
  /* '<S99>:1:5' DEG2RAD     = pi/180.0; */
  /*  ----- */
  /*  Convert to Julian Centuries since J2000 */
  /*  JD_cent_ut1     = (JD_ut1 - 2451545)/36525; */
  /*  Mean longitude in a mean-equator of date frame */
  /* '<S99>:1:12' mean_long_sun  = rem(280.460 + 36000.771*JD_cent_ut1,360); */
  /*  [deg] */
  /*  Mean anomaly for the sun. Low precision formula since we're approximating */
  /*  T_TDB with T_UT1. */
  /* '<S99>:1:16' mean_anom_sun   = rem(357.5291092 + 35999.05034*JD_cent_ut1,360); */
  /* [deg] */
  /* '<S99>:1:17' mean_anom_sun_rad   = DEG2RAD*mean_anom_sun; */
  mean_anom_sun_rad = rt_remd_snf(35999.05034 * rtDW.RateTransition4 +
    357.5291092, 360.0) * 0.017453292519943295;

  /*  Make sure we're \in [0,2pi] */
  /* '<S99>:1:20' if ( mean_anom_sun_rad < 0.0  ) */
  if (mean_anom_sun_rad < 0.0) {
    /* '<S99>:1:21' mean_anom_sun_rad = 2*pi + mean_anom_sun_rad; */
    mean_anom_sun_rad += 6.2831853071795862;
  }

  /*  Approximate the ecliptic longitude of the sun */
  /* '<S99>:1:25' long_eclp       = mean_long_sun + 1.914666471*sin(mean_anom_sun_rad) + ... */
  /* '<S99>:1:26'                     0.019994643*sin(2*mean_anom_sun_rad); */
  /* [deg] */
  /* '<S99>:1:27' long_eclp_rad   = rem(DEG2RAD*long_eclp,360); */
  long_eclp_rad = rt_remd_snf(((rt_remd_snf(36000.771 * rtDW.RateTransition4 +
    280.46, 360.0) + 1.914666471 * sin(mean_anom_sun_rad)) + sin(2.0 *
    mean_anom_sun_rad) * 0.019994643) * 0.017453292519943295, 360.0);

  /*  [rad]             */
  /*  Assume the ecliptic latitude is zero */
  /* '<S99>:1:30' lat_eclp     = 0; */
  /* [deg] */
  /*  Approximate the obliquity of the ecliptic using */
  /* '<S99>:1:33' oblq        = 23.439291 - 0.0130042*JD_cent_ut1; */
  /* '<S99>:1:34' oblq_rad    = DEG2RAD*oblq; */
  oblq_rad = (23.439291 - 0.0130042 * rtDW.RateTransition4) *
    0.017453292519943295;

  /*  Find the distance in AU from E to S */
  /* '<S99>:1:37' r           =  1.000140612 - 0.016708617*cos(mean_anom_sun_rad) - ... */
  /* '<S99>:1:38'                     0.000139589*cos(2*mean_anom_sun_rad); */
  r = (1.000140612 - 0.016708617 * cos(mean_anom_sun_rad)) - cos(2.0 *
    mean_anom_sun_rad) * 0.000139589;

  /* '<S99>:1:40' x_MOD_km    = r*cos(long_eclp_rad)*AU2KM; */
  /* '<S99>:1:41' y_MOD_km    = r*cos(oblq_rad)*sin(long_eclp_rad)*AU2KM; */
  /* '<S99>:1:42' z_MOD_km    = r*sin(oblq_rad)*sin(long_eclp_rad)*AU2KM; */
  /* '<S99>:1:44' sun_vector_mod_km = [x_MOD_km; y_MOD_km; z_MOD_km]; */
  /*  Convert to ECI (mean-equator-mean-equinox) frame  */
  /* '<S99>:1:48' sun_vector_eci_km   = mod2eci(sun_vector_mod_km,JD_cent_ut1); */
  /* '<S99>:1:54' [prec,psia,wa,ea,xa] = precess ( JD_cent_ut1 ); */
  /*  " to rad */
  /* '<S99>:1:64' convrt = pi / (180.0*3600.0); */
  /*  ------------------ iau 03 precession angles ------------------- */
  /* '<S99>:1:67' oblo =  84381.406; */
  /*  " */
  /* '<S99>:1:68' psia =  (((( -0.0000000951 * ttt + 0.000132851 ) * ttt - 0.00114045 ) * ttt - 1.0790069 ) * ttt + 5038.481507 ) * ttt; */
  /*  " */
  /* '<S99>:1:69' wa   =  ((((  0.0000003337 * ttt - 0.000000467 ) * ttt - 0.00772503 ) * ttt + 0.0512623 ) * ttt -    0.025754 ) * ttt + oblo; */
  /* '<S99>:1:70' ea   =  (((( -0.0000000434 * ttt - 0.000000576 ) * ttt + 0.00200340 ) * ttt - 0.0001831 ) * ttt -   46.836769 ) * ttt + oblo; */
  /* '<S99>:1:71' xa   =  (((( - 0.0000000560 * ttt + 0.000170663 ) * ttt - 0.00121197 ) * ttt - 2.3814292 ) * ttt +   10.556403 ) * ttt; */
  /* '<S99>:1:73' zeta =  (((( - 0.0000003173 * ttt - 0.000005971 ) * ttt + 0.01801828 ) * ttt + 0.2988499 ) * ttt + 2306.083227 ) * ttt + 2.650545; */
  /*  " */
  /* '<S99>:1:74' theta=  (((( - 0.0000001274 * ttt - 0.000007089 ) * ttt - 0.04182264 ) * ttt - 0.4294934 ) * ttt + 2004.191903 ) * ttt; */
  /* '<S99>:1:75' z    =  ((((   0.0000002904 * ttt - 0.000028596 ) * ttt + 0.01826837 ) * ttt + 1.0927348 ) * ttt + 2306.077181 ) * ttt - 2.650545; */
  /*  convert all units to rad */
  /* '<S99>:1:78' psia = psia  * convrt; */
  c_c = ((((-9.51E-8 * rtDW.RateTransition4 + 0.000132851) *
           rtDW.RateTransition4 - 0.00114045) * rtDW.RateTransition4 - 1.0790069)
         * rtDW.RateTransition4 + 5038.481507) * rtDW.RateTransition4 *
    4.84813681109536E-6;

  /*  rad */
  /* '<S99>:1:79' wa   = wa    * convrt; */
  b_c = (((((3.337E-7 * rtDW.RateTransition4 - 4.67E-7) * rtDW.RateTransition4 -
            0.00772503) * rtDW.RateTransition4 + 0.0512623) *
          rtDW.RateTransition4 - 0.025754) * rtDW.RateTransition4 + 84381.406) *
    4.84813681109536E-6;

  /* '<S99>:1:80' ea   = ea    * convrt; */
  /* '<S99>:1:81' xa   = xa    * convrt; */
  c = ((((-5.6E-8 * rtDW.RateTransition4 + 0.000170663) * rtDW.RateTransition4 -
         0.00121197) * rtDW.RateTransition4 - 2.3814292) * rtDW.RateTransition4
       + 10.556403) * rtDW.RateTransition4 * 4.84813681109536E-6;

  /* '<S99>:1:83' oblo = oblo * convrt; */
  /*  " to rad */
  /* '<S99>:1:84' a4  = rot3mat(-xa); */
  /* '<S99>:1:105' s   = sin( z_rad ); */
  mean_anom_sun_rad = sin(-c);

  /* '<S99>:1:106' c   = cos( z_rad ); */
  c = cos(-c);

  /* '<S99>:1:108' DCMz    = [ c   s   0; */
  /* '<S99>:1:109'            -s   c   0; */
  /* '<S99>:1:110'             0   0   1 ]; */
  /* '<S99>:1:85' a5  = rot1mat(wa); */
  /*  precess */
  /* '<S99>:1:94' s   = sin( x_rad ); */
  b_s = sin(b_c);

  /* '<S99>:1:95' c   = cos( x_rad ); */
  b_c = cos(b_c);

  /* '<S99>:1:97' DCMx    = [ 1   0   0 */
  /* '<S99>:1:98'             0   c   s; */
  /* '<S99>:1:99'             0  -s   c ]; */
  /* '<S99>:1:86' a6  = rot3mat(psia); */
  /* '<S99>:1:105' s   = sin( z_rad ); */
  c_s = sin(c_c);

  /* '<S99>:1:106' c   = cos( z_rad ); */
  c_c = cos(c_c);

  /* '<S99>:1:108' DCMz    = [ c   s   0; */
  /* '<S99>:1:109'            -s   c   0; */
  /* '<S99>:1:110'             0   0   1 ]; */
  /* '<S99>:1:87' a7  = rot1mat(-oblo); */
  /* '<S99>:1:88' prec = a7*a6*a5*a4; */
  /* '<S99>:1:56' vec_eci = prec*vec_mod; */
  c_c_0[0] = c_c;
  c_c_0[3] = c_s;
  c_c_0[6] = 0.0;
  c_c_0[1] = -c_s;
  c_c_0[4] = c_c;
  c_c_0[7] = 0.0;
  c_c_0[2] = 0.0;
  c_c_0[5] = 0.0;
  c_c_0[8] = 1.0;
  for (lowAlt = 0; lowAlt < 3; lowAlt++) {
    for (qY = 0; qY < 3; qY++) {
      a_0[lowAlt + 3 * qY] = 0.0;
      a_0[lowAlt + 3 * qY] += c_c_0[3 * qY] * a[lowAlt];
      a_0[lowAlt + 3 * qY] += c_c_0[3 * qY + 1] * a[lowAlt + 3];
      a_0[lowAlt + 3 * qY] += c_c_0[3 * qY + 2] * a[lowAlt + 6];
    }

    b_1[3 * lowAlt] = b[lowAlt];
  }

  b_1[1] = 0.0;
  b_1[4] = b_c;
  b_1[7] = b_s;
  b_1[2] = 0.0;
  b_1[5] = -b_s;
  b_1[8] = b_c;
  c_0[0] = c;
  c_0[3] = mean_anom_sun_rad;
  c_0[6] = 0.0;
  c_0[1] = -mean_anom_sun_rad;
  c_0[4] = c;
  c_0[7] = 0.0;
  for (lowAlt = 0; lowAlt < 3; lowAlt++) {
    for (qY = 0; qY < 3; qY++) {
      c_c_0[lowAlt + 3 * qY] = 0.0;
      c_c_0[lowAlt + 3 * qY] += b_1[3 * qY] * a_0[lowAlt];
      c_c_0[lowAlt + 3 * qY] += b_1[3 * qY + 1] * a_0[lowAlt + 3];
      c_c_0[lowAlt + 3 * qY] += b_1[3 * qY + 2] * a_0[lowAlt + 6];
    }

    c_0[2 + 3 * lowAlt] = d[lowAlt];
  }

  rtb_Gain[0] = r * cos(long_eclp_rad) * 1.495978707E+8;
  rtb_Gain[1] = r * cos(oblq_rad) * sin(long_eclp_rad) * 1.495978707E+8;
  rtb_Gain[2] = r * sin(oblq_rad) * sin(long_eclp_rad) * 1.495978707E+8;
  for (lowAlt = 0; lowAlt < 3; lowAlt++) {
    rtb_sun_vector_eci_km[lowAlt] = 0.0;
    for (qY = 0; qY < 3; qY++) {
      a_0[lowAlt + 3 * qY] = 0.0;
      a_0[lowAlt + 3 * qY] += c_0[3 * qY] * c_c_0[lowAlt];
      a_0[lowAlt + 3 * qY] += c_0[3 * qY + 1] * c_c_0[lowAlt + 3];
      a_0[lowAlt + 3 * qY] += c_0[3 * qY + 2] * c_c_0[lowAlt + 6];
      rtb_sun_vector_eci_km[lowAlt] += a_0[3 * qY + lowAlt] * rtb_Gain[qY];
    }
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */

  /* RateTransition: '<S1>/Rate Transition7' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    memcpy(&rtDW.RateTransition7[0], &rtDW.RateTransition7_Buffer0[0], 9U *
           sizeof(real_T));

    /* RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3 = rtDW.RateTransition3_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition7' */

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Inport: '<Root>/orbit_tle'
   */
  /*  ----------------------------------------------------------------------- % */
  /*  LOAD CONSTANTS */
  /*  ----------------------------------------------------------------------- % */
  /* MATLAB Function 'sgp4_lib_fsw/MATLAB Function': '<S98>:1' */
  /*  SGP4 Orbit Propagator */
  /*  UW Husky-Sat1 - ADCS Subsystem team */
  /*    Author:     Taylor Reynolds */
  /*    Updated:    5/9/17 */
  /*  Based on "SpaceTrack Report #3: Models for Propagation of NORAD Element */
  /*  Sets", Hoots & Roerhrich, 1980. */
  /*  */
  /*  TLE Format: */
  /*    Line 1: Column | Description */
  /*            01          line number of element data */
  /*            03-07       satellite number */
  /*            08          classification (u = unclassified) */
  /*            10-11       last two digits of launch year */
  /*            12-14       launch number of year */
  /*            15-17       piece of launch */
  /*            19-20       epoch year (last two digits) */
  /*            21-32       epoch (DOY and fractional portion of the day) */
  /*            34-43       first derivative of the mean motion */
  /*            45-52       second time derivative of mean motion (decimal */
  /*                            assumed) */
  /*            54-61       BS drag term (decimal point assumed) */
  /*            63          ephemeris type */
  /*            65-68       element number */
  /*            69          checksum (mod 10) */
  /*     */
  /*    Line 2: Column  | Description */
  /*            01          line number of element data */
  /*            03-07       satellite number */
  /*            09-16       inclination (degrees) */
  /*            18-25       right ascension of the ascending node (degrees) */
  /*            27-33       eccentricity (decimal assumed) */
  /*            35-42       argument of perigee (degrees) */
  /*            44-51       mean anomaly (degrees) */
  /*            53-63       mean motion (revs per day) */
  /*            64-68       revolution number at epoch (revs) */
  /*            69          checksum (mod 10) */
  /*  */
  /*  ----------------------------------------------------------------------- % */
  /*  Inputs: */
  /*    - orbit_tle: NORAD two line element set containing orbit info */
  /*    - tsince: Time since epoch of TLE in MINUTES */
  /*  Outputs: */
  /*    - pos_frame: Position vector in the teme frame   */
  /*    - vel_frame: Velocity vector in the teme frame */
  /*  */
  /*  Variables: */
  /*    - n_o = SGP type "mean" mean motion at epoch */
  /*    - e_o = the "mean" eccentricity at epoch */
  /*    - i_o = the "mean" inclination at epoch */
  /*    - M_o = the "mean" mean anomaly at epoch */
  /*    - w_o = the "mean" argument of perigee at epoch */
  /*    - Om_o = the "mean" longitude of ascending node at epoch */
  /*    - nd_o  = the TRoC of n_o */
  /*    - ndd_o = the TRoC of nd_o */
  /*    - Bs = the SGP4 type drag coefficient */
  /*    - k_e = gravitational constant of Earth, sqrt(GM_e) */
  /*    - a_E = the equatorial radius of Earth */
  /*    - J_2 = the second gravitation zonal harmonic of Earth */
  /*    - J_3 = the third gravitational zonal harmonic of Earth */
  /*    - J_4 = the fourth gravitational zonal harmonic of Earth */
  /*    - (t-t_0) = time since epoch */
  /*    - k_2   = 0.5*J_2*a_E^2 */
  /*    - k_4   = -(3/8)*J_4*a_E^4 */
  /*    - A_30  = -J_3*a_E^3 */
  /*    - q_0   = parameter for the SGP4 density function */
  /*    - s     = parameter for the SGP4 density function */
  /*  ----------------------------------------------------------------------- % */
  /*  Function Body */
  /* '<S98>:1:75' k_2     = 5.413080e-4; */
  /*  CK2 = 0.5*J_2*a_E^2 */
  /* '<S98>:1:76' k_4     = 0.62098875e-6; */
  /*  CK4 = -3/8*J_4*a_E^4 */
  /* '<S98>:1:77' QOMS4   = 1.88027916e-9; */
  c = 1.88027916E-9;

  /*  QOMS2T = (q_0 - s)^4 * ER^4 */
  /* '<S98>:1:78' s       = 1.01222928; */
  mean_anom_sun_rad = 1.01222928;

  /*  S = s*ER */
  /* '<S98>:1:79' XJ3     = -0.2538815e-5; */
  /*  J_3 */
  /* '<S98>:1:80' XKE     = 0.743669161e-1; */
  /*  XKE = k_e*(ER/min)^{3/2} */
  /* '<S98>:1:81' XKMPER  = 6378.137; */
  /*  km/ER */
  /* '<S98>:1:82' XMNPDA  = 1440; */
  /*  time_units/day */
  /* '<S98>:1:83' a_E     = 1; */
  /*  distance units/ER */
  /* '<S98>:1:84' DE2RA   = 0.174532925e-1; */
  /*  radians/degree */
  /* '<S98>:1:85' TRUE    = 1; */
  /* '<S98>:1:86' FALSE   = 0; */
  /* '<S98>:1:87' r_E     = 6378.137; */
  /*  Earth's equatorial radius [km] */
  /* '<S98>:1:88' A_30    = -XJ3*a_E^3; */
  /*  see nomenclature */
  /* '<S98>:1:89' VKMPS   = XKMPER/60; */
  /*  Convert ER/min velocities to km/s */
  /*  ----------------------------------------------------------------------- % */
  /*  Line 1 */
  /* '<S98>:1:94' epoch_year  = orbit_tle(1); */
  /* '<S98>:1:95' epoch_JD    = orbit_tle(2); */
  /* '<S98>:1:96' BS          = orbit_tle(3); */
  /*  Line 2 */
  /* '<S98>:1:99' i_o     = orbit_tle(4)*DE2RA; */
  long_eclp_rad = rtU.orbit_tle[3] * 0.0174532925;

  /*  Radians (INC) */
  /* '<S98>:1:100' Om_o    = orbit_tle(5)*DE2RA; */
  /*  Radians (RAAN) */
  /* '<S98>:1:101' e_o     = orbit_tle(6); */
  /*  Non-dimensional (ECC) */
  /* '<S98>:1:102' w_o     = orbit_tle(7)*DE2RA; */
  c_s = rtU.orbit_tle[6] * 0.0174532925;

  /*  Radians (AOP) */
  /* '<S98>:1:103' M_o     = orbit_tle(8)*DE2RA; */
  c_c = rtU.orbit_tle[7] * 0.0174532925;

  /*  Radians (MNA) */
  /* '<S98>:1:104' n_o     = orbit_tle(9)*2*pi/XMNPDA; */
  oblq_rad = rtU.orbit_tle[8] * 2.0 * 3.1415926535897931 / 1440.0;

  /*  Revs per time unit (MNM)    */
  /*  Time since epoch                                   */
  /* '<S98>:1:107' tsince_JD      = (JD_J2000_cur - (epoch_JD-2451545)); */
  r = rtDW.RateTransition3 - (rtU.orbit_tle[1] - 2.451545E+6);

  /* '<S98>:1:108' if( abs(tsince_JD) < 1e-8 || tsince_JD < 0) */
  if ((fabs(r) < 1.0E-8) || (r < 0.0)) {
    /* '<S98>:1:109' tsince_JD   = 0; */
    r = 0.0;
  }

  /* '<S98>:1:112' tsince  = XMNPDA*tsince_JD; */
  r *= 1440.0;

  /* '<S98>:1:114' a_1  = (XKE/n_o)^(2/3); */
  b_s = rt_powd_snf(0.0743669161 / oblq_rad, 0.66666666666666663);

  /* '<S98>:1:115' d_1  = 1.5*(k_2/(a_1^2))*((3*cos(i_o)^2 - 1)/(1 - e_o^2)^(3/2)); */
  b_c = cos(long_eclp_rad);
  b_c = (b_c * b_c * 3.0 - 1.0) / rt_powd_snf(1.0 - rtU.orbit_tle[5] *
    rtU.orbit_tle[5], 1.5) * (0.000541308 / (b_s * b_s) * 1.5);

  /* '<S98>:1:116' a_o  = a_1*(1 - (1/3)*d_1 - d_1^2 - (134/81)*d_1^3); */
  b_c = (((1.0 - 0.33333333333333331 * b_c) - b_c * b_c) - 1.654320987654321 *
         rt_powd_snf(b_c, 3.0)) * b_s;

  /* '<S98>:1:117' d_o  = (3/2)*(k_2/(a_o^2))*((3*cos(i_o)^2 - 1)/(1 - e_o^2)^(3/2)); */
  b_s = cos(long_eclp_rad);
  d_o = (b_s * b_s * 3.0 - 1.0) / rt_powd_snf(1.0 - rtU.orbit_tle[5] *
    rtU.orbit_tle[5], 1.5) * (0.000541308 / (b_c * b_c) * 1.5);

  /* '<S98>:1:118' n_o_pp   = n_o/(1 + d_o); */
  b_s = oblq_rad / (1.0 + d_o);

  /* '<S98>:1:119' a_o_pp   = a_o/(1 - d_o); */
  d_o = b_c / (1.0 - d_o);

  /* '<S98>:1:121' r_p     = r_E*(a_o_pp*(1 - e_o) - a_E); */
  oblq_rad = ((1.0 - rtU.orbit_tle[5]) * d_o - 1.0) * 6378.137;

  /*  Radius of perigee */
  /*  Check low altitude condition                                     */
  /* '<S98>:1:124' if( a_o_pp*(1-e_o)/a_E < (220/XKMPER + a_E) ) */
  if ((1.0 - rtU.orbit_tle[5]) * d_o < 1.0344928307435228) {
    /* '<S98>:1:125' lowAlt  = TRUE; */
    lowAlt = 1;
  } else {
    /* '<S98>:1:126' else */
    /* '<S98>:1:127' lowAlt  = FALSE; */
    lowAlt = 0;
  }

  /*  Check if perigee is between [98,156]km or below 98km and adjust the */
  /*  constant s accordingly. */
  /* '<S98>:1:133' if( (r_p > 98) && (r_p < 156) ) */
  if ((oblq_rad > 98.0) && (oblq_rad < 156.0)) {
    /* '<S98>:1:134' s_star  = a_o_pp*(1 - e_o) - s + a_E; */
    mean_anom_sun_rad = ((1.0 - rtU.orbit_tle[5]) * d_o - 1.01222928) + 1.0;

    /* '<S98>:1:135' QOMS4   = (QOMS4^(0.25) + s - s_star)^4; */
    c = rt_powd_snf(1.0188142770258546 - mean_anom_sun_rad, 4.0);

    /* '<S98>:1:136' s       = s_star; */
  } else {
    if (oblq_rad < 98.0) {
      /* '<S98>:1:137' elseif( r_p < 98 ) */
      /* '<S98>:1:138' s_star  = 20/XKMPER + a_E; */
      /* '<S98>:1:139' QOMS4   = (QOMS4^(0.25) + s - s_star)^4; */
      c = 6.0426196528035638E-8;

      /* '<S98>:1:140' s       = s_star; */
      mean_anom_sun_rad = 1.0031357118857749;
    }
  }

  /*  Constants */
  /* '<S98>:1:144' tht     = cos(i_o); */
  oblq_rad = cos(long_eclp_rad);

  /* '<S98>:1:145' xi      = 1/(a_o_pp - s); */
  xi = 1.0 / (d_o - mean_anom_sun_rad);

  /* '<S98>:1:146' b_o     = (1 - e_o^2)^(0.5); */
  b_o = sqrt(1.0 - rtU.orbit_tle[5] * rtU.orbit_tle[5]);

  /* '<S98>:1:147' eta     = a_o_pp*e_o*xi; */
  eta = d_o * rtU.orbit_tle[5] * xi;

  /* '<S98>:1:148' C_2     = QOMS4*xi^4*n_o_pp*(1-eta^2)^(-7/2)*((a_o_pp*(1 + ... */
  /* '<S98>:1:149'             (3/2)*eta^2 + 4*e_o*eta + e_o*eta^3)) + ... */
  /* '<S98>:1:150'             (3/2)*k_2*xi*(-0.5+1.5*tht^2)*(8+24*eta^2+3*eta^4)/(1-eta^2)); */
  /* '<S98>:1:151' C_1     = BS*C_2; */
  C_1 = ((((eta * eta * 1.5 + 1.0) + 4.0 * rtU.orbit_tle[5] * eta) +
          rtU.orbit_tle[5] * rt_powd_snf(eta, 3.0)) * d_o + (oblq_rad * oblq_rad
          * 1.5 + -0.5) * (0.00081196200000000006 * xi) * ((eta * eta * 24.0 +
           8.0) + 3.0 * rt_powd_snf(eta, 4.0)) / (1.0 - eta * eta)) * (c *
    rt_powd_snf(xi, 4.0) * b_s * rt_powd_snf(1.0 - eta * eta, -3.5)) *
    rtU.orbit_tle[2];

  /* '<S98>:1:152' C_3     = (QOMS4*xi^5*A_30*n_o_pp*a_E*sin(i_o))/(k_2*e_o); */
  /* '<S98>:1:153' C_4     = 2*n_o_pp*QOMS4*xi^4*a_o_pp*b_o^2*(1-eta^2)^(-7/2)*... */
  /* '<S98>:1:154'             ((2*eta*(1+e_o*eta) + 0.5*e_o + 0.5*eta^3) - (2*k_2*xi)/(a_o_pp*(1-eta^2))*... */
  /* '<S98>:1:155'             (3*(1-3*tht^2)*(1-(3/2)*eta^2-2*e_o*eta-0.5*e_o*eta^3)+(3/4)*(1-tht^2)*... */
  /* '<S98>:1:156'             (2*eta^2-e_o*eta-e_o*eta^3)*cos(2*w_o))); */
  C_4 = ((((rtU.orbit_tle[5] * eta + 1.0) * (2.0 * eta) + 0.5 * rtU.orbit_tle[5])
          + 0.5 * rt_powd_snf(eta, 3.0)) - ((((1.0 - eta * eta * 1.5) - 2.0 *
            rtU.orbit_tle[5] * eta) - 0.5 * rtU.orbit_tle[5] * rt_powd_snf(eta,
            3.0)) * ((1.0 - oblq_rad * oblq_rad * 3.0) * 3.0) + ((eta * eta *
            2.0 - rtU.orbit_tle[5] * eta) - rtU.orbit_tle[5] * rt_powd_snf(eta,
            3.0)) * ((1.0 - oblq_rad * oblq_rad) * 0.75) * cos(2.0 * c_s)) *
         (0.001082616 * xi / ((1.0 - eta * eta) * d_o))) * (2.0 * b_s * c *
    rt_powd_snf(xi, 4.0) * d_o * (b_o * b_o) * rt_powd_snf(1.0 - eta * eta, -3.5));

  /* '<S98>:1:157' C_5     = 0; */
  C_5 = 0.0;

  /* '<S98>:1:158' D_2     = 0; */
  D_2 = 0.0;

  /* '<S98>:1:159' D_3     = 0; */
  D_3 = 0.0;

  /* '<S98>:1:160' D_4     = 0; */
  D_4 = 0.0;

  /* '<S98>:1:161' IL2     = 1.5*C_1; */
  IL2 = 1.5 * C_1;

  /* '<S98>:1:162' IL3     = 0; */
  IL3 = 0.0;

  /* '<S98>:1:163' IL4     = 0; */
  IL4 = 0.0;

  /* '<S98>:1:164' IL5     = 0; */
  IL5 = 0.0;

  /* '<S98>:1:166' if( lowAlt  == FALSE ) */
  if (lowAlt == 0) {
    /* '<S98>:1:167' C_5     = 2*QOMS4*xi^4*a_o_pp*b_o^2*(1-eta^2)^(-7/2)*(1+(11/4)*eta*(eta+e_o) + e_o*eta^3); */
    C_5 = 2.0 * c * rt_powd_snf(xi, 4.0) * d_o * (b_o * b_o) * rt_powd_snf(1.0 -
      eta * eta, -3.5) * ((2.75 * eta * (eta + rtU.orbit_tle[5]) + 1.0) +
                          rtU.orbit_tle[5] * rt_powd_snf(eta, 3.0));

    /* '<S98>:1:168' D_2     = 4*a_o_pp*xi*C_1^2; */
    D_2 = 4.0 * d_o * xi * (C_1 * C_1);

    /* '<S98>:1:169' D_3     = (4/3)*a_o_pp*xi^2*(17*a_o_pp + s)*C_1^3; */
    D_3 = 1.3333333333333333 * d_o * (xi * xi) * (17.0 * d_o + mean_anom_sun_rad)
      * rt_powd_snf(C_1, 3.0);

    /* '<S98>:1:170' D_4     = (2/3)*a_o_pp*xi^3*(221*a_o_pp + 31*s)*C_1^4; */
    D_4 = 0.66666666666666663 * d_o * rt_powd_snf(xi, 3.0) * (221.0 * d_o + 31.0
      * mean_anom_sun_rad) * rt_powd_snf(C_1, 4.0);

    /* '<S98>:1:171' IL3     = D_2 + 2*C_1^2; */
    IL3 = C_1 * C_1 * 2.0 + D_2;

    /* '<S98>:1:172' IL4     = 0.25*(3*D_3 + 12*C_1*D_2 + 10*C_1^3); */
    IL4 = ((12.0 * C_1 * D_2 + 3.0 * D_3) + 10.0 * rt_powd_snf(C_1, 3.0)) * 0.25;

    /* '<S98>:1:173' IL5     = 0.2*(3*D_4 + 12*C_1*D_3 + 6*D_2^2 + 30*C_1^2*D_2 + 15*C_1^4); */
    IL5 = ((((12.0 * C_1 * D_3 + 3.0 * D_4) + D_2 * D_2 * 6.0) + C_1 * C_1 *
            30.0 * D_2) + 15.0 * rt_powd_snf(C_1, 4.0)) * 0.2;
  }

  /*  Secular effects of atm drag and gravitation */
  /* '<S98>:1:178' M_DF    = M_o + ( 1 + (3*k_2*(3*tht^2-1))/(2*a_o_pp^2*b_o^3) + ... */
  /* '<S98>:1:179'              (3*k_2^2*(13-78*tht^2+137*tht^4))/(16*a_o_pp^4*b_o^7) )*n_o_pp*tsince; */
  M_DF = (((oblq_rad * oblq_rad * 3.0 - 1.0) * 0.0016239240000000001 / (d_o *
            d_o * 2.0 * rt_powd_snf(b_o, 3.0)) + 1.0) + ((13.0 - oblq_rad *
            oblq_rad * 78.0) + 137.0 * rt_powd_snf(oblq_rad, 4.0)) *
          8.7904305259200008E-7 / (16.0 * rt_powd_snf(d_o, 4.0) * rt_powd_snf
           (b_o, 7.0))) * b_s * r + c_c;

  /* '<S98>:1:180' w_DF    = w_o + ( (-3*k_2*(1-5*tht^2))/(2*a_o_pp^2*b_o^3) +... */
  /* '<S98>:1:181'                    (3*k_2^2*(7-114*tht^2+395*tht^4))/(16*a_o_pp^4*b_o^8) + ... */
  /* '<S98>:1:182'                     (5*k_4*(3-36*tht^2+49*tht^4))/(4*a_o_pp^4*b_o^8) )*n_o_pp*tsince; */
  b_c = ((((7.0 - oblq_rad * oblq_rad * 114.0) + 395.0 * rt_powd_snf(oblq_rad,
            4.0)) * 8.7904305259200008E-7 / (16.0 * rt_powd_snf(d_o, 4.0) *
           rt_powd_snf(b_o, 8.0)) + (1.0 - oblq_rad * oblq_rad * 5.0) *
          -0.0016239240000000001 / (d_o * d_o * 2.0 * rt_powd_snf(b_o, 3.0))) +
         ((3.0 - oblq_rad * oblq_rad * 36.0) + 49.0 * rt_powd_snf(oblq_rad, 4.0))
         * 3.1049437500000002E-6 / (4.0 * rt_powd_snf(d_o, 4.0) * rt_powd_snf
          (b_o, 8.0))) * b_s * r + c_s;

  /* '<S98>:1:183' Om_DF   = Om_o + ( (-3*k_2*tht)/(a_o_pp^2*b_o^4) +... */
  /* '<S98>:1:184'                     (3*k_2^2*(4*tht-19*tht^3))/(2*a_o_pp^4*b_o^8) +... */
  /* '<S98>:1:185'                      (5*k_4*tht*(3-7*tht^2))/(2*a_o_pp^4*b_o^8) )*n_o_pp*tsince; */
  /* '<S98>:1:187' Om      = Om_DF - (21/2)*( (n_o_pp*k_2*tht)/(a_o_pp^2*b_o^2) )*C_1*tsince^2; */
  mean_anom_sun_rad = ((((4.0 * oblq_rad - 19.0 * rt_powd_snf(oblq_rad, 3.0)) *
    8.7904305259200008E-7 / (2.0 * rt_powd_snf(d_o, 4.0) * rt_powd_snf(b_o, 8.0))
    + -0.0016239240000000001 * oblq_rad / (d_o * d_o * rt_powd_snf(b_o, 4.0))) +
                        (3.0 - oblq_rad * oblq_rad * 7.0) *
                        (3.1049437500000002E-6 * oblq_rad) / (2.0 * rt_powd_snf
    (d_o, 4.0) * rt_powd_snf(b_o, 8.0))) * b_s * r + rtU.orbit_tle[4] *
                       0.0174532925) - b_s * 0.000541308 * oblq_rad / (d_o * d_o
    * (b_o * b_o)) * 10.5 * C_1 * (r * r);

  /* '<S98>:1:189' if( lowAlt == FALSE ) */
  if (lowAlt == 0) {
    /*  #5 %     */
    /* '<S98>:1:190' d_w     = BS*C_3*cos(w_o)*tsince; */
    c_s = c * rt_powd_snf(xi, 5.0) * 2.538815E-6 * b_s * sin(long_eclp_rad) /
      (0.000541308 * rtU.orbit_tle[5]) * rtU.orbit_tle[2] * cos(c_s) * r;

    /* '<S98>:1:191' d_M     = -(2/3)*QOMS4*BS*xi^4*(a_E/(e_o*eta))*( (1+eta*cos(M_DF))^3 - (1 + eta*cos(M_o))^3 ); */
    c = -0.66666666666666663 * c * rtU.orbit_tle[2] * rt_powd_snf(xi, 4.0) *
      (1.0 / (rtU.orbit_tle[5] * eta)) * (rt_powd_snf(eta * cos(M_DF) + 1.0, 3.0)
      - rt_powd_snf(eta * cos(c_c) + 1.0, 3.0));

    /* '<S98>:1:192' M_p     = M_DF + d_w + d_M; */
    M_DF = (M_DF + c_s) + c;

    /* '<S98>:1:193' w       = w_DF - d_w - d_M; */
    b_c = (b_c - c_s) - c;

    /* '<S98>:1:194' e       = e_o - BS*C_4*tsince - BS*C_5*( sin(M_p) - sin(M_o) ); */
    c = (rtU.orbit_tle[5] - rtU.orbit_tle[2] * C_4 * r) - rtU.orbit_tle[2] * C_5
      * (sin(M_DF) - sin(c_c));

    /* '<S98>:1:195' a       = a_o_pp*( 1 - C_1*tsince - D_2*tsince^2 - D_3*tsince^3 - D_4*tsince^4 )^2; */
    c_c = (((1.0 - C_1 * r) - r * r * D_2) - D_3 * rt_powd_snf(r, 3.0)) - D_4 *
      rt_powd_snf(r, 4.0);
    c_c = c_c * c_c * d_o;

    /* '<S98>:1:196' L       = M_p + w + Om + n_o_pp*( IL2*tsince^2 + IL3*tsince^3 +... */
    /* '<S98>:1:197'             IL4*tsince^4 + IL5*tsince^5 ); */
    r = (((r * r * IL2 + IL3 * rt_powd_snf(r, 3.0)) + IL4 * rt_powd_snf(r, 4.0))
         + IL5 * rt_powd_snf(r, 5.0)) * b_s + ((M_DF + b_c) + mean_anom_sun_rad);
  } else {
    /* '<S98>:1:198' else */
    /* '<S98>:1:199' M_p     = M_DF; */
    /* '<S98>:1:200' w       = w_DF; */
    /* '<S98>:1:201' a       = a_o_pp*(1 - C_1*tsince)^2; */
    c_c = 1.0 - C_1 * r;
    c_c = c_c * c_c * d_o;

    /* '<S98>:1:202' e       = e_o - BS*C_4*tsince; */
    c = rtU.orbit_tle[5] - rtU.orbit_tle[2] * C_4 * r;

    /* '<S98>:1:203' L       = M_p + w + Om + n_o_pp*IL2*tsince^2; */
    r = ((M_DF + b_c) + mean_anom_sun_rad) + b_s * IL2 * (r * r);
  }

  /* '<S98>:1:206' b       = sqrt(1-e^2); */
  d_o = sqrt(1.0 - c * c);

  /* '<S98>:1:207' n       = XKE/(a^(3/2)); */
  /*  Add the long-period periodic terms */
  /* '<S98>:1:211' a_xN    = e*cos(w); */
  b_s = c * cos(b_c);

  /* '<S98>:1:212' L_L     = (A_30*sin(i_o)/(8*k_2*a*b^2))*e*cos(w)*((3+5*tht)/(1+tht)); */
  /* '<S98>:1:213' a_yNL   = A_30*sin(i_o)/(4*k_2*a*b^2); */
  /* '<S98>:1:214' L_T     = L + L_L; */
  /* '<S98>:1:215' a_yN    = e*sin(w) + a_yNL; */
  c_s = 2.538815E-6 * sin(long_eclp_rad) / (0.002165232 * c_c * (d_o * d_o)) + c
    * sin(b_c);

  /* '<S98>:1:217' U       = mod(L_T - Om,2*pi); */
  r = ((2.538815E-6 * sin(long_eclp_rad) / (0.004330464 * c_c * (d_o * d_o)) * c
        * cos(b_c) * ((5.0 * oblq_rad + 3.0) / (1.0 + oblq_rad)) + r) -
       mean_anom_sun_rad) / 6.2831853071795862;
  if (fabs(r - rt_roundd_snf(r)) <= 2.2204460492503131E-16 * fabs(r)) {
    r = 0.0;
  } else {
    r = (r - floor(r)) * 6.2831853071795862;
  }

  /* '<S98>:1:218' Epw     = kepler(U,a_yN,a_xN); */
  /*  Solves Kepler's equation for Epw = E + w using iterative method */
  /* '<S98>:1:262' tol         = 1e-8; */
  /* '<S98>:1:263' iter_max    = 1000; */
  /* '<S98>:1:264' Epw         = U; */
  c = r;

  /* '<S98>:1:265' Epw_new     = 0; */
  b_c = 0.0;

  /* '<S98>:1:266' iter        = 0; */
  lowAlt = 0;

  /* '<S98>:1:268' while( (abs(Epw - Epw_new) > tol) && (iter < iter_max) ) */
  while ((fabs(c - b_c) > 1.0E-8) && (lowAlt < 1000)) {
    /* '<S98>:1:269' Epw = Epw_new; */
    c = b_c;

    /* '<S98>:1:270' dEpw   = (U-a_yN*cos(Epw) + a_xN*sin(Epw) - Epw)/(-a_yN*sin(Epw) - a_xN*cos(Epw) + 1); */
    /* '<S98>:1:271' Epw_new     = Epw + dEpw; */
    b_c += (((r - c_s * cos(b_c)) + b_s * sin(b_c)) - b_c) / ((-c_s * sin(b_c) -
      b_s * cos(b_c)) + 1.0);

    /* '<S98>:1:272' iter = iter +1; */
    lowAlt++;
  }

  /* '<S98>:1:275' Epw     = Epw_new; */
  /*  Preliminary quantities for short-period periodics */
  /* '<S98>:1:221' ecE     = a_xN*cos(Epw) + a_yN*sin(Epw); */
  /* '<S98>:1:222' esE     = a_xN*sin(Epw) - a_yN*cos(Epw); */
  IL2 = b_s * sin(b_c) - c_s * cos(b_c);

  /* '<S98>:1:223' e_L     = (a_xN^2 + a_yN^2)^(1/2); */
  d_o = sqrt(b_s * b_s + c_s * c_s);

  /* '<S98>:1:224' p_L     = a*(1 - e_L^2); */
  c = (1.0 - d_o * d_o) * c_c;

  /* '<S98>:1:225' r       = a*(1 - ecE); */
  r = (1.0 - (b_s * cos(b_c) + c_s * sin(b_c))) * c_c;

  /* '<S98>:1:226' r_dot   = XKE*sqrt(a)*esE/r; */
  /* '<S98>:1:227' r_f_dot     = XKE*sqrt(p_L)/r; */
  /* '<S98>:1:228' cosu    = (a/r)*( cos(Epw) - a_xN + ((a_yN*esE)/(1+sqrt(1 - e_L^2))) ); */
  /* '<S98>:1:229' sinu    = (a/r)*( sin(Epw) - a_yN - ((a_xN*esE)/(1 + sqrt(1 - e_L^2))) ); */
  /* '<S98>:1:230' u       = atan2(sinu,cosu); */
  c_c = rt_atan2d_snf(((sin(b_c) - c_s) - b_s * IL2 / (sqrt(1.0 - d_o * d_o) +
    1.0)) * (c_c / r), (c_s * IL2 / (sqrt(1.0 - d_o * d_o) + 1.0) + (cos(b_c) -
    b_s)) * (c_c / r));

  /* '<S98>:1:231' dr      = (k_2/(2*p_L))*(1 - tht^2)*cos(2*u); */
  /* '<S98>:1:232' du      = -(k_2/(4*p_L^2))*(7*tht^2 - 1)*sin(2*u); */
  /* '<S98>:1:233' dOm     = (3*k_2*tht/(2*p_L^2))*sin(2*u); */
  /* '<S98>:1:234' di      = (3*k_2*tht/(2*p_L^2))*sin(i_o)*cos(2*u); */
  /* '<S98>:1:235' dr_dot  = -((k_2*n)/p_L)*(1-tht^2)*sin(2*u); */
  /* '<S98>:1:236' dr_f_dot    = (k_2*n/p_L)*( (1-tht^2)*cos(2*u) - (3/2)*(1-3*tht^2) ); */
  /*  Add the short-period periodics to get osculating elements */
  /* '<S98>:1:239' r_k     = r*(1 - (3/2)*k_2*sqrt(1 - e_L^2)*(3*tht^2 - 1)/p_L^2) + dr; */
  r = (1.0 - sqrt(1.0 - d_o * d_o) * 0.00081196200000000006 * (oblq_rad *
        oblq_rad * 3.0 - 1.0) / (c * c)) * r + 0.000541308 / (2.0 * c) * (1.0 -
    oblq_rad * oblq_rad) * cos(2.0 * c_c);

  /* '<S98>:1:240' u_k     = u + du; */
  b_s = -(0.000541308 / (c * c * 4.0)) * (oblq_rad * oblq_rad * 7.0 - 1.0) * sin
    (2.0 * c_c) + c_c;

  /* '<S98>:1:241' Om_k    = Om + dOm; */
  mean_anom_sun_rad += 0.0016239240000000001 * oblq_rad / (c * c * 2.0) * sin
    (2.0 * c_c);

  /* '<S98>:1:242' i_k     = i_o + di; */
  long_eclp_rad += 0.0016239240000000001 * oblq_rad / (c * c * 2.0) * sin
    (long_eclp_rad) * cos(2.0 * c_c);

  /* '<S98>:1:243' r_dot_k     = r_dot + dr_dot; */
  /* '<S98>:1:244' r_f_dot_k   = r_f_dot + dr_f_dot; */
  /*  Create unit orientation vectors */
  /* '<S98>:1:247' M       = [ -sin(Om_k)*cos(i_k); cos(Om_k)*cos(i_k); sin(i_k)]; */
  /* '<S98>:1:248' N       = [ cos(Om_k); sin(Om_k); 0 ]; */
  /* '<S98>:1:250' U       = M.*sin(u_k) + N.*cos(u_k); */
  oblq_rad = sin(b_s);
  c_c = cos(b_s);

  /* '<S98>:1:251' V       = M.*cos(u_k) - N.*sin(u_k); */
  /*  Find position and velocity in km & km/s */
  /* '<S98>:1:254' pos_teme_km     = r_k.*U.*XKMPER; */
  /* '<S98>:1:255' vel_teme_kmps   = (r_dot_k.*U + r_f_dot_k.*V).*(VKMPS); */
  c = (-sin(mean_anom_sun_rad) * cos(long_eclp_rad) * oblq_rad + cos
       (mean_anom_sun_rad) * c_c) * r * 6378.137;
  mean_anom_sun_rad = (cos(mean_anom_sun_rad) * cos(long_eclp_rad) * oblq_rad +
                       sin(mean_anom_sun_rad) * c_c) * r * 6378.137;
  long_eclp_rad = (sin(long_eclp_rad) * oblq_rad + 0.0 * c_c) * r * 6378.137;

  /* End of MATLAB Function: '<S3>/MATLAB Function' */
  /*  Constants */
  /* MATLAB Function 'sun_vector_lib/MATLAB Function1': '<S100>:1' */
  /* '<S100>:1:4' M2KM        = 1e-3; */
  /* '<S100>:1:5' ECCE2       = 0.006694385000; */
  /* '<S100>:1:6' RE          = 6378.137; */
  /* '<S100>:1:7' TRUE        = 1; */
  /* '<S100>:1:8' FALSE       = 0; */
  /*  ----- */
  /*  Convert to sc position vector to km if necessary */
  /* '<S100>:1:12' sc_pos_eci_km   = sc_pos_eci_m*M2KM; */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S1>/Gain' incorporates:
     *  Product: '<S1>/Product1'
     */
    c_c = 1000.0 * (rtDW.RateTransition7[i + 6] * long_eclp_rad +
                    (rtDW.RateTransition7[i + 3] * mean_anom_sun_rad +
                     rtDW.RateTransition7[i] * c));

    /* MATLAB Function: '<S4>/MATLAB Function1' */
    sc_pos_eci_km[i] = c_c * 0.001;

    /* Gain: '<S1>/Gain' */
    rtb_Gain[i] = c_c;
  }

  /* MATLAB Function: '<S4>/MATLAB Function1' */
  /* ----- */
  /*  Main Function */
  /* '<S100>:1:16' LOS     = FALSE; */
  lowAlt = 0;

  /* '<S100>:1:18' sun_vector_eci_km(3)    = sun_vector_eci_km(3)/(sqrt(1 - ECCE2)); */
  rtb_sun_vector_eci_km[2] /= 0.99664718682189635;

  /* '<S100>:1:19' sc_pos_eci_km(3)        = sc_pos_eci_km(3)/(sqrt(1 - ECCE2)); */
  sc_pos_eci_km[2] /= 0.99664718682189635;

  /* '<S100>:1:21' sun_vec     = sun_vector_eci_km; */
  /* '<S100>:1:22' sc_vec      = sc_pos_eci_km; */
  /* '<S100>:1:24' sc2sun_unit  = (sun_vec - sc_vec)/norm(sun_vec - sc_vec); */
  rtb_sun_vector_eci_km_0[0] = rtb_sun_vector_eci_km[0] - sc_pos_eci_km[0];
  rtb_sun_vector_eci_km_0[1] = rtb_sun_vector_eci_km[1] - sc_pos_eci_km[1];
  rtb_sun_vector_eci_km_0[2] = rtb_sun_vector_eci_km[2] - sc_pos_eci_km[2];
  long_eclp_rad = norm(rtb_sun_vector_eci_km_0);

  /*  Determine if the sc is in the light or shadow */
  /*    Call vector 1 the sun, vector 2 the sc */
  /* '<S100>:1:29' mag1    = norm(sun_vec); */
  mean_anom_sun_rad = norm(rtb_sun_vector_eci_km);

  /* '<S100>:1:30' mag2    = norm(sc_vec); */
  oblq_rad = norm(sc_pos_eci_km);

  /* '<S100>:1:32' mag1_sq     = mag1*mag1; */
  mean_anom_sun_rad *= mean_anom_sun_rad;

  /* '<S100>:1:33' mag2_sq     = mag2*mag2; */
  /* '<S100>:1:35' sun_sc_dot  = dot(sun_vec,sc_vec); */
  r = (rtb_sun_vector_eci_km[0] * sc_pos_eci_km[0] + rtb_sun_vector_eci_km[1] *
       sc_pos_eci_km[1]) + rtb_sun_vector_eci_km[2] * sc_pos_eci_km[2];

  /*  Find t_min */
  /* '<S100>:1:38' t_min_num   = mag1_sq - sun_sc_dot; */
  /* '<S100>:1:39' t_min_den   = mag1_sq + mag2_sq - 2*sun_sc_dot; */
  oblq_rad = (oblq_rad * oblq_rad + mean_anom_sun_rad) - 2.0 * r;

  /* '<S100>:1:41' if ( t_min_den < 0.0001  ) */
  if (oblq_rad < 0.0001) {
    /* '<S100>:1:42' t_min = 0.0; */
    oblq_rad = 0.0;
  } else {
    /* '<S100>:1:43' else */
    /* '<S100>:1:44' t_min = ( t_min_num ) / ( t_min_den ); */
    oblq_rad = (mean_anom_sun_rad - r) / oblq_rad;
  }

  /* '<S100>:1:47' c_t_min_sq  = ((1-t_min)*mag1_sq + sun_sc_dot*t_min)/RE^2; */
  /*  Check LoS */
  /* '<S100>:1:50' if( t_min < 0 || t_min > 0.999979 ) */
  if ((oblq_rad < 0.0) || (oblq_rad > 0.999979)) {
    /* '<S100>:1:51' LOS     = TRUE; */
    lowAlt = 1;
  }

  /* Outport: '<Root>/sc2sun_unit' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function1'
   */
  /* '<S100>:1:56' sc_in_sun   = LOS; */
  rtY.sc2sun_unit[0] = (rtb_sun_vector_eci_km[0] - sc_pos_eci_km[0]) /
    long_eclp_rad;
  rtY.sc2sun_unit[1] = (rtb_sun_vector_eci_km[1] - sc_pos_eci_km[1]) /
    long_eclp_rad;
  rtY.sc2sun_unit[2] = (rtb_sun_vector_eci_km[2] - sc_pos_eci_km[2]) /
    long_eclp_rad;

  /* Outport: '<Root>/sc_in_sun' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function1'
   */
  rtY.sc_in_sun = lowAlt;

  /* RateTransition: '<S1>/Rate Transition2' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    memcpy(&rtDW.RateTransition2[0], &rtDW.RateTransition2_Buffer0[0], 9U *
           sizeof(real_T));

    /* RateTransition: '<S1>/Rate Transition5' */
    memcpy(&rtDW.RateTransition5[0], &rtDW.RateTransition5_Buffer0[0], 9U *
           sizeof(real_T));
  }

  /* End of RateTransition: '<S1>/Rate Transition2' */

  /* Product: '<S1>/Product' incorporates:
   *  Math: '<S1>/Math Function'
   */
  for (lowAlt = 0; lowAlt < 3; lowAlt++) {
    rtb_sun_vector_eci_km[lowAlt] = rtDW.RateTransition5[3 * lowAlt + 2] *
      rtb_Gain[2] + (rtDW.RateTransition5[3 * lowAlt + 1] * rtb_Gain[1] +
                     rtDW.RateTransition5[3 * lowAlt] * rtb_Gain[0]);
  }

  /* End of Product: '<S1>/Product' */

  /* Sqrt: '<S11>/sqrt' incorporates:
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Sum: '<S11>/Sum2'
   */
  c_c = sqrt(rtb_sun_vector_eci_km[0] * rtb_sun_vector_eci_km[0] +
             rtb_sun_vector_eci_km[1] * rtb_sun_vector_eci_km[1]);

  /* Outputs for Iterator SubSystem: '<S5>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S13>/While Iterator'
   */
  s13_iter = 1;
  do {
    long_eclp_rad = rtDW.Memory_PreviousInput;
    if (!(s13_iter > 0)) {
      long_eclp_rad = rt_atan2d_snf(rtb_sun_vector_eci_km[2],
        0.99664718933525254 * c_c);
    }

    oblq_rad = sin(long_eclp_rad);
    mean_anom_sun_rad = cos(long_eclp_rad);
    c = rt_atan2d_snf(42841.31151331366 * oblq_rad * oblq_rad * oblq_rad +
                      rtb_sun_vector_eci_km[2], c_c - mean_anom_sun_rad *
                      mean_anom_sun_rad * mean_anom_sun_rad *
                      0.00669437999014133 * 6.378137E+6);
    oblq_rad = rt_atan2d_snf(0.99664718933525254 * sin(c), cos(c));
    rtDW.Memory_PreviousInput = oblq_rad;
    s13_iter++;
  } while ((long_eclp_rad != oblq_rad) && (s13_iter <= 5));

  /* End of Outputs for SubSystem: '<S5>/While Iterator Subsystem' */

  /* UnitConversion: '<S10>/Unit Conversion' incorporates:
   *  Trigonometry: '<S5>/Trigonometric Function2'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  b_c = 57.295779513082323 * c;
  b_s = 57.295779513082323 * rt_atan2d_snf(rtb_sun_vector_eci_km[1],
    rtb_sun_vector_eci_km[0]);

  /* UnitConversion: '<S29>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  long_eclp_rad = 0.017453292519943295 * b_c;

  /* Trigonometry: '<S6>/sincos' */
  r = cos(long_eclp_rad);
  long_eclp_rad = sin(long_eclp_rad);
  c_s = r;

  /* UnitConversion: '<S29>/Unit Conversion' */
  xi = long_eclp_rad;
  long_eclp_rad = 0.017453292519943295 * b_s;

  /* Trigonometry: '<S6>/sincos' */
  r = cos(long_eclp_rad);
  long_eclp_rad = sin(long_eclp_rad);

  /* UnaryMinus: '<S20>/Unary Minus' incorporates:
   *  Product: '<S20>/u(1)*u(4)'
   *  Trigonometry: '<S6>/sincos'
   */
  rtb_VectorConcatenate[0] = -(xi * r);

  /* UnaryMinus: '<S23>/Unary Minus' */
  rtb_VectorConcatenate[1] = -long_eclp_rad;

  /* UnaryMinus: '<S26>/Unary Minus' incorporates:
   *  Product: '<S26>/u(3)*u(4)'
   *  Trigonometry: '<S6>/sincos'
   */
  rtb_VectorConcatenate[2] = -(c_s * r);

  /* UnaryMinus: '<S21>/Unary Minus' incorporates:
   *  Product: '<S21>/u(1)*u(2)'
   */
  rtb_VectorConcatenate[3] = -(xi * long_eclp_rad);

  /* SignalConversion: '<S30>/ConcatBufferAtVector ConcatenateIn5' incorporates:
   *  Trigonometry: '<S6>/sincos'
   */
  rtb_VectorConcatenate[4] = r;

  /* UnaryMinus: '<S27>/Unary Minus' incorporates:
   *  Product: '<S27>/u(2)*u(3)'
   */
  rtb_VectorConcatenate[5] = -(long_eclp_rad * c_s);

  /* SignalConversion: '<S30>/ConcatBufferAtVector ConcatenateIn7' */
  rtb_VectorConcatenate[6] = c_s;

  /* SignalConversion: '<S30>/ConcatBufferAtVector ConcatenateIn8' incorporates:
   *  Constant: '<S25>/Constant'
   */
  rtb_VectorConcatenate[7] = 0.0;

  /* UnaryMinus: '<S28>/Unary Minus' */
  rtb_VectorConcatenate[8] = -xi;

  /* RateTransition: '<S1>/Rate Transition1' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    for (i = 0; i < 6; i++) {
      rtDW.RateTransition1[i] = rtDW.RateTransition1_Buffer0[i];
    }
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */

  /* MATLAB Function: '<S2>/MATLAB Function' */
  /*  UW HuskySat 1, ADCS Subsystem */
  /*    T. Reynolds, Updated: 8.24.17 */
  /* MATLAB Function 'estimate_eci_vectors/mag_vector/MATLAB Function': '<S7>:1' */
  /*  Converts a time vector into a decimal year number. See Vallado pp 200-201 */
  /*  for reference algorithms. */
  /* '<S7>:1:9' year    = time_vec(1); */
  /* '<S7>:1:10' month   = time_vec(2); */
  /* '<S7>:1:11' day     = time_vec(3); */
  /* '<S7>:1:12' hour    = time_vec(4); */
  /* '<S7>:1:13' min     = time_vec(5); */
  /* '<S7>:1:14' sec     = time_vec(6); */
  /*  find day of year - valid until 2100 */
  /* '<S7>:1:17' Lmonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; */
  for (lowAlt = 0; lowAlt < 12; lowAlt++) {
    Lmonth[lowAlt] = b_0[lowAlt];
  }

  /* '<S7>:1:18' days_in_year    = 365.25; */
  long_eclp_rad = 365.25;

  /* '<S7>:1:20' if mod(year,4) == 0 */
  if (rtDW.RateTransition1[0] - floor(rtDW.RateTransition1[0] / 4.0) * 4.0 ==
      0.0) {
    /* '<S7>:1:21' Lmonth(2) = 29; */
    Lmonth[1] = 29;

    /* '<S7>:1:22' days_in_year    = 366; */
    long_eclp_rad = 366.0;
  }

  /* '<S7>:1:25' day_of_year = 0; */
  oblq_rad = 0.0;

  /* '<S7>:1:26' for i = 1:month-1 */
  for (lowAlt = 0; lowAlt < (int16_T)(rtDW.RateTransition1[1] - 1.0); lowAlt++)
  {
    /* '<S7>:1:27' day_of_year = day_of_year + Lmonth(i); */
    oblq_rad += (real_T)Lmonth[lowAlt];
  }

  /*  Add number of days into the month */
  /* '<S7>:1:31' day_of_year = day_of_year + day; */
  oblq_rad += rtDW.RateTransition1[2];

  /*  Add HMS info to the day of year */
  /* '<S7>:1:34' day_of_year    = day_of_year + hour/24 + min/1440 + sec/86400; */
  oblq_rad = ((rtDW.RateTransition1[3] / 24.0 + oblq_rad) +
              rtDW.RateTransition1[4] / 1440.0) + rtDW.RateTransition1[5] /
    86400.0;

  /*  Find the year fraction represented by day_of_year */
  /* '<S7>:1:37' day_frac    = day_of_year/days_in_year; */
  /*  Sum to get total decimal year */
  /* '<S7>:1:40' dec_year = year + day_frac; */
  long_eclp_rad = oblq_rad / long_eclp_rad + rtDW.RateTransition1[0];

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* RelationalOperator: '<S47>/Relational Operator' incorporates:
   *  Memory: '<S47>/otime'
   */
  rtb_RelationalOperator = (long_eclp_rad != rtDW.otime_PreviousInput);

  /* Saturate: '<S9>/+//- 180 deg' */
  if (b_s > 180.0) {
    oblq_rad = 180.0;
  } else if (b_s < -180.0) {
    oblq_rad = -180.0;
  } else {
    oblq_rad = b_s;
  }

  /* End of Saturate: '<S9>/+//- 180 deg' */

  /* Saturate: '<S9>/+//- 90 deg' */
  if (b_c > 90.0) {
    mean_anom_sun_rad = 90.0;
  } else if (b_c < -90.0) {
    mean_anom_sun_rad = -90.0;
  } else {
    mean_anom_sun_rad = b_c;
  }

  /* End of Saturate: '<S9>/+//- 90 deg' */

  /* UnitConversion: '<S91>/Unit Conversion' */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  c_s = 0.017453292519943295 * oblq_rad;
  b_s = 0.017453292519943295 * mean_anom_sun_rad;

  /* Trigonometry: '<S44>/sincos' */
  r = sin(c_s);
  eta = cos(c_s);
  xi = sin(b_s);
  b_o = cos(b_s);

  /* Outputs for Enabled SubSystem: '<S39>/Convert from geodetic to  spherical coordinates ' incorporates:
   *  EnablePort: '<S43>/Enable'
   */
  /* RelationalOperator: '<S46>/Relational Operator' incorporates:
   *  Memory: '<S46>/olon'
   */
  if (oblq_rad != rtDW.olon_PreviousInput) {
    /* Outputs for Iterator SubSystem: '<S43>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S90>/For Iterator'
     */
    for (lowAlt = 1; lowAlt < 12; lowAlt++) {
      /* Switch: '<S90>/cp[m-1] sp[m-1]' incorporates:
       *  Inport: '<S43>/cp[2]'
       *  Inport: '<S43>/sp[2]'
       *  UnitDelay: '<S90>/Unit Delay1'
       */
      if (lowAlt > 1) {
        b_c = rtDW.UnitDelay1_DSTATE[0];
        b_s = rtDW.UnitDelay1_DSTATE[1];
      } else {
        b_c = eta;
        b_s = r;
      }

      /* End of Switch: '<S90>/cp[m-1] sp[m-1]' */

      /* Sum: '<S90>/Sum2' incorporates:
       *  Inport: '<S43>/cp[2]'
       *  Inport: '<S43>/sp[2]'
       *  Product: '<S90>/Product1'
       *  Product: '<S90>/Product2'
       */
      c_s = b_c * r + b_s * eta;

      /* Assignment: '<S90>/Assignment' incorporates:
       *  Assignment: '<S90>/Assignment1'
       *  Constant: '<S90>/Constant'
       *  Constant: '<S90>/Constant1'
       */
      if (lowAlt == 1) {
        memcpy(&rtb_Assignment[0], &rtConstP.pooled11[0], 11U * sizeof(real_T));
        memcpy(&rtb_Assignment1[0], &rtConstP.pooled11[0], 11U * sizeof(real_T));
      }

      rtb_Assignment[lowAlt - 1] = c_s;

      /* End of Assignment: '<S90>/Assignment' */

      /* Sum: '<S90>/Sum1' incorporates:
       *  Inport: '<S43>/cp[2]'
       *  Inport: '<S43>/sp[2]'
       *  Product: '<S90>/Product3'
       *  Product: '<S90>/Product8'
       */
      d_o = b_c * eta - b_s * r;

      /* Assignment: '<S90>/Assignment1' */
      rtb_Assignment1[lowAlt - 1] = d_o;

      /* Update for UnitDelay: '<S90>/Unit Delay1' */
      rtDW.UnitDelay1_DSTATE[0] = d_o;
      rtDW.UnitDelay1_DSTATE[1] = c_s;
    }

    /* End of Outputs for SubSystem: '<S43>/For Iterator Subsystem' */

    /* SignalConversion: '<S43>/OutportBufferForcp[13]' incorporates:
     *  Constant: '<S43>/cp[1]'
     *  Inport: '<S43>/cp[2]'
     */
    rtDW.OutportBufferForcp13[0] = 1.0;
    rtDW.OutportBufferForcp13[1] = eta;

    /* SignalConversion: '<S43>/OutportBufferForsp[13]' incorporates:
     *  Constant: '<S43>/sp[1]'
     *  Inport: '<S43>/sp[2]'
     */
    rtDW.OutportBufferForsp13[0] = 0.0;
    rtDW.OutportBufferForsp13[1] = r;

    /* SignalConversion: '<S43>/OutportBufferForcp[13]' */
    memcpy(&rtDW.OutportBufferForcp13[2], &rtb_Assignment1[0], 11U * sizeof
           (real_T));

    /* SignalConversion: '<S43>/OutportBufferForsp[13]' */
    memcpy(&rtDW.OutportBufferForsp13[2], &rtb_Assignment[0], 11U * sizeof
           (real_T));
  }

  /* End of RelationalOperator: '<S46>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S39>/Convert from geodetic to  spherical coordinates ' */

  /* Trigonometry: '<S12>/sincos' */
  b_s = sin(c);

  /* Product: '<S12>/Product2' */
  b_c = b_s * 0.00669437999014133;

  /* Product: '<S12>/Product3' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/f'
   *  Product: '<S12>/Product1'
   *  Sqrt: '<S12>/sqrt'
   *  Sum: '<S12>/Sum'
   */
  d_o = 6.378137E+6 / sqrt(1.0 - b_c * b_s);

  /* Sum: '<S12>/Sum3' incorporates:
   *  Product: '<S12>/Product4'
   *  Product: '<S12>/Product5'
   *  Product: '<S12>/Product6'
   *  Sum: '<S12>/Sum2'
   *  Trigonometry: '<S12>/sincos'
   */
  d_o = ((b_c * d_o + rtb_sun_vector_eci_km[2]) * b_s - d_o) + cos(c) * c_c;

  /* Saturate: '<S9>/0 to 1,000,000 m' */
  if (d_o > 1.0E+6) {
    d_o = 1.0E+6;
  } else {
    if (d_o < 0.0) {
      d_o = 0.0;
    }
  }

  /* End of Saturate: '<S9>/0 to 1,000,000 m' */

  /* Gain: '<S9>/Gain' */
  r = 0.001 * d_o;

  /* Logic: '<S45>/Logical Operator' incorporates:
   *  Memory: '<S45>/oalt'
   *  Memory: '<S45>/olat'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  RelationalOperator: '<S45>/Relational Operator1'
   */
  rtb_LogicalOperator = ((mean_anom_sun_rad != rtDW.olat_PreviousInput) || (r !=
    rtDW.oalt_PreviousInput));

  /* Product: '<S44>/Product' */
  d_o = xi * xi;

  /* Product: '<S44>/Product1' */
  c_c = b_o * b_o;

  /* Outputs for Enabled SubSystem: '<S39>/Convert from geodetic to  spherical coordinates' incorporates:
   *  EnablePort: '<S42>/Enable'
   */
  if (rtb_LogicalOperator) {
    /* Sqrt: '<S85>/sqrt' incorporates:
     *  Product: '<S85>/Product'
     *  Sum: '<S85>/Sum'
     */
    c = sqrt(4.0680631590768993E+7 - d_o * 272331.60668193549);

    /* Product: '<S42>/Product1' */
    b_s = c * r;

    /* Sqrt: '<S84>/sqrt' incorporates:
     *  Product: '<S84>/Product10'
     *  Product: '<S84>/Product9'
     *  Sum: '<S84>/Sum7'
     */
    b_c = sqrt(c_c * 4.0680631590768993E+7 + 4.0408299984087057E+7 * d_o);

    /* Sqrt: '<S42>/sqrt' incorporates:
     *  Gain: '<S87>/Gain'
     *  Product: '<S87>/Product1'
     *  Product: '<S87>/Product6'
     *  Product: '<S87>/Product7'
     *  Product: '<S87>/Product8'
     *  Sum: '<S87>/Sum5'
     *  Sum: '<S87>/Sum6'
     */
    rtDW.sqrt_m = sqrt((1.6549137866238722E+15 - 2.208307901990225E+13 * d_o) /
                       (c * c) + (2.0 * b_s + r * r));

    /* Product: '<S82>/Product11' incorporates:
     *  Sum: '<S82>/Sum8'
     */
    rtDW.Product11 = (r + b_c) / rtDW.sqrt_m;

    /* Sum: '<S86>/Sum2' */
    c = 4.0680631590768993E+7 + b_s;

    /* Sum: '<S86>/Sum1' */
    b_s += 4.0408299984087057E+7;

    /* Product: '<S83>/Product4' incorporates:
     *  Product: '<S83>/Product3'
     *  Product: '<S86>/Product1'
     *  Product: '<S86>/Product2'
     *  Sqrt: '<S83>/sqrt'
     *  Sum: '<S83>/Sum3'
     */
    rtDW.Product4 = xi / sqrt(c * c / (b_s * b_s) * c_c + d_o);

    /* Product: '<S88>/Product12' incorporates:
     *  Product: '<S88>/Product1'
     */
    rtDW.Product12 = 272331.60668193549 / (rtDW.sqrt_m * b_c) * b_o * xi;

    /* Sqrt: '<S89>/sqrt' incorporates:
     *  Constant: '<S89>/Constant'
     *  Product: '<S89>/Product5'
     *  Sum: '<S89>/Sum4'
     */
    rtDW.sqrt_m1 = sqrt(1.0 - rtDW.Product4 * rtDW.Product4);
  }

  /* End of Outputs for SubSystem: '<S39>/Convert from geodetic to  spherical coordinates' */

  /* Product: '<S39>/aor' incorporates:
   *  Constant: '<S39>/re'
   */
  d_o = 6371.2 / rtDW.sqrt_m;

  /* Product: '<S39>/ar' */
  c_c = d_o * d_o;

  /* Outputs for Iterator SubSystem: '<S39>/Compute magnetic vector in spherical coordinates' incorporates:
   *  ForIterator: '<S41>/For Iterator'
   */
  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay' */
  c = 0.0;

  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay2' */
  xi = 0.0;
  b_o = 0.0;
  eta = 0.0;
  C_1 = 0.0;
  for (lowAlt = 1; lowAlt < 13; lowAlt++) {
    /* Switch: '<S41>/ar(n)' */
    if (!(lowAlt > 1)) {
      c = c_c;
    }

    /* End of Switch: '<S41>/ar(n)' */

    /* Product: '<S41>/Product8' */
    c *= d_o;

    /* Sum: '<S41>/Sum' */
    qY = lowAlt + 1;

    /* Outputs for Iterator SubSystem: '<S41>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S49>/For Iterator'
     */
    if (rtDW.ForIterator_IterationMarker[4] != 0) {
      /* InitializeConditions for UnitDelay: '<S50>/Unit Delay1' */
      rtDW.UnitDelay1_DSTATE_c = 0.0;

      /* InitializeConditions for UnitDelay: '<S50>/Unit Delay3' */
      rtDW.UnitDelay3_DSTATE = 0.0;

      /* InitializeConditions for UnitDelay: '<S50>/Unit Delay2' */
      rtDW.UnitDelay2_DSTATE_n = 0.0;

      /* InitializeConditions for UnitDelay: '<S50>/Unit Delay4' */
      rtDW.UnitDelay4_DSTATE = 0.0;
    }

    for (i = 0; i < 7; i++) {
      rtDW.ForIterator_IterationMarker[i] = 1U;
    }

    /* Sum: '<S41>/Sum' incorporates:
     *  Constant: '<S56>/Constant'
     *  Constant: '<S56>/Constant1'
     *  Logic: '<S56>/Logical Operator'
     *  RelationalOperator: '<S56>/Relational Operator'
     *  RelationalOperator: '<S56>/Relational Operator1'
     *  Sum: '<S49>/Sum1'
     */
    for (s49_iter = 1; s49_iter <= qY; s49_iter++) {
      /* Sum: '<S49>/Sum1' */
      qY_2 = s49_iter - 1;

      /* Outputs for Enabled SubSystem: '<S49>/Time adjust the gauss coefficients' incorporates:
       *  EnablePort: '<S52>/Enable'
       */
      if (rtb_RelationalOperator) {
        /* Outputs for Atomic SubSystem: '<S52>/If Action Subsystem' */
        /* Sum: '<S78>/Sum1' incorporates:
         *  Sum: '<S49>/Sum1'
         */
        i = qY_2 + 1;

        /* Sum: '<S78>/Sum2' */
        qY_1 = lowAlt + 1;

        /* End of Outputs for SubSystem: '<S52>/If Action Subsystem' */

        /* Assignment: '<S52>/Assignment' incorporates:
         *  Constant: '<S39>/epoch'
         *  Constant: '<S52>/c[maxdef][maxdef]'
         *  Constant: '<S52>/cd[maxdef][maxdef]'
         *  Product: '<S78>/Product'
         *  Selector: '<S78>/c[m][n]'
         *  Selector: '<S78>/cd[m][n]'
         *  Sum: '<S39>/Sum'
         *  Sum: '<S78>/Sum'
         *  Sum: '<S78>/Sum1'
         *  Sum: '<S78>/Sum2'
         *  UnitDelay: '<S52>/Unit Delay'
         */
        if (rtDW.ForIterator_IterationMarker[5] < 2) {
          rtDW.ForIterator_IterationMarker[5L] = 2U;
          memcpy(&Assignment[0], &rtDW.UnitDelay_DSTATE_i[0], 169U * sizeof
                 (real_T));
        }

        /* Outputs for Atomic SubSystem: '<S52>/If Action Subsystem' */
        Assignment[(i + 13 * (qY_1 - 1)) - 1] = rtConstP.cdmaxdefmaxdef_Value
          [((qY_1 - 1) * 13 + i) - 1] * (long_eclp_rad - 2015.0) +
          rtConstP.cmaxdefmaxdef_Value[((qY_1 - 1) * 13 + i) - 1];

        /* End of Assignment: '<S52>/Assignment' */
        /* End of Outputs for SubSystem: '<S52>/If Action Subsystem' */

        /* Switch: '<S79>/tc_old' incorporates:
         *  UnitDelay: '<S79>/Unit Delay'
         */
        for (i = 0; i < 169; i++) {
          if (lowAlt > 1) {
            rtb_tc_old[i] = rtDW.UnitDelay_DSTATE_m[i];
          } else {
            rtb_tc_old[i] = 0.0;
          }
        }

        /* End of Switch: '<S79>/tc_old' */

        /* If: '<S79>/If' incorporates:
         *  Sum: '<S49>/Sum1'
         */
        if (qY_2 != 0) {
          /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S80>/Action Port'
           */
          /* Sum: '<S80>/Sum2' */
          i = lowAlt + 1;

          /* Assignment: '<S80>/Assignment2' incorporates:
           *  Constant: '<S39>/epoch'
           *  Constant: '<S52>/c[maxdef][maxdef]'
           *  Constant: '<S52>/cd[maxdef][maxdef]'
           *  Product: '<S80>/Product'
           *  Selector: '<S80>/c[m][n]'
           *  Selector: '<S80>/cd[m][n]'
           *  Sum: '<S39>/Sum'
           *  Sum: '<S80>/Sum'
           *  Sum: '<S80>/Sum2'
           */
          if (rtDW.ForIterator_IterationMarker[6] < 2) {
            rtDW.ForIterator_IterationMarker[6L] = 2U;
            memcpy(&Assignment2[0], &rtb_tc_old[0], 169U * sizeof(real_T));
          }

          Assignment2[(i + 13 * (qY_2 - 1)) - 1] =
            rtConstP.cdmaxdefmaxdef_Value[((qY_2 - 1) * 13 + i) - 1] *
            (long_eclp_rad - 2015.0) + rtConstP.cmaxdefmaxdef_Value[((qY_2 - 1) *
            13 + i) - 1];

          /* End of Assignment: '<S80>/Assignment2' */

          /* Gain: '<S80>/Gain' */
          memcpy(&rtb_tc_old[0], &Assignment2[0], 169U * sizeof(real_T));

          /* End of Outputs for SubSystem: '<S79>/If Action Subsystem1' */
        }

        /* End of If: '<S79>/If' */
        for (i = 0; i < 169; i++) {
          /* Sum: '<S52>/Sum2' */
          rtDW.Sum2_i[i] = Assignment[i] + rtb_tc_old[i];

          /* Update for UnitDelay: '<S52>/Unit Delay' */
          rtDW.UnitDelay_DSTATE_i[i] = Assignment[i];

          /* Update for UnitDelay: '<S79>/Unit Delay' */
          rtDW.UnitDelay_DSTATE_m[i] = rtb_tc_old[i];
        }
      }

      /* End of Outputs for SubSystem: '<S49>/Time adjust the gauss coefficients' */

      /* If: '<S55>/If' incorporates:
       *  Sum: '<S49>/Sum1'
       */
      if (qY_2 == 0) {
        /* Outputs for IfAction SubSystem: '<S55>/If Action Subsystem' incorporates:
         *  ActionPort: '<S61>/Action Port'
         */
        /* Gain: '<S61>/Gain1' incorporates:
         *  Constant: '<S55>/Constant1'
         *  Constant: '<S61>/Constant'
         *  Product: '<S61>/Product'
         *  Selector: '<S55>/cp[m+1]'
         *  Selector: '<S61>/Selector'
         *  Sum: '<S55>/Sum4'
         *  Sum: '<S61>/Sum'
         */
        b_s = rtDW.Sum2_i[((lowAlt + 1) - 1) * 13] * rtDW.OutportBufferForcp13
          [(qY_2 + 1) - 1];

        /* Gain: '<S61>/Gain2' incorporates:
         *  Constant: '<S55>/Constant1'
         *  Constant: '<S61>/Constant'
         *  Product: '<S61>/Product'
         *  Selector: '<S55>/sp[m+1]'
         *  Selector: '<S61>/Selector'
         *  Sum: '<S55>/Sum4'
         *  Sum: '<S61>/Sum'
         */
        b_c = rtDW.Sum2_i[((lowAlt + 1) - 1) * 13] * rtDW.OutportBufferForsp13
          [(qY_2 + 1) - 1];

        /* End of Outputs for SubSystem: '<S55>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S55>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S62>/Action Port'
         */
        /* Sum: '<S62>/Sum' incorporates:
         *  Constant: '<S55>/Constant1'
         *  Constant: '<S63>/Constant'
         *  Product: '<S62>/Product'
         *  Product: '<S62>/Product1'
         *  Selector: '<S55>/cp[m+1]'
         *  Selector: '<S55>/sp[m+1]'
         *  Selector: '<S62>/Selector'
         *  Selector: '<S62>/Selector1'
         *  Sum: '<S55>/Sum4'
         *  Sum: '<S63>/Sum'
         */
        b_s = rtDW.Sum2_i[(((lowAlt + 1) - 1) * 13 + (qY_2 + 1)) - 1] *
          rtDW.OutportBufferForcp13[(qY_2 + 1) - 1] + rtDW.Sum2_i[(qY_2 - 1) *
          13 + lowAlt] * rtDW.OutportBufferForsp13[(qY_2 + 1) - 1];

        /* Sum: '<S62>/Sum1' incorporates:
         *  Constant: '<S55>/Constant1'
         *  Constant: '<S63>/Constant'
         *  Product: '<S62>/Product'
         *  Product: '<S62>/Product1'
         *  Selector: '<S55>/cp[m+1]'
         *  Selector: '<S55>/sp[m+1]'
         *  Selector: '<S62>/Selector'
         *  Selector: '<S62>/Selector1'
         *  Sum: '<S55>/Sum4'
         *  Sum: '<S63>/Sum'
         */
        b_c = rtDW.Sum2_i[(((lowAlt + 1) - 1) * 13 + (qY_2 + 1)) - 1] *
          rtDW.OutportBufferForsp13[(qY_2 + 1) - 1] - rtDW.Sum2_i[(qY_2 - 1) *
          13 + lowAlt] * rtDW.OutportBufferForcp13[(qY_2 + 1) - 1];

        /* End of Outputs for SubSystem: '<S55>/If Action Subsystem1' */
      }

      /* End of If: '<S55>/If' */

      /* Outputs for Enabled SubSystem: '<S49>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' incorporates:
       *  EnablePort: '<S51>/Enable'
       */
      if (rtb_LogicalOperator) {
        /* If: '<S51>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' incorporates:
         *  Sum: '<S49>/Sum1'
         */
        if (lowAlt == qY_2) {
          /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem' incorporates:
           *  ActionPort: '<S65>/Action Port'
           */
          /* Gain: '<S69>/Gain' incorporates:
           *  Sum: '<S69>/Sum2'
           */
          rtb_Sum1_m = mul_s32_sat(13L, qY_2 - 1);

          /* Selector: '<S65>/Selector' incorporates:
           *  Sum: '<S69>/Sum1'
           */
          if (rtb_Sum1_m > MAX_int32_T - lowAlt) {
            rtb_Sum1_a = MAX_int32_T;
            rtb_Sum1_m = MAX_int32_T;
          } else {
            rtb_Sum1_a = lowAlt + rtb_Sum1_m;
            rtb_Sum1_m += lowAlt;
          }

          /* Product: '<S65>/Product1' incorporates:
           *  Selector: '<S65>/Selector'
           *  UnitDelay: '<S51>/Unit Delay1'
           */
          rtDW.Merge_c = rtDW.UnitDelay1_DSTATE_i[(int16_T)rtb_Sum1_a - 1] *
            rtDW.sqrt_m1;

          /* Sum: '<S65>/Sum' incorporates:
           *  Product: '<S65>/Product'
           *  Product: '<S65>/Product2'
           *  Selector: '<S65>/Selector'
           *  Selector: '<S65>/Selector1'
           *  UnitDelay: '<S51>/Unit Delay'
           *  UnitDelay: '<S51>/Unit Delay1'
           */
          rtDW.Merge1_c = rtDW.UnitDelay_DSTATE_c[((lowAlt - 1) * 13 + qY_2) - 1]
            * rtDW.sqrt_m1 + rtDW.UnitDelay1_DSTATE_i[(int16_T)rtb_Sum1_m - 1] *
            rtDW.Product4;

          /* End of Outputs for SubSystem: '<S51>/If Action Subsystem' */
        } else if ((lowAlt == 1) && (qY_2 == 0)) {
          /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S66>/Action Port'
           */
          /* Selector: '<S66>/Selector' incorporates:
           *  Gain: '<S71>/Gain'
           *  Sum: '<S71>/Sum1'
           */
          rtb_Sum1_m = mul_s32_sat(13L, 0L);
          if (rtb_Sum1_m > 2147483646L) {
            rtb_Sum1_m = MAX_int32_T;
          } else {
            rtb_Sum1_m++;
          }

          /* Product: '<S66>/Product3' incorporates:
           *  Selector: '<S66>/Selector'
           *  UnitDelay: '<S51>/Unit Delay1'
           */
          rtDW.Merge_c = rtDW.UnitDelay1_DSTATE_i[(int16_T)rtb_Sum1_m - 1] *
            rtDW.Product4;

          /* Selector: '<S66>/Selector' incorporates:
           *  Gain: '<S71>/Gain'
           *  Sum: '<S71>/Sum1'
           */
          rtb_Sum1_m = mul_s32_sat(13L, 0L);
          if (rtb_Sum1_m > 2147483646L) {
            rtb_Sum1_m = MAX_int32_T;
          } else {
            rtb_Sum1_m++;
          }

          /* Sum: '<S66>/Sum' incorporates:
           *  Product: '<S66>/Product'
           *  Product: '<S66>/Product2'
           *  Selector: '<S66>/Selector'
           *  Selector: '<S66>/Selector1'
           *  UnitDelay: '<S51>/Unit Delay'
           *  UnitDelay: '<S51>/Unit Delay1'
           */
          rtDW.Merge1_c = rtDW.Product4 * rtDW.UnitDelay_DSTATE_c[0] -
            rtDW.UnitDelay1_DSTATE_i[(int16_T)rtb_Sum1_m - 1] * rtDW.sqrt_m1;

          /* End of Outputs for SubSystem: '<S51>/If Action Subsystem1' */
        } else {
          if ((lowAlt > 1) && (lowAlt != qY_2)) {
            /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S67>/Action Port'
             */
            /* Sum: '<S75>/Sum' */
            i = qY_2 + 1;

            /* Sum: '<S74>/Sum' */
            qY_1 = lowAlt + 1;
            qY_0 = qY_2 + 1;

            /* Gain: '<S73>/Gain' */
            rtb_Sum1_m = mul_s32_sat(13L, qY_2);

            /* Selector: '<S67>/Selector' incorporates:
             *  Sum: '<S73>/Sum1'
             */
            if (rtb_Sum1_m > MAX_int32_T - lowAlt) {
              rtb_Sum1_a = MAX_int32_T;
            } else {
              rtb_Sum1_a = lowAlt + rtb_Sum1_m;
            }

            /* Switch: '<S67>/Switch' incorporates:
             *  Constant: '<S67>/Constant'
             *  DataTypeConversion: '<S76>/Data Type Conversion'
             *  RelationalOperator: '<S76>/Relational Operator'
             *  Selector: '<S67>/Selector1'
             *  Sum: '<S75>/Sum'
             *  Sum: '<S76>/Sum2'
             *  UnitDelay: '<S51>/Unit Delay'
             */
            if ((lowAlt - 2 >= qY_2) > 0.5) {
              rtb_Sum1_j_idx_3 = rtDW.UnitDelay_DSTATE_c[((lowAlt - 2) * 13 + i)
                - 1];
            } else {
              rtb_Sum1_j_idx_3 = 0.0;
            }

            /* End of Switch: '<S67>/Switch' */

            /* Sum: '<S67>/Sum' incorporates:
             *  Constant: '<S67>/k[13][13]'
             *  Product: '<S67>/Product'
             *  Product: '<S67>/Product1'
             *  Product: '<S67>/Product4'
             *  Selector: '<S67>/Selector'
             *  Selector: '<S67>/Selector1'
             *  Selector: '<S67>/Selector2'
             *  Sum: '<S74>/Sum'
             *  Sum: '<S75>/Sum'
             *  UnitDelay: '<S51>/Unit Delay'
             *  UnitDelay: '<S51>/Unit Delay1'
             */
            rtDW.Merge1_c = (rtDW.UnitDelay_DSTATE_c[((lowAlt - 1) * 13 + i) - 1]
                             * rtDW.Product4 - rtDW.UnitDelay1_DSTATE_i[(int16_T)
                             rtb_Sum1_a - 1] * rtDW.sqrt_m1) - rtConstP.pooled5
              [((qY_1 - 1) * 13 + qY_0) - 1] * rtb_Sum1_j_idx_3;

            /* Switch: '<S67>/Switch1' incorporates:
             *  Constant: '<S67>/Constant1'
             *  DataTypeConversion: '<S77>/Data Type Conversion'
             *  RelationalOperator: '<S77>/Relational Operator'
             *  Selector: '<S67>/Selector'
             *  Sum: '<S77>/Sum2'
             *  UnitDelay: '<S51>/Unit Delay1'
             */
            if ((lowAlt - 2 >= qY_2) > 0.5) {
              /* Selector: '<S67>/Selector' incorporates:
               *  Sum: '<S73>/Sum1'
               *  Sum: '<S73>/Sum2'
               */
              i = lowAlt - 1;
              if (rtb_Sum1_m > MAX_int32_T - i) {
                rtb_Sum1_a = MAX_int32_T;
              } else {
                rtb_Sum1_a = i + rtb_Sum1_m;
              }

              rtb_Sum1_j_idx_3 = rtDW.UnitDelay1_DSTATE_i[(int16_T)rtb_Sum1_a -
                1];
            } else {
              rtb_Sum1_j_idx_3 = 0.0;
            }

            /* End of Switch: '<S67>/Switch1' */

            /* Selector: '<S67>/Selector' incorporates:
             *  Sum: '<S73>/Sum1'
             */
            if (rtb_Sum1_m > MAX_int32_T - lowAlt) {
              rtb_Sum1_m = MAX_int32_T;
            } else {
              rtb_Sum1_m += lowAlt;
            }

            /* Sum: '<S67>/Sum1' incorporates:
             *  Constant: '<S67>/k[13][13]'
             *  Product: '<S67>/Product2'
             *  Product: '<S67>/Product3'
             *  Selector: '<S67>/Selector'
             *  Selector: '<S67>/Selector2'
             *  Sum: '<S74>/Sum'
             *  UnitDelay: '<S51>/Unit Delay1'
             */
            rtDW.Merge_c = rtDW.UnitDelay1_DSTATE_i[(int16_T)rtb_Sum1_m - 1] *
              rtDW.Product4 - rtConstP.pooled5[((qY_1 - 1) * 13 + qY_0) - 1] *
              rtb_Sum1_j_idx_3;

            /* End of Outputs for SubSystem: '<S51>/If Action Subsystem2' */
          }
        }

        /* End of If: '<S51>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' */

        /* Sum: '<S51>/Sum' incorporates:
         *  Sum: '<S49>/Sum1'
         */
        i = lowAlt + 1;
        qY_1 = qY_2 + 1;

        /* Assignment: '<S51>/Assignment' incorporates:
         *  Sum: '<S51>/Sum'
         *  UnitDelay: '<S51>/Unit Delay'
         */
        if (rtDW.ForIterator_IterationMarker[2] < 2) {
          rtDW.ForIterator_IterationMarker[2L] = 2U;
          memcpy(&rtDW.Assignment_p[0], &rtDW.UnitDelay_DSTATE_c[0], 169U *
                 sizeof(real_T));
        }

        rtDW.Assignment_p[(qY_1 + 13 * (i - 1)) - 1] = rtDW.Merge1_c;

        /* End of Assignment: '<S51>/Assignment' */

        /* Assignment: '<S51>/Assignment_snorm' incorporates:
         *  Gain: '<S68>/Gain'
         *  Sum: '<S51>/Sum'
         *  Sum: '<S68>/Sum1'
         *  Sum: '<S68>/Sum2'
         *  UnitDelay: '<S51>/Unit Delay1'
         */
        if (rtDW.ForIterator_IterationMarker[3] < 2) {
          rtDW.ForIterator_IterationMarker[3L] = 2U;
          memcpy(&rtDW.Assignment_snorm[0], &rtDW.UnitDelay1_DSTATE_i[0], 169U *
                 sizeof(real_T));
        }

        rtDW.Assignment_snorm[(int16_T)((real_T)i + (real_T)mul_s32_sat(13L,
          qY_1 - 1)) - 1] = rtDW.Merge_c;

        /* End of Assignment: '<S51>/Assignment_snorm' */

        /* Update for UnitDelay: '<S51>/Unit Delay' */
        memcpy(&rtDW.UnitDelay_DSTATE_c[0], &rtDW.Assignment_p[0], 169U * sizeof
               (real_T));

        /* Update for UnitDelay: '<S51>/Unit Delay1' */
        memcpy(&rtDW.UnitDelay1_DSTATE_i[0], &rtDW.Assignment_snorm[0], 169U *
               sizeof(real_T));
      }

      /* End of Outputs for SubSystem: '<S49>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

      /* Selector: '<S50>/snorm[n+m*13]' incorporates:
       *  Gain: '<S54>/Gain'
       *  Sum: '<S49>/Sum1'
       *  Sum: '<S54>/Sum1'
       */
      i = 1 + lowAlt;
      rtb_Sum1_m = mul_s32_sat(13L, qY_2);
      if (rtb_Sum1_m > MAX_int32_T - i) {
        rtb_Sum1_m = MAX_int32_T;
      } else {
        rtb_Sum1_m += i;
      }

      /* Product: '<S50>/par' incorporates:
       *  Selector: '<S50>/snorm[n+m*13]'
       */
      c_s = rtDW.Assignment_snorm[(int16_T)rtb_Sum1_m - 1] * c;

      /* Outputs for Enabled SubSystem: '<S50>/Special case - North//South Geographic Pole' incorporates:
       *  EnablePort: '<S53>/Enable'
       */
      if ((rtDW.sqrt_m1 == 0.0) && (1 == qY_2)) {
        if (!rtDW.SpecialcaseNorthSouthGeographic) {
          rtDW.SpecialcaseNorthSouthGeographic = true;
        }

        /* If: '<S53>/n ==1' incorporates:
         *  Assignment: '<S58>/Assignment2'
         */
        if (lowAlt == 1) {
          /* Outputs for IfAction SubSystem: '<S53>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S57>/Action Port'
           */
          /* Assignment: '<S57>/Assignment2' incorporates:
           *  Selector: '<S57>/pp[n-1]'
           *  UnitDelay: '<S53>/Unit Delay1'
           */
          if (rtDW.ForIterator_IterationMarker[0] < 2) {
            rtDW.ForIterator_IterationMarker[0L] = 2U;
            memcpy(&rtDW.Assignment2_e[0], &rtDW.UnitDelay1_DSTATE_d[0], 13U *
                   sizeof(real_T));
          }

          rtDW.Assignment2_e[1] = rtDW.UnitDelay1_DSTATE_d[0];

          /* End of Assignment: '<S57>/Assignment2' */
          /* End of Outputs for SubSystem: '<S53>/If Action Subsystem1' */
        } else {
          /* Outputs for IfAction SubSystem: '<S53>/If Action Subsystem2' incorporates:
           *  ActionPort: '<S58>/Action Port'
           */
          if (rtDW.ForIterator_IterationMarker[1] < 2) {
            /* Assignment: '<S58>/Assignment2' incorporates:
             *  UnitDelay: '<S53>/Unit Delay1'
             */
            rtDW.ForIterator_IterationMarker[1L] = 2U;
            memcpy(&rtDW.Assignment2_g[0], &rtDW.UnitDelay1_DSTATE_d[0], 13U *
                   sizeof(real_T));
          }

          /* Assignment: '<S58>/Assignment2' incorporates:
           *  Constant: '<S58>/k[13][13]'
           *  Product: '<S58>/Product1'
           *  Product: '<S58>/Product2'
           *  Selector: '<S58>/Selector2'
           *  Selector: '<S58>/pp[n-2] pp[n-1]'
           *  Sum: '<S58>/Sum1'
           *  UnitDelay: '<S53>/Unit Delay1'
           */
          rtDW.Assignment2_g[lowAlt] = rtDW.UnitDelay1_DSTATE_d[lowAlt - 1] *
            rtDW.Product4 - rtConstP.pooled5[lowAlt * 13 + 1] *
            rtDW.UnitDelay1_DSTATE_d[lowAlt - 2];

          /* End of Outputs for SubSystem: '<S53>/If Action Subsystem2' */
        }

        /* End of If: '<S53>/n ==1' */

        /* SignalConversion: '<S53>/TmpSignal ConversionAtpp[n]Inport1' incorporates:
         *  UnitDelay: '<S53>/Unit Delay1'
         */
        rtb_TmpSignalConversionAtppnInp[0] = rtDW.UnitDelay1_DSTATE_d[0];
        rtb_TmpSignalConversionAtppnInp[1] = rtDW.Assignment2_e[1];
        memcpy(&rtb_TmpSignalConversionAtppnInp[2], &rtDW.Assignment2_g[2], 11U *
               sizeof(real_T));

        /* Product: '<S53>/Product2' incorporates:
         *  Selector: '<S53>/pp[n]'
         */
        rtDW.Product2 = c * rtb_TmpSignalConversionAtppnInp[lowAlt] * b_c;

        /* Update for UnitDelay: '<S53>/Unit Delay1' */
        memcpy(&rtDW.UnitDelay1_DSTATE_d[0], &rtb_TmpSignalConversionAtppnInp[0],
               13U * sizeof(real_T));
      } else {
        if (rtDW.SpecialcaseNorthSouthGeographic) {
          /* Disable for Outport: '<S53>/bpp' */
          rtDW.Product2 = 0.0;
          rtDW.SpecialcaseNorthSouthGeographic = false;
        }
      }

      /* End of Outputs for SubSystem: '<S50>/Special case - North//South Geographic Pole' */

      /* Sum: '<S50>/Sum1' incorporates:
       *  Constant: '<S56>/Constant'
       *  Constant: '<S56>/Constant1'
       *  Logic: '<S56>/Logical Operator'
       *  Product: '<S50>/Product'
       *  RelationalOperator: '<S56>/Relational Operator'
       *  RelationalOperator: '<S56>/Relational Operator1'
       *  Selector: '<S50>/dp[n][m]'
       *  Sum: '<S49>/Sum1'
       *  UnitDelay: '<S50>/Unit Delay1'
       */
      rtDW.Sum1 = rtDW.UnitDelay1_DSTATE_c - rtDW.Assignment_p[lowAlt * 13 +
        qY_2] * b_s * c;

      /* Sum: '<S50>/Sum2' incorporates:
       *  Constant: '<S50>/fm'
       *  Product: '<S50>/Product1'
       *  Selector: '<S50>/fm[m]'
       *  Sum: '<S49>/Sum1'
       *  UnitDelay: '<S50>/Unit Delay3'
       */
      rtDW.Sum2 = rtConstP.fm_Value[qY_2] * c_s * b_c + rtDW.UnitDelay3_DSTATE;

      /* Sum: '<S50>/Sum3' incorporates:
       *  Constant: '<S50>/fn'
       *  Product: '<S50>/Product2'
       *  Selector: '<S50>/fn[m]'
       *  UnitDelay: '<S50>/Unit Delay2'
       */
      rtDW.Sum3 = rtConstP.fn_Value[lowAlt] * c_s * b_s +
        rtDW.UnitDelay2_DSTATE_n;

      /* Sum: '<S50>/Sum5' incorporates:
       *  UnitDelay: '<S50>/Unit Delay4'
       */
      rtDW.Sum5 = rtDW.UnitDelay4_DSTATE + rtDW.Product2;

      /* Update for UnitDelay: '<S50>/Unit Delay1' */
      rtDW.UnitDelay1_DSTATE_c = rtDW.Sum1;

      /* Update for UnitDelay: '<S50>/Unit Delay3' */
      rtDW.UnitDelay3_DSTATE = rtDW.Sum2;

      /* Update for UnitDelay: '<S50>/Unit Delay2' */
      rtDW.UnitDelay2_DSTATE_n = rtDW.Sum3;

      /* Update for UnitDelay: '<S50>/Unit Delay4' */
      rtDW.UnitDelay4_DSTATE = rtDW.Sum5;
    }

    /* End of Outputs for SubSystem: '<S41>/For Iterator Subsystem' */

    /* Sum: '<S41>/Sum1' incorporates:
     *  UnitDelay: '<S41>/Unit Delay2'
     */
    rtb_Sum1_j_idx_0 = xi + rtDW.Sum1;
    rtb_Sum1_j_idx_1 = b_o + rtDW.Sum2;
    rtb_Sum1_j_idx_2 = eta + rtDW.Sum3;
    rtb_Sum1_j_idx_3 = C_1 + rtDW.Sum5;

    /* Update for UnitDelay: '<S41>/Unit Delay2' */
    xi = rtb_Sum1_j_idx_0;
    b_o = rtb_Sum1_j_idx_1;
    eta = rtb_Sum1_j_idx_2;
    C_1 = rtb_Sum1_j_idx_3;
  }

  /* End of Outputs for SubSystem: '<S39>/Compute magnetic vector in spherical coordinates' */

  /* Switch: '<S93>/Switch' incorporates:
   *  Product: '<S93>/Product'
   */
  if (rtDW.sqrt_m1 != 0.0) {
    d_o = rtb_Sum1_j_idx_1 / rtDW.sqrt_m1;
  } else {
    d_o = rtb_Sum1_j_idx_3;
  }

  /* End of Switch: '<S93>/Switch' */

  /* Sum: '<S92>/Sum1' incorporates:
   *  Product: '<S92>/Product1'
   *  Product: '<S92>/Product4'
   */
  b_c = (0.0 - rtDW.Product11 * rtb_Sum1_j_idx_0) - rtb_Sum1_j_idx_2 *
    rtDW.Product12;

  /* UnitConversion: '<S97>/Unit Conversion' incorporates:
   *  Trigonometry: '<S95>/Trigonometric Function1'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  b_s = 57.295779513082323 * rt_atan2d_snf(d_o, b_c);

  /* Sum: '<S94>/Sum1' incorporates:
   *  Product: '<S94>/Product1'
   *  Product: '<S94>/Product4'
   */
  c_c = rtDW.Product12 * rtb_Sum1_j_idx_0 - rtb_Sum1_j_idx_2 * rtDW.Product11;

  /* Sum: '<S95>/Sum' incorporates:
   *  Product: '<S95>/Product'
   *  Product: '<S95>/Product1'
   */
  d_o = d_o * d_o + b_c * b_c;

  /* UnitConversion: '<S40>/Unit Conversion' incorporates:
   *  Sqrt: '<S95>/sqrt1'
   *  Trigonometry: '<S95>/Trigonometric Function'
   *  UnitConversion: '<S96>/Unit Conversion'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  /* Unit Conversion - from: deg to: rad
     Expression: output = (0.0174533*input) + (0) */
  c_s = 0.017453292519943295 * b_s;
  b_s = 57.295779513082323 * rt_atan2d_snf(c_c, sqrt(d_o)) *
    0.017453292519943295;

  /* Trigonometry: '<S34>/sincos' */
  xi = cos(c_s);
  c_s = sin(c_s);

  /* Sum: '<S95>/Sum1' incorporates:
   *  Product: '<S95>/Product2'
   */
  d_o += c_c * c_c;

  /* Sqrt: '<S95>/sqrt' */
  d_o = sqrt(d_o);

  /* Product: '<S34>/h1' incorporates:
   *  Trigonometry: '<S34>/sincos'
   */
  c_c = cos(b_s) * d_o;

  /* Product: '<S34>/x1' */
  b_c = xi * c_c;

  /* Product: '<S34>/y1' */
  c_c *= c_s;

  /* Product: '<S34>/z1' incorporates:
   *  Trigonometry: '<S34>/sincos'
   */
  d_o *= sin(b_s);

  /* Gain: '<S2>/nT2T' */
  rtb_Sum1_j_idx_3 = 1.0E-9 * b_c;
  c_c *= 1.0E-9;
  rtb_Sum1_j_idx_1 = 1.0E-9 * d_o;

  /* Product: '<S2>/Matrix Multiply1' incorporates:
   *  Math: '<S2>/Math Function'
   *  Product: '<S2>/Matrix Multiply2'
   */
  for (lowAlt = 0; lowAlt < 3; lowAlt++) {
    rtb_sun_vector_eci_km_0[lowAlt] = rtb_VectorConcatenate[3 * lowAlt + 2] *
      rtb_Sum1_j_idx_1 + (rtb_VectorConcatenate[3 * lowAlt + 1] * c_c +
                          rtb_VectorConcatenate[3 * lowAlt] * rtb_Sum1_j_idx_3);
  }

  /* End of Product: '<S2>/Matrix Multiply1' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S2>/Matrix Multiply2' */
    c_c = rtDW.RateTransition2[i + 6] * rtb_sun_vector_eci_km_0[2] +
      (rtDW.RateTransition2[i + 3] * rtb_sun_vector_eci_km_0[1] +
       rtDW.RateTransition2[i] * rtb_sun_vector_eci_km_0[0]);

    /* Math: '<S8>/Math Function' */
    rtb_sun_vector_eci_km[i] = c_c * c_c;

    /* Product: '<S2>/Matrix Multiply2' */
    rtb_Gain[i] = c_c;
  }

  /* Sum: '<S8>/Sum of Elements' */
  c_c = (rtb_sun_vector_eci_km[0] + rtb_sun_vector_eci_km[1]) +
    rtb_sun_vector_eci_km[2];

  /* Math: '<S8>/Math Function1'
   *
   * About '<S8>/Math Function1':
   *  Operator: sqrt
   */
  if (c_c < 0.0) {
    c_c = -sqrt(fabs(c_c));
  } else {
    c_c = sqrt(c_c);
  }

  /* End of Math: '<S8>/Math Function1' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant'
   *  Product: '<S8>/Product'
   */
  if (c_c > 0.0) {
    xi = rtb_Gain[0];
    b_o = rtb_Gain[1];
    eta = rtb_Gain[2];
    C_1 = c_c;
  } else {
    xi = rtb_Gain[0] * 0.0;
    b_o = rtb_Gain[1] * 0.0;
    eta = rtb_Gain[2] * 0.0;
    C_1 = 1.0;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Outport: '<Root>/mag_unit_vector_eci' incorporates:
   *  Product: '<S8>/Divide'
   */
  rtY.mag_unit_vector_eci[0] = xi / C_1;

  /* Outport: '<Root>/mag_vector_eci' */
  rtY.mag_vector_eci[0] = rtb_Gain[0];

  /* Outport: '<Root>/mag_unit_vector_eci' incorporates:
   *  Product: '<S8>/Divide'
   */
  rtY.mag_unit_vector_eci[1] = b_o / C_1;

  /* Outport: '<Root>/mag_vector_eci' */
  rtY.mag_vector_eci[1] = rtb_Gain[1];

  /* Outport: '<Root>/mag_unit_vector_eci' incorporates:
   *  Product: '<S8>/Divide'
   */
  rtY.mag_unit_vector_eci[2] = eta / C_1;

  /* Outport: '<Root>/mag_vector_eci' */
  rtY.mag_vector_eci[2] = rtb_Gain[2];

  /* Update for Memory: '<S47>/otime' */
  rtDW.otime_PreviousInput = long_eclp_rad;

  /* Update for Memory: '<S46>/olon' */
  rtDW.olon_PreviousInput = oblq_rad;

  /* Update for Memory: '<S45>/olat' */
  rtDW.olat_PreviousInput = mean_anom_sun_rad;

  /* Update for Memory: '<S45>/oalt' */
  rtDW.oalt_PreviousInput = r;
}

/* Model step function for TID1 */
void estimate_eci_vectors_step1(void)  /* Sample time: [1.0s, 0.0s] */
{
  int16_T i;

  /* Update for RateTransition: '<S1>/Rate Transition4' incorporates:
   *  Update for Inport: '<Root>/Inport1'
   */
  rtDW.RateTransition4_Buffer0 = rtU.JD_ut1_J2000_century;

  /* Update for RateTransition: '<S1>/Rate Transition7' incorporates:
   *  Update for Inport: '<Root>/Inport5'
   */
  memcpy(&rtDW.RateTransition7_Buffer0[0], &rtU.teme_to_gcrf[0], 9U * sizeof
         (real_T));

  /* Update for RateTransition: '<S1>/Rate Transition3' incorporates:
   *  Update for Inport: '<Root>/Inport4'
   */
  rtDW.RateTransition3_Buffer0 = rtU.JD_ut1_J2000_days;

  /* Update for RateTransition: '<S1>/Rate Transition2' incorporates:
   *  Update for Inport: '<Root>/Inport2'
   */
  memcpy(&rtDW.RateTransition2_Buffer0[0], &rtU.itrf_to_gcrf[0], 9U * sizeof
         (real_T));

  /* Update for RateTransition: '<S1>/Rate Transition5' incorporates:
   *  Update for Inport: '<Root>/Inport2'
   */
  memcpy(&rtDW.RateTransition5_Buffer0[0], &rtU.itrf_to_gcrf[0], 9U * sizeof
         (real_T));

  /* Update for RateTransition: '<S1>/Rate Transition1' incorporates:
   *  Update for Inport: '<Root>/Inport3'
   */
  for (i = 0; i < 6; i++) {
    rtDW.RateTransition1_Buffer0[i] = rtU.time_vec_ut1[i];
  }

  /* End of Update for RateTransition: '<S1>/Rate Transition1' */
}

/* Model initialize function */
void estimate_eci_vectors_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int16_T i;

    /* InitializeConditions for Memory: '<S47>/otime' */
    rtDW.otime_PreviousInput = -1000.0;

    /* InitializeConditions for Memory: '<S46>/olon' */
    rtDW.olon_PreviousInput = -1000.0;

    /* InitializeConditions for Memory: '<S45>/olat' */
    rtDW.olat_PreviousInput = -1000.0;

    /* InitializeConditions for Memory: '<S45>/oalt' */
    rtDW.oalt_PreviousInput = -1000.0;

    /* SystemInitialize for Enabled SubSystem: '<S39>/Convert from geodetic to  spherical coordinates ' */
    /* SystemInitialize for Outport: '<S43>/sp[13]' */
    memcpy(&rtDW.OutportBufferForsp13[0], &rtConstP.sp13_Y0[0], 13U * sizeof
           (real_T));

    /* SystemInitialize for Outport: '<S43>/cp[13]' */
    memcpy(&rtDW.OutportBufferForcp13[0], &rtConstP.cp13_Y0[0], 13U * sizeof
           (real_T));

    /* End of SystemInitialize for SubSystem: '<S39>/Convert from geodetic to  spherical coordinates ' */

    /* SystemInitialize for Enabled SubSystem: '<S39>/Convert from geodetic to  spherical coordinates' */
    /* SystemInitialize for Outport: '<S42>/r' */
    rtDW.sqrt_m = 6378.137;

    /* SystemInitialize for Outport: '<S42>/ct' */
    rtDW.Product4 = 1.0;

    /* End of SystemInitialize for SubSystem: '<S39>/Convert from geodetic to  spherical coordinates' */

    /* SystemInitialize for Iterator SubSystem: '<S39>/Compute magnetic vector in spherical coordinates' */
    /* SystemInitialize for Iterator SubSystem: '<S41>/For Iterator Subsystem' */
    /* SystemInitialize for Enabled SubSystem: '<S49>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */
    /* InitializeConditions for UnitDelay: '<S51>/Unit Delay1' */
    memcpy(&rtDW.UnitDelay1_DSTATE_i[0], &rtConstP.pooled8[0], 169U * sizeof
           (real_T));

    /* SystemInitialize for Outport: '<S51>/snorm[169]' */
    memcpy(&rtDW.Assignment_snorm[0], &rtConstP.pooled8[0], 169U * sizeof(real_T));

    /* End of SystemInitialize for SubSystem: '<S49>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

    /* SystemInitialize for Enabled SubSystem: '<S50>/Special case - North//South Geographic Pole' */
    /* SystemInitialize for IfAction SubSystem: '<S53>/If Action Subsystem2' */
    /* SystemInitialize for IfAction SubSystem: '<S53>/If Action Subsystem1' */
    for (i = 0; i < 13; i++) {
      /* InitializeConditions for UnitDelay: '<S53>/Unit Delay1' */
      rtDW.UnitDelay1_DSTATE_d[i] = 1.0;

      /* SystemInitialize for Outport: '<S57>/pp[13]' */
      rtDW.Assignment2_e[i] = 1.0;

      /* SystemInitialize for Outport: '<S58>/pp[13]' */
      rtDW.Assignment2_g[i] = 1.0;
    }

    /* End of SystemInitialize for SubSystem: '<S53>/If Action Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<S53>/If Action Subsystem2' */
    /* End of SystemInitialize for SubSystem: '<S50>/Special case - North//South Geographic Pole' */
    /* End of SystemInitialize for SubSystem: '<S41>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S39>/Compute magnetic vector in spherical coordinates' */
  }
}

/* Model terminate function */
void estimate_eci_vectors_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
