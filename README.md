# STM32 Embedded Development Project

This is an embedded systems development project based on STM32 microcontrollers, using the libopencm3 open-source firmware framework. The project includes development environment setup, example programs, and demonstration applications, designed for educational purposes and rapid development of STM32 applications.

## Project Structure

The project consists of the following main components:

```
.
├── Dockerfile                 # Development environment container definition
├── libopencm3-template/       # libopencm3 project template
│   ├── libopencm3/            # libopencm3 library
│   ├── my-common-code/        # Shared code
│   └── my-project/            # Project template
└── nucleo-f767zi/             # Nucleo-F767ZI development board examples
    └── gpio-blink/            # LED blinking demonstration
```

## Development Environment

This project provides a Docker containerized environment to ensure all developers use a unified and complete toolchain. The container includes:

- ARM GCC toolchain (gcc-arm-none-eabi)
- GDB multi-architecture debugging tool (gdb-multiarch)
- ST-Link tools (stlink-tools)
- OpenOCD open-source debugger
- Python 3 environment and tools

### Building the stm32-libopencm3 Docker Image

To build the development environment with a specific name that references the libopencm3 framework:

1. Build the Docker image with the specified name:
   ```bash
   docker build -t stm32-libopencm3 .
   ```

2. Verify the image was created successfully:
   ```bash
   docker images | grep stm32-libopencm3
   ```

3. Run the container with the new image name:
   ```bash
   docker run -it --rm --privileged -v $(pwd):/workspace stm32-libopencm3
   ```

This named image helps distinguish your STM32 libopencm3 development environment from other Docker containers on your system.

## Example Projects

### Nucleo-F767ZI GPIO LED Blinking Example

Located in the `nucleo-f767zi/gpio-blink/` directory, this example demonstrates how to:

- Configure the STM32F767ZI system clock
- Set up GPIO output mode
- Control the onboard RGB LED in a cycling pattern

#### Compiling and Flashing the Example

1. Compile the example project:
   ```bash
   cd nucleo-f767zi/gpio-blink
   make
   ```

2. Flash to the development board:
   ```bash
   make flash
   ```

## Custom Project Development

To create a new project based on the libopencm3 template:

1. Copy the template directory:
   ```bash
   cp -r libopencm3-template/my-project my-new-project
   ```

2. Modify `my-new-project/Makefile` to set the project name and target device

3. Write your code and compile:
   ```bash
   cd my-new-project
   make
   ```

## Related Resources

- [libopencm3 Official Documentation](https://libopencm3.org/docs/latest/)
- [STM32F7 Reference Manual](https://www.st.com/resource/en/reference_manual/dm00305990-stm32f76xxx-and-stm32f77xxx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)
- [Nucleo-F767ZI Development Board User Manual](https://www.st.com/resource/en/user_manual/dm00244518-stm32-nucleo144-boards-stmicroelectronics.pdf)