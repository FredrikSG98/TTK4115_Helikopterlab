/*
 * lab3_init.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab3_init".
 *
 * Model version              : 11.61
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Oct 13 14:13:32 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab3_init.h"
#include "lab3_init_private.h"
#include "lab3_init_dt.h"

t_stream lab3_init_rtZt_stream = NULL;

/* Block signals (default storage) */
B_lab3_init_T lab3_init_B;

/* Continuous states */
X_lab3_init_T lab3_init_X;

/* Block states (default storage) */
DW_lab3_init_T lab3_init_DW;

/* Real-time model */
static RT_MODEL_lab3_init_T lab3_init_M_;
RT_MODEL_lab3_init_T *const lab3_init_M = &lab3_init_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(lab3_init_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(lab3_init_M, 2);
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
  if (lab3_init_M->Timing.TaskCounters.TID[1] == 0) {
    lab3_init_M->Timing.RateInteraction.TID1_2 =
      (lab3_init_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    lab3_init_M->Timing.perTaskSampleHits[5] =
      lab3_init_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (lab3_init_M->Timing.TaskCounters.TID[2])++;
  if ((lab3_init_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    lab3_init_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  lab3_init_derivatives();
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
void lab3_init_output0(void)           /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall2_o1;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_DeadZoney;
  int32_T rtb_StreamFormattedRead1_o8;
  int32_T rtb_StreamFormattedRead_o2;
  int32_T rtb_StreamCall2_o3;
  real_T tmp[9];
  real_T tmp_0[5];
  real_T rtb_Sum2[2];
  real_T euler_rates_tmp;
  real_T euler_rates_tmp_0;
  real_T rtb_Backgain;
  real_T rtb_Frontgain;
  int32_T Gain2_c_tmp;
  int32_T i;
  int32_T i_0;
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* set solver stop time */
    if (!(lab3_init_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lab3_init_M->solverInfo,
                            ((lab3_init_M->Timing.clockTickH0 + 1) *
        lab3_init_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lab3_init_M->solverInfo,
                            ((lab3_init_M->Timing.clockTick0 + 1) *
        lab3_init_M->Timing.stepSize0 + lab3_init_M->Timing.clockTickH0 *
        lab3_init_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lab3_init_M)) {
    lab3_init_M->Timing.t[0] = rtsiGetT(&lab3_init_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(lab3_init_DW.Skiptonextline_SubsysRanBC);
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: lab3_init/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(lab3_init_DW.HILReadEncoderTimebase_Task, 1,
        &lab3_init_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          lab3_init_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          lab3_init_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = lab3_init_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* S-Function (stream_call_block): '<S4>/Stream Call2' incorporates:
     *  Constant: '<S4>/Constant4'
     *  S-Function (string_constant_block): '<S4>/String Constant1'
     */

    /* S-Function Block: lab3_init/IMU_BT/Stream Call2 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (lab3_init_P.Constant4_Value != 0);
      rtb_StreamCall2_o1 = NULL;
      switch (lab3_init_DW.StreamCall2_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) lab3_init_P.StringConstant1_Value, 255) ==
                255) {
              rtmSetErrorStatus(lab3_init_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *) lab3_init_P.StringConstant1_Value,
                lab3_init_P.StreamCall2_NonBlocking != 0,
                lab3_init_P.StreamCall2_SendBufferSize,
                lab3_init_P.StreamCall2_ReceiveBufferSize,
                &lab3_init_DW.StreamCall2_Stream);
              if (result == 0) {
                lab3_init_DW.StreamCall2_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(lab3_init_DW.StreamCall2_Stream,
                                      (t_stream_byte_order)
                                      lab3_init_P.StreamCall2_Endian);
                rtb_StreamCall2_o1 = &lab3_init_DW.StreamCall2_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                lab3_init_DW.StreamCall2_State = STREAM_CALL_STATE_CONNECTING;
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

            result = stream_poll(lab3_init_DW.StreamCall2_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              lab3_init_DW.StreamCall2_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(lab3_init_DW.StreamCall2_Stream,
                                    (t_stream_byte_order)
                                    lab3_init_P.StreamCall2_Endian);
              rtb_StreamCall2_o1 = &lab3_init_DW.StreamCall2_Stream;
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
          rtb_StreamCall2_o1 = &lab3_init_DW.StreamCall2_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(lab3_init_DW.StreamCall2_Stream);
          if (close_result == 0) {
            lab3_init_DW.StreamCall2_State = STREAM_CALL_STATE_NOT_CONNECTED;
            lab3_init_DW.StreamCall2_Stream = NULL;
            rtb_StreamCall2_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      lab3_init_B.StreamCall2_o2 = lab3_init_DW.StreamCall2_State;
      rtb_StreamCall2_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_read_block): '<S4>/Stream Formatted Read1' */
    {
      t_error result;
      lab3_init_B.StreamFormattedRead1_o11 = false;
      if (rtb_StreamCall2_o1 != NULL) {
        result = stream_scan_utf8_char_array(*rtb_StreamCall2_o1,
          lab3_init_P.StreamFormattedRead1_MaxUnits,
          &rtb_StreamFormattedRead1_o8, " :%f,%f,%f,%f,%f,%f\r"
          , &lab3_init_B.StreamFormattedRead1_o2
          , &lab3_init_B.StreamFormattedRead1_o3
          , &lab3_init_B.StreamFormattedRead1_o4
          , &lab3_init_B.StreamFormattedRead1_o5
          , &lab3_init_B.StreamFormattedRead1_o6
          , &lab3_init_B.StreamFormattedRead1_o7
          );
        lab3_init_B.StreamFormattedRead1_o11 = (result == 0);
        if (result > 0) {
          result = 0;
        }
      } else {
        rtb_StreamFormattedRead1_o8 = 0;
        result = 0;
        lab3_init_B.StreamFormattedRead1_o2 = 0;
        lab3_init_B.StreamFormattedRead1_o3 = 0;
        lab3_init_B.StreamFormattedRead1_o4 = 0;
        lab3_init_B.StreamFormattedRead1_o5 = 0;
        lab3_init_B.StreamFormattedRead1_o6 = 0;
        lab3_init_B.StreamFormattedRead1_o7 = 0;
      }

      lab3_init_B.StreamFormattedRead1_o10 = (result ==
        -QERR_MISMATCHED_CHARACTER);
    }

    /* DataTypeConversion: '<S4>/Data Type Conversion2' */
    lab3_init_B.DataTypeConversion2[0] = lab3_init_B.StreamFormattedRead1_o5;
    lab3_init_B.DataTypeConversion2[1] = lab3_init_B.StreamFormattedRead1_o6;
    lab3_init_B.DataTypeConversion2[2] = lab3_init_B.StreamFormattedRead1_o7;

    /* UnitDelay: '<S8>/Unit Delay' */
    lab3_init_B.UnitDelay = lab3_init_DW.UnitDelay_DSTATE;

    /* RelationalOperator: '<S8>/Relational Operator' */
    lab3_init_B.RelationalOperator = (lab3_init_B.StreamFormattedRead1_o2 ==
      lab3_init_B.UnitDelay);

    /* UnitDelay: '<S9>/Unit Delay' */
    lab3_init_B.UnitDelay_k = lab3_init_DW.UnitDelay_DSTATE_d;

    /* RelationalOperator: '<S9>/Relational Operator' */
    lab3_init_B.RelationalOperator_o = (lab3_init_B.StreamFormattedRead1_o3 ==
      lab3_init_B.UnitDelay_k);

    /* UnitDelay: '<S10>/Unit Delay' */
    lab3_init_B.UnitDelay_g = lab3_init_DW.UnitDelay_DSTATE_p;

    /* RelationalOperator: '<S10>/Relational Operator' */
    lab3_init_B.RelationalOperator_g = (lab3_init_B.StreamFormattedRead1_o4 ==
      lab3_init_B.UnitDelay_g);

    /* UnitDelay: '<S11>/Unit Delay' */
    lab3_init_B.UnitDelay_n = lab3_init_DW.UnitDelay_DSTATE_l;

    /* RelationalOperator: '<S11>/Relational Operator' */
    lab3_init_B.RelationalOperator_p = (lab3_init_B.StreamFormattedRead1_o5 ==
      lab3_init_B.UnitDelay_n);

    /* UnitDelay: '<S12>/Unit Delay' */
    lab3_init_B.UnitDelay_m = lab3_init_DW.UnitDelay_DSTATE_n;

    /* RelationalOperator: '<S12>/Relational Operator' */
    lab3_init_B.RelationalOperator_a = (lab3_init_B.StreamFormattedRead1_o6 ==
      lab3_init_B.UnitDelay_m);

    /* UnitDelay: '<S13>/Unit Delay' */
    lab3_init_B.UnitDelay_i = lab3_init_DW.UnitDelay_DSTATE_dn;

    /* RelationalOperator: '<S13>/Relational Operator' */
    lab3_init_B.RelationalOperator_pg = (lab3_init_B.StreamFormattedRead1_o7 ==
      lab3_init_B.UnitDelay_i);

    /* Logic: '<S4>/Logical Operator1' incorporates:
     *  Logic: '<S4>/Logical Operator'
     */
    lab3_init_B.LogicalOperator1 = ((!lab3_init_B.RelationalOperator) ||
      (!lab3_init_B.RelationalOperator_o) || (!lab3_init_B.RelationalOperator_g)
      || (!lab3_init_B.RelationalOperator_p) ||
      (!lab3_init_B.RelationalOperator_a) || (!lab3_init_B.RelationalOperator_pg));

    /* DataTypeConversion: '<S4>/Data Type Conversion1' */
    lab3_init_B.DataTypeConversion1[0] = lab3_init_B.StreamFormattedRead1_o2;
    lab3_init_B.DataTypeConversion1[1] = lab3_init_B.StreamFormattedRead1_o3;
    lab3_init_B.DataTypeConversion1[2] = lab3_init_B.StreamFormattedRead1_o4;
    for (i = 0; i < 3; i++) {
      /* Gain: '<S4>/Gain1' */
      lab3_init_B.Gain1[i] = 0.0;

      /* Gain: '<S4>/Gain2' */
      lab3_init_B.Gain2[i] = 0.0;

      /* Gain: '<S4>/Gain1' */
      lab3_init_B.Gain1[i] += lab3_init_P.Gain1_Gain[i] *
        lab3_init_B.DataTypeConversion2[0];

      /* Gain: '<S4>/Gain2' */
      lab3_init_B.Gain2[i] += lab3_init_P.Gain2_Gain[i] *
        lab3_init_B.DataTypeConversion1[0];

      /* Gain: '<S4>/Gain1' */
      lab3_init_B.Gain1[i] += lab3_init_P.Gain1_Gain[i + 3] *
        lab3_init_B.DataTypeConversion2[1];

      /* Gain: '<S4>/Gain2' */
      lab3_init_B.Gain2[i] += lab3_init_P.Gain2_Gain[i + 3] *
        lab3_init_B.DataTypeConversion1[1];

      /* Gain: '<S4>/Gain1' */
      lab3_init_B.Gain1[i] += lab3_init_P.Gain1_Gain[i + 6] *
        lab3_init_B.DataTypeConversion2[2];

      /* Gain: '<S4>/Gain2' */
      lab3_init_B.Gain2[i] += lab3_init_P.Gain2_Gain[i + 6] *
        lab3_init_B.DataTypeConversion1[2];
    }

    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* MATLAB Function 'MATLAB Function': '<S6>:1' */
    if ((!lab3_init_DW.p_last_not_empty) || (!lab3_init_DW.e_last_not_empty)) {
      /* '<S6>:1:5' */
      /* '<S6>:1:6' */
      lab3_init_DW.p_last = 0.0;
      lab3_init_DW.p_last_not_empty = true;

      /* '<S6>:1:7' */
      lab3_init_DW.e_last = 0.0;
      lab3_init_DW.e_last_not_empty = true;
    }

    if (lab3_init_B.LogicalOperator1) {
      /* '<S6>:1:10' */
      /* '<S6>:1:11' */
      lab3_init_DW.p_last = rt_atan2d_snf(-lab3_init_B.Gain2[1],
        -lab3_init_B.Gain2[2]) + 0.08;

      /* '<S6>:1:12' */
      lab3_init_DW.e_last = rt_atan2d_snf(lab3_init_B.Gain2[0], sqrt
        (lab3_init_B.Gain2[1] * lab3_init_B.Gain2[1] + lab3_init_B.Gain2[2] *
         lab3_init_B.Gain2[2]));
    }

    /* '<S6>:1:14' */
    lab3_init_B.euler_angles[0] = lab3_init_DW.p_last;
    lab3_init_B.euler_angles[1] = lab3_init_DW.e_last;

    /* End of MATLAB Function: '<Root>/MATLAB Function' */

    /* Gain: '<S3>/Pitch: Count to rad' */
    lab3_init_B.PitchCounttorad = lab3_init_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;
  }

  for (i = 0; i < 5; i++) {
    /* Integrator: '<S7>/Integrator' */
    lab3_init_B.x_hat[i] = lab3_init_X.Integrator_CSTATE[i];
  }

  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travle rate]': '<S2>:1' */
    /* '<S2>:1:3' */
    /* '<S2>:1:4' */
    /* '<S2>:1:6' */
    /* '<S2>:1:9' */
    rtb_Backgain = tan(lab3_init_B.euler_angles[1]);
    rtb_Frontgain = sin(lab3_init_B.euler_angles[0]);
    euler_rates_tmp = cos(lab3_init_B.euler_angles[0]);
    euler_rates_tmp_0 = cos(lab3_init_B.euler_angles[1]);
    tmp[0] = 1.0;
    tmp[3] = rtb_Frontgain * rtb_Backgain;
    tmp[6] = euler_rates_tmp * rtb_Backgain;
    tmp[1] = 0.0;
    tmp[4] = euler_rates_tmp;
    tmp[7] = -rtb_Frontgain;
    tmp[2] = 0.0;
    tmp[5] = rtb_Frontgain / euler_rates_tmp_0;
    tmp[8] = euler_rates_tmp / euler_rates_tmp_0;
    for (i = 0; i < 3; i++) {
      lab3_init_B.euler_rates[i] = 0.0;
      lab3_init_B.euler_rates[i] += tmp[i] * lab3_init_B.Gain1[0];
      lab3_init_B.euler_rates[i] += tmp[i + 3] * lab3_init_B.Gain1[1];
      lab3_init_B.euler_rates[i] += tmp[i + 6] * lab3_init_B.Gain1[2];
    }

    /* End of MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' */

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     *  Gain: '<S3>/Elevation: Count to rad'
     */
    lab3_init_B.Sum = lab3_init_P.ElevationCounttorad_Gain * rtb_DeadZoney +
      lab3_init_P.ELEV_OFFSET;
  }

  /* TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  lab3_init_B.PitchTransferFcn = 0.0;
  lab3_init_B.PitchTransferFcn += lab3_init_P.PitchTransferFcn_C *
    lab3_init_X.PitchTransferFcn_CSTATE;
  lab3_init_B.PitchTransferFcn += lab3_init_P.PitchTransferFcn_D *
    lab3_init_B.PitchCounttorad;

  /* TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  lab3_init_B.ElevationTransferFcn = 0.0;
  lab3_init_B.ElevationTransferFcn += lab3_init_P.ElevationTransferFcn_C *
    lab3_init_X.ElevationTransferFcn_CSTATE;
  lab3_init_B.ElevationTransferFcn += lab3_init_P.ElevationTransferFcn_D *
    lab3_init_B.Sum;
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* Gain: '<Root>/Gain2' */
    lab3_init_B.Gain2_e = lab3_init_P.Gain2_Gain_d * lab3_init_B.euler_rates[2];

    /* Gain: '<S3>/Travel: Count to rad' */
    lab3_init_B.TravelCounttorad = lab3_init_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S3>/Travel: Transfer Fcn' */
  lab3_init_B.TravelTransferFcn = 0.0;
  lab3_init_B.TravelTransferFcn += lab3_init_P.TravelTransferFcn_C *
    lab3_init_X.TravelTransferFcn_CSTATE;
  lab3_init_B.TravelTransferFcn += lab3_init_P.TravelTransferFcn_D *
    lab3_init_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* RateTransition: '<S5>/Rate Transition: x' */
    if (lab3_init_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S5>/Rate Transition: x' */
      lab3_init_B.RateTransitionx = lab3_init_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S5>/Rate Transition: x' */

    /* DeadZone: '<S5>/Dead Zone: x' */
    if (lab3_init_B.RateTransitionx > lab3_init_P.DeadZonex_End) {
      /* DeadZone: '<S5>/Dead Zone: y' */
      rtb_DeadZoney = lab3_init_B.RateTransitionx - lab3_init_P.DeadZonex_End;
    } else if (lab3_init_B.RateTransitionx >= lab3_init_P.DeadZonex_Start) {
      /* DeadZone: '<S5>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S5>/Dead Zone: y' */
      rtb_DeadZoney = lab3_init_B.RateTransitionx - lab3_init_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S5>/Dead Zone: x' */

    /* Gain: '<S5>/Joystick_gain_x' incorporates:
     *  Gain: '<S5>/Gain: x'
     */
    lab3_init_B.Joystick_gain_x = lab3_init_P.Gainx_Gain * rtb_DeadZoney *
      lab3_init_P.Joystick_gain_x;

    /* RateTransition: '<S5>/Rate Transition: y' */
    if (lab3_init_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S5>/Rate Transition: y' */
      lab3_init_B.RateTransitiony = lab3_init_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S5>/Rate Transition: y' */

    /* DeadZone: '<S5>/Dead Zone: y' */
    if (lab3_init_B.RateTransitiony > lab3_init_P.DeadZoney_End) {
      /* DeadZone: '<S5>/Dead Zone: y' */
      rtb_DeadZoney = lab3_init_B.RateTransitiony - lab3_init_P.DeadZoney_End;
    } else if (lab3_init_B.RateTransitiony >= lab3_init_P.DeadZoney_Start) {
      /* DeadZone: '<S5>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S5>/Dead Zone: y' */
      rtb_DeadZoney = lab3_init_B.RateTransitiony - lab3_init_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S5>/Dead Zone: y' */

    /* Gain: '<S5>/Joystick_gain_y' incorporates:
     *  Gain: '<S5>/Gain: y'
     */
    lab3_init_B.Joystick_gain_y = lab3_init_P.Gainy_Gain * rtb_DeadZoney *
      lab3_init_P.Joystick_gain_y;

    /* Gain: '<Root>/Gain' incorporates:
     *  SignalConversion generated from: '<Root>/Gain'
     */
    lab3_init_B.Gain[0] = 0.0;
    lab3_init_B.Gain[0] += lab3_init_P.F[0] * lab3_init_B.Joystick_gain_x;
    lab3_init_B.Gain[0] += lab3_init_P.F[2] * lab3_init_B.Joystick_gain_y;
    lab3_init_B.Gain[1] = 0.0;
    lab3_init_B.Gain[1] += lab3_init_P.F[1] * lab3_init_B.Joystick_gain_x;
    lab3_init_B.Gain[1] += lab3_init_P.F[3] * lab3_init_B.Joystick_gain_y;
  }

  /* SignalConversion generated from: '<Root>/Gain1' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  Integrator: '<Root>/Integrator1'
   */
  tmp_0[0] = lab3_init_B.x_hat[0];
  tmp_0[1] = lab3_init_B.x_hat[1];
  tmp_0[2] = lab3_init_B.x_hat[3];
  tmp_0[3] = lab3_init_X.Integrator_CSTATE_g;
  tmp_0[4] = lab3_init_X.Integrator1_CSTATE;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  for (i = 0; i < 2; i++) {
    rtb_Backgain = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Backgain += lab3_init_P.K[(i_0 << 1) + i] * tmp_0[i_0];
    }

    rtb_Sum2[i] = lab3_init_B.Gain[i] - rtb_Backgain;
  }

  /* End of Sum: '<Root>/Sum2' */

  /* Sum: '<Root>/Sum6' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_Backgain = rtb_Sum2[1] + lab3_init_P.Constant2_Value;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Frontgain = rtb_Sum2[0] + lab3_init_P.V_s_0;
  if (rtmIsMajorTimeStep(lab3_init_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  euler_rates_tmp = (rtb_Frontgain - rtb_Backgain) * lab3_init_P.Frontgain_Gain;

  /* Saturate: '<S3>/Front motor: Saturation' */
  if (euler_rates_tmp > lab3_init_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S3>/Front motor: Saturation' */
    lab3_init_B.FrontmotorSaturation = lab3_init_P.FrontmotorSaturation_UpperSat;
  } else if (euler_rates_tmp < lab3_init_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S3>/Front motor: Saturation' */
    lab3_init_B.FrontmotorSaturation = lab3_init_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S3>/Front motor: Saturation' */
    lab3_init_B.FrontmotorSaturation = euler_rates_tmp;
  }

  /* End of Saturate: '<S3>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  euler_rates_tmp = (rtb_Frontgain + rtb_Backgain) * lab3_init_P.Backgain_Gain;

  /* Saturate: '<S3>/Back motor: Saturation' */
  if (euler_rates_tmp > lab3_init_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S3>/Back motor: Saturation' */
    lab3_init_B.BackmotorSaturation = lab3_init_P.BackmotorSaturation_UpperSat;
  } else if (euler_rates_tmp < lab3_init_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S3>/Back motor: Saturation' */
    lab3_init_B.BackmotorSaturation = lab3_init_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S3>/Back motor: Saturation' */
    lab3_init_B.BackmotorSaturation = euler_rates_tmp;
  }

  /* End of Saturate: '<S3>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: lab3_init/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      lab3_init_DW.HILWriteAnalog_Buffer[0] = lab3_init_B.FrontmotorSaturation;
      lab3_init_DW.HILWriteAnalog_Buffer[1] = lab3_init_B.BackmotorSaturation;
      result = hil_write_analog(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILWriteAnalog_channels, 2,
        &lab3_init_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
      }
    }

    /* Outputs for Enabled SubSystem: '<S4>/Skip to next line' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    if (lab3_init_B.StreamFormattedRead1_o10) {
      /* S-Function (stream_formatted_read_block): '<S14>/Stream Formatted Read' incorporates:
       *  S-Function (stream_call_block): '<S4>/Stream Call2'
       *  S-Function (stream_formatted_read_block): '<S4>/Stream Formatted Read1'
       */
      {
        if (((t_stream_ptr)rtb_StreamCall2_o1) != NULL) {
          stream_scan_utf8_char_array(*((t_stream_ptr)rtb_StreamCall2_o1),
            lab3_init_P.StreamFormattedRead_MaxUnits,
            &rtb_StreamFormattedRead_o2, " %*[^\r]"
            );
        } else {
          rtb_StreamFormattedRead_o2 = 0;
        }
      }

      if (rtmIsMajorTimeStep(lab3_init_M)) {
        srUpdateBC(lab3_init_DW.Skiptonextline_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S4>/Skip to next line' */

    /* S-Function (stop_with_error_block): '<S4>/Stop with Error' */

    /* S-Function Block: lab3_init/IMU_BT/Stop with Error (stop_with_error_block) */
    {
      if (rtb_StreamCall2_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall2_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }

    /* SignalConversion generated from: '<S7>/Gain4' */
    tmp_0[0] = lab3_init_B.euler_angles[0];
    tmp_0[1] = lab3_init_B.euler_rates[0];
    tmp_0[2] = lab3_init_B.euler_angles[1];
    tmp_0[3] = lab3_init_B.euler_rates[1];
    tmp_0[4] = lab3_init_B.Gain2_e;
    for (i = 0; i < 5; i++) {
      /* Gain: '<S7>/Gain4' */
      lab3_init_B.Gain4[i] = 0.0;
      for (i_0 = 0; i_0 < 5; i_0++) {
        lab3_init_B.Gain4[i] += lab3_init_P.C_est[5 * i_0 + i] * tmp_0[i_0];
      }

      /* End of Gain: '<S7>/Gain4' */
    }
  }

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S7>/Gain3'
   */
  for (i = 0; i < 5; i++) {
    rtb_Backgain = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Backgain += lab3_init_P.C_est[5 * i_0 + i] * lab3_init_B.x_hat[i_0];
    }

    tmp_0[i] = lab3_init_B.Gain4[i] - rtb_Backgain;
  }

  /* End of Sum: '<S7>/Sum1' */
  for (i = 0; i < 5; i++) {
    /* Gain: '<S7>/Gain2' */
    lab3_init_B.Gain2_c[i] = 0.0;

    /* Gain: '<S7>/Gain1' */
    lab3_init_B.Gain1_i[i] = 0.0;
    lab3_init_B.Gain1_i[i] += lab3_init_P.B_est[i] * rtb_Sum2[0];
    lab3_init_B.Gain1_i[i] += lab3_init_P.B_est[i + 5] * rtb_Sum2[1];

    /* Gain: '<S7>/Gain' */
    lab3_init_B.Gain_i[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      /* Gain: '<S7>/Gain2' incorporates:
       *  Gain: '<S7>/Gain'
       */
      Gain2_c_tmp = 5 * i_0 + i;

      /* Gain: '<S7>/Gain2' */
      lab3_init_B.Gain2_c[i] += lab3_init_P.L_est[Gain2_c_tmp] * tmp_0[i_0];

      /* Gain: '<S7>/Gain' */
      lab3_init_B.Gain_i[i] += lab3_init_P.A_est[Gain2_c_tmp] *
        lab3_init_B.x_hat[i_0];
    }
  }

  if (rtmIsMajorTimeStep(lab3_init_M)) {
  }

  for (i = 0; i < 5; i++) {
    /* Sum: '<S7>/Sum' */
    lab3_init_B.x_hat_dot[i] = (lab3_init_B.Gain2_c[i] + lab3_init_B.Gain1_i[i])
      + lab3_init_B.Gain_i[i];
  }

  /* Sum: '<Root>/Sum4' */
  lab3_init_B.gamma_dot = lab3_init_B.Joystick_gain_x - lab3_init_B.x_hat[0];

  /* Sum: '<Root>/Sum5' */
  lab3_init_B.zeta_dot = lab3_init_B.Joystick_gain_y - lab3_init_B.x_hat[3];
}

/* Model update function for TID0 */
void lab3_init_update0(void)           /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* Update for UnitDelay: '<S8>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE = lab3_init_B.StreamFormattedRead1_o2;

    /* Update for UnitDelay: '<S9>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_d = lab3_init_B.StreamFormattedRead1_o3;

    /* Update for UnitDelay: '<S10>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_p = lab3_init_B.StreamFormattedRead1_o4;

    /* Update for UnitDelay: '<S11>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_l = lab3_init_B.StreamFormattedRead1_o5;

    /* Update for UnitDelay: '<S12>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_n = lab3_init_B.StreamFormattedRead1_o6;

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_dn = lab3_init_B.StreamFormattedRead1_o7;
  }

  if (rtmIsMajorTimeStep(lab3_init_M)) {
    rt_ertODEUpdateContinuousStates(&lab3_init_M->solverInfo);
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
  if (!(++lab3_init_M->Timing.clockTick0)) {
    ++lab3_init_M->Timing.clockTickH0;
  }

  lab3_init_M->Timing.t[0] = rtsiGetSolverStopTime(&lab3_init_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab3_init_M->Timing.clockTick1)) {
    ++lab3_init_M->Timing.clockTickH1;
  }

  lab3_init_M->Timing.t[1] = lab3_init_M->Timing.clockTick1 *
    lab3_init_M->Timing.stepSize1 + lab3_init_M->Timing.clockTickH1 *
    lab3_init_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void lab3_init_derivatives(void)
{
  XDot_lab3_init_T *_rtXdot;
  int32_T i;
  _rtXdot = ((XDot_lab3_init_T *) lab3_init_M->derivs);

  /* Derivatives for Integrator: '<S7>/Integrator' */
  for (i = 0; i < 5; i++) {
    _rtXdot->Integrator_CSTATE[i] = lab3_init_B.x_hat_dot[i];
  }

  /* End of Derivatives for Integrator: '<S7>/Integrator' */

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += lab3_init_P.PitchTransferFcn_A *
    lab3_init_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += lab3_init_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += lab3_init_P.ElevationTransferFcn_A *
    lab3_init_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += lab3_init_B.Sum;

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += lab3_init_P.TravelTransferFcn_A *
    lab3_init_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += lab3_init_B.TravelCounttorad;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = lab3_init_B.gamma_dot;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = lab3_init_B.zeta_dot;
}

/* Model output function for TID2 */
void lab3_init_output2(void)           /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S5>/Game Controller' */

  /* S-Function Block: lab3_init/Joystick/Game Controller (game_controller_block) */
  {
    if (lab3_init_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(lab3_init_DW.GameController_Controller,
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

  /* RateTransition: '<S5>/Rate Transition: x' */
  lab3_init_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S5>/Rate Transition: y' */
  lab3_init_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void lab3_init_update2(void)           /* Sample time: [0.01s, 0.0s] */
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
  if (!(++lab3_init_M->Timing.clockTick2)) {
    ++lab3_init_M->Timing.clockTickH2;
  }

  lab3_init_M->Timing.t[2] = lab3_init_M->Timing.clockTick2 *
    lab3_init_M->Timing.stepSize2 + lab3_init_M->Timing.clockTickH2 *
    lab3_init_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void lab3_init_output(int_T tid)
{
  switch (tid) {
   case 0 :
    lab3_init_output0();
    break;

   case 2 :
    lab3_init_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void lab3_init_update(int_T tid)
{
  switch (tid) {
   case 0 :
    lab3_init_update0();
    break;

   case 2 :
    lab3_init_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void lab3_init_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab3_init/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &lab3_init_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab3_init_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(lab3_init_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab3_init_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(lab3_init_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab3_init_M, _rt_error_message);
      return;
    }

    if ((lab3_init_P.HILInitialize_AIPStart && !is_switching) ||
        (lab3_init_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &lab3_init_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (lab3_init_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &lab3_init_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = lab3_init_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILInitialize_AIChannels, 8U,
        &lab3_init_DW.HILInitialize_AIMinimums[0],
        &lab3_init_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }

    if ((lab3_init_P.HILInitialize_AOPStart && !is_switching) ||
        (lab3_init_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &lab3_init_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (lab3_init_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &lab3_init_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = lab3_init_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILInitialize_AOChannels, 8U,
        &lab3_init_DW.HILInitialize_AOMinimums[0],
        &lab3_init_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }

    if ((lab3_init_P.HILInitialize_AOStart && !is_switching) ||
        (lab3_init_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab3_init_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab3_init_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILInitialize_AOChannels, 8U,
        &lab3_init_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }

    if (lab3_init_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab3_init_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab3_init_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (lab3_init_DW.HILInitialize_Card, lab3_init_P.HILInitialize_AOChannels,
         8U, &lab3_init_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }

    if ((lab3_init_P.HILInitialize_EIPStart && !is_switching) ||
        (lab3_init_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &lab3_init_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = lab3_init_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &lab3_init_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }

    if ((lab3_init_P.HILInitialize_EIStart && !is_switching) ||
        (lab3_init_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &lab3_init_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = lab3_init_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILInitialize_EIChannels, 8U,
        &lab3_init_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }

    if ((lab3_init_P.HILInitialize_POPStart && !is_switching) ||
        (lab3_init_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab3_init_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab3_init_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &lab3_init_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          lab3_init_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &lab3_init_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            lab3_init_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            lab3_init_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              lab3_init_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            lab3_init_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            lab3_init_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              lab3_init_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(lab3_init_DW.HILInitialize_Card,
          &lab3_init_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &lab3_init_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab3_init_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(lab3_init_DW.HILInitialize_Card,
          &lab3_init_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &lab3_init_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab3_init_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &lab3_init_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = lab3_init_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &lab3_init_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = lab3_init_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &lab3_init_DW.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = lab3_init_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &lab3_init_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &lab3_init_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &lab3_init_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &lab3_init_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = lab3_init_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &lab3_init_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab3_init_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILInitialize_POChannels, 8U,
        &lab3_init_DW.HILInitialize_POSortedFreqs[0],
        &lab3_init_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }

    if ((lab3_init_P.HILInitialize_POStart && !is_switching) ||
        (lab3_init_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab3_init_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab3_init_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(lab3_init_DW.HILInitialize_Card,
        lab3_init_P.HILInitialize_POChannels, 8U,
        &lab3_init_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }

    if (lab3_init_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &lab3_init_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab3_init_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (lab3_init_DW.HILInitialize_Card, lab3_init_P.HILInitialize_POChannels,
         8U, &lab3_init_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: lab3_init/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(lab3_init_DW.HILInitialize_Card,
      lab3_init_P.HILReadEncoderTimebase_SamplesI,
      lab3_init_P.HILReadEncoderTimebase_Channels, 3,
      &lab3_init_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (lab3_init_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (lab3_init_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(lab3_init_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_call_block): '<S4>/Stream Call2' incorporates:
   *  Constant: '<S4>/Constant4'
   *  S-Function (string_constant_block): '<S4>/String Constant1'
   */

  /* S-Function Block: lab3_init/IMU_BT/Stream Call2 (stream_call_block) */
  {
    lab3_init_DW.StreamCall2_State = STREAM_CALL_STATE_NOT_CONNECTED;
    lab3_init_DW.StreamCall2_Stream = NULL;
  }

  /* Start for RateTransition: '<S5>/Rate Transition: x' */
  lab3_init_B.RateTransitionx = lab3_init_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S5>/Rate Transition: y' */
  lab3_init_B.RateTransitiony = lab3_init_P.RateTransitiony_InitialConditio;

  /* Start for S-Function (game_controller_block): '<S5>/Game Controller' */

  /* S-Function Block: lab3_init/Joystick/Game Controller (game_controller_block) */
  {
    if (lab3_init_P.GameController_Enabled) {
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

      result = game_controller_open(lab3_init_P.GameController_ControllerNumber,
        lab3_init_P.GameController_BufferSize, deadzone, saturation,
        lab3_init_P.GameController_AutoCenter, 0, 1.0,
        &lab3_init_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE = lab3_init_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_d = lab3_init_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_p = lab3_init_P.UnitDelay_InitialCondition_j;

    /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_l = lab3_init_P.UnitDelay_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_n = lab3_init_P.UnitDelay_InitialCondition_l1;

    /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_dn = lab3_init_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    for (i = 0; i < 5; i++) {
      lab3_init_X.Integrator_CSTATE[i] = lab3_init_P.Integrator_IC;
    }

    /* End of InitializeConditions for Integrator: '<S7>/Integrator' */

    /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
    lab3_init_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
    lab3_init_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
    lab3_init_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition: x' */
    lab3_init_DW.RateTransitionx_Buffer0 =
      lab3_init_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition: y' */
    lab3_init_DW.RateTransitiony_Buffer0 =
      lab3_init_P.RateTransitiony_InitialConditio;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    lab3_init_X.Integrator_CSTATE_g = lab3_init_P.Integrator_IC_a;

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    lab3_init_X.Integrator1_CSTATE = lab3_init_P.Integrator1_IC;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
    lab3_init_DW.p_last_not_empty = false;
    lab3_init_DW.e_last_not_empty = false;
  }
}

/* Model terminate function */
void lab3_init_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: lab3_init/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(lab3_init_DW.HILInitialize_Card);
    hil_monitor_stop_all(lab3_init_DW.HILInitialize_Card);
    is_switching = false;
    if ((lab3_init_P.HILInitialize_AOTerminate && !is_switching) ||
        (lab3_init_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &lab3_init_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = lab3_init_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((lab3_init_P.HILInitialize_POTerminate && !is_switching) ||
        (lab3_init_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &lab3_init_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = lab3_init_P.HILInitialize_POFinal;
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
      result = hil_write(lab3_init_DW.HILInitialize_Card
                         , lab3_init_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , lab3_init_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &lab3_init_DW.HILInitialize_AOVoltages[0]
                         , &lab3_init_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(lab3_init_DW.HILInitialize_Card,
            lab3_init_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &lab3_init_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(lab3_init_DW.HILInitialize_Card,
            lab3_init_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &lab3_init_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(lab3_init_DW.HILInitialize_Card);
    hil_monitor_delete_all(lab3_init_DW.HILInitialize_Card);
    hil_close(lab3_init_DW.HILInitialize_Card);
    lab3_init_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S4>/Stream Call2' incorporates:
   *  Constant: '<S4>/Constant4'
   *  S-Function (string_constant_block): '<S4>/String Constant1'
   */

  /* S-Function Block: lab3_init/IMU_BT/Stream Call2 (stream_call_block) */
  {
    if (lab3_init_DW.StreamCall2_Stream != NULL) {
      stream_close(lab3_init_DW.StreamCall2_Stream);
      lab3_init_DW.StreamCall2_Stream = NULL;
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S5>/Game Controller' */

  /* S-Function Block: lab3_init/Joystick/Game Controller (game_controller_block) */
  {
    if (lab3_init_P.GameController_Enabled) {
      game_controller_close(lab3_init_DW.GameController_Controller);
      lab3_init_DW.GameController_Controller = NULL;
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
  lab3_init_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab3_init_update(tid);
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
  lab3_init_initialize();
}

void MdlTerminate(void)
{
  lab3_init_terminate();
}

/* Registration function */
RT_MODEL_lab3_init_T *lab3_init(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  lab3_init_P.UnitDelay_InitialCondition = rtNaNF;
  lab3_init_P.UnitDelay_InitialCondition_l = rtNaNF;
  lab3_init_P.UnitDelay_InitialCondition_j = rtNaNF;
  lab3_init_P.UnitDelay_InitialCondition_m = rtNaNF;
  lab3_init_P.UnitDelay_InitialCondition_l1 = rtNaNF;
  lab3_init_P.UnitDelay_InitialCondition_i = rtNaNF;

  /* initialize real-time model */
  (void) memset((void *)lab3_init_M, 0,
                sizeof(RT_MODEL_lab3_init_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab3_init_M->solverInfo,
                          &lab3_init_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab3_init_M->solverInfo, &rtmGetTPtr(lab3_init_M));
    rtsiSetStepSizePtr(&lab3_init_M->solverInfo, &lab3_init_M->Timing.stepSize0);
    rtsiSetdXPtr(&lab3_init_M->solverInfo, &lab3_init_M->derivs);
    rtsiSetContStatesPtr(&lab3_init_M->solverInfo, (real_T **)
                         &lab3_init_M->contStates);
    rtsiSetNumContStatesPtr(&lab3_init_M->solverInfo,
      &lab3_init_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lab3_init_M->solverInfo,
      &lab3_init_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lab3_init_M->solverInfo,
      &lab3_init_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lab3_init_M->solverInfo,
      &lab3_init_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lab3_init_M->solverInfo, (&rtmGetErrorStatus
      (lab3_init_M)));
    rtsiSetRTModelPtr(&lab3_init_M->solverInfo, lab3_init_M);
  }

  rtsiSetSimTimeStep(&lab3_init_M->solverInfo, MAJOR_TIME_STEP);
  lab3_init_M->intgData.f[0] = lab3_init_M->odeF[0];
  lab3_init_M->contStates = ((real_T *) &lab3_init_X);
  rtsiSetSolverData(&lab3_init_M->solverInfo, (void *)&lab3_init_M->intgData);
  rtsiSetSolverName(&lab3_init_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab3_init_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    lab3_init_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab3_init_M->Timing.sampleTimes = (&lab3_init_M->Timing.sampleTimesArray[0]);
    lab3_init_M->Timing.offsetTimes = (&lab3_init_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab3_init_M->Timing.sampleTimes[0] = (0.0);
    lab3_init_M->Timing.sampleTimes[1] = (0.002);
    lab3_init_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    lab3_init_M->Timing.offsetTimes[0] = (0.0);
    lab3_init_M->Timing.offsetTimes[1] = (0.0);
    lab3_init_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab3_init_M, &lab3_init_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab3_init_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = lab3_init_M->Timing.perTaskSampleHitsArray;
    lab3_init_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    lab3_init_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab3_init_M, -1);
  lab3_init_M->Timing.stepSize0 = 0.002;
  lab3_init_M->Timing.stepSize1 = 0.002;
  lab3_init_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  lab3_init_M->Sizes.checksums[0] = (3722332900U);
  lab3_init_M->Sizes.checksums[1] = (1604340118U);
  lab3_init_M->Sizes.checksums[2] = (2396975944U);
  lab3_init_M->Sizes.checksums[3] = (2866133730U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    lab3_init_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&lab3_init_DW.Skiptonextline_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab3_init_M->extModeInfo,
      &lab3_init_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab3_init_M->extModeInfo, lab3_init_M->Sizes.checksums);
    rteiSetTPtr(lab3_init_M->extModeInfo, rtmGetTPtr(lab3_init_M));
  }

  lab3_init_M->solverInfoPtr = (&lab3_init_M->solverInfo);
  lab3_init_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lab3_init_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lab3_init_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  lab3_init_M->blockIO = ((void *) &lab3_init_B);
  (void) memset(((void *) &lab3_init_B), 0,
                sizeof(B_lab3_init_T));

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      lab3_init_B.x_hat[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab3_init_B.Gain4[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab3_init_B.Gain2_c[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab3_init_B.Gain1_i[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab3_init_B.Gain_i[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab3_init_B.x_hat_dot[i] = 0.0;
    }

    lab3_init_B.DataTypeConversion2[0] = 0.0;
    lab3_init_B.DataTypeConversion2[1] = 0.0;
    lab3_init_B.DataTypeConversion2[2] = 0.0;
    lab3_init_B.Gain1[0] = 0.0;
    lab3_init_B.Gain1[1] = 0.0;
    lab3_init_B.Gain1[2] = 0.0;
    lab3_init_B.DataTypeConversion1[0] = 0.0;
    lab3_init_B.DataTypeConversion1[1] = 0.0;
    lab3_init_B.DataTypeConversion1[2] = 0.0;
    lab3_init_B.Gain2[0] = 0.0;
    lab3_init_B.Gain2[1] = 0.0;
    lab3_init_B.Gain2[2] = 0.0;
    lab3_init_B.PitchCounttorad = 0.0;
    lab3_init_B.PitchTransferFcn = 0.0;
    lab3_init_B.Sum = 0.0;
    lab3_init_B.ElevationTransferFcn = 0.0;
    lab3_init_B.Gain2_e = 0.0;
    lab3_init_B.TravelCounttorad = 0.0;
    lab3_init_B.TravelTransferFcn = 0.0;
    lab3_init_B.RateTransitionx = 0.0;
    lab3_init_B.Joystick_gain_x = 0.0;
    lab3_init_B.RateTransitiony = 0.0;
    lab3_init_B.Joystick_gain_y = 0.0;
    lab3_init_B.Gain[0] = 0.0;
    lab3_init_B.Gain[1] = 0.0;
    lab3_init_B.FrontmotorSaturation = 0.0;
    lab3_init_B.BackmotorSaturation = 0.0;
    lab3_init_B.gamma_dot = 0.0;
    lab3_init_B.zeta_dot = 0.0;
    lab3_init_B.euler_angles[0] = 0.0;
    lab3_init_B.euler_angles[1] = 0.0;
    lab3_init_B.euler_rates[0] = 0.0;
    lab3_init_B.euler_rates[1] = 0.0;
    lab3_init_B.euler_rates[2] = 0.0;
    lab3_init_B.StreamFormattedRead1_o2 = 0.0F;
    lab3_init_B.StreamFormattedRead1_o3 = 0.0F;
    lab3_init_B.StreamFormattedRead1_o4 = 0.0F;
    lab3_init_B.StreamFormattedRead1_o5 = 0.0F;
    lab3_init_B.StreamFormattedRead1_o6 = 0.0F;
    lab3_init_B.StreamFormattedRead1_o7 = 0.0F;
    lab3_init_B.UnitDelay = 0.0F;
    lab3_init_B.UnitDelay_k = 0.0F;
    lab3_init_B.UnitDelay_g = 0.0F;
    lab3_init_B.UnitDelay_n = 0.0F;
    lab3_init_B.UnitDelay_m = 0.0F;
    lab3_init_B.UnitDelay_i = 0.0F;
  }

  /* parameters */
  lab3_init_M->defaultParam = ((real_T *)&lab3_init_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lab3_init_X;
    lab3_init_M->contStates = (x);
    (void) memset((void *)&lab3_init_X, 0,
                  sizeof(X_lab3_init_T));
  }

  /* states (dwork) */
  lab3_init_M->dwork = ((void *) &lab3_init_DW);
  (void) memset((void *)&lab3_init_DW, 0,
                sizeof(DW_lab3_init_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab3_init_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab3_init_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab3_init_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab3_init_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab3_init_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab3_init_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab3_init_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      lab3_init_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  lab3_init_DW.RateTransitionx_Buffer0 = 0.0;
  lab3_init_DW.RateTransitiony_Buffer0 = 0.0;
  lab3_init_DW.HILWriteAnalog_Buffer[0] = 0.0;
  lab3_init_DW.HILWriteAnalog_Buffer[1] = 0.0;
  lab3_init_DW.p_last = 0.0;
  lab3_init_DW.e_last = 0.0;
  lab3_init_DW.UnitDelay_DSTATE = 0.0F;
  lab3_init_DW.UnitDelay_DSTATE_d = 0.0F;
  lab3_init_DW.UnitDelay_DSTATE_p = 0.0F;
  lab3_init_DW.UnitDelay_DSTATE_l = 0.0F;
  lab3_init_DW.UnitDelay_DSTATE_n = 0.0F;
  lab3_init_DW.UnitDelay_DSTATE_dn = 0.0F;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab3_init_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab3_init_M->Sizes.numContStates = (10);/* Number of continuous states */
  lab3_init_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  lab3_init_M->Sizes.numY = (0);       /* Number of model outputs */
  lab3_init_M->Sizes.numU = (0);       /* Number of model inputs */
  lab3_init_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab3_init_M->Sizes.numSampTimes = (3);/* Number of sample times */
  lab3_init_M->Sizes.numBlocks = (104);/* Number of blocks */
  lab3_init_M->Sizes.numBlockIO = (50);/* Number of block outputs */
  lab3_init_M->Sizes.numBlockPrms = (530);/* Sum of parameter "widths" */
  return lab3_init_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
