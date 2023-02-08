#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "LED.h"

void init()
{
    init_pins();
    wave();
}
int main()
{
    stdio_init_all();

    xTaskCreate(init, "init", 256, NULL, 1, NULL);
    
    vTaskStartScheduler();

    while(1){};
}
