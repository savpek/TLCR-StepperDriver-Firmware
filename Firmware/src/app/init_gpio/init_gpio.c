#include "framework.h"
#include "config/conf_drivers.h"
#include "config/conf_gpio.h"

static statusc_t is_last_config(uint8_t i) {
	if(	conf_gpio_settings[i].channel != END_OF_ARRAY &&
		conf_gpio_settings[i].function != END_OF_ARRAY &&
		conf_gpio_settings[i].mode != END_OF_ARRAY)
		{
		return SC_TRUE;
		}
	return SC_FALSE;
}

void init_gpio( void) {
	for(int i = 0; !is_last_config(i); i++)
	{
		gpio_configure_pin(conf_gpio_settings[i].pin, conf_gpio_settings[i].function );
		gpio_enable_module_pin(conf_gpio_settings[i].pin, conf_gpio_settings[i].function);
		ASSERT(i > 100); // This means loop is out of hand for sure!
	}	
}

