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

// Pin should be safe to set output, input, adc etc without danger to brake HW up!
#define SAFE_PIN AVR32_PIN_PA19

TEST(ioapi, test_ioapi_output_high) {
	gpio_configure_pin(SAFE_PIN, GPIO_DIR_OUTPUT);
	ioapi_output_high(SAFE_PIN);
	TEST_ASSERT(ioapi_is_pin_output(SAFE_PIN));
}

TEST(ioapi, test_ioapi_output_low) 
{
	gpio_configure_pin(SAFE_PIN, GPIO_DIR_OUTPUT);
	ioapi_output_low(SAFE_PIN);
	TEST_ASSERT(ioapi_is_pin_output(SAFE_PIN));
}

TEST(ioapi, test_ioapi_input_value) 
{
	/* Cannot truly test this functionality, because register values
	 * depends HW. */
	gpio_configure_pin(SAFE_PIN, GPIO_DIR_INPUT);
	TEST_ASSERT(ioapi_is_pin_input(SAFE_PIN));
}

TEST(ioapi, test_ioapi_is_pin_output) 
{
	gpio_configure_pin(SAFE_PIN, GPIO_DIR_OUTPUT);
	TEST_ASSERT(ioapi_is_pin_output(SAFE_PIN));
	
	gpio_configure_pin(SAFE_PIN, GPIO_DIR_INPUT);
	TEST_ASSERT(!ioapi_is_pin_output(SAFE_PIN));
}

TEST(ioapi, test_ioapi_is_pin_input) 
{
	gpio_configure_pin(SAFE_PIN, GPIO_DIR_OUTPUT);
	TEST_ASSERT(!ioapi_is_pin_input(SAFE_PIN));
	
	gpio_configure_pin(SAFE_PIN, GPIO_DIR_INPUT);
	TEST_ASSERT(ioapi_is_pin_input(SAFE_PIN));
}

TEST_GROUP_RUNNER(ioapi) 
{
	RUN_TEST_CASE(ioapi, test_ioapi_output_high);
	RUN_TEST_CASE(ioapi, test_ioapi_output_low);
	RUN_TEST_CASE(ioapi, test_ioapi_input_value);
	RUN_TEST_CASE(ioapi, test_ioapi_is_pin_output)
	RUN_TEST_CASE(ioapi, test_ioapi_is_pin_input)
}