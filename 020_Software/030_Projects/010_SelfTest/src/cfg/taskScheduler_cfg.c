#include "taskScheduler/inc/taskScheduler.h"
#include "taskScheduler_cfg.h"

#include "../msp/mDIO.h"

void task_128ms(void)
{
  mDIO_setDigitalOutput(DO_PB12, DO_CMD_TOGGLE);
}

void task_256ms(void)
{
  mDIO_setDigitalOutput(DO_PB13, DO_CMD_TOGGLE);
}

void task_512ms(void)
{
  mDIO_setDigitalOutput(DO_PB14, DO_CMD_TOGGLE);
}

void task_1024ms(void)
{
  mDIO_setDigitalOutput(DO_PB15, DO_CMD_TOGGLE);
}

