/***********************************************************************************************************************
* DISCLAIMER
*
* Copyright (C) Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : main.c
* Version      : 1.00
* Device(s)    : ATTINY104
* Tool-Chain   : GNU C99 (AVR_8_bit_GNU_Toolchain_3.6.2_1778) version 5.4.0 (avr)
* OS           : None
* H/W Platform : ATTINY104 DC Voltage Meter Platform
* Description  : Main
* Operation    : Main processing
* Limitations  : None
******************************************************************************
* History : DD.MM.YYYY Version Description
***********************************************************************************************************************/





/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <wrp_em_adc.h>
#include <wrp_uart.h>


/******************************************************************************
* Function Name: int main(void)
* Description  : Main processing
* Arguments    : none
* Return Value : 1
******************************************************************************/
int main(void)
{
	cli();						// Clear all interrupt before module setup
	EM_ADC_Start();				// Start adc module
	WRP_UART_Start();			// Start Uart module
	sei();						// Set Interrupt gain if any module require
	
    /* Main application code */
    while (1) 
    {
		WRP_UART_SendData(WRP_MeasuredVoltage());
		_delay_ms(3000);
    }
	
	return 1;
}



