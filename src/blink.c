#include "pico/blink.h"

void init_blink(uint gpio_pin) {
  gpio_init(gpio_pin);
  gpio_set_dir(gpio_pin, GPIO_OUT);
}

void blink_toggle(uint pin) {
  gpio_put(pin, !gpio_get_out_level(pin));
}

void blink_led(uint pin, uint delay_ms) {
  gpio_put(pin, 1);
  sleep_ms(delay_ms);
  gpio_put(pin, 0);
  sleep_ms(delay_ms);
}

void blink_led_times(uint pin, uint delay_ms, uint times) {
  for (uint i = 0; i < times; i++) {
    gpio_put(pin, 1);
    sleep_ms(delay_ms);
    gpio_put(pin, 0);
    sleep_ms(delay_ms);
  }
}

void blink_pulsate(uint pin, uint pulse_duration_ms) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_init(slice_num, &config, true);

    for (int i = 0; i < pulse_duration_ms * 1000; i += 10) {
      pwm_set_gpio_level(pin, i % 256);
      sleep_us(10);
    }
}

void blink_variable_speed(uint pin, uint min_delay_ms, uint max_delay_ms, uint step_ms) {
  for (uint delay = min_delay_ms; delay <= max_delay_ms; delay += step_ms) {
    gpio_put(pin, 1);
    sleep_ms(delay);
    gpio_put(pin, 0);
    sleep_ms(delay);
  }
  for (uint delay = max_delay_ms; delay >= min_delay_ms; delay -= step_ms) {
    gpio_put(pin, 1);
    sleep_ms(delay);
    gpio_put(pin, 0);
    sleep_ms(delay);
  }
}
