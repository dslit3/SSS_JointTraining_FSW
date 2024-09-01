/*
 * print_scan.c
 *
 * 	- May 11, 2023 (Creation)
 * 		Author : Darsh
 * 		Log    : Created the printMsg function
 */


#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "print_scan.h"
#include <UART/uart.h>

#if OP_REV == 2
#define ConsoleUART 	LPUART1
#endif

#define UART_BAUDRATE	115200

void printer_init() {
	usart_init(ConsoleUART, UART_BAUDRATE);
}

int printMsg(const char *message, ...) {
	char buff[128];

	va_list args;
	va_start(args, message);
	vsprintf(buff,message,args);

	usart_transmitBytes(ConsoleUART, buff);
}
