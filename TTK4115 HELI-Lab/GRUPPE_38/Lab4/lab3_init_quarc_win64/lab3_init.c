/*
 * lab3_init.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lab3_init".
 *
 * Model version              : 11.104
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Oct 27 13:49:42 2026
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
  real_T rtb_TmpSignalConversionAtToFile[27];
  real_T rtb_DeadZoney;
  int32_T rtb_StreamFormattedRead1_o8;
  int32_T rtb_StreamFormattedRead_o2;
  int32_T rtb_StreamCall2_o3;
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
  real_T tmp_3[9];
  real_T tmp_1[6];
  real_T tmp_2[6];
  real_T x_k_[6];
  real_T tmp_4[5];
  real_T tmp_5[5];
  real_T tmp_6[5];
  real_T tmp[2];
  real_T tmp_0[2];
  real_T euler_rates_tmp;
  real_T euler_rates_tmp_0;
  real_T rtb_Frontgain;
  real_T smax;
  real_T tmp_7;
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
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

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

    /* S-Function (stream_call_block): '<S10>/Stream Call2' incorporates:
     *  Constant: '<S10>/Constant4'
     *  S-Function (string_constant_block): '<S10>/String Constant1'
     */

    /* S-Function Block: lab3_init/IMU_data/IMU_BT/Stream Call2 (stream_call_block) */
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

    /* S-Function (stream_formatted_read_block): '<S10>/Stream Formatted Read1' */
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

    /* DataTypeConversion: '<S10>/Data Type Conversion1' */
    lab3_init_B.DataTypeConversion1[0] = lab3_init_B.StreamFormattedRead1_o2;
    lab3_init_B.DataTypeConversion1[1] = lab3_init_B.StreamFormattedRead1_o3;
    lab3_init_B.DataTypeConversion1[2] = lab3_init_B.StreamFormattedRead1_o4;
    for (i = 0; i < 3; i++) {
      /* Gain: '<S10>/Gain2' */
      lab3_init_B.Gain2[i] = 0.0;
      lab3_init_B.Gain2[i] += lab3_init_P.Gain2_Gain[i] *
        lab3_init_B.DataTypeConversion1[0];
      lab3_init_B.Gain2[i] += lab3_init_P.Gain2_Gain[i + 3] *
        lab3_init_B.DataTypeConversion1[1];
      lab3_init_B.Gain2[i] += lab3_init_P.Gain2_Gain[i + 6] *
        lab3_init_B.DataTypeConversion1[2];
    }

    /* UnitDelay: '<S12>/Unit Delay' */
    lab3_init_B.UnitDelay = lab3_init_DW.UnitDelay_DSTATE;

    /* RelationalOperator: '<S12>/Relational Operator' */
    lab3_init_B.RelationalOperator = (lab3_init_B.StreamFormattedRead1_o2 ==
      lab3_init_B.UnitDelay);

    /* UnitDelay: '<S13>/Unit Delay' */
    lab3_init_B.UnitDelay_k = lab3_init_DW.UnitDelay_DSTATE_d;

    /* RelationalOperator: '<S13>/Relational Operator' */
    lab3_init_B.RelationalOperator_o = (lab3_init_B.StreamFormattedRead1_o3 ==
      lab3_init_B.UnitDelay_k);

    /* UnitDelay: '<S14>/Unit Delay' */
    lab3_init_B.UnitDelay_g = lab3_init_DW.UnitDelay_DSTATE_p;

    /* RelationalOperator: '<S14>/Relational Operator' */
    lab3_init_B.RelationalOperator_g = (lab3_init_B.StreamFormattedRead1_o4 ==
      lab3_init_B.UnitDelay_g);

    /* UnitDelay: '<S15>/Unit Delay' */
    lab3_init_B.UnitDelay_n = lab3_init_DW.UnitDelay_DSTATE_l;

    /* RelationalOperator: '<S15>/Relational Operator' */
    lab3_init_B.RelationalOperator_p = (lab3_init_B.StreamFormattedRead1_o5 ==
      lab3_init_B.UnitDelay_n);

    /* UnitDelay: '<S16>/Unit Delay' */
    lab3_init_B.UnitDelay_m = lab3_init_DW.UnitDelay_DSTATE_n;

    /* RelationalOperator: '<S16>/Relational Operator' */
    lab3_init_B.RelationalOperator_a = (lab3_init_B.StreamFormattedRead1_o6 ==
      lab3_init_B.UnitDelay_m);

    /* UnitDelay: '<S17>/Unit Delay' */
    lab3_init_B.UnitDelay_i = lab3_init_DW.UnitDelay_DSTATE_dn;

    /* RelationalOperator: '<S17>/Relational Operator' */
    lab3_init_B.RelationalOperator_pg = (lab3_init_B.StreamFormattedRead1_o7 ==
      lab3_init_B.UnitDelay_i);

    /* Logic: '<S10>/Logical Operator1' incorporates:
     *  Logic: '<S10>/Logical Operator'
     */
    lab3_init_B.LogicalOperator1 = ((!lab3_init_B.RelationalOperator) ||
      (!lab3_init_B.RelationalOperator_o) || (!lab3_init_B.RelationalOperator_g)
      || (!lab3_init_B.RelationalOperator_p) ||
      (!lab3_init_B.RelationalOperator_a) || (!lab3_init_B.RelationalOperator_pg));

    /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
     *  Constant: '<S3>/Constant'
     */
    /* MATLAB Function 'IMU_data/MATLAB Function': '<S11>:1' */
    if ((!lab3_init_DW.p_last_not_empty) || (!lab3_init_DW.e_last_not_empty)) {
      /* '<S11>:1:5' */
      /* '<S11>:1:6' */
      lab3_init_DW.p_last = 0.0;
      lab3_init_DW.p_last_not_empty = true;

      /* '<S11>:1:7' */
      lab3_init_DW.e_last = lab3_init_P.e_0;
      lab3_init_DW.e_last_not_empty = true;
    }

    if (lab3_init_B.LogicalOperator1) {
      /* '<S11>:1:10' */
      /* '<S11>:1:11' */
      lab3_init_DW.p_last = rt_atan2d_snf(-lab3_init_B.Gain2[1],
        -lab3_init_B.Gain2[2]);

      /* '<S11>:1:12' */
      lab3_init_DW.e_last = rt_atan2d_snf(lab3_init_B.Gain2[0], sqrt
        (lab3_init_B.Gain2[1] * lab3_init_B.Gain2[1] + lab3_init_B.Gain2[2] *
         lab3_init_B.Gain2[2]));
    }

    /* '<S11>:1:14' */
    lab3_init_B.euler_angles[0] = lab3_init_DW.p_last;
    lab3_init_B.euler_angles[1] = lab3_init_DW.e_last;

    /* End of MATLAB Function: '<S3>/MATLAB Function' */

    /* Gain: '<S2>/Pitch: Count to rad' */
    lab3_init_B.PitchCounttorad = lab3_init_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* DataTypeConversion: '<S10>/Data Type Conversion2' */
    lab3_init_B.DataTypeConversion2[0] = lab3_init_B.StreamFormattedRead1_o5;
    lab3_init_B.DataTypeConversion2[1] = lab3_init_B.StreamFormattedRead1_o6;
    lab3_init_B.DataTypeConversion2[2] = lab3_init_B.StreamFormattedRead1_o7;
    for (i = 0; i < 3; i++) {
      /* Gain: '<S10>/Gain1' */
      lab3_init_B.Gain1[i] = 0.0;
      lab3_init_B.Gain1[i] += lab3_init_P.Gain1_Gain[i] *
        lab3_init_B.DataTypeConversion2[0];
      lab3_init_B.Gain1[i] += lab3_init_P.Gain1_Gain[i + 3] *
        lab3_init_B.DataTypeConversion2[1];
      lab3_init_B.Gain1[i] += lab3_init_P.Gain1_Gain[i + 6] *
        lab3_init_B.DataTypeConversion2[2];
    }

    /* MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    /* MATLAB Function 'IMU_data/Gyro vector to [pitch rate, elevation rate, travle rate]': '<S9>:1' */
    /* '<S9>:1:3' */
    /* '<S9>:1:4' */
    /* '<S9>:1:6' */
    /* '<S9>:1:9' */
    smax = tan(lab3_init_B.euler_angles[1]);
    rtb_Frontgain = sin(lab3_init_B.euler_angles[0]);
    euler_rates_tmp = cos(lab3_init_B.euler_angles[0]);
    euler_rates_tmp_0 = cos(lab3_init_B.euler_angles[1]);
    tmp_3[0] = 1.0;
    tmp_3[3] = rtb_Frontgain * smax;
    tmp_3[6] = euler_rates_tmp * smax;
    tmp_3[1] = 0.0;
    tmp_3[4] = euler_rates_tmp;
    tmp_3[7] = -rtb_Frontgain;
    tmp_3[2] = 0.0;
    tmp_3[5] = rtb_Frontgain / euler_rates_tmp_0;
    tmp_3[8] = euler_rates_tmp / euler_rates_tmp_0;
    for (i = 0; i < 3; i++) {
      lab3_init_B.euler_rates[i] = 0.0;
      lab3_init_B.euler_rates[i] += tmp_3[i] * lab3_init_B.Gain1[0];
      lab3_init_B.euler_rates[i] += tmp_3[i + 3] * lab3_init_B.Gain1[1];
      lab3_init_B.euler_rates[i] += tmp_3[i + 6] * lab3_init_B.Gain1[2];
    }

    /* End of MATLAB Function: '<S3>/Gyro vector to [pitch rate, elevation rate, travle rate]' */

    /* MATLAB Function: '<S4>/MATLAB Function2' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant2'
     *  Delay: '<S4>/Delay One Step'
     *  Delay: '<S4>/Delay One Step1'
     */
    for (i = 0; i < 6; i++) {
      x_k_[i] = lab3_init_DW.DelayOneStep_DSTATE[i];
    }

    memcpy(&rtb_P_k[0], &lab3_init_DW.DelayOneStep1_DSTATE[0], 36U * sizeof
           (real_T));

    /* MATLAB Function 'Kalman_filter/MATLAB Function2': '<S20>:1' */
    if (!lab3_init_DW.first_not_empty) {
      /* '<S20>:1:3' */
      lab3_init_DW.first_not_empty = true;

      /* '<S20>:1:5' */
      x_k_[0] = 0.0;
      x_k_[1] = 0.0;
      x_k_[2] = lab3_init_P.e_0;
      x_k_[3] = 0.0;
      x_k_[4] = 0.0;
      x_k_[5] = 0.0;

      /* '<S20>:1:6' */
      for (i = 0; i < 36; i++) {
        rtb_P_k[i] = 0.0;
      }
    }

    /* '<S20>:1:8' */
    for (i = 0; i < 6; i++) {
      lab3_init_B.x_k[i] = x_k_[i];
    }

    /* '<S20>:1:9' */
    if (lab3_init_B.LogicalOperator1) {
      /* '<S20>:1:11' */
      /* '<S20>:1:12' */
      for (i = 0; i < 25; i++) {
        b[i] = 0.0;
      }

      for (i = 0; i < 5; i++) {
        for (iy = 0; iy < 6; iy++) {
          ix = 5 * iy + i;
          A_tmp[iy + 6 * i] = lab3_init_P.C_d[ix];
          L_k[ix] = 0.0;
          for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
            L_k[ix] += lab3_init_P.C_d[5 * A_tmp_0 + i] * rtb_P_k[6 * iy +
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
          A[A_tmp_0] = lab3_init_P.R_d[A_tmp_0] + smax;
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
          rtb_Frontgain = fabs(A[ix]);
          if (rtb_Frontgain > smax) {
            iy = d_k - 1;
            smax = rtb_Frontgain;
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

      /* SignalConversion generated from: '<S20>/ SFunction ' incorporates:
       *  Constant: '<S4>/Constant1'
       *  Constant: '<S4>/Constant2'
       */
      /* '<S20>:1:13' */
      tmp_4[0] = lab3_init_B.euler_angles[0];
      tmp_4[1] = lab3_init_B.euler_rates[0];
      tmp_4[2] = lab3_init_B.euler_angles[1];
      tmp_4[3] = lab3_init_B.euler_rates[1];
      tmp_4[4] = lab3_init_B.euler_rates[2];
      for (i = 0; i < 5; i++) {
        tmp_5[i] = 0.0;
        for (iy = 0; iy < 6; iy++) {
          tmp_5[i] += lab3_init_P.C_d[5 * iy + i] * x_k_[iy];
        }

        tmp_6[i] = tmp_4[i] - tmp_5[i];
      }

      for (i = 0; i < 6; i++) {
        smax = 0.0;
        for (iy = 0; iy < 5; iy++) {
          smax += L_k[6 * iy + i] * tmp_6[iy];
        }

        lab3_init_B.x_k[i] = x_k_[i] + smax;
      }

      for (i = 0; i < 36; i++) {
        b_I[i] = 0;
      }

      for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
        b_I[A_tmp_0 + 6 * A_tmp_0] = 1;
      }

      /* '<S20>:1:14' */
      for (i = 0; i < 36; i++) {
        c_I[i] = 0;
      }

      for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
        c_I[A_tmp_0 + 6 * A_tmp_0] = 1;
        for (i = 0; i < 6; i++) {
          ix = A_tmp_0 + 6 * i;
          rtb_P_k_tmp[ix] = 0.0;
          for (iy = 0; iy < 5; iy++) {
            rtb_P_k_tmp[ix] += L_k[6 * iy + A_tmp_0] * lab3_init_P.C_d[5 * i +
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
            A_tmp[ix] += L_k[6 * A_tmp_0 + i] * lab3_init_P.R_d[5 * iy + A_tmp_0];
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

    /* End of MATLAB Function: '<S4>/MATLAB Function2' */
  }

  /* Step: '<S8>/Step2' incorporates:
   *  Step: '<S8>/Step'
   *  Step: '<S8>/Step1'
   *  Step: '<S8>/Step3'
   *  Step: '<S8>/Step4'
   *  Step: '<S8>/Step5'
   *  Step: '<S8>/Step6'
   */
  smax = lab3_init_M->Timing.t[0];
  if (smax < lab3_init_P.Step2_Time) {
    rtb_Frontgain = lab3_init_P.Step2_Y0;
  } else {
    rtb_Frontgain = lab3_init_P.Step2_YFinal;
  }

  /* End of Step: '<S8>/Step2' */

  /* Step: '<S8>/Step3' */
  if (smax < lab3_init_P.Step3_Time) {
    euler_rates_tmp = lab3_init_P.Step3_Y0;
  } else {
    euler_rates_tmp = lab3_init_P.Step3_YFinal;
  }

  /* Sum: '<S8>/Sum2' incorporates:
   *  Constant: '<S8>/Constant4'
   *  Sum: '<S8>/Sum3'
   */
  lab3_init_B.Sum2 = (rtb_Frontgain - euler_rates_tmp) + lab3_init_P.p_c_offset;

  /* Step: '<S8>/Step6' */
  if (smax < lab3_init_P.Step6_Time) {
    rtb_Frontgain = lab3_init_P.Step6_Y0;
  } else {
    rtb_Frontgain = lab3_init_P.Step6_YFinal;
  }

  /* Step: '<S8>/Step' */
  if (smax < lab3_init_P.Step_Time) {
    euler_rates_tmp = lab3_init_P.Step_Y0;
  } else {
    euler_rates_tmp = lab3_init_P.Step_YFinal;
  }

  /* Step: '<S8>/Step1' */
  if (smax < lab3_init_P.Step1_Time) {
    euler_rates_tmp_0 = lab3_init_P.Step1_Y0;
  } else {
    euler_rates_tmp_0 = lab3_init_P.Step1_YFinal;
  }

  /* Step: '<S8>/Step5' */
  if (smax < lab3_init_P.Step5_Time) {
    tmp_7 = lab3_init_P.Step5_Y0;
  } else {
    tmp_7 = lab3_init_P.Step5_YFinal;
  }

  /* Step: '<S8>/Step4' */
  if (smax < lab3_init_P.Step4_Time) {
    smax = lab3_init_P.Step4_Y0;
  } else {
    smax = lab3_init_P.Step4_YFinal;
  }

  /* Sum: '<S8>/Sum' incorporates:
   *  Sum: '<S8>/Sum1'
   */
  lab3_init_B.Sum = (((euler_rates_tmp - euler_rates_tmp_0) + tmp_7) - smax) +
    rtb_Frontgain;

  /* SignalConversion generated from: '<S5>/LQR' incorporates:
   *  Integrator: '<S5>/Integrator'
   *  Integrator: '<S5>/Integrator1'
   */
  tmp_4[2] = lab3_init_B.x_k[3];
  tmp_4[3] = lab3_init_X.Integrator_CSTATE;
  tmp_4[4] = lab3_init_X.Integrator1_CSTATE;
  tmp_4[0] = lab3_init_B.x_k[0];

  /* Gain: '<S5>/Gain' incorporates:
   *  SignalConversion generated from: '<S5>/Gain'
   */
  tmp[0] = lab3_init_P.F[0] * lab3_init_B.Sum2 + lab3_init_P.F[2] *
    lab3_init_B.Sum;

  /* SignalConversion generated from: '<S5>/LQR' */
  tmp_4[1] = lab3_init_B.x_k[1];

  /* Gain: '<S5>/Gain' incorporates:
   *  SignalConversion generated from: '<S5>/Gain'
   */
  tmp[1] = lab3_init_P.F[1] * lab3_init_B.Sum2;
  tmp[1] += lab3_init_P.F[3] * lab3_init_B.Sum;
  for (i = 0; i < 2; i++) {
    /* Gain: '<S5>/LQR' */
    tmp_0[i] = 0.0;
    for (iy = 0; iy < 5; iy++) {
      tmp_0[i] += lab3_init_P.K[(iy << 1) + i] * tmp_4[iy];
    }

    /* End of Gain: '<S5>/LQR' */

    /* Sum: '<S5>/Sum2' */
    lab3_init_B.u[i] = tmp[i] - tmp_0[i];
  }

  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* MATLAB Function: '<S4>/MATLAB Function1' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant3'
     *  Constant: '<S4>/Constant4'
     *  Constant: '<S4>/Constant5'
     */
    for (i = 0; i < 6; i++) {
      x_k_[i] = lab3_init_B.x_k[i];
    }

    /* MATLAB Function 'Kalman_filter/MATLAB Function1': '<S19>:1' */
    if (!lab3_init_DW.first_not_empty_b) {
      /* '<S19>:1:3' */
      lab3_init_DW.first_not_empty_b = true;

      /* '<S19>:1:5' */
      x_k_[0] = 0.0;
      x_k_[1] = 0.0;
      x_k_[2] = lab3_init_P.e_0;
      x_k_[3] = 0.0;
      x_k_[4] = 0.0;
      x_k_[5] = 0.0;

      /* '<S19>:1:6' */
      for (i = 0; i < 36; i++) {
        rtb_P_k[i] = 0.0;
      }
    }

    /* '<S19>:1:9' */
    /* '<S19>:1:10' */
    for (i = 0; i < 6; i++) {
      for (iy = 0; iy < 6; iy++) {
        A_tmp_0 = i + 6 * iy;
        c_I_0[A_tmp_0] = 0.0;
        for (ix = 0; ix < 6; ix++) {
          c_I_0[A_tmp_0] += lab3_init_P.A_d[6 * ix + i] * rtb_P_k[6 * iy + ix];
        }
      }

      tmp_1[i] = 0.0;
      for (iy = 0; iy < 6; iy++) {
        smax = 0.0;
        for (A_tmp_0 = 0; A_tmp_0 < 6; A_tmp_0++) {
          smax += c_I_0[6 * A_tmp_0 + i] * lab3_init_P.A_d[6 * A_tmp_0 + iy];
        }

        A_tmp_0 = 6 * iy + i;
        lab3_init_B.P_k1_[A_tmp_0] = lab3_init_P.Q_w[A_tmp_0] + smax;
        tmp_1[i] += lab3_init_P.A_d[A_tmp_0] * x_k_[iy];
      }

      tmp_2[i] = 0.0;
      tmp_2[i] += lab3_init_P.B_d[i] * lab3_init_B.u[0];
      tmp_2[i] += lab3_init_P.B_d[i + 6] * lab3_init_B.u[1];
      lab3_init_B.x_k1_[i] = tmp_1[i] + tmp_2[i];
    }

    /* End of MATLAB Function: '<S4>/MATLAB Function1' */

    /* Gain: '<S2>/Elevation: Count to rad' */
    lab3_init_B.ElevationCounttorad = lab3_init_P.ElevationCounttorad_Gain *
      rtb_DeadZoney;

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Constant'
     */
    lab3_init_B.Sum_g = lab3_init_B.ElevationCounttorad + lab3_init_P.e_0;
  }

  /* TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  lab3_init_B.PitchTransferFcn = 0.0;
  lab3_init_B.PitchTransferFcn += lab3_init_P.PitchTransferFcn_C *
    lab3_init_X.PitchTransferFcn_CSTATE;
  lab3_init_B.PitchTransferFcn += lab3_init_P.PitchTransferFcn_D *
    lab3_init_B.PitchCounttorad;

  /* TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  lab3_init_B.ElevationTransferFcn = 0.0;
  lab3_init_B.ElevationTransferFcn += lab3_init_P.ElevationTransferFcn_C *
    lab3_init_X.ElevationTransferFcn_CSTATE;
  lab3_init_B.ElevationTransferFcn += lab3_init_P.ElevationTransferFcn_D *
    lab3_init_B.ElevationCounttorad;
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* Gain: '<S2>/Travel: Count to rad' */
    lab3_init_B.TravelCounttorad = lab3_init_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S2>/Travel: Transfer Fcn' */
  lab3_init_B.TravelTransferFcn = 0.0;
  lab3_init_B.TravelTransferFcn += lab3_init_P.TravelTransferFcn_C *
    lab3_init_X.TravelTransferFcn_CSTATE;
  lab3_init_B.TravelTransferFcn += lab3_init_P.TravelTransferFcn_D *
    lab3_init_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* SignalConversion generated from: '<S7>/To File' */
    rtb_TmpSignalConversionAtToFile[0] = lab3_init_B.Sum2;
    rtb_TmpSignalConversionAtToFile[1] = lab3_init_B.Sum;
    rtb_TmpSignalConversionAtToFile[4] = lab3_init_B.euler_angles[0];
    rtb_TmpSignalConversionAtToFile[5] = lab3_init_B.euler_rates[0];
    rtb_TmpSignalConversionAtToFile[6] = lab3_init_B.euler_angles[1];
    rtb_TmpSignalConversionAtToFile[2] = lab3_init_B.u[0];
    rtb_TmpSignalConversionAtToFile[7] = lab3_init_B.euler_rates[1];
    rtb_TmpSignalConversionAtToFile[3] = lab3_init_B.u[1];
    rtb_TmpSignalConversionAtToFile[8] = lab3_init_B.euler_rates[2];
    rtb_TmpSignalConversionAtToFile[9] = lab3_init_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[10] = lab3_init_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[11] = lab3_init_B.Sum_g;
    rtb_TmpSignalConversionAtToFile[12] = lab3_init_B.ElevationTransferFcn;
    rtb_TmpSignalConversionAtToFile[13] = lab3_init_B.TravelCounttorad;
    rtb_TmpSignalConversionAtToFile[14] = lab3_init_B.TravelTransferFcn;
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtToFile[i + 15] = lab3_init_B.x_k1_[i];
      rtb_TmpSignalConversionAtToFile[i + 21] = lab3_init_B.x_k[i];
    }

    /* End of SignalConversion generated from: '<S7>/To File' */

    /* ToFile: '<S7>/To File' */
    if (rtmIsMajorTimeStep(lab3_init_M)) {
      if (rtmIsMajorTimeStep(lab3_init_M) ) {
        {
          if (!(++lab3_init_DW.ToFile_IWORK.Decimation % 1) &&
              (lab3_init_DW.ToFile_IWORK.Count * (27 + 1)) + 1 < 100000000 ) {
            FILE *fp = (FILE *) lab3_init_DW.ToFile_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[27 + 1];
              lab3_init_DW.ToFile_IWORK.Decimation = 0;
              u[0] = lab3_init_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFile[0];
              u[2] = rtb_TmpSignalConversionAtToFile[1];
              u[3] = rtb_TmpSignalConversionAtToFile[2];
              u[4] = rtb_TmpSignalConversionAtToFile[3];
              u[5] = rtb_TmpSignalConversionAtToFile[4];
              u[6] = rtb_TmpSignalConversionAtToFile[5];
              u[7] = rtb_TmpSignalConversionAtToFile[6];
              u[8] = rtb_TmpSignalConversionAtToFile[7];
              u[9] = rtb_TmpSignalConversionAtToFile[8];
              u[10] = rtb_TmpSignalConversionAtToFile[9];
              u[11] = rtb_TmpSignalConversionAtToFile[10];
              u[12] = rtb_TmpSignalConversionAtToFile[11];
              u[13] = rtb_TmpSignalConversionAtToFile[12];
              u[14] = rtb_TmpSignalConversionAtToFile[13];
              u[15] = rtb_TmpSignalConversionAtToFile[14];
              u[16] = rtb_TmpSignalConversionAtToFile[15];
              u[17] = rtb_TmpSignalConversionAtToFile[16];
              u[18] = rtb_TmpSignalConversionAtToFile[17];
              u[19] = rtb_TmpSignalConversionAtToFile[18];
              u[20] = rtb_TmpSignalConversionAtToFile[19];
              u[21] = rtb_TmpSignalConversionAtToFile[20];
              u[22] = rtb_TmpSignalConversionAtToFile[21];
              u[23] = rtb_TmpSignalConversionAtToFile[22];
              u[24] = rtb_TmpSignalConversionAtToFile[23];
              u[25] = rtb_TmpSignalConversionAtToFile[24];
              u[26] = rtb_TmpSignalConversionAtToFile[25];
              u[27] = rtb_TmpSignalConversionAtToFile[26];
              if (fwrite(u, sizeof(real_T), 27 + 1, fp) != 27 + 1) {
                rtmSetErrorStatus(lab3_init_M,
                                  "Error writing to MAT-file testplan2_3.mat");
                return;
              }

              if (((++lab3_init_DW.ToFile_IWORK.Count) * (27 + 1))+1 >=
                  100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file testplan2_3.mat.\n");
              }
            }
          }
        }
      }
    }
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  smax = lab3_init_B.u[0] + lab3_init_P.V_s_0;

  /* Sum: '<S1>/Add' */
  rtb_Frontgain = smax - lab3_init_B.u[1];

  /* Sum: '<S1>/Subtract' */
  smax += lab3_init_B.u[1];

  /* Gain: '<S1>/Back gain' */
  smax *= lab3_init_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' */
  rtb_Frontgain *= lab3_init_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(lab3_init_M)) {
  }

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (rtb_Frontgain > lab3_init_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S2>/Front motor: Saturation' */
    lab3_init_B.FrontmotorSaturation = lab3_init_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Frontgain < lab3_init_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S2>/Front motor: Saturation' */
    lab3_init_B.FrontmotorSaturation = lab3_init_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Front motor: Saturation' */
    lab3_init_B.FrontmotorSaturation = rtb_Frontgain;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (smax > lab3_init_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S2>/Back motor: Saturation' */
    lab3_init_B.BackmotorSaturation = lab3_init_P.BackmotorSaturation_UpperSat;
  } else if (smax < lab3_init_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S2>/Back motor: Saturation' */
    lab3_init_B.BackmotorSaturation = lab3_init_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Back motor: Saturation' */
    lab3_init_B.BackmotorSaturation = smax;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

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

    /* Outputs for Enabled SubSystem: '<S10>/Skip to next line' incorporates:
     *  EnablePort: '<S18>/Enable'
     */
    if (lab3_init_B.StreamFormattedRead1_o10) {
      /* S-Function (stream_formatted_read_block): '<S18>/Stream Formatted Read' incorporates:
       *  S-Function (stream_call_block): '<S10>/Stream Call2'
       *  S-Function (stream_formatted_read_block): '<S10>/Stream Formatted Read1'
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

    /* End of Outputs for SubSystem: '<S10>/Skip to next line' */

    /* S-Function (stop_with_error_block): '<S10>/Stop with Error' */

    /* S-Function Block: lab3_init/IMU_data/IMU_BT/Stop with Error (stop_with_error_block) */
    {
      if (rtb_StreamCall2_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall2_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(lab3_init_M, _rt_error_message);
        return;
      }
    }
  }

  /* Sum: '<S5>/Sum4' */
  lab3_init_B.gamma_dot = lab3_init_B.Sum2 - lab3_init_B.x_k[0];

  /* Sum: '<S5>/Sum5' */
  lab3_init_B.zeta_dot = lab3_init_B.Sum - lab3_init_B.x_k[3];

  /* RateTransition: '<S21>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    if (lab3_init_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S21>/Rate Transition: x' */
      lab3_init_B.RateTransitionx = lab3_init_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S21>/Dead Zone: x' */
    if (lab3_init_B.RateTransitionx > lab3_init_P.DeadZonex_End) {
      /* DeadZone: '<S21>/Dead Zone: y' */
      rtb_DeadZoney = lab3_init_B.RateTransitionx - lab3_init_P.DeadZonex_End;
    } else if (lab3_init_B.RateTransitionx >= lab3_init_P.DeadZonex_Start) {
      /* DeadZone: '<S21>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S21>/Dead Zone: y' */
      rtb_DeadZoney = lab3_init_B.RateTransitionx - lab3_init_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S21>/Dead Zone: x' */

    /* Gain: '<S21>/Joystick_gain_x' incorporates:
     *  Gain: '<S21>/Gain: x'
     */
    lab3_init_B.Joystick_gain_x = lab3_init_P.Gainx_Gain * rtb_DeadZoney *
      lab3_init_P.Joystick_gain_x;

    /* RateTransition: '<S21>/Rate Transition: y' */
    if (lab3_init_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S21>/Rate Transition: y' */
      lab3_init_B.RateTransitiony = lab3_init_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S21>/Rate Transition: y' */

    /* DeadZone: '<S21>/Dead Zone: y' */
    if (lab3_init_B.RateTransitiony > lab3_init_P.DeadZoney_End) {
      /* DeadZone: '<S21>/Dead Zone: y' */
      rtb_DeadZoney = lab3_init_B.RateTransitiony - lab3_init_P.DeadZoney_End;
    } else if (lab3_init_B.RateTransitiony >= lab3_init_P.DeadZoney_Start) {
      /* DeadZone: '<S21>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S21>/Dead Zone: y' */
      rtb_DeadZoney = lab3_init_B.RateTransitiony - lab3_init_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S21>/Dead Zone: y' */

    /* Gain: '<S21>/Joystick_gain_y' incorporates:
     *  Gain: '<S21>/Gain: y'
     */
    lab3_init_B.Joystick_gain_y = lab3_init_P.Gainy_Gain * rtb_DeadZoney *
      lab3_init_P.Joystick_gain_y;
    for (i = 0; i < 5; i++) {
      /* Gain: '<S6>/Gain4' incorporates:
       *  SignalConversion generated from: '<S6>/Gain4'
       */
      lab3_init_B.Gain4[i] = 0.0;
      for (iy = 0; iy < 5; iy++) {
        lab3_init_B.Gain4[i] += lab3_init_P.C_est[5 * iy + i] * 0.0;
      }

      /* End of Gain: '<S6>/Gain4' */
    }
  }

  /* End of RateTransition: '<S21>/Rate Transition: x' */

  /* Sum: '<S6>/Sum1' incorporates:
   *  Gain: '<S6>/Gain3'
   *  Integrator: '<S6>/Integrator'
   */
  for (i = 0; i < 5; i++) {
    smax = 0.0;
    for (iy = 0; iy < 5; iy++) {
      smax += lab3_init_P.C_est[5 * iy + i] * lab3_init_X.Integrator_CSTATE_h[iy];
    }

    tmp_4[i] = lab3_init_B.Gain4[i] - smax;
  }

  /* End of Sum: '<S6>/Sum1' */
  for (i = 0; i < 5; i++) {
    /* Gain: '<S6>/Gain2' */
    lab3_init_B.Gain2_c[i] = 0.0;
    for (iy = 0; iy < 5; iy++) {
      lab3_init_B.Gain2_c[i] += lab3_init_P.L_est[5 * iy + i] * tmp_4[iy];
    }

    /* End of Gain: '<S6>/Gain2' */
  }

  if (rtmIsMajorTimeStep(lab3_init_M)) {
    for (i = 0; i < 5; i++) {
      /* Gain: '<S6>/Gain1' incorporates:
       *  SignalConversion generated from: '<S6>/Gain1'
       */
      lab3_init_B.Gain1_i[i] = 0.0;
      lab3_init_B.Gain1_i[i] += lab3_init_P.B_est[i] * 0.0;
      lab3_init_B.Gain1_i[i] += lab3_init_P.B_est[i + 5] * 0.0;
    }
  }

  for (i = 0; i < 5; i++) {
    /* Gain: '<S6>/Gain' incorporates:
     *  Integrator: '<S6>/Integrator'
     */
    lab3_init_B.Gain[i] = 0.0;
    for (iy = 0; iy < 5; iy++) {
      lab3_init_B.Gain[i] += lab3_init_P.A_est[5 * iy + i] *
        lab3_init_X.Integrator_CSTATE_h[iy];
    }

    /* End of Gain: '<S6>/Gain' */
  }

  if (rtmIsMajorTimeStep(lab3_init_M)) {
  }

  for (i = 0; i < 5; i++) {
    /* Sum: '<S6>/Sum' */
    lab3_init_B.x_hat_dot[i] = (lab3_init_B.Gain2_c[i] + lab3_init_B.Gain1_i[i])
      + lab3_init_B.Gain[i];
  }
}

/* Model update function for TID0 */
void lab3_init_update0(void)           /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(lab3_init_M)) {
    /* Update for UnitDelay: '<S12>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE = lab3_init_B.StreamFormattedRead1_o2;

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_d = lab3_init_B.StreamFormattedRead1_o3;

    /* Update for UnitDelay: '<S14>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_p = lab3_init_B.StreamFormattedRead1_o4;

    /* Update for UnitDelay: '<S15>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_l = lab3_init_B.StreamFormattedRead1_o5;

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_n = lab3_init_B.StreamFormattedRead1_o6;

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_dn = lab3_init_B.StreamFormattedRead1_o7;

    /* Update for Delay: '<S4>/Delay One Step' */
    for (i = 0; i < 6; i++) {
      lab3_init_DW.DelayOneStep_DSTATE[i] = lab3_init_B.x_k1_[i];
    }

    /* End of Update for Delay: '<S4>/Delay One Step' */

    /* Update for Delay: '<S4>/Delay One Step1' */
    memcpy(&lab3_init_DW.DelayOneStep1_DSTATE[0], &lab3_init_B.P_k1_[0], 36U *
           sizeof(real_T));
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

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE = lab3_init_B.gamma_dot;

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = lab3_init_B.zeta_dot;

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += lab3_init_P.PitchTransferFcn_A *
    lab3_init_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += lab3_init_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += lab3_init_P.ElevationTransferFcn_A *
    lab3_init_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += lab3_init_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += lab3_init_P.TravelTransferFcn_A *
    lab3_init_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += lab3_init_B.TravelCounttorad;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  for (i = 0; i < 5; i++) {
    _rtXdot->Integrator_CSTATE_h[i] = lab3_init_B.x_hat_dot[i];
  }

  /* End of Derivatives for Integrator: '<S6>/Integrator' */
}

/* Model output function for TID2 */
void lab3_init_output2(void)           /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S21>/Game Controller' */

  /* S-Function Block: lab3_init/Subsystem1/Joystick/Game Controller (game_controller_block) */
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

  /* RateTransition: '<S21>/Rate Transition: x' */
  lab3_init_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S21>/Rate Transition: y' */
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

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

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

  /* Start for S-Function (stream_call_block): '<S10>/Stream Call2' incorporates:
   *  Constant: '<S10>/Constant4'
   *  S-Function (string_constant_block): '<S10>/String Constant1'
   */

  /* S-Function Block: lab3_init/IMU_data/IMU_BT/Stream Call2 (stream_call_block) */
  {
    lab3_init_DW.StreamCall2_State = STREAM_CALL_STATE_NOT_CONNECTED;
    lab3_init_DW.StreamCall2_Stream = NULL;
  }

  /* Start for ToFile: '<S7>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "testplan2_3.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(lab3_init_M, "Error creating .mat file testplan2_3.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 27 + 1, 0, "ans")) {
      rtmSetErrorStatus(lab3_init_M,
                        "Error writing mat file header to file testplan2_3.mat");
      return;
    }

    lab3_init_DW.ToFile_IWORK.Count = 0;
    lab3_init_DW.ToFile_IWORK.Decimation = -1;
    lab3_init_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for RateTransition: '<S21>/Rate Transition: x' */
  lab3_init_B.RateTransitionx = lab3_init_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S21>/Rate Transition: y' */
  lab3_init_B.RateTransitiony = lab3_init_P.RateTransitiony_InitialConditio;

  /* Start for S-Function (game_controller_block): '<S21>/Game Controller' */

  /* S-Function Block: lab3_init/Subsystem1/Joystick/Game Controller (game_controller_block) */
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

    /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE = lab3_init_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_d = lab3_init_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_p = lab3_init_P.UnitDelay_InitialCondition_j;

    /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_l = lab3_init_P.UnitDelay_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_n = lab3_init_P.UnitDelay_InitialCondition_l1;

    /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
    lab3_init_DW.UnitDelay_DSTATE_dn = lab3_init_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S4>/Delay One Step' */
    for (i = 0; i < 6; i++) {
      lab3_init_DW.DelayOneStep_DSTATE[i] =
        lab3_init_P.DelayOneStep_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S4>/Delay One Step' */

    /* InitializeConditions for Delay: '<S4>/Delay One Step1' */
    for (i = 0; i < 36; i++) {
      lab3_init_DW.DelayOneStep1_DSTATE[i] =
        lab3_init_P.DelayOneStep1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S4>/Delay One Step1' */

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    lab3_init_X.Integrator_CSTATE = lab3_init_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S5>/Integrator1' */
    lab3_init_X.Integrator1_CSTATE = lab3_init_P.Integrator1_IC;

    /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
    lab3_init_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
    lab3_init_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
    lab3_init_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for RateTransition: '<S21>/Rate Transition: x' */
    lab3_init_DW.RateTransitionx_Buffer0 =
      lab3_init_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for RateTransition: '<S21>/Rate Transition: y' */
    lab3_init_DW.RateTransitiony_Buffer0 =
      lab3_init_P.RateTransitiony_InitialConditio;

    /* InitializeConditions for Integrator: '<S6>/Integrator' */
    for (i = 0; i < 5; i++) {
      lab3_init_X.Integrator_CSTATE_h[i] = lab3_init_P.Integrator_IC_i;
    }

    /* End of InitializeConditions for Integrator: '<S6>/Integrator' */

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    lab3_init_DW.p_last_not_empty = false;
    lab3_init_DW.e_last_not_empty = false;

    /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1' */
    lab3_init_DW.first_not_empty_b = false;

    /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function2' */
    lab3_init_DW.first_not_empty = false;
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

  /* Terminate for S-Function (stream_call_block): '<S10>/Stream Call2' incorporates:
   *  Constant: '<S10>/Constant4'
   *  S-Function (string_constant_block): '<S10>/String Constant1'
   */

  /* S-Function Block: lab3_init/IMU_data/IMU_BT/Stream Call2 (stream_call_block) */
  {
    if (lab3_init_DW.StreamCall2_Stream != NULL) {
      stream_close(lab3_init_DW.StreamCall2_Stream);
      lab3_init_DW.StreamCall2_Stream = NULL;
    }
  }

  /* Terminate for ToFile: '<S7>/To File' */
  {
    FILE *fp = (FILE *) lab3_init_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "testplan2_3.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab3_init_M, "Error closing MAT-file testplan2_3.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(lab3_init_M,
                          "Error reopening MAT-file testplan2_3.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 27 + 1, lab3_init_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(lab3_init_M,
                          "Error writing header for ans to MAT-file testplan2_3.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(lab3_init_M, "Error closing MAT-file testplan2_3.mat");
        return;
      }

      lab3_init_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S21>/Game Controller' */

  /* S-Function Block: lab3_init/Subsystem1/Joystick/Game Controller (game_controller_block) */
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
  lab3_init_M->Sizes.checksums[0] = (1975118174U);
  lab3_init_M->Sizes.checksums[1] = (3586597587U);
  lab3_init_M->Sizes.checksums[2] = (2505687088U);
  lab3_init_M->Sizes.checksums[3] = (3135800418U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    lab3_init_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&lab3_init_DW.Skiptonextline_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
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
      lab3_init_B.Gain4[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab3_init_B.Gain2_c[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab3_init_B.Gain1_i[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab3_init_B.Gain[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      lab3_init_B.x_hat_dot[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      lab3_init_B.x_k[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      lab3_init_B.x_k1_[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      lab3_init_B.P_k1_[i] = 0.0;
    }

    lab3_init_B.DataTypeConversion1[0] = 0.0;
    lab3_init_B.DataTypeConversion1[1] = 0.0;
    lab3_init_B.DataTypeConversion1[2] = 0.0;
    lab3_init_B.Gain2[0] = 0.0;
    lab3_init_B.Gain2[1] = 0.0;
    lab3_init_B.Gain2[2] = 0.0;
    lab3_init_B.PitchCounttorad = 0.0;
    lab3_init_B.DataTypeConversion2[0] = 0.0;
    lab3_init_B.DataTypeConversion2[1] = 0.0;
    lab3_init_B.DataTypeConversion2[2] = 0.0;
    lab3_init_B.Gain1[0] = 0.0;
    lab3_init_B.Gain1[1] = 0.0;
    lab3_init_B.Gain1[2] = 0.0;
    lab3_init_B.Sum2 = 0.0;
    lab3_init_B.Sum = 0.0;
    lab3_init_B.u[0] = 0.0;
    lab3_init_B.u[1] = 0.0;
    lab3_init_B.PitchTransferFcn = 0.0;
    lab3_init_B.ElevationCounttorad = 0.0;
    lab3_init_B.Sum_g = 0.0;
    lab3_init_B.ElevationTransferFcn = 0.0;
    lab3_init_B.TravelCounttorad = 0.0;
    lab3_init_B.TravelTransferFcn = 0.0;
    lab3_init_B.FrontmotorSaturation = 0.0;
    lab3_init_B.BackmotorSaturation = 0.0;
    lab3_init_B.gamma_dot = 0.0;
    lab3_init_B.zeta_dot = 0.0;
    lab3_init_B.RateTransitionx = 0.0;
    lab3_init_B.Joystick_gain_x = 0.0;
    lab3_init_B.RateTransitiony = 0.0;
    lab3_init_B.Joystick_gain_y = 0.0;
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
    for (i = 0; i < 6; i++) {
      lab3_init_DW.DelayOneStep_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      lab3_init_DW.DelayOneStep1_DSTATE[i] = 0.0;
    }
  }

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

  lab3_init_DW.HILWriteAnalog_Buffer[0] = 0.0;
  lab3_init_DW.HILWriteAnalog_Buffer[1] = 0.0;
  lab3_init_DW.RateTransitionx_Buffer0 = 0.0;
  lab3_init_DW.RateTransitiony_Buffer0 = 0.0;
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
  lab3_init_M->Sizes.numBlocks = (131);/* Number of blocks */
  lab3_init_M->Sizes.numBlockIO = (54);/* Number of block outputs */
  lab3_init_M->Sizes.numBlockPrms = (691);/* Sum of parameter "widths" */
  return lab3_init_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
