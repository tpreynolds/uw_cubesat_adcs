/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: reaction_wheel_PID_lib.c
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

#include "reaction_wheel_PID_lib.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Model step function */
void reaction_wheel_PID_lib_step(void)
{
  real_T rtb_FilterCoefficient;

  /* Gain: '<S2>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S2>/Filter'
   *  Gain: '<S2>/Derivative Gain'
   *  Gain: '<S2>/Setpoint Weighting (Derivative)'
   *  Inport: '<Root>/omega_in_radps'
   *  Inport: '<Root>/omega_ref_radps'
   *  Sum: '<S2>/Sum3'
   *  Sum: '<S2>/SumD'
   */
  rtb_FilterCoefficient = ((0.0142681697957121 * rtU.omega - rtU.omega_in_radps)
    * -56.0991504171521 - rtDW.Filter_DSTATE) * 4917.07172490179;

  /* Outport: '<Root>/omega_PID_out' incorporates:
   *  DiscreteIntegrator: '<S2>/Integrator'
   *  Gain: '<S2>/Proportional Gain'
   *  Gain: '<S2>/Setpoint Weighting (Proportional)'
   *  Inport: '<Root>/omega_in_radps'
   *  Inport: '<Root>/omega_ref_radps'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  rtY.omega_PID_out = ((0.0142681697957121 * rtU.omega - rtU.omega_in_radps) *
                       275843.546307191 + rtDW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S2>/Filter' */
  rtDW.Filter_DSTATE += 0.2 * rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S2>/Integrator' incorporates:
   *  Gain: '<S2>/Integral Gain'
   *  Inport: '<Root>/omega_in_radps'
   *  Inport: '<Root>/omega_ref_radps'
   *  Sum: '<S2>/Sum2'
   */
  rtDW.Integrator_DSTATE += (rtU.omega - rtU.omega_in_radps) *
    4.3993998100777E+6 * 0.2;
}

/* Model initialize function */
void reaction_wheel_PID_lib_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void reaction_wheel_PID_lib_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
