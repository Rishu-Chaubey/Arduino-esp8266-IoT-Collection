#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);  // Attach servo to pin 9
}

void loop() {
  // Sweep from 0 to 180 degrees in 10-degree steps
  for (int angle = 0; angle <= 180; angle += 10) {
    myServo.write(angle);
    delay(100);  // Wait for servo to reach the position
  }

  // Sweep back from 180 to 0 degrees in 10-degree steps
  for (int angle = 180; angle >= 0; angle -= 10) {
    myServo.write(angle);
    delay(100);  // Wait for servo to reach the position
  }
}
