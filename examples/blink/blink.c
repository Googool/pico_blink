#include "pico/stdlib.h"
#include "pico/blink.h"

const uint led_pin = 25;

int main(void) {
  init_blink(led_pin);
  while (1) {
    blink(led_pin, 1000, 250);
  }
}
