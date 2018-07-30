/**
  ******************************************************************************
  * @file    xio.h
  * @author  taoynkkx@github.com
  * @version V1.0
  * @date    2018.7.28
  * @brief   text io
  ******************************************************************************
  * @history
  *
  *
  ******************************************************************************
  */

#ifndef  __XIO_H
#define  __XIO_H

#include "xio_cfg.h"

extern void xputc (char c);
extern void xputs (const char* str);
extern void xprintf (const char* fmt, ...);
extern void xsprintf (char* buff, const char* fmt, ...);

#ifndef xio_cfg_putc
extern void xio_cfg_putc(char c);
#endif

#endif  //  __XIO_H
