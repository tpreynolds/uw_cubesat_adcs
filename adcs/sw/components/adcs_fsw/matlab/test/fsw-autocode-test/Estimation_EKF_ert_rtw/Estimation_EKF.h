/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Estimation_EKF.h
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

#ifndef RTW_HEADER_Estimation_EKF_h_
#define RTW_HEADER_Estimation_EKF_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef Estimation_EKF_COMMON_INCLUDES_
# define Estimation_EKF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Estimation_EKF_COMMON_INCLUDES_ */

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
  real_T u1[3];                        /* '<S1>/ 11' */
  real_T u[3];                         /* '<S1>/ 5' */
  real_T UnitDelay_DSTATE[4];          /* '<S1>/Unit Delay' */
  real_T UnitDelay1_DSTATE[3];         /* '<S1>/Unit Delay1' */
  real_T UnitDelay2_DSTATE[36];        /* '<S1>/Unit Delay2' */
  real_T u1_Buffer0[3];                /* '<S1>/ 11' */
  real_T u_Buffer0[3];                 /* '<S1>/ 5' */
} DW;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Product1[36];           /* '<S3>/Product1' */
} ConstB;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: fsw_params.estimation.ic.error_cov
   * Referenced by: '<S1>/Unit Delay2'
   */
  real_T UnitDelay2_InitialCondition[36];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T valid_gyro;                   /* '<Root>/valid_gyro' */
  boolean_T valid_mag;                 /* '<Root>/valid_mag' */
  boolean_T valid_sun;                 /* '<Root>/valid_sun ' */
  real_T w_body_radps[3];              /* '<Root>/w_body_radps' */
  real_T mag_body[3];                  /* '<Root>/mag_body' */
  real_T mag_eci_est[3];               /* '<Root>/mag_eci_est' */
  real_T sun_body[3];                  /* '<Root>/sun_body' */
  real_T sc2sun_unit[3];               /* '<Root>/sun_eci_est' */
  real_T meas_cov[36];                 /* '<Root>/meas_cov' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T quat_hat[4];                  /* '<Root>/quat_hat' */
  real_T w_body_hat_radps[3];          /* '<Root>/w_body_hat_radps' */
  real_T usigma[36];                   /* '<Root>/3sigma' */
  real_T bias_hat[3];                  /* '<Root>/bias_hat' */
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
extern const ConstB rtConstB;          /* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void Estimation_EKF_initialize(void);
extern void Estimation_EKF_step0(void);
extern void Estimation_EKF_step1(void);
extern void Estimation_EKF_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/ ' : Eliminated since input and output rates are identical
 * Block '<S1>/ 1' : Eliminated since input and output rates are identical
 * Block '<S1>/ 10' : Eliminated since input and output rates are identical
 * Block '<S1>/ 2' : Eliminated since input and output rates are identical
 * Block '<S1>/ 3' : Eliminated since input and output rates are identical
 * Block '<S1>/ 4' : Eliminated since input and output rates are identical
 * Block '<S1>/ 6' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition10' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S1>/Reshape1' : Reshape block reduction
 * Block '<S1>/Reshape2' : Reshape block reduction
 * Block '<S1>/Reshape3' : Reshape block reduction
 * Block '<S1>/Reshape4' : Reshape block reduction
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
 * hilite_system('adcs_sim_main/Flightsoftware/Estimation_EKF ')    - opens subsystem adcs_sim_main/Flightsoftware/Estimation_EKF
 * hilite_system('adcs_sim_main/Flightsoftware/Estimation_EKF /Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'adcs_sim_main/Flightsoftware'
 * '<S1>'   : 'adcs_sim_main/Flightsoftware/Estimation_EKF '
 * '<S2>'   : 'adcs_sim_main/Flightsoftware/Estimation_EKF /3_sig_bnd '
 * '<S3>'   : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Propagate Step '
 * '<S4>'   : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Update Step '
 * '<S5>'   : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Propagate Step /Quaternion Normalize'
 * '<S6>'   : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Propagate Step /propagate_quat'
 * '<S7>'   : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Propagate Step /state_transition'
 * '<S8>'   : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Propagate Step /Quaternion Normalize/Quaternion Modulus'
 * '<S9>'   : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Propagate Step /Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S10>'  : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Update Step /If Action Subsystem'
 * '<S11>'  : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Update Step /If Action Subsystem1'
 * '<S12>'  : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Update Step /If Action Subsystem/convert_inertial_body'
 * '<S13>'  : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Update Step /If Action Subsystem/covariance_update'
 * '<S14>'  : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Update Step /If Action Subsystem/kalman_gain'
 * '<S15>'  : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Update Step /If Action Subsystem/observation_matrix'
 * '<S16>'  : 'adcs_sim_main/Flightsoftware/Estimation_EKF /Update Step /If Action Subsystem/update_state '
 */
#endif                                 /* RTW_HEADER_Estimation_EKF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
