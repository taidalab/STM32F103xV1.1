/*
 * escore-uart.h  --  Audience eS705 UART interface
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

#ifndef _ESCORE_UART_H
#define _ESCORE_UART_H

enum {
	UART_RATE_4608,	UART_RATE_9216,	UART_RATE_1kk,
	UART_RATE_1M, UART_RATE_1152k, UART_RATE_2kk,
	UART_RATE_2M, UART_RATE_3kk, UART_RATE_3M,
	UART_RATE_MAX
};
enum {
	ESXXX_CLK_6M, ESXXX_CLK_6144M,
	ESXXX_CLK_9M6, ESXXX_CLK_12M,
	ESXXX_CLK_12M288, ESXXX_CLK_13M,
	ESXXX_CLK_15M36, ESXXX_CLK_18M432,
	ESXXX_CLK_19M2, ESXXX_CLK_24M,
	ESXXX_CLK_24M576, ESXXX_CLK_26M,
	ESXXX_CLK_FREQ_MAX
};

struct escore_priv;

struct escore_uart_device {
	struct file *file;
	unsigned int baudrate_bootloader;
	unsigned int baudrate_fw;
};
  struct cycle_buffer {  
     unsigned char *buf;  
     unsigned int size;  
     unsigned int in;  
     unsigned int out;  
 };  

unsigned int fifo_put(unsigned char *buf, unsigned int len) ; 
unsigned int fifo_get(unsigned char *buf, unsigned int len) ; 
  int fifo_check();

 int debug_fifo(void);

extern struct platform_driver escore_uart_driver;
extern struct platform_device escore_uart_device;
extern struct escore_uart_device escore_uart;
int escore_uart_probe(void);
int escore_uart_bus_init(struct escore_priv *escore);
#if defined(CONFIG_SND_SOC_ES_UART) ||\
	defined(CONFIG_SND_SOC_ES_HIGH_BW_BUS_UART) ||\
	defined(CONFIG_SND_SOC_ES_WAKEUP_UART)
int escore_uart_add_dummy_dev(struct escore_priv *escore);
#else
#define escore_uart_add_dummy_dev(x) ({ do {} while (0); 0; })
#endif

#endif
