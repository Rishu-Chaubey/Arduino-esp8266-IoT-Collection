// Motor Control via Serial Commands
// Controls motor driver input pins IN1 to IN4 based on serial commands:
// 'F' - Forward, 'B' - Backward, 'R' - Right turn, 'L' - Left turn, 'S' - Stop

int IN1 = 13;  // Motor 1 input pin 1
int IN2 = 12;  // Motor 1 input pin 2
int IN3 = 11;  // Motor 2 input pin 1
int IN4 = 10;  // Motor 2 input pin 2

char val;      // Variable to store received serial character

void setup() {
  Serial.begin(9600);         // Initialize serial communication at 9600 baud

  // Set motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Check if a serial command is available
  if (Serial.available() > 0) {
    val = Serial.read();          // Read the incoming character
    Serial.println(val);          // Echo the received character for debugging

    // Execute motor control based on received command
    switch (val) {
      case 'F':  // Move Forward
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break;

      case 'B':  // Move Backward
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;

      case 'R':  // Turn Right (both pins HIGH on left motor, off on right)
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;

      case 'L':  // Turn Left (both pins HIGH on right motor, off on left)
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
        break;

      case 'S':  // Stop all motors
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;

      default:   // Invalid command handling
        Serial.println("Invalid command.");
        break;
    }

    delay(200);  // Small delay for command processing stability (optional)
  }
}
