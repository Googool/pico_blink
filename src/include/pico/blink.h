#ifndef BLINK_H
#define BLINK_H

#include "pico/stdlib.h"

void init_blink(uint gpio_pin);
void blink(uint gpio_pin, uint32_t on_time_ms, uint32_t off_time_ms);

#endif /* BLINK_H */
