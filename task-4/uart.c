#include <stdint.h>
#include "uart.h"

#define RCC_APB2PCENR (*(volatile uint32_t*)0x40021018)
#define IOPDEN        (1 << 5)
#define USART1EN      (1 << 14)

#define GPIOD_CFGLR   (*(volatile uint32_t*)0x40011400)

#define USART_STATR   (*(volatile uint32_t*)0x40013800)
#define USART_DATAR   (*(volatile uint32_t*)0x40013804)
#define USART_BRR     (*(volatile uint32_t*)0x40013808)
#define USART_CTLR1   (*(volatile uint32_t*)0x4001380C)

void uart_init(void)
{
    RCC_APB2PCENR |= IOPDEN;
    RCC_APB2PCENR |= USART1EN;

    GPIOD_CFGLR &= ~(0xF << 20);
    GPIOD_CFGLR |=  (0xB << 20);

    USART_BRR = 208;

    USART_CTLR1 |= (1 << 3);
    USART_CTLR1 |= (1 << 2);
    USART_CTLR1 |= (1 << 13);
}

void uart_tx(char c)
{
    while(!(USART_STATR & (1 << 7)));
    USART_DATAR = c;
}

char uart_rx(void)
{
    while(!(USART_STATR & (1 << 5)));
    return (char)USART_DATAR;
}

void uart_print(char *str)
{
    while(*str)
    {
        uart_tx(*str++);
    }
}