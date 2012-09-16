#include "framework.h"

#include "str/str.h"
#include "utest/utest.h"
#include "init_mcu/init_mcu.h"
#include "init_gpio/init_gpio.h"
#include "init_usart/init_usart.h"

void test_runner() {
	RUN_TEST_GROUP(ioapi);
//	RUN_TEST_GROUP(utest);
//	RUN_TEST_GROUP(str);
}

int main() {
	init_mcu();
	
	struct genclk_config gcfg;
	
	genclk_config_defaults(&gcfg, AVR32_PM_GCLK_GCLK3);
	genclk_config_set_source(&gcfg, 5);
	genclk_config_set_divider(&gcfg, 2);
	genclk_enable(&gcfg, AVR32_PM_GCLK_GCLK3);
	
	init_gpio();
	init_usart();

	utest_main(&test_runner);
	//pwma_set_channels_value( &AVR32_PWMA, (1<<28), 50);
	
	usart_putchar(CONF_USART_POINTER, 'a');
	while(1);
}