// Define the LED pin
int led = D6;  // Using pin D6 for the LED

void setup() {
  pinMode(led, OUTPUT);  // Set the LED pin as an OUTPUT
}

void loop() {
  digitalWrite(led, HIGH);   // Turn the LED ON
  delay(1000);               // Wait for 1 second (1000 milliseconds)
  
  digitalWrite(led, LOW);    // Turn the LED OFF
  delay(1000);               // Wait for 1 second
}
