/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_selection0.c
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

#include "control_selection0.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/*=========*
 * Asserts *
 *=========*/
#ifndef utAssert
# if defined(DOASSERTS)
#  if !defined(PRINT_ASSERTS)
#    include <assert.h>
#    define utAssert(exp)              assert(exp)
#  else
#    include <stdio.h>

static void _assert(char *statement, char *file, int line)
{
  printf("%s in %s on line %d\n", statement, file, line);
}

#   define utAssert(_EX)               ((_EX) ? (void)0 : _assert(#_EX, __FILE__, __LINE__))
#  endif

# else
#  define utAssert(exp)                                          /* do nothing */
# endif
#endif

/* Model step function for TID0 */
void control_selection0_step0(void)    /* Sample time: [0.004s, 0.0s] */
{
  int16_T rtb_PulseGenerator;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.004s, 0.0s] to Sample time: [0.1s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 24) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.004s, 0.0s] to Sample time: [0.2s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_2)++;
  if ((rtM->Timing.RateInteraction.TID0_2) > 49) {
    rtM->Timing.RateInteraction.TID0_2 = 0;
  }

  /* RateTransition: '<S5>/Rate Transition2' incorporates:
   *  Inport: '<Root>/B_body_T_unprocessed'
   */
  if (!(rtDW.RateTransition2_semaphoreTaken != 0)) {
    rtDW.RateTransition2_Buffer0 = rtU.mag_body_T[3];
  }

  /* End of RateTransition: '<S5>/Rate Transition2' */

  /* RateTransition: '<S3>/Rate Transition1' incorporates:
   *  Inport: '<Root>/omega_radps'
   */
  if (rtM->Timing.RateInteraction.TID0_2 == 1) {
    rtDW.RateTransition1[0] = rtU.omega_radps[0];
    rtDW.RateTransition1[1] = rtU.omega_radps[1];
    rtDW.RateTransition1[2] = rtU.omega_radps[2];
  }

  /* End of RateTransition: '<S3>/Rate Transition1' */

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_PulseGenerator = ((rtDW.clockTickCounter < 3L) && (rtDW.clockTickCounter >=
    0L));
  if (rtDW.clockTickCounter >= 499L) {
    rtDW.clockTickCounter = 0L;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* RateTransition: '<S3>/Rate Transition4' */
  if (rtM->Timing.RateInteraction.TID0_2 == 1) {
    rtDW.RateTransition4 = rtb_PulseGenerator;

    /* RateTransition: '<S3>/Rate Transition3' incorporates:
     *  Inport: '<Root>/B_body_T_unprocessed'
     */
    rtDW.RateTransition3 = rtU.mag_body_T[3];

    /* RateTransition: '<S3>/Rate Transition2' incorporates:
     *  Inport: '<Root>/B_body_T'
     */
    rtDW.RateTransition2[0] = rtU.B_body_T[0];
    rtDW.RateTransition2[1] = rtU.B_body_T[1];
    rtDW.RateTransition2[2] = rtU.B_body_T[2];
  }

  /* End of RateTransition: '<S3>/Rate Transition4' */

  /* RateTransition: '<S4>/Rate Transition2' incorporates:
   *  Inport: '<Root>/omega_radps'
   */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    rtDW.RateTransition2_k[0] = rtU.omega_radps[0];
    rtDW.RateTransition2_k[1] = rtU.omega_radps[1];
    rtDW.RateTransition2_k[2] = rtU.omega_radps[2];
  }

  /* End of RateTransition: '<S4>/Rate Transition2' */

  /* Assertion: '<S19>/Assertion' */
  utAssert(true);

  /* RateTransition: '<S5>/Rate Transition4' incorporates:
   *  Inport: '<Root>/B_body_T_unprocessed'
   */
  if (!(rtDW.RateTransition4_semaphoreTaken != 0)) {
    rtDW.RateTransition4_Buffer0[0] = rtU.mag_body_T[0];
    rtDW.RateTransition4_Buffer0[1] = rtU.mag_body_T[1];
    rtDW.RateTransition4_Buffer0[2] = rtU.mag_body_T[2];
  }

  /* End of RateTransition: '<S5>/Rate Transition4' */
}

