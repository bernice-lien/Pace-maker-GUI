/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: group5_A2finalmodel.h
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

#ifndef RTW_HEADER_group5_A2finalmodel_h_
#define RTW_HEADER_group5_A2finalmodel_h_
#ifndef group5_A2finalmodel_COMMON_INCLUDES_
#define group5_A2finalmodel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_AnalogIn.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#endif                                /* group5_A2finalmodel_COMMON_INCLUDES_ */

#include "group5_A2finalmodel_types.h"
#include <stddef.h>
#include "transmit.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[34];
  uint8_T RxDataLocChar[34];
  real_T Gain[3];                      /* '<S4>/Gain' */
  MW_AnalogIn_TriggerSource_Type trigger_val;
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T TmpLatchAtatr_signalOutport1;
  real_T TmpLatchAtvent_signalOutport1;
  real_T PACE_CHARGE_CTRL;             /* '<Root>/Chart' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Chart' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Chart' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Chart' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Chart' */
  real_T PACE_GND_CTRL;                /* '<Root>/Chart' */
  real_T ATR_GND_CTRL;                 /* '<Root>/Chart' */
  real_T VENT_GND_CTRL;                /* '<Root>/Chart' */
  real_T FRONTEND_CTRL;                /* '<Root>/Chart' */
  real_T AnalogInput1;                 /* '<Root>/Analog Input1' */
  real_T AnalogInput;                  /* '<Root>/Analog Input' */
  real_T rtb_MovingAverage_m;
  real_T cumRevIndex;
  real_T csum;
  real_T modValueRev;
  real_T z;
  real_T SquareRoot;                   /* '<S4>/Square Root' */
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  real32_T ATR_AMP;
  real32_T VENT_AMP;
  real32_T VENT_PW;                    /* '<Root>/Chart1' */
  real32_T ATR_PW;                     /* '<Root>/Chart1' */
  real32_T ATR_SENSE;                  /* '<Root>/Chart1' */
  real32_T ATR_AMP_c;                  /* '<Root>/Chart1' */
  real32_T VENT_SENSE;                 /* '<Root>/Chart1' */
  real32_T VENT_AMP_g;                 /* '<Root>/Chart1' */
  real32_T VENT_CMP_REF_PWM;           /* '<Root>/Chart' */
  real32_T PACING_REF_PWM;             /* '<Root>/Chart' */
  real32_T ATR_CMP_REF_PWM;            /* '<Root>/Chart' */
  int32_T i;
  uint32_T qY;
  uint8_T y[2];
  uint8_T b_x[2];
  uint8_T b_SwappedDataBytes[2];
  uint16_T VRP;                        /* '<Root>/Chart1' */
  uint16_T ARP;                        /* '<Root>/Chart1' */
  uint8_T BytePack4[4];                /* '<S1>/Byte Pack4' */
  uint8_T BytePack5[4];                /* '<S1>/Byte Pack5' */
  uint8_T BytePack10[8];               /* '<S1>/Byte Pack10' */
  uint8_T BytePack11[8];               /* '<S1>/Byte Pack11' */
  uint8_T rate_period;                 /* '<S4>/Chart1' */
  uint8_T URL;                         /* '<Root>/Chart1' */
  uint8_T LRL;                         /* '<Root>/Chart1' */
  uint8_T mode;                        /* '<Root>/Chart1' */
  uint8_T Period;                      /* '<Root>/Chart1' */
  uint8_T RESP_FACTOR;                 /* '<Root>/Chart1' */
  uint8_T status;
  uint8_T b_RegisterValue_c;
  uint8_T status_k;
  boolean_T b;
  boolean_T VENT_CMP_DETECT;
} B_group5_A2finalmodel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_gr_T obj; /* '<S4>/Moving Average' */
  freedomk64f_fxos8700_group5_A_T obj_j;/* '<S4>/FXOS8700 6-Axes Sensor' */
  freedomk64f_AnalogInput_group_T obj_f;/* '<Root>/Analog Input1' */
  freedomk64f_AnalogInput_group_T obj_e;/* '<Root>/Analog Input' */
  freedomk64f_SCIRead_group5_A2_T obj_l;/* '<Root>/Serial Receive' */
  freedomk64f_DigitalRead_group_T obj_m;/* '<S4>/VENT_CMP_DETECT' */
  freedomk64f_DigitalRead_group_T obj_et;/* '<S4>/ATR_CMP_DETECT' */
  freedomk64f_SCIWrite_group5_A_T obj_jz;/* '<S1>/Serial Transmit1' */
  freedomk64f_PWMOutput_group5__T obj_c;/* '<S5>/VENT_CMP_REF_PWM' */
  freedomk64f_PWMOutput_group5__T obj_lj;/* '<S5>/PACING_REF_PWM' */
  freedomk64f_PWMOutput_group5__T obj_a;/* '<S5>/ATR_CMP_REF_PWM' */
  freedomk64f_DigitalWrite_grou_T obj_fj;/* '<S5>/Z_VENT_CTRL' */
  freedomk64f_DigitalWrite_grou_T obj_p;/* '<S5>/Z_ATR_CTRL' */
  freedomk64f_DigitalWrite_grou_T obj_i;/* '<S5>/VENT_PACE_CTRL' */
  freedomk64f_DigitalWrite_grou_T obj_c1;/* '<S5>/VENT_GND_CTRL ' */
  freedomk64f_DigitalWrite_grou_T obj_h;/* '<S5>/PACE_GND_CTRL ' */
  freedomk64f_DigitalWrite_grou_T obj_jf;/* '<S5>/PACE_CHARGE_CTRL' */
  freedomk64f_DigitalWrite_grou_T obj_k;/* '<S5>/FRONTEND_CTRL' */
  freedomk64f_DigitalWrite_grou_T obj_b;/* '<S5>/ATR_PACE_CTRL ' */
  freedomk64f_DigitalWrite_grou_T obj_iw;/* '<S5>/ATR_GND_CTRL' */
  real_T Hys;                          /* '<Root>/Chart' */
  real_T Set_VRP;                      /* '<Root>/Chart' */
  real_T Set_ARP;                      /* '<Root>/Chart' */
  real_T Hys_on;                       /* '<Root>/Chart' */
  real_T Hys_delay;                    /* '<Root>/Chart' */
  real32_T copy_Period;                /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T Highest;                     /* '<S4>/Chart1' */
  uint8_T Lowest;                      /* '<S4>/Chart1' */
  uint8_T Interval;                    /* '<S4>/Chart1' */
  uint8_T is_active_c3_group5_A2finalmode;/* '<S4>/Chart1' */
  uint8_T is_c3_group5_A2finalmodel;   /* '<S4>/Chart1' */
  uint8_T is_active_c1_group5_A2finalmode;/* '<Root>/Chart1' */
  uint8_T is_c1_group5_A2finalmodel;   /* '<Root>/Chart1' */
  uint8_T is_active_c2_group5_A2finalmode;/* '<Root>/Chart' */
  uint8_T is_c2_group5_A2finalmodel;   /* '<Root>/Chart' */
  uint8_T is_AAI;                      /* '<Root>/Chart' */
  uint8_T is_AAIR;                     /* '<Root>/Chart' */
  uint8_T is_rate_adjust;              /* '<Root>/Chart' */
  uint8_T is_rate_adjust1;             /* '<Root>/Chart' */
  uint8_T is_rate_adjust2;             /* '<Root>/Chart' */
  uint8_T is_AOO;                      /* '<Root>/Chart' */
  uint8_T is_AOOR;                     /* '<Root>/Chart' */
  uint8_T is_VOO;                      /* '<Root>/Chart' */
  uint8_T is_VOOR;                     /* '<Root>/Chart' */
  uint8_T is_VVI;                      /* '<Root>/Chart' */
  uint8_T is_VVIR;                     /* '<Root>/Chart' */
  uint8_T is_rate_adjust_i;            /* '<Root>/Chart' */
  uint8_T is_rate_adjust2_b;           /* '<Root>/Chart' */
} DW_group5_A2finalmodel_T;

