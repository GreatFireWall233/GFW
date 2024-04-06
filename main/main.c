#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "nvs_flash.h"

#include "DHT22.h"
#include "MQ2.h"

#define DHT22_GPIO 2
#define READ_TICK 500


void DHT_task(void *pvParameter) {
    setDHTgpio(DHT22_GPIO);

    while (1) {
        int ret = readDHT();

        errorHandler(ret);

        printf("Hum %.1f\n", getHumidity());
        printf("Temp %.1f\n", getTemperature());
        vTaskDelay(READ_TICK);
    }
}

void MQ2_task(void *pvParameter) {
    initMQ2();

    while (1) {
        int ret = readMQ2RowData();

        printf("%d", ret);

        vTaskDelay(READ_TICK);
    }
    
}

void app_main() {
    nvs_flash_init();
    vTaskDelay(READ_TICK);
    xTaskCreate(&DHT_task, "DHT_task", 2048, NULL, 5, NULL);
    xTaskCreate(&MQ2_task, "MQ2_task", 2048, NULL, 5, NULL);
}