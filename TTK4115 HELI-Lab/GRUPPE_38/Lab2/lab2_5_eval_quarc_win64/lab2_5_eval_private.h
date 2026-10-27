/*
 * lab2_5_eval_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab2_5_eval".
 *
 * Model version              : 11.7
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Sep 15 12:31:10 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_lab2_5_eval_private_h_
#define RTW_HEADER_lab2_5_eval_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "lab2_5_eval.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
void lab2_5_eval_output0(void);
void lab2_5_eval_update0(void);
void lab2_5_eval_output2(void);
void lab2_5_eval_update2(void);        /* private model entry point functions */
extern void lab2_5_eval_derivatives(void);

#endif                                 /* RTW_HEADER_lab2_5_eval_private_h_ */
