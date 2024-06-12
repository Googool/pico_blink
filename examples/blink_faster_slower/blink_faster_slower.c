#include "pico/stdlib.h"
#include "pico/blink.h"

const uint led_pin = 25;

int main(void) {
  init_blink(led_pin);
  while (1) {
    blink_faster_slower(led_pin, 1000, 100, 100, 100);
  }

  return 0;
}
