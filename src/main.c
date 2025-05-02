#include "main.h"

void blink_led();


int main() {


    xTaskCreate(blink_led, "Blink_led_task", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    return 0;
}

void blink_led(){

    stdio_init_all();
    cyw43_arch_init();

    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        printf("Set ON LED\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);     
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        printf("Set OFF LED\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}
