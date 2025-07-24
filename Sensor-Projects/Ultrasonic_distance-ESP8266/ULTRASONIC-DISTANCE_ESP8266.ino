// Ultrasonic Distance Sensor with Traffic Light LEDs
// Controls red, green, and yellow LEDs based on measured distance (cm)

int redPin = D2;    // Red LED pin
int greenPin = D3;  // Green LED pin
int yellowPin = D4; // Yellow LED pin

int trigPin = D1; // Ultrasonic sensor Trigger pin
int echoPin = D0; // Ultrasonic sensor Echo pin

long duration;
float distanceCm;

void setup()
{
  Serial.begin(9600);

  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);

  // Initially turn off all LEDs
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
}

void loop()
{
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distanceCm = (duration / 2.0) * 0.0343;

  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // LED logic based on distance ranges
  if (distanceCm >= 2 && distanceCm <= 75)
  {
    // Close distance: Red LED ON, others OFF
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
  }
  else if (distanceCm > 75 && distanceCm <= 150)
  {
    // Medium distance: Green LED ON, others OFF
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
  }
  else if (distanceCm > 150 && distanceCm <= 250)
  {
    // Far distance: Yellow LED ON, others OFF
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
  }
  else
  {
    // Out of range or no object: turn off all LEDs
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
  }

  delay(2000); // Wait before next measurement to reduce noise
}
