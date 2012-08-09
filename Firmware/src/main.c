#include "framework.h"

#include "init_mcu/init_mcu.h"
#include "init_gpio/init_gpio.h"
#include "init_usart/init_usart.h"

int main() {
	init_mcu();
	init_usart();
	init_gpio();
	
	while(1) {
		usart_putchar((&AVR32_USART0), 'a');
	}
}