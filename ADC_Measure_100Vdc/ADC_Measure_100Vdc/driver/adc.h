/***********************************************************************************************************************
* DISCLAIMER
*
* Copyright (C) Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : adc.h
* Version      : v1.0 [08 Aug 2020]
* Device(s)    : ATtiny104-SSFR
* Tool-Chain   : GNU C99 (AVR_8_bit_GNU_Toolchain_3.6.2_1778) version 5.4.0 (avr)
* Description  : This file implements device driver for ADC module.
* Creation Date: 08/08/2020
***********************************************************************************************************************/




#ifndef ADC_H_
#define ADC_H_





/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Analog input channel specification register (ADC Multiplexer Selection Register) 
*/
/* Specification of analog input channel */
#define _00_ADMUX_INPUT_CHANNEL_0                      (0x00U) /* ADC0 */
#define _01_ADMUX_INPUT_CHANNEL_1                      (0x01U) /* ADC1 */
#define _02_ADMUX_INPUT_CHANNEL_2                      (0x02U) /* ADC2 */
#define _03_ADMUX_INPUT_CHANNEL_3                      (0x03U) /* ADC3 */
#define _04_ADMUX_INPUT_CHANNEL_4                      (0x04U) /* ADC4 */
#define _05_ADMUX_INPUT_CHANNEL_5                      (0x05U) /* ADC5 */
#define _06_ADMUX_INPUT_CHANNEL_6                      (0x06U) /* ADC6 */
#define _07_ADMUX_INPUT_CHANNEL_7                      (0x07U) /* ADC7 */

#define _00_AD_INPUT_AVCCREFVOLT						(0x00U) /* internal reference voltage output is used to be the input channel */


/* A/D conversion operation control (ADCSRA) */
#define _00_AD_ENABLE									(0x40U) /* enables ADC */
#define _80_AD_ENABLE									(0x40U) /* disable ADC */
#define _00_AD_CONVERSION_DISABLE						(0x00U) /* stops conversion operation */
#define _40_AD_CONVERSION_ENABLE						(0x40U) /* enables conversion operation */


/* A/D conversion mode control (ADCSRB)*/
#define _00_AD_MODE_FREERUN								(0x00U) /* Free Running mode */
#define _01_AD_MODE_AC									(0x01U) /* Analog Comparator */
#define _02_AD_MODE_EIR0								(0x02U) /* External Interrupt Request 0 */
#define _03_AD_MODE_TC0CMA								(0x03U) /* Timer/Counter 0 Compare Match A */
#define _04_AD_MODE_TOV0								(0x04U) /* Timer/Counter 0 Overflow */
#define _05_AD_MODE_TC0CMB								(0x05U) /* Timer/Counter 0 Compare Match B */
#define _06_AD_MODE_PCI0R								(0x06U) /* Pin Change Interrupt 0 Request */
#define _07_AD_MODE_TC0CE								(0x07U) /* Timer/Counter 0 Capture Event */


/* A/D conversion clock selection (ADPS2,ADPS1,ADPS0) */
#define _07_AD_CONVERSION_CLOCK_128						(0x07U) /* fCLK/128 */
#define _06_AD_CONVERSION_CLOCK_64						(0x06U) /* fCLK/64 */
#define _05_AD_CONVERSION_CLOCK_32						(0x05U) /* fCLK/32 */
#define _04_AD_CONVERSION_CLOCK_16						(0x04U) /* fCLK/16 */
#define _03_AD_CONVERSION_CLOCK_8						(0x03U) /* fCLK/8 */
#define _02_AD_CONVERSION_CLOCK_4						(0x02U) /* fCLK/4 */
#define _01_AD_CONVERSION_CLOCK_2						(0x01U) /* fCLK/2 */
#define _00_AD_CONVERSION_CLOCK_2						(0x00U) /* fCLK/2 */


/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void AdcInit(void);
void AdcStop(void);
uint16_t AdcGetResult();

#endif /* ADC_H_ */