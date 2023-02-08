#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

void phil(uint pin)
{
    while(true)
    {
        gpio_put(pin, 1);
        vTaskDelay(50);
        gpio_put(pin,0);
        vTaskDelay(50);
    }
}

int main()
{
    stdio_init_all();

    for(uint pin=2;pin<10;pin++){
        gpio_init(pin);
        gpio_set_dir(pin, GPIO_OUT);
    }

    for(uint i = 2; i < 10; i++)
    {
        xTaskCreate(phil, "phil", 256, i, 1, NULL);
    }
    
    vTaskStartScheduler();

    while(1){};
}
