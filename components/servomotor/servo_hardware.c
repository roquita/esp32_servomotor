#include "servo_hardware.h"

#define TAG "SERVO_HW"

void init_hw_for_servo(servo_hardware_t *hw)
{
#if (ESP_PLATFORM == 1)
    mcpwm_io_signals_t io_signal = (hw->mcpwm_timer) * 2 + hw->mcpwm_generator;

    //1. mcpwm gpio initialization
    ESP_LOGI(TAG, "initializing mcpwm servo control gpio......");
    mcpwm_gpio_init(hw->mcpwm_unit, io_signal, hw->gpio_num);

    //2. initial mcpwm configuration
    ESP_LOGI(TAG, "Configuring Initial Parameters of mcpwm......");

    mcpwm_init(hw->mcpwm_unit, hw->mcpwm_timer, &(hw->pwm_config));
#endif
}

esp_err_t set_duty_by_us(servo_hardware_t *hw, uint32_t us)
{
#if (ESP_PLATFORM == 1)
    return mcpwm_set_duty_in_us(hw->mcpwm_unit, hw->mcpwm_timer, hw->mcpwm_generator, us);
#endif
}

esp_err_t set_duty_by_percent(servo_hardware_t *hw, float percent)
{
#if (ESP_PLATFORM == 1)
    return mcpwm_set_duty(hw->mcpwm_unit, hw->mcpwm_timer, hw->mcpwm_generator, percent);
#endif
}