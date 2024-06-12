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

void blink_n_times(uint gpio_pin, uint32_t on_time_ms, uint32_t off_time_ms, uint32_t n) {
  for (uint32_t i = 0; i < n; i++) {
    blink(gpio_pin, on_time_ms, off_time_ms);
  }
}

void blink_faster_slower(uint gpio_pin, uint32_t start_time_ms, uint32_t end_time_ms, uint32_t increment, uint32_t decrement) {
  uint32_t time_ms = start_time_ms;

  while (time_ms > end_time_ms) {
    blink(gpio_pin, time_ms, time_ms);
    if (time_ms > end_time_ms + increment) {
      time_ms -= increment;
    } else {
      time_ms = end_time_ms;
    }
  }

  while (time_ms < start_time_ms) {
    blink(gpio_pin, time_ms, time_ms);
    if (time_ms < start_time_ms - decrement) {
      time_ms += decrement;
    } else {
      time_ms = start_time_ms;
    }
  }
}
