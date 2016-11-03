/*
 * escore-uart-common.h  --  UART interface for Audience earSmart chips
 *
 * Copyright 2013 Audience, Inc.
 *
 * Author: Matt Lupfer <mlupfer@cardinalpeak.com>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _ESCORE_UART_COMMON_H
#define _ESCORE_UART_COMMON_H

/* UART Baud rates */

#define ES_UARTHS_BAUD_RATE_460K  0x00 /* 460.8 kHz */
#define ES_UARTHS_BAUD_RATE_921K  0x01 /* 921.6 kHz */
#define ES_UARTHS_BAUD_RATE_1000K 0x02 /* 1.000 MHz */
#define ES_UARTHS_BAUD_RATE_1024K 0x03 /* 1.024 MHz */
#define ES_UARTHS_BAUD_RATE_1152K 0x04 /* 1.152 MHz */
#define ES_UARTHS_BAUD_RATE_2000K 0x05 /* 2.000 MHz */
#define ES_UARTHS_BAUD_RATE_2048K 0x06 /* 2.048 MHz */
#define ES_UARTHS_BAUD_RATE_3000K 0x07 /* 3.000 MHz */
#define ES_UARTHS_BAUD_RATE_3072K 0x08 /* 3.072 MHz */


#define UART_TTY_BAUD_RATE_28_8_K	28800
#define UART_TTY_BAUD_RATE_460_8_K	460800
#define UART_TTY_BAUD_RATE_2_048_M	2048000
#define UART_TTY_BAUD_RATE_3_M		3000000

#define UART_TTY_STOP_BITS		2
#define UART_TTY_WRITE_SZ		512

#define ESCORE_SBL_SYNC_CMD		0x00
#define ESCORE_SBL_SYNC_ACK		ESCORE_SBL_SYNC_CMD
#define ESCORE_SBL_BOOT_CMD		0x01
#define ESCORE_SBL_BOOT_ACK		ESCORE_SBL_BOOT_CMD
#define ESCORE_SBL_FW_ACK		0x02

#define ESCORE_SBL_SET_RATE_REQ_CMD	0x8019
#define MAX_EAGAIN_RETRY		20
#define EAGAIN_RETRY_DELAY		1000
#define ES_TTY_BUF_AVAIL_WAIT_DELAY	2000

extern  u8 RxBuf[RX_BUFF_SIZE];

u32 escore_cpu_to_uart(struct escore_priv *escore, u32 resp);
u32 escore_uart_to_cpu(struct escore_priv *escore, u32 resp);
int escore_uart_read(struct escore_priv *escore, void *buf, int len);
int escore_uart_read_internal(struct escore_priv *escore, void *buf, int len);
int escore_uart_write(struct escore_priv *escore, const void *buf, int len);
int escore_uart_write_file(struct escore_priv *escore, const char * name);
int escore_uart_write_data_block(struct escore_priv *escore, const void *buf, int len);
int escore_uart_cmd(struct escore_priv *escore, u32 cmd, u32 *resp);
int escore_configure_tty(u32 bps, int stop);
int escore_uart_open(struct escore_priv *escore);
int escore_uart_close(struct escore_priv *escore);
int escore_uart_wait(struct escore_priv *escore);



#endif