/* Model step function for TID1 */
void control_selection0_step1(void)    /* Sample time: [0.1s, 0.0s] */
{
  boolean_T rtb_RateTransition3;
  real_T rtb_RateTransition2;
  real_T rtb_Sum_l[3];
  real_T rtb_MultiportSwitch1[3];
  real_T rtb_RateTransition4[3];
  real_T rtb_Product_j[3];
  real_T rtb_Gain[3];
  int16_T i;
  real_T tmp[3];
  real_T rtb_MultiportSwitch2_idx_0;
  real_T rtb_MultiportSwitch2_idx_1;
  real_T rtb_MultiportSwitch2_idx_2;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.1s, 0.0s] to Sample time: [0.2s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID1_2)++;
  if ((rtM->Timing.RateInteraction.TID1_2) > 1) {
    rtM->Timing.RateInteraction.TID1_2 = 0;
  }

  for (i = 0; i < 3; i++) {
    /* Gain: '<S12>/Gain' incorporates:
     *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
     *  Product: '<S12>/Product'
     *  Sum: '<S12>/Sum'
     */
    rtb_Gain[i] = 9.5492965855137211 * (rtConstB.Product[i + 6] *
      rtDW.DiscreteTimeIntegrator_DSTATE[2] + (rtConstB.Product[i + 3] *
      rtDW.DiscreteTimeIntegrator_DSTATE[1] + rtConstB.Product[i] *
      rtDW.DiscreteTimeIntegrator_DSTATE[0]));
  }

  /* RateTransition: '<S3>/Rate Transition' */
  if (rtM->Timing.RateInteraction.TID1_2 == 1) {
    rtDW.RateTransition[0] = rtDW.RateTransition_Buffer0[0];
    rtDW.RateTransition[1] = rtDW.RateTransition_Buffer0[1];
    rtDW.RateTransition[2] = rtDW.RateTransition_Buffer0[2];
  }

  /* End of RateTransition: '<S3>/Rate Transition' */

  /* DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' */
  rtb_Sum_l[0L] = 0.060898632575707344 * rtDW.DiscreteTransferFcn_states[0L];
  rtb_Sum_l[1L] = 0.060898632575707344 * rtDW.DiscreteTransferFcn_states[1L];
  rtb_Sum_l[2L] = 0.060898632575707344 * rtDW.DiscreteTransferFcn_states[2L];

  /* RateTransition: '<S5>/Rate Transition3' incorporates:
   *  Inport: '<Root>/MT_on'
   */
  rtb_RateTransition3 = rtU.MT_on;

  /* Logic: '<S5>/Logical Operator1' */
  rtb_RateTransition3 = !rtb_RateTransition3;

  /* RateTransition: '<S5>/Rate Transition2' */
  rtDW.RateTransition2_semaphoreTaken = 1;
  rtb_RateTransition2 = rtDW.RateTransition2_Buffer0;
  rtDW.RateTransition2_semaphoreTaken = 0;

  /* SampleTimeMath: '<S21>/TSamp'
   *
   * About '<S21>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Sum_l[0] *= 10.0;
  rtb_Sum_l[1] *= 10.0;
  rtb_MultiportSwitch2_idx_0 = rtb_Sum_l[2] * 10.0;
  rtb_Sum_l[2] = rtb_MultiportSwitch2_idx_0;

  /* MultiPortSwitch: '<S5>/Multiport Switch1' incorporates:
   *  Logic: '<S5>/Logical Operator'
   *  Sum: '<S21>/Diff'
   *  UnitDelay: '<S21>/UD'
   *  UnitDelay: '<S5>/Unit Delay'
   *
   * Block description for '<S21>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S21>/UD':
   *
   *  Store in Global RAM
   */
  if (!(rtb_RateTransition3 && (rtb_RateTransition2 != 0.0))) {
    rtb_MultiportSwitch1[0] = rtDW.UnitDelay_DSTATE[0];
    rtb_MultiportSwitch1[1] = rtDW.UnitDelay_DSTATE[1];
    rtb_MultiportSwitch1[2] = rtDW.UnitDelay_DSTATE[2];
  } else {
    rtb_MultiportSwitch1[0] = rtb_Sum_l[0] - rtDW.UD_DSTATE[0];
    rtb_MultiportSwitch1[1] = rtb_Sum_l[1] - rtDW.UD_DSTATE[1];
    rtb_MultiportSwitch1[2] = rtb_MultiportSwitch2_idx_0 - rtDW.UD_DSTATE[2];
  }

  /* End of MultiPortSwitch: '<S5>/Multiport Switch1' */

  /* MultiPortSwitch: '<S5>/Multiport Switch2' incorporates:
   *  Gain: '<S5>/To DigVal1'
   *  Gain: '<S5>/To DigVal2'
   *  Gain: '<S5>/To DigVal3'
   */
  if (!rtb_RateTransition3) {
    rtb_MultiportSwitch2_idx_0 = 0.0;
    rtb_MultiportSwitch2_idx_1 = 0.0;
    rtb_MultiportSwitch2_idx_2 = 0.0;
  } else {
    /* Product: '<S5>/Product' incorporates:
     *  Constant: '<S5>/gain matrix'
     */
    for (i = 0; i < 3; i++) {
      rtb_Product_j[i] = rtConstP.gainmatrix_Value[i + 6] *
        rtb_MultiportSwitch1[2] + (rtConstP.gainmatrix_Value[i + 3] *
        rtb_MultiportSwitch1[1] + rtConstP.gainmatrix_Value[i] *
        rtb_MultiportSwitch1[0]);
    }

    /* End of Product: '<S5>/Product' */

    /* Saturate: '<S5>/Saturation1' */
    if (rtb_Product_j[0] > 0.15) {
      rtb_MultiportSwitch2_idx_2 = 0.15;
    } else if (rtb_Product_j[0] < -0.15) {
      rtb_MultiportSwitch2_idx_2 = -0.15;
    } else {
      rtb_MultiportSwitch2_idx_2 = rtb_Product_j[0];
    }

    /* End of Saturate: '<S5>/Saturation1' */
    rtb_MultiportSwitch2_idx_0 = 1700.0000000000002 * rtb_MultiportSwitch2_idx_2;

    /* Saturate: '<S5>/Saturation2' incorporates:
     *  Gain: '<S5>/To DigVal1'
     */
    if (rtb_Product_j[1] > 0.15) {
      rtb_MultiportSwitch2_idx_2 = 0.15;
    } else if (rtb_Product_j[1] < -0.15) {
      rtb_MultiportSwitch2_idx_2 = -0.15;
    } else {
      rtb_MultiportSwitch2_idx_2 = rtb_Product_j[1];
    }

    /* End of Saturate: '<S5>/Saturation2' */
    rtb_MultiportSwitch2_idx_1 = 1700.0000000000002 * rtb_MultiportSwitch2_idx_2;

    /* Saturate: '<S5>/Saturation3' incorporates:
     *  Gain: '<S5>/To DigVal2'
     */
    if (rtb_Product_j[2] > 0.15) {
      rtb_MultiportSwitch2_idx_2 = 0.15;
    } else if (rtb_Product_j[2] < -0.15) {
      rtb_MultiportSwitch2_idx_2 = -0.15;
    } else {
      rtb_MultiportSwitch2_idx_2 = rtb_Product_j[2];
    }

    /* End of Saturate: '<S5>/Saturation3' */
    rtb_MultiportSwitch2_idx_2 *= 1700.0000000000002;
  }

  /* End of MultiPortSwitch: '<S5>/Multiport Switch2' */

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Inport: '<Root>/sc_mode'
   */
  /*  Control Selection Logic */
  /*    HuskySat-1, ADCS Team */
  /*    Last Update: T. Reynolds, 8.5.17 */
  /* MATLAB Function 'control_selection/Control Selection/MATLAB Function': '<S6>:1' */
  /*  Selects which command gets passed to the actuators based on the mode */
  /*  provided by upstream mode selection. Current modes are: */
  /*    mode_logic.do_nothing   = 0; */
  /*    mode_logic.bdot         = 1; */
  /*    mode_logic.slew         = 2; */
  /*    mode_logic.desat        = 3; */
  /*  */
  /*  FLAG output can be used to make sure the control output matches up with */
  /*  what is being commanded, before commands are passed to actuators. FLAG */
  /*  should match mode, unless something is wrong. */
  /* '<S6>:1:17' if mode == 0 */
  if (rtU.sc_mode == 0.0) {
    /* Outport: '<Root>/cmd_RW_out' */
    /* '<S6>:1:18' cmd_RW_out      = zeros(3,1); */
    /* '<S6>:1:19' cmd_MAG_out     = zeros(3,1); */
    rtY.cmd_RW_out[0] = 0.0;

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[0] = 0.0;

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[1] = 0.0;

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[1] = 0.0;

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[2] = 0.0;

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[2] = 0.0;

    /* Outport: '<Root>/ctrl_status' */
    /* '<S6>:1:20' FLAG            = 0; */
    rtY.ctrl_status = 0.0;
  } else if (rtU.sc_mode == 1.0) {
    /* Outport: '<Root>/cmd_RW_out' */
    /* '<S6>:1:21' elseif mode == 1 */
    /* '<S6>:1:22' cmd_RW_out      = zeros(3,1); */
    /* '<S6>:1:23' cmd_MAG_out     = cmd_bdot; */
    rtY.cmd_RW_out[0] = 0.0;

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[0] = rtb_MultiportSwitch2_idx_0;

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[1] = 0.0;

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[1] = rtb_MultiportSwitch2_idx_1;

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[2] = 0.0;

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[2] = rtb_MultiportSwitch2_idx_2;

    /* Outport: '<Root>/ctrl_status' */
    /* '<S6>:1:24' FLAG            = 1; */
    rtY.ctrl_status = 1.0;
  } else if (rtU.sc_mode == 2.0) {
    /* Outport: '<Root>/cmd_RW_out' */
    /* '<S6>:1:25' elseif mode == 2 */
    /* '<S6>:1:26' cmd_RW_out      = cmd_RW; */
    /* '<S6>:1:27' cmd_MAG_out     = zeros(3,1); */
    rtY.cmd_RW_out[0] = rtb_Gain[0];

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[0] = 0.0;

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[1] = rtb_Gain[1];

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[1] = 0.0;

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[2] = rtb_Gain[2];

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[2] = 0.0;

    /* Outport: '<Root>/ctrl_status' */
    /* '<S6>:1:28' FLAG            = 2; */
    rtY.ctrl_status = 2.0;
  } else if (rtU.sc_mode == 3.0) {
    /* Outport: '<Root>/cmd_RW_out' */
    /* '<S6>:1:29' elseif mode == 3 */
    /* '<S6>:1:30' cmd_RW_out      = cmd_RW; */
    /* '<S6>:1:31' cmd_MAG_out     = cmd_MAG; */
    rtY.cmd_RW_out[0] = rtb_Gain[0];

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[0] = rtDW.RateTransition[0];

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[1] = rtb_Gain[1];

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[1] = rtDW.RateTransition[1];

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[2] = rtb_Gain[2];

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[2] = rtDW.RateTransition[2];

    /* Outport: '<Root>/ctrl_status' */
    /* '<S6>:1:32' FLAG            = 3; */
    rtY.ctrl_status = 3.0;
  } else {
    /* Outport: '<Root>/ctrl_status' */
    /* '<S6>:1:33' else */
    /* '<S6>:1:34' FLAG = -1; */
    rtY.ctrl_status = -1.0;

    /* Outport: '<Root>/cmd_RW_out' */
    /* '<S6>:1:35' cmd_RW_out      = zeros(3,1); */
    /* '<S6>:1:36' cmd_MAG_out     = zeros(3,1); */
    rtY.cmd_RW_out[0] = 0.0;

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[0] = 0.0;

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[1] = 0.0;

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[1] = 0.0;

    /* Outport: '<Root>/cmd_RW_out' */
    rtY.cmd_RW_out[2] = 0.0;

    /* Outport: '<Root>/cmd_MAG_out' */
    rtY.cmd_MAG_out[2] = 0.0;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* RateTransition: '<S5>/Rate Transition4' */
  rtDW.RateTransition4_semaphoreTaken = 1;
  rtb_RateTransition4[0] = rtDW.RateTransition4_Buffer0[0];
  rtb_RateTransition4[1] = rtDW.RateTransition4_Buffer0[1];
  rtb_RateTransition4[2] = rtDW.RateTransition4_Buffer0[2];
  rtDW.RateTransition4_semaphoreTaken = 0;

  /* Gain: '<S4>/P gain' incorporates:
   *  Inport: '<Root>/sc_quat'
   *  Product: '<S16>/Product'
   *  Product: '<S16>/Product1'
   *  Product: '<S16>/Product2'
   *  Product: '<S16>/Product3'
   *  Product: '<S17>/Product'
   *  Product: '<S17>/Product1'
   *  Product: '<S17>/Product2'
   *  Product: '<S17>/Product3'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product1'
   *  Product: '<S18>/Product2'
   *  Product: '<S18>/Product3'
   *  Sum: '<S16>/Sum'
   *  Sum: '<S17>/Sum'
   *  Sum: '<S18>/Sum'
   */
  tmp[0] = ((-0.0 * rtU.sc_quat[0] + rtU.sc_quat[1]) + -0.0 * rtU.sc_quat[3]) -
    -0.0 * rtU.sc_quat[2];
  tmp[1] = ((rtU.sc_quat[2] - -0.0 * rtU.sc_quat[3]) + -0.0 * rtU.sc_quat[0]) +
    -0.0 * rtU.sc_quat[1];
  tmp[2] = ((-0.0 * rtU.sc_quat[2] + rtU.sc_quat[3]) - -0.0 * rtU.sc_quat[1]) +
    -0.0 * rtU.sc_quat[0];
  for (i = 0; i < 3; i++) {
    /* Product: '<S22>/Product' incorporates:
     *  Constant: '<S22>/Constant1'
     *  DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
     *  Update for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
     *  Sum: '<S22>/Sum'
     */
    rtb_Gain[i] = 0.0;
    rtb_Gain[i] += rtConstP.Constant1_Value[i] * rtb_RateTransition4[0];
    rtb_Gain[i] += rtConstP.Constant1_Value[i + 3] * rtb_RateTransition4[1];
    rtb_Gain[i] += rtConstP.Constant1_Value[i + 6] * rtb_RateTransition4[2];

    /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
     *  DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
     *  Update for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
     *  Gain: '<S4>/D gain'
     *  Gain: '<S4>/P gain'
     *  Sum: '<S4>/Sum'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE[i] += (-0.001114238870515 * tmp[i] +
      -0.00842325 * rtDW.RateTransition2_k[i]) * 0.1;

    /* Update for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' */
    rtDW.DiscreteTransferFcn_states[(int32_T)i] = rtb_Gain[(int32_T)i] -
      -0.93910136742429262 * rtDW.DiscreteTransferFcn_states[(int32_T)i];

    /* Update for UnitDelay: '<S5>/Unit Delay' incorporates:
     *  DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
     *  Update for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
     */
    rtDW.UnitDelay_DSTATE[i] = rtb_MultiportSwitch1[i];

    /* Update for UnitDelay: '<S21>/UD' incorporates:
     *  DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
     *  Update for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
     *
     * Block description for '<S21>/UD':
     *
     *  Store in Global RAM
     */
    rtDW.UD_DSTATE[i] = rtb_Sum_l[i];
  }
}

