#pragma once

#include "driver/mcpwm.h"
#include "soc/mcpwm_periph.h"
#include "esp_log.h"
#include "esp_err.h"

typedef struct
{
    mcpwm_config_t pwm_config;
    mcpwm_timer_t mcpwm_timer;
    mcpwm_unit_t mcpwm_unit;
    mcpwm_generator_t mcpwm_generator;
    int gpio_num;
} servo_hardware_t;

void init_hw_for_servo(servo_hardware_t* hw);
int32_t set_duty_by_us(servo_hardware_t* servo, uint32_t us);
int32_t set_duty_by_percent(servo_hardware_t *hw, float percent);
