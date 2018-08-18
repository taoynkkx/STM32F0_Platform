#include "mDIO.h"
#include "stm32f0xx_gpio.h"

typedef struct
{
  GPIO_TypeDef * GPIOx;
  unsigned short GPIO_Pin;
}
T_DO_DESC;

const T_DO_DESC  mDIO_doDesc[4] = 
{
  { GPIOB, GPIO_Pin_12 },
  { GPIOB, GPIO_Pin_13 },
  { GPIOB, GPIO_Pin_14 },
  { GPIOB, GPIO_Pin_15 },
};

void mDIO_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* GPIOB Periph clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

  /* Configure PB12~PB15 as output low */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_ResetBits(GPIOB, GPIO_InitStructure.GPIO_Pin);
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void mDIO_setDigitalOutput(E_DO_CHANNEL ch, E_DO_COMMAND cmd)
{
  if( ch<DO_MAX )
  {
    unsigned char i = (unsigned char)ch;
	GPIO_TypeDef * GPIOx = mDIO_doDesc[i].GPIOx;
	unsigned short Pin = mDIO_doDesc[i].GPIO_Pin;
	switch(cmd)
	{
	  case DO_CMD_LOW:
	    GPIOx->BRR = Pin;
	    break;
	  case DO_CMD_HIGH:
	    GPIOx->BSRR = Pin;
		break;
	  case DO_CMD_TOGGLE:
	    GPIOx->ODR ^= Pin;
		break;
	  default:
	    break;
	}
  }
}
