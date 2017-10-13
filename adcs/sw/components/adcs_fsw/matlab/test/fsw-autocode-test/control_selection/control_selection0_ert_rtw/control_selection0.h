/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_selection0.h
 *
 * Code generated for Simulink model 'control_selection0'.
 *
 * Model version                  : 1.147
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Oct 13 16:06:29 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->MSP430
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_control_selection0_h_
#define RTW_HEADER_control_selection0_h_
#include <math.h>
#ifndef control_selection0_COMMON_INCLUDES_
# define control_selection0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* control_selection0_COMMON_INCLUDES_ */

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
  real_T RateTransition[3];            /* '<S3>/Rate Transition' */
  real_T RateTransition1[3];           /* '<S3>/Rate Transition1' */
  real_T RateTransition2[3];           /* '<S3>/Rate Transition2' */
  real_T RateTransition2_k[3];         /* '<S4>/Rate Transition2' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S12>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states[3];/* '<S5>/Discrete Transfer Fcn' */
  real_T UnitDelay_DSTATE[3];          /* '<S5>/Unit Delay' */
  real_T UD_DSTATE[3];                 /* '<S21>/UD' */
  real_T UnitDelay_DSTATE_e[3];        /* '<S3>/Unit Delay' */
  real_T Product_DWORK4[9];            /* '<S19>/Product' */
  real_T RateTransition_Buffer0[3];    /* '<S3>/Rate Transition' */
  real_T RateTransition4_Buffer0[3];   /* '<S5>/Rate Transition4' */
  real_T RateTransition4;              /* '<S3>/Rate Transition4' */
  real_T RateTransition3;              /* '<S3>/Rate Transition3' */
  real_T RateTransition2_Buffer0;      /* '<S5>/Rate Transition2' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  int8_T RateTransition2_semaphoreTaken;/* '<S5>/Rate Transition2' */
  int8_T RateTransition4_semaphoreTaken;/* '<S5>/Rate Transition4' */
} DW;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Product[9];             /* '<S19>/Product' */
} ConstB;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: fsw_params.bdot.gain_matrix
   * Referenced by: '<S5>/gain matrix'
   */
  real_T gainmatrix_Value[9];

  /* Expression: fsw_params.sensor_processing.magnetometer.process_matrix
   * Referenced by: '<S22>/Constant1'
   */
  real_T Constant1_Value[9];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T sc_mode;                      /* '<Root>/sc_mode' */
  real_T omega_radps[3];               /* '<Root>/omega_radps' */
  real_T sc_quat[4];                   /* '<Root>/sc_quat' */
  real_T B_body_T[3];                  /* '<Root>/B_body_T' */
  real_T mag_body_T[4];                /* '<Root>/B_body_T_unprocessed' */
  boolean_T MT_on;                     /* '<Root>/MT_on' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T cmd_RW_out[3];                /* '<Root>/cmd_RW_out' */
  real_T cmd_MAG_out[3];               /* '<Root>/cmd_MAG_out' */
  real_T ctrl_status;                  /* '<Root>/ctrl_status' */
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
      uint8_T TID0_2;
      uint8_T TID1_2;
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
extern void control_selection0_initialize(void);
extern void control_selection0_step0(void);
extern void control_selection0_step1(void);
extern void control_selection0_step2(void);
extern void control_selection0_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Product' : Unused code path elimination
 * Block '<S15>/Product1' : Unused code path elimination
 * Block '<S15>/Product2' : Unused code path elimination
 * Block '<S15>/Product3' : Unused code path elimination
 * Block '<S15>/Sum' : Unused code path elimination
 * Block '<S4>/Rate Transition' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S4>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S20>/Reshape' : Reshape block reduction
 * Block '<S12>/Reshape' : Reshape block reduction
 * Block '<S1>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S5>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * hilite_system('adcs_sim_main/Flightsoftware/control_selection')    - opens subsystem adcs_sim_main/Flightsoftware/control_selection
 * hilite_system('adcs_sim_main/Flightsoftware/control_selection/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'adcs_sim_main/Flightsoftware'
 * '<S1>'   : 'adcs_sim_main/Flightsoftware/control_selection'
 * '<S2>'   : 'adcs_sim_main/Flightsoftware/control_selection/Control Selection'
 * '<S3>'   : 'adcs_sim_main/Flightsoftware/control_selection/Momentum unloading'
 * '<S4>'   : 'adcs_sim_main/Flightsoftware/control_selection/PD Control'
 * '<S5>'   : 'adcs_sim_main/Flightsoftware/control_selection/bdot_controller_lib'
 * '<S6>'   : 'adcs_sim_main/Flightsoftware/control_selection/Control Selection/MATLAB Function'
 * '<S7>'   : 'adcs_sim_main/Flightsoftware/control_selection/Momentum unloading/3x3 Cross Product'
 * '<S8>'   : 'adcs_sim_main/Flightsoftware/control_selection/Momentum unloading/3x3 Cross Product/Subsystem'
 * '<S9>'   : 'adcs_sim_main/Flightsoftware/control_selection/Momentum unloading/3x3 Cross Product/Subsystem1'
 * '<S10>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/Quaternion Inverse'
 * '<S11>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/Quaternion Multiplication'
 * '<S12>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/torque-2-RPM'
 * '<S13>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/Quaternion Inverse/Quaternion Conjugate'
 * '<S14>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/Quaternion Inverse/Quaternion Norm'
 * '<S15>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/Quaternion Multiplication/q0'
 * '<S16>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/Quaternion Multiplication/q1'
 * '<S17>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/Quaternion Multiplication/q2'
 * '<S18>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/Quaternion Multiplication/q3'
 * '<S19>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/torque-2-RPM/Invert  3x3 Matrix'
 * '<S20>'  : 'adcs_sim_main/Flightsoftware/control_selection/PD Control/torque-2-RPM/Invert  3x3 Matrix/Determinant of 3x3 Matrix'
 * '<S21>'  : 'adcs_sim_main/Flightsoftware/control_selection/bdot_controller_lib/Discrete Derivative'
 * '<S22>'  : 'adcs_sim_main/Flightsoftware/control_selection/bdot_controller_lib/Signal Processing'
 */
#endif                                 /* RTW_HEADER_control_selection0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
