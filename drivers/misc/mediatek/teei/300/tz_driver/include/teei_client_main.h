/*
 * Copyright (c) 2015-2019, MICROTRUST Incorporated
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __TEEI_CLIENT_MAIN_H__
#define __TEEI_CLIENT_MAIN_H__

#include <linux/suspend.h>

#ifdef TUI_SUPPORT
#define POWER_DOWN			"power-detect"
#endif
#include <teei_ioc.h>
#include "teei_smc_struct.h"
#include "teei_client.h"
/* #define UT_DEBUG */
#define CANCEL_BUFF_SIZE                (4096)
#define TEEI_CONFIG_FULL_PATH_DEV_NAME	"/dev/teei_config"
#define TEEI_CONFIG_DEV			"teei_config"
#define MIN_BC_NUM			(4)
#define MAX_LC_NUM			(3)
#define TEEI_CPU_0

#define TEEI_TA 0x01
#define TEEI_DRV 0x00

enum {
	TZ_CALL_PREPARE,
	TZ_CALL_RETURNED,
};

struct tz_driver_state {
	struct mutex smc_lock;
	struct atomic_notifier_head notifier;
	struct platform_device *tz_log_pdev;
};

struct tz_driver_state *get_tz_drv_state(void);
int tz_call_notifier_register(struct notifier_block *n);
int tz_call_notifier_unregister(struct notifier_block *n);

extern unsigned int soter_error_flag;

extern struct workqueue_struct *secure_wq;
extern struct semaphore boot_sema;
extern struct smc_call_struct smc_call_entry;
extern unsigned long boot_vfs_addr;
extern unsigned long boot_soter_flag;
extern int keymaster_call_flag;
extern struct completion boot_decryto_lock;
extern struct task_struct *teei_switch_task;
extern struct kthread_worker ut_fastcall_worker;
extern unsigned long spi_ready_flag;
extern struct list_head g_block_link;

int get_current_cpuid(void);

void *tz_malloc_shared_mem(size_t size, int flags);
void tz_free_shared_mem(void *addr, size_t size);
void *tz_malloc(size_t size, int flags);

void secondary_boot_stage1(void *info);

int handle_switch_core(int cpu);
extern int handle_move_core(int cpu);
int tz_move_core(uint32_t cpu_id);


int is_teei_ready(void);
int teei_new_capi_init(void);
int handle_new_capi_call(void *args);

int tz_load_drv_by_str(const char *buf);
int tz_load_ta_by_str(const char *buf);

#endif /* __TEEI_CLIENT_MAIN_H__ */
