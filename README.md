# Navigador - DC Motor Navigation Library

<p align="center">
    <img src="assets/mini-l293d-module.jfif" width="300" />
    <br/>
    <i>L293D module is the most recommended DC motor driver to be used with Navigador.</i>
</p>

The Navigador Arduino library provides a convenient way to control the movement of a mobile robot or vehicle using an Arduino board. It allows you to easily control the robot's movement in various directions and define predefined paths for it to follow. This library is designed to work with Arduino boards and provides an intuitive interface for controlling motors and managing robot behavior.

## Features

The Navigador Arduino library offers a range of features to facilitate the control and navigation of mobile robots or vehicles. Here are the key features provided by the library:

- **Directional Movement**: Control the movement of the robot in various directions, including forward, backward, left, and right. The library provides simple and intuitive methods for initiating these movements, allowing you to easily maneuver your robot.

- **Duration Control**: Specify the duration for which the robot should perform a specific movement. This feature enables precise control over the robot's movement, allowing you to set the exact duration for forward, backward, left, or right movements.

- **Predefined Paths**: Define and follow predefined paths for the robot to navigate autonomously. The library allows you to add custom paths that consist of a sequence of movements, specifying the direction and duration for each step. The robot can then autonomously follow these paths, making it ideal for tasks requiring predefined routes.

- **Path Management**: The library provides methods to add and remove predefined paths dynamically. This allows you to modify and adapt the robot's navigation strategy on the fly, adding or removing paths as needed during runtime.

- **Stop Control**: Instantly stop the robot's movement at any time using the stop() method. This feature ensures quick and precise control over the robot's motion, allowing you to halt its movement immediately when necessary.

- **Flexible Motor Configuration**: The library supports flexible motor configurations, allowing you to define the Arduino pin assignments for controlling the motors. This flexibility enables compatibility with various motor driver configurations and simplifies integration with different robot platforms.

These features make the Navigador Arduino library a powerful tool for controlling and navigating mobile robots or vehicles using Arduino, providing simplicity, flexibility, and precise control over the robot's movements.

## Installation

To use the Navigador library in your Arduino sketches, follow the steps below:

1. Download the Navigador library by clicking [here](https://github.com/nthnn/Navigador).
2. Extract the downloaded ZIP file.
3. Move the extracted folder to the Arduino libraries directory. The location of this directory depends on your operating system:
    - **Windows**: `Documents/Arduino/libraries`
    - **Mac**: `~/Documents/Arduino/libraries`
    - **Linux**: `~/Arduino/libraries`
4. Rename the extracted folder to `Navigador` (if necessary).

You can now include the Navigador library in your sketches, after carefully following the steps. If you are unfamiliar with installing Arduino libraries, you can refer to the official Arduino guide on how to install a library.

**Note**: The Navigador is also available on the PlaformIO's registry.

**Note**: If you prefer to install the library manually, you can simply copy the Navigador folder (from the extracted ZIP) into the libraries directory mentioned above.

## Usage

To use the Navigador library in your Arduino sketch, you need to include the library and create an instance of the Navigador class. Here's a basic example:

```cpp
#include <navigador.h>

// Motor pins for L293D module
#define MOTOR1A_PIN 2
#define MOTOR1B_PIN 3
#define MOTOR2A_PIN 4
#define MOTOR2B_PIN 5

Navigador navigator(MOTOR1A_PIN, MOTOR1B_PIN, MOTOR2A_PIN, MOTOR2B_PIN);

void setup() {
  // Add paths to navigate
  NavigadorPath path1 = {NAVIGADOR_FORWARD_DIRECTION, 1000}; // Forward for 1 second
  NavigadorPath path2 = {NAVIGADOR_LEFT_DIRECTION, 500};     // Left for 0.5 seconds

  navigator.add_path(path1);
  navigator.add_path(path2);

  // Start following the path
  navigator.follow_path();

  // Remove a specific path
  NavigadorPath path_to_remove = {NAVIGADOR_LEFT_DIRECTION, 500}; // left for 0.5 seconds
  navigator.remove_path(path_to_remove);

  // Follow it again without the removed path
  navigator.follow_path();
}

void loop() {
  // Other code in the loop if needed
}
```

For more details on the available methods and their usage, please refer to the [library reference](docs/reference.md).

## Compatibility

The Navigador library is compatible with Arduino boards and has been tested on popular boards like Arduino Uno, Arduino Mega, and Arduino Nano. It should also work with other Arduino-compatible boards.

Please ensure that you have the latest version of the Arduino IDE installed and that your board is properly configured before using the Navigador library.

## Dependencies

The Navigador library has the following dependencies:

- [List.hpp](https://github.com/nkaaf/Arduino-List): The Navigador library utilizes the List data structure for managing predefined paths. Make sure you have the List library installed. You can find it on GitHub.

Please make sure to install the dependencies before using the Navigador library to avoid any compilation errors.

## Troubleshooting

If you encounter any issues during the installation or usage of the Navigador library, consider the following troubleshooting steps:

- **Verify Library Installation**: Ensure that the Navigador library is installed in the correct location within your Arduino libraries directory.

- **Check Dependencies**: Double-check that you have installed the required dependencies, the List.hpp library.

- **Library Version**: Make sure you are using the latest version of the Navigador library. Check the [library's GitHub repository](https://github.com/nthnn/Navigador) for any updates or bug fixes.

- **Hardware Connections**: Confirm that your hardware connections are accurate and properly configured according to your specific robot or vehicle setup.

If you still encounter issues, feel free to open an issue on the GitHub repository with detailed information about the problem.

## License

Copyright 2023 - Nathanne Isip

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

```THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.```