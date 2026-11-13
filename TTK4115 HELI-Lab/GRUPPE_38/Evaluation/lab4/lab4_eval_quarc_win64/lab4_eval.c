/*
 * lab4_eval.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab4_eval".
 *
 * Model version              : 11.109
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Fri Nov 13 09:52:53 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab4_eval.h"
#include "lab4_eval_private.h"

t_stream lab4_eval_rtZt_stream = NULL;

/* Block signals (default storage) */
B_lab4_eval_T lab4_eval_B;

/* Continuous states */
X_lab4_eval_T lab4_eval_X;

/* Block states (default storage) */
DW_lab4_eval_T lab4_eval_DW;

/* Real-time model */
static RT_MODEL_lab4_eval_T lab4_eval_M_;
RT_MODEL_lab4_eval_T *const lab4_eval_M = &lab4_eval_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(lab4_eval_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(lab4_eval_M, 2);
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
  if (lab4_eval_M->Timing.TaskCounters.TID[1] == 0) {
    lab4_eval_M->Timing.RateInteraction.TID1_2 =
      (lab4_eval_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    lab4_eval_M->Timing.perTaskSampleHits[5] =
      lab4_eval_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (lab4_eval_M->Timing.TaskCounters.TID[2])++;
  if ((lab4_eval_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    lab4_eval_M->Timing.TaskCounters.TID[2] = 0;
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
  lab4_eval_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function for TID0 */
void lab4_eval_output0(void)           /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall2_o1;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_FrontmotorSaturation;
  real_T rtb_BackmotorSaturation;
  int32_T rtb_StreamFormattedRead1_o8;
  int32_T rtb_StreamFormattedRead_o2;
  int32_T rtb_StreamCall2_o3;
  uint8_T rtb_StreamCall2_o2;
  boolean_T rtb_StreamFormattedRead1_o11;
  real_T b_I_0[36];
  real_T c_I_0[36];
  real_T c_I_1[36];
  real_T rtb_P_k[36];
  real_T rtb_P_k_tmp[36];
  real_T A_tmp[30];
  real_T L_k[30];
  real_T P_k_[30];
  real_T A[25];
  real_T b[25];
  real_T tmp[9];
  real_T rtb_x_k[6];
  real_T tmp_3[6];
  real_T tmp_4[6];
  real_T x_k_[6];
  real_T rtb_euler_angles_0[5];
  real_T rtb_euler_angles_1[5];
  real_T tmp_2[5];
  real_T rtb_Gain2[3];
  real_T tmp_0[3];
  real_T rtb_euler_angles[2];
  real_T tmp_1[2];
  real_T rtb_Joystick_gain_y;
  real_T rtb_Sum2;
  real_T rtb_euler_rates_tmp;
  real_T rtb_euler_rates_tmp_0;
  real_T rtb_euler_rates_tmp_1;
  real_T smax;
  int32_T A_tmp_0;
  int32_T c_ix;
  int32_T d_k;
  int32_T e;
  int32_T i;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int8_T b_I[36];
  int8_T c_I[36];
  int8_T ipiv[5];
  int8_T p[5];
  boolean_T rtb_LogicalOperator1;
  if (rtmIsMajorTimeStep(lab4_eval_M)) {
    /* set solver stop time */
    if (!(lab4_eval_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab4_eval_M->solverInfo,
                            ((lab4_eval_M->Timing.clockTickH0 + 1) *
        lab4_eval_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab4_eval_M->solverInfo,
                            ((lab4_eval_M->Timing.clockTick0 + 1) *
        lab4_eval_M->Timing.stepSize0 + lab4_eval_M->Timing.clockTickH0 *
        lab4_eval_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab4_eval_M)) {
    lab4_eval_M->Timing.t[0] = rtsiGetT(&lab4_eval_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lab4_eval_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: lab4_eval/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(lab4_eval_DW.HILReadEncoderTimebase_Task, 1,
        &lab4_eval_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          lab4_eval_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          lab4_eval_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          lab4_eval_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* RateTransition: '<S20>/Rate Transition: x' */
    if (lab4_eval_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S20>/Rate Transition: x' */
      lab4_eval_B.RateTransitionx = lab4_eval_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S20>/Rate Transition: x' */

    /* DeadZone: '<S20>/Dead Zone: x' */
    if (lab4_eval_B.RateTransitionx > lab4_eval_P.DeadZonex_End) {
      smax = lab4_eval_B.RateTransitionx - lab4_eval_P.DeadZonex_End;
    } else if (lab4_eval_B.RateTransitionx >= lab4_eval_P.DeadZonex_Start) {
      smax = 0.0;
    } else {
      smax = lab4_eval_B.RateTransitionx - lab4_eval_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S20>/Dead Zone: x' */

    /* Sum: '<S7>/Sum2' incorporates:
     *  Constant: '<S7>/Constant4'
     *  Gain: '<S20>/Gain: x'
     *  Gain: '<S20>/Joystick_gain_x'
     */
    rtb_Sum2 = lab4_eval_P.Gainx_Gain * smax * lab4_eval_P.Joystick_gain_x +
      lab4_eval_P.p_c_offset;

    /* RateTransition: '<S20>/Rate Transition: y' */
    if (lab4_eval_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S20>/Rate Transition: y' */
      lab4_eval_B.RateTransitiony = lab4_eval_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S20>/Rate Transition: y' */

    /* DeadZone: '<S20>/Dead Zone: y' */
    if (lab4_eval_B.RateTransitiony > lab4_eval_P.DeadZoney_End) {
      smax = lab4_eval_B.RateTransitiony - lab4_eval_P.DeadZoney_End;
    } else if (lab4_eval_B.RateTransitiony >= lab4_eval_P.DeadZoney_Start) {
      smax = 0.0;
    } else {
      smax = lab4_eval_B.RateTransitiony - lab4_eval_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S20>/Dead Zone: y' */

    /* Gain: '<S20>/Joystick_gain_y' incorporates:
     *  Gain: '<S20>/Gain: y'
     */
    rtb_Joystick_gain_y = lab4_eval_P.Gainy_Gain * smax *
      lab4_eval_P.Joystick_gain_y;

    /* S-Function (stream_call_block): '<S9>/Stream Call2' incorporates:
     *  Constant: '<S9>/Constant4'
     *  S-Function (string_constant_block): '<S9>/String Constant1'
     */

    /* S-Function Block: lab4_eval/IMU_data/IMU_BT/Stream Call2 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (lab4_eval_P.Constant4_Value != 0);
      rtb_StreamCall2_o1 = NULL;
      switch (lab4_eval_DW.StreamCall2_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) lab4_eval_P.StringConstant1_Value, 255) ==
                255) {
              rtmSetErrorStatus(lab4_eval_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *) lab4_eval_P.StringConstant1_Value,
                lab4_eval_P.StreamCall2_NonBlocking != 0,
                lab4_eval_P.StreamCall2_SendBufferSize,
                lab4_eval_P.StreamCall2_ReceiveBufferSize,
                &lab4_eval_DW.StreamCall2_Stream);
              if (result == 0) {
                lab4_eval_DW.StreamCall2_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(lab4_eval_DW.StreamCall2_Stream,
                                      (t_stream_byte_order)
                                      lab4_eval_P.StreamCall2_Endian);
                rtb_StreamCall2_o1 = &lab4_eval_DW.StreamCall2_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                lab4_eval_DW.StreamCall2_State = STREAM_CALL_STATE_CONNECTING;
                result = 0;
              }
            }
          }
          break;
        }

       case STREAM_CALL_STATE_CONNECTING:
        {
          if (!close_flag) {
            const t_timeout timeout = { 0, 0, false };/* zero seconds */

            result = stream_poll(lab4_eval_DW.StreamCall2_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              lab4_eval_DW.StreamCall2_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(lab4_eval_DW.StreamCall2_Stream,
                                    (t_stream_byte_order)
                                    lab4_eval_P.StreamCall2_Endian);
              rtb_StreamCall2_o1 = &lab4_eval_DW.StreamCall2_Stream;
              result = 0;
              break;
            } else if (result == 0) {
              break;
            }
          }

          /* Fall through deliberately */
        }

       case STREAM_CALL_STATE_CONNECTED:
        {
          rtb_StreamCall2_o1 = &lab4_eval_DW.StreamCall2_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(lab4_eval_DW.StreamCall2_Stream);
          if (close_result == 0) {
            lab4_eval_DW.StreamCall2_State = STREAM_CALL_STATE_NOT_CONNECTED;
            lab4_eval_DW.StreamCall2_Stream = NULL;
            rtb_StreamCall2_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      rtb_StreamCall2_o2 = lab4_eval_DW.StreamCall2_State;
      rtb_StreamCall2_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_read_block): '<S9>/Stream Formatted Read1' */
    {
      t_error result;
      rtb_StreamFormattedRead1_o11 = false;
      if (rtb_StreamCall2_o1 != NULL) {
        result = stream_scan_utf8_char_array(*rtb_StreamCall2_o1,
          lab4_eval_P.StreamFormattedRead1_MaxUnits,
          &rtb_StreamFormattedRead1_o8, " :%f,%f,%f,%f,%f,%f\r"
          , &lab4_eval_B.StreamFormattedRead1_o2
          , &lab4_eval_B.StreamFormattedRead1_o3
          , &lab4_eval_B.StreamFormattedRead1_o4
          , &lab4_eval_B.StreamFormattedRead1_o5
          , &lab4_eval_B.StreamFormattedRead1_o6
          , &lab4_eval_B.StreamFormattedRead1_o7
          );
        rtb_StreamFormattedRead1_o11 = (result == 0);
        if (result > 0) {
          result = 0;
        }
      } else {
        rtb_StreamFormattedRead1_o8 = 0;
        result = 0;
        lab4_eval_B.StreamFormattedRead1_o2 = 0;
        lab4_eval_B.StreamFormattedRead1_o3 = 0;
        lab4_eval_B.StreamFormattedRead1_o4 = 0;
        lab4_eval_B.StreamFormattedRead1_o5 = 0;
        lab4_eval_B.StreamFormattedRead1_o6 = 0;
        lab4_eval_B.StreamFormattedRead1_o7 = 0;
      }

      lab4_eval_B.StreamFormattedRead1_o10 = (result ==
        -QERR_MISMATCHED_CHARACTER);
    }

    /* Gain: '<S9>/Gain2' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion1'
     */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = lab4_eval_P.Gain2_Gain[i + 6] *
        lab4_eval_B.StreamFormattedRead1_o4 + (lab4_eval_P.Gain2_Gain[i + 3] *
        lab4_eval_B.StreamFormattedRead1_o3 + lab4_eval_P.Gain2_Gain[i] *
        lab4_eval_B.StreamFormattedRead1_o2);
    }

    /* End of Gain: '<S9>/Gain2' */

    /* Logic: '<S9>/Logical Operator1' incorporates:
     *  Logic: '<S9>/Logical Operator'
     *  RelationalOperator: '<S11>/Relational Operator'
     *  RelationalOperator: '<S12>/Relational Operator'
     *  RelationalOperator: '<S13>/Relational Operator'
     *  RelationalOperator: '<S14>/Relational Operator'
     *  RelationalOperator: '<S15>/Relational Operator'
     *  RelationalOperator: '<S16>/Relational Operator'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S12>/Unit Delay'
     *  UnitDelay: '<S13>/Unit Delay'
     *  UnitDelay: '<S14>/Unit Delay'
     *  UnitDelay: '<S15>/Unit Delay'
     *  UnitDelay: '<S16>/Unit Delay'
     */
    rtb_LogicalOperator1 = ((!(lab4_eval_B.StreamFormattedRead1_o2 ==
      lab4_eval_DW.UnitDelay_DSTATE)) || (!(lab4_eval_B.StreamFormattedRead1_o3 ==
      lab4_eval_DW.UnitDelay_DSTATE_d)) ||
      (!(lab4_eval_B.StreamFormattedRead1_o4 == lab4_eval_DW.UnitDelay_DSTATE_p))
      || (!(lab4_eval_B.StreamFormattedRead1_o5 ==
            lab4_eval_DW.UnitDelay_DSTATE_l)) ||
      (!(lab4_eval_B.StreamFormattedRead1_o6 == lab4_eval_DW.UnitDelay_DSTATE_n))
      || (!(lab4_eval_B.StreamFormattedRead1_o7 ==
            lab4_eval_DW.UnitDelay_DSTATE_dn)));

    /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
     *  Constant: '<S3>/Constant'
     */
    /* MATLAB Function 'IMU_data/MATLAB Function': '<S10>:1' */
    if ((!lab4_eval_DW.p_last_not_empty) || (!lab4_eval_DW.e_last_not_empty)) {
      /* '<S10>:1:5' */
      /* '<S10>:1:6' */
      lab4_eval_DW.p_last = 0.0;
      lab4_eval_DW.p_last_not_empty = true;

      /* '<S10>:1:7' */
      lab4_eval_DW.e_last = lab4_eval_P.e_0;
      lab4_eval_DW.e_last_not_empty = true;
    }

    if (rtb_LogicalOperator1) {
      /* '<S10>:1:10' */
      /* '<S10>:1:11' */
      lab4_eval_DW.p_last = rt_atan2d_snf(-rtb_Gain2[1], -rtb_Gain2[2]);

      /* '<S10>:1:12' */
      lab4_eval_DW.e_last = rt_atan2d_snf(rtb_Gain2[0], sqrt(rtb_Gain2[1] *
        rtb_Gain2[1] + rtb_Gain2[2] * rtb_Gain2[2]));
    }

    /* MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
     *  MATLAB Function: '<S3>/MATLAB Function'
     */
    /* '<S10>:1:14' */
    /* MATLAB Function 'IMU_data/Gyro vector to [pitch rate, elevation rate, travle rate]': '<S8>:1' */
    /* '<S8>:1:3' */
    /* '<S8>:1:4' */
    /* '<S8>:1:6' */
    /* '<S8>:1:9' */
    smax = tan(lab4_eval_DW.e_last);
    rtb_euler_rates_tmp = sin(lab4_eval_DW.p_last);
    rtb_euler_rates_tmp_0 = cos(lab4_eval_DW.p_last);
    rtb_euler_rates_tmp_1 = cos(lab4_eval_DW.e_last);
    tmp[0] = 1.0;
    tmp[3] = rtb_euler_rates_tmp * smax;
    tmp[6] = rtb_euler_rates_tmp_0 * smax;
    tmp[1] = 0.0;
    tmp[4] = rtb_euler_rates_tmp_0;
    tmp[7] = -rtb_euler_rates_tmp;
    tmp[2] = 0.0;
    tmp[5] = rtb_euler_rates_tmp / rtb_euler_rates_tmp_1;
    tmp[8] = rtb_euler_rates_tmp_0 / rtb_euler_rates_tmp_1;

    /* Gain: '<S9>/Gain1' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion2'
     */
    for (i = 0; i < 3; i++) {
      tmp_0[i] = lab4_eval_P.Gain1_Gain[i + 6] *
        lab4_eval_B.StreamFormattedRead1_o7 + (lab4_eval_P.Gain1_Gain[i + 3] *
        lab4_eval_B.StreamFormattedRead1_o6 + lab4_eval_P.Gain1_Gain[i] *
        lab4_eval_B.StreamFormattedRead1_o5);
    }

    /* End of Gain: '<S9>/Gain1' */

    /* MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = tmp[i + 6] * tmp_0[2] + (tmp[i + 3] * tmp_0[1] + tmp[i] *
        tmp_0[0]);
    }

    /* MATLAB Function: '<S4>/MATLAB Function2' incorporates:
     *  Constant: '<S4>/Constant'
     *  Delay: '<S4>/Delay One Step'
     *  Delay: '<S4>/Delay One Step1'
     */
    for (i = 0; i < 6; i++) {
      x_k_[i] = lab4_eval_DW.DelayOneStep_DSTATE[i];
    }

    memcpy(&rtb_P_k[0], &lab4_eval_DW.DelayOneStep1_DSTATE[0], 36U * sizeof
           (real_T));

    /* MATLAB Function 'Kalman_filter/MATLAB Function2': '<S19>:1' */
    if (!lab4_eval_DW.first_not_empty) {
      /* '<S19>:1:3' */
      lab4_eval_DW.first_not_empty = true;

      /* '<S19>:1:5' */
      x_k_[0] = 0.0;
      x_k_[1] = 0.0;
      x_k_[2] = lab4_eval_P.e_0;
      x_k_[3] = 0.0;
      x_k_[4] = 0.0;
      x_k_[5] = 0.0;

      /* '<S19>:1:6' */
      for (i = 0; i < 36; i++) {
        rtb_P_k[i] = 0.0;
      }
    }

    /* '<S19>:1:8' */
    for (i = 0; i < 6; i++) {
      rtb_x_k[i] = x_k_[i];
    }

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    /* '<S19>:1:9' */
    if (lab4_eval_P.ManualSwitch_CurrentSetting == 1) {
      smax = rtb_LogicalOperator1;
    } else {
      smax = lab4_eval_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* MATLAB Function: '<S4>/MATLAB Function2' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant2'
     */
    if (smax != 0.0) {
      /* '<S19>:1:12' */
      for (i = 0; i < 25; i++) {
        b[i] = 0.0;
      }

      for (i = 0; i < 5; i++) {
        for (iy = 0; iy < 6; iy++) {
          ix = 5 * iy + i;
          A_tmp[iy + 6 * i] = lab4_eval_P.C_d[ix];
          L_k[ix] = 0.0;
          for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
            L_k[ix] += lab4_eval_P.C_d[5 * A_tmp_0 + i] * rtb_P_k[6 * iy +
              A_tmp_0];
          }
        }
      }

      for (i = 0; i < 5; i++) {
        for (iy = 0; iy < 5; iy++) {
          smax = 0.0;
          for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
            smax += L_k[5 * A_tmp_0 + i] * A_tmp[6 * iy + A_tmp_0];
          }

          A_tmp_0 = 5 * iy + i;
          A[A_tmp_0] = lab4_eval_P.R_d[A_tmp_0] + smax;
        }

        ipiv[i] = (int8_T)(i + 1);
      }

      for (A_tmp_0 = 0; A_tmp_0 < 4; A_tmp_0++) {
        i = A_tmp_0 * 6;
        iy = 0;
        ix = i;
        smax = fabs(A[i]);
        for (d_k = 2; d_k <= 5 - A_tmp_0; d_k++) {
          ix++;
          rtb_euler_rates_tmp = fabs(A[ix]);
          if (rtb_euler_rates_tmp > smax) {
            iy = d_k - 1;
            smax = rtb_euler_rates_tmp;
          }
        }

        if (A[i + iy] != 0.0) {
          if (iy != 0) {
            iy += A_tmp_0;
            ipiv[A_tmp_0] = (int8_T)(iy + 1);
            ix = A_tmp_0;
            for (d_k = 0; d_k < 5; d_k++) {
              smax = A[ix];
              A[ix] = A[iy];
              A[iy] = smax;
              ix += 5;
              iy += 5;
            }
          }

          iy = (i - A_tmp_0) + 5;
          for (ix = i + 1; ix < iy; ix++) {
            A[ix] /= A[i];
          }
        }

        iy = i;
        ix = i + 5;
        for (d_k = 0; d_k <= 3 - A_tmp_0; d_k++) {
          if (A[ix] != 0.0) {
            smax = -A[ix];
            c_ix = i + 1;
            e = (iy - A_tmp_0) + 10;
            for (ijA = iy + 6; ijA < e; ijA++) {
              A[ijA] += A[c_ix] * smax;
              c_ix++;
            }
          }

          ix += 5;
          iy += 5;
        }
      }

      for (i = 0; i < 5; i++) {
        p[i] = (int8_T)(i + 1);
      }

      if (ipiv[0] > 1) {
        i = p[ipiv[0] - 1];
        p[ipiv[0] - 1] = p[0];
        p[0] = (int8_T)i;
      }

      if (ipiv[1] > 2) {
        i = p[ipiv[1] - 1];
        p[ipiv[1] - 1] = p[1];
        p[1] = (int8_T)i;
      }

      if (ipiv[2] > 3) {
        i = p[ipiv[2] - 1];
        p[ipiv[2] - 1] = p[2];
        p[2] = (int8_T)i;
      }

      if (ipiv[3] > 4) {
        i = p[ipiv[3] - 1];
        p[ipiv[3] - 1] = p[3];
        p[3] = (int8_T)i;
      }

      for (A_tmp_0 = 0; A_tmp_0 < 5; A_tmp_0++) {
        d_k = p[A_tmp_0] - 1;
        b[A_tmp_0 + 5 * d_k] = 1.0;
        for (iy = A_tmp_0; iy + 1 < 6; iy++) {
          i = 5 * d_k + iy;
          if (b[i] != 0.0) {
            for (ix = iy + 1; ix + 1 < 6; ix++) {
              c_ix = 5 * d_k + ix;
              b[c_ix] -= b[i] * A[5 * iy + ix];
            }
          }
        }
      }

      for (A_tmp_0 = 0; A_tmp_0 < 5; A_tmp_0++) {
        i = 5 * A_tmp_0;
        for (iy = 4; iy >= 0; iy--) {
          ix = 5 * iy;
          if (b[iy + i] != 0.0) {
            c_ix = iy + i;
            b[c_ix] /= A[iy + ix];
            for (d_k = 0; d_k < iy; d_k++) {
              e = d_k + i;
              b[e] -= b[c_ix] * A[d_k + ix];
            }
          }
        }
      }

      for (i = 0; i < 6; i++) {
        for (iy = 0; iy < 5; iy++) {
          ix = i + 6 * iy;
          P_k_[ix] = 0.0;
          for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
            P_k_[ix] += rtb_P_k[6 * A_tmp_0 + i] * A_tmp[6 * iy + A_tmp_0];
          }
        }

        for (iy = 0; iy < 5; iy++) {
          ix = i + 6 * iy;
          L_k[ix] = 0.0;
          for (A_tmp_0 = 0; A_tmp_0 < 5; A_tmp_0++) {
            L_k[ix] += P_k_[6 * A_tmp_0 + i] * b[5 * iy + A_tmp_0];
          }
        }
      }

      /* SignalConversion generated from: '<S19>/ SFunction ' incorporates:
       *  Constant: '<S4>/Constant1'
       *  Constant: '<S4>/Constant2'
       *  MATLAB Function: '<S3>/MATLAB Function'
       */
      /* '<S19>:1:13' */
      rtb_euler_angles_0[0] = lab4_eval_DW.p_last;
      rtb_euler_angles_0[1] = rtb_Gain2[0];
      rtb_euler_angles_0[2] = lab4_eval_DW.e_last;
      rtb_euler_angles_0[3] = rtb_Gain2[1];
      rtb_euler_angles_0[4] = rtb_Gain2[2];
      for (i = 0; i < 5; i++) {
        tmp_2[i] = 0.0;
        for (iy = 0; iy < 6; iy++) {
          tmp_2[i] += lab4_eval_P.C_d[5 * iy + i] * x_k_[iy];
        }

        rtb_euler_angles_1[i] = rtb_euler_angles_0[i] - tmp_2[i];
      }

      for (i = 0; i < 6; i++) {
        smax = 0.0;
        for (iy = 0; iy < 5; iy++) {
          smax += L_k[6 * iy + i] * rtb_euler_angles_1[iy];
        }

        rtb_x_k[i] = x_k_[i] + smax;
      }

      for (i = 0; i < 36; i++) {
        b_I[i] = 0;
      }

      for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
        b_I[A_tmp_0 + 6 * A_tmp_0] = 1;
      }

      /* '<S19>:1:14' */
      for (i = 0; i < 36; i++) {
        c_I[i] = 0;
      }

      for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
        c_I[A_tmp_0 + 6 * A_tmp_0] = 1;
        for (i = 0; i < 6; i++) {
          ix = A_tmp_0 + 6 * i;
          rtb_P_k_tmp[ix] = 0.0;
          for (iy = 0; iy < 5; iy++) {
            rtb_P_k_tmp[ix] += L_k[6 * iy + A_tmp_0] * lab4_eval_P.C_d[5 * i +
              iy];
          }
        }
      }

      for (i = 0; i < 36; i++) {
        c_I_0[i] = (real_T)c_I[i] - rtb_P_k_tmp[i];
      }

      for (i = 0; i < 6; i++) {
        for (iy = 0; iy < 6; iy++) {
          ix = i + 6 * iy;
          c_I_1[ix] = 0.0;
          for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
            c_I_1[ix] += c_I_0[6 * A_tmp_0 + i] * rtb_P_k[6 * iy + A_tmp_0];
          }

          b_I_0[iy + 6 * i] = (real_T)b_I[ix] - rtb_P_k_tmp[ix];
        }

        for (iy = 0; iy < 5; iy++) {
          ix = i + 6 * iy;
          A_tmp[ix] = 0.0;
          for (A_tmp_0 = 0; A_tmp_0 < 5; A_tmp_0++) {
            A_tmp[ix] += L_k[6 * A_tmp_0 + i] * lab4_eval_P.R_d[5 * iy + A_tmp_0];
          }
        }
      }

      for (i = 0; i < 6; i++) {
        for (iy = 0; iy < 6; iy++) {
          ix = i + 6 * iy;
          c_I_0[ix] = 0.0;
          for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
            c_I_0[ix] += c_I_1[6 * A_tmp_0 + i] * b_I_0[6 * iy + A_tmp_0];
          }

          rtb_P_k_tmp[ix] = 0.0;
          for (A_tmp_0 = 0; A_tmp_0 < 5; A_tmp_0++) {
            rtb_P_k_tmp[ix] += A_tmp[6 * A_tmp_0 + i] * L_k[6 * A_tmp_0 + iy];
          }
        }
      }

      for (i = 0; i < 36; i++) {
        rtb_P_k[i] = c_I_0[i] + rtb_P_k_tmp[i];
      }
    }

    /* SignalConversion generated from: '<S5>/LQR' */
    smax = rtb_x_k[3];
    rtb_euler_rates_tmp = rtb_x_k[0];

    /* Gain: '<S5>/Gain' incorporates:
     *  SignalConversion generated from: '<S5>/Gain'
     */
    tmp_1[0] = lab4_eval_P.F[0] * rtb_Sum2 + lab4_eval_P.F[2] *
      rtb_Joystick_gain_y;

    /* SignalConversion generated from: '<S5>/LQR' */
    rtb_euler_rates_tmp_0 = rtb_x_k[1];

    /* Gain: '<S5>/Gain' incorporates:
     *  SignalConversion generated from: '<S5>/Gain'
     */
    tmp_1[1] = lab4_eval_P.F[1] * rtb_Sum2;
    tmp_1[1] += lab4_eval_P.F[3] * rtb_Joystick_gain_y;
    for (i = 0; i < 2; i++) {
      /* Sum: '<S5>/Sum2' incorporates:
       *  Gain: '<S5>/LQR'
       */
      rtb_euler_angles[i] = tmp_1[i] - (lab4_eval_P.K[i + 4] * smax +
        (lab4_eval_P.K[i + 2] * rtb_euler_rates_tmp_0 + lab4_eval_P.K[i] *
         rtb_euler_rates_tmp));
    }

    /* Saturate: '<S2>/Back motor: Saturation' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    rtb_BackmotorSaturation = rtb_euler_angles[0] + lab4_eval_P.V_s_0;

    /* Saturate: '<S2>/Front motor: Saturation' incorporates:
     *  Sum: '<S1>/Add'
     */
    rtb_FrontmotorSaturation = rtb_BackmotorSaturation - rtb_euler_angles[1];

    /* Saturate: '<S2>/Back motor: Saturation' incorporates:
     *  Gain: '<S1>/Back gain'
     *  Sum: '<S1>/Subtract'
     */
    rtb_BackmotorSaturation += rtb_euler_angles[1];
    rtb_BackmotorSaturation *= lab4_eval_P.Backgain_Gain;

    /* Saturate: '<S2>/Front motor: Saturation' incorporates:
     *  Gain: '<S1>/Front gain'
     */
    rtb_FrontmotorSaturation *= lab4_eval_P.Frontgain_Gain;

    /* Gain: '<S2>/Elevation: Count to rad' */
    lab4_eval_B.ElevationCounttorad = lab4_eval_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3;

    /* Gain: '<S2>/Pitch: Count to rad' */
    lab4_eval_B.PitchCounttorad = lab4_eval_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S2>/Travel: Count to rad' */
    lab4_eval_B.TravelCounttorad = lab4_eval_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Saturate: '<S2>/Front motor: Saturation' */
    if (rtb_FrontmotorSaturation > lab4_eval_P.FrontmotorSaturation_UpperSat) {
      /* Saturate: '<S2>/Front motor: Saturation' */
      rtb_FrontmotorSaturation = lab4_eval_P.FrontmotorSaturation_UpperSat;
    } else {
      if (rtb_FrontmotorSaturation < lab4_eval_P.FrontmotorSaturation_LowerSat)
      {
        /* Saturate: '<S2>/Front motor: Saturation' */
        rtb_FrontmotorSaturation = lab4_eval_P.FrontmotorSaturation_LowerSat;
      }
    }

    /* End of Saturate: '<S2>/Front motor: Saturation' */

    /* Saturate: '<S2>/Back motor: Saturation' */
    if (rtb_BackmotorSaturation > lab4_eval_P.BackmotorSaturation_UpperSat) {
      /* Saturate: '<S2>/Back motor: Saturation' */
      rtb_BackmotorSaturation = lab4_eval_P.BackmotorSaturation_UpperSat;
    } else {
      if (rtb_BackmotorSaturation < lab4_eval_P.BackmotorSaturation_LowerSat) {
        /* Saturate: '<S2>/Back motor: Saturation' */
        rtb_BackmotorSaturation = lab4_eval_P.BackmotorSaturation_LowerSat;
      }
    }

    /* End of Saturate: '<S2>/Back motor: Saturation' */

    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: lab4_eval/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      lab4_eval_DW.HILWriteAnalog_Buffer[0] = rtb_FrontmotorSaturation;
      lab4_eval_DW.HILWriteAnalog_Buffer[1] = rtb_BackmotorSaturation;
      result = hil_write_analog(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILWriteAnalog_channels, 2,
        &lab4_eval_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
      }
    }

    /* Outputs for Enabled SubSystem: '<S9>/Skip to next line' incorporates:
     *  EnablePort: '<S17>/Enable'
     */
    if (lab4_eval_B.StreamFormattedRead1_o10) {
      /* S-Function (stream_formatted_read_block): '<S17>/Stream Formatted Read' incorporates:
       *  S-Function (stream_call_block): '<S9>/Stream Call2'
       *  S-Function (stream_formatted_read_block): '<S9>/Stream Formatted Read1'
       */
      {
        if (((t_stream_ptr)rtb_StreamCall2_o1) != NULL) {
          stream_scan_utf8_char_array(*((t_stream_ptr)rtb_StreamCall2_o1),
            lab4_eval_P.StreamFormattedRead_MaxUnits,
            &rtb_StreamFormattedRead_o2, " %*[^\r]"
            );
        } else {
          rtb_StreamFormattedRead_o2 = 0;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S9>/Skip to next line' */

    /* S-Function (stop_with_error_block): '<S9>/Stop with Error' */

    /* S-Function Block: lab4_eval/IMU_data/IMU_BT/Stop with Error (stop_with_error_block) */
    {
      if (rtb_StreamCall2_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall2_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }

    /* MATLAB Function: '<S4>/MATLAB Function1' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant3'
     *  Constant: '<S4>/Constant4'
     *  Constant: '<S4>/Constant5'
     */
    for (i = 0; i < 6; i++) {
      x_k_[i] = rtb_x_k[i];
    }

    /* MATLAB Function 'Kalman_filter/MATLAB Function1': '<S18>:1' */
    if (!lab4_eval_DW.first_not_empty_b) {
      /* '<S18>:1:3' */
      lab4_eval_DW.first_not_empty_b = true;

      /* '<S18>:1:5' */
      x_k_[0] = 0.0;
      x_k_[1] = 0.0;
      x_k_[2] = lab4_eval_P.e_0;
      x_k_[3] = 0.0;
      x_k_[4] = 0.0;
      x_k_[5] = 0.0;

      /* '<S18>:1:6' */
      for (i = 0; i < 36; i++) {
        rtb_P_k[i] = 0.0;
      }
    }

    /* '<S18>:1:9' */
    /* '<S18>:1:10' */
    for (i = 0; i < 6; i++) {
      for (iy = 0; iy < 6; iy++) {
        A_tmp_0 = i + 6 * iy;
        c_I_0[A_tmp_0] = 0.0;
        for (ix = 0; ix < 6; ix++) {
          c_I_0[A_tmp_0] += lab4_eval_P.A_d[6 * ix + i] * rtb_P_k[6 * iy + ix];
        }
      }

      tmp_3[i] = 0.0;
      for (iy = 0; iy < 6; iy++) {
        smax = 0.0;
        for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
          smax += c_I_0[6 * A_tmp_0 + i] * lab4_eval_P.A_d[6 * A_tmp_0 + iy];
        }

        A_tmp_0 = 6 * iy + i;
        lab4_eval_B.P_k1_[A_tmp_0] = lab4_eval_P.Q_d[A_tmp_0] + smax;
        tmp_3[i] += lab4_eval_P.A_d[A_tmp_0] * x_k_[iy];
      }

      tmp_4[i] = 0.0;
      tmp_4[i] += lab4_eval_P.B_d[i] * rtb_euler_angles[0];
      tmp_4[i] += lab4_eval_P.B_d[i + 6] * rtb_euler_angles[1];
      lab4_eval_B.x_k1_[i] = tmp_3[i] + tmp_4[i];
    }

    /* End of MATLAB Function: '<S4>/MATLAB Function1' */

    /* Sum: '<S5>/Sum4' */
    lab4_eval_B.gamma_dot = rtb_Sum2 - rtb_x_k[0];

    /* Sum: '<S5>/Sum5' */
    lab4_eval_B.zeta_dot = rtb_Joystick_gain_y - rtb_x_k[3];
  }
}

/* Model update function for TID0 */
void lab4_eval_update0(void)           /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(lab4_eval_M)) {
    /* Update for Delay: '<S4>/Delay One Step' */
    for (i = 0; i < 6; i++) {
      lab4_eval_DW.DelayOneStep_DSTATE[i] = lab4_eval_B.x_k1_[i];
    }

    /* End of Update for Delay: '<S4>/Delay One Step' */

    /* Update for Delay: '<S4>/Delay One Step1' */
    memcpy(&lab4_eval_DW.DelayOneStep1_DSTATE[0], &lab4_eval_B.P_k1_[0], 36U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S11>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE = lab4_eval_B.StreamFormattedRead1_o2;

    /* Update for UnitDelay: '<S12>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_d = lab4_eval_B.StreamFormattedRead1_o3;

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_p = lab4_eval_B.StreamFormattedRead1_o4;

    /* Update for UnitDelay: '<S14>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_l = lab4_eval_B.StreamFormattedRead1_o5;

    /* Update for UnitDelay: '<S15>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_n = lab4_eval_B.StreamFormattedRead1_o6;

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_dn = lab4_eval_B.StreamFormattedRead1_o7;
  }

  if (rtmIsMajorTimeStep(lab4_eval_M)) {
    rt_ertODEUpdateContinuousStates(&lab4_eval_M->solverInfo);
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
  if (!(++lab4_eval_M->Timing.clockTick0)) {
    ++lab4_eval_M->Timing.clockTickH0;
  }

  lab4_eval_M->Timing.t[0] = rtsiGetSolverStopTime(&lab4_eval_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab4_eval_M->Timing.clockTick1)) {
    ++lab4_eval_M->Timing.clockTickH1;
  }

  lab4_eval_M->Timing.t[1] = lab4_eval_M->Timing.clockTick1 *
    lab4_eval_M->Timing.stepSize1 + lab4_eval_M->Timing.clockTickH1 *
    lab4_eval_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void lab4_eval_derivatives(void)
{
  XDot_lab4_eval_T *_rtXdot;
  _rtXdot = ((XDot_lab4_eval_T *) lab4_eval_M->derivs);

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += lab4_eval_P.ElevationTransferFcn_A *
    lab4_eval_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += lab4_eval_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += lab4_eval_P.PitchTransferFcn_A *
    lab4_eval_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += lab4_eval_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += lab4_eval_P.TravelTransferFcn_A *
    lab4_eval_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += lab4_eval_B.TravelCounttorad;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE = lab4_eval_B.gamma_dot;

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = lab4_eval_B.zeta_dot;
}

/* Model output function for TID2 */
void lab4_eval_output2(void)           /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S20>/Game Controller' */

  /* S-Function Block: lab4_eval/Subsystem1/Joystick/Game Controller (game_controller_block) */
  {
    if (lab4_eval_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(lab4_eval_DW.GameController_Controller,
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

  /* RateTransition: '<S20>/Rate Transition: x' */
  lab4_eval_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S20>/Rate Transition: y' */
  lab4_eval_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void lab4_eval_update2(void)           /* Sample time: [0.01s, 0.0s] */
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
  if (!(++lab4_eval_M->Timing.clockTick2)) {
    ++lab4_eval_M->Timing.clockTickH2;
  }

  lab4_eval_M->Timing.t[2] = lab4_eval_M->Timing.clockTick2 *
    lab4_eval_M->Timing.stepSize2 + lab4_eval_M->Timing.clockTickH2 *
    lab4_eval_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void lab4_eval_output(int_T tid)
{
  switch (tid) {
   case 0 :
    lab4_eval_output0();
    break;

   case 2 :
    lab4_eval_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void lab4_eval_update(int_T tid)
{
  switch (tid) {
   case 0 :
    lab4_eval_update0();
    break;

   case 2 :
    lab4_eval_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void lab4_eval_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab4_eval/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &lab4_eval_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab4_eval_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(lab4_eval_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
      return;
    }

    if ((lab4_eval_P.HILInitialize_AIPStart && !is_switching) ||
        (lab4_eval_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &lab4_eval_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (lab4_eval_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &lab4_eval_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = lab4_eval_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILInitialize_AIChannels, 8U,
        &lab4_eval_DW.HILInitialize_AIMinimums[0],
        &lab4_eval_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_eval_P.HILInitialize_AOPStart && !is_switching) ||
        (lab4_eval_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &lab4_eval_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (lab4_eval_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &lab4_eval_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = lab4_eval_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILInitialize_AOChannels, 8U,
        &lab4_eval_DW.HILInitialize_AOMinimums[0],
        &lab4_eval_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_eval_P.HILInitialize_AOStart && !is_switching) ||
        (lab4_eval_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab4_eval_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab4_eval_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILInitialize_AOChannels, 8U,
        &lab4_eval_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }

    if (lab4_eval_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab4_eval_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab4_eval_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (lab4_eval_DW.HILInitialize_Card, lab4_eval_P.HILInitialize_AOChannels,
         8U, &lab4_eval_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_eval_P.HILInitialize_EIPStart && !is_switching) ||
        (lab4_eval_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &lab4_eval_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = lab4_eval_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &lab4_eval_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_eval_P.HILInitialize_EIStart && !is_switching) ||
        (lab4_eval_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &lab4_eval_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = lab4_eval_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILInitialize_EIChannels, 8U,
        &lab4_eval_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_eval_P.HILInitialize_POPStart && !is_switching) ||
        (lab4_eval_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab4_eval_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab4_eval_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &lab4_eval_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          lab4_eval_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &lab4_eval_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            lab4_eval_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            lab4_eval_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              lab4_eval_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            lab4_eval_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            lab4_eval_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              lab4_eval_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(lab4_eval_DW.HILInitialize_Card,
          &lab4_eval_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &lab4_eval_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(lab4_eval_DW.HILInitialize_Card,
          &lab4_eval_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &lab4_eval_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab4_eval_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab4_eval_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &lab4_eval_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = lab4_eval_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &lab4_eval_DW.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = lab4_eval_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &lab4_eval_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &lab4_eval_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &lab4_eval_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &lab4_eval_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = lab4_eval_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &lab4_eval_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab4_eval_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILInitialize_POChannels, 8U,
        &lab4_eval_DW.HILInitialize_POSortedFreqs[0],
        &lab4_eval_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }

    if ((lab4_eval_P.HILInitialize_POStart && !is_switching) ||
        (lab4_eval_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab4_eval_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab4_eval_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(lab4_eval_DW.HILInitialize_Card,
        lab4_eval_P.HILInitialize_POChannels, 8U,
        &lab4_eval_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }

    if (lab4_eval_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &lab4_eval_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab4_eval_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (lab4_eval_DW.HILInitialize_Card, lab4_eval_P.HILInitialize_POChannels,
         8U, &lab4_eval_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: lab4_eval/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(lab4_eval_DW.HILInitialize_Card,
      lab4_eval_P.HILReadEncoderTimebase_SamplesI,
      lab4_eval_P.HILReadEncoderTimebase_Channels, 3,
      &lab4_eval_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (lab4_eval_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (lab4_eval_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S20>/Rate Transition: x' */
  lab4_eval_B.RateTransitionx = lab4_eval_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S20>/Rate Transition: y' */
  lab4_eval_B.RateTransitiony = lab4_eval_P.RateTransitiony_InitialConditio;

  /* Start for S-Function (stream_call_block): '<S9>/Stream Call2' incorporates:
   *  Constant: '<S9>/Constant4'
   *  S-Function (string_constant_block): '<S9>/String Constant1'
   */

  /* S-Function Block: lab4_eval/IMU_data/IMU_BT/Stream Call2 (stream_call_block) */
  {
    lab4_eval_DW.StreamCall2_State = STREAM_CALL_STATE_NOT_CONNECTED;
    lab4_eval_DW.StreamCall2_Stream = NULL;
  }

  /* Start for S-Function (game_controller_block): '<S20>/Game Controller' */

  /* S-Function Block: lab4_eval/Subsystem1/Joystick/Game Controller (game_controller_block) */
  {
    if (lab4_eval_P.GameController_Enabled) {
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

      result = game_controller_open(lab4_eval_P.GameController_ControllerNumber,
        lab4_eval_P.GameController_BufferSize, deadzone, saturation,
        lab4_eval_P.GameController_AutoCenter, 0, 1.0,
        &lab4_eval_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for RateTransition: '<S20>/Rate Transition: x' */
    lab4_eval_DW.RateTransitionx_Buffer0 =
      lab4_eval_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for RateTransition: '<S20>/Rate Transition: y' */
    lab4_eval_DW.RateTransitiony_Buffer0 =
      lab4_eval_P.RateTransitiony_InitialConditio;

    /* InitializeConditions for Delay: '<S4>/Delay One Step' */
    for (i = 0; i < 6; i++) {
      lab4_eval_DW.DelayOneStep_DSTATE[i] =
        lab4_eval_P.DelayOneStep_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S4>/Delay One Step' */

    /* InitializeConditions for Delay: '<S4>/Delay One Step1' */
    for (i = 0; i < 36; i++) {
      lab4_eval_DW.DelayOneStep1_DSTATE[i] =
        lab4_eval_P.DelayOneStep1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S4>/Delay One Step1' */

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE = lab4_eval_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_d = lab4_eval_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_p = lab4_eval_P.UnitDelay_InitialCondition_j;

    /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_l = lab4_eval_P.UnitDelay_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_n = lab4_eval_P.UnitDelay_InitialCondition_l1;

    /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
    lab4_eval_DW.UnitDelay_DSTATE_dn = lab4_eval_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
    lab4_eval_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
    lab4_eval_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
    lab4_eval_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    lab4_eval_X.Integrator_CSTATE = lab4_eval_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S5>/Integrator1' */
    lab4_eval_X.Integrator1_CSTATE = lab4_eval_P.Integrator1_IC;

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    lab4_eval_DW.p_last_not_empty = false;
    lab4_eval_DW.e_last_not_empty = false;

    /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1' */
    lab4_eval_DW.first_not_empty_b = false;

    /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function2' */
    lab4_eval_DW.first_not_empty = false;
  }
}

/* Model terminate function */
void lab4_eval_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab4_eval/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(lab4_eval_DW.HILInitialize_Card);
    hil_monitor_stop_all(lab4_eval_DW.HILInitialize_Card);
    is_switching = false;
    if ((lab4_eval_P.HILInitialize_AOTerminate && !is_switching) ||
        (lab4_eval_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab4_eval_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab4_eval_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((lab4_eval_P.HILInitialize_POTerminate && !is_switching) ||
        (lab4_eval_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab4_eval_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab4_eval_P.HILInitialize_POFinal;
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
      result = hil_write(lab4_eval_DW.HILInitialize_Card
                         , lab4_eval_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , lab4_eval_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &lab4_eval_DW.HILInitialize_AOVoltages[0]
                         , &lab4_eval_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(lab4_eval_DW.HILInitialize_Card,
            lab4_eval_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &lab4_eval_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(lab4_eval_DW.HILInitialize_Card,
            lab4_eval_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &lab4_eval_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab4_eval_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(lab4_eval_DW.HILInitialize_Card);
    hil_monitor_delete_all(lab4_eval_DW.HILInitialize_Card);
    hil_close(lab4_eval_DW.HILInitialize_Card);
    lab4_eval_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S9>/Stream Call2' incorporates:
   *  Constant: '<S9>/Constant4'
   *  S-Function (string_constant_block): '<S9>/String Constant1'
   */

  /* S-Function Block: lab4_eval/IMU_data/IMU_BT/Stream Call2 (stream_call_block) */
  {
    if (lab4_eval_DW.StreamCall2_Stream != NULL) {
      stream_close(lab4_eval_DW.StreamCall2_Stream);
      lab4_eval_DW.StreamCall2_Stream = NULL;
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S20>/Game Controller' */

  /* S-Function Block: lab4_eval/Subsystem1/Joystick/Game Controller (game_controller_block) */
  {
    if (lab4_eval_P.GameController_Enabled) {
      game_controller_close(lab4_eval_DW.GameController_Controller);
      lab4_eval_DW.GameController_Controller = NULL;
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
  lab4_eval_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab4_eval_update(tid);
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
  lab4_eval_initialize();
}

void MdlTerminate(void)
{
  lab4_eval_terminate();
}

/* Registration function */
RT_MODEL_lab4_eval_T *lab4_eval(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  lab4_eval_P.UnitDelay_InitialCondition = rtNaNF;
  lab4_eval_P.UnitDelay_InitialCondition_l = rtNaNF;
  lab4_eval_P.UnitDelay_InitialCondition_j = rtNaNF;
  lab4_eval_P.UnitDelay_InitialCondition_m = rtNaNF;
  lab4_eval_P.UnitDelay_InitialCondition_l1 = rtNaNF;
  lab4_eval_P.UnitDelay_InitialCondition_i = rtNaNF;

  /* initialize real-time model */
  (void) memset((void *)lab4_eval_M, 0,
                sizeof(RT_MODEL_lab4_eval_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab4_eval_M->solverInfo,
                          &lab4_eval_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab4_eval_M->solverInfo, &rtmGetTPtr(lab4_eval_M));
    rtsiSetStepSizePtr(&lab4_eval_M->solverInfo, &lab4_eval_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab4_eval_M->solverInfo, &lab4_eval_M->derivs);
    rtsiSetContStatesPtr(&lab4_eval_M->solverInfo, (real_T **)
                         &lab4_eval_M->contStates);
    rtsiSetNumContStatesPtr(&lab4_eval_M->solverInfo,
      &lab4_eval_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab4_eval_M->solverInfo,
      &lab4_eval_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab4_eval_M->solverInfo,
      &lab4_eval_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab4_eval_M->solverInfo,
      &lab4_eval_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab4_eval_M->solverInfo, (&rtmGetErrorStatus
      (lab4_eval_M)));
    rtsiSetRTModelPtr(&lab4_eval_M->solverInfo, lab4_eval_M);
  }

  rtsiSetSimTimeStep(&lab4_eval_M->solverInfo, MAJOR_TIME_STEP);
  lab4_eval_M->intgData.f[0] = lab4_eval_M->odeF[0];
  lab4_eval_M->contStates = ((real_T *) &lab4_eval_X);
  rtsiSetSolverData(&lab4_eval_M->solverInfo, (void *)&lab4_eval_M->intgData);
  rtsiSetSolverName(&lab4_eval_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab4_eval_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab4_eval_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab4_eval_M->Timing.sampleTimes = (&lab4_eval_M->Timing.sampleTimesArray[0]);
    lab4_eval_M->Timing.offsetTimes = (&lab4_eval_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab4_eval_M->Timing.sampleTimes[0] = (0.0);
    lab4_eval_M->Timing.sampleTimes[1] = (0.002);
    lab4_eval_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    lab4_eval_M->Timing.offsetTimes[0] = (0.0);
    lab4_eval_M->Timing.offsetTimes[1] = (0.0);
    lab4_eval_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab4_eval_M, &lab4_eval_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab4_eval_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = lab4_eval_M->Timing.perTaskSampleHitsArray;
    lab4_eval_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    lab4_eval_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab4_eval_M, -1);
  lab4_eval_M->Timing.stepSize0 = 0.002;
  lab4_eval_M->Timing.stepSize1 = 0.002;
  lab4_eval_M->Timing.stepSize2 = 0.01;
  lab4_eval_M->solverInfoPtr = (&lab4_eval_M->solverInfo);
  lab4_eval_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lab4_eval_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lab4_eval_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  lab4_eval_M->blockIO = ((void *) &lab4_eval_B);
  (void) memset(((void *) &lab4_eval_B), 0,
                sizeof(B_lab4_eval_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      lab4_eval_B.x_k1_[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      lab4_eval_B.P_k1_[i] = 0.0;
    }

    lab4_eval_B.RateTransitionx = 0.0;
    lab4_eval_B.RateTransitiony = 0.0;
    lab4_eval_B.ElevationCounttorad = 0.0;
    lab4_eval_B.PitchCounttorad = 0.0;
    lab4_eval_B.TravelCounttorad = 0.0;
    lab4_eval_B.gamma_dot = 0.0;
    lab4_eval_B.zeta_dot = 0.0;
    lab4_eval_B.StreamFormattedRead1_o2 = 0.0F;
    lab4_eval_B.StreamFormattedRead1_o3 = 0.0F;
    lab4_eval_B.StreamFormattedRead1_o4 = 0.0F;
    lab4_eval_B.StreamFormattedRead1_o5 = 0.0F;
    lab4_eval_B.StreamFormattedRead1_o6 = 0.0F;
    lab4_eval_B.StreamFormattedRead1_o7 = 0.0F;
  }

  /* parameters */
  lab4_eval_M->defaultParam = ((real_T *)&lab4_eval_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab4_eval_X;
    lab4_eval_M->contStates = (x);
    (void) memset((void *)&lab4_eval_X, 0,
                  sizeof(X_lab4_eval_T));
  }

  /* states (dwork) */
  lab4_eval_M->dwork = ((void *) &lab4_eval_DW);
  (void) memset((void *)&lab4_eval_DW, 0,
                sizeof(DW_lab4_eval_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      lab4_eval_DW.DelayOneStep_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      lab4_eval_DW.DelayOneStep1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_eval_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_eval_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_eval_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_eval_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_eval_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_eval_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_eval_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab4_eval_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  lab4_eval_DW.RateTransitionx_Buffer0 = 0.0;
  lab4_eval_DW.RateTransitiony_Buffer0 = 0.0;
  lab4_eval_DW.HILWriteAnalog_Buffer[0] = 0.0;
  lab4_eval_DW.HILWriteAnalog_Buffer[1] = 0.0;
  lab4_eval_DW.p_last = 0.0;
  lab4_eval_DW.e_last = 0.0;
  lab4_eval_DW.UnitDelay_DSTATE = 0.0F;
  lab4_eval_DW.UnitDelay_DSTATE_d = 0.0F;
  lab4_eval_DW.UnitDelay_DSTATE_p = 0.0F;
  lab4_eval_DW.UnitDelay_DSTATE_l = 0.0F;
  lab4_eval_DW.UnitDelay_DSTATE_n = 0.0F;
  lab4_eval_DW.UnitDelay_DSTATE_dn = 0.0F;

  /* Initialize Sizes */
  lab4_eval_M->Sizes.numContStates = (5);/* Number of continuous states */
  lab4_eval_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab4_eval_M->Sizes.numY = (0);       /* Number of model outputs */
  lab4_eval_M->Sizes.numU = (0);       /* Number of model inputs */
  lab4_eval_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab4_eval_M->Sizes.numSampTimes = (3);/* Number of sample times */
  lab4_eval_M->Sizes.numBlocks = (83); /* Number of blocks */
  lab4_eval_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  lab4_eval_M->Sizes.numBlockPrms = (582);/* Sum of parameter "widths" */
  return lab4_eval_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
