/* * halo_am3517.h - Configuration for Halo Instrument AM3517
 *
 * Author: Sean Donohue <sean.donohue@asdi.com>
 *
 * Based on am3517_evm.h
 *
 * Copyright (C) 2016 ASD Incorporated
 *
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* High Level Configuration Options */

#define CONFIG_OMAP
#define CONFIG_OMAP_COMMON

#define CONFIG_ARMV7_SECURE_BASE
/*#define CONFIG_ARMV7_NONSEC*/

#define CONFIG_SYS_CACHELINE_SIZE	64

#define CONFIG_SYS_NO_FLASH

#define CONFIG_NR_DRAM_BANKS	2	/* CS1 may or may not be populated */

/* Common ARM Erratas */
#define CONFIG_ARM_ERRATA_454179
#define CONFIG_ARM_ERRATA_430973
#define CONFIG_ARM_ERRATA_621766

#define CONFIG_EMIF4	/* The chip has EMIF4 controller */

/*
 * 1MB into the SDRAM to allow for SPL's bss at the beginning of SDRAM
 * 64 bytes before this address should be set aside for u-boot.img's
 * header. That is 0x800FFFC0--0x80100000 should not be used for any
 * other needs.
 */
#define CONFIG_SYS_TEXT_BASE		0x80100000
#define CONFIG_SYS_SPL_MALLOC_START	0x80208000
#define CONFIG_SYS_SPL_MALLOC_SIZE	0x100000

#include <asm/arch/cpu.h>		/* get chip and board defs */
#include <asm/arch/omap.h>

/* Display CPU and Board information */
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_MISC_INIT_R
#define CONFIG_CMDLINE_TAG		/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* Clock Defines */
#define V_OSCK			26000000	/* Clock output from T2 */
#define V_SCLK			(V_OSCK >> 1)

/* Size of malloc() pool */
/* Must be > 512 << 10 for use with ubifs commands */
#define CONFIG_SYS_MALLOC_LEN		(512 << 11)

/* Hardware drivers */

/* OMAP GPIO configuration */
#define CONFIG_OMAP_GPIO
#define CONFIG_OMAP3_GPIO_2
#define CONFIG_OMAP3_GPIO_3
#define CONFIG_OMAP3_GPIO_4
#define CONFIG_OMAP3_GPIO_5
#define CONFIG_OMAP3_GPIO_6

/* NS16550 Configuration */
#define V_NS16550_CLK			48000000	/* 48MHz (APLL96/2) */
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		V_NS16550_CLK

/* select serial console configuration */
#define CONFIG_CONS_INDEX		3
#define CONFIG_SYS_NS16550_COM3		OMAP34XX_UART3
#define CONFIG_SERIAL3			3	/* UART3 on AM3517 EVM */

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{4800, 9600, 19200, 38400, 57600,\
					115200}

/* SD/MMC */
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_OMAP_HSMMC
#define CONFIG_DOS_PARTITION

/*
 * USB configuration
 * Enable CONFIG_USB_MUSB_HOST for Host functionalities MSC, keyboard
 * Enable CONFIG_USB_MUSB_GADGET for Device functionalities.
 */
#define CONFIG_USB_MUSB_AM35X
#define CONFIG_USB_MUSB_PIO_ONLY

#ifdef CONFIG_USB_MUSB_AM35X

#ifdef CONFIG_USB_MUSB_HOST

#define CONFIG_USB_STORAGE
#define CONGIG_CMD_STORAGE

#ifdef CONFIG_USB_KEYBOARD
#define CONFIG_SYS_USB_EVENT_POLL
#define CONFIG_PREBOOT "usb start"
#endif /* CONFIG_USB_KEYBOARD */

#endif /* CONFIG_USB_MUSB_HOST */

#ifdef CONFIG_USB_MUSB_GADGET
#define CONFIG_USB_ETHER
#define CONFIG_USB_ETH_RNDIS
#endif /* CONFIG_USB_MUSB_GADGET */

