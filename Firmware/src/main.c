#include "framework.h"

#include "str/str.h"
#include "utest/utest.h"
#include "init_mcu/init_mcu.h"
#include "init_gpio/init_gpio.h"
#include "init_usart/init_usart.h"

void test_runner() {
	//RUN_TEST_GROUP(ioapi);
	RUN_TEST_GROUP(utest);
}

int main() {
	init_mcu();
	init_gpio();
	init_usart();

	utest_main(&test_runner);
}