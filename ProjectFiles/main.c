#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

void init_pins()
{
    uint pin = 2;
    for(pin=2;pin<10;pin++){
        gpio_init(pin);
        gpio_set_dir(pin, GPIO_OUT);
    }
    while(true){

        for(pin=2;pin<10;pin++){
            gpio_put(pin, 1);
        }
        vTaskDelay(100);
        for(pin=2;pin<10;pin++){
            gpio_put(pin, 0);
        }
        vTaskDelay(100);
    }
}
void LED_ON(uint PIN)
{
    gpio_put(PIN, 1);
}

int main()
{
    stdio_init_all();

    xTaskCreate(init_pins, "init_pins", 256, NULL, 1, NULL);
    
    vTaskStartScheduler();

    while(1){};
}