#endif /* CONFIG_USB_MUSB_AM35X */

/* commands to include */
#define CONFIG_CMD_NAND
#define CONFIG_CMD_PART
#define CONFIG_CMD_MTDPARTS

/* I2C */
#define CONFIG_SYS_I2C
#define CONFIG_SYS_OMAP24_I2C_SPEED	100000
#define CONFIG_SYS_OMAP24_I2C_SLAVE	1
#define CONFIG_SYS_I2C_OMAP34XX

/* Ethernet */
#define CONFIG_DRIVER_TI_EMAC
#define CONFIG_DRIVER_TI_EMAC_USE_RMII
#define CONFIG_MII
#define CONFIG_BOOTP_DEFAULT
#define CONFIG_BOOTP_DNS
#define CONFIG_BOOTP_DNS2
#define CONFIG_BOOTP_SEND_HOSTNAME
#define CONFIG_NET_RETRY_COUNT		10

/* Board NAND Info. */
#ifdef CONFIG_NAND
#define CONFIG_NAND_OMAP_GPMC
#define CONFIG_NAND_OMAP_GPMC_PREFETCH
#define CONFIG_BCH
#define CONFIG_CMD_UBI			/* UBI-formated MTD partition support */
#define CONFIG_CMD_UBIFS		/* Read-only UBI volume operations */
#define CONFIG_RBTREE			/* required by CONFIG_CMD_UBI */
#define CONFIG_LZO			/* required by CONFIG_CMD_UBIFS */
#define CONFIG_SYS_NAND_ADDR		NAND_BASE	/* physical address */
							/* to access nand */
#define CONFIG_SYS_NAND_BASE		NAND_BASE	/* physical address */
							/* to access */
							/* nand at CS0 */

#define CONFIG_SYS_MAX_NAND_DEVICE	1		/* Max number of */
							/* NAND devices */
#define CONFIG_SYS_NAND_BUSWIDTH_16BIT
#define CONFIG_SYS_NAND_5_ADDR_CYCLE
#define CONFIG_SYS_NAND_PAGE_COUNT	64
#define CONFIG_SYS_NAND_PAGE_SIZE	2048
#define CONFIG_SYS_NAND_OOBSIZE		64
#define CONFIG_SYS_NAND_BLOCK_SIZE	(128 * 1024)
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	NAND_LARGE_BADBLOCK_POS
#define CONFIG_SYS_NAND_ECCPOS		{ 2,  3,  4,  5,  6,  7,  8,  9, 10, \
					 11, 12, 13, 14, 16, 17, 18, 19, 20, \
					 21, 22, 23, 24, 25, 26, 27, 28, 30, \
					 31, 32, 33, 34, 35, 36, 37, 38, 39, \
					 40, 41, 42, 44, 45, 46, 47, 48, 49, \
					 50, 51, 52, 53, 54, 55, 56 }

#define CONFIG_SYS_NAND_ECCSIZE		512
#define CONFIG_SYS_NAND_ECCBYTES	13
#define CONFIG_NAND_OMAP_ECCSCHEME	OMAP_ECC_BCH8_CODE_HW_DETECTION_SW
#define CONFIG_SYS_NAND_MAX_OOBFREE	2
#define CONFIG_SYS_NAND_MAX_ECCPOS	56
#define CONFIG_SYS_NAND_U_BOOT_START	CONFIG_SYS_TEXT_BASE

/**
 * See FS5-200
 */
#define CONFIG_SYS_NAND_U_BOOT_OFFS	0x20000
#define CONFIG_MTD_PARTITIONS		/* required for UBI partition support */
#define CONFIG_MTD_DEVICE		/* needed for mtdparts commands */
/* NAND block size is 128 KiB.  Synchronize these values with
 * corresponding Device Tree entries in Linux:
 *  MLO(SPL)            1 * NAND_BLOCK_SIZE = 128 KiB  @ 0x000000
 *  u-boot              8 * NAND_BLOCK_SIZE = 1024 KiB @ 0x020000
 *  u-boot-env          2 * NAND_BLOCK_SIZE = 256 KiB  @ 0x120000
 *  ubi                 Remaining Flash Space           @ 0x160000
 */
