#include "taskScheduler/inc/taskScheduler.h"
#include "taskScheduler_cfg.h"

#include "xprintf/inc/xio.h"

#include "../msp/mDIO.h"
#include "../msp/msp.h"
#include "../msp/mSPI.h"

extern unsigned long tick;

void task_init(void)
{
#ifdef SPI_MASTER
  mSPI_masterInit();
#else
  mSPI_slaveInit();
#endif
}

void task_idle(void)
{
#ifndef SPI_MASTER
  mSPI_slaveReceiveByte();
#endif
}

void task_2ms(void)
{
  extern int spiRxWaiting;
  if( spiRxWaiting>0 ) spiRxWaiting--;
}

void task_128ms(void)
{
  mDIO_setDigitalOutput(DO_PB12, DO_CMD_TOGGLE);
  xprintf("%d\t7\n", tick);
#ifdef SPI_MASTER
  mSPI_masterSendByteBlocking(0xAA);
//  mSPI_masterSendByteBlocking(0xCC);
//  mSPI_masterSendByteBlocking(0xF0);
//  mSPI_masterSendByteBlocking(tick);
#endif
}

void task_256ms(void)
{
  mDIO_setDigitalOutput(DO_PB13, DO_CMD_TOGGLE);
  xprintf("%d\t\t8\n", tick);
}

void task_512ms(void)
{
//  mDIO_setDigitalOutput(DO_PB14, DO_CMD_TOGGLE);
  xprintf("%d\t\t\t9\n", tick);
}

void task_1024ms(void)
{
//  mDIO_setDigitalOutput(DO_PB15, DO_CMD_TOGGLE);
  xprintf("%d\t\t\t\tA\n", tick);
}

