int trigPin = 13;    // Trigger pin for ultrasonic sensor
int echoPin = 12;    // Echo pin for ultrasonic sensor

long duration;       // Variable to store duration of echo pulse
long cm;             // Calculated distance in centimeters

void setup() {
  Serial.begin(9600);        // Initialize serial communication at 9600 baud
  pinMode(trigPin, OUTPUT);  // Set trigPin as an output
  pinMode(echoPin, INPUT);   // Set echoPin as an input
}

void loop() {
  digitalWrite(trigPin, LOW);   // Clear the trigger pin
  delay(5);                     // Wait 5 milliseconds for sensor stability

  digitalWrite(trigPin, HIGH);  // Send a 10 microsecond HIGH pulse to trigger the sensor
  delay(10);                    // Wait for 10 microseconds
  
  digitalWrite(trigPin, LOW);   // Stop sending the pulse
  
  pinMode(echoPin, INPUT);      // Ensure echoPin is set as input (redundant but kept)
  
  duration = pulseIn(echoPin, HIGH); // Read the echo pulse duration in microseconds
  
  cm = (duration / 2) * 0.0343;       // Calculate distance in cm (speed of sound approx. 343 m/s)
  
  Serial.print(cm);              // Print the distance value
  Serial.print(" cm");           // Print units
  Serial.println();             // New line for next measurement
  
  delay(250);                   // Wait 250 milliseconds before next reading
}
