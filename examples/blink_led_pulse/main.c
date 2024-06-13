#include "pico/stdlib.h"
#include "pico/blink.h"

int main(void) {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink_toggle example requires a board with a regular LED
#else
  const uint LED_PIN = PICO_DEFAULT_LED_PIN;
  init_blink(LED_PIN);
  while (true) {
    blink_led_pulse(LED_PIN, 250);
  }
#endif
  return 0;
}
