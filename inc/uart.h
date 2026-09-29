#ifndef UART_H
#define UART_H
void initUart(void);
void uart_isr(void) __interrupt(4);
#endif