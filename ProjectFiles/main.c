#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "semphr.h"

SemaphoreHandle_t leds;

void phil(uint pin)
{
    while(true)
    {
        if(xSemaphoreTake(leds, (TickType_t) 10000) == pdTRUE){
            gpio_put(pin, 1);
            vTaskDelay(50);
            gpio_put(pin, 0);
            xSemaphoreGive(leds);
            vTaskDelay(1);
        }
        else{
            vTaskDelay(1);
        }
    }
}

int main()
{
    stdio_init_all();

    leds = xSemaphoreCreateCounting(3,3); // AMOUNT OF CHOPSTICKS

    for(uint pin=2;pin<10;pin++){
        gpio_init(pin);
        gpio_set_dir(pin, GPIO_OUT);
    }

    for(uint i = 2; i < 10; i++) // 8 PHILOSOPHERS
    {
        xTaskCreate(phil, "phil", 256, i, 1, NULL);
    }
    
    vTaskStartScheduler();

    while(1){};
}
