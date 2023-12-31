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

#ifndef BACKWARD_DRIVER_H
#define BACKWARD_DRIVER_H

#include <linux/types.h>

#include "teei_common.h"

extern struct service_handler reetime;
extern struct service_handler vfs_handler;
extern unsigned char *daulOS_VFS_share_mem;

int notify_vfs_handle(void);
int wait_for_vfs_done(void);

int init_all_service_handlers(void);
int vfs_thread_function(unsigned long virt_addr,
			unsigned long para_vaddr, unsigned long buff_vaddr);


#endif /* end of BACKWARD_DRIVER_H */
