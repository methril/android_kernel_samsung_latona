/*
 * Copyright (C) 2009-2010 Texas Instruments Inc.
 * Mikkel Christensen <mlc@ti.com>
 * Felipe Balbi <balbi@ti.com>
 *
<<<<<<< HEAD
 * Modified from mach-omap2/board-ldp.c
=======
 * Modified from mach-omap2/board-zoom.c for Samsung Latona board
 *
 * Dheeraj CVR "dhiru1602" <cvr.dheeraj@gmail.com>
 * Aditya Patange aka "Adi_Pat" <adithemagnficent@gmail.com> 
>>>>>>> dhiru1602_cm-10.1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/gpio.h>
#include <linux/i2c/twl.h>
<<<<<<< HEAD
#include <linux/mtd/nand.h>
=======
>>>>>>> dhiru1602_cm-10.1
#include <linux/memblock.h>
#include <linux/skbuff.h>
#include <linux/ti_wilink_st.h>
#include <linux/wl12xx.h>

<<<<<<< HEAD
#include <asm/mach-types.h>
#include <asm/mach/arch.h>

=======
#include <asm/setup.h>
#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <asm/sizes.h>
>>>>>>> dhiru1602_cm-10.1
#include <plat/common.h>
#include <plat/board.h>
#include <plat/usb.h>

<<<<<<< HEAD
#include <mach/board-zoom.h>

#include "board-flash.h"
#include "mux.h"
#include "sdram-micron-mt46h32m32lf-6.h"
#include "sdram-hynix-h8mbx00u0mer-0em.h"
#include "omap_ion.h"

#define ZOOM3_EHCI_RESET_GPIO		64
#define ZOOM3_McBSP3_BT_GPIO            164
#define ZOOM3_BT_RESET_GPIO             109
#define ZOOM3_WIFI_PMENA_GPIO		157
#define ZOOM3_WIFI_IRQ_GPIO		162

#define WILINK_UART_DEV_NAME            "/dev/ttyO1"

static void __init omap_zoom_init_early(void)
{
	omap2_init_common_infrastructure();
	if (machine_is_omap_zoom2())
		omap2_init_common_devices(mt46h32m32lf6_sdrc_params,
					  mt46h32m32lf6_sdrc_params);
	else if (machine_is_omap_zoom3())
		omap2_init_common_devices(h8mbx00u0mer0em_sdrc_params,
					  h8mbx00u0mer0em_sdrc_params);
}

#ifdef CONFIG_OMAP_MUX
static struct omap_board_mux board_mux[] __initdata = {
	/* WLAN IRQ - GPIO 162 */
	OMAP3_MUX(MCBSP1_CLKX, OMAP_MUX_MODE4 | OMAP_PIN_INPUT),
	/* WLAN POWER ENABLE - GPIO 101 */
	OMAP3_MUX(CAM_D2, OMAP_MUX_MODE4 | OMAP_PIN_OUTPUT),
	/* WLAN SDIO: MMC3 CMD */
	OMAP3_MUX(MCSPI1_CS1, OMAP_MUX_MODE3 | OMAP_PIN_INPUT_PULLUP),
	/* WLAN SDIO: MMC3 CLK */
	OMAP3_MUX(ETK_CLK, OMAP_MUX_MODE2 | OMAP_PIN_INPUT_PULLUP),
	/* WLAN SDIO: MMC3 DAT[0-3] */
	OMAP3_MUX(ETK_D3, OMAP_MUX_MODE2 | OMAP_PIN_INPUT_PULLUP),
	OMAP3_MUX(ETK_D4, OMAP_MUX_MODE2 | OMAP_PIN_INPUT_PULLUP),
	OMAP3_MUX(ETK_D5, OMAP_MUX_MODE2 | OMAP_PIN_INPUT_PULLUP),
	OMAP3_MUX(ETK_D6, OMAP_MUX_MODE2 | OMAP_PIN_INPUT_PULLUP),
	{ .reg_offset = OMAP_MUX_TERMINATOR },
};
#endif

