#include "framework.h"

#include "str/str.h"
#include "utest/utest.h"
#include "init_gpio/init_gpio.h"
#include "init_usart/init_usart.h"

void test_runner() {
	RUN_TEST_GROUP(ioapi);
//	RUN_TEST_GROUP(utest);
//	RUN_TEST_GROUP(str);
}

int main() {
	sysclk_init();
	
	init_gpio();
	init_usart();

	utest_main(&test_runner);
	
	while(1);
}