/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_selecction_a.h
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

#ifndef RTW_HEADER_mode_selecction_a_h_
#define RTW_HEADER_mode_selecction_a_h_
#include <math.h>
#ifndef mode_selecction_COMMON_INCLUDES_
# define mode_selecction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* mode_selecction_COMMON_INCLUDES_ */

#include "mode_selecction_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

extern void mode_selecction_a(const real_T rtu_RW_RPM[3], real_T rtu_sc_in_sun,
  const real_T rtu_omega_body_radps[3], const real_T rtu_quat_commanded[4],
  real_T *rty_sc_mode);

#endif                                 /* RTW_HEADER_mode_selecction_a_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
