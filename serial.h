#ifndef SERIAL_H_
#define SERIAL_H_
#include <stdio.h>
#define BAUDRATE 38400
#define UBRR (F_CPU/16/BAUDRATE-1)

void uart_init(void);

int uart_putchar(char chr, FILE *stream);

void uart_putstr(const char *str);

char uart_getchar(void);

#endif

