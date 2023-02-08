#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

void init_pins()
{
    uint pin = 2;
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
}
void LED_ON(uint PIN)
{
    gpio_put(PIN, 1);
}

int main()
{
    stdio_init_all();

    xTaskCreate(init_pins, "init_pins", 256, NULL, 1, NULL);
    xTaskCreate(LED_ON, "led on", 256, 2, 1, NULL);
    
    vTaskStartScheduler();

    while(1){};
}