/* Model step function for TID2 */
void control_selection0_step2(void)    /* Sample time: [0.2s, 0.0s] */
{
  real_T rtb_MultiportSwitch[3];
  int32_T idxStart;
  int16_T i;
  int32_T idx1;
  int32_T idx2;
  real_T rtb_Sum_b[3];
  real_T rtb_Divide;
  real_T rtb_Product[3];

  /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
   *  Logic: '<S3>/Logical Operator'
   *  Logic: '<S3>/Logical Operator1'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  if (!((!(rtDW.RateTransition4 != 0.0)) && (rtDW.RateTransition3 != 0.0))) {
    rtb_MultiportSwitch[0] = rtDW.UnitDelay_DSTATE_e[0];
    rtb_MultiportSwitch[1] = rtDW.UnitDelay_DSTATE_e[1];
    rtb_MultiportSwitch[2] = rtDW.UnitDelay_DSTATE_e[2];
  } else {
    rtb_MultiportSwitch[0] = rtDW.RateTransition2[0];
    rtb_MultiportSwitch[1] = rtDW.RateTransition2[1];
    rtb_MultiportSwitch[2] = rtDW.RateTransition2[2];
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

  /* S-Function (sdsp2norm2): '<S3>/Normalization' */
  idxStart = 0L;
  i = 0;
  while (i < 1) {
    idx1 = idxStart;
    idx2 = idxStart;
    i = 0;
    while (i < 1) {
      rtb_Divide = 0.0;
      for (i = 0; i < 3; i++) {
        rtb_Divide += rtb_MultiportSwitch[idx1] * rtb_MultiportSwitch[idx1];
        idx1++;
      }

      rtb_Divide = 1.0 / (sqrt(rtb_Divide) + 1.0E-10);
      for (i = 0; i < 3; i++) {
        rtb_Sum_b[idx2] = rtb_MultiportSwitch[idx2] * rtb_Divide;
        idx2++;
      }

      i = 1;
    }

    idxStart++;
    i = 1;
  }

  /* End of S-Function (sdsp2norm2): '<S3>/Normalization' */

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/k '
   *  DotProduct: '<S3>/Dot Product'
   *  Sqrt: '<S3>/Sqrt'
   */
  rtb_Divide = 1.0 / sqrt((rtb_MultiportSwitch[0] * rtb_MultiportSwitch[0] +
    rtb_MultiportSwitch[1] * rtb_MultiportSwitch[1]) + rtb_MultiportSwitch[2] *
    rtb_MultiportSwitch[2]);

  /* Product: '<S3>/Product' incorporates:
   *  Product: '<S8>/i x j'
   *  Product: '<S8>/j x k'
   *  Product: '<S8>/k x i'
   *  Product: '<S9>/i x k'
   *  Product: '<S9>/j x i'
   *  Product: '<S9>/k x j'
   *  Sum: '<S7>/Sum'
   */
  rtb_Product[0] = (rtDW.RateTransition1[1] * rtb_Sum_b[2] -
                    rtDW.RateTransition1[2] * rtb_Sum_b[1]) * rtb_Divide;
  rtb_Product[1] = (rtDW.RateTransition1[2] * rtb_Sum_b[0] -
                    rtDW.RateTransition1[0] * rtb_Sum_b[2]) * rtb_Divide;
  rtb_Product[2] = (rtDW.RateTransition1[0] * rtb_Sum_b[1] -
                    rtDW.RateTransition1[1] * rtb_Sum_b[0]) * rtb_Divide;

  /* Update for RateTransition: '<S3>/Rate Transition' */
  rtDW.RateTransition_Buffer0[0] = rtb_Product[0];
  rtDW.RateTransition_Buffer0[1] = rtb_Product[1];
  rtDW.RateTransition_Buffer0[2] = rtb_Product[2];

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_e[0] = rtb_MultiportSwitch[0];
  rtDW.UnitDelay_DSTATE_e[1] = rtb_MultiportSwitch[1];
  rtDW.UnitDelay_DSTATE_e[2] = rtb_MultiportSwitch[2];
}

/* Model initialize function */
void control_selection0_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void control_selection0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
