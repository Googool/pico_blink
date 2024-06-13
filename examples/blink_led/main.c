#include "pico/stdlib.h"
#include "pico/blink.h"

/**
 * The blink_led and blink_toggle examples perform the same function.
 * Both examples are redundant.
 */

int main(void) {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink_led example requires a board with a regular LED
#else
  const uint LED_PIN = PICO_DEFAULT_LED_PIN;
  init_blink(LED_PIN);
  while (true) {
    blink_led(LED_PIN, 250);
  }
#endif
  return 0;
}
