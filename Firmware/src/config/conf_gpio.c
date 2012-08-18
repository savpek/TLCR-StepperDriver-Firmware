/*
 * conf_gpio.c
 *
 * Created: 13.8.2012 20:28:41
 *  Author: savpek
 */ 

#include "framework.h"
#include "config/conf_gpio.h"

const conf_gpio_t conf_gpio_settings[] =
{
	{
		PIN_USART_TXD,						// PIN
		AVR32_USART0_TXD_0_FUNCTION,		// FUNCTION
		CHANNEL_NOT_DEFINED,				// CHANNEL	
		INIT_AS_GPIO						// MODE
	},
	{
		PIN_USART_RXD,						// PIN
		AVR32_USART0_RXD_0_FUNCTION,		// FUNCTION
		CHANNEL_NOT_DEFINED,				// CHANNEL
		INIT_AS_GPIO						// MODE
	},
	{
		END_OF_ARRAY,
		END_OF_ARRAY,
		END_OF_ARRAY,
		INIT_AS_GPIO
	}
};