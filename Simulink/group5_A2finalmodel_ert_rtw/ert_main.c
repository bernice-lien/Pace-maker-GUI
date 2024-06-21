/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "group5_A2finalmodel_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "board.h"
#include "mw_cmsis_rtos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
mw_signal_event_t stopSem;
mw_signal_event_t baserateTaskSem;
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(group5_A2finalmodel_M) == (NULL));
  while (runModel) {
    mw_osSignalEventWaitEver(&baserateTaskSem);
    group5_A2finalmodel_step();

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(group5_A2finalmodel_M) == (NULL)));
  }

  runModel = 0;
  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(group5_A2finalmodel_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Terminate model */
  group5_A2finalmodel_terminate();
  mw_osSignalEventRelease(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  SystemCoreClockUpdate();
  hardware_init();
  rtmSetErrorStatus(group5_A2finalmodel_M, 0);

  /* Initialize model */
  group5_A2finalmodel_initialize();

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.001, 0);

  /* Wait for stop semaphore */
  mw_osSignalEventWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSignalEventDelete(&timerTaskSem[i]), 0,
                   "mw_osSignalEventDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
