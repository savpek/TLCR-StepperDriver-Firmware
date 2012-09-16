#include "framework.h"
#include "config/conf_gpio.h"

const conf_gpio_t conf_gpio_settings[] =
{
	{
		.pin = PIN_USART_TXD,						// PIN
		.function = AVR32_USART0_TXD_0_FUNCTION,		// FUNCTION
		.channel = CHANNEL_NOT_DEFINED,				// CHANNEL	
		.mode = INIT_AS_GPIO,						// MODE
		.is_last = SC_FALSE,
	},
	{
		.pin = PIN_USART_RXD,						// PIN
		.function = AVR32_USART0_RXD_0_FUNCTION,		// FUNCTION
		.channel = CHANNEL_NOT_DEFINED,				// CHANNEL
		.mode = INIT_AS_GPIO,						// MODE
		.is_last = SC_FALSE,
	},
	{
		.pin = AVR32_PWMA_28_PIN,					// PIN
		.function = AVR32_PWMA_28_FUNCTION,				// FUNCTION
		.channel = 28,									// CHANNEL
		.mode = INIT_AS_PWM,						// MODE
		.is_last = SC_FALSE,
	},
	{
		.is_last = SC_TRUE
	}
};