#include "mSPI.h"
#include "stm32f0xx.h"

void mSPI_masterInit(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  SPI_InitTypeDef  SPI_InitStructure;

  /* reset SPI */  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
  SPI_I2S_DeInit(SPI1);

  /* config GPIOs */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_0);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_0);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_0);
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure the SPI interrupt priority */
  NVIC_InitStructure.NVIC_IRQChannel = SPI1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  /* SPI configuration -------------------------------------------------------*/
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low; // SPI_CPOL_High
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; // SPI_CPHA_2Edge
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_Init(SPI1, &SPI_InitStructure);
  
  /* Initialize the FIFO threshold */
  SPI_RxFIFOThresholdConfig(SPI1, SPI_RxFIFOThreshold_QF);
  
  /* Enable the Rx buffer not empty interrupt */
//  SPI_I2S_ITConfig(SPI1, SPI_I2S_IT_RXNE, ENABLE);
  /* Enable the SPI Error interrupt */
//  SPI_I2S_ITConfig(SPI1, SPI_I2S_IT_ERR, ENABLE);
  /* Data transfer is performed in the SPI interrupt routine */
  
  /* Enable the SPI peripheral */
  SPI_Cmd(SPI1, ENABLE);
}

void mSPI_masterSendByteBlocking(unsigned char data)
{
  while( SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE)==RESET );
  SPI_SendData8(SPI1,data);
}

