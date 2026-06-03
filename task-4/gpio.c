#include "gpio.h"

#define RCC_APB2PCENR (*(volatile uint32_t*)0x40021018)
#define IOPDEN        (1 << 5)

#define GPIOD_CFGLR   (*(volatile uint32_t*)0x40011400)
#define GPIOD_BSHR    (*(volatile uint32_t*)0x40011410)

#define LED_PIN 6

void gpio_init(void)
{
    RCC_APB2PCENR |= IOPDEN;

    GPIOD_CFGLR &= ~(0xF << 24);
    GPIOD_CFGLR |=  (0x3 << 24);
}

void led_on(void)
{
    GPIOD_BSHR = (1 << LED_PIN);
}

void led_off(void)
{
    GPIOD_BSHR = (1 << (LED_PIN + 16));
}