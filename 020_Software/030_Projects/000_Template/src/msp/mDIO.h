#ifndef  __MDIO_H
#define  __MDIO_H

typedef enum
{
  DO_PB12,
  DO_PB13,
  DO_PB14,
  DO_PB15,

  DO_MAX,
}
E_DO_CHANNEL;

typedef enum
{
  DO_CMD_LOW,
  DO_CMD_HIGH,
  DO_CMD_TOGGLE,
}
E_DO_COMMAND;

extern void mDIO_init(void);

extern void mDIO_setDigitalOutput(E_DO_CHANNEL ch, E_DO_COMMAND cmd);

#endif // __MDIO_H