/* Parameters (default storage) */
struct P_group5_A2finalmodel_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S4>/ATR_CMP_DETECT'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S4>/FXOS8700 6-Axes Sensor'
                                         */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S4>/VENT_CMP_DETECT'
                                        */
  real_T Gain_Gain;                    /* Expression: 9.8
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 60000
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 60
                                        * Referenced by: '<S4>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_group5_A2finalmodel_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_group5_A2finalmodel_T group5_A2finalmodel_P;

/* Block signals (default storage) */
extern B_group5_A2finalmodel_T group5_A2finalmodel_B;

/* Block states (default storage) */
extern DW_group5_A2finalmodel_T group5_A2finalmodel_DW;

/* Model entry point functions */
extern void group5_A2finalmodel_initialize(void);
extern void group5_A2finalmodel_step(void);
extern void group5_A2finalmodel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_group5_A2finalmodel_T *const group5_A2finalmodel_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'group5_A2finalmodel'
 * '<S1>'   : 'group5_A2finalmodel/COM_OUT1'
 * '<S2>'   : 'group5_A2finalmodel/Chart'
 * '<S3>'   : 'group5_A2finalmodel/Chart1'
 * '<S4>'   : 'group5_A2finalmodel/Subjdsystem'
 * '<S5>'   : 'group5_A2finalmodel/Subsystem1'
 * '<S6>'   : 'group5_A2finalmodel/Subjdsystem/Chart1'
 */
#endif                                 /* RTW_HEADER_group5_A2finalmodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
