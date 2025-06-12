/*
 * GPIO Blink Example for STM32F767ZI Nucleo Board
 * This program demonstrates blinking the onboard LED (connected to PB14, PB0,
 * and PB7) in a sequential manner using GPIO pins. using libopencm3 library.
 */

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

// RGB LEDs connected to GPIOB on Nucleo-F767ZI
// Red LED: PB14, Green LED: PB0, Blue LED: PB7
#define LED_PORT GPIOB
#define LED_PIN_R GPIO14
#define LED_PIN_G GPIO0
#define LED_PIN_B GPIO7

// System clock frequency (216MHz for STM32F767ZI at max configuration)
#define SYSTEM_CLOCK_FREQ 216000000

// Delay function that accepts milliseconds
static void delay(uint32_t milliseconds) {
  // Convert milliseconds to system clock cycles
  // Rough approximation - needs tuning for exact timing
  uint32_t cycles = milliseconds * (SYSTEM_CLOCK_FREQ / 10000);

  while (cycles--) {
    __asm__("nop");
  }
}

int main(void) {
  // Array of RGB LED pins for sequential blinking
  uint16_t leds[3] = {LED_PIN_R, LED_PIN_G, LED_PIN_B};

  // Clock setup for the STM32F767ZI
  // Set the clock to run at 216MHz (max frequency for STM32F767ZI)
  rcc_clock_setup_hse(&rcc_3v3[RCC_CLOCK_3V3_216MHZ], 8);

  // Enable GPIOB clock
  rcc_periph_clock_enable(RCC_GPIOB);

  // Configure RGB LEDs as outputs
  gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN_R);
  gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN_G);
  gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN_B);

  // Main loop: blink all LEDs in sequence
  while (1) {
    // Use for loop to iterate through each RGB LED in the array
    for (int i = 0; i < 3; i++) {
      // Turn on current LED from the array
      gpio_set(LED_PORT, leds[i]);
      delay(1000);  // 1000ms on

      // Turn off current LED
      gpio_clear(LED_PORT, leds[i]);
      delay(1000);  // 1000ms off
    }
  }

  return 0;
}
