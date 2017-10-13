/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_selecction.h
 *
 * Code generated for Simulink model 'mode_selecction'.
 *
 * Model version                  : 1.147
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Oct 13 15:43:59 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->MSP430
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mode_selecction_h_
#define RTW_HEADER_mode_selecction_h_
#ifndef mode_selecction_COMMON_INCLUDES_
# define mode_selecction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* mode_selecction_COMMON_INCLUDES_ */

#include "mode_selecction_types.h"

/* Child system includes */
#include "mode_selecction_a.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T magnetorquer_pwrstate[3];     /* '<Root>/MT_powerstate' */
  real_T RW_pwrstate[3];               /* '<Root>/RW_powerstate' */
  real_T current_RW_RPM[3];            /* '<Root>/RW_RPM' */
  real_T sc_in_sun_fsw;                /* '<Root>/sc_in_sun' */
  real_T omega_body_radps[3];          /* '<Root>/omega_body_radps' */
  real_T quat_commanded[4];            /* '<Root>/quat_commanded' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T sc_mode;                      /* '<Root>/sc_mode' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void mode_selecction_initialize(void);
extern void mode_selecction_step(void);
extern void mode_selecction_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * hilite_system('adcs_sim_main/Flightsoftware/mode_selecction')    - opens subsystem adcs_sim_main/Flightsoftware/mode_selecction
 * hilite_system('adcs_sim_main/Flightsoftware/mode_selecction/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'adcs_sim_main/Flightsoftware'
 * '<S1>'   : 'adcs_sim_main/Flightsoftware/mode_selecction'
 * '<S2>'   : 'adcs_sim_main/Flightsoftware/mode_selecction/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_mode_selecction_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
