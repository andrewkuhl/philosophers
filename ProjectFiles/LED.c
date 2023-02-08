#include "LED.h"

void init_pins()
{
    uint pin = 2;
    for(pin=2;pin<10;pin++){
        gpio_init(pin);
        gpio_set_dir(pin, GPIO_OUT);
    }
}

void wave()
{
    uint pin = 2;
    while(true){

        for(pin=2;pin<10;pin++){
            gpio_put(pin, 1);
            vTaskDelay(10);
        }
        for(pin=2;pin<10;pin++){
            gpio_put(pin, 0);
            vTaskDelay(10);
        }
    }
}