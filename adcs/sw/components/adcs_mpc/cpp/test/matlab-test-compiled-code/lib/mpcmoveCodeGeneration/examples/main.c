/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 02-Nov-2017 18:25:03
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "mpcmoveCodeGeneration.h"
#include "main.h"
#include "mpcmoveCodeGeneration_terminate.h"
#include "mpcmoveCodeGeneration_initialize.h"

/* Function Declarations */
static void argInit_1x7_real_T(double result[7]);
static void argInit_3x1_real_T(double result[3]);
static void argInit_7x1_real_T(double result[7]);
static double argInit_real_T(void);
static void argInit_struct1_T(struct1_T *result);
static void argInit_struct2_T(struct2_T *result);
static void argInit_struct3_T(struct3_T *result);
static void main_mpcmoveCodeGeneration(void);

/* Function Definitions */

/*
 * Arguments    : double result[7]
 * Return Type  : void
 */
static void argInit_1x7_real_T(double result[7])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[3]
 * Return Type  : void
 */
static void argInit_3x1_real_T(double result[3])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 3; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[7]
 * Return Type  : void
 */
static void argInit_7x1_real_T(double result[7])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 7; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : struct1_T *result
 * Return Type  : void
 */
static void argInit_struct1_T(struct1_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_7x1_real_T(result->Plant);
  argInit_3x1_real_T(result->LastMove);
}

/*
 * Arguments    : struct2_T *result
 * Return Type  : void
 */
static void argInit_struct2_T(struct2_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_struct3_T(&result->signals);
}

/*
 * Arguments    : struct3_T *result
 * Return Type  : void
 */
static void argInit_struct3_T(struct3_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_7x1_real_T(result->ym);
  argInit_1x7_real_T(result->ref);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_mpcmoveCodeGeneration(void)
{
  struct1_T mpcmovestate;
  struct2_T r0;
  double u[3];
  struct7_T Info;

  /* Initialize function 'mpcmoveCodeGeneration' input arguments. */
  /* Initialize function input argument 'mpcmovestate'. */
  /* Initialize function input argument 'mpcmovedata'. */
  /* Call the entry-point 'mpcmoveCodeGeneration'. */
  argInit_struct1_T(&mpcmovestate);
  argInit_struct2_T(&r0);
  mpcmoveCodeGeneration(&mpcmovestate, &r0, u, &Info);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  mpcmoveCodeGeneration_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_mpcmoveCodeGeneration();

  /* Terminate the application.
     You do not need to do this more than one time. */
  mpcmoveCodeGeneration_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
