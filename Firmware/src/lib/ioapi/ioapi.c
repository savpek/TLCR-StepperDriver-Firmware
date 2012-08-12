#include "framework.h"
#include "gpio.h"
#include "./ioapi/ioapi.h"

static uint8_t get_port_idx(uint8_t pin) {
	/* This because AVR32 port has 32 pins. */
	return pin>>5;
}

static uint32_t get_pin_bit_in_port(uint8_t pin) {
	return (1<<(pin & 0x1F));
}

static uint8_t is_register_set(uint32_t register_value, uint8_t pin) {
	return ((register_value & get_pin_bit_in_port(pin)) != 0 );
}

static statusc_t is_pin_in_gpio_mode(volatile avr32_gpio_port_t *gpio_port, uint8_t pin_number) 
{
	if(is_register_set(gpio_port->gper, pin_number))
		return true;
	return false;
}

uint32_t ioapi_get_pin_info( const uint8_t pin_number ) {
	volatile avr32_gpio_port_t *gpio_port = &AVR32_GPIO.port[get_port_idx(pin_number)];
	uint32_t return_flags = 0;

	if(is_register_set(gpio_port->gper, pin_number)) {
		return_flags |= IOAPI_GPIO_USED;
	}
	else {
		return_flags |= IOAPI_PERIPHEAL_USED;
	}

	if(is_register_set(gpio_port->oder, pin_number)) {
		return_flags |= IOAPI_OUTPUT;
	}
	else {
		return_flags |= IOAPI_INPUT;
	}

	if(is_register_set(gpio_port->ovr, pin_number)) {
		return_flags |= IOAPI_OUT_HIGH;
	}
	else {
		return_flags |= IOAPI_OUT_LOW;
	}

	if(is_register_set(gpio_port->puer, pin_number)) {
		return_flags |= 0x03;
	}

	return return_flags;
}

static inline void assert_if_not_output( uint8_t pin_number) 
{
	ASSERT( (ioapi_get_pin_info(pin_number) & IOAPI_GPIO_USED) != 0 );
	ASSERT( (ioapi_get_pin_info(pin_number) & IOAPI_OUTPUT ) != 0);
}

void ioapi_output_high_body( uint8_t pin_number )
{
	gpio_set_pin_high(pin_number);
	assert_if_not_output(pin_number);
}
void (*ioapi_output_high)(uint8_t) = ioapi_output_high_body;

void ioapi_output_low_body( uint8_t pin_number )
{
	gpio_set_pin_low(pin_number);
	assert_if_not_output(pin_number);
}
void (*ioapi_output_low)(uint8_t) = ioapi_output_low_body;

statusc_t ioapi_input_value_body( uint8_t pin_number )
{
	if(gpio_get_pin_value(pin_number) == 0)
		return SC_LOW;
	return SC_HIGH;
}
statusc_t (*ioapi_input_value)(uint8_t) = ioapi_input_value_body;

statusc_t ioapi_is_pin_output( uint8_t pin_number )
{
	volatile avr32_gpio_port_t *gpio_port = &AVR32_GPIO.port[get_port_idx(pin_number)];
	
	if(	is_pin_in_gpio_mode(gpio_port, pin_number) &&
		is_register_set(gpio_port->oder, pin_number))
	{
		return SC_TRUE;
	}
	return SC_FALSE;
}

statusc_t ioapi_is_pin_input( uint8_t pin_number)
{
	volatile avr32_gpio_port_t *gpio_port = &AVR32_GPIO.port[get_port_idx(pin_number)];
	
	if(	is_pin_in_gpio_mode(gpio_port, pin_number) &&
		!is_register_set(gpio_port->oder, pin_number))
	{
		return SC_TRUE;
	}
	return SC_FALSE;
}