#include "framework.h"
#include "ioapi/ioapi.h"
#include "gpio.h"

TEST_GROUP(ioapi);

TEST_SETUP(ioapi) 
{
}

TEST_TEAR_DOWN(ioapi) 
{
}

TEST(ioapi, test_ioapi_output_high) {
	gpio_configure_pin(AVR32_PIN_PA19, GPIO_DIR_OUTPUT);
	ioapi_output_high(AVR32_PIN_PA19);
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_GPIO_USED );
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_OUTPUT);
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_OUT_HIGH);
}

TEST(ioapi, test_ioapi_output_low) 
{
	gpio_configure_pin(AVR32_PIN_PA19, GPIO_DIR_OUTPUT);
	ioapi_output_low(AVR32_PIN_PA19);
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_GPIO_USED );
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_OUTPUT );
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_OUT_LOW );
}

TEST(ioapi, test_ioapi_input_value) 
{
	/* Cannot truly test this functionality, because register values
	 * depends HW. */
	gpio_configure_pin(AVR32_PIN_PA19, GPIO_DIR_INPUT);
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_GPIO_USED );
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_INPUT);
}

TEST(ioapi, test_ioapi_get_pin_info) 
{
	gpio_configure_pin(AVR32_PIN_PA19, GPIO_DIR_OUTPUT);
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_GPIO_USED );
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_OUTPUT );

	gpio_configure_pin(AVR32_PIN_PA19, GPIO_DIR_INPUT);
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & IOAPI_INPUT );

	gpio_configure_pin(AVR32_PIN_PA19, GPIO_DIR_INPUT|GPIO_PULL_UP );
	TEST_ASSERT(ioapi_get_pin_info(AVR32_PIN_PA19) & 0x03 );
}

TEST(ioapi, test_ioapi_is_pin_output) 
{
	gpio_configure_pin(AVR32_PIN_PA19, GPIO_DIR_OUTPUT);
	TEST_ASSERT(ioapi_is_pin_output(AVR32_PIN_PA19));
	
	gpio_configure_pin(AVR32_PIN_PA19, GPIO_DIR_INPUT);
	TEST_ASSERT(!ioapi_is_pin_output(AVR32_PIN_PA19));
}

TEST_GROUP_RUNNER(ioapi) 
{
	RUN_TEST_CASE(ioapi, test_ioapi_get_pin_info);
	RUN_TEST_CASE(ioapi, test_ioapi_output_high);
	RUN_TEST_CASE(ioapi, test_ioapi_output_low);
	RUN_TEST_CASE(ioapi, test_ioapi_input_value);
	RUN_TEST_CASE(ioapi, test_ioapi_is_pin_output)
}