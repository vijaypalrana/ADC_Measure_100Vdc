/***********************************************************************************************************************
* DISCLAIMER
*
* Copyright (C) Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : wrp_adc.c
* Version      : v1.0 [08 Aug 2020]
* Device(s)    : ATtiny104-SSFR
* Tool-Chain   : GNU C99 (AVR_8_bit_GNU_Toolchain_3.6.2_1778) version 5.4.0 (avr)
* Description  : ADC wrapper layer source File
* Creation Date: 08/08/2020
***********************************************************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/

#include <avr/io.h>
#include <adc.h>



/******************************************************************************
Macro definitions
******************************************************************************/

#define _MAX_INPUT_VOLTS						100
#define _VOLTAGE_DIVIDER_R1						5.49
#define _VOLTAGE_DIVIDER_R2						105

#define _10BIT_RESOLUTION						1024
#define _AVCC_REFERENCE							5
#define _STEP_SIZE								(_AVCC_REFERENCE/_10BIT_RESOLUTION)


/******************************************************************************
Private global variables and functions
******************************************************************************/
uint8_t WRP_MeasuredVoltage()
{
	/* Calculate voltage at lower resistor R2 */
	uint16_t vout = AdcGetResult() * _STEP_SIZE;
	
	/* Calculate Battery voltage from R2 vout */																
	uint8_t BatteryVoltage = (uint8_t)(vout * ((_VOLTAGE_DIVIDER_R1 + _VOLTAGE_DIVIDER_R2)/_VOLTAGE_DIVIDER_R2));
	
	/* return battery voltage */
	return BatteryVoltage;
	
}