static struct mtd_partition zoom_nand_partitions[] = {
	/* All the partition sizes are listed in terms of NAND block size */
	{
		.name		= "X-Loader-NAND",
		.offset		= 0,
		.size		= 4 * (64 * 2048),	/* 512KB, 0x80000 */
		.mask_flags	= MTD_WRITEABLE,	/* force read-only */
	},
	{
		.name		= "U-Boot-NAND",
		.offset		= MTDPART_OFS_APPEND,	/* Offset = 0x80000 */
		.size		= 10 * (64 * 2048),	/* 1.25MB, 0x140000 */
		.mask_flags	= MTD_WRITEABLE,	/* force read-only */
	},
	{
		.name		= "Boot Env-NAND",
		.offset		= MTDPART_OFS_APPEND,   /* Offset = 0x1c0000 */
		.size		= 2 * (64 * 2048),	/* 256KB, 0x40000 */
	},
	{
		.name		= "Kernel-NAND",
		.offset		= MTDPART_OFS_APPEND,	/* Offset = 0x0200000*/
		.size		= 240 * (64 * 2048),	/* 30M, 0x1E00000 */
	},
	{
		.name		= "system",
		.offset		= MTDPART_OFS_APPEND,	/* Offset = 0x2000000 */
		.size		= 1760 * (64 * 2048),	/* 220M, 0xDC00000 */
	},
	{
		.name		= "userdata",
		.offset		= MTDPART_OFS_APPEND,	/* Offset = 0x1C000000*/
		.size		= 512 * (64 * 2048),	/* 64M, 0x4000000 */
	},
	{
		.name		= "cache",
		.offset		= MTDPART_OFS_APPEND,	/* Offset = 0x1E000000*/
		.size		= 256 * (64 * 2048),	/* 32M, 0x2000000 */
	},
};
=======
#include <mach/board-latona.h>

#include "board-flash.h"
#include "mux.h"
#include "pm.h"
#include "sdram-qimonda-hyb18m512160af-6.h"
#include "omap_ion.h"
#include "omap_ram_console.h"
#include "control.h"

#define WILINK_UART_DEV_NAME            "/dev/ttyS1"

#ifdef CONFIG_OMAP_RAM_CONSOLE
#define LATONA_RAM_CONSOLE_START  PLAT_PHYS_OFFSET + 0xE000000
#define LATONA_RAM_CONSOLE_SIZE    SZ_1M
#endif

#ifdef CONFIG_OMAP_MUX
extern struct omap_board_mux *latona_board_mux_ptr;
extern struct omap_board_mux *latona_board_wk_mux_ptr;
#else
#define latona_board_mux_ptr		NULL
#define latona_board_wk_mux_ptr		NULL
#endif

static void __init latona_init_early(void)
{
	omap2_init_common_infrastructure();
	omap2_init_common_devices(hyb18m512160af6_sdrc_params,
					  hyb18m512160af6_sdrc_params);
}
>>>>>>> dhiru1602_cm-10.1

static const struct usbhs_omap_board_data usbhs_bdata __initconst = {
	.port_mode[0]		= OMAP_USBHS_PORT_MODE_UNUSED,
	.port_mode[1]		= OMAP_EHCI_PORT_MODE_PHY,
	.port_mode[2]		= OMAP_USBHS_PORT_MODE_UNUSED,
	.phy_reset		= true,
	.reset_gpio_port[0]	= -EINVAL,
<<<<<<< HEAD
	.reset_gpio_port[1]	= ZOOM3_EHCI_RESET_GPIO,
=======
	.reset_gpio_port[1]	= 64,
>>>>>>> dhiru1602_cm-10.1
	.reset_gpio_port[2]	= -EINVAL,
};

static int plat_kim_suspend(struct platform_device *pdev, pm_message_t state)
{
	/* TODO: wait for HCI-LL sleep */
	return 0;
}
static int plat_kim_resume(struct platform_device *pdev)
{
	return 0;
}

/* wl127x BT, FM, GPS connectivity chip */
struct ti_st_plat_data wilink_pdata = {
<<<<<<< HEAD
	.nshutdown_gpio = 109,
	.dev_name = WILINK_UART_DEV_NAME,
	.flow_cntrl = 1,
	.baud_rate = 3686400,
=======
	.nshutdown_gpio = OMAP_GPIO_BT_NRST,
	.dev_name = WILINK_UART_DEV_NAME,
	.flow_cntrl = 1,
	.baud_rate = 3000000,
>>>>>>> dhiru1602_cm-10.1
	.suspend = plat_kim_suspend,
	.resume = plat_kim_resume,
};
static struct platform_device wl127x_device = {
	.name           = "kim",
	.id             = -1,
	.dev.platform_data = &wilink_pdata,
};
static struct platform_device btwilink_device = {
	.name = "btwilink",
	.id = -1,
};

