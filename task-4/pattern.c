#include <stdint.h>
#include "gpio.h"
#include "pattern.h"

extern volatile uint8_t stop_flag;

void delay_ms(uint32_t ms)
{
    for(uint32_t j=0;j<ms;j++)
    {
        for(volatile uint32_t i=0;i<5000;i++);
    }
}

void play_pattern(char *buf)
{
    stop_flag = 0;

    uint32_t i = 0;

    while(buf[i] != '\0')
    {
        if(stop_flag)
        {
            led_off();
            return;
        }

        if(buf[i] == '1')
            led_on();
        else
            led_off();

        delay_ms(500);

        i++;
    }

    led_off();
}