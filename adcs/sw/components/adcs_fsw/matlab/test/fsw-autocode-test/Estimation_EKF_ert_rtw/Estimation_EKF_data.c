/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Estimation_EKF_data.c
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

#include "Estimation_EKF.h"

/* Invariant block signals (auto storage) */
const ConstB rtConstB = {
  { 1.0033333333333333E-7, 0.0, 0.0, 5.0000000000000009E-9, 0.0, 0.0, 0.0,
    1.0033333333333333E-7, 0.0, 0.0, 5.0000000000000009E-9, 0.0, 0.0, 0.0,
    1.0033333333333333E-7, 0.0, 0.0, 5.0000000000000009E-9,
    5.0000000000000009E-9, 0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0,
    5.0000000000000009E-9, 0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0,
    5.0000000000000009E-9, 0.0, 0.0, 1.0E-7 }/* '<S3>/Product1' */
};

/* Constant parameters (auto storage) */
const ConstP rtConstP = {
  /* Expression: fsw_params.estimation.ic.error_cov
   * Referenced by: '<S1>/Unit Delay2'
   */
  { 0.0027415567780803771, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0027415567780803771,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0027415567780803771, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 2.7415567780803768E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.7415567780803768E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.7415567780803768E-5 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
