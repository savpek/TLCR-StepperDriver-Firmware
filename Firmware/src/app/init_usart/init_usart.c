#include "framework.h"
#include "init_usart/init_usart.h"
#include "asf.h"

void init_usart( void) {
	const usart_options_t usart_settings = {
		.baudrate = CONF_USART_BAUDRATE,
		.charlength = CONF_USART_CHARLENGTH,
		.paritytype = CONF_USART_PARITYPE,
		.stopbits = CONF_USART_STOPBITS,
		.channelmode = CONF_USART_CHANNELMODE,
	};

	usart_init_rs232(CONF_USART_POINTER, &usart_settings, CONF_PBA_F);
}