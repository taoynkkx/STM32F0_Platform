#include "xio_cfg.h"
#include "xprintf/inc/xio.h"
#include "../msp/msp.h"

void xio_cfg_putc(char c)
{
  msp_xioSend(c);
}
