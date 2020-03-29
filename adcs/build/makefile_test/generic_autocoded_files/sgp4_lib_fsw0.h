/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sgp4_lib_fsw0.h
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

#ifndef RTW_HEADER_sgp4_lib_fsw0_h_
#define RTW_HEADER_sgp4_lib_fsw0_h_
#include <stddef.h>
#include <math.h>
#ifndef sgp4_lib_fsw0_COMMON_INCLUDES_
# define sgp4_lib_fsw0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* sgp4_lib_fsw0_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T JD_utc_J2000;                 /* '<Root>/JD_J2000_utc' */
  real_T orbit_tle[9];                 /* '<Root>/orbit_tle' */
  real_T teme_to_gcrf[9];              /* '<Root>/teme_2_eci' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T pos_eci_m[3];                 /* '<Root>/pos_eci_m' */
  real_T vel_eci_mps[3];               /* '<Root>/vel_eci_mps' */
  real_T SGP4_FLAG;                    /* '<Root>/SGP4_FLAG' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void sgp4_lib_fsw0_initialize(void);
extern void sgp4_lib_fsw0_step(void);

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
 * hilite_system('sgp4_unit_test/sgp4_lib_fsw')    - opens subsystem sgp4_unit_test/sgp4_lib_fsw
 * hilite_system('sgp4_unit_test/sgp4_lib_fsw/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sgp4_unit_test'
 * '<S1>'   : 'sgp4_unit_test/sgp4_lib_fsw'
 * '<S2>'   : 'sgp4_unit_test/sgp4_lib_fsw/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_sgp4_lib_fsw0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
