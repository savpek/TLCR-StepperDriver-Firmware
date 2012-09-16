#include "framework.h"
#include "asf.h"
#include "config/conf_drivers.h"
#include "config/conf_gpio.h"

static void init_clocks_for_pwma()
{
	struct genclk_config gcfg;	
	genclk_config_defaults(&gcfg, AVR32_PM_GCLK_GCLK3);
	genclk_config_set_source(&gcfg, GENCLK_SRC_CLK_CPU);
	genclk_config_set_divider(&gcfg, 2);
	genclk_enable(&gcfg, AVR32_PM_GCLK_GCLK3);
}

void init_gpio( void) 
{
	init_clocks_for_pwma();
	
	for(int i = 0; !conf_gpio_settings[i].is_last; i++)
	{
		switch (conf_gpio_settings[i].mode)
		{
			case INIT_AS_GPIO:
				gpio_configure_pin(conf_gpio_settings[i].pin, conf_gpio_settings[i].function);
				gpio_enable_module_pin(conf_gpio_settings[i].pin, conf_gpio_settings[i].function);
				break;
			case INIT_AS_PWM:
				pwma_config_and_enable(&AVR32_PWMA, (1 << conf_gpio_settings[i].channel), PWMA_MAX_VALUE, 0);
				gpio_enable_module_pin(conf_gpio_settings[i].pin, conf_gpio_settings[i].function);
				break;
			case INIT_AS_ADC:
				break;
		}		
		ASSERT(i > 100); // This means loop is out of hand for sure!
	}	
}

