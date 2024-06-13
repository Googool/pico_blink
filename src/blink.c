#include "pico/blink.h"

void init_blink(uint gpio_pin) {
  gpio_init(gpio_pin);
  gpio_set_dir(gpio_pin, GPIO_OUT);
}

void blink_toggle(uint pin) {
  gpio_put(pin, !gpio_get_out_level(pin));
}

void blink_led(uint pin, uint delay_ms) {
  blink_toggle(pin);
  sleep_ms(delay_ms);
}

void blink_led_pulse(uint pin, uint pulse_duration_ms) {
  gpio_set_function(pin, GPIO_FUNC_PWM);
  uint slice_num = pwm_gpio_to_slice_num(pin);

  pwm_config config = pwm_get_default_config();
  pwm_config_set_clkdiv(&config, 4.0f);
  pwm_config_set_wrap(&config, 65535);
  pwm_init(slice_num, &config, true);

  uint step_size = 129;
  uint delay_us = 5000;

  for (uint duty_cycle = 0; duty_cycle < 65536; duty_cycle += step_size) {
    pwm_set_gpio_level(pin, duty_cycle);
    sleep_us(delay_us);
  }

  for (int duty_cycle = 65535; duty_cycle >= 0; duty_cycle -= step_size) {
    pwm_set_gpio_level(pin, duty_cycle);
    sleep_us(delay_us);
  }
}