<<<<<<< HEAD
static struct platform_device *zoom_devices[] __initdata = {
=======
static struct platform_device *latona_devices[] __initdata = {
>>>>>>> dhiru1602_cm-10.1
	&wl127x_device,
	&btwilink_device,
};

/* Fix to prevent VIO leakage on wl127x */
static int wl127x_vio_leakage_fix(void)
{
	int ret = 0;

	pr_info(" wl127x_vio_leakage_fix\n");

<<<<<<< HEAD
	ret = gpio_request(ZOOM3_BT_RESET_GPIO, "wl127x_bten");
	if (ret < 0) {
		pr_err("wl127x_bten gpio_%d request fail",
			ZOOM3_BT_RESET_GPIO);
		goto fail;
	}

	gpio_direction_output(ZOOM3_BT_RESET_GPIO, 1);
	mdelay(10);
	gpio_direction_output(ZOOM3_BT_RESET_GPIO, 0);
	udelay(64);

	gpio_free(ZOOM3_BT_RESET_GPIO);
=======
	ret = gpio_request(OMAP_GPIO_BT_NRST, "wl127x_bten");
	if (ret < 0) {
		pr_err("wl127x_bten gpio_%d request fail",
			OMAP_GPIO_BT_NRST);
		goto fail;
	}

	gpio_direction_output(OMAP_GPIO_BT_NRST, 1);
	mdelay(10);
	gpio_direction_output(OMAP_GPIO_BT_NRST, 0);
	udelay(64);

	gpio_free(OMAP_GPIO_BT_NRST);
>>>>>>> dhiru1602_cm-10.1
fail:
	return ret;
}

<<<<<<< HEAD
static void config_wlan_mux(void)
{
	/* WLAN PW_EN and IRQ */
	omap_mux_init_gpio(ZOOM3_WIFI_PMENA_GPIO, OMAP_PIN_OUTPUT);
	omap_mux_init_gpio(ZOOM3_WIFI_IRQ_GPIO, OMAP_PIN_INPUT |
				OMAP_PIN_OFF_WAKEUPENABLE);

	/* MMC3 */
	omap_mux_init_signal("etk_clk.sdmmc3_clk", OMAP_PIN_INPUT_PULLUP);
	omap_mux_init_signal("mcspi1_cs1.sdmmc3_cmd", OMAP_PIN_INPUT_PULLUP);
	omap_mux_init_signal("etk_d4.sdmmc3_dat0", OMAP_PIN_INPUT_PULLUP);
	omap_mux_init_signal("etk_d5.sdmmc3_dat1", OMAP_PIN_INPUT_PULLUP);
	omap_mux_init_signal("etk_d6.sdmmc3_dat2", OMAP_PIN_INPUT_PULLUP);
	omap_mux_init_signal("etk_d3.sdmmc3_dat3", OMAP_PIN_INPUT_PULLUP);
}

static struct wl12xx_platform_data zoom3_wlan_data __initdata = {
	.irq = OMAP_GPIO_IRQ(ZOOM3_WIFI_IRQ_GPIO),
	.board_ref_clock = WL12XX_REFCLOCK_26,
	.board_tcxo_clock = WL12XX_TCXOCLOCK_26,
};

static void zoom3_wifi_init(void)
{
	config_wlan_mux();
	if (wl12xx_set_platform_data(&zoom3_wlan_data))
		pr_err("Error setting wl12xx data\n");
}

static void __init omap_zoom_init(void)
{
	if (machine_is_omap_zoom2()) {
		omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
	} else if (machine_is_omap_zoom3()) {
		omap3_mux_init(board_mux, OMAP_PACKAGE_CBP);
		omap_mux_init_gpio(ZOOM3_EHCI_RESET_GPIO, OMAP_PIN_OUTPUT);
		omap_mux_init_gpio(ZOOM3_McBSP3_BT_GPIO, OMAP_PIN_OUTPUT);
		usbhs_init(&usbhs_bdata);
	}

	board_nand_init(zoom_nand_partitions, ARRAY_SIZE(zoom_nand_partitions),
						ZOOM_NAND_CS, NAND_BUSWIDTH_16);
	zoom3_wifi_init();
	zoom_debugboard_init();
	zoom_peripherals_init();
	zoom_display_init();
	omap_register_ion();
	/* Added to register zoom devices */
	platform_add_devices(zoom_devices, ARRAY_SIZE(zoom_devices));
	wl127x_vio_leakage_fix();
}

static void __init zoom_reserve(void)
{
=======
static struct wl12xx_platform_data latona_wlan_data __initdata = {
	.irq = OMAP_GPIO_IRQ(LATONA_WIFI_IRQ_GPIO),
	.board_ref_clock = WL12XX_REFCLOCK_38,
};

static void latona_wifi_init(void)
{
	if (wl12xx_set_platform_data(&latona_wlan_data))
		pr_err("Error setting wl12xx data\n");
}

#define GPIO_MSECURE_PIN_ON_HS		1	//TI Patch: MSECURE Pin mode change

static int __init msecure_init(void)
{
	int ret = 0;

	//printk("*****msecure_init++\n"); //TI Patch: MSECURE Pin mode change
#ifdef CONFIG_RTC_DRV_TWL4030
	/* 3430ES2.0 doesn't have msecure/gpio-22 line connected to T2 */
	if (omap_type() == OMAP2_DEVICE_TYPE_GP || GPIO_MSECURE_PIN_ON_HS)  //TI Patch: MSECURE Pin mode change
	{
		void __iomem *msecure_pad_config_reg =
		    omap_ctrl_base_get() + 0x5EC;
		int mux_mask = 0x04;
		u16 tmp;

		printk("msecure_pin setting: GPIO  %d, %d\n", omap_type(), GPIO_MSECURE_PIN_ON_HS); //TI Patch: MSECURE Pin mode change

		ret = gpio_request(OMAP_GPIO_SYS_DRM_MSECURE, "msecure");
		if (ret < 0) {
			printk(KERN_ERR "msecure_init: can't"
			       "reserve GPIO:%d !\n",
			       OMAP_GPIO_SYS_DRM_MSECURE);
			goto out;
		}
		/*
		 * TWL4030 will be in secure mode if msecure line from OMAP
		 * is low. Make msecure line high in order to change the
		 * TWL4030 RTC time and calender registers.
		 */
		tmp = __raw_readw(msecure_pad_config_reg);
		tmp &= 0xF8;	/* To enable mux mode 03/04 = GPIO_RTC */
		tmp |= mux_mask;	/* To enable mux mode 03/04 = GPIO_RTC */
		__raw_writew(tmp, msecure_pad_config_reg);

		gpio_direction_output(OMAP_GPIO_SYS_DRM_MSECURE, 1);
	}
out:	
	//printk("*****msecure_init--\n"); //TI Patch: MSECURE Pin mode change
#endif

	return ret;
}

static struct cpuidle_params latona_cpuidle_params[] = {
	/* C1 */
	{74 + 78, 152, 1},
	/* C2 */
	{165 + 90, 255, 0},
	/* C3 */
	{163 + 180, 345, 1},
	/* C4 */
	{2852 + 605, 3457, 0},
	/* C5 */
	{800 + 366, 2120, 1},
	/* C6 */
	{4080 + 801, 4881, 0},
	/* C7 */
	{4300 + 8794, 159000, 1},
};

static void __init latona_init(void)
{
	omap3_mux_init(latona_board_mux_ptr, OMAP_PACKAGE_CBP);
	omap3_pm_init_cpuidle(latona_cpuidle_params);
	latona_mux_init_gpio_out();
	latona_mux_set_wakeup_gpio();
	msecure_init();
	usbhs_init(&usbhs_bdata);
	latona_wifi_init();
	latona_peripherals_init();
	latona_display_init();
	omap_register_ion();
	/* Added to register latona devices */
	platform_add_devices(latona_devices, ARRAY_SIZE(latona_devices));
	wl127x_vio_leakage_fix();
	latona_cmdline_set_serialno(); //Inject serialno in commandline
}

static void __init latona_reserve(void)
{

#ifdef CONFIG_OMAP_RAM_CONSOLE
	omap_ram_console_init(LATONA_RAM_CONSOLE_START,
				LATONA_RAM_CONSOLE_SIZE);
#endif
>>>>>>> dhiru1602_cm-10.1
	/* do the static reservations first */
	memblock_remove(OMAP3_PHYS_ADDR_SMC_MEM, PHYS_ADDR_SMC_SIZE);

#ifdef CONFIG_ION_OMAP
	omap_ion_init();
#endif
	omap_reserve();
}

<<<<<<< HEAD
MACHINE_START(OMAP_ZOOM2, "OMAP Zoom2 board")
	.boot_params	= 0x80000100,
	.reserve	= omap_reserve,
	.map_io		= omap3_map_io,
	.init_early	= omap_zoom_init_early,
	.init_irq	= omap_init_irq,
	.init_machine	= omap_zoom_init,
	.timer		= &omap_timer,
MACHINE_END

MACHINE_START(OMAP_ZOOM3, "OMAP Zoom3 board")
	.boot_params	= 0x80000100,
	.reserve	= zoom_reserve,
	.map_io		= omap3_map_io,
	.init_early	= omap_zoom_init_early,
	.init_irq	= omap_init_irq,
	.init_machine	= omap_zoom_init,
=======
static void __init latona_fixup(struct machine_desc *desc,
				    struct tag *tags, char **cmdline,
				    struct meminfo *mi)
{
	mi->nr_banks = 2;

	mi->bank[0].start = 0x80000000;
	mi->bank[0].size = SZ_256M;

	mi->bank[1].start = 0x90000000;
	mi->bank[1].size = SZ_256M;
}

MACHINE_START(LATONA, "SAMSUNG LATONA BOARD")
	.boot_params	= 0x80000100,
	.fixup          = latona_fixup,
	.reserve	= latona_reserve,
	.map_io		= omap3_map_io,
	.init_early	= latona_init_early,
	.init_irq	= omap_init_irq,
	.init_machine	= latona_init,
>>>>>>> dhiru1602_cm-10.1
	.timer		= &omap_timer,
MACHINE_END
