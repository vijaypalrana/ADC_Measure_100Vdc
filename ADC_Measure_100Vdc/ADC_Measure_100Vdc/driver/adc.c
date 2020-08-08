/***********************************************************************************************************************
* DISCLAIMER
*
* Copyright (C) Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : adc.c
* Version      : v1.0 [08 Aug 2020]
* Device(s)    : ATtiny104-SSFR
* Tool-Chain   : GNU C99 (AVR_8_bit_GNU_Toolchain_3.6.2_1778) version 5.4.0 (avr)
* Description  : This file implements device driver for ADC module.
* Creation Date: 08/08/2020
***********************************************************************************************************************/




/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/


#include <avr/io.h>
#include <util/delay.h>
#include <adc.h>


/******************************************************************************
Private global variables and functions
******************************************************************************/

/***********************************************************************************************************************
* Function Name: AdcInit
* Description  : This function starts the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void AdcInit(void)
{
	/* Turn on voltage reference as AVCC and select channel ADC4 (PB0). */
	ADMUX |= _00_AD_INPUT_AVCCREFVOLT | _04_ADMUX_INPUT_CHANNEL_4;
	
	/* Set prescaler to 32 (115.2 khz) */
	ADCSRA |= _05_AD_CONVERSION_CLOCK_32 | _80_AD_ENABLE;
	
}

/***********************************************************************************************************************
* Function Name: AdcStop
* Description  : This function stop the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void AdcStop(void)
{
	ADCSRA |=  _80_AD_ENABLE;
}


/***********************************************************************************************************************
* Function Name: AdcGetResult
* Description  : This function returns the conversion result in 10-bit range.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
uint16_t AdcGetResult()
{
	/*Start Conversion*/
	ADCSRA |= _40_AD_CONVERSION_ENABLE;
	
	/* Wait for conversion*/
	//_delay_ms(1);
	
	/*ADSC stays 1 as long as conversion is going on*/
	while  (ADCSRA & (_40_AD_CONVERSION_ENABLE));
	
	uint16_t adcVal = (ADCH << 8) | ADCL;
	/*Return Value*/
	return(adcVal);
}