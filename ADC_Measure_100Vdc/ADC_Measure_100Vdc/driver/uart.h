/***********************************************************************************************************************
* DISCLAIMER
*
* Copyright (C) Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : uart.h
* Version      : v1.0 [08 Aug 2020]
* Device(s)    : ATtiny104-SSFR
* Tool-Chain   : GNU C99 (AVR_8_bit_GNU_Toolchain_3.6.2_1778) version 5.4.0 (avr)
* Description  : This file implements device driver for uart module.
* Creation Date: 08/08/2020
***********************************************************************************************************************/ 





#ifndef UART_H_
#define UART_H_


/******************************************************************************
Macro definitions
******************************************************************************/
/* BAUDRATE specifications for UART */
#define _23_UART_BAUD_0									(23) 

/* Enable Uart RX, TX lines */
#define _18_UART_RX										(0x18U)

/* Uart Frame format */
#define _00_UART_ASYNC_MODE								(0x00U)
#define _00_UART_PARITY_NONE							(0x00U)
#define _00_UART_STOP_BIT								(0x00U)
#define _06_UART_DATA_SIZE								(0x06U)

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void UartStart();
void UartStop();
void UartSendData(uint8_t data);


#endif /* UART_H_ */