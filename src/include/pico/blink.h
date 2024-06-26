#ifndef BLINK_H
#define BLINK_H

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

void init_blink(uint gpio_pin);
void blink_toggle(uint pin);
void blink_led(uint pin, uint delay_ms);
void blink_pulse(uint pin, uint pulse_duration_ms);

#endif // BLINK_H
