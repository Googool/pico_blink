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
    pwm_init(slice_num, &config, true);

    uint step_size = 10;

    for (uint i = 0; i <= 255; ++i) {
        pwm_set_gpio_level(pin, i);
        sleep_us(step_size);
    }

    for (int i = 255; i >= 0; --i) {
        pwm_set_gpio_level(pin, i);
        sleep_us(step_size);
    }
}