#define MTDIDS_DEFAULT "nand0=omap2-nand.0"
#define MTDPARTS_DEFAULT "mtdparts=omap2-nand.0:"	\
	"128k(MLO),"					\
	"1024k(u-boot),"				\
	"256k(u-boot-env),"				\
	"-(ubi)"
#else
#define MTDIDS_DEFAULT
#define MTDPARTS_DEFAULT
#endif /* CONFIG_NAND */

/* Environment information */
#define CONFIG_BOOTDELAY	10

#define CONFIG_BOOTFILE		"zImage"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"loadaddr=0x82000000\0" \
	"console=ttyO2,115200n8\0" \
	"fdtfile=fs5-am3517.dtb\0" \
	"fdtaddr=0x82C00000\0" \
	"vram=16M\0" \
	"bootenv=uEnv.txt\0" \
	"cmdline=\0" \
	"optargs=\0" \
	"mtdids=" MTDIDS_DEFAULT "\0" \
	"mtdparts=" MTDPARTS_DEFAULT "\0" \
	"mmcdev=0\0" \
	"mmcpart=1\0" \
	"mmcroot=/dev/mmcblk0p2 rw\0" \
	"nandbootpart=rootfsa\0" \
	"nandrootfssize=0x5000000\0" \
	"MLOprodstage=0x160000\0" \
	"ubootprodstage=0x180000\0" \
	"MLOsize=0x20000\0" \
	"ubootstart=0x20000\0" \
	"ubootsize=0x100000\0" \
	"rootfsubifsprodstage=0x280000\0" \
	"ubipartname=${mender_mtd_ubi_dev_name}\0" \
	"mmcrootfstype=ext4\0" \
	"mmcargs=" \
		"setenv ubipartname ${mender_mtd_ubi_dev_name}; " \
		"setenv bootargs console=${console} " \
			"${mtdparts} " \
			"${optargs} " \
			"root=${mmcroot} ubi.mtd=${ubipartname} " \
			"rootfstype=${mmcrootfstype} rootwait ubi.fm_autoconvert=1 " \
			"${cmdline}\0" \
	"nandargs="\
        "setenv ubipartname ${mender_mtd_ubi_dev_name}; "\
        "setenv bootargs console=${console} " \
            "${mtdparts} " \
            "${optargs} " \
            "root=${mender_kernel_root} ro ubi.mtd=${ubipartname} " \
            "rootfstype=ubifs rootwait ubi.fm_autoconvert=1 " \
            "${cmdline}\0" \
	"nandMLO=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} MLO; " \
		"nandecc hw hamming1; nand erase.part MLO; " \
		"nand write ${loadaddr} 0x0 ${MLOsize}; nandecc sw bch8; \0"\
	"nandMLOfirstrun=nandecc hw hamming1; nand read ${loadaddr} ${MLOprodstage} ${MLOsize}; " \
		"nand erase.part MLO; " \
		"nand write ${loadaddr} 0x0 ${MLOsize}; nandecc sw bch8; \0"\
	"nanduboot=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} u-boot.img; " \
		"nandecc sw bch8; nand erase.part u-boot; " \
		"nand write ${loadaddr} ${ubootstart} ${ubootsize}\0" \
	"nandubootfirstrun=nandecc hw hamming1; nand read ${loadaddr} ${ubootprodstage} ${ubootsize}; " \
		"nandecc sw bch8; nand erase.part u-boot; "\
		"nand write ${loadaddr} ${ubootstart} ${ubootsize}\0" \
	"nandubifsloadmmc=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} core-image-fs5-nand-fs5-am3517.ubifs;\0" \
	"nandubifsloadfirstrun=nandecc hw hamming1; nand read ${loadaddr} ${rootfsubifsprodstage} ${nandrootfssize}; nandecc sw bch8;\0" \
	"nandubicreate=nand erase.part ${ubipartname}; ubi part ${ubipartname}; " \
        "ubi createvol rootfsa ${nandrootfssize}; ubi createvol rootfsb ${nandrootfssize}; ubi createvol data;\0"\
    "nandubifswrite=ubi write ${loadaddr} ${nandbootpart} ${nandrootfssize};\0"  \
    "nandreflashmmc=if mmc rescan; then echo Reflashing NAND...; " \
		"run mender_setup; run nandargs; run nandMLO; run nanduboot; run nandubifsloadmmc; ubi part ${ubipartname}; run nandubifswrite;" \
		"else echo No MMC detected!; fi;\0" \
	"nandfirstrun=" \
		"run nandMLOfirstrun; run nandubootfirstrun; run nandubifsloadfirstrun; run nandubicreate; run nandubifswrite;\0" \
	"loadbootenv=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${bootenv}\0"\
	"importbootenv=echo Importing environment from mmc ...; " \
		"env import -t ${loadaddr} ${filesize}\0" \
	"bootscript=echo Running bootscript from mmc ...; " \
		"source ${loadaddr}\0" \
	"loadimage=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${bootfile}\0" \
	"loadfdt=fatload mmc ${mmcdev}:${mmcpart} ${fdtaddr} ${fdtfile}\0" \
	"mmcboot=echo Booting from mmc ...; " \
		"run mmcargs; " \
		"if run loadimage; then " \
			"run loadfdt; " \
			"ubi part ${mender_mtd_ubi_dev_name}; " \
			"bootz ${loadaddr} - ${fdtaddr};" \
		"fi;\0" \
	"nandboot=echo Booting from nand with mender support...; " \
        "run mender_setup; "\
        "run nandargs; "\
        "ubi part ${mender_mtd_ubi_dev_name} && "\
        "ubifsmount ${mender_uboot_root_name} && "\
		"ubifsload ${loadaddr} /boot/uImage; " \
		"ubifsload ${fdtaddr} /boot/${fdtfile}; " \
		"bootm ${loadaddr} - ${fdtaddr}\0" \

