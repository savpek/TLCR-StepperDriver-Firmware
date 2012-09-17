#include "framework.h"
#include "config/conf_drivers.h"
#include "config/conf_gpio.h"

static statusc_t is_last_config(uint8_t i) {
	if(	conf_gpio_settings[i].is_last == SC_TRUE)
		{
		return SC_TRUE;
		}
	return SC_FALSE;
}

/*! Settings for PWMA module. 
 * If dision is enabled, PWM freq is
 * CPU_CLK/Division factor. Remember that actual frequency
 * of PWM signal is (CPU_FREG/DIVISION_F)/PERIOD! */
#define MOTOR_PWMA_ENABLE_CLK_DIV 1
#define MOTOR_PWMA_DIVISION_FACTOR 7

#define PWMA_MAX_VALUE 255
void init_gpio( void) 
{
	struct genclk_config gcfg;
		
	genclk_config_defaults(&gcfg, AVR32_PM_GCLK_GCLK3);
	genclk_config_set_source(&gcfg, 5);
	genclk_config_set_divider(&gcfg, 2);
	genclk_enable(&gcfg, AVR32_PM_GCLK_GCLK3);
		
	for(int i = 0; !is_last_config(i); i++)
	{
		switch (conf_gpio_settings[i].mode)
		{
			case INIT_AS_GPIO:
				gpio_configure_pin(conf_gpio_settings[i].pin, conf_gpio_settings[i].function);
				gpio_enable_module_pin(conf_gpio_settings[i].pin, conf_gpio_settings[i].function);
				break;
			case INIT_AS_PWM:
				pwma_config_and_enable(&AVR32_PWMA, (1 << conf_gpio_settings[i].channel), 127, 50);
				gpio_enable_module_pin(conf_gpio_settings[i].pin, conf_gpio_settings[i].function);
				break;
		}		
		ASSERT(i > 100); // This means loop is out of hand for sure!
	}	
}

