/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mag_vector.h
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

#ifndef RTW_HEADER_mag_vector_h_
#define RTW_HEADER_mag_vector_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef mag_vector_COMMON_INCLUDES_
# define mag_vector_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* mag_vector_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T OutportBufferForcp13[13];
  real_T OutportBufferForsp13[13];
  real_T Sum2_b[169];                  /* '<S49>/Sum2' */
  real_T Assignment_h[169];            /* '<S48>/Assignment' */
  real_T Assignment_snorm[169];        /* '<S48>/Assignment_snorm' */
  real_T Assignment2_a[13];            /* '<S55>/Assignment2' */
  real_T Assignment2_e[13];            /* '<S54>/Assignment2' */
  real_T UnitDelay1_DSTATE[2];         /* '<S87>/Unit Delay1' */
  real_T UnitDelay_DSTATE_m[169];      /* '<S49>/Unit Delay' */
  real_T UnitDelay_DSTATE_j[169];      /* '<S76>/Unit Delay' */
  real_T UnitDelay_DSTATE_l[169];      /* '<S48>/Unit Delay' */
  real_T UnitDelay1_DSTATE_p[169];     /* '<S48>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_b[13];      /* '<S50>/Unit Delay1' */
  real_T sqrt_i;                       /* '<S39>/sqrt' */
  real_T Product11;                    /* '<S79>/Product11' */
  real_T Product4;                     /* '<S80>/Product4' */
  real_T Product12;                    /* '<S85>/Product12' */
  real_T sqrt_p;                       /* '<S86>/sqrt' */
  real_T Sum1;                         /* '<S47>/Sum1' */
  real_T Sum2;                         /* '<S47>/Sum2' */
  real_T Sum3;                         /* '<S47>/Sum3' */
  real_T Sum5;                         /* '<S47>/Sum5' */
  real_T Merge1_e;                     /* '<S48>/Merge1' */
  real_T Merge_a;                      /* '<S48>/Merge' */
  real_T Product2;                     /* '<S50>/Product2' */
  real_T UnitDelay1_DSTATE_h;          /* '<S47>/Unit Delay1' */
  real_T UnitDelay3_DSTATE;            /* '<S47>/Unit Delay3' */
  real_T UnitDelay2_DSTATE_i;          /* '<S47>/Unit Delay2' */
  real_T UnitDelay4_DSTATE;            /* '<S47>/Unit Delay4' */
  real_T otime_PreviousInput;          /* '<S44>/otime' */
  real_T olon_PreviousInput;           /* '<S43>/olon' */
  real_T olat_PreviousInput;           /* '<S42>/olat' */
  real_T oalt_PreviousInput;           /* '<S42>/oalt' */
  real_T Memory_PreviousInput;         /* '<S16>/Memory' */
  uint8_T ForIterator_IterationMarker[7];/* '<S46>/For Iterator' */
  boolean_T SpecialcaseNorthSouthGeographic;/* '<S47>/Special case - North//South Geographic Pole' */
} DW;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: k)
   * Referenced by:
   *   '<S64>/k[13][13]'
   *   '<S55>/k[13][13]'
   */
  real_T pooled5[169];

  /* Pooled Parameter (Expression: snorm)
   * Referenced by:
   *   '<S48>/snorm[169]'
   *   '<S48>/Unit Delay1'
   */
  real_T pooled8[169];

  /* Expression: c
   * Referenced by: '<S49>/c[maxdef][maxdef]'
   */
  real_T cmaxdefmaxdef_Value[169];

  /* Expression: cd
   * Referenced by: '<S49>/cd[maxdef][maxdef]'
   */
  real_T cdmaxdefmaxdef_Value[169];

  /* Expression: fm
   * Referenced by: '<S47>/fm'
   */
  real_T fm_Value[13];

  /* Expression: fn
   * Referenced by: '<S47>/fn'
   */
  real_T fn_Value[13];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S87>/sp[11]'
   *   '<S87>/cp[11]'
   *   '<S87>/Constant'
   *   '<S87>/Constant1'
   */
  real_T pooled11[11];

  /* Expression: [0 0 (1:(maxdef-1))]
   * Referenced by: '<S40>/sp[13]'
   */
  real_T sp13_Y0[13];

  /* Expression: [1 1 (1:(maxdef-1))]
   * Referenced by: '<S40>/cp[13]'
   */
  real_T cp13_Y0[13];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T pos_ecef_m[3];                /* '<Root>/pos_ecef_m' */
  real_T time_vec[6];                  /* '<Root>/time_vec' */
  real_T eci_to_ecef[9];               /* '<Root>/eci_to_ecef' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T mag_unit_vector_eci[3];       /* '<Root>/mag_unit_vector_eci' */
  real_T mag_vector_eci_T[3];          /* '<Root>/mag_vector_eci_T' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void mag_vector_initialize(void);
extern void mag_vector_step(void);
extern void mag_vector_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S28>/Assertion' : Unused code path elimination
 * Block '<S28>/conjunction' : Unused code path elimination
 * Block '<S28>/max_relop' : Unused code path elimination
 * Block '<S28>/max_val' : Unused code path elimination
 * Block '<S28>/min_relop' : Unused code path elimination
 * Block '<S28>/min_val' : Unused code path elimination
 * Block '<S29>/Assertion' : Unused code path elimination
 * Block '<S29>/conjunction' : Unused code path elimination
 * Block '<S29>/max_relop' : Unused code path elimination
 * Block '<S29>/max_val' : Unused code path elimination
 * Block '<S29>/min_relop' : Unused code path elimination
 * Block '<S29>/min_val' : Unused code path elimination
 * Block '<S30>/Assertion' : Unused code path elimination
 * Block '<S30>/conjunction' : Unused code path elimination
 * Block '<S30>/max_relop' : Unused code path elimination
 * Block '<S30>/max_val' : Unused code path elimination
 * Block '<S30>/min_relop' : Unused code path elimination
 * Block '<S30>/min_val' : Unused code path elimination
 * Block '<S32>/Assertion' : Unused code path elimination
 * Block '<S32>/conjunction' : Unused code path elimination
 * Block '<S32>/max_relop' : Unused code path elimination
 * Block '<S32>/max_val' : Unused code path elimination
 * Block '<S32>/maxtype' : Unused code path elimination
 * Block '<S32>/min_relop' : Unused code path elimination
 * Block '<S32>/min_val' : Unused code path elimination
 * Block '<S32>/mintype' : Unused code path elimination
 * Block '<S34>/Unit Conversion' : Unused code path elimination
 * Block '<S35>/Unit Conversion' : Unused code path elimination
 * Block '<S27>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S33>/Unit Conversion' : Eliminated nontunable gain of 1
 * Block '<S6>/Unit Conversion2' : Eliminated nontunable gain of 1
 * Block '<S55>/Reshape' : Reshape block reduction
 * Block '<S62>/Reshape' : Reshape block reduction
 * Block '<S63>/Reshape' : Reshape block reduction
 * Block '<S64>/Reshape' : Reshape block reduction
 * Block '<S64>/Reshape1' : Reshape block reduction
 * Block '<S40>/Gain' : Eliminated nontunable gain of 1
 * Block '<S40>/Gain1' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector')    - opens subsystem adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector
 * hilite_system('adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors'
 * '<S1>'   : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector'
 * '<S2>'   : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA'
 * '<S3>'   : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED'
 * '<S4>'   : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/MATLAB Function'
 * '<S5>'   : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/Normalize Vector'
 * '<S6>'   : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015'
 * '<S7>'   : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/Conversion'
 * '<S8>'   : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/Subsystem2'
 * '<S9>'   : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/Subsystem3'
 * '<S10>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/While Iterator Subsystem'
 * '<S11>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/e^1'
 * '<S12>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/e^2'
 * '<S13>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/e^3'
 * '<S14>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/While Iterator Subsystem/Subsystem2'
 * '<S15>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/While Iterator Subsystem/Subsystem3'
 * '<S16>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoLLA/While Iterator Subsystem/Subsystem4'
 * '<S17>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/A11'
 * '<S18>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/A12'
 * '<S19>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/A13'
 * '<S20>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/A21'
 * '<S21>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/A22'
 * '<S22>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/A23'
 * '<S23>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/A31'
 * '<S24>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/A32'
 * '<S25>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/A33'
 * '<S26>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/Angle Conversion'
 * '<S27>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/ECEFtoNED/Create Transformation Matrix'
 * '<S28>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Check Altitude'
 * '<S29>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Check Latitude'
 * '<S30>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Check Longitude'
 * '<S31>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Compute x,y,z, and h components of magnetic field'
 * '<S32>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Is time within model limits'
 * '<S33>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Length Conversion'
 * '<S34>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/MagField Conversion'
 * '<S35>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/MagField Conversion1'
 * '<S36>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag'
 * '<S37>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Compute x,y,z, and h components of magnetic field/Angle Conversion'
 * '<S38>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates'
 * '<S39>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates'
 * '<S40>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates '
 * '<S41>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Get Cosine and Sine  of Latitude and Longitude'
 * '<S42>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Has altitude or latitude changed'
 * '<S43>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Has longitude changed '
 * '<S44>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Has time changed'
 * '<S45>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity'
 * '<S46>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem'
 * '<S47>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion'
 * '<S48>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations'
 * '<S49>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients'
 * '<S50>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole'
 * '<S51>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate  index'
 * '<S52>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values'
 * '<S53>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/special case'
 * '<S54>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem1'
 * '<S55>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2'
 * '<S56>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  indices'
 * '<S57>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  row and column'
 * '<S58>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem'
 * '<S59>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1'
 * '<S60>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/m,n'
 * '<S61>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/n,m-1'
 * '<S62>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem'
 * '<S63>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1'
 * '<S64>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2'
 * '<S65>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/calculate  index'
 * '<S66>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  index'
 * '<S67>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  row and column'
 * '<S68>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  index'
 * '<S69>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  row and column'
 * '<S70>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  indices'
 * '<S71>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column1'
 * '<S72>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column2'
 * '<S73>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2'
 * '<S74>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2 '
 * '<S75>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/If Action Subsystem'
 * '<S76>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)'
 * '<S77>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem1'
 * '<S78>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem2'
 * '<S79>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate ca'
 * '<S80>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate ct'
 * '<S81>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate d'
 * '<S82>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate q'
 * '<S83>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate q2'
 * '<S84>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate r2'
 * '<S85>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate sa'
 * '<S86>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate st'
 * '<S87>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates /For Iterator Subsystem'
 * '<S88>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Get Cosine and Sine  of Latitude and Longitude/Angle Conversion2'
 * '<S89>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bx'
 * '<S90>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate by'
 * '<S91>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bz'
 * '<S92>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity'
 * '<S93>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion'
 * '<S94>'  : 'adcs_sim_main/Flightsoftware/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion1'
 */
#endif                                 /* RTW_HEADER_mag_vector_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
