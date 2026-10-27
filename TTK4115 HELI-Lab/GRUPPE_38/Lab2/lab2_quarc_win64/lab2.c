/*
 * lab2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab2".
 *
 * Model version              : 11.2
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Sep 15 09:53:29 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab2.h"
#include "lab2_private.h"
#include "lab2_dt.h"

/* Block signals (default storage) */
B_lab2_T lab2_B;

/* Continuous states */
X_lab2_T lab2_X;

/* Block states (default storage) */
DW_lab2_T lab2_DW;

/* Real-time model */
static RT_MODEL_lab2_T lab2_M_;
RT_MODEL_lab2_T *const lab2_M = &lab2_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(lab2_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(lab2_M, 2);
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
  if (lab2_M->Timing.TaskCounters.TID[1] == 0) {
    lab2_M->Timing.RateInteraction.TID1_2 = (lab2_M->Timing.TaskCounters.TID[2] ==
      0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    lab2_M->Timing.perTaskSampleHits[5] = lab2_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (lab2_M->Timing.TaskCounters.TID[2])++;
  if ((lab2_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    lab2_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  lab2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void lab2_output0(void)                /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_TmpSignalConversionAtToFile[6];
  real_T rtb_DeadZoney;
  real_T rtb_Sum2[2];
  real_T rtb_Backgain;
  real_T rtb_Frontgain;
  real_T tmp;
  int32_T i;
  if (rtmIsMajorTimeStep(lab2_M)) {
    /* set solver stop time */
    if (!(lab2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab2_M->solverInfo, ((lab2_M->Timing.clockTickH0 +
        1) * lab2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab2_M->solverInfo, ((lab2_M->Timing.clockTick0 + 1)
        * lab2_M->Timing.stepSize0 + lab2_M->Timing.clockTickH0 *
        lab2_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab2_M)) {
    lab2_M->Timing.t[0] = rtsiGetT(&lab2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab2_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: lab2/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(lab2_DW.HILReadEncoderTimebase_Task, 1,
        &lab2_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 = lab2_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 = lab2_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = lab2_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S2>/Pitch: Count to rad' */
    lab2_B.PitchCounttorad = lab2_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S2>/Elevation: Count to rad'
     */
    lab2_B.Sum = lab2_P.ElevationCounttorad_Gain * rtb_DeadZoney +
      lab2_P.ELEV_OFFSET;
  }

  /* TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  lab2_B.PitchTransferFcn = 0.0;
  lab2_B.PitchTransferFcn += lab2_P.PitchTransferFcn_C *
    lab2_X.PitchTransferFcn_CSTATE;
  lab2_B.PitchTransferFcn += lab2_P.PitchTransferFcn_D * lab2_B.PitchCounttorad;

  /* TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  lab2_B.ElevationTransferFcn = 0.0;
  lab2_B.ElevationTransferFcn += lab2_P.ElevationTransferFcn_C *
    lab2_X.ElevationTransferFcn_CSTATE;
  lab2_B.ElevationTransferFcn += lab2_P.ElevationTransferFcn_D * lab2_B.Sum;

  /* Step: '<Root>/Step2' incorporates:
   *  Step: '<Root>/Step'
   *  Step: '<Root>/Step1'
   *  Step: '<Root>/Step3'
   */
  rtb_Backgain = lab2_M->Timing.t[0];
  if (rtb_Backgain < lab2_P.Step2_Time) {
    rtb_Frontgain = lab2_P.Step2_Y0;
  } else {
    rtb_Frontgain = lab2_P.Step2_YFinal;
  }

  /* End of Step: '<Root>/Step2' */

  /* Step: '<Root>/Step3' */
  if (rtb_Backgain < lab2_P.Step3_Time) {
    tmp = lab2_P.Step3_Y0;
  } else {
    tmp = lab2_P.Step3_YFinal;
  }

  /* Sum: '<Root>/Sum3' */
  lab2_B.p_c = rtb_Frontgain - tmp;

  /* Step: '<Root>/Step' */
  if (rtb_Backgain < lab2_P.Step_Time) {
    rtb_Frontgain = lab2_P.Step_Y0;
  } else {
    rtb_Frontgain = lab2_P.Step_YFinal;
  }

  /* Step: '<Root>/Step1' */
  if (rtb_Backgain < lab2_P.Step1_Time) {
    rtb_Backgain = lab2_P.Step1_Y0;
  } else {
    rtb_Backgain = lab2_P.Step1_YFinal;
  }

  /* Sum: '<Root>/Sum1' */
  lab2_B.e_c_dot = rtb_Frontgain - rtb_Backgain;
  if (rtmIsMajorTimeStep(lab2_M)) {
    /* SignalConversion generated from: '<Root>/To File1' */
    rtb_TmpSignalConversionAtToFile[0] = lab2_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[1] = lab2_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[2] = lab2_B.Sum;
    rtb_TmpSignalConversionAtToFile[3] = lab2_B.ElevationTransferFcn;
    rtb_TmpSignalConversionAtToFile[4] = lab2_B.p_c;
    rtb_TmpSignalConversionAtToFile[5] = lab2_B.e_c_dot;

    /* ToFile: '<Root>/To File1' */
    if (rtmIsMajorTimeStep(lab2_M)) {
      if (rtmIsMajorTimeStep(lab2_M) ) {
        {
          if (!(++lab2_DW.ToFile1_IWORK.Decimation % 1) &&
              (lab2_DW.ToFile1_IWORK.Count * (6 + 1)) + 1 < 100000000 ) {
            FILE *fp = (FILE *) lab2_DW.ToFile1_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[6 + 1];
              lab2_DW.ToFile1_IWORK.Decimation = 0;
              u[0] = lab2_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFile[0];
              u[2] = rtb_TmpSignalConversionAtToFile[1];
              u[3] = rtb_TmpSignalConversionAtToFile[2];
              u[4] = rtb_TmpSignalConversionAtToFile[3];
              u[5] = rtb_TmpSignalConversionAtToFile[4];
              u[6] = rtb_TmpSignalConversionAtToFile[5];
              if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
                rtmSetErrorStatus(lab2_M,
                                  "Error writing to MAT-file 3_treg_Vs.mat");
                return;
              }

              if (((++lab2_DW.ToFile1_IWORK.Count) * (6 + 1))+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file 3_treg_Vs.mat.\n");
              }
            }
          }
        }
      }
    }
  }

  for (i = 0; i < 2; i++) {
    /* Sum: '<Root>/Sum2' incorporates:
     *  Gain: '<Root>/Gain'
     *  Gain: '<Root>/Gain1'
     *  SignalConversion generated from: '<Root>/Gain1'
     *  SignalConversion generated from: '<Root>/Gain'
     */
    rtb_Sum2[i] = (lab2_P.F[i + 2] * lab2_B.e_c_dot + lab2_P.F[i] * lab2_B.p_c)
      - (lab2_P.K[i + 4] * lab2_B.ElevationTransferFcn + (lab2_P.K[i + 2] *
          lab2_B.PitchTransferFcn + lab2_P.K[i] * lab2_B.PitchCounttorad));
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Backgain = rtb_Sum2[0] + lab2_P.Constant_Value;

  /* Sum: '<S1>/Add' */
  rtb_Frontgain = rtb_Backgain - rtb_Sum2[1];

  /* Sum: '<S1>/Subtract' */
  rtb_Backgain += rtb_Sum2[1];

  /* Gain: '<S1>/Back gain' */
  rtb_Backgain *= lab2_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' */
  rtb_Frontgain *= lab2_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(lab2_M)) {
    /* Gain: '<S2>/Travel: Count to rad' */
    lab2_B.TravelCounttorad = lab2_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S2>/Travel: Transfer Fcn' */
  lab2_B.TravelTransferFcn = 0.0;
  lab2_B.TravelTransferFcn += lab2_P.TravelTransferFcn_C *
    lab2_X.TravelTransferFcn_CSTATE;
  lab2_B.TravelTransferFcn += lab2_P.TravelTransferFcn_D *
    lab2_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(lab2_M)) {
  }

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (rtb_Frontgain > lab2_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S2>/Front motor: Saturation' */
    lab2_B.FrontmotorSaturation = lab2_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Frontgain < lab2_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S2>/Front motor: Saturation' */
    lab2_B.FrontmotorSaturation = lab2_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Front motor: Saturation' */
    lab2_B.FrontmotorSaturation = rtb_Frontgain;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (rtb_Backgain > lab2_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S2>/Back motor: Saturation' */
    lab2_B.BackmotorSaturation = lab2_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Backgain < lab2_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S2>/Back motor: Saturation' */
    lab2_B.BackmotorSaturation = lab2_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Back motor: Saturation' */
    lab2_B.BackmotorSaturation = rtb_Backgain;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(lab2_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: lab2/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      lab2_DW.HILWriteAnalog_Buffer[0] = lab2_B.FrontmotorSaturation;
      lab2_DW.HILWriteAnalog_Buffer[1] = lab2_B.BackmotorSaturation;
      result = hil_write_analog(lab2_DW.HILInitialize_Card,
        lab2_P.HILWriteAnalog_channels, 2, &lab2_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
      }
    }

    /* RateTransition: '<S3>/Rate Transition: x' */
    if (lab2_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S3>/Rate Transition: x' */
      lab2_B.RateTransitionx = lab2_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: x' */

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (lab2_B.RateTransitionx > lab2_P.DeadZonex_End) {
      /* DeadZone: '<S3>/Dead Zone: y' */
      rtb_DeadZoney = lab2_B.RateTransitionx - lab2_P.DeadZonex_End;
    } else if (lab2_B.RateTransitionx >= lab2_P.DeadZonex_Start) {
      /* DeadZone: '<S3>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S3>/Dead Zone: y' */
      rtb_DeadZoney = lab2_B.RateTransitionx - lab2_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    lab2_B.Joystick_gain_x = lab2_P.Gainx_Gain * rtb_DeadZoney *
      lab2_P.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (lab2_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S3>/Rate Transition: y' */
      lab2_B.RateTransitiony = lab2_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (lab2_B.RateTransitiony > lab2_P.DeadZoney_End) {
      /* DeadZone: '<S3>/Dead Zone: y' */
      rtb_DeadZoney = lab2_B.RateTransitiony - lab2_P.DeadZoney_End;
    } else if (lab2_B.RateTransitiony >= lab2_P.DeadZoney_Start) {
      /* DeadZone: '<S3>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S3>/Dead Zone: y' */
      rtb_DeadZoney = lab2_B.RateTransitiony - lab2_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    lab2_B.Joystick_gain_y = lab2_P.Gainy_Gain * rtb_DeadZoney *
      lab2_P.Joystick_gain_y;
  }
}

/* Model update function for TID0 */
void lab2_update0(void)                /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(lab2_M)) {
    rt_ertODEUpdateContinuousStates(&lab2_M->solverInfo);
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
  if (!(++lab2_M->Timing.clockTick0)) {
    ++lab2_M->Timing.clockTickH0;
  }

  lab2_M->Timing.t[0] = rtsiGetSolverStopTime(&lab2_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2_M->Timing.clockTick1)) {
    ++lab2_M->Timing.clockTickH1;
  }

  lab2_M->Timing.t[1] = lab2_M->Timing.clockTick1 * lab2_M->Timing.stepSize1 +
    lab2_M->Timing.clockTickH1 * lab2_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void lab2_derivatives(void)
{
  XDot_lab2_T *_rtXdot;
  _rtXdot = ((XDot_lab2_T *) lab2_M->derivs);

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += lab2_P.PitchTransferFcn_A *
    lab2_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += lab2_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += lab2_P.ElevationTransferFcn_A *
    lab2_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += lab2_B.Sum;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += lab2_P.TravelTransferFcn_A *
    lab2_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += lab2_B.TravelCounttorad;
}

/* Model output function for TID2 */
void lab2_output2(void)                /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: lab2/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(lab2_DW.GameController_Controller, &state,
        &new_data);
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
  lab2_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S3>/Rate Transition: y' */
  lab2_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void lab2_update2(void)                /* Sample time: [0.01s, 0.0s] */
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
  if (!(++lab2_M->Timing.clockTick2)) {
    ++lab2_M->Timing.clockTickH2;
  }

  lab2_M->Timing.t[2] = lab2_M->Timing.clockTick2 * lab2_M->Timing.stepSize2 +
    lab2_M->Timing.clockTickH2 * lab2_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void lab2_output(int_T tid)
{
  switch (tid) {
   case 0 :
    lab2_output0();
    break;

   case 2 :
    lab2_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void lab2_update(int_T tid)
{
  switch (tid) {
   case 0 :
    lab2_update0();
    break;

   case 2 :
    lab2_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void lab2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &lab2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab2_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(lab2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_M, _rt_error_message);
      return;
    }

    if ((lab2_P.HILInitialize_AIPStart && !is_switching) ||
        (lab2_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &lab2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (lab2_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &lab2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = lab2_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_AIChannels, 8U,
        &lab2_DW.HILInitialize_AIMinimums[0], &lab2_DW.HILInitialize_AIMaximums
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_P.HILInitialize_AOPStart && !is_switching) ||
        (lab2_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &lab2_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (lab2_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &lab2_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = lab2_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_AOChannels, 8U,
        &lab2_DW.HILInitialize_AOMinimums[0], &lab2_DW.HILInitialize_AOMaximums
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_P.HILInitialize_AOStart && !is_switching) ||
        (lab2_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_AOChannels, 8U, &lab2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }
    }

    if (lab2_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (lab2_DW.HILInitialize_Card, lab2_P.HILInitialize_AOChannels, 8U,
         &lab2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_P.HILInitialize_EIPStart && !is_switching) ||
        (lab2_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &lab2_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = lab2_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &lab2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_P.HILInitialize_EIStart && !is_switching) ||
        (lab2_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &lab2_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = lab2_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_EIChannels, 8U,
        &lab2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_P.HILInitialize_POPStart && !is_switching) ||
        (lab2_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab2_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &lab2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          lab2_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &lab2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            lab2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            lab2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              lab2_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            lab2_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            lab2_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              lab2_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(lab2_DW.HILInitialize_Card,
          &lab2_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &lab2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(lab2_DW.HILInitialize_Card,
          &lab2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &lab2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab2_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &lab2_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = lab2_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &lab2_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = lab2_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &lab2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &lab2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &lab2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &lab2_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = lab2_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &lab2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_POChannels, 8U,
        &lab2_DW.HILInitialize_POSortedFreqs[0],
        &lab2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }
    }

    if ((lab2_P.HILInitialize_POStart && !is_switching) ||
        (lab2_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_POChannels, 8U, &lab2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }
    }

    if (lab2_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state(lab2_DW.HILInitialize_Card,
        lab2_P.HILInitialize_POChannels, 8U, &lab2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: lab2/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(lab2_DW.HILInitialize_Card,
      lab2_P.HILReadEncoderTimebase_SamplesI,
      lab2_P.HILReadEncoderTimebase_Channels, 3,
      &lab2_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (lab2_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (lab2_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab2_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "3_treg_Vs.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(lab2_M, "Error creating .mat file 3_treg_Vs.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "ans")) {
      rtmSetErrorStatus(lab2_M,
                        "Error writing mat file header to file 3_treg_Vs.mat");
      return;
    }

    lab2_DW.ToFile1_IWORK.Count = 0;
    lab2_DW.ToFile1_IWORK.Decimation = -1;
    lab2_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  lab2_B.RateTransitionx = lab2_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  lab2_B.RateTransitiony = lab2_P.RateTransitiony_InitialConditio;

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: lab2/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2_P.GameController_Enabled) {
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

      result = game_controller_open(lab2_P.GameController_ControllerNumber,
        lab2_P.GameController_BufferSize, deadzone, saturation,
        lab2_P.GameController_AutoCenter, 0, 1.0,
        &lab2_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab2_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  lab2_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  lab2_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  lab2_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
  lab2_DW.RateTransitionx_Buffer0 = lab2_P.RateTransitionx_InitialConditio;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
  lab2_DW.RateTransitiony_Buffer0 = lab2_P.RateTransitiony_InitialConditio;
}

/* Model terminate function */
void lab2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(lab2_DW.HILInitialize_Card);
    hil_monitor_stop_all(lab2_DW.HILInitialize_Card);
    is_switching = false;
    if ((lab2_P.HILInitialize_AOTerminate && !is_switching) ||
        (lab2_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab2_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((lab2_P.HILInitialize_POTerminate && !is_switching) ||
        (lab2_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab2_P.HILInitialize_POFinal;
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
      result = hil_write(lab2_DW.HILInitialize_Card
                         , lab2_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , lab2_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &lab2_DW.HILInitialize_AOVoltages[0]
                         , &lab2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(lab2_DW.HILInitialize_Card,
            lab2_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &lab2_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(lab2_DW.HILInitialize_Card,
            lab2_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &lab2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(lab2_DW.HILInitialize_Card);
    hil_monitor_delete_all(lab2_DW.HILInitialize_Card);
    hil_close(lab2_DW.HILInitialize_Card);
    lab2_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) lab2_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "3_treg_Vs.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab2_M, "Error closing MAT-file 3_treg_Vs.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(lab2_M, "Error reopening MAT-file 3_treg_Vs.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1, lab2_DW.ToFile1_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(lab2_M,
                          "Error writing header for ans to MAT-file 3_treg_Vs.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab2_M, "Error closing MAT-file 3_treg_Vs.mat");
        return;
      }

      lab2_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: lab2/Joystick/Game Controller (game_controller_block) */
  {
    if (lab2_P.GameController_Enabled) {
      game_controller_close(lab2_DW.GameController_Controller);
      lab2_DW.GameController_Controller = NULL;
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
  lab2_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab2_update(tid);
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
  lab2_initialize();
}

void MdlTerminate(void)
{
  lab2_terminate();
}

/* Registration function */
RT_MODEL_lab2_T *lab2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab2_M, 0,
                sizeof(RT_MODEL_lab2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab2_M->solverInfo, &lab2_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab2_M->solverInfo, &rtmGetTPtr(lab2_M));
    rtsiSetStepSizePtr(&lab2_M->solverInfo, &lab2_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab2_M->solverInfo, &lab2_M->derivs);
    rtsiSetContStatesPtr(&lab2_M->solverInfo, (real_T **) &lab2_M->contStates);
    rtsiSetNumContStatesPtr(&lab2_M->solverInfo, &lab2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab2_M->solverInfo,
      &lab2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab2_M->solverInfo,
      &lab2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab2_M->solverInfo,
      &lab2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab2_M->solverInfo, (&rtmGetErrorStatus(lab2_M)));
    rtsiSetRTModelPtr(&lab2_M->solverInfo, lab2_M);
  }

  rtsiSetSimTimeStep(&lab2_M->solverInfo, MAJOR_TIME_STEP);
  lab2_M->intgData.f[0] = lab2_M->odeF[0];
  lab2_M->contStates = ((real_T *) &lab2_X);
  rtsiSetSolverData(&lab2_M->solverInfo, (void *)&lab2_M->intgData);
  rtsiSetSolverName(&lab2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab2_M->Timing.sampleTimes = (&lab2_M->Timing.sampleTimesArray[0]);
    lab2_M->Timing.offsetTimes = (&lab2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab2_M->Timing.sampleTimes[0] = (0.0);
    lab2_M->Timing.sampleTimes[1] = (0.002);
    lab2_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    lab2_M->Timing.offsetTimes[0] = (0.0);
    lab2_M->Timing.offsetTimes[1] = (0.0);
    lab2_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab2_M, &lab2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab2_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = lab2_M->Timing.perTaskSampleHitsArray;
    lab2_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    lab2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab2_M, -1);
  lab2_M->Timing.stepSize0 = 0.002;
  lab2_M->Timing.stepSize1 = 0.002;
  lab2_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  lab2_M->Sizes.checksums[0] = (3492166520U);
  lab2_M->Sizes.checksums[1] = (2566446388U);
  lab2_M->Sizes.checksums[2] = (3223607477U);
  lab2_M->Sizes.checksums[3] = (1918178774U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab2_M->extModeInfo,
      &lab2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab2_M->extModeInfo, lab2_M->Sizes.checksums);
    rteiSetTPtr(lab2_M->extModeInfo, rtmGetTPtr(lab2_M));
  }

  lab2_M->solverInfoPtr = (&lab2_M->solverInfo);
  lab2_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lab2_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lab2_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  lab2_M->blockIO = ((void *) &lab2_B);

  {
    lab2_B.PitchCounttorad = 0.0;
    lab2_B.PitchTransferFcn = 0.0;
    lab2_B.Sum = 0.0;
    lab2_B.ElevationTransferFcn = 0.0;
    lab2_B.p_c = 0.0;
    lab2_B.e_c_dot = 0.0;
    lab2_B.TravelCounttorad = 0.0;
    lab2_B.TravelTransferFcn = 0.0;
    lab2_B.FrontmotorSaturation = 0.0;
    lab2_B.BackmotorSaturation = 0.0;
    lab2_B.RateTransitionx = 0.0;
    lab2_B.Joystick_gain_x = 0.0;
    lab2_B.RateTransitiony = 0.0;
    lab2_B.Joystick_gain_y = 0.0;
  }

  /* parameters */
  lab2_M->defaultParam = ((real_T *)&lab2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab2_X;
    lab2_M->contStates = (x);
    (void) memset((void *)&lab2_X, 0,
                  sizeof(X_lab2_T));
  }

  /* states (dwork) */
  lab2_M->dwork = ((void *) &lab2_DW);
  (void) memset((void *)&lab2_DW, 0,
                sizeof(DW_lab2_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab2_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  lab2_DW.HILWriteAnalog_Buffer[0] = 0.0;
  lab2_DW.HILWriteAnalog_Buffer[1] = 0.0;
  lab2_DW.RateTransitionx_Buffer0 = 0.0;
  lab2_DW.RateTransitiony_Buffer0 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab2_M->Sizes.numContStates = (3);   /* Number of continuous states */
  lab2_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab2_M->Sizes.numY = (0);            /* Number of model outputs */
  lab2_M->Sizes.numU = (0);            /* Number of model inputs */
  lab2_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  lab2_M->Sizes.numSampTimes = (3);    /* Number of sample times */
  lab2_M->Sizes.numBlocks = (49);      /* Number of blocks */
  lab2_M->Sizes.numBlockIO = (14);     /* Number of block outputs */
  lab2_M->Sizes.numBlockPrms = (160);  /* Sum of parameter "widths" */
  return lab2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