#define CONFIG_BOOTCOMMAND \
	"mmc dev ${mmcdev}; if mmc rescan; then " \
		"echo SD/MMC found on device $mmcdev; " \
		"echo Running default loadimage ...; " \
		"setenv bootfile zImage; " \
		"if run loadimage; then " \
			"run loadfdt; " \
			"run mmcboot; " \
		"fi; " \
	"else run nandboot; run mender_try_to_recover; fi"

/* Miscellaneous configurable options */
#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING
#define CONFIG_VERSION_VARIABLE
#define CONFIG_SYS_LONGHELP
#define CONFIG_PARTITION_UUIDS

/* We set the max number of command args high to avoid HUSH bugs. */
#define CONFIG_SYS_MAXARGS		64

/* Console I/O Buffer Size */
#define CONFIG_SYS_CBSIZE		512
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE \
					+ sizeof(CONFIG_SYS_PROMPT) + 16)
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE

/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	(OMAP34XX_SDRC_CS0)
#define CONFIG_SYS_MEMTEST_END		(OMAP34XX_SDRC_CS0 + \
					0x01F00000) /* 31MB */

#define CONFIG_SYS_LOAD_ADDR		(OMAP34XX_SDRC_CS0) /* default load */
								/* address */

/*
 * AM3517 has 12 GP timers, they can be driven by the system clock
 * (12/13/16.8/19.2/38.4MHz) or by 32KHz clock. We use 13MHz (V_SCLK).
 * This rate is divided by a local divisor.
 */
