/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef	_USB_OSAI_H_
#define	_USB_OSAI_H_
#include <linux/delay.h>
#include <linux/spinlock_types.h>
#include <linux/spinlock.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <linux/random.h>
#include <linux/slab.h>
#include "mu3d_hal_comm.h"
#include "mu3d_hal_hw.h"

#undef EXTERN

#ifdef _USB_OSAI_EXT_
#define EXTERN
#else
#define EXTERN \
extern
#endif

#define K_EMERG		0
#define K_ALET		1
#define K_CRIT		2
#define K_ERR		3
#define K_WARNIN	4
#define K_NOTICE	5
#define K_INFO		6
#define K_DEBUG		7

/*Set the debug level at musb_core.c*/
extern int debug_level;

#ifdef USE_SSUSB_QMU
#define qmu_printk(level, fmt, args...) do { \
		if (debug_level >= level) { \
			pr_notice("[U3D][Q]" fmt, ## args); \
		} \
	} while (0)
#endif
#ifdef VENDOR_EDIT
///tongfeng.Huang@BSP.BaseDrv.CHG.Basic, 2018/02/19  mark for delete debug log
extern int oppo_debug_level;
#define os_printk(level, fmt, args...) do { \
		if (oppo_debug_level >= level) { \
			pr_notice("[U3D]" fmt, ## args); \
		} \
	} while (0)
#else
#define os_printk(level, fmt, args...) do { \
		if (debug_level >= level) { \
			pr_notice("[U3D]" fmt, ## args); \
		} \
	} while (0)
#endif
#define OS_R_OK                    ((int)   0)

EXTERN spinlock_t _lock;
EXTERN int os_reg_isr(unsigned int irq, irq_handler_t handler, void *isrbuffer);
/* USBIF */
EXTERN void os_free_isr(unsigned int irq, void *isrbuffer);
EXTERN void os_ms_delay(unsigned int ui4_delay);
EXTERN void os_us_delay(unsigned int ui4_delay);
EXTERN void os_ms_sleep(unsigned int ui4_sleep);

void os_memcpy(char *pv_to, char *pv_from, size_t z_l);
EXTERN void *os_memset(void *pv_to, unsigned char ui1_c, size_t z_l);
EXTERN void *os_mem_alloc(size_t z_size);

EXTERN void *os_phys_to_virt(void *paddr);

EXTERN void os_mem_free(void *pv_mem);
EXTERN void os_disableIrq(unsigned int irq);
EXTERN void os_disableIrq(unsigned int irq);
EXTERN void os_enableIrq(unsigned int irq);
EXTERN void os_clearIrq(unsigned int irq);
EXTERN void os_get_random_bytes(void *buf, int nbytes);
EXTERN void os_disableDcache(void);
EXTERN void os_flushinvalidateDcache(void);
extern int rand(void);
extern void HalFlushInvalidateDCache(void);


#undef EXTERN

#endif
