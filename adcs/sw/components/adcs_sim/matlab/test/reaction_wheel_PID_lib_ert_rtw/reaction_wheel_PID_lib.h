/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: reaction_wheel_PID_lib.h
 *
 * Code generated for Simulink model 'reaction_wheel_PID_lib'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Aug 28 20:37:18 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->MSP430
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_reaction_wheel_PID_lib_h_
#define RTW_HEADER_reaction_wheel_PID_lib_h_
#ifndef reaction_wheel_PID_lib_COMMON_INCLUDES_
# define reaction_wheel_PID_lib_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* reaction_wheel_PID_lib_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T Filter_DSTATE;                /* '<S2>/Filter' */
  real_T Integrator_DSTATE;            /* '<S2>/Integrator' */
} DW;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T omega;                        /* '<Root>/omega_ref_radps' */
  real_T omega_in_radps;               /* '<Root>/omega_in_radps' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T omega_PID_out;                /* '<Root>/omega_PID_out' */
} ExtY;

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void reaction_wheel_PID_lib_initialize(void);
extern void reaction_wheel_PID_lib_step(void);
extern void reaction_wheel_PID_lib_terminate(void);

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
 * hilite_system('untitled/reaction_wheel_PID_lib')    - opens subsystem untitled/reaction_wheel_PID_lib
 * hilite_system('untitled/reaction_wheel_PID_lib/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/reaction_wheel_PID_lib'
 * '<S2>'   : 'untitled/reaction_wheel_PID_lib/pid_controller'
 */
#endif                                 /* RTW_HEADER_reaction_wheel_PID_lib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
