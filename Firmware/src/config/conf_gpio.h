#ifndef CONF_GPIO_H_
#define CONF_GPIO_H_

#define END_OF_ARRAY NULL
#define CHANNEL_NOT_DEFINED ~0

typedef enum 
{
	INIT_AS_GPIO,
	INIT_AS_ADC,
	INIT_AS_PWM,
} conf_gpio_modes;

typedef struct 
{
	uint8_t pin;
	uint8_t function;
	uint8_t channel;	// Set this if adc or pwm	// .
	conf_gpio_modes mode;
} conf_gpio_t;

extern const conf_gpio_t conf_gpio_settings[];

// Define PIN Aliases here.
#define PIN_USART_TXD		AVR32_PIN_PA00
#define PIN_USART_RXD		AVR32_PIN_PA01
#define PIN_PWM_TEST		AVR32_PIN_PB05

#endif /* CONF_GPIO_H_ */