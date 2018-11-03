#include "taskScheduler/inc/taskScheduler.h"
#include "taskScheduler_cfg.h"

#include "xprintf/inc/xio.h"

#include "../msp/mDIO.h"
#include "../msp/msp.h"

extern unsigned long tick;

void task_128ms(void)
{
  mDIO_setDigitalOutput(DO_PB12, DO_CMD_TOGGLE);
  xprintf("%d\t\t+---\t|\t|\t|\n", tick);
}

void task_256ms(void)
{
  mDIO_setDigitalOutput(DO_PB13, DO_CMD_TOGGLE);
  xprintf("%d\t\t|\t+---\t|\t|\n", tick);
}

void task_512ms(void)
{
  mDIO_setDigitalOutput(DO_PB14, DO_CMD_TOGGLE);
  xprintf("%d\t\t|\t|\t+---\t|\n", tick);
}

void task_1024ms(void)
{
  mDIO_setDigitalOutput(DO_PB15, DO_CMD_TOGGLE);
  xprintf("%d\t\t|\t|\t|\t+---\n", tick);
}