#define CONFIG_SYS_TIMERBASE		OMAP34XX_GPT2
#define CONFIG_SYS_PTV			2	/* Divisor: 2^(PTV+1) => 8 */

/* Physical Memory Map */
#define PHYS_SDRAM_1			OMAP34XX_SDRC_CS0
#define PHYS_SDRAM_2			OMAP34XX_SDRC_CS1
#define CONFIG_SYS_CS0_SIZE		(256 * 1024 * 1024)
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_INIT_RAM_ADDR	0x4020f800
#define CONFIG_SYS_INIT_RAM_SIZE	0x800
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR + \
					 CONFIG_SYS_INIT_RAM_SIZE - \
					 GENERATED_GBL_DATA_SIZE)

/* FLASH and environment organization */

/* **** PISMO SUPPORT *** */
#define CONFIG_SYS_MAX_FLASH_SECT	520	/* max number of sectors */
						/* on one chip */
#define CONFIG_SYS_MAX_FLASH_BANKS	2	/* max number of flash banks */
#define CONFIG_SYS_MONITOR_LEN		(256 << 10)	/* Reserve 2 sectors */

#if defined(CONFIG_NAND)
#define CONFIG_SYS_FLASH_BASE		NAND_BASE
#endif

/* Monitor at start of flash */
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_FLASH_BASE

#define CONFIG_SYS_ENV_SECT_SIZE	(128 << 10)	/* 128 KiB */
#define CONFIG_ENV_SIZE			CONFIG_SYS_ENV_SECT_SIZE
#define SMNAND_ENV_OFFSET		0x120000 /* u-boot-env starts here */
/*
 * Moved to MENDER_UBOOT_ENV_STORAGE_DEVICE_OFFSET_1 and MENDER_UBOOT_ENV_STORAGE_DEVICE_OFFSET_2
 * See 0002-Generic-boot-code-for-Mender.patch from mender layer
 * #define CONFIG_ENV_OFFSET		SMNAND_ENV_OFFSET
 * #define CONFIG_ENV_OFFSET_REDUND		(CONFIG_ENV_OFFSET + CONFIG_ENV_SIZE)
 */
#define CONFIG_ENV_ADDR			SMNAND_ENV_OFFSET
#define CONFIG_ENV_IS_IN_NAND

/* Defines for SPL */
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_BOARD_INIT
#define CONFIG_SPL_NAND_SIMPLE
#define CONFIG_SPL_TEXT_BASE		0x40200000
/*#define CONFIG_SPL_MAX_SIZE		(SRAM_SCRATCH_SPACE_ADDR - \
					 CONFIG_SPL_TEXT_BASE)*/
#define CONFIG_SPL_MAX_SIZE 		(64*1024)

#define CONFIG_SPL_BSS_START_ADDR	0x80000000
#define CONFIG_SPL_BSS_MAX_SIZE		0x80000		/* 512 KB */

#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR	0x300 /* address 0x60000 */
#define CONFIG_SYS_U_BOOT_MAX_SIZE_SECTORS	0x200 /* 256 KB */
#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION	1
#define CONFIG_SPL_FS_LOAD_PAYLOAD_NAME		"u-boot.img"

#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_LIBDISK_SUPPORT
#define CONFIG_SPL_I2C_SUPPORT
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_MMC_SUPPORT
#define CONFIG_SPL_FAT_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_NAND_SUPPORT
#define CONFIG_SPL_NAND_BASE
#define CONFIG_SPL_NAND_DRIVERS
#define CONFIG_SPL_NAND_ECC
#define CONFIG_SPL_MTD_SUPPORT
#define CONFIG_SPL_POWER_SUPPORT
#define CONFIG_SPL_LDSCRIPT		"$(CPUDIR)/omap-common/u-boot-spl.lds"

/* defines for Mender */
#define CONFIG_BOOTCOUNT_ENV
#define CONFIG_BOOTCOUNT_LIMIT


#endif /* __CONFIG_H */
