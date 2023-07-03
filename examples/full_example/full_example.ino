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
