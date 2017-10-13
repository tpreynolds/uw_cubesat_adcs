/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_selecction.c
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

#include "mode_selecction.h"
#include "mode_selecction_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void mode_selecction_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/mode_selecction' */

  /* Inport: '<Root>/RW_RPM' incorporates:
   *  Inport: '<Root>/omega_body_radps'
   *  Inport: '<Root>/quat_commanded'
   *  Inport: '<Root>/sc_in_sun'
   */
  mode_selecction_a(rtU.current_RW_RPM, rtU.sc_in_sun_fsw, rtU.omega_body_radps,
                    rtU.quat_commanded, &rtY.sc_mode);

  /* End of Outputs for SubSystem: '<Root>/mode_selecction' */
}

/* Model initialize function */
void mode_selecction_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void mode_selecction_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
