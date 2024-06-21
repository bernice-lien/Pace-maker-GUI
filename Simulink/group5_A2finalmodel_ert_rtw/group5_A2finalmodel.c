/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: group5_A2finalmodel.c
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

#include "group5_A2finalmodel.h"
#include "rtwtypes.h"
#include "group5_A2finalmodel_types.h"
#include <string.h>
#include <math.h>
#include "rt_roundd_snf.h"
#include <stddef.h>
#include "transmit.h"
#include "transmit_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define group5_A2_IN_Charging_sensing_l ((uint8_T)1U)
#define group5_A2f_IN_Charging_sensing1 ((uint8_T)1U)
#define group5_A2fi_IN_Charging_sensing ((uint8_T)2U)
#define group5_A2fin_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define group5_A2fina_IN_rate_adjust2_o ((uint8_T)6U)
#define group5_A2final_IN_rate_adjust_h ((uint8_T)5U)
#define group5_A2finalm_IN_rate_adjust1 ((uint8_T)7U)
#define group5_A2finalm_IN_rate_adjust2 ((uint8_T)8U)
#define group5_A2finalmo_IN_Discharging ((uint8_T)2U)
#define group5_A2finalmo_IN_rate_adjust ((uint8_T)6U)
#define group5_A2finalmod_IN_Mode_Start ((uint8_T)5U)
#define group5_A2finalmod_IN_Pacing_gmb ((uint8_T)3U)
#define group5_A2finalmode_IN_Initate_l ((uint8_T)3U)
#define group5_A2finalmode_IN_Pacing_gm ((uint8_T)2U)
#define group5_A2finalmode_IN_decrease2 ((uint8_T)1U)
#define group5_A2finalmode_IN_increase2 ((uint8_T)2U)
#define group5_A2finalmodel_IN_AAI     ((uint8_T)1U)
#define group5_A2finalmodel_IN_AAIR    ((uint8_T)2U)
#define group5_A2finalmodel_IN_AOO     ((uint8_T)3U)
#define group5_A2finalmodel_IN_AOOR    ((uint8_T)4U)
#define group5_A2finalmodel_IN_ARP_ON  ((uint8_T)1U)
#define group5_A2finalmodel_IN_Charging ((uint8_T)1U)
#define group5_A2finalmodel_IN_Hys_ON  ((uint8_T)3U)
#define group5_A2finalmodel_IN_INIT    ((uint8_T)3U)
#define group5_A2finalmodel_IN_INIT1   ((uint8_T)2U)
#define group5_A2finalmodel_IN_INIT_m  ((uint8_T)4U)
#define group5_A2finalmodel_IN_INIT_ml ((uint8_T)2U)
#define group5_A2finalmodel_IN_Initate ((uint8_T)2U)
#define group5_A2finalmodel_IN_Pacing  ((uint8_T)4U)
#define group5_A2finalmodel_IN_Pacing1 ((uint8_T)3U)
#define group5_A2finalmodel_IN_Pacing_g ((uint8_T)5U)
#define group5_A2finalmodel_IN_VOO     ((uint8_T)6U)
#define group5_A2finalmodel_IN_VOOR    ((uint8_T)7U)
#define group5_A2finalmodel_IN_VRP_ON  ((uint8_T)4U)
#define group5_A2finalmodel_IN_VRP_ON1 ((uint8_T)4U)
#define group5_A2finalmodel_IN_VVI     ((uint8_T)8U)
#define group5_A2finalmodel_IN_VVIR    ((uint8_T)9U)
#define group5_A2finalmodel_IN_decrease ((uint8_T)4U)
#define group5_A2finalmodel_IN_increase ((uint8_T)5U)

/* Named constants for Chart: '<Root>/Chart1' */
#define group5_A2finalmode_IN_Set_Param ((uint8_T)3U)
#define group5_A2finalmodel_IN_Echo    ((uint8_T)1U)
#define group5_A2finalmodel_IN_Initial ((uint8_T)2U)
#define group5_A2finalmodel_IN_Standby ((uint8_T)4U)

/* Named constants for Chart: '<S4>/Chart1' */
#define group5_A2finalmode_IN_Mid_high1 ((uint8_T)3U)
#define group5_A2finalmode_IN_Rest_Mid1 ((uint8_T)4U)
#define group5_A2finalmodel_IN_High1   ((uint8_T)1U)
#define group5_A2finalmodel_IN_Mid1    ((uint8_T)2U)
#define group5_A2finalmodel_IN_Resting1 ((uint8_T)5U)
#define group5_A2finalmodel_IN_initial1 ((uint8_T)6U)

/* Block signals (default storage) */
B_group5_A2finalmodel_T group5_A2finalmodel_B;

/* Block states (default storage) */
DW_group5_A2finalmodel_T group5_A2finalmodel_DW;

/* Real-time model */
static RT_MODEL_group5_A2finalmodel_T group5_A2finalmodel_M_;
RT_MODEL_group5_A2finalmodel_T *const group5_A2finalmodel_M =
  &group5_A2finalmodel_M_;

/* Forward declaration for local functions */
static void enter_atomic_Charging_sensin_pa(void);
static void group5_A2finalmodel_VVIR(const boolean_T *VENT_CMP_DETECT);
static void g_enter_atomic_Charging_sensing(void);
static void enter_atomic_Charging_sensing_p(void);
static void group5_A2finalmodel_AAIR(const boolean_T *ATR_CMP_DETECT);
static void group5_A2_enter_atomic_Charging(void);
static void group5_A2finalmodel_AOOR(void);
static void group5_enter_atomic_Charging_ej(void);
static void group5_A2finalmodel_VOOR(void);
static void group5_A2finalmodel_VVI(const boolean_T *VENT_CMP_DETECT);
static void group5_A2fin_SystemCore_setup_k(freedomk64f_SCIRead_group5_A2_T *obj);
static void group5_A2fi_SystemCore_setup_k2(freedomk64f_fxos8700_group5_A_T *obj);
static void group5_A2f_SystemCore_setup_k2c(dsp_simulink_MovingAverage_gr_T *obj);

/* Function for Chart: '<Root>/Chart' */
static void enter_atomic_Charging_sensin_pa(void)
{
  group5_A2finalmodel_B.FRONTEND_CTRL = 1.0;
  group5_A2finalmodel_B.VENT_CMP_REF_PWM = group5_A2finalmodel_B.VENT_SENSE;
  group5_A2finalmodel_B.PACING_REF_PWM = group5_A2finalmodel_B.VENT_AMP_g;
  group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
  group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
  group5_A2finalmodel_B.VENT_PACE_CTRL = 0.0;
  group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
  group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
  group5_A2finalmodel_B.ATR_PACE_CTRL = 0.0;
  group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
  group5_A2finalmodel_B.VENT_GND_CTRL = 1.0;
}

