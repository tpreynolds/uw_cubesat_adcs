/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: estimate_eci_vectors.h
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

#ifndef RTW_HEADER_estimate_eci_vectors_h_
#define RTW_HEADER_estimate_eci_vectors_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef estimate_eci_vectors_COMMON_INCLUDES_
# define estimate_eci_vectors_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* estimate_eci_vectors_COMMON_INCLUDES_ */

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
  real_T RateTransition7[9];           /* '<S1>/Rate Transition7' */
  real_T RateTransition2[9];           /* '<S1>/Rate Transition2' */
  real_T RateTransition5[9];           /* '<S1>/Rate Transition5' */
  real_T RateTransition1[6];           /* '<S1>/Rate Transition1' */
  real_T OutportBufferForcp13[13];
  real_T OutportBufferForsp13[13];
  real_T Sum2_i[169];                  /* '<S52>/Sum2' */
  real_T Assignment_p[169];            /* '<S51>/Assignment' */
  real_T Assignment_snorm[169];        /* '<S51>/Assignment_snorm' */
  real_T Assignment2_g[13];            /* '<S58>/Assignment2' */
  real_T Assignment2_e[13];            /* '<S57>/Assignment2' */
  real_T UnitDelay1_DSTATE[2];         /* '<S90>/Unit Delay1' */
  real_T UnitDelay_DSTATE_i[169];      /* '<S52>/Unit Delay' */
  real_T UnitDelay_DSTATE_m[169];      /* '<S79>/Unit Delay' */
  real_T UnitDelay_DSTATE_c[169];      /* '<S51>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i[169];     /* '<S51>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_d[13];      /* '<S53>/Unit Delay1' */
  real_T RateTransition7_Buffer0[9];   /* '<S1>/Rate Transition7' */
  real_T RateTransition2_Buffer0[9];   /* '<S1>/Rate Transition2' */
  real_T RateTransition5_Buffer0[9];   /* '<S1>/Rate Transition5' */
  real_T RateTransition1_Buffer0[6];   /* '<S1>/Rate Transition1' */
  real_T RateTransition4;              /* '<S1>/Rate Transition4' */
  real_T RateTransition3;              /* '<S1>/Rate Transition3' */
  real_T sqrt_m;                       /* '<S42>/sqrt' */
  real_T Product11;                    /* '<S82>/Product11' */
  real_T Product4;                     /* '<S83>/Product4' */
  real_T Product12;                    /* '<S88>/Product12' */
  real_T sqrt_m1;                      /* '<S89>/sqrt' */
  real_T Sum1;                         /* '<S50>/Sum1' */
  real_T Sum2;                         /* '<S50>/Sum2' */
  real_T Sum3;                         /* '<S50>/Sum3' */
  real_T Sum5;                         /* '<S50>/Sum5' */
  real_T Merge1_c;                     /* '<S51>/Merge1' */
  real_T Merge_c;                      /* '<S51>/Merge' */
  real_T Product2;                     /* '<S53>/Product2' */
  real_T UnitDelay1_DSTATE_c;          /* '<S50>/Unit Delay1' */
  real_T UnitDelay3_DSTATE;            /* '<S50>/Unit Delay3' */
  real_T UnitDelay2_DSTATE_n;          /* '<S50>/Unit Delay2' */
  real_T UnitDelay4_DSTATE;            /* '<S50>/Unit Delay4' */
  real_T RateTransition4_Buffer0;      /* '<S1>/Rate Transition4' */
  real_T RateTransition3_Buffer0;      /* '<S1>/Rate Transition3' */
  real_T otime_PreviousInput;          /* '<S47>/otime' */
  real_T olon_PreviousInput;           /* '<S46>/olon' */
  real_T olat_PreviousInput;           /* '<S45>/olat' */
  real_T oalt_PreviousInput;           /* '<S45>/oalt' */
  real_T Memory_PreviousInput;         /* '<S19>/Memory' */
  uint8_T ForIterator_IterationMarker[7];/* '<S49>/For Iterator' */
  boolean_T SpecialcaseNorthSouthGeographic;/* '<S50>/Special case - North//South Geographic Pole' */
} DW;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: k)
   * Referenced by:
   *   '<S67>/k[13][13]'
   *   '<S58>/k[13][13]'
   */
  real_T pooled5[169];

  /* Pooled Parameter (Expression: snorm)
   * Referenced by:
   *   '<S51>/snorm[169]'
   *   '<S51>/Unit Delay1'
   */
  real_T pooled8[169];

  /* Expression: c
   * Referenced by: '<S52>/c[maxdef][maxdef]'
   */
  real_T cmaxdefmaxdef_Value[169];

  /* Expression: cd
   * Referenced by: '<S52>/cd[maxdef][maxdef]'
   */
  real_T cdmaxdefmaxdef_Value[169];

  /* Expression: fm
   * Referenced by: '<S50>/fm'
   */
  real_T fm_Value[13];

  /* Expression: fn
   * Referenced by: '<S50>/fn'
   */
  real_T fn_Value[13];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S90>/sp[11]'
   *   '<S90>/cp[11]'
   *   '<S90>/Constant'
   *   '<S90>/Constant1'
   */
  real_T pooled11[11];

  /* Expression: [0 0 (1:(maxdef-1))]
   * Referenced by: '<S43>/sp[13]'
   */
  real_T sp13_Y0[13];

  /* Expression: [1 1 (1:(maxdef-1))]
   * Referenced by: '<S43>/cp[13]'
   */
  real_T cp13_Y0[13];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T orbit_tle[9];                 /* '<Root>/orbit_tle' */
  real_T JD_ut1_J2000_century;         /* '<Root>/Inport1' */
  real_T itrf_to_gcrf[9];              /* '<Root>/Inport2' */
  real_T time_vec_ut1[6];              /* '<Root>/Inport3' */
  real_T JD_ut1_J2000_days;            /* '<Root>/Inport4' */
  real_T teme_to_gcrf[9];              /* '<Root>/Inport5' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T sc_in_sun;                    /* '<Root>/sc_in_sun' */
  real_T sc2sun_unit[3];               /* '<Root>/sc2sun_unit' */
  real_T mag_unit_vector_eci[3];       /* '<Root>/mag_unit_vector_eci' */
  real_T mag_vector_eci[3];            /* '<Root>/mag_vector_eci' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID0_1;
    } RateInteraction;
  } Timing;
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
extern void estimate_eci_vectors_initialize(void);
extern void estimate_eci_vectors_step0(void);
extern void estimate_eci_vectors_step1(void);
extern void estimate_eci_vectors_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Gain1' : Unused code path elimination
 * Block '<S1>/Product2' : Unused code path elimination
 * Block '<S1>/Rate Transition6' : Unused code path elimination
 * Block '<S31>/Assertion' : Unused code path elimination
 * Block '<S31>/conjunction' : Unused code path elimination
 * Block '<S31>/max_relop' : Unused code path elimination
 * Block '<S31>/max_val' : Unused code path elimination
 * Block '<S31>/min_relop' : Unused code path elimination
 * Block '<S31>/min_val' : Unused code path elimination
 * Block '<S32>/Assertion' : Unused code path elimination
 * Block '<S32>/conjunction' : Unused code path elimination
 * Block '<S32>/max_relop' : Unused code path elimination
 * Block '<S32>/max_val' : Unused code path elimination
 * Block '<S32>/min_relop' : Unused code path elimination
 * Block '<S32>/min_val' : Unused code path elimination
 * Block '<S33>/Assertion' : Unused code path elimination
 * Block '<S33>/conjunction' : Unused code path elimination
 * Block '<S33>/max_relop' : Unused code path elimination
 * Block '<S33>/max_val' : Unused code path elimination
 * Block '<S33>/min_relop' : Unused code path elimination
 * Block '<S33>/min_val' : Unused code path elimination
 * Block '<S35>/Assertion' : Unused code path elimination
 * Block '<S35>/conjunction' : Unused code path elimination
 * Block '<S35>/max_relop' : Unused code path elimination
 * Block '<S35>/max_val' : Unused code path elimination
 * Block '<S35>/maxtype' : Unused code path elimination
 * Block '<S35>/min_relop' : Unused code path elimination
 * Block '<S35>/min_val' : Unused code path elimination
 * Block '<S35>/mintype' : Unused code path elimination
 * Block '<S37>/Unit Conversion' : Unused code path elimination
 * Block '<S38>/Unit Conversion' : Unused code path elimination
 * Block '<S1>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition12' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition13' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition9' : Eliminated since input and output rates are identical
 * Block '<S30>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S36>/Unit Conversion' : Eliminated nontunable gain of 1
 * Block '<S9>/Unit Conversion2' : Eliminated nontunable gain of 1
 * Block '<S58>/Reshape' : Reshape block reduction
 * Block '<S65>/Reshape' : Reshape block reduction
 * Block '<S66>/Reshape' : Reshape block reduction
 * Block '<S67>/Reshape' : Reshape block reduction
 * Block '<S67>/Reshape1' : Reshape block reduction
 * Block '<S43>/Gain' : Eliminated nontunable gain of 1
 * Block '<S43>/Gain1' : Eliminated nontunable gain of 1
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
 * hilite_system('adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors')    - opens subsystem adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors
 * hilite_system('adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'adcs_sim_main/Flightsoftware/MSP_FSW'
 * '<S1>'   : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors'
 * '<S2>'   : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector'
 * '<S3>'   : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/sgp4_lib_fsw'
 * '<S4>'   : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/sun_vector_lib'
 * '<S5>'   : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA'
 * '<S6>'   : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED'
 * '<S7>'   : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/MATLAB Function'
 * '<S8>'   : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/Normalize Vector'
 * '<S9>'   : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015'
 * '<S10>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/Conversion'
 * '<S11>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/Subsystem2'
 * '<S12>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/Subsystem3'
 * '<S13>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/While Iterator Subsystem'
 * '<S14>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/e^1'
 * '<S15>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/e^2'
 * '<S16>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/e^3'
 * '<S17>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/While Iterator Subsystem/Subsystem2'
 * '<S18>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/While Iterator Subsystem/Subsystem3'
 * '<S19>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoLLA/While Iterator Subsystem/Subsystem4'
 * '<S20>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/A11'
 * '<S21>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/A12'
 * '<S22>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/A13'
 * '<S23>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/A21'
 * '<S24>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/A22'
 * '<S25>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/A23'
 * '<S26>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/A31'
 * '<S27>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/A32'
 * '<S28>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/A33'
 * '<S29>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/Angle Conversion'
 * '<S30>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/ECEFtoNED/Create Transformation Matrix'
 * '<S31>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Check Altitude'
 * '<S32>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Check Latitude'
 * '<S33>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Check Longitude'
 * '<S34>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Compute x,y,z, and h components of magnetic field'
 * '<S35>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Is time within model limits'
 * '<S36>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Length Conversion'
 * '<S37>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/MagField Conversion'
 * '<S38>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/MagField Conversion1'
 * '<S39>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag'
 * '<S40>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/Compute x,y,z, and h components of magnetic field/Angle Conversion'
 * '<S41>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates'
 * '<S42>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates'
 * '<S43>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates '
 * '<S44>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Get Cosine and Sine  of Latitude and Longitude'
 * '<S45>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Has altitude or latitude changed'
 * '<S46>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Has longitude changed '
 * '<S47>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Has time changed'
 * '<S48>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity'
 * '<S49>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem'
 * '<S50>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion'
 * '<S51>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations'
 * '<S52>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients'
 * '<S53>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole'
 * '<S54>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate  index'
 * '<S55>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values'
 * '<S56>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/special case'
 * '<S57>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem1'
 * '<S58>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2'
 * '<S59>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  indices'
 * '<S60>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/Special case - North//South Geographic Pole/If Action Subsystem2/calculate  row and column'
 * '<S61>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem'
 * '<S62>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1'
 * '<S63>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/m,n'
 * '<S64>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Accumulate terms of the  spherical harmonic expansion/calculate temp values/If Action Subsystem1/n,m-1'
 * '<S65>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem'
 * '<S66>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1'
 * '<S67>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2'
 * '<S68>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/calculate  index'
 * '<S69>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  index'
 * '<S70>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem/calculate  row and column'
 * '<S71>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  index'
 * '<S72>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem1/calculate  row and column'
 * '<S73>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  indices'
 * '<S74>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column1'
 * '<S75>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/calculate  row and column2'
 * '<S76>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2'
 * '<S77>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations/If Action Subsystem2/m<n-2 '
 * '<S78>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/If Action Subsystem'
 * '<S79>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)'
 * '<S80>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem1'
 * '<S81>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Compute magnetic vector in spherical coordinates/For Iterator Subsystem/Time adjust the gauss coefficients/if (m~=0)/If Action Subsystem2'
 * '<S82>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate ca'
 * '<S83>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate ct'
 * '<S84>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate d'
 * '<S85>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate q'
 * '<S86>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate q2'
 * '<S87>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate r2'
 * '<S88>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate sa'
 * '<S89>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates/calculate st'
 * '<S90>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Convert from geodetic to  spherical coordinates /For Iterator Subsystem'
 * '<S91>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Get Cosine and Sine  of Latitude and Longitude/Angle Conversion2'
 * '<S92>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bx'
 * '<S93>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate by'
 * '<S94>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Calculate bz'
 * '<S95>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity'
 * '<S96>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion'
 * '<S97>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/mag_vector/World Magnetic Model 2015/geomag/Rotate magnetic vector components  to geodetic from spherical and  compute declination, inclination  and total intensity/Compute declination, inclination,  and total intensity/Angle Conversion1'
 * '<S98>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/sgp4_lib_fsw/MATLAB Function'
 * '<S99>'  : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/sun_vector_lib/MATLAB Function'
 * '<S100>' : 'adcs_sim_main/Flightsoftware/MSP_FSW/estimate_eci_vectors/sun_vector_lib/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_estimate_eci_vectors_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
