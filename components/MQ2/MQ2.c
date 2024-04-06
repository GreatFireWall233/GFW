#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "hal/adc_types.h"
#include "freertos/FreeRTOS.h"
#include "esp_adc/adc_continuous.h"


#include "MQ2.h"

bool is_initialized = false;

adc_continuous_handle_cfg_t adc_config;

void initMQ2() {

    adc_continuous_handle_cfg_t adc_config = {
        .max_store_buf_size = 1024,
        .conv_frame_size = 100
    };
    
}

void deinitMQ2() {
    adc_continuous_deinit(adc_config);
}

uint32_t readMQ2RowData() {

    
}