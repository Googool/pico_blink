#ifndef BLINK_H
#define BLINK_H

#include "pico/stdlib.h"

void blink_toggle(uint pin);
void blink_led(uint pin, uint delay_ms);
void blink_led_times(uint pin, uint delay_ms, uint times);
void blink_pulsate(uint pin, uint pulse_duration_ms);
void blink_variable_speed(uint pin, uint min_delay_ms, uint max_delay_ms, uint step_ms);

#endif // BLINK_H
