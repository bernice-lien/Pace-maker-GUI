/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: transmit.c
 *
 * Code generated for Simulink model 'group5_A2finalmodel'.
 *
 * Model version                  : 7.27
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Dec  3 21:21:00 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "group5_A2finalmodel_types.h"
#include "transmit_private.h"
#include "group5_A2finalmodel.h"
#include "transmit.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void group5_A2final_SystemCore_setup(freedomk64f_SCIWrite_group5_A_T *obj);
static void group5_A2final_SystemCore_setup(freedomk64f_SCIWrite_group5_A_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<Root>/COM_OUT1' */
void transmit_Init(void)
{
  /* Start for MATLABSystem: '<S1>/Serial Transmit1' */
  group5_A2finalmodel_DW.obj_jz.isInitialized = 0;
  group5_A2finalmodel_DW.obj_jz.matlabCodegenIsDeleted = false;
  group5_A2final_SystemCore_setup(&group5_A2finalmodel_DW.obj_jz);
}

/* Output and update for Simulink Function: '<Root>/COM_OUT1' */
void transmit(void)
{
  int32_T i;
  uint8_T TxDataLocChar[26];
  uint8_T rtb_TmpSignalConversionAtSerial[26];
  uint8_T status;

  /* SignalConversion generated from: '<S1>/Atrial_Amp' */
  group5_A2finalmodel_B.ATR_AMP = group5_A2finalmodel_B.ATR_AMP_c;

  /* SignalConversion generated from: '<S1>/Vent_Amp' */
  group5_A2finalmodel_B.VENT_AMP = group5_A2finalmodel_B.VENT_AMP_g;

  /* SignalConversion generated from: '<S1>/atr_signal' */
  group5_A2finalmodel_B.TmpLatchAtatr_signalOutport1 =
    group5_A2finalmodel_B.AnalogInput;

  /* SignalConversion generated from: '<S1>/vent_signal' */
  group5_A2finalmodel_B.TmpLatchAtvent_signalOutport1 =
    group5_A2finalmodel_B.AnalogInput1;

  /* S-Function (any2byte): '<S1>/Byte Pack4' */

  /* Pack: <S1>/Byte Pack4 */
  (void) memcpy(&group5_A2finalmodel_B.BytePack4[0],
                &group5_A2finalmodel_B.ATR_AMP,
                4);

  /* S-Function (any2byte): '<S1>/Byte Pack5' */

  /* Pack: <S1>/Byte Pack5 */
  (void) memcpy(&group5_A2finalmodel_B.BytePack5[0],
                &group5_A2finalmodel_B.VENT_AMP,
                4);

  /* S-Function (any2byte): '<S1>/Byte Pack10' */

  /* Pack: <S1>/Byte Pack10 */
  (void) memcpy(&group5_A2finalmodel_B.BytePack10[0],
                &group5_A2finalmodel_B.TmpLatchAtatr_signalOutport1,
                8);

  /* S-Function (any2byte): '<S1>/Byte Pack11' */

  /* Pack: <S1>/Byte Pack11 */
  (void) memcpy(&group5_A2finalmodel_B.BytePack11[0],
                &group5_A2finalmodel_B.TmpLatchAtvent_signalOutport1,
                8);

  /* SignalConversion generated from: '<S1>/Serial Transmit1' incorporates:
   *  SignalConversion generated from: '<S1>/Mode'
   */
  rtb_TmpSignalConversionAtSerial[0] = group5_A2finalmodel_B.mode;
  rtb_TmpSignalConversionAtSerial[1] = group5_A2finalmodel_B.BytePack4[0];
  rtb_TmpSignalConversionAtSerial[5] = group5_A2finalmodel_B.BytePack5[0];
  rtb_TmpSignalConversionAtSerial[2] = group5_A2finalmodel_B.BytePack4[1];
  rtb_TmpSignalConversionAtSerial[6] = group5_A2finalmodel_B.BytePack5[1];
  rtb_TmpSignalConversionAtSerial[3] = group5_A2finalmodel_B.BytePack4[2];
  rtb_TmpSignalConversionAtSerial[7] = group5_A2finalmodel_B.BytePack5[2];
  rtb_TmpSignalConversionAtSerial[4] = group5_A2finalmodel_B.BytePack4[3];
  rtb_TmpSignalConversionAtSerial[8] = group5_A2finalmodel_B.BytePack5[3];
  rtb_TmpSignalConversionAtSerial[9] = 0U;
  for (i = 0; i < 8; i++) {
    rtb_TmpSignalConversionAtSerial[i + 10] = group5_A2finalmodel_B.BytePack10[i];
    rtb_TmpSignalConversionAtSerial[i + 18] = group5_A2finalmodel_B.BytePack11[i];
  }

  /* End of SignalConversion generated from: '<S1>/Serial Transmit1' */

  /* MATLABSystem: '<S1>/Serial Transmit1' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&TxDataLocChar[0], (void *)&rtb_TmpSignalConversionAtSerial[0],
           (size_t)26 * sizeof(uint8_T));
    status = MW_SCI_Transmit(group5_A2finalmodel_DW.obj_jz.MW_SCIHANDLE,
      &TxDataLocChar[0], 26U);
  }

  /* End of MATLABSystem: '<S1>/Serial Transmit1' */
}

/* Termination for Simulink Function: '<Root>/COM_OUT1' */
void transmit_Term(void)
{
  /* Terminate for MATLABSystem: '<S1>/Serial Transmit1' */
  if (!group5_A2finalmodel_DW.obj_jz.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_jz.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_jz.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_jz.isSetupComplete) {
      MW_SCI_Close(group5_A2finalmodel_DW.obj_jz.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Serial Transmit1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
