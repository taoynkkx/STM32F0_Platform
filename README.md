# STM32F0 Platform

This project begins with designing a simple development board with the chip STM32F072C8T6.

## The platform hardware will include the following peripherals

- 4 buttons: BOOT0, RESET, WAKEUP1, WAKEUP2
- 2 potentiometers (@ ADC_IN8/9)
- 2 crystals: 12MHz, 32.768KHz
- Cell battery
- SPI Flash (W25Q128 @ SPI1)
- EEPROM (AT24C256 @ IIC1)
- USB-UART converter (PL2303 @ USART1)
- LIN transceiver (TJA1020 @ USART2)
- RS485 transceiver (SP485 @ USART3)
- CAN transceiver (TJA1050 @ CAN)
- USB connector ( @ DP+DM)
- SW debug ports (SWDIO+SWCLK)
- some LEDs
- not used PINs will be left with connectors

## With these the following features can supported

- STLink connection: SWDIO, SWCLK, RESET
- FlashLoaderDemo: RESET, BOOT0, USART1 or USB(DP+DM)
- Low power mode: WAKEUP1, WAKEUP2
- RTC: cell battery, 32.768KHz crystal
- Backup: cell battery
- USB device.

### Software is going to port all interesting examples from the official library examples, as the first step.
