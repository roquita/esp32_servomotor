#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "servomotor.h"

#define TAG "MAIN"

void servo_task(void *arg)
{
    servomotor_t servo = {
        .duty_min_us = 504,
        .duty_max_us = 2360,
        .hw = {
            .pwm_config = {
                .frequency = 50,
                .cmpr_a = 0.0,
                .cmpr_b = 0.0,
                .duty_mode = MCPWM_DUTY_MODE_0,
                .counter_mode = MCPWM_UP_COUNTER,
            },
            .mcpwm_timer = MCPWM_TIMER_0,
            .mcpwm_unit = MCPWM_UNIT_0,
            .mcpwm_generator = MCPWM_GEN_A,
            .gpio_num = 18,
        },
    };

    servo_init(&servo);

    while (1)
    {
        int angle = 0;
        for (; angle < 180; angle++)
        {
            ESP_LOGI(TAG, "angle:%i", angle);
            servo_set_pos_by_angle(&servo, angle);
            vTaskDelay(pdMS_TO_TICKS(20));
        }

        for (; angle >= 0; angle--)
        {
            ESP_LOGI(TAG, "angle:%i", angle);
            servo_set_pos_by_angle(&servo, angle);
            vTaskDelay(pdMS_TO_TICKS(20));
        }
    }
}

void app_main(void)
{
    printf("Testing servo motor.......\n");
    xTaskCreatePinnedToCore(servo_task, "servo_task", 4 * 1024, NULL, 2, NULL, 0);
}
