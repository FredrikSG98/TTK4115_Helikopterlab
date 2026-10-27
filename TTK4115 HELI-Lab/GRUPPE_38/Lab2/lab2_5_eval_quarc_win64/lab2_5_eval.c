/*
 * lab2_5_eval.c
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

#include "lab2_5_eval.h"
#include "lab2_5_eval_private.h"
#include "lab2_5_eval_dt.h"

/* Block signals (default storage) */
B_lab2_5_eval_T lab2_5_eval_B;

/* Continuous states */
X_lab2_5_eval_T lab2_5_eval_X;

/* Block states (default storage) */
DW_lab2_5_eval_T lab2_5_eval_DW;

/* Real-time model */
static RT_MODEL_lab2_5_eval_T lab2_5_eval_M_;
RT_MODEL_lab2_5_eval_T *const lab2_5_eval_M = &lab2_5_eval_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(lab2_5_eval_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(lab2_5_eval_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (lab2_5_eval_M->Timing.TaskCounters.TID[1] == 0) {
    lab2_5_eval_M->Timing.RateInteraction.TID1_2 =
      (lab2_5_eval_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    lab2_5_eval_M->Timing.perTaskSampleHits[5] =
      lab2_5_eval_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (lab2_5_eval_M->Timing.TaskCounters.TID[2])++;
  if ((lab2_5_eval_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    lab2_5_eval_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  lab2_5_eval_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void lab2_5_eval_output0(void)         /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T tmp[5];
  real_T rtb_Sum2[2];
  real_T rtb_Backgain;
  real_T rtb_Frontgain;
  int32_T i;
  int32_T i_0;
  if (rtmIsMajorTimeStep(lab2_5_eval_M)) {
    /* set solver stop time */
    if (!(lab2_5_eval_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab2_5_eval_M->solverInfo,
                            ((lab2_5_eval_M->Timing.clockTickH0 + 1) *
        lab2_5_eval_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab2_5_eval_M->solverInfo,
                            ((lab2_5_eval_M->Timing.clockTick0 + 1) *
        lab2_5_eval_M->Timing.stepSize0 + lab2_5_eval_M->Timing.clockTickH0 *
        lab2_5_eval_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab2_5_eval_M)) {
    lab2_5_eval_M->Timing.t[0] = rtsiGetT(&lab2_5_eval_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab2_5_eval_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: lab2_5_eval/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(lab2_5_eval_DW.HILReadEncoderTimebase_Task,
        1, &lab2_5_eval_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          lab2_5_eval_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          lab2_5_eval_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          lab2_5_eval_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* RateTransition: '<S3>/Rate Transition: x' */
    if (lab2_5_eval_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S3>/Rate Transition: x' */
      lab2_5_eval_B.RateTransitionx = lab2_5_eval_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: x' */

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (lab2_5_eval_B.RateTransitionx > lab2_5_eval_P.DeadZonex_End) {
      rtb_Backgain = lab2_5_eval_B.RateTransitionx - lab2_5_eval_P.DeadZonex_End;
    } else if (lab2_5_eval_B.RateTransitionx >= lab2_5_eval_P.DeadZonex_Start) {
      rtb_Backgain = 0.0;
    } else {
      rtb_Backgain = lab2_5_eval_B.RateTransitionx -
        lab2_5_eval_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    lab2_5_eval_B.Joystick_gain_x = lab2_5_eval_P.Gainx_Gain * rtb_Backgain *
      lab2_5_eval_P.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (lab2_5_eval_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S3>/Rate Transition: y' */
      lab2_5_eval_B.RateTransitiony = lab2_5_eval_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (lab2_5_eval_B.RateTransitiony > lab2_5_eval_P.DeadZoney_End) {
      rtb_Backgain = lab2_5_eval_B.RateTransitiony - lab2_5_eval_P.DeadZoney_End;
    } else if (lab2_5_eval_B.RateTransitiony >= lab2_5_eval_P.DeadZoney_Start) {
      rtb_Backgain = 0.0;
    } else {
      rtb_Backgain = lab2_5_eval_B.RateTransitiony -
        lab2_5_eval_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    lab2_5_eval_B.Joystick_gain_y = lab2_5_eval_P.Gainy_Gain * rtb_Backgain *
      lab2_5_eval_P.Joystick_gain_y;

    /* Gain: '<Root>/Gain' incorporates:
     *  SignalConversion generated from: '<Root>/Gain'
     */
    lab2_5_eval_B.Gain[0] = 0.0;
    lab2_5_eval_B.Gain[0] += lab2_5_eval_P.F[0] * lab2_5_eval_B.Joystick_gain_x;
    lab2_5_eval_B.Gain[0] += lab2_5_eval_P.F[2] * lab2_5_eval_B.Joystick_gain_y;
    lab2_5_eval_B.Gain[1] = 0.0;
    lab2_5_eval_B.Gain[1] += lab2_5_eval_P.F[1] * lab2_5_eval_B.Joystick_gain_x;
    lab2_5_eval_B.Gain[1] += lab2_5_eval_P.F[3] * lab2_5_eval_B.Joystick_gain_y;

    /* Gain: '<S2>/Pitch: Count to rad' */
    lab2_5_eval_B.PitchCounttorad = lab2_5_eval_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S2>/Elevation: Count to rad'
     */
    lab2_5_eval_B.Sum = lab2_5_eval_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3 + lab2_5_eval_P.ELEV_OFFSET;
  }

  /* TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  lab2_5_eval_B.PitchTransferFcn = 0.0;
  lab2_5_eval_B.PitchTransferFcn += lab2_5_eval_P.PitchTransferFcn_C *
    lab2_5_eval_X.PitchTransferFcn_CSTATE;
  lab2_5_eval_B.PitchTransferFcn += lab2_5_eval_P.PitchTransferFcn_D *
    lab2_5_eval_B.PitchCounttorad;

  /* TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  lab2_5_eval_B.ElevationTransferFcn = 0.0;
  lab2_5_eval_B.ElevationTransferFcn += lab2_5_eval_P.ElevationTransferFcn_C *
    lab2_5_eval_X.ElevationTransferFcn_CSTATE;
  lab2_5_eval_B.ElevationTransferFcn += lab2_5_eval_P.ElevationTransferFcn_D *
    lab2_5_eval_B.Sum;

  /* SignalConversion generated from: '<Root>/Gain1' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  Integrator: '<Root>/Integrator1'
   */
  tmp[0] = lab2_5_eval_B.PitchCounttorad;
  tmp[1] = lab2_5_eval_B.PitchTransferFcn;
  tmp[2] = lab2_5_eval_B.ElevationTransferFcn;
  tmp[3] = lab2_5_eval_X.Integrator_CSTATE;
  tmp[4] = lab2_5_eval_X.Integrator1_CSTATE;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  for (i = 0; i < 2; i++) {
    rtb_Backgain = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Backgain += lab2_5_eval_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    rtb_Sum2[i] = lab2_5_eval_B.Gain[i] - rtb_Backgain;
  }

  /* End of Sum: '<Root>/Sum2' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Backgain = rtb_Sum2[0] + lab2_5_eval_P.Constant_Value;

  /* Sum: '<S1>/Add' */
  rtb_Frontgain = rtb_Backgain - rtb_Sum2[1];

  /* Sum: '<S1>/Subtract' */
  rtb_Backgain += rtb_Sum2[1];

  /* Gain: '<S1>/Back gain' */
  rtb_Backgain *= lab2_5_eval_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' */
  rtb_Frontgain *= lab2_5_eval_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(lab2_5_eval_M)) {
    /* Gain: '<S2>/Travel: Count to rad' */
    lab2_5_eval_B.TravelCounttorad = lab2_5_eval_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S2>/Travel: Transfer Fcn' */
  lab2_5_eval_B.TravelTransferFcn = 0.0;
  lab2_5_eval_B.TravelTransferFcn += lab2_5_eval_P.TravelTransferFcn_C *
    lab2_5_eval_X.TravelTransferFcn_CSTATE;
  lab2_5_eval_B.TravelTransferFcn += lab2_5_eval_P.TravelTransferFcn_D *
    lab2_5_eval_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(lab2_5_eval_M)) {
  }

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (rtb_Frontgain > lab2_5_eval_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S2>/Front motor: Saturation' */
    lab2_5_eval_B.FrontmotorSaturation =
      lab2_5_eval_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Frontgain < lab2_5_eval_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S2>/Front motor: Saturation' */
    lab2_5_eval_B.FrontmotorSaturation =
      lab2_5_eval_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Front motor: Saturation' */
    lab2_5_eval_B.FrontmotorSaturation = rtb_Frontgain;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (rtb_Backgain > lab2_5_eval_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S2>/Back motor: Saturation' */
    lab2_5_eval_B.BackmotorSaturation =
      lab2_5_eval_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Backgain < lab2_5_eval_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S2>/Back motor: Saturation' */
    lab2_5_eval_B.BackmotorSaturation =
      lab2_5_eval_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Back motor: Saturation' */
    lab2_5_eval_B.BackmotorSaturation = rtb_Backgain;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(lab2_5_eval_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: lab2_5_eval/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      lab2_5_eval_DW.HILWriteAnalog_Buffer[0] =
        lab2_5_eval_B.FrontmotorSaturation;
      lab2_5_eval_DW.HILWriteAnalog_Buffer[1] =
        lab2_5_eval_B.BackmotorSaturation;
      result = hil_write_analog(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILWriteAnalog_channels, 2,
        &lab2_5_eval_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
      }
    }

    /* Sum: '<Root>/Sum4' */
    lab2_5_eval_B.gamma_dot = lab2_5_eval_B.Joystick_gain_x -
      lab2_5_eval_B.PitchCounttorad;
  }

  /* Sum: '<Root>/Sum5' */
  lab2_5_eval_B.zeta_dot = lab2_5_eval_B.Joystick_gain_y -
    lab2_5_eval_B.ElevationTransferFcn;
}

/* Model update function for TID0 */
void lab2_5_eval_update0(void)         /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(lab2_5_eval_M)) {
    rt_ertODEUpdateContinuousStates(&lab2_5_eval_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2_5_eval_M->Timing.clockTick0)) {
    ++lab2_5_eval_M->Timing.clockTickH0;
  }

  lab2_5_eval_M->Timing.t[0] = rtsiGetSolverStopTime(&lab2_5_eval_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2_5_eval_M->Timing.clockTick1)) {
    ++lab2_5_eval_M->Timing.clockTickH1;
  }

  lab2_5_eval_M->Timing.t[1] = lab2_5_eval_M->Timing.clockTick1 *
    lab2_5_eval_M->Timing.stepSize1 + lab2_5_eval_M->Timing.clockTickH1 *
    lab2_5_eval_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void lab2_5_eval_derivatives(void)
{
  XDot_lab2_5_eval_T *_rtXdot;
  _rtXdot = ((XDot_lab2_5_eval_T *) lab2_5_eval_M->derivs);

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += lab2_5_eval_P.PitchTransferFcn_A *
    lab2_5_eval_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += lab2_5_eval_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += lab2_5_eval_P.ElevationTransferFcn_A *
    lab2_5_eval_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += lab2_5_eval_B.Sum;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = lab2_5_eval_B.gamma_dot;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = lab2_5_eval_B.zeta_dot;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += lab2_5_eval_P.TravelTransferFcn_A *
    lab2_5_eval_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += lab2_5_eval_B.TravelCounttorad;
}

/* Model output function for TID2 */
void lab2_5_eval_output2(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: lab2_5_eval/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2_5_eval_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(lab2_5_eval_DW.GameController_Controller,
        &state, &new_data);
      if (result < 0) {
        new_data = false;
      }

      rtb_GameController_o4 = state.x;
      rtb_GameController_o5 = state.y;
    } else {
      rtb_GameController_o4 = 0;
      rtb_GameController_o5 = 0;
    }
  }

  /* RateTransition: '<S3>/Rate Transition: x' */
  lab2_5_eval_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S3>/Rate Transition: y' */
  lab2_5_eval_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void lab2_5_eval_update2(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2_5_eval_M->Timing.clockTick2)) {
    ++lab2_5_eval_M->Timing.clockTickH2;
  }

  lab2_5_eval_M->Timing.t[2] = lab2_5_eval_M->Timing.clockTick2 *
    lab2_5_eval_M->Timing.stepSize2 + lab2_5_eval_M->Timing.clockTickH2 *
    lab2_5_eval_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void lab2_5_eval_output(int_T tid)
{
  switch (tid) {
   case 0 :
    lab2_5_eval_output0();
    break;

   case 2 :
    lab2_5_eval_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void lab2_5_eval_update(int_T tid)
{
  switch (tid) {
   case 0 :
    lab2_5_eval_update0();
    break;

   case 2 :
    lab2_5_eval_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void lab2_5_eval_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab2_5_eval/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &lab2_5_eval_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab2_5_eval_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(lab2_5_eval_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
      return;
    }

    if ((lab2_5_eval_P.HILInitialize_AIPStart && !is_switching) ||
        (lab2_5_eval_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &lab2_5_eval_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (lab2_5_eval_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &lab2_5_eval_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = lab2_5_eval_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILInitialize_AIChannels, 8U,
        &lab2_5_eval_DW.HILInitialize_AIMinimums[0],
        &lab2_5_eval_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_5_eval_P.HILInitialize_AOPStart && !is_switching) ||
        (lab2_5_eval_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &lab2_5_eval_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (lab2_5_eval_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &lab2_5_eval_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = lab2_5_eval_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILInitialize_AOChannels, 8U,
        &lab2_5_eval_DW.HILInitialize_AOMinimums[0],
        &lab2_5_eval_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_5_eval_P.HILInitialize_AOStart && !is_switching) ||
        (lab2_5_eval_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2_5_eval_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2_5_eval_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILInitialize_AOChannels, 8U,
        &lab2_5_eval_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }
    }

    if (lab2_5_eval_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2_5_eval_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2_5_eval_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (lab2_5_eval_DW.HILInitialize_Card,
         lab2_5_eval_P.HILInitialize_AOChannels, 8U,
         &lab2_5_eval_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_5_eval_P.HILInitialize_EIPStart && !is_switching) ||
        (lab2_5_eval_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &lab2_5_eval_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = lab2_5_eval_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &lab2_5_eval_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_5_eval_P.HILInitialize_EIStart && !is_switching) ||
        (lab2_5_eval_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &lab2_5_eval_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = lab2_5_eval_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILInitialize_EIChannels, 8U,
        &lab2_5_eval_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_5_eval_P.HILInitialize_POPStart && !is_switching) ||
        (lab2_5_eval_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab2_5_eval_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab2_5_eval_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &lab2_5_eval_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          lab2_5_eval_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &lab2_5_eval_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            lab2_5_eval_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            lab2_5_eval_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              lab2_5_eval_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            lab2_5_eval_DW.HILInitialize_POSortedChans[7U - num_frequency_modes]
              = (p_HILInitialize_POChannels[i1]);
            lab2_5_eval_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes]
              = lab2_5_eval_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(lab2_5_eval_DW.HILInitialize_Card,
          &lab2_5_eval_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &lab2_5_eval_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(lab2_5_eval_DW.HILInitialize_Card,
          &lab2_5_eval_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &lab2_5_eval_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab2_5_eval_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab2_5_eval_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &lab2_5_eval_DW.HILInitialize_POAlignValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = lab2_5_eval_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &lab2_5_eval_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = lab2_5_eval_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &lab2_5_eval_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &lab2_5_eval_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &lab2_5_eval_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &lab2_5_eval_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = lab2_5_eval_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &lab2_5_eval_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_5_eval_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILInitialize_POChannels, 8U,
        &lab2_5_eval_DW.HILInitialize_POSortedFreqs[0],
        &lab2_5_eval_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_5_eval_P.HILInitialize_POStart && !is_switching) ||
        (lab2_5_eval_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2_5_eval_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_5_eval_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(lab2_5_eval_DW.HILInitialize_Card,
        lab2_5_eval_P.HILInitialize_POChannels, 8U,
        &lab2_5_eval_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }
    }

    if (lab2_5_eval_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2_5_eval_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_5_eval_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (lab2_5_eval_DW.HILInitialize_Card,
         lab2_5_eval_P.HILInitialize_POChannels, 8U,
         &lab2_5_eval_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: lab2_5_eval/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(lab2_5_eval_DW.HILInitialize_Card,
      lab2_5_eval_P.HILReadEncoderTimebase_SamplesI,
      lab2_5_eval_P.HILReadEncoderTimebase_Channels, 3,
      &lab2_5_eval_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (lab2_5_eval_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (lab2_5_eval_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  lab2_5_eval_B.RateTransitionx = lab2_5_eval_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  lab2_5_eval_B.RateTransitiony = lab2_5_eval_P.RateTransitiony_InitialConditio;

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: lab2_5_eval/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2_5_eval_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (lab2_5_eval_P.GameController_ControllerNumber,
         lab2_5_eval_P.GameController_BufferSize, deadzone, saturation,
         lab2_5_eval_P.GameController_AutoCenter, 0, 1.0,
         &lab2_5_eval_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
  lab2_5_eval_DW.RateTransitionx_Buffer0 =
    lab2_5_eval_P.RateTransitionx_InitialConditio;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
  lab2_5_eval_DW.RateTransitiony_Buffer0 =
    lab2_5_eval_P.RateTransitiony_InitialConditio;

  /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  lab2_5_eval_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  lab2_5_eval_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  lab2_5_eval_X.Integrator_CSTATE = lab2_5_eval_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  lab2_5_eval_X.Integrator1_CSTATE = lab2_5_eval_P.Integrator1_IC;

  /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  lab2_5_eval_X.TravelTransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void lab2_5_eval_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab2_5_eval/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(lab2_5_eval_DW.HILInitialize_Card);
    hil_monitor_stop_all(lab2_5_eval_DW.HILInitialize_Card);
    is_switching = false;
    if ((lab2_5_eval_P.HILInitialize_AOTerminate && !is_switching) ||
        (lab2_5_eval_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2_5_eval_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2_5_eval_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((lab2_5_eval_P.HILInitialize_POTerminate && !is_switching) ||
        (lab2_5_eval_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2_5_eval_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_5_eval_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(lab2_5_eval_DW.HILInitialize_Card
                         , lab2_5_eval_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , lab2_5_eval_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &lab2_5_eval_DW.HILInitialize_AOVoltages[0]
                         , &lab2_5_eval_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(lab2_5_eval_DW.HILInitialize_Card,
            lab2_5_eval_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &lab2_5_eval_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(lab2_5_eval_DW.HILInitialize_Card,
            lab2_5_eval_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &lab2_5_eval_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2_5_eval_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(lab2_5_eval_DW.HILInitialize_Card);
    hil_monitor_delete_all(lab2_5_eval_DW.HILInitialize_Card);
    hil_close(lab2_5_eval_DW.HILInitialize_Card);
    lab2_5_eval_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: lab2_5_eval/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2_5_eval_P.GameController_Enabled) {
      game_controller_close(lab2_5_eval_DW.GameController_Controller);
      lab2_5_eval_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab2_5_eval_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab2_5_eval_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  lab2_5_eval_initialize();
}

void MdlTerminate(void)
{
  lab2_5_eval_terminate();
}

/* Registration function */
RT_MODEL_lab2_5_eval_T *lab2_5_eval(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab2_5_eval_M, 0,
                sizeof(RT_MODEL_lab2_5_eval_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab2_5_eval_M->solverInfo,
                          &lab2_5_eval_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab2_5_eval_M->solverInfo, &rtmGetTPtr(lab2_5_eval_M));
    rtsiSetStepSizePtr(&lab2_5_eval_M->solverInfo,
                       &lab2_5_eval_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab2_5_eval_M->solverInfo, &lab2_5_eval_M->derivs);
    rtsiSetContStatesPtr(&lab2_5_eval_M->solverInfo, (real_T **)
                         &lab2_5_eval_M->contStates);
    rtsiSetNumContStatesPtr(&lab2_5_eval_M->solverInfo,
      &lab2_5_eval_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab2_5_eval_M->solverInfo,
      &lab2_5_eval_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab2_5_eval_M->solverInfo,
      &lab2_5_eval_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab2_5_eval_M->solverInfo,
      &lab2_5_eval_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab2_5_eval_M->solverInfo, (&rtmGetErrorStatus
      (lab2_5_eval_M)));
    rtsiSetRTModelPtr(&lab2_5_eval_M->solverInfo, lab2_5_eval_M);
  }

  rtsiSetSimTimeStep(&lab2_5_eval_M->solverInfo, MAJOR_TIME_STEP);
  lab2_5_eval_M->intgData.f[0] = lab2_5_eval_M->odeF[0];
  lab2_5_eval_M->contStates = ((real_T *) &lab2_5_eval_X);
  rtsiSetSolverData(&lab2_5_eval_M->solverInfo, (void *)&lab2_5_eval_M->intgData);
  rtsiSetSolverName(&lab2_5_eval_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab2_5_eval_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab2_5_eval_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab2_5_eval_M->Timing.sampleTimes = (&lab2_5_eval_M->
      Timing.sampleTimesArray[0]);
    lab2_5_eval_M->Timing.offsetTimes = (&lab2_5_eval_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    lab2_5_eval_M->Timing.sampleTimes[0] = (0.0);
    lab2_5_eval_M->Timing.sampleTimes[1] = (0.002);
    lab2_5_eval_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    lab2_5_eval_M->Timing.offsetTimes[0] = (0.0);
    lab2_5_eval_M->Timing.offsetTimes[1] = (0.0);
    lab2_5_eval_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab2_5_eval_M, &lab2_5_eval_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab2_5_eval_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = lab2_5_eval_M->Timing.perTaskSampleHitsArray;
    lab2_5_eval_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    lab2_5_eval_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab2_5_eval_M, -1);
  lab2_5_eval_M->Timing.stepSize0 = 0.002;
  lab2_5_eval_M->Timing.stepSize1 = 0.002;
  lab2_5_eval_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  lab2_5_eval_M->Sizes.checksums[0] = (1685999813U);
  lab2_5_eval_M->Sizes.checksums[1] = (4196808515U);
  lab2_5_eval_M->Sizes.checksums[2] = (1886199115U);
  lab2_5_eval_M->Sizes.checksums[3] = (3753272970U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab2_5_eval_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab2_5_eval_M->extModeInfo,
      &lab2_5_eval_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab2_5_eval_M->extModeInfo,
                        lab2_5_eval_M->Sizes.checksums);
    rteiSetTPtr(lab2_5_eval_M->extModeInfo, rtmGetTPtr(lab2_5_eval_M));
  }

  lab2_5_eval_M->solverInfoPtr = (&lab2_5_eval_M->solverInfo);
  lab2_5_eval_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lab2_5_eval_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lab2_5_eval_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  lab2_5_eval_M->blockIO = ((void *) &lab2_5_eval_B);

  {
    lab2_5_eval_B.RateTransitionx = 0.0;
    lab2_5_eval_B.Joystick_gain_x = 0.0;
    lab2_5_eval_B.RateTransitiony = 0.0;
    lab2_5_eval_B.Joystick_gain_y = 0.0;
    lab2_5_eval_B.Gain[0] = 0.0;
    lab2_5_eval_B.Gain[1] = 0.0;
    lab2_5_eval_B.PitchCounttorad = 0.0;
    lab2_5_eval_B.PitchTransferFcn = 0.0;
    lab2_5_eval_B.Sum = 0.0;
    lab2_5_eval_B.ElevationTransferFcn = 0.0;
    lab2_5_eval_B.TravelCounttorad = 0.0;
    lab2_5_eval_B.TravelTransferFcn = 0.0;
    lab2_5_eval_B.FrontmotorSaturation = 0.0;
    lab2_5_eval_B.BackmotorSaturation = 0.0;
    lab2_5_eval_B.gamma_dot = 0.0;
    lab2_5_eval_B.zeta_dot = 0.0;
  }

  /* parameters */
  lab2_5_eval_M->defaultParam = ((real_T *)&lab2_5_eval_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab2_5_eval_X;
    lab2_5_eval_M->contStates = (x);
    (void) memset((void *)&lab2_5_eval_X, 0,
                  sizeof(X_lab2_5_eval_T));
  }

  /* states (dwork) */
  lab2_5_eval_M->dwork = ((void *) &lab2_5_eval_DW);
  (void) memset((void *)&lab2_5_eval_DW, 0,
                sizeof(DW_lab2_5_eval_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_5_eval_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_5_eval_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_5_eval_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_5_eval_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_5_eval_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_5_eval_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_5_eval_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_5_eval_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  lab2_5_eval_DW.RateTransitionx_Buffer0 = 0.0;
  lab2_5_eval_DW.RateTransitiony_Buffer0 = 0.0;
  lab2_5_eval_DW.HILWriteAnalog_Buffer[0] = 0.0;
  lab2_5_eval_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab2_5_eval_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab2_5_eval_M->Sizes.numContStates = (5);/* Number of continuous states */
  lab2_5_eval_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab2_5_eval_M->Sizes.numY = (0);     /* Number of model outputs */
  lab2_5_eval_M->Sizes.numU = (0);     /* Number of model inputs */
  lab2_5_eval_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab2_5_eval_M->Sizes.numSampTimes = (3);/* Number of sample times */
  lab2_5_eval_M->Sizes.numBlocks = (45);/* Number of blocks */
  lab2_5_eval_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  lab2_5_eval_M->Sizes.numBlockPrms = (154);/* Sum of parameter "widths" */
  return lab2_5_eval_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
