# GPIO Blink Example Project

This is a GPIO LED blinking example for the STM32F767ZI Nucleo development board, developed using the libopencm3 framework.

## Project Overview

This example makes the RGB LEDs (Red: PB14, Green: PB0, Blue: PB7) on the Nucleo-F767ZI board blink in a sequential pattern. It demonstrates how to:

- Set up the STM32F767ZI microcontroller clock to run at 216MHz
- Configure multiple GPIO pins as output mode
- Control sequential LED blinking using simple timing delays

## Building and Flashing

### Prerequisites

- ARM GCC toolchain installed
- OpenOCD installed
- ST-Link tools installed (`st-flash` utility)
- libopencm3 installed at `/opt/libopencm3`

### Build Steps

1. Ensure libopencm3 is properly installed at `/opt/libopencm3`

2. Compile this project:
   ```
   make
   ```

3. Flash the project to the board:
   ```
   make flash
   ```

   This uses the `st-flash` utility to write the binary to the board at address 0x8000000 and then reset the MCU.

### Alternative Flashing Methods

You can also use OpenOCD for flashing if you prefer:

```
openocd -f board/st_nucleo_f7.cfg -c "program bin/gpio-blink.elf verify reset exit"
```

The `st-flash` utility is required from the [stlink tools](https://github.com/stlink-org/stlink) package.

## Hardware Connections

No additional wiring is needed, as the RGB LEDs on the Nucleo-F767ZI board are already connected:
- Red LED: Connected to PB14
- Green LED: Connected to PB0
- Blue LED: Connected to PB7

## References

- [libopencm3 Documentation](https://libopencm3.org/docs/latest/stm32f7/)
- [STM32F767ZI Reference Manual](https://www.st.com/resource/en/reference_manual/dm00224583.pdf)
- [Nucleo-F767ZI User Manual](https://www.st.com/resource/en/user_manual/dm00244518.pdf)
