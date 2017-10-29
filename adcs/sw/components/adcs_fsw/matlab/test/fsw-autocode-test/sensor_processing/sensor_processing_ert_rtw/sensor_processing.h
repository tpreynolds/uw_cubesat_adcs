/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sensor_processing.h
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

#ifndef RTW_HEADER_sensor_processing_h_
#define RTW_HEADER_sensor_processing_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef sensor_processing_COMMON_INCLUDES_
# define sensor_processing_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* sensor_processing_COMMON_INCLUDES_ */

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
  real_T RateTransition9[4];           /* '<S1>/Rate Transition9' */
  real_T RateTransition6[4];           /* '<S1>/Rate Transition6' */
  real_T RateTransition7[9];           /* '<S1>/Rate Transition7' */
  real_T RateTransition1[4];           /* '<S1>/Rate Transition1' */
  real_T RateTransition3[9];           /* '<S1>/Rate Transition3' */
  real_T RateTransition[3];            /* '<S1>/Rate Transition' */
  real_T RateTransition5[3];           /* '<S1>/Rate Transition5' */
  real_T RateTransition8[2];           /* '<S1>/Rate Transition8' */
  real_T UnitDelay_DSTATE[2];          /* '<S2>/Unit Delay' */
  real_T UnitDelay2_DSTATE[3];         /* '<S2>/Unit Delay2' */
  real_T UnitDelay1_DSTATE[3];         /* '<S2>/Unit Delay1' */
  real_T RateTransition2_Buffer[8];    /* '<S1>/Rate Transition2' */
  real_T RateTransition7_Buffer0[9];   /* '<S1>/Rate Transition7' */
  real_T RateTransition5_Buffer0[3];   /* '<S1>/Rate Transition5' */
  real_T RateTransition8_Buffer0[2];   /* '<S1>/Rate Transition8' */
  int8_T RateTransition2_ActiveBufIdx; /* '<S1>/Rate Transition2' */
  int8_T RateTransition2_semaphoreTaken;/* '<S1>/Rate Transition2' */
} DW;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S3>/Constant1'
   *   '<S4>/Constant1'
   *   '<S6>/Constant1'
   */
  real_T pooled1[9];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T measurements_deg_err[6];      /* '<Root>/measurements_deg_err' */
  real_T sun_body_unit_photodiode[3];  /* '<Root>/sun_body_unit_photodiode' */
  real_T sun_body_unit_sunsensor[4];   /* '<Root>/sun_body_unit_sunsensor' */
  real_T mag_body_T[4];                /* '<Root>/mag_body_T' */
  real_T GPS[9];                       /* '<Root>/GPS' */
  real_T omega_radps_gyro[4];          /* '<Root>/omega_radps_gyro' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T omega_radps[4];               /* '<Root>/omega_radps' */
  real_T mag_body_Tb[4];               /* '<Root>/mag_body_Tb' */
  real_T sun_body_sunsensor[4];        /* '<Root>/sun_body_sunsensor' */
  real_T orbit_tle[9];                 /* '<Root>/orbit_tle' */
  real_T cur_gps_time[2];              /* '<Root>/cur_gps_time' */
  real_T scfaceinsun_body_unit[3];     /* '<Root>/sc-face-in-sun_body_unit' */
  real_T Outport2;                     /* '<Root>/Outport2' */
  real_T Outport3[9];                  /* '<Root>/Outport3' */
  real_T Outport4[6];                  /* '<Root>/Outport4' */
  real_T Outport5;                     /* '<Root>/Outport5' */
  real_T Outport6[9];                  /* '<Root>/Outport6' */
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
      uint8_T TID1_3;
      uint8_T TID1_5;
      uint8_T TID2_3;
      uint8_T TID3_5;
      uint8_T TID3_6;
      uint8_T TID4_6;
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
extern void sensor_processing_initialize(void);
extern void sensor_processing_step0(void);
extern void sensor_processing_step1(void);
extern void sensor_processing_step2(void);
extern void sensor_processing_step3(void);
extern void sensor_processing_step4(void);
extern void sensor_processing_step5(void);
extern void sensor_processing_step6(void);
extern void sensor_processing_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Rate Transition11' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition4' : Eliminated since input and output rates are identical
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
 * hilite_system('adcs_sim_main/Flightsoftware/sensor_processing')    - opens subsystem adcs_sim_main/Flightsoftware/sensor_processing
 * hilite_system('adcs_sim_main/Flightsoftware/sensor_processing/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'adcs_sim_main/Flightsoftware'
 * '<S1>'   : 'adcs_sim_main/Flightsoftware/sensor_processing'
 * '<S2>'   : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib'
 * '<S3>'   : 'adcs_sim_main/Flightsoftware/sensor_processing/gyro_processing_lib'
 * '<S4>'   : 'adcs_sim_main/Flightsoftware/sensor_processing/magnetometer_processing_lib'
 * '<S5>'   : 'adcs_sim_main/Flightsoftware/sensor_processing/photodiode_processing_lib'
 * '<S6>'   : 'adcs_sim_main/Flightsoftware/sensor_processing/sunsensor_processing_lib'
 * '<S7>'   : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib/eci_2_TLE_lib'
 * '<S8>'   : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib/eci_2_TLE_lib/MATLAB Function'
 * '<S9>'   : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib/eci_2_TLE_lib/time and coord rotation libraries'
 * '<S10>'  : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib/eci_2_TLE_lib/time and coord rotation libraries/coord_rotations_lib'
 * '<S11>'  : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib/eci_2_TLE_lib/time and coord rotation libraries/gps_to_tt'
 * '<S12>'  : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib/eci_2_TLE_lib/time and coord rotation libraries/gps_to_ut1'
 * '<S13>'  : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib/eci_2_TLE_lib/time and coord rotation libraries/coord_rotations_lib/MATLAB Function'
 * '<S14>'  : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib/eci_2_TLE_lib/time and coord rotation libraries/gps_to_tt/Translate to TT'
 * '<S15>'  : 'adcs_sim_main/Flightsoftware/sensor_processing/GPS_processing_lib/eci_2_TLE_lib/time and coord rotation libraries/gps_to_ut1/Translate to UT1'
 * '<S16>'  : 'adcs_sim_main/Flightsoftware/sensor_processing/photodiode_processing_lib/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_sensor_processing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
