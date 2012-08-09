#include "framework.h"
#include "asf.h"

#include "init_mcu/init_mcu.h"

#define INITD_CPU_F 	48000000UL
#define INITD_PBA_F		48000000UL
#define INITD_PBB_F		48000000UL

/* This must be bigger than any other clocks, DFLL loop
 * is used to  * generate rest of frequencies. */
#define INITD_DFLL_F	48000000UL

void init_mcu( void) {

	/* Set required changes for flash wait state and readmode */
	flashcdw_set_flash_waitstate_and_readmode(INITD_CPU_F);

	/* We will use Atmel power_clocks_lib to configure clocks in MCU. This library supports
	 * high level of abstraction straction over settings. */
	static scif_gclk_opt_t gc_dfllif_ref_opt = { SCIF_GCCTRL_SLOWCLOCK, 0, false };
	static pcl_freq_param_t pcl_dfll_freq_param =
		{
		.main_clk_src = PCL_MC_DFLL0,
		.cpu_f        = INITD_CPU_F,
		.pba_f        = INITD_PBA_F,
		.pbb_f        = INITD_PBB_F,
		.dfll_f       = INITD_DFLL_F,
		.pextra_params = &gc_dfllif_ref_opt
		};

	/* Configure core clocks (MCU, PBA, PBB, DFFL */
	pcl_configure_clocks(&pcl_dfll_freq_param);
}