/* Function for Chart: '<Root>/Chart' */
static void group5_A2finalmodel_VVIR(const boolean_T *VENT_CMP_DETECT)
{
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  if (group5_A2finalmodel_B.mode != 8) {
    group5_A2finalmodel_DW.is_rate_adjust_i = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_rate_adjust2_b = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_VVIR = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
      group5_A2finalmod_IN_Mode_Start;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    switch (group5_A2finalmodel_DW.is_VVIR) {
     case group5_A2f_IN_Charging_sensing1:
      group5_A2finalmodel_B.FRONTEND_CTRL = 1.0;
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 1.0;
      if (group5_A2finalmodel_DW.Set_VRP == 0.0) {
        if (*VENT_CMP_DETECT) {
          guard1 = true;
        } else if (group5_A2finalmodel_DW.temporalCounter_i1 >=
                   group5_A2finalmodel_DW.copy_Period -
                   group5_A2finalmodel_B.VENT_PW) {
          guard2 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }
      break;

     case group5_A2finalmodel_IN_INIT1:
      group5_A2finalmodel_DW.is_VVIR = group5_A2f_IN_Charging_sensing1;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      enter_atomic_Charging_sensin_pa();
      break;

     case group5_A2finalmodel_IN_Pacing1:
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          group5_A2finalmodel_B.VENT_PW) {
        if (group5_A2finalmodel_DW.copy_Period >
            group5_A2finalmodel_B.rate_period) {
          group5_A2finalmodel_DW.is_VVIR = group5_A2final_IN_rate_adjust_h;
          group5_A2finalmodel_DW.is_rate_adjust_i =
            group5_A2finalmode_IN_decrease2;
          group5_A2finalmodel_DW.copy_Period -= (real32_T)
            group5_A2finalmodel_B.RESP_FACTOR;
        } else if (group5_A2finalmodel_DW.copy_Period <
                   group5_A2finalmodel_B.rate_period) {
          group5_A2finalmodel_DW.is_VVIR = group5_A2final_IN_rate_adjust_h;
          group5_A2finalmodel_DW.is_rate_adjust_i =
            group5_A2finalmode_IN_increase2;
          group5_A2finalmodel_DW.copy_Period += (real32_T)
            group5_A2finalmodel_B.RESP_FACTOR;
        } else if (group5_A2finalmodel_DW.copy_Period ==
                   group5_A2finalmodel_B.rate_period) {
          group5_A2finalmodel_DW.is_VVIR = group5_A2f_IN_Charging_sensing1;
          group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_sensin_pa();
        }
      }
      break;

     case group5_A2finalmodel_IN_VRP_ON1:
      if (group5_A2finalmodel_DW.Hys_on == 0.0) {
        group5_A2finalmodel_DW.is_VVIR = group5_A2f_IN_Charging_sensing1;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_sensin_pa();
      }
      break;

     case group5_A2final_IN_rate_adjust_h:
      if (group5_A2finalmodel_DW.is_rate_adjust_i ==
          group5_A2finalmode_IN_decrease2) {
        group5_A2finalmodel_DW.is_rate_adjust_i =
          group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_VVIR = group5_A2f_IN_Charging_sensing1;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_sensin_pa();
      } else {
        /* case IN_increase2: */
        group5_A2finalmodel_DW.is_rate_adjust_i =
          group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_VVIR = group5_A2f_IN_Charging_sensing1;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_sensin_pa();
      }
      break;

     default:
      /* case IN_rate_adjust2: */
      if (group5_A2finalmodel_DW.is_rate_adjust2_b ==
          group5_A2finalmode_IN_decrease2) {
        group5_A2finalmodel_DW.is_rate_adjust2_b =
          group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_VVIR = group5_A2finalmodel_IN_VRP_ON1;
        group5_A2finalmodel_DW.Set_VRP = 1.0;
      } else {
        /* case IN_increase2: */
        group5_A2finalmodel_DW.is_rate_adjust2_b =
          group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_VVIR = group5_A2finalmodel_IN_VRP_ON1;
        group5_A2finalmodel_DW.Set_VRP = 1.0;
      }
      break;
    }

    if (guard3) {
      if ((group5_A2finalmodel_DW.Set_VRP == 1.0) &&
          (group5_A2finalmodel_DW.temporalCounter_i1 >=
           group5_A2finalmodel_B.VRP)) {
        if (group5_A2finalmodel_DW.temporalCounter_i1 >=
            (group5_A2finalmodel_DW.copy_Period - group5_A2finalmodel_B.VENT_PW)
            - (real32_T)group5_A2finalmodel_B.VRP) {
          guard2 = true;
        } else if (*VENT_CMP_DETECT) {
          if (group5_A2finalmodel_DW.copy_Period >
              group5_A2finalmodel_B.rate_period) {
            group5_A2finalmodel_DW.is_VVIR = group5_A2fina_IN_rate_adjust2_o;
            group5_A2finalmodel_DW.is_rate_adjust2_b =
              group5_A2finalmode_IN_decrease2;
            group5_A2finalmodel_DW.copy_Period -= (real32_T)
              group5_A2finalmodel_B.RESP_FACTOR;
          } else if (group5_A2finalmodel_DW.copy_Period <
                     group5_A2finalmodel_B.rate_period) {
            group5_A2finalmodel_DW.is_VVIR = group5_A2fina_IN_rate_adjust2_o;
            group5_A2finalmodel_DW.is_rate_adjust2_b =
              group5_A2finalmode_IN_increase2;
            group5_A2finalmodel_DW.copy_Period += (real32_T)
              group5_A2finalmodel_B.RESP_FACTOR;
          } else if (group5_A2finalmodel_DW.copy_Period ==
                     group5_A2finalmodel_B.rate_period) {
            guard1 = true;
          }
        }
      }
    }

    if (guard2) {
      group5_A2finalmodel_DW.is_VVIR = group5_A2finalmodel_IN_Pacing1;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_PACE_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_PACE_CTRL = 1.0;
      group5_A2finalmodel_DW.Set_VRP = 1.0;
    }

    if (guard1) {
      group5_A2finalmodel_DW.is_VVIR = group5_A2finalmodel_IN_VRP_ON1;
      group5_A2finalmodel_DW.Set_VRP = 1.0;
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void g_enter_atomic_Charging_sensing(void)
{
  group5_A2finalmodel_B.FRONTEND_CTRL = 1.0;
  group5_A2finalmodel_B.ATR_CMP_REF_PWM = group5_A2finalmodel_B.ATR_SENSE;
  group5_A2finalmodel_B.PACING_REF_PWM = group5_A2finalmodel_B.ATR_AMP_c;
  group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
  group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
  group5_A2finalmodel_B.ATR_PACE_CTRL = 0.0;
  group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
  group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
  group5_A2finalmodel_B.ATR_GND_CTRL = 1.0;
  group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
  group5_A2finalmodel_B.VENT_PACE_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void enter_atomic_Charging_sensing_p(void)
{
  group5_A2finalmodel_B.FRONTEND_CTRL = 1.0;
  group5_A2finalmodel_B.ATR_CMP_REF_PWM = group5_A2finalmodel_B.ATR_SENSE;
  group5_A2finalmodel_B.PACING_REF_PWM = group5_A2finalmodel_B.ATR_AMP_c;
  group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
  group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
  group5_A2finalmodel_B.ATR_PACE_CTRL = 0.0;
  group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
  group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
  group5_A2finalmodel_B.ATR_GND_CTRL = 1.0;
  group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
  group5_A2finalmodel_B.VENT_PACE_CTRL = 0.0;
  group5_A2finalmodel_DW.Hys_delay = 100.0;
}

/* Function for Chart: '<Root>/Chart' */
static void group5_A2finalmodel_AAIR(const boolean_T *ATR_CMP_DETECT)
{
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  boolean_T guard5;
  if (group5_A2finalmodel_B.mode != 7) {
    group5_A2finalmodel_DW.is_rate_adjust = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_rate_adjust1 = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_rate_adjust2 = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_AAIR = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
      group5_A2finalmod_IN_Mode_Start;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    switch (group5_A2finalmodel_DW.is_AAIR) {
     case group5_A2finalmodel_IN_ARP_ON:
      if (group5_A2finalmodel_DW.Hys_on == 0.0) {
        group5_A2finalmodel_DW.is_AAIR = group5_A2fi_IN_Charging_sensing;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_sensing_p();
      } else if (group5_A2finalmodel_DW.Hys_on == 1.0) {
        group5_A2finalmodel_DW.is_AAIR = group5_A2finalmodel_IN_Hys_ON;
        group5_A2finalmodel_DW.Hys = 1.0;
      }
      break;

     case group5_A2fi_IN_Charging_sensing:
      group5_A2finalmodel_B.FRONTEND_CTRL = 1.0;
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 1.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
      if (group5_A2finalmodel_DW.Set_ARP == 0.0) {
        if (*ATR_CMP_DETECT) {
          guard1 = true;
        } else if (group5_A2finalmodel_DW.temporalCounter_i1 >=
                   group5_A2finalmodel_DW.copy_Period -
                   group5_A2finalmodel_B.ATR_PW) {
          guard2 = true;
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }
      break;

     case group5_A2finalmodel_IN_Hys_ON:
      group5_A2finalmodel_DW.is_AAIR = group5_A2fi_IN_Charging_sensing;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      enter_atomic_Charging_sensing_p();
      break;

     case group5_A2finalmodel_IN_INIT_m:
      group5_A2finalmodel_DW.is_AAIR = group5_A2fi_IN_Charging_sensing;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      enter_atomic_Charging_sensing_p();
      break;

     case group5_A2finalmodel_IN_Pacing_g:
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          group5_A2finalmodel_B.ATR_PW) {
        if (group5_A2finalmodel_DW.copy_Period >
            group5_A2finalmodel_B.rate_period) {
          group5_A2finalmodel_DW.is_AAIR = group5_A2finalmo_IN_rate_adjust;
          group5_A2finalmodel_DW.is_rate_adjust =
            group5_A2finalmode_IN_decrease2;
          group5_A2finalmodel_DW.copy_Period -= (real32_T)
            group5_A2finalmodel_B.RESP_FACTOR;
        } else if (group5_A2finalmodel_DW.copy_Period <
                   group5_A2finalmodel_B.rate_period) {
          group5_A2finalmodel_DW.is_AAIR = group5_A2finalmo_IN_rate_adjust;
          group5_A2finalmodel_DW.is_rate_adjust =
            group5_A2finalmode_IN_increase2;
          group5_A2finalmodel_DW.copy_Period += (real32_T)
            group5_A2finalmodel_B.RESP_FACTOR;
        } else if (group5_A2finalmodel_DW.copy_Period ==
                   group5_A2finalmodel_B.rate_period) {
          group5_A2finalmodel_DW.is_AAIR = group5_A2fi_IN_Charging_sensing;
          group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_sensing_p();
        }
      }
      break;

     case group5_A2finalmo_IN_rate_adjust:
      if (group5_A2finalmodel_DW.is_rate_adjust ==
          group5_A2finalmode_IN_decrease2) {
        group5_A2finalmodel_DW.is_rate_adjust = group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_AAIR = group5_A2fi_IN_Charging_sensing;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_sensing_p();
      } else {
        /* case IN_increase2: */
        group5_A2finalmodel_DW.is_rate_adjust = group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_AAIR = group5_A2fi_IN_Charging_sensing;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_sensing_p();
      }
      break;

     case group5_A2finalm_IN_rate_adjust1:
      if (group5_A2finalmodel_DW.is_rate_adjust1 ==
          group5_A2finalmode_IN_decrease2) {
        group5_A2finalmodel_DW.is_rate_adjust1 = group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_AAIR = group5_A2finalmodel_IN_ARP_ON;
        group5_A2finalmodel_DW.Set_ARP = 1.0;
      } else {
        /* case IN_increase2: */
        group5_A2finalmodel_DW.is_rate_adjust1 = group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_AAIR = group5_A2finalmodel_IN_ARP_ON;
        group5_A2finalmodel_DW.Set_ARP = 1.0;
      }
      break;

     default:
      /* case IN_rate_adjust2: */
      if (group5_A2finalmodel_DW.is_rate_adjust2 ==
          group5_A2finalmode_IN_decrease2) {
        group5_A2finalmodel_DW.is_rate_adjust2 = group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_AAIR = group5_A2finalmodel_IN_ARP_ON;
        group5_A2finalmodel_DW.Set_ARP = 1.0;
      } else {
        /* case IN_increase2: */
        group5_A2finalmodel_DW.is_rate_adjust2 = group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_AAIR = group5_A2finalmodel_IN_ARP_ON;
        group5_A2finalmodel_DW.Set_ARP = 1.0;
      }
      break;
    }

    if (guard5) {
      if ((group5_A2finalmodel_DW.Set_ARP == 1.0) &&
          (group5_A2finalmodel_DW.temporalCounter_i1 >=
           group5_A2finalmodel_B.ARP)) {
        if (group5_A2finalmodel_DW.Hys == 0.0) {
          if (group5_A2finalmodel_DW.temporalCounter_i1 >=
              group5_A2finalmodel_DW.copy_Period - group5_A2finalmodel_B.ATR_PW)
          {
            guard2 = true;
          } else if (*ATR_CMP_DETECT) {
            if (group5_A2finalmodel_DW.copy_Period >
                group5_A2finalmodel_B.rate_period) {
              group5_A2finalmodel_DW.is_AAIR = group5_A2finalm_IN_rate_adjust2;
              group5_A2finalmodel_DW.is_rate_adjust2 =
                group5_A2finalmode_IN_decrease2;
              group5_A2finalmodel_DW.copy_Period -= (real32_T)
                group5_A2finalmodel_B.RESP_FACTOR;
            } else if (group5_A2finalmodel_DW.copy_Period <
                       group5_A2finalmodel_B.rate_period) {
              group5_A2finalmodel_DW.is_AAIR = group5_A2finalm_IN_rate_adjust2;
              group5_A2finalmodel_DW.is_rate_adjust2 =
                group5_A2finalmode_IN_increase2;
              group5_A2finalmodel_DW.copy_Period += (real32_T)
                group5_A2finalmodel_B.RESP_FACTOR;
            } else if (group5_A2finalmodel_DW.copy_Period ==
                       group5_A2finalmodel_B.rate_period) {
              guard1 = true;
            } else {
              guard4 = true;
            }
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }
      }
    }

    if (guard4) {
      if (group5_A2finalmodel_DW.Hys == 1.0) {
        if (*ATR_CMP_DETECT) {
          if (group5_A2finalmodel_DW.copy_Period >
              group5_A2finalmodel_B.rate_period) {
            group5_A2finalmodel_DW.is_AAIR = group5_A2finalm_IN_rate_adjust1;
            group5_A2finalmodel_DW.is_rate_adjust1 =
              group5_A2finalmode_IN_decrease2;
            group5_A2finalmodel_DW.copy_Period -= (real32_T)
              group5_A2finalmodel_B.RESP_FACTOR;
          } else if (group5_A2finalmodel_DW.copy_Period <
                     group5_A2finalmodel_B.rate_period) {
            group5_A2finalmodel_DW.is_AAIR = group5_A2finalm_IN_rate_adjust1;
            group5_A2finalmodel_DW.is_rate_adjust1 =
              group5_A2finalmode_IN_increase2;
            group5_A2finalmodel_DW.copy_Period += (real32_T)
              group5_A2finalmodel_B.RESP_FACTOR;
          } else if (group5_A2finalmodel_DW.copy_Period ==
                     group5_A2finalmodel_B.rate_period) {
            guard1 = true;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }
      }
    }

    if (guard3) {
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          (group5_A2finalmodel_DW.copy_Period - group5_A2finalmodel_B.ATR_PW) +
          (real32_T)group5_A2finalmodel_DW.Hys_delay) {
        guard2 = true;
      }
    }

    if (guard2) {
      group5_A2finalmodel_DW.is_AAIR = group5_A2finalmodel_IN_Pacing_g;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_PACE_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_PACE_CTRL = 1.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_DW.Set_ARP = 1.0;
      group5_A2finalmodel_DW.Hys = 0.0;
    }

    if (guard1) {
      group5_A2finalmodel_DW.is_AAIR = group5_A2finalmodel_IN_ARP_ON;
      group5_A2finalmodel_DW.Set_ARP = 1.0;
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void group5_A2_enter_atomic_Charging(void)
{
  group5_A2finalmodel_B.PACING_REF_PWM = group5_A2finalmodel_B.ATR_AMP_c;
  group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
  group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
  group5_A2finalmodel_B.ATR_PACE_CTRL = 0.0;
  group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
  group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
  group5_A2finalmodel_B.ATR_GND_CTRL = 1.0;
  group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
  group5_A2finalmodel_B.VENT_PACE_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void group5_A2finalmodel_AOOR(void)
{
  if (group5_A2finalmodel_B.mode != 5) {
    group5_A2finalmodel_DW.is_AOOR = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
      group5_A2finalmod_IN_Mode_Start;
  } else {
    switch (group5_A2finalmodel_DW.is_AOOR) {
     case group5_A2finalmodel_IN_Charging:
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 1.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          group5_A2finalmodel_DW.copy_Period - group5_A2finalmodel_B.ATR_PW) {
        group5_A2finalmodel_DW.is_AOOR = group5_A2finalmod_IN_Pacing_gmb;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
        group5_A2finalmodel_B.VENT_PACE_CTRL = 0.0;
        group5_A2finalmodel_B.ATR_PACE_CTRL = 1.0;
        group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      }
      break;

     case group5_A2finalmodel_IN_Initate:
      group5_A2finalmodel_DW.is_AOOR = group5_A2finalmodel_IN_Charging;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      group5_A2_enter_atomic_Charging();
      break;

     case group5_A2finalmod_IN_Pacing_gmb:
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
      if ((group5_A2finalmodel_DW.copy_Period ==
           group5_A2finalmodel_B.rate_period) &&
          (group5_A2finalmodel_DW.temporalCounter_i1 >=
           group5_A2finalmodel_B.ATR_PW)) {
        group5_A2finalmodel_DW.is_AOOR = group5_A2finalmodel_IN_Charging;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2_enter_atomic_Charging();
      } else if (group5_A2finalmodel_DW.copy_Period <
                 group5_A2finalmodel_B.rate_period) {
        group5_A2finalmodel_DW.is_AOOR = group5_A2finalmodel_IN_increase;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2finalmodel_DW.copy_Period += (real32_T)
          group5_A2finalmodel_B.RESP_FACTOR;
      } else if (group5_A2finalmodel_DW.copy_Period >
                 group5_A2finalmodel_B.rate_period) {
        group5_A2finalmodel_DW.is_AOOR = group5_A2finalmodel_IN_decrease;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2finalmodel_DW.copy_Period -= (real32_T)
          group5_A2finalmodel_B.RESP_FACTOR;
      }
      break;

     case group5_A2finalmodel_IN_decrease:
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          group5_A2finalmodel_B.ATR_PW) {
        group5_A2finalmodel_DW.is_AOOR = group5_A2finalmodel_IN_Charging;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2_enter_atomic_Charging();
      }
      break;

     default:
      /* case IN_increase: */
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          group5_A2finalmodel_B.ATR_PW) {
        group5_A2finalmodel_DW.is_AOOR = group5_A2finalmodel_IN_Charging;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2_enter_atomic_Charging();
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void group5_enter_atomic_Charging_ej(void)
{
  group5_A2finalmodel_B.PACING_REF_PWM = group5_A2finalmodel_B.VENT_AMP_g;
  group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
  group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
  group5_A2finalmodel_B.VENT_PACE_CTRL = 0.0;
  group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
  group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
  group5_A2finalmodel_B.ATR_PACE_CTRL = 0.0;
  group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
  group5_A2finalmodel_B.VENT_GND_CTRL = 1.0;
}

/* Function for Chart: '<Root>/Chart' */
static void group5_A2finalmodel_VOOR(void)
{
  if (group5_A2finalmodel_B.mode != 6) {
    group5_A2finalmodel_DW.is_VOOR = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
      group5_A2finalmod_IN_Mode_Start;
  } else {
    switch (group5_A2finalmodel_DW.is_VOOR) {
     case group5_A2finalmodel_IN_Charging:
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 1.0;
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          group5_A2finalmodel_DW.copy_Period - group5_A2finalmodel_B.VENT_PW) {
        group5_A2finalmodel_DW.is_VOOR = group5_A2finalmo_IN_Discharging;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
        group5_A2finalmodel_B.ATR_PACE_CTRL = 0.0;
        group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
        group5_A2finalmodel_B.VENT_PACE_CTRL = 1.0;
      }
      break;

     case group5_A2finalmo_IN_Discharging:
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
      if (group5_A2finalmodel_DW.copy_Period < group5_A2finalmodel_B.rate_period)
      {
        group5_A2finalmodel_DW.is_VOOR = group5_A2finalmodel_IN_increase;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2finalmodel_DW.copy_Period += (real32_T)
          group5_A2finalmodel_B.RESP_FACTOR;
      } else if (group5_A2finalmodel_DW.copy_Period >
                 group5_A2finalmodel_B.rate_period) {
        group5_A2finalmodel_DW.is_VOOR = group5_A2finalmodel_IN_decrease;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2finalmodel_DW.copy_Period -= (real32_T)
          group5_A2finalmodel_B.RESP_FACTOR;
      } else if ((group5_A2finalmodel_DW.copy_Period ==
                  group5_A2finalmodel_B.rate_period) &&
                 (group5_A2finalmodel_DW.temporalCounter_i1 >=
                  group5_A2finalmodel_B.VENT_PW)) {
        group5_A2finalmodel_DW.is_VOOR = group5_A2finalmodel_IN_Charging;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_enter_atomic_Charging_ej();
      }
      break;

     case group5_A2finalmode_IN_Initate_l:
      group5_A2finalmodel_DW.is_VOOR = group5_A2finalmodel_IN_Charging;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      group5_enter_atomic_Charging_ej();
      break;

     case group5_A2finalmodel_IN_decrease:
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          group5_A2finalmodel_B.VENT_PW) {
        group5_A2finalmodel_DW.is_VOOR = group5_A2finalmodel_IN_Charging;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_enter_atomic_Charging_ej();
      }
      break;

     default:
      /* case IN_increase: */
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          group5_A2finalmodel_B.VENT_PW) {
        group5_A2finalmodel_DW.is_VOOR = group5_A2finalmodel_IN_Charging;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_enter_atomic_Charging_ej();
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void group5_A2finalmodel_VVI(const boolean_T *VENT_CMP_DETECT)
{
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  if (group5_A2finalmodel_B.mode != 4) {
    group5_A2finalmodel_DW.is_VVI = group5_A2fin_IN_NO_ACTIVE_CHILD;
    group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
      group5_A2finalmod_IN_Mode_Start;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    switch (group5_A2finalmodel_DW.is_VVI) {
     case group5_A2_IN_Charging_sensing_l:
      group5_A2finalmodel_B.FRONTEND_CTRL = 1.0;
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 1.0;
      if ((group5_A2finalmodel_DW.Set_VRP == 1.0) &&
          (group5_A2finalmodel_DW.temporalCounter_i1 >=
           group5_A2finalmodel_B.VRP)) {
        if (group5_A2finalmodel_DW.temporalCounter_i1 >= (real32_T)
            group5_A2finalmodel_B.Period - group5_A2finalmodel_B.VENT_PW) {
          guard1 = true;
        } else if (*VENT_CMP_DETECT) {
          guard2 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }
      break;

     case group5_A2finalmodel_IN_INIT_ml:
      group5_A2finalmodel_DW.is_VVI = group5_A2_IN_Charging_sensing_l;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      enter_atomic_Charging_sensin_pa();
      break;

     case group5_A2finalmod_IN_Pacing_gmb:
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
      group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
      group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
      if (group5_A2finalmodel_DW.temporalCounter_i1 >=
          group5_A2finalmodel_B.VENT_PW) {
        group5_A2finalmodel_DW.is_VVI = group5_A2_IN_Charging_sensing_l;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_sensin_pa();
      }
      break;

     default:
      /* case IN_VRP_ON: */
      group5_A2finalmodel_DW.is_VVI = group5_A2_IN_Charging_sensing_l;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      enter_atomic_Charging_sensin_pa();
      break;
    }

    if (guard3) {
      if (group5_A2finalmodel_DW.Set_VRP == 0.0) {
        if (*VENT_CMP_DETECT) {
          guard2 = true;
        } else if (group5_A2finalmodel_DW.temporalCounter_i1 >= (real32_T)
                   group5_A2finalmodel_B.Period - group5_A2finalmodel_B.VENT_PW)
        {
          guard1 = true;
        }
      }
    }

    if (guard2) {
      group5_A2finalmodel_DW.is_VVI = group5_A2finalmodel_IN_VRP_ON;
      group5_A2finalmodel_DW.Set_VRP = 1.0;
    }

    if (guard1) {
      group5_A2finalmodel_DW.is_VVI = group5_A2finalmod_IN_Pacing_gmb;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_PACE_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_PACE_CTRL = 1.0;
      group5_A2finalmodel_DW.Set_VRP = 1.0;
    }
  }
}

static void group5_A2fin_SystemCore_setup_k(freedomk64f_SCIRead_group5_A2_T *obj)
{
  obj->isInitialized = 1;
  group5_A2finalmodel_B.TxPinLoc = MW_UNDEFINED_VALUE;
  group5_A2finalmodel_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&group5_A2finalmodel_B.SCIModuleLoc, false,
    10U, group5_A2finalmodel_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  group5_A2finalmodel_B.StopBitsValue = MW_SCI_STOPBITS_1;
  group5_A2finalmodel_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, group5_A2finalmodel_B.ParityValue,
                        group5_A2finalmodel_B.StopBitsValue);
  obj->isSetupComplete = true;
}

static void group5_A2fi_SystemCore_setup_k2(freedomk64f_fxos8700_group5_A_T *obj)
{
  obj->isInitialized = 1;
  group5_A2finalmodel_B.ModeType = MW_I2C_MASTER;
  group5_A2finalmodel_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(group5_A2finalmodel_B.i2cname,
    group5_A2finalmodel_B.ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  group5_A2finalmodel_B.b_SwappedDataBytes[0] = 43U;
  group5_A2finalmodel_B.b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &group5_A2finalmodel_B.b_SwappedDataBytes[0], 2U, false,
                     false);
  OSA_TimeDelay(500U);
  group5_A2finalmodel_B.status_k = 42U;
  group5_A2finalmodel_B.status_k = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE,
    29U, &group5_A2finalmodel_B.status_k, 1U, true, false);
  if (group5_A2finalmodel_B.status_k == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U,
                      &group5_A2finalmodel_B.status_k, 1U, false, true);
    memcpy((void *)&group5_A2finalmodel_B.b_RegisterValue_c, (void *)
           &group5_A2finalmodel_B.status_k, (size_t)1 * sizeof(uint8_T));
  } else {
    group5_A2finalmodel_B.b_RegisterValue_c = 0U;
  }

  group5_A2finalmodel_B.b_SwappedDataBytes[0] = 42U;
  group5_A2finalmodel_B.b_SwappedDataBytes[1] = (uint8_T)
    (group5_A2finalmodel_B.b_RegisterValue_c & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &group5_A2finalmodel_B.b_SwappedDataBytes[0], 2U, false,
                     false);
  group5_A2finalmodel_B.b_SwappedDataBytes[0] = 14U;
  group5_A2finalmodel_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &group5_A2finalmodel_B.b_SwappedDataBytes[0], 2U, false,
                     false);
  group5_A2finalmodel_B.b_SwappedDataBytes[0] = 91U;
  group5_A2finalmodel_B.b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &group5_A2finalmodel_B.b_SwappedDataBytes[0], 2U, false,
                     false);
  group5_A2finalmodel_B.b_SwappedDataBytes[0] = 42U;
  group5_A2finalmodel_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &group5_A2finalmodel_B.b_SwappedDataBytes[0], 2U, false,
                     false);
  obj->isSetupComplete = true;
}

static void group5_A2f_SystemCore_setup_k2c(dsp_simulink_MovingAverage_gr_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function */
void group5_A2finalmodel_step(void)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (group5_A2finalmodel_DW.obj_l.SampleTime !=
      group5_A2finalmodel_P.SerialReceive_SampleTime) {
    group5_A2finalmodel_DW.obj_l.SampleTime =
      group5_A2finalmodel_P.SerialReceive_SampleTime;
  }

  group5_A2finalmodel_B.status = MW_SCI_Receive
    (group5_A2finalmodel_DW.obj_l.MW_SCIHANDLE,
     &group5_A2finalmodel_B.RxDataLocChar[0], 34U);
  memcpy((void *)&group5_A2finalmodel_B.RxData[0], (void *)
         &group5_A2finalmodel_B.RxDataLocChar[0], (size_t)34 * sizeof(uint8_T));

  /* MATLABSystem: '<Root>/Analog Input' */
  if (group5_A2finalmodel_DW.obj_e.SampleTime !=
      group5_A2finalmodel_P.AnalogInput_SampleTime) {
    group5_A2finalmodel_DW.obj_e.SampleTime =
      group5_A2finalmodel_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(group5_A2finalmodel_DW.obj_e.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(group5_A2finalmodel_DW.obj_e.MW_ANALOGIN_HANDLE,
    &group5_A2finalmodel_B.AnalogInput, 7);

  /* End of MATLABSystem: '<Root>/Analog Input' */

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (group5_A2finalmodel_DW.obj_f.SampleTime !=
      group5_A2finalmodel_P.AnalogInput1_SampleTime) {
    group5_A2finalmodel_DW.obj_f.SampleTime =
      group5_A2finalmodel_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(group5_A2finalmodel_DW.obj_f.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(group5_A2finalmodel_DW.obj_f.MW_ANALOGIN_HANDLE,
    &group5_A2finalmodel_B.AnalogInput1, 7);

  /* End of MATLABSystem: '<Root>/Analog Input1' */

  /* Chart: '<Root>/Chart1' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (group5_A2finalmodel_DW.is_active_c1_group5_A2finalmode == 0U) {
    group5_A2finalmodel_DW.is_active_c1_group5_A2finalmode = 1U;
    group5_A2finalmodel_DW.is_c1_group5_A2finalmodel =
      group5_A2finalmodel_IN_Initial;
    group5_A2finalmodel_B.mode = 1U;
    group5_A2finalmodel_B.Period = 80U;
    group5_A2finalmodel_B.ATR_AMP_c = 1.0F;
    group5_A2finalmodel_B.VENT_AMP_g = 1.0F;
    group5_A2finalmodel_B.ATR_PW = 0.5F;
    group5_A2finalmodel_B.VENT_PW = 0.5F;
    group5_A2finalmodel_B.ARP = 400U;
    group5_A2finalmodel_B.VRP = 500U;
    group5_A2finalmodel_B.ATR_SENSE = 0.25F;
    group5_A2finalmodel_B.VENT_SENSE = 0.25F;
    group5_A2finalmodel_B.RESP_FACTOR = 4U;
    group5_A2finalmodel_B.LRL = 60U;
    group5_A2finalmodel_B.URL = 160U;
  } else {
    switch (group5_A2finalmodel_DW.is_c1_group5_A2finalmodel) {
     case group5_A2finalmodel_IN_Echo:
      group5_A2finalmodel_DW.is_c1_group5_A2finalmodel =
        group5_A2finalmodel_IN_Standby;
      break;

     case group5_A2finalmodel_IN_Initial:
      group5_A2finalmodel_DW.is_c1_group5_A2finalmodel =
        group5_A2finalmodel_IN_Standby;
      break;

     case group5_A2finalmode_IN_Set_Param:
      group5_A2finalmodel_DW.is_c1_group5_A2finalmodel =
        group5_A2finalmodel_IN_Standby;
      break;

     default:
      /* case IN_Standby: */
      if (group5_A2finalmodel_B.status == 0) {
        switch (group5_A2finalmodel_B.RxData[0]) {
         case 1:
          group5_A2finalmodel_DW.is_c1_group5_A2finalmodel =
            group5_A2finalmode_IN_Set_Param;
          group5_A2finalmodel_B.mode = group5_A2finalmodel_B.RxData[1];
          group5_A2finalmodel_B.Period = group5_A2finalmodel_B.RxData[2];
          memcpy((void *)&group5_A2finalmodel_B.ATR_AMP_c, (void *)
                 &group5_A2finalmodel_B.RxData[3], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&group5_A2finalmodel_B.VENT_AMP_g, (void *)
                 &group5_A2finalmodel_B.RxData[7], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&group5_A2finalmodel_B.ATR_PW, (void *)
                 &group5_A2finalmodel_B.RxData[11], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&group5_A2finalmodel_B.VENT_PW, (void *)
                 &group5_A2finalmodel_B.RxData[15], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&group5_A2finalmodel_B.ARP, (void *)
                 &group5_A2finalmodel_B.RxData[19], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&group5_A2finalmodel_B.VRP, (void *)
                 &group5_A2finalmodel_B.RxData[21], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&group5_A2finalmodel_B.ATR_SENSE, (void *)
                 &group5_A2finalmodel_B.RxData[23], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&group5_A2finalmodel_B.VENT_SENSE, (void *)
                 &group5_A2finalmodel_B.RxData[27], (size_t)1 * sizeof(real32_T));
          group5_A2finalmodel_B.RESP_FACTOR = group5_A2finalmodel_B.RxData[31];
          group5_A2finalmodel_B.URL = group5_A2finalmodel_B.RxData[32];
          group5_A2finalmodel_B.LRL = group5_A2finalmodel_B.RxData[33];
          break;

         case 0:
          group5_A2finalmodel_DW.is_c1_group5_A2finalmodel =
            group5_A2finalmodel_IN_Echo;
          transmit();
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* MATLABSystem: '<S4>/FXOS8700 6-Axes Sensor' */
  if (group5_A2finalmodel_DW.obj_j.SampleTime !=
      group5_A2finalmodel_P.FXOS87006AxesSensor_SampleTime) {
    group5_A2finalmodel_DW.obj_j.SampleTime =
      group5_A2finalmodel_P.FXOS87006AxesSensor_SampleTime;
  }

  group5_A2finalmodel_B.status = 1U;
  group5_A2finalmodel_B.status = MW_I2C_MasterWrite
    (group5_A2finalmodel_DW.obj_j.i2cobj.MW_I2C_HANDLE, 29U,
     &group5_A2finalmodel_B.status, 1U, true, false);
  if (group5_A2finalmodel_B.status == 0) {
    MW_I2C_MasterRead(group5_A2finalmodel_DW.obj_j.i2cobj.MW_I2C_HANDLE, 29U,
                      &group5_A2finalmodel_B.output_raw[0], 6U, false, true);
    memcpy((void *)&group5_A2finalmodel_B.b_RegisterValue[0], (void *)
           &group5_A2finalmodel_B.output_raw[0], (size_t)3 * sizeof(int16_T));
    memcpy((void *)&group5_A2finalmodel_B.y[0], (void *)
           &group5_A2finalmodel_B.b_RegisterValue[0], (size_t)2 * sizeof(uint8_T));
    group5_A2finalmodel_B.b_x[0] = group5_A2finalmodel_B.y[1];
    group5_A2finalmodel_B.b_x[1] = group5_A2finalmodel_B.y[0];
    memcpy((void *)&group5_A2finalmodel_B.b_RegisterValue[0], (void *)
           &group5_A2finalmodel_B.b_x[0], (size_t)1 * sizeof(int16_T));
    memcpy((void *)&group5_A2finalmodel_B.y[0], (void *)
           &group5_A2finalmodel_B.b_RegisterValue[1], (size_t)2 * sizeof(uint8_T));
    group5_A2finalmodel_B.b_x[0] = group5_A2finalmodel_B.y[1];
    group5_A2finalmodel_B.b_x[1] = group5_A2finalmodel_B.y[0];
    memcpy((void *)&group5_A2finalmodel_B.b_RegisterValue[1], (void *)
           &group5_A2finalmodel_B.b_x[0], (size_t)1 * sizeof(int16_T));
    memcpy((void *)&group5_A2finalmodel_B.y[0], (void *)
           &group5_A2finalmodel_B.b_RegisterValue[2], (size_t)2 * sizeof(uint8_T));
    group5_A2finalmodel_B.b_x[0] = group5_A2finalmodel_B.y[1];
    group5_A2finalmodel_B.b_x[1] = group5_A2finalmodel_B.y[0];
    memcpy((void *)&group5_A2finalmodel_B.b_RegisterValue[2], (void *)
           &group5_A2finalmodel_B.b_x[0], (size_t)1 * sizeof(int16_T));
  } else {
    group5_A2finalmodel_B.b_RegisterValue[0] = 0;
    group5_A2finalmodel_B.b_RegisterValue[1] = 0;
    group5_A2finalmodel_B.b_RegisterValue[2] = 0;
  }

  /* Gain: '<S4>/Gain' incorporates:
   *  MATLABSystem: '<S4>/FXOS8700 6-Axes Sensor'
   */
  group5_A2finalmodel_B.Gain[0] = (real_T)(int16_T)
    (group5_A2finalmodel_B.b_RegisterValue[0] >> 2) * 2.0 * 0.244 / 1000.0 *
    group5_A2finalmodel_P.Gain_Gain;
  group5_A2finalmodel_B.Gain[1] = (real_T)(int16_T)
    (group5_A2finalmodel_B.b_RegisterValue[1] >> 2) * 2.0 * 0.244 / 1000.0 *
    group5_A2finalmodel_P.Gain_Gain;
  group5_A2finalmodel_B.Gain[2] = (real_T)(int16_T)
    (group5_A2finalmodel_B.b_RegisterValue[2] >> 2) * 2.0 * 0.244 / 1000.0 *
    group5_A2finalmodel_P.Gain_Gain;

  /* Sqrt: '<S4>/Square Root' incorporates:
   *  Math: '<S4>/Square'
   *  Math: '<S4>/Square1'
   *  Math: '<S4>/Square2'
   *  Sum: '<S4>/Add'
   */
  group5_A2finalmodel_B.SquareRoot = sqrt((group5_A2finalmodel_B.Gain[0] *
    group5_A2finalmodel_B.Gain[0] + group5_A2finalmodel_B.Gain[1] *
    group5_A2finalmodel_B.Gain[1]) + group5_A2finalmodel_B.Gain[2] *
    group5_A2finalmodel_B.Gain[2]);

  /* MATLABSystem: '<S4>/Moving Average' */
  if (group5_A2finalmodel_DW.obj.TunablePropsChanged) {
    group5_A2finalmodel_DW.obj.TunablePropsChanged = false;
  }

  obj = group5_A2finalmodel_DW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  group5_A2finalmodel_B.cumRevIndex = obj->pCumRevIndex;
  group5_A2finalmodel_B.csum = obj->pCumSum;
  group5_A2finalmodel_B.Gain[0] = obj->pCumSumRev[0];
  group5_A2finalmodel_B.Gain[1] = obj->pCumSumRev[1];
  group5_A2finalmodel_B.Gain[2] = obj->pCumSumRev[2];
  group5_A2finalmodel_B.modValueRev = obj->pModValueRev;
  group5_A2finalmodel_B.z = 0.0;
  group5_A2finalmodel_B.rtb_MovingAverage_m = 0.0;
  group5_A2finalmodel_B.csum += group5_A2finalmodel_B.SquareRoot;
  if (group5_A2finalmodel_B.modValueRev == 0.0) {
    group5_A2finalmodel_B.z = group5_A2finalmodel_B.Gain[(int32_T)
      group5_A2finalmodel_B.cumRevIndex - 1] + group5_A2finalmodel_B.csum;
  }

  group5_A2finalmodel_B.Gain[(int32_T)group5_A2finalmodel_B.cumRevIndex - 1] =
    group5_A2finalmodel_B.SquareRoot;
  if (group5_A2finalmodel_B.cumRevIndex != 3.0) {
    group5_A2finalmodel_B.cumRevIndex++;
  } else {
    group5_A2finalmodel_B.cumRevIndex = 1.0;
    group5_A2finalmodel_B.csum = 0.0;
    group5_A2finalmodel_B.Gain[1] += group5_A2finalmodel_B.Gain[2];
    group5_A2finalmodel_B.Gain[0] += group5_A2finalmodel_B.Gain[1];
  }

  if (group5_A2finalmodel_B.modValueRev == 0.0) {
    group5_A2finalmodel_B.rtb_MovingAverage_m = group5_A2finalmodel_B.z / 4.0;
  }

  obj->pCumSum = group5_A2finalmodel_B.csum;
  obj->pCumSumRev[0] = group5_A2finalmodel_B.Gain[0];
  obj->pCumSumRev[1] = group5_A2finalmodel_B.Gain[1];
  obj->pCumSumRev[2] = group5_A2finalmodel_B.Gain[2];
  obj->pCumRevIndex = group5_A2finalmodel_B.cumRevIndex;
  if (group5_A2finalmodel_B.modValueRev > 0.0) {
    obj->pModValueRev = group5_A2finalmodel_B.modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* Chart: '<S4>/Chart1' incorporates:
   *  MATLABSystem: '<S4>/Moving Average'
   */
  if (group5_A2finalmodel_DW.is_active_c3_group5_A2finalmode == 0U) {
    group5_A2finalmodel_DW.is_active_c3_group5_A2finalmode = 1U;
    group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
      group5_A2finalmodel_IN_initial1;
    group5_A2finalmodel_DW.Lowest = group5_A2finalmodel_B.URL;
    group5_A2finalmodel_DW.Highest = group5_A2finalmodel_B.LRL;
    group5_A2finalmodel_B.qY = (uint32_T)group5_A2finalmodel_B.LRL -
      /*MW:OvSatOk*/ group5_A2finalmodel_B.URL;
    if (group5_A2finalmodel_B.qY > group5_A2finalmodel_B.LRL) {
      group5_A2finalmodel_B.qY = 0U;
    }

    group5_A2finalmodel_DW.Interval = (uint8_T)rt_roundd_snf((real_T)(int32_T)
      group5_A2finalmodel_B.qY / 4.0);
  } else {
    switch (group5_A2finalmodel_DW.is_c3_group5_A2finalmodel) {
     case group5_A2finalmodel_IN_High1:
      group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
        group5_A2finalmodel_IN_initial1;
      group5_A2finalmodel_DW.Lowest = group5_A2finalmodel_B.URL;
      group5_A2finalmodel_DW.Highest = group5_A2finalmodel_B.LRL;
      group5_A2finalmodel_B.qY = (uint32_T)group5_A2finalmodel_B.LRL -
        /*MW:OvSatOk*/ group5_A2finalmodel_B.URL;
      if (group5_A2finalmodel_B.qY > group5_A2finalmodel_B.LRL) {
        group5_A2finalmodel_B.qY = 0U;
      }

      group5_A2finalmodel_DW.Interval = (uint8_T)rt_roundd_snf((real_T)(int32_T)
        group5_A2finalmodel_B.qY / 4.0);
      break;

     case group5_A2finalmodel_IN_Mid1:
      group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
        group5_A2finalmodel_IN_initial1;
      group5_A2finalmodel_DW.Lowest = group5_A2finalmodel_B.URL;
      group5_A2finalmodel_DW.Highest = group5_A2finalmodel_B.LRL;
      group5_A2finalmodel_B.qY = (uint32_T)group5_A2finalmodel_B.LRL -
        /*MW:OvSatOk*/ group5_A2finalmodel_B.URL;
      if (group5_A2finalmodel_B.qY > group5_A2finalmodel_B.LRL) {
        group5_A2finalmodel_B.qY = 0U;
      }

      group5_A2finalmodel_DW.Interval = (uint8_T)rt_roundd_snf((real_T)(int32_T)
        group5_A2finalmodel_B.qY / 4.0);
      break;

     case group5_A2finalmode_IN_Mid_high1:
      group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
        group5_A2finalmodel_IN_initial1;
      group5_A2finalmodel_DW.Lowest = group5_A2finalmodel_B.URL;
      group5_A2finalmodel_DW.Highest = group5_A2finalmodel_B.LRL;
      group5_A2finalmodel_B.qY = (uint32_T)group5_A2finalmodel_B.LRL -
        /*MW:OvSatOk*/ group5_A2finalmodel_B.URL;
      if (group5_A2finalmodel_B.qY > group5_A2finalmodel_B.LRL) {
        group5_A2finalmodel_B.qY = 0U;
      }

      group5_A2finalmodel_DW.Interval = (uint8_T)rt_roundd_snf((real_T)(int32_T)
        group5_A2finalmodel_B.qY / 4.0);
      break;

     case group5_A2finalmode_IN_Rest_Mid1:
      group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
        group5_A2finalmodel_IN_initial1;
      group5_A2finalmodel_DW.Lowest = group5_A2finalmodel_B.URL;
      group5_A2finalmodel_DW.Highest = group5_A2finalmodel_B.LRL;
      group5_A2finalmodel_B.qY = (uint32_T)group5_A2finalmodel_B.LRL -
        /*MW:OvSatOk*/ group5_A2finalmodel_B.URL;
      if (group5_A2finalmodel_B.qY > group5_A2finalmodel_B.LRL) {
        group5_A2finalmodel_B.qY = 0U;
      }

      group5_A2finalmodel_DW.Interval = (uint8_T)rt_roundd_snf((real_T)(int32_T)
        group5_A2finalmodel_B.qY / 4.0);
      break;

     case group5_A2finalmodel_IN_Resting1:
      group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
        group5_A2finalmodel_IN_initial1;
      group5_A2finalmodel_DW.Lowest = group5_A2finalmodel_B.URL;
      group5_A2finalmodel_DW.Highest = group5_A2finalmodel_B.LRL;
      group5_A2finalmodel_B.qY = (uint32_T)group5_A2finalmodel_B.LRL -
        /*MW:OvSatOk*/ group5_A2finalmodel_B.URL;
      if (group5_A2finalmodel_B.qY > group5_A2finalmodel_B.LRL) {
        group5_A2finalmodel_B.qY = 0U;
      }

      group5_A2finalmodel_DW.Interval = (uint8_T)rt_roundd_snf((real_T)(int32_T)
        group5_A2finalmodel_B.qY / 4.0);
      break;

     default:
      /* case IN_initial1: */
      if (group5_A2finalmodel_B.rtb_MovingAverage_m >= 44.0) {
        group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
          group5_A2finalmodel_IN_High1;
        group5_A2finalmodel_B.SquareRoot = rt_roundd_snf(60000.0 / (real_T)
          group5_A2finalmodel_DW.Highest);
        if (group5_A2finalmodel_B.SquareRoot < 256.0) {
          group5_A2finalmodel_B.rate_period = (uint8_T)
            group5_A2finalmodel_B.SquareRoot;
        } else {
          group5_A2finalmodel_B.rate_period = MAX_uint8_T;
        }
      } else if (group5_A2finalmodel_B.rtb_MovingAverage_m < 11.0) {
        group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
          group5_A2finalmodel_IN_Resting1;
        group5_A2finalmodel_B.SquareRoot = rt_roundd_snf(60000.0 / (real_T)
          group5_A2finalmodel_DW.Lowest);
        if (group5_A2finalmodel_B.SquareRoot < 256.0) {
          group5_A2finalmodel_B.rate_period = (uint8_T)
            group5_A2finalmodel_B.SquareRoot;
        } else {
          group5_A2finalmodel_B.rate_period = MAX_uint8_T;
        }
      } else if ((group5_A2finalmodel_B.rtb_MovingAverage_m >= 11.0) &&
                 (group5_A2finalmodel_B.rtb_MovingAverage_m < 22.0)) {
        group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
          group5_A2finalmode_IN_Rest_Mid1;
        group5_A2finalmodel_B.i = (int32_T)((uint32_T)
          group5_A2finalmodel_DW.Lowest + group5_A2finalmodel_DW.Interval);
        if ((uint32_T)group5_A2finalmodel_B.i > 255U) {
          group5_A2finalmodel_B.i = 255;
        }

        group5_A2finalmodel_B.SquareRoot = rt_roundd_snf(60000.0 / (real_T)
          group5_A2finalmodel_B.i);
        if (group5_A2finalmodel_B.SquareRoot < 256.0) {
          group5_A2finalmodel_B.rate_period = (uint8_T)
            group5_A2finalmodel_B.SquareRoot;
        } else {
          group5_A2finalmodel_B.rate_period = MAX_uint8_T;
        }
      } else if ((group5_A2finalmodel_B.rtb_MovingAverage_m >= 33.0) &&
                 (group5_A2finalmodel_B.rtb_MovingAverage_m < 44.0)) {
        group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
          group5_A2finalmode_IN_Mid_high1;
        group5_A2finalmodel_B.SquareRoot = rt_roundd_snf(60000.0 / (real_T)
          group5_A2finalmodel_DW.Lowest);
        if (group5_A2finalmodel_B.SquareRoot < 256.0) {
          group5_A2finalmodel_B.status = (uint8_T)
            group5_A2finalmodel_B.SquareRoot;
        } else {
          group5_A2finalmodel_B.status = MAX_uint8_T;
        }

        group5_A2finalmodel_B.i = (int32_T)((uint32_T)
          group5_A2finalmodel_B.status + group5_A2finalmodel_DW.Interval);
        if ((uint32_T)group5_A2finalmodel_B.i > 255U) {
          group5_A2finalmodel_B.i = 255;
        }

        group5_A2finalmodel_B.i = (int32_T)((uint32_T)group5_A2finalmodel_B.i +
          group5_A2finalmodel_DW.Interval);
        if ((uint32_T)group5_A2finalmodel_B.i > 255U) {
          group5_A2finalmodel_B.i = 255;
        }

        group5_A2finalmodel_B.i = (int32_T)((uint32_T)group5_A2finalmodel_B.i +
          group5_A2finalmodel_DW.Interval);
        if ((uint32_T)group5_A2finalmodel_B.i > 255U) {
          group5_A2finalmodel_B.i = 255;
        }

        group5_A2finalmodel_B.rate_period = (uint8_T)group5_A2finalmodel_B.i;
      } else if ((group5_A2finalmodel_B.rtb_MovingAverage_m >= 22.0) &&
                 (group5_A2finalmodel_B.rtb_MovingAverage_m < 33.0)) {
        group5_A2finalmodel_DW.is_c3_group5_A2finalmodel =
          group5_A2finalmodel_IN_Mid1;
        group5_A2finalmodel_B.i = (int32_T)((uint32_T)
          group5_A2finalmodel_DW.Lowest + group5_A2finalmodel_DW.Interval);
        if ((uint32_T)group5_A2finalmodel_B.i > 255U) {
          group5_A2finalmodel_B.i = 255;
        }

        group5_A2finalmodel_B.i = (int32_T)((uint32_T)group5_A2finalmodel_B.i +
          group5_A2finalmodel_DW.Interval);
        if ((uint32_T)group5_A2finalmodel_B.i > 255U) {
          group5_A2finalmodel_B.i = 255;
        }

        group5_A2finalmodel_B.SquareRoot = rt_roundd_snf(60000.0 / (real_T)
          group5_A2finalmodel_B.i);
        if (group5_A2finalmodel_B.SquareRoot < 256.0) {
          group5_A2finalmodel_B.rate_period = (uint8_T)
            group5_A2finalmodel_B.SquareRoot;
        } else {
          group5_A2finalmodel_B.rate_period = MAX_uint8_T;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Chart1' */

  /* Product: '<S4>/Divide' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   */
  group5_A2finalmodel_B.SquareRoot = group5_A2finalmodel_P.Constant_Value /
    group5_A2finalmodel_P.Constant1_Value;

  /* MATLABSystem: '<S4>/ATR_CMP_DETECT' */
  if (group5_A2finalmodel_DW.obj_et.SampleTime !=
      group5_A2finalmodel_P.ATR_CMP_DETECT_SampleTime) {
    group5_A2finalmodel_DW.obj_et.SampleTime =
      group5_A2finalmodel_P.ATR_CMP_DETECT_SampleTime;
  }

  group5_A2finalmodel_B.b = MW_digitalIO_read
    (group5_A2finalmodel_DW.obj_et.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S4>/VENT_CMP_DETECT' */
  if (group5_A2finalmodel_DW.obj_m.SampleTime !=
      group5_A2finalmodel_P.VENT_CMP_DETECT_SampleTime) {
    group5_A2finalmodel_DW.obj_m.SampleTime =
      group5_A2finalmodel_P.VENT_CMP_DETECT_SampleTime;
  }

  /* MATLABSystem: '<S4>/VENT_CMP_DETECT' */
  group5_A2finalmodel_B.VENT_CMP_DETECT = MW_digitalIO_read
    (group5_A2finalmodel_DW.obj_m.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<S4>/ATR_CMP_DETECT'
   */
  if (group5_A2finalmodel_DW.temporalCounter_i1 < MAX_uint32_T) {
    group5_A2finalmodel_DW.temporalCounter_i1++;
  }

  if (group5_A2finalmodel_DW.is_active_c2_group5_A2finalmode == 0U) {
    group5_A2finalmodel_DW.is_active_c2_group5_A2finalmode = 1U;
    group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
      group5_A2finalmod_IN_Mode_Start;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (group5_A2finalmodel_DW.is_c2_group5_A2finalmodel) {
     case group5_A2finalmodel_IN_AAI:
      switch (group5_A2finalmodel_DW.is_AAI) {
       case group5_A2finalmodel_IN_ARP_ON:
        group5_A2finalmodel_DW.is_AAI = group5_A2fi_IN_Charging_sensing;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        g_enter_atomic_Charging_sensing();
        break;

       case group5_A2fi_IN_Charging_sensing:
        group5_A2finalmodel_B.FRONTEND_CTRL = 1.0;
        group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
        group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
        group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
        group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
        group5_A2finalmodel_B.ATR_GND_CTRL = 1.0;
        group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
        if ((group5_A2finalmodel_DW.Set_ARP == 1.0) &&
            (group5_A2finalmodel_DW.temporalCounter_i1 >=
             group5_A2finalmodel_B.ARP)) {
          if (group5_A2finalmodel_DW.temporalCounter_i1 >= (real32_T)
              group5_A2finalmodel_B.Period - group5_A2finalmodel_B.ATR_PW) {
            guard1 = true;
          } else if (group5_A2finalmodel_B.b) {
            guard2 = true;
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }
        break;

       case group5_A2finalmodel_IN_INIT:
        group5_A2finalmodel_DW.is_AAI = group5_A2fi_IN_Charging_sensing;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        g_enter_atomic_Charging_sensing();
        break;

       default:
        /* case IN_Pacing: */
        group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
        group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
        group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
        group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
        group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
        group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
        if (group5_A2finalmodel_DW.temporalCounter_i1 >=
            group5_A2finalmodel_B.ATR_PW) {
          group5_A2finalmodel_DW.is_AAI = group5_A2fi_IN_Charging_sensing;
          group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
          g_enter_atomic_Charging_sensing();
        }
        break;
      }
      break;

     case group5_A2finalmodel_IN_AAIR:
      group5_A2finalmodel_AAIR(&group5_A2finalmodel_B.b);
      break;

     case group5_A2finalmodel_IN_AOO:
      if (group5_A2finalmodel_B.mode != 3) {
        group5_A2finalmodel_DW.is_AOO = group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
          group5_A2finalmod_IN_Mode_Start;
      } else if (group5_A2finalmodel_DW.is_AOO ==
                 group5_A2finalmodel_IN_Charging) {
        group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
        group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
        group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
        group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
        group5_A2finalmodel_B.ATR_GND_CTRL = 1.0;
        group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
        if (group5_A2finalmodel_DW.temporalCounter_i1 >= (real32_T)
            group5_A2finalmodel_B.Period - group5_A2finalmodel_B.ATR_PW) {
          group5_A2finalmodel_DW.is_AOO = group5_A2finalmode_IN_Pacing_gm;
          group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
          group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
          group5_A2finalmodel_B.VENT_PACE_CTRL = 0.0;
          group5_A2finalmodel_B.ATR_PACE_CTRL = 1.0;
          group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
        }
      } else {
        /* case IN_Pacing: */
        group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
        group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
        group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
        group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
        group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
        group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
        if (group5_A2finalmodel_DW.temporalCounter_i1 >=
            group5_A2finalmodel_B.ATR_PW) {
          group5_A2finalmodel_DW.is_AOO = group5_A2finalmodel_IN_Charging;
          group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
          group5_A2_enter_atomic_Charging();
        }
      }
      break;

     case group5_A2finalmodel_IN_AOOR:
      group5_A2finalmodel_AOOR();
      break;

     case group5_A2finalmod_IN_Mode_Start:
      if (group5_A2finalmodel_B.mode == 1) {
        group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
          group5_A2finalmodel_IN_VOO;
        group5_A2finalmodel_DW.is_VOO = group5_A2finalmodel_IN_Charging;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_enter_atomic_Charging_ej();
      } else if (group5_A2finalmodel_B.mode == 2) {
        guard3 = true;
      } else if (group5_A2finalmodel_B.mode == 3) {
        group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
          group5_A2finalmodel_IN_AOO;
        group5_A2finalmodel_DW.is_AOO = group5_A2finalmodel_IN_Charging;
        group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
        group5_A2_enter_atomic_Charging();
      } else if (group5_A2finalmodel_B.mode == 4) {
        group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
          group5_A2finalmodel_IN_VVI;
        group5_A2finalmodel_DW.is_VVI = group5_A2finalmodel_IN_INIT_ml;
        group5_A2finalmodel_DW.Set_VRP = 0.0;
      } else if (group5_A2finalmodel_B.mode == 5) {
        group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
          group5_A2finalmodel_IN_AOOR;
        group5_A2finalmodel_DW.is_AOOR = group5_A2finalmodel_IN_Initate;
        group5_A2finalmodel_DW.copy_Period = group5_A2finalmodel_B.Period;
      } else if (group5_A2finalmodel_B.mode == 6) {
        group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
          group5_A2finalmodel_IN_VOOR;
        group5_A2finalmodel_DW.is_VOOR = group5_A2finalmode_IN_Initate_l;
        group5_A2finalmodel_DW.copy_Period = group5_A2finalmodel_B.Period;
      } else if (group5_A2finalmodel_B.mode == 7) {
        group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
          group5_A2finalmodel_IN_AAIR;
        group5_A2finalmodel_DW.is_AAIR = group5_A2finalmodel_IN_INIT_m;
        group5_A2finalmodel_DW.Set_ARP = 0.0;
        group5_A2finalmodel_DW.copy_Period = group5_A2finalmodel_B.Period;
        group5_A2finalmodel_DW.Hys = 0.0;
        group5_A2finalmodel_DW.Hys_delay = group5_A2finalmodel_B.SquareRoot;
        group5_A2finalmodel_DW.Hys_on = 1.0;
      } else if (group5_A2finalmodel_B.mode == 8) {
        group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
          group5_A2finalmodel_IN_VVIR;
        group5_A2finalmodel_DW.is_VVIR = group5_A2finalmodel_IN_INIT1;
        group5_A2finalmodel_DW.Set_VRP = 0.0;
        group5_A2finalmodel_DW.copy_Period = group5_A2finalmodel_B.Period;
        group5_A2finalmodel_DW.Hys = 0.0;
        group5_A2finalmodel_DW.Hys_delay = group5_A2finalmodel_B.SquareRoot;
        group5_A2finalmodel_DW.Hys_on = 0.0;
      } else if (group5_A2finalmodel_B.mode != 2) {
        guard3 = true;
      }
      break;

     case group5_A2finalmodel_IN_VOO:
      if (group5_A2finalmodel_B.mode != 1) {
        group5_A2finalmodel_DW.is_VOO = group5_A2fin_IN_NO_ACTIVE_CHILD;
        group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
          group5_A2finalmod_IN_Mode_Start;
      } else if (group5_A2finalmodel_DW.is_VOO ==
                 group5_A2finalmodel_IN_Charging) {
        group5_A2finalmodel_B.PACE_CHARGE_CTRL = 1.0;
        group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
        group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
        group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
        group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
        group5_A2finalmodel_B.VENT_GND_CTRL = 1.0;
        if (group5_A2finalmodel_DW.temporalCounter_i1 >= (real32_T)
            group5_A2finalmodel_B.Period - group5_A2finalmodel_B.VENT_PW) {
          group5_A2finalmodel_DW.is_VOO = group5_A2finalmo_IN_Discharging;
          group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
          group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
          group5_A2finalmodel_B.ATR_PACE_CTRL = 0.0;
          group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
          group5_A2finalmodel_B.VENT_PACE_CTRL = 1.0;
        }
      } else {
        /* case IN_Discharging: */
        group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
        group5_A2finalmodel_B.PACE_GND_CTRL = 1.0;
        group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
        group5_A2finalmodel_B.Z_VENT_CTRL = 0.0;
        group5_A2finalmodel_B.Z_ATR_CTRL = 0.0;
        group5_A2finalmodel_B.VENT_GND_CTRL = 0.0;
        if (group5_A2finalmodel_DW.temporalCounter_i1 >=
            group5_A2finalmodel_B.VENT_PW) {
          group5_A2finalmodel_DW.is_VOO = group5_A2finalmodel_IN_Charging;
          group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
          group5_enter_atomic_Charging_ej();
        }
      }
      break;

     case group5_A2finalmodel_IN_VOOR:
      group5_A2finalmodel_VOOR();
      break;

     case group5_A2finalmodel_IN_VVI:
      group5_A2finalmodel_VVI(&group5_A2finalmodel_B.VENT_CMP_DETECT);
      break;

     default:
      /* case IN_VVIR: */
      group5_A2finalmodel_VVIR(&group5_A2finalmodel_B.VENT_CMP_DETECT);
      break;
    }

    if (guard4) {
      if (group5_A2finalmodel_DW.Set_ARP == 0.0) {
        if (group5_A2finalmodel_B.b) {
          guard2 = true;
        } else if (group5_A2finalmodel_DW.temporalCounter_i1 >= (real32_T)
                   group5_A2finalmodel_B.Period - group5_A2finalmodel_B.ATR_PW)
        {
          guard1 = true;
        }
      }
    }

    if (guard3) {
      group5_A2finalmodel_DW.is_c2_group5_A2finalmodel =
        group5_A2finalmodel_IN_AAI;
      group5_A2finalmodel_DW.is_AAI = group5_A2finalmodel_IN_INIT;
      group5_A2finalmodel_DW.Set_ARP = 0.0;
    }

    if (guard2) {
      group5_A2finalmodel_DW.is_AAI = group5_A2finalmodel_IN_ARP_ON;
      group5_A2finalmodel_DW.Set_ARP = 1.0;
    }

    if (guard1) {
      group5_A2finalmodel_DW.is_AAI = group5_A2finalmodel_IN_Pacing;
      group5_A2finalmodel_DW.temporalCounter_i1 = 0U;
      group5_A2finalmodel_B.PACE_CHARGE_CTRL = 0.0;
      group5_A2finalmodel_B.VENT_PACE_CTRL = 0.0;
      group5_A2finalmodel_B.ATR_PACE_CTRL = 1.0;
      group5_A2finalmodel_B.ATR_GND_CTRL = 0.0;
      group5_A2finalmodel_DW.Set_ARP = 1.0;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S5>/PACE_CHARGE_CTRL' */
  MW_digitalIO_write(group5_A2finalmodel_DW.obj_jf.MW_DIGITALIO_HANDLE,
                     group5_A2finalmodel_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S5>/VENT_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(group5_A2finalmodel_DW.obj_c.MW_PWM_HANDLE, (real_T)
                      group5_A2finalmodel_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S5>/Z_ATR_CTRL' */
  MW_digitalIO_write(group5_A2finalmodel_DW.obj_p.MW_DIGITALIO_HANDLE,
                     group5_A2finalmodel_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S5>/PACING_REF_PWM' */
  MW_PWM_SetDutyCycle(group5_A2finalmodel_DW.obj_lj.MW_PWM_HANDLE, (real_T)
                      group5_A2finalmodel_B.PACING_REF_PWM);

  /* MATLABSystem: '<S5>/ATR_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(group5_A2finalmodel_DW.obj_a.MW_PWM_HANDLE, (real_T)
                      group5_A2finalmodel_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S5>/Z_VENT_CTRL' */
  MW_digitalIO_write(group5_A2finalmodel_DW.obj_fj.MW_DIGITALIO_HANDLE,
                     group5_A2finalmodel_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S5>/ATR_PACE_CTRL ' */
  MW_digitalIO_write(group5_A2finalmodel_DW.obj_b.MW_DIGITALIO_HANDLE,
                     group5_A2finalmodel_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S5>/VENT_PACE_CTRL' */
  MW_digitalIO_write(group5_A2finalmodel_DW.obj_i.MW_DIGITALIO_HANDLE,
                     group5_A2finalmodel_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S5>/PACE_GND_CTRL ' */
  MW_digitalIO_write(group5_A2finalmodel_DW.obj_h.MW_DIGITALIO_HANDLE,
                     group5_A2finalmodel_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S5>/ATR_GND_CTRL' */
  MW_digitalIO_write(group5_A2finalmodel_DW.obj_iw.MW_DIGITALIO_HANDLE,
                     group5_A2finalmodel_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S5>/VENT_GND_CTRL ' */
  MW_digitalIO_write(group5_A2finalmodel_DW.obj_c1.MW_DIGITALIO_HANDLE,
                     group5_A2finalmodel_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S5>/FRONTEND_CTRL' */
  MW_digitalIO_write(group5_A2finalmodel_DW.obj_k.MW_DIGITALIO_HANDLE,
                     group5_A2finalmodel_B.FRONTEND_CTRL != 0.0);
}

/* Model initialize function */
void group5_A2finalmodel_initialize(void)
{
  {
    freedomk64f_AnalogInput_group_T *obj;
    freedomk64f_DigitalRead_group_T *obj_1;
    freedomk64f_DigitalWrite_grou_T *obj_2;
    freedomk64f_PWMOutput_group5__T *obj_3;
    g_dsp_internal_SlidingWindowA_T *obj_0;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT1' incorporates:
     *  SubSystem: '<Root>/COM_OUT1'
     */
    transmit_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT1' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    group5_A2finalmodel_DW.obj_l.isInitialized = 0;
    group5_A2finalmodel_DW.obj_l.matlabCodegenIsDeleted = false;
    group5_A2finalmodel_DW.obj_l.SampleTime =
      group5_A2finalmodel_P.SerialReceive_SampleTime;
    group5_A2fin_SystemCore_setup_k(&group5_A2finalmodel_DW.obj_l);

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    group5_A2finalmodel_DW.obj_e.matlabCodegenIsDeleted = false;
    group5_A2finalmodel_DW.obj_e.SampleTime =
      group5_A2finalmodel_P.AnalogInput_SampleTime;
    obj = &group5_A2finalmodel_DW.obj_e;
    group5_A2finalmodel_DW.obj_e.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    group5_A2finalmodel_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(group5_A2finalmodel_DW.obj_e.MW_ANALOGIN_HANDLE,
      group5_A2finalmodel_B.trigger_val, 0U);
    group5_A2finalmodel_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    group5_A2finalmodel_DW.obj_f.matlabCodegenIsDeleted = false;
    group5_A2finalmodel_DW.obj_f.SampleTime =
      group5_A2finalmodel_P.AnalogInput1_SampleTime;
    obj = &group5_A2finalmodel_DW.obj_f;
    group5_A2finalmodel_DW.obj_f.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    group5_A2finalmodel_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(group5_A2finalmodel_DW.obj_f.MW_ANALOGIN_HANDLE,
      group5_A2finalmodel_B.trigger_val, 0U);
    group5_A2finalmodel_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/FXOS8700 6-Axes Sensor' */
    group5_A2finalmodel_DW.obj_j.isInitialized = 0;
    group5_A2finalmodel_DW.obj_j.i2cobj.isInitialized = 0;
    group5_A2finalmodel_DW.obj_j.i2cobj.matlabCodegenIsDeleted = false;
    group5_A2finalmodel_DW.obj_j.matlabCodegenIsDeleted = false;
    group5_A2finalmodel_DW.obj_j.SampleTime =
      group5_A2finalmodel_P.FXOS87006AxesSensor_SampleTime;
    group5_A2fi_SystemCore_setup_k2(&group5_A2finalmodel_DW.obj_j);

    /* Start for MATLABSystem: '<S4>/Moving Average' */
    group5_A2finalmodel_DW.obj.isInitialized = 0;
    group5_A2finalmodel_DW.obj.NumChannels = -1;
    group5_A2finalmodel_DW.obj.FrameLength = -1;
    group5_A2finalmodel_DW.obj.matlabCodegenIsDeleted = false;
    group5_A2f_SystemCore_setup_k2c(&group5_A2finalmodel_DW.obj);

    /* InitializeConditions for MATLABSystem: '<S4>/Moving Average' */
    obj_0 = group5_A2finalmodel_DW.obj.pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      obj_0->pCumSumRev[0] = 0.0;
      obj_0->pCumSumRev[1] = 0.0;
      obj_0->pCumSumRev[2] = 0.0;
      obj_0->pCumRevIndex = 1.0;
      obj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S4>/Moving Average' */

    /* Start for MATLABSystem: '<S4>/ATR_CMP_DETECT' */
    group5_A2finalmodel_DW.obj_et.matlabCodegenIsDeleted = false;
    group5_A2finalmodel_DW.obj_et.SampleTime =
      group5_A2finalmodel_P.ATR_CMP_DETECT_SampleTime;
    obj_1 = &group5_A2finalmodel_DW.obj_et;
    group5_A2finalmodel_DW.obj_et.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    group5_A2finalmodel_DW.obj_et.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/VENT_CMP_DETECT' */
    group5_A2finalmodel_DW.obj_m.matlabCodegenIsDeleted = false;
    group5_A2finalmodel_DW.obj_m.SampleTime =
      group5_A2finalmodel_P.VENT_CMP_DETECT_SampleTime;
    obj_1 = &group5_A2finalmodel_DW.obj_m;
    group5_A2finalmodel_DW.obj_m.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    group5_A2finalmodel_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PACE_CHARGE_CTRL' */
    group5_A2finalmodel_DW.obj_jf.matlabCodegenIsDeleted = false;
    obj_2 = &group5_A2finalmodel_DW.obj_jf;
    group5_A2finalmodel_DW.obj_jf.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    group5_A2finalmodel_DW.obj_jf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/VENT_CMP_REF_PWM' */
    group5_A2finalmodel_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_3 = &group5_A2finalmodel_DW.obj_c;
    group5_A2finalmodel_DW.obj_c.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(group5_A2finalmodel_DW.obj_c.MW_PWM_HANDLE);
    group5_A2finalmodel_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Z_ATR_CTRL' */
    group5_A2finalmodel_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_2 = &group5_A2finalmodel_DW.obj_p;
    group5_A2finalmodel_DW.obj_p.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    group5_A2finalmodel_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PACING_REF_PWM' */
    group5_A2finalmodel_DW.obj_lj.matlabCodegenIsDeleted = false;
    obj_3 = &group5_A2finalmodel_DW.obj_lj;
    group5_A2finalmodel_DW.obj_lj.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(group5_A2finalmodel_DW.obj_lj.MW_PWM_HANDLE);
    group5_A2finalmodel_DW.obj_lj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/ATR_CMP_REF_PWM' */
    group5_A2finalmodel_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_3 = &group5_A2finalmodel_DW.obj_a;
    group5_A2finalmodel_DW.obj_a.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(group5_A2finalmodel_DW.obj_a.MW_PWM_HANDLE);
    group5_A2finalmodel_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Z_VENT_CTRL' */
    group5_A2finalmodel_DW.obj_fj.matlabCodegenIsDeleted = false;
    obj_2 = &group5_A2finalmodel_DW.obj_fj;
    group5_A2finalmodel_DW.obj_fj.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    group5_A2finalmodel_DW.obj_fj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/ATR_PACE_CTRL ' */
    group5_A2finalmodel_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_2 = &group5_A2finalmodel_DW.obj_b;
    group5_A2finalmodel_DW.obj_b.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    group5_A2finalmodel_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/VENT_PACE_CTRL' */
    group5_A2finalmodel_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_2 = &group5_A2finalmodel_DW.obj_i;
    group5_A2finalmodel_DW.obj_i.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    group5_A2finalmodel_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PACE_GND_CTRL ' */
    group5_A2finalmodel_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_2 = &group5_A2finalmodel_DW.obj_h;
    group5_A2finalmodel_DW.obj_h.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    group5_A2finalmodel_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/ATR_GND_CTRL' */
    group5_A2finalmodel_DW.obj_iw.matlabCodegenIsDeleted = false;
    obj_2 = &group5_A2finalmodel_DW.obj_iw;
    group5_A2finalmodel_DW.obj_iw.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    group5_A2finalmodel_DW.obj_iw.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/VENT_GND_CTRL ' */
    group5_A2finalmodel_DW.obj_c1.matlabCodegenIsDeleted = false;
    obj_2 = &group5_A2finalmodel_DW.obj_c1;
    group5_A2finalmodel_DW.obj_c1.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    group5_A2finalmodel_DW.obj_c1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/FRONTEND_CTRL' */
    group5_A2finalmodel_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_2 = &group5_A2finalmodel_DW.obj_k;
    group5_A2finalmodel_DW.obj_k.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    group5_A2finalmodel_DW.obj_k.isSetupComplete = true;
  }
}

/* Model terminate function */
void group5_A2finalmodel_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;
  g_dsp_internal_SlidingWindowA_T *obj_0;

  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!group5_A2finalmodel_DW.obj_l.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_l.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_l.isSetupComplete) {
      MW_SCI_Close(group5_A2finalmodel_DW.obj_l.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!group5_A2finalmodel_DW.obj_e.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_e.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_e.isSetupComplete) {
      MW_AnalogIn_Stop(group5_A2finalmodel_DW.obj_e.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(group5_A2finalmodel_DW.obj_e.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!group5_A2finalmodel_DW.obj_f.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_f.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_f.isSetupComplete) {
      MW_AnalogIn_Stop(group5_A2finalmodel_DW.obj_f.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(group5_A2finalmodel_DW.obj_f.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT1' incorporates:
   *  SubSystem: '<Root>/COM_OUT1'
   */
  transmit_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT1' */

  /* Terminate for MATLABSystem: '<S4>/FXOS8700 6-Axes Sensor' */
  if (!group5_A2finalmodel_DW.obj_j.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_j.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_j.isSetupComplete) {
      MW_I2C_Close(group5_A2finalmodel_DW.obj_j.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &group5_A2finalmodel_DW.obj_j.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/FXOS8700 6-Axes Sensor' */

  /* Terminate for MATLABSystem: '<S4>/Moving Average' */
  if (!group5_A2finalmodel_DW.obj.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj.isSetupComplete) {
      obj_0 = group5_A2finalmodel_DW.obj.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      group5_A2finalmodel_DW.obj.NumChannels = -1;
      group5_A2finalmodel_DW.obj.FrameLength = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Moving Average' */

  /* Terminate for MATLABSystem: '<S4>/ATR_CMP_DETECT' */
  if (!group5_A2finalmodel_DW.obj_et.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_et.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_et.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_et.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_et.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/ATR_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S4>/VENT_CMP_DETECT' */
  if (!group5_A2finalmodel_DW.obj_m.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_m.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/VENT_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S5>/PACE_CHARGE_CTRL' */
  if (!group5_A2finalmodel_DW.obj_jf.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_jf.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_jf.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_jf.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_jf.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PACE_CHARGE_CTRL' */

  /* Terminate for MATLABSystem: '<S5>/VENT_CMP_REF_PWM' */
  if (!group5_A2finalmodel_DW.obj_c.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_c.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_c.isSetupComplete) {
      MW_PWM_Stop(group5_A2finalmodel_DW.obj_c.MW_PWM_HANDLE);
      MW_PWM_Close(group5_A2finalmodel_DW.obj_c.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/VENT_CMP_REF_PWM' */

  /* Terminate for MATLABSystem: '<S5>/Z_ATR_CTRL' */
  if (!group5_A2finalmodel_DW.obj_p.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_p.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Z_ATR_CTRL' */

  /* Terminate for MATLABSystem: '<S5>/PACING_REF_PWM' */
  if (!group5_A2finalmodel_DW.obj_lj.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_lj.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_lj.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_lj.isSetupComplete) {
      MW_PWM_Stop(group5_A2finalmodel_DW.obj_lj.MW_PWM_HANDLE);
      MW_PWM_Close(group5_A2finalmodel_DW.obj_lj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PACING_REF_PWM' */

  /* Terminate for MATLABSystem: '<S5>/ATR_CMP_REF_PWM' */
  if (!group5_A2finalmodel_DW.obj_a.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_a.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_a.isSetupComplete) {
      MW_PWM_Stop(group5_A2finalmodel_DW.obj_a.MW_PWM_HANDLE);
      MW_PWM_Close(group5_A2finalmodel_DW.obj_a.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/ATR_CMP_REF_PWM' */

  /* Terminate for MATLABSystem: '<S5>/Z_VENT_CTRL' */
  if (!group5_A2finalmodel_DW.obj_fj.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_fj.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_fj.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_fj.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_fj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Z_VENT_CTRL' */

  /* Terminate for MATLABSystem: '<S5>/ATR_PACE_CTRL ' */
  if (!group5_A2finalmodel_DW.obj_b.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_b.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/ATR_PACE_CTRL ' */

  /* Terminate for MATLABSystem: '<S5>/VENT_PACE_CTRL' */
  if (!group5_A2finalmodel_DW.obj_i.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_i.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/VENT_PACE_CTRL' */

  /* Terminate for MATLABSystem: '<S5>/PACE_GND_CTRL ' */
  if (!group5_A2finalmodel_DW.obj_h.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_h.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PACE_GND_CTRL ' */

  /* Terminate for MATLABSystem: '<S5>/ATR_GND_CTRL' */
  if (!group5_A2finalmodel_DW.obj_iw.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_iw.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_iw.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_iw.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_iw.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/ATR_GND_CTRL' */

  /* Terminate for MATLABSystem: '<S5>/VENT_GND_CTRL ' */
  if (!group5_A2finalmodel_DW.obj_c1.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_c1.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_c1.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_c1.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_c1.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/VENT_GND_CTRL ' */

  /* Terminate for MATLABSystem: '<S5>/FRONTEND_CTRL' */
  if (!group5_A2finalmodel_DW.obj_k.matlabCodegenIsDeleted) {
    group5_A2finalmodel_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((group5_A2finalmodel_DW.obj_k.isInitialized == 1) &&
        group5_A2finalmodel_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(group5_A2finalmodel_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/FRONTEND_CTRL' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
