# Navigador - Library Reference

The Navigador library consists of a single class named Navigador and several supporting structures and enumerations. The class provides methods for controlling the movement of a mobile robot, defining movement paths, and managing the robot's behavior.

## Navigador Class

The Navigador class is the main class of the library, representing a mobile robot or vehicle. It provides methods for controlling the robot's movement and defining movement paths.

### Navigador Constructor

```cpp
Navigador(uint16_t motor_1a, uint16_t motor_1b, uint16_t motor_2a, uint16_t motor_2b)
```

- **Description**: Constructs a new instance of the Navigador class.
- **Parameters**:
    * `motor_1a`: The Arduino pin number connected to motor 1A.
    * `motor_1b`: The Arduino pin number connected to motor 1B.
    * `motor_2a`: The Arduino pin number connected to motor 2A.
    * `motor_2b`: The Arduino pin number connected to motor 2B.

### Methods

```cpp
void forward()
```

**Description**: Moves the robot forward.

---

```cpp
void backward()
```

**Description**: Moves the robot backward.

---

```cpp
void left()
```

**Description**: Turns the robot to the left.

---

```cpp
void right()
```

**Description**: Turns the robot to the right.

---

```cpp
void forward(unsigned long travel_duration)
```

- **Description**: Moves the robot forward for a specified duration.
- **Parameters**:
    * `travel_duration`: The duration in milliseconds for which the robot should move forward.

---

```cpp
void backward(unsigned long travel_duration)
```

- **Description**: Moves the robot backward for a specified duration.
- **Parameters**:
    * `travel_duration`: The duration in milliseconds for which the robot should move backward.

---

```cpp
void left(unsigned long travel_duration)
```

- **Description**: Turns the robot to the left for a specified duration.
- **Parameters**:
    * `travel_duration`: The duration in milliseconds for which the robot should turn left.

---

```cpp
void right(unsigned long travel_duration)
```

- **Description**: Turns the robot to the right for a specified duration.
- **Parameters**:
    * `travel_duration`: The duration in milliseconds for which the robot should turn right.

---

```cpp
void add_path(NavigadorPath path)
```

- **Description**: Adds a path to the list of predefined paths for the robot to follow.
- **Parameters**:
    * `path`: A NavigadorPath structure representing the path to be added.

---

```cpp
void remove_path(NavigadorPath path)
```

- **Description**: Removes a path from the list of predefined paths.
- **Parameters**:
    * `path`: A NavigadorPath structure representing the path to be removed.

---

```cpp
void follow_path()
```

- **Description**: Makes the robot follow the predefined paths sequentially.

---

```cpp
void clear_path()
```

- **Description**: Clears the list of predefined paths.

---

```cpp
void stop()
```

- **Description**: Stops the robot's movement.

## NavigadorDirection Enumeration

The NavigadorDirection enumeration defines the possible directions of movement for the robot. It is used in the NavigadorPath structure.

```cpp
enum NavigadorDirection {
    NAVIGADOR_FORWARD_DIRECTION,
    NAVIGADOR_BACKWARD_DIRECTION,
    NAVIGADOR_LEFT_DIRECTION,
    NAVIGADOR_RIGHT_DIRECTION,
};
```

- `NAVIGADOR_FORWARD_DIRECTION`: Indicates forward movement.
- `NAVIGADOR_BACKWARD_DIRECTION`: Indicates backward movement.
- `NAVIGADOR_LEFT_DIRECTION`: Indicates left turn.
- `NAVIGADOR_RIGHT_DIRECTION`: Indicates right turn.

## NavigadorPathStruct Structure

The NavigadorPathStruct structure represents a movement path for the robot. It contains information about the direction of movement and the duration of travel.

```cpp
struct NavigadorPathStruct {
    uint8_t direction;
    unsigned long travel_duration;
};
```

- `direction`: An integer representing the direction of movement (see NavigadorDirection enumeration).
- `travel_duration`: The duration in milliseconds for which the robot should travel in the specified direction.

**Note:** It is recommended to use the typedef NavigadorPath instead of directly using the NavigadorPathStruct structure.