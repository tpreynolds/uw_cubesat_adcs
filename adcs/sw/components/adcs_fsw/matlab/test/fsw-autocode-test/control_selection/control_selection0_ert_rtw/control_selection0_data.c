/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_selection0_data.c
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

/* Invariant block signals (auto storage) */
const ConstB rtConstB = {
  { 558.659217877095, 0.0, 0.0, 0.0, 558.659217877095, 0.0, 0.0, 0.0,
    558.659217877095 }                 /* '<S19>/Product' */
};

/* Constant parameters (auto storage) */
const ConstP rtConstP = {
  /* Expression: fsw_params.bdot.gain_matrix
   * Referenced by: '<S5>/gain matrix'
   */
  { -100000.0, 0.0, 0.0, 0.0, -100000.0, 0.0, 0.0, 0.0, -88235.294117647049 },

  /* Expression: fsw_params.sensor_processing.magnetometer.process_matrix
   * Referenced by: '<S22>/Constant1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
