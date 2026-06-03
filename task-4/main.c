#include <stdint.h>
#include <string.h>

#include "gpio.h"
#include "uart.h"
#include "pattern.h"

char pattern[64];
volatile uint8_t stop_flag = 0;

int main(void)
{
    gpio_init();
    uart_init();

    uart_print("Pattern Sequencer Ready\r\n");

    while(1)
    {
        char cmd[80];
        uint32_t idx = 0;

        char c;

        while(1)
        {
            c = uart_rx();

            if(c == '\r' || c == '\n')
                break;

            cmd[idx++] = c;
        }

        cmd[idx] = '\0';

        if(strncmp(cmd, "PLAY ", 5) == 0)
        {
            strcpy(pattern, &cmd[5]);

            uart_print("PLAYING\r\n");

            play_pattern(pattern);

            uart_print("DONE\r\n");
        }

        else if(strcmp(cmd, "STOP") == 0)
        {
            stop_flag = 1;

            led_off();

            uart_print("STOPPED\r\n");
        }
    }
}