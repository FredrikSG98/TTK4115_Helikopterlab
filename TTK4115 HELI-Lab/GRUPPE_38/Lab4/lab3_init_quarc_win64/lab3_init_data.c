/*
 * lab3_init_data.c
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

/* Block parameters (default storage) */
P_lab3_init_T lab3_init_P = {
  /* Variable: A_d
   * Referenced by: '<S4>/Constant3'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.9334046868883735E-6, 0.0019334046868883735, 0.002, 1.0,
    0.0, 0.0, 1.2889364579255824E-9, 1.9334046868883739E-6, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.002, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.002, 1.0 },

  /* Variable: A_est
   * Referenced by: '<S6>/Gain'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.96670234344418671, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: B_d
   * Referenced by: '<S4>/Constant4'
   */
  { 0.0, 0.0, 3.1100425882676187E-7, 0.00031100425882676187, 0.0, 0.0,
    1.8092307692307694E-6, 0.0018092307692307694, 0.0, 0.0,
    5.8299587481557112E-13, 1.1659917496311423E-9 },

  /* Variable: B_est
   * Referenced by: '<S6>/Gain1'
   */
  { 0.0, 0.0, 0.0, 0.15550212941338093, 0.0, 0.0, 0.90461538461538471, 0.0, 0.0,
    0.0 },

  /* Variable: C_d
   * Referenced by: '<S4>/Constant1'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: C_est
   * Referenced by:
   *   '<S6>/Gain3'
   *   '<S6>/Gain4'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: F
   * Referenced by: '<S5>/Gain'
   */
  { -9.8353792191908833E-16, 13.766981775376948, 20.322693200025029,
    9.3812622871954876E-15 },

  /* Variable: Joystick_gain_x
   * Referenced by: '<S21>/Joystick_gain_x'
   */
  1.0,

  /* Variable: Joystick_gain_y
   * Referenced by: '<S21>/Joystick_gain_y'
   */
  -1.0,

  /* Variable: K
   * Referenced by: '<S5>/LQR'
   */
  { -9.8353792191908833E-16, 13.766981775376948, -3.440806345759457E-16,
    5.741971281405343, 20.322693200025029, 9.3812622871954876E-15,
    3.412633432447707E-17, -2.3873241463784307, -17.825353626292273,
    -5.2008933255326012E-15 },

  /* Variable: L_est
   * Referenced by: '<S6>/Gain2'
   */
  { 0.7, 0.1, 0.0, 0.0, 0.96670234344418671, 0.9, 0.7, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.5, 0.3, 0.0, 0.0, 0.0, 0.7, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.6 },

  /* Variable: Q_w
   * Referenced by: '<S4>/Constant5'
   */
  { 1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5 },

  /* Variable: R_d
   * Referenced by: '<S4>/Constant2'
   */
  { 0.002, 0.0054, 0.0069, -0.0025, -0.0017, 0.0054, 0.0393, 0.0536, -0.0061,
    -0.0093, 0.0069, 0.0536, 0.0753, -0.0065, -0.0115, -0.0025, -0.0061, -0.0065,
    0.0056, 0.0031, -0.0017, -0.0093, -0.0115, 0.0031, 0.0084 },

  /* Variable: V_s_0
   * Referenced by: '<Root>/Constant'
   */
  6.5,

  /* Variable: e_0
   * Referenced by:
   *   '<S2>/Constant'
   *   '<S3>/Constant'
   *   '<S4>/Constant'
   */
  -0.475,

  /* Variable: p_c_offset
   * Referenced by: '<S8>/Constant4'
   */
  -0.08,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S2>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant4'
   */
  0.0,

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S10>/Gain2'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: -2*pi /4096
   * Referenced by: '<S2>/Pitch: Count to rad'
   */
  -0.0015339807878856412,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay One Step'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay One Step1'
   */
  0.0,

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S10>/Gain1'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: 30
   * Referenced by: '<S8>/Step2'
   */
  30.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step2'
   */
  0.0,

  /* Expression: 0.175
   * Referenced by: '<S8>/Step2'
   */
  0.175,

  /* Expression: 40
   * Referenced by: '<S8>/Step3'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step3'
   */
  0.0,

  /* Expression: 0.175
   * Referenced by: '<S8>/Step3'
   */
  0.175,

  /* Expression: 3
   * Referenced by: '<S8>/Step6'
   */
  3.0,

  /* Expression: 0.16
   * Referenced by: '<S8>/Step6'
   */
  0.16,

  /* Expression: 0
   * Referenced by: '<S8>/Step6'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S8>/Step'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step'
   */
  0.0,

  /* Expression: 0.175
   * Referenced by: '<S8>/Step'
   */
  0.175,

  /* Expression: 12
   * Referenced by: '<S8>/Step1'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step1'
   */
  0.0,

  /* Expression: 0.175
   * Referenced by: '<S8>/Step1'
   */
  0.175,

  /* Expression: 22
   * Referenced by: '<S8>/Step5'
   */
  22.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step5'
   */
  0.0,

  /* Expression: 0.175
   * Referenced by: '<S8>/Step5'
   */
  0.175,

  /* Expression: 20
   * Referenced by: '<S8>/Step4'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step4'
   */
  0.0,

  /* Expression: 0.175
   * Referenced by: '<S8>/Step4'
   */
  0.175,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator1'
   */
  0.0,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S2>/Pitch: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S2>/Pitch: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S2>/Pitch: Transfer Fcn'
   */
  50.0,

  /* Expression: -2 * pi /4096
   * Referenced by: '<S2>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S2>/Elevation: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S2>/Elevation: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S2>/Elevation: Transfer Fcn'
   */
  50.0,

  /* Expression: -2*pi/8192
   * Referenced by: '<S2>/Travel: Count to rad'
   */
  -0.00076699039394282058,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S2>/Travel: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S2>/Travel: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S2>/Travel: Transfer Fcn'
   */
  50.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Back gain'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/Front gain'
   */
  0.5,

  /* Expression: 5
   * Referenced by: '<S2>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S2>/Front motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S2>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S2>/Back motor: Saturation'
   */
  -5.0,

  /* Expression: 0
   * Referenced by: '<S21>/Rate Transition: x'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S21>/Dead Zone: x'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S21>/Dead Zone: x'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S21>/Gain: x'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S21>/Rate Transition: y'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S21>/Dead Zone: y'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S21>/Dead Zone: y'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S21>/Gain: y'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator'
   */
  0.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S2>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: StreamCall2_SendBufferSize
   * Referenced by: '<S10>/Stream Call2'
   */
  8000,

  /* Computed Parameter: StreamCall2_ReceiveBufferSize
   * Referenced by: '<S10>/Stream Call2'
   */
  8000,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S12>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_l
   * Referenced by: '<S13>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_j
   * Referenced by: '<S14>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_m
   * Referenced by: '<S15>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_l1
   * Referenced by: '<S16>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_i
   * Referenced by: '<S17>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: StreamFormattedRead_MaxUnits
   * Referenced by: '<S18>/Stream Formatted Read'
   */
  80U,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S2>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S2>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: StreamFormattedRead1_MaxUnits
   * Referenced by: '<S10>/Stream Formatted Read1'
   */
  80U,

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S21>/Game Controller'
   */
  12U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S2>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: StreamCall2_NonBlocking
   * Referenced by: '<S10>/Stream Call2'
   */
  1,

  /* Computed Parameter: StreamCall2_Active
   * Referenced by: '<S10>/Stream Call2'
   */
  0,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S2>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S21>/Game Controller'
   */
  0,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S21>/Game Controller'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S2>/HIL Read Encoder Timebase'
   */
  1U,

  /* Expression: value
   * Referenced by: '<S10>/String Constant1'
   */
  { 115U, 101U, 114U, 105U, 97U, 108U, 58U, 47U, 47U, 73U, 77U, 85U, 58U, 51U,
    63U, 98U, 97U, 117U, 100U, 61U, 49U, 49U, 53U, 50U, 48U, 48U, 44U, 119U,
    111U, 114U, 100U, 61U, 56U, 44U, 112U, 97U, 114U, 105U, 116U, 121U, 61U,
    110U, 111U, 110U, 101U, 44U, 115U, 116U, 111U, 112U, 61U, 49U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Expression: uri_argument
   * Referenced by: '<S10>/Stream Call2'
   */
  0U,

  /* Computed Parameter: StreamCall2_Endian
   * Referenced by: '<S10>/Stream Call2'
   */
  1U,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S21>/Game Controller'
   */
  1U
};
