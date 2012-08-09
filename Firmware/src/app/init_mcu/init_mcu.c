#include "framework.h"
#include "asf.h"

#include "init_mcu/init_mcu.h"

void init_mcu( void) {

	/* Set required changes for flash wait state and readmode */
	flashcdw_set_flash_waitstate_and_readmode(CONF_CPU_F);

	/* We will use Atmel power_clocks_lib to configure clocks in MCU. This library supports
	 * high level of abstraction straction over settings. */
	static scif_gclk_opt_t gc_dfllif_ref_opt = { SCIF_GCCTRL_SLOWCLOCK, 0, false };
	static pcl_freq_param_t pcl_dfll_freq_param =
		{
		.main_clk_src = PCL_MC_DFLL0,
		.cpu_f        = CONF_CPU_F,
		.pba_f        = CONF_PBA_F,
		.pbb_f        = CONF_PBB_F,
		.dfll_f       = CONF_DFLL_F,
		.pextra_params = &gc_dfllif_ref_opt
		};

	/* Configure core clocks (MCU, PBA, PBB, DFFL */
	pcl_configure_clocks(&pcl_dfll_freq_param);
}