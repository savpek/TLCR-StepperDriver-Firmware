#include "framework.h"

/*! @def FUNCTION, CONFIG and ALIAS for PA00 */
#define INITD_GPIO_PA00_FUNCTION	AVR32_USART0_TXD_0_FUNCTION
//#define INITD_GPIO_PA00_CONFIG
#define IOPIN_USART0_TXD			AVR32_PIN_PA00

/*! @def FUNCTION and ALIAS for PA01 */
#define INITD_GPIO_PA01_FUNCTION	AVR32_USART0_RXD_0_FUNCTION
//#define INITD_GPIO_PA01_CONFIG
#define IOPIN_USART0_RXD			AVR32_PIN_PA01

#define CONFIG_PIN(pin_name) \
gpio_configure_pin(	AVR32_PIN_##pin_name, INITD_GPIO_##pin_name##_CONFIG )

#define FUNCTION_PIN(pin_name) \
gpio_enable_module_pin(	AVR32_PIN_##pin_name,	INITD_GPIO_##pin_name##_FUNCTION)

void init_gpio( void) {
	/* For some reason, you should not configure certain pins after they have set function.
	 * For example, USART TX stop working if you do so... */
	#ifdef INITD_GPIO_PA00_FUNCTION
		FUNCTION_PIN(PA00);
		#ifdef INITD_GPIO_PA00_CONFIG
			CONFIG_PIN(PA00);
		#endif
	#endif

	#ifdef INITD_GPIO_PA01_FUNCTION
		FUNCTION_PIN(PA01);
		#ifdef INITD_GPIO_PA01_CONFIG
			CONFIG_PIN(PA01);
		#endif
	#endif
}