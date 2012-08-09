#include "framework.h"
#include "config/conf_drivers.h"

#define CONFIG_PIN(pin_name) \
gpio_configure_pin(	AVR32_PIN_##pin_name, CONF_GPIO_##pin_name##_CONFIG )

#define FUNCTION_PIN(pin_name) \
gpio_enable_module_pin(	AVR32_PIN_##pin_name,	CONF_GPIO_##pin_name##_FUNCTION)

void init_gpio( void) {
	/* For some reason, you should not configure certain pins after they have set function.
	 * For example, USART TX stop working if you do so... */
	#ifdef CONF_GPIO_PA00_FUNCTION
		FUNCTION_PIN(PA00);
		#ifdef INITD_GPIO_PA00_CONFIG
			CONFIG_PIN(PA00);
		#endif
	#endif

	#ifdef CONF_GPIO_PA01_FUNCTION
		FUNCTION_PIN(PA01);
		#ifdef INITD_GPIO_PA01_CONFIG
			CONFIG_PIN(PA01);
		#endif
	#endif
}