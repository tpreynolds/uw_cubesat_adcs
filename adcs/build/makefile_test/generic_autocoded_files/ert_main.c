/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'sgp4_lib_fsw0'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Mar 29 15:15:33 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (8-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "sgp4_lib_fsw0.h"             /* Model's header file */
#include "rtwtypes.h"

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  sgp4_lib_fsw0_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  sgp4_lib_fsw0_initialize();

  rtU.JD_utc_J2000 = 7220.9952105745;
  rtU.orbit_tle[0] = 19.0;
  rtU.orbit_tle[1] = 7220.9945161301;
  rtU.orbit_tle[2] = 0.0001027;
  rtU.orbit_tle[3] = 51.6432;
  rtU.orbit_tle[4] = 154.4443;
  rtU.orbit_tle[5] = 0.0006957;
  rtU.orbit_tle[6] = 130.5924;
  rtU.orbit_tle[7] = 229.5833;
  rtU.orbit_tle[8] = 15.5022591;
  rtU.teme_to_gcrf[0] = 1.0;
  rtU.teme_to_gcrf[1] = -0.04421;
  rtU.teme_to_gcrf[2] = -0.001887;
  rtU.teme_to_gcrf[3] = 0.00421;
  rtU.teme_to_gcrf[4] = 1.0;
  rtU.teme_to_gcrf[5] = 2.678e-6;
  rtU.teme_to_gcrf[6] = 0.001887;
  rtU.teme_to_gcrf[7] = -1.102e-5;
  rtU.teme_to_gcrf[8] = 1.0;

  rt_OneStep();

  for (int i = 0; i < 3; ++i) {
    printf("rtY.pos_eci_m[%d] = %20.12f\n",i,rtY.pos_eci_m[i]);
  }
  for (int i = 0; i < 3; ++i) {
    printf("rtY.vel_eci_mps[%d] = %20.12f\n",i,rtY.vel_eci_mps[i]);
  }
  printf("rtY.SGP4_FLAG = %f\n",rtY.SGP4_FLAG);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.002 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep();
   */
  printf("I'm working!\n");
  // fflush((NULL));
  // while (rtmGetErrorStatus(rtM) == (NULL)) {
  //   /*  Perform other application tasks here */
  // }

  /* Disable rt_OneStep() here */
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
