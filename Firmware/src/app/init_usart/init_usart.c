#include "framework.h"
#include "init_usart/init_usart.h"
#include "asf.h"


#define INITD_USART_POINTER 	(&AVR32_USART0)

#define INITD_USART_BAUDRATE	9600
#define INITD_USART_CHARLENGTH	8
#define INITD_USART_PARITYPE	USART_NO_PARITY
#define INITD_USART_STOPBITS	USART_2_STOPBITS
#define INITD_USART_CHANNELMODE USART_NORMAL_CHMODE

void init_usart( void) {
	const usart_options_t usart_settings = {
		.baudrate = INITD_USART_BAUDRATE,
		.charlength = INITD_USART_CHARLENGTH,
		.paritytype = INITD_USART_PARITYPE,
		.stopbits = INITD_USART_STOPBITS,
		.channelmode = INITD_USART_CHANNELMODE,
	};

	usart_init_rs232(INITD_USART_POINTER, &usart_settings, 48000000UL);
}