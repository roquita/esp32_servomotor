#include "servomotor.h"

#define TAG "SERVOMOTOR"

static uint32_t angle_to_us(uint32_t angle, uint32_t min_us, uint32_t max_us)
{
    float us = ((max_us - min_us) / 180.0) * angle + min_us;
    return (uint32_t)us;
}
void servo_init(servomotor_t *servo)
{
    init_hw_for_servo(&(servo->hw));
}
int32_t servo_set_pos_by_angle(servomotor_t *servo, uint32_t angle)
{ 
    uint32_t us = angle_to_us(angle, servo->duty_min_us, servo->duty_max_us);
    return set_duty_by_us(&(servo->hw), us);
}
int32_t servo_set_pos_by_time_us(servomotor_t *servo, uint32_t us)
{
    return set_duty_by_us(&(servo->hw), us);
}
int32_t servo_set_pos_by_percent(servomotor_t *servo, float percent)
{  
    return set_duty_by_percent(&(servo->hw), percent);
}
