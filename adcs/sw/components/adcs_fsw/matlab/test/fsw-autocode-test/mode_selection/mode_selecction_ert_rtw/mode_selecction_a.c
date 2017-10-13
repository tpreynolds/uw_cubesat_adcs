/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mode_selecction_a.c
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

#include "mode_selecction_a.h"

/* Include model header file for global data */
#include "mode_selecction.h"
#include "mode_selecction_private.h"

/* Forward declaration for local functions */
static real_T norm(const real_T x[4]);

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static real_T norm(const real_T x[4])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[3]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Output and update for atomic system: '<Root>/mode_selecction' */
void mode_selecction_a(const real_T rtu_RW_RPM[3], real_T rtu_sc_in_sun, const
  real_T rtu_omega_body_radps[3], const real_T rtu_quat_commanded[4], real_T
  *rty_sc_mode)
{
  int16_T sc_mode;
  real_T y;
  real_T absx;
  int16_T k;
  real_T absxk;
  real_T t;
  boolean_T exitg1;

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   */
  /*  Main FSW Mode Selector */
  /*    UW HuskySat-1, ADCS Team */
  /*    Last Updated: T. Reynolds 8.5.17 */
  /* MATLAB Function 'mode_selecction/MATLAB Function': '<S2>:1' */
  /*  Chooses control mode based on sensor and actuator data. */
  /*    mode_logic.do_nothing   = 0; */
  /*    mode_logic.bdot         = 1; */
  /*    mode_logic.slew         = 2; */
  /*    mode_logic.desat        = 3; */
  /* '<S2>:1:13' tol     = 1e-2; */
  /* '<S2>:1:15' sc_mode     = 1; */
  sc_mode = 1;

  /* '<S2>:1:17' if (1-tol <= norm(quat_commanded)) && (norm(quat_commanded) <= 1+tol) */
  if ((0.99 <= norm(rtu_quat_commanded)) && (norm(rtu_quat_commanded) <= 1.01))
  {
    /* '<S2>:1:18' sc_mode    = 2; */
    sc_mode = 2;
  }

  /* '<S2>:1:21' if norm(RW_RPM,inf) >= RW_RPM_thresh */
  y = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    absx = fabs(rtu_RW_RPM[k]);
    if (rtIsNaN(absx)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (absx > y) {
        y = absx;
      }

      k++;
    }
  }

  if (y >= 10000.0) {
    /* '<S2>:1:22' sc_mode    = 3; */
    sc_mode = 3;
  }

  /* '<S2>:1:25' if norm(omega_body_radps) >= omega_thresh */
  absx = 2.2250738585072014E-308;
  absxk = fabs(rtu_omega_body_radps[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    absx = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(rtu_omega_body_radps[1]);
  if (absxk > absx) {
    t = absx / absxk;
    y = y * t * t + 1.0;
    absx = absxk;
  } else {
    t = absxk / absx;
    y += t * t;
  }

  absxk = fabs(rtu_omega_body_radps[2]);
  if (absxk > absx) {
    t = absx / absxk;
    y = y * t * t + 1.0;
    absx = absxk;
  } else {
    t = absxk / absx;
    y += t * t;
  }

  y = absx * sqrt(y);
  if (y >= 0.12) {
    /* '<S2>:1:26' sc_mode = 1; */
    sc_mode = 1;
  }

  /* '<S2>:1:29' if sc_in_sun == 0 */
  if (rtu_sc_in_sun == 0.0) {
    /* '<S2>:1:30' sc_mode    = 0; */
    sc_mode = 0;
  }

  *rty_sc_mode = sc_mode;

  /* End of MATLAB Function: '<S1>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
