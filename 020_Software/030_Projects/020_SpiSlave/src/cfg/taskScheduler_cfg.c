#include "taskScheduler/inc/taskScheduler.h"
#include "taskScheduler_cfg.h"

#include "xprintf/inc/xio.h"

#include "../msp/mDIO.h"
#include "../msp/msp.h"
#include "../msp/mSPI.h"

extern unsigned long tick;

void task_128ms(void)
{
  mDIO_setDigitalOutput(DO_PB12, DO_CMD_TOGGLE);
  xprintf("%d\t7\n", tick);
  mSPI_masterSendByteBlocking(0x55);
  mSPI_masterSendByteBlocking(tick);
  mSPI_masterSendByteBlocking(0xAA);
}

void task_256ms(void)
{
  mDIO_setDigitalOutput(DO_PB13, DO_CMD_TOGGLE);
  xprintf("%d\t\t8\n", tick);
}

void task_512ms(void)
{
  mDIO_setDigitalOutput(DO_PB14, DO_CMD_TOGGLE);
  xprintf("%d\t\t\t9\n", tick);
}

void task_1024ms(void)
{
  mDIO_setDigitalOutput(DO_PB15, DO_CMD_TOGGLE);
  xprintf("%d\t\t\t\tA\n", tick);
}

