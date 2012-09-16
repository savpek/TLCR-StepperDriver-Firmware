#include "framework.h"
#include "config/conf_gpio.h"

const conf_gpio_t conf_gpio_settings[] =
{
	{
		PIN_USART_TXD,						// PIN
		AVR32_USART0_TXD_0_FUNCTION,		// FUNCTION
		CHANNEL_NOT_DEFINED,				// CHANNEL	
		INIT_AS_GPIO,						// MODE
		SC_FALSE,
	},
	{
		PIN_USART_RXD,						// PIN
		AVR32_USART0_RXD_0_FUNCTION,		// FUNCTION
		CHANNEL_NOT_DEFINED,				// CHANNEL
		INIT_AS_GPIO,						// MODE
		SC_FALSE,
	},
	{
		AVR32_PWMA_28_PIN,					// PIN
		AVR32_PWMA_28_FUNCTION,				// FUNCTION
		28,									// CHANNEL
		INIT_AS_PWM,						// MODE
		SC_FALSE,
	},
	{
		END_OF_ARRAY,
		END_OF_ARRAY,
		END_OF_ARRAY,
		INIT_AS_GPIO,
		SC_TRUE
	}
};