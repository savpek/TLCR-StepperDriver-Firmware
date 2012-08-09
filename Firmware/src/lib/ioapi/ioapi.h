#ifndef IOAPI_H_
#define IOAPI_H_

#include "framework.h"

extern void (*ioapi_output_high)( uint8_t pin_number);
extern void (*ioapi_output_low)( uint8_t pin_number );
extern statusc_t (*ioapi_input_value)( uint8_t pin_number );
extern void ioapi_output_pwm( uint8_t pin_number, uint32_t pwm_percent );
extern uint32_t ioapi_input_adc( uint8_t pin_number );

extern statusc_t ioapi_is_it_output( uint8_t pin_number);
extern statusc_t ioapi_is_it_input( uint8_t pin_number);
extern statusc_t ioapi_is_it_pwm( uint8_t pin_number);
extern statusc_t ioapi_is_it_adc( uint8_t pin_number);

typedef enum {
	IOAPI_OUTPUT =		0x01,
	IOAPI_INPUT  =		0x02,
	IOAPI_GPIO_USED =	0x04,
	IOAPI_PERIPHEAL_USED = 0x08,
	IOAPI_OUT_HIGH = 0x10,
	IOAPI_OUT_LOW  = 0x20,
	IOAPI_INPUT_HIGH  = 0x40,
	IOAPI_INPUT_LOW	  = 0x80,
	IOAPI_PULL_UP	  = 0x100
} ioapi_pin_status_t;

#endif /* IOAPI_H_ */