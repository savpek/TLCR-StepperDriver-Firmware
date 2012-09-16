#include "framework.h"
#include "config/conf_gpio.h"

const conf_gpio_t conf_gpio_settings[] =
{
	{
		.pin = PIN_USART_TXD,				
		.function = AVR32_USART0_TXD_0_FUNCTION,
		.channel = CHANNEL_NOT_DEFINED,			
		.mode = INIT_AS_GPIO,
		.is_last = SC_FALSE,
	},
	{
		.pin = PIN_USART_RXD,						
		.function = AVR32_USART0_RXD_0_FUNCTION,
		.channel = CHANNEL_NOT_DEFINED,				
		.mode = INIT_AS_GPIO,					
		.is_last = SC_FALSE,
	},
	{
		.pin = AVR32_PWMA_28_PIN,						
		.function = AVR32_PWMA_28_FUNCTION,				
		.channel = 28,							
		.mode = INIT_AS_PWM,
		.is_last = SC_FALSE,
	},
	{
		.is_last = SC_TRUE
	}
};