#include <stdint.h>           // For uint32_t
#include "freertos/FreeRTOS.h" // For FreeRTOS functions
#include "freertos/task.h"     // For vTaskDelay
#include "driver/gpio.h"       // For GPIO functions

#define GPIO_OUT_W1TS_REG 0x3FF44008 // Dummy address; replace with actual
#define GPIO_OUT_W1TC_REG 0x3FF4400C // Dummy address; replace with actual
#define GPIO_ENABLE_REG   0x3FF44020 // Dummy address; replace with actual

#define DELAY_MS 1000 // Delay in milliseconds

void app_main(void) {
    // Corrected uint32_t type
    volatile uint32_t* gpio_out_w1ts_reg = (volatile uint32_t*) GPIO_OUT_W1TS_REG;
    volatile uint32_t* gpio_out_w1tc_reg = (volatile uint32_t*) GPIO_OUT_W1TC_REG;
    volatile uint32_t* gpio_enable_reg   = (volatile uint32_t*) GPIO_ENABLE_REG;

    // Enable GPIO pin
    *gpio_enable_reg = (1 << 2); // Enable GPIO2 as output

    while (1) {
        // Set GPIO pin high
        *gpio_out_w1ts_reg = (1 << 2);

        // Delay
        vTaskDelay(pdMS_TO_TICKS(DELAY_MS));

        // Set GPIO pin low
        *gpio_out_w1tc_reg = (1 << 2);

        // Delay
        vTaskDelay(pdMS_TO_TICKS(DELAY_MS));
    }
}
