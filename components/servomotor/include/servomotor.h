#pragma once

#include "servo_hardware.h"

typedef struct
{
    uint32_t duty_min_us;
    uint32_t duty_max_us;
    servo_hardware_t hw;
} servomotor_t;

void servo_init(servomotor_t *servo);
int32_t servo_set_pos_by_angle(servomotor_t *servo, uint32_t angle);
int32_t servo_set_pos_by_time_us(servomotor_t *servo, uint32_t us);
int32_t servo_set_pos_by_percent(servomotor_t *servo, float percent);