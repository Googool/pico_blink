#include "pico/blink.h"

void init_blink(uint gpio_pin) {
  gpio_init(gpio_pin);
  gpio_set_dir(gpio_pin, GPIO_OUT);
}

void blink(uint gpio_pin, uint32_t on_time_ms, uint32_t off_time_ms) {
  gpio_put(gpio_pin, 1);
  sleep_ms(on_time_ms);
  gpio_put(gpio_pin, 0);
  sleep_ms(off_time_ms);
}
