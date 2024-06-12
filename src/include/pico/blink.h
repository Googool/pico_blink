#ifndef BLINK_H
#define BLINK_H

#include "pico/stdlib.h"

void init_blink(uint gpio_pin);
void blink(uint gpio_pin, uint32_t on_time_ms, uint32_t off_time_ms);
void blink_n_times(uint gpio_pin, uint32_t on_time_ms, uint32_t off_time_ms, uint32_t n);
void blink_faster_slower(uint gpio_pin, uint32_t start_time_ms, uint32_t end_time_ms, uint32_t increment, uint32_t decrement);

#endif /* BLINK_H */
