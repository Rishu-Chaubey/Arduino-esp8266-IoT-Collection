// Define LED pins
int led = D5;  // First LED pin
int led1 = D6; // Second LED pin
int led2 = D7; // Third LED pin

void setup()
{
  // Initialize the LED pins as outputs
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()
{
  // Turn on the first LED
  digitalWrite(led, HIGH);
  delay(1000); // Wait for 1 second

  // Turn off the first LED
  digitalWrite(led, LOW);
  delay(1000); // Wait for 1 second

  // Turn on the second LED
  digitalWrite(led1, HIGH);
  delay(1000); // Wait for 1 second

  // Turn off the second LED
  digitalWrite(led1, LOW);
  delay(1000); // Wait for 1 second

  // Turn on the third LED
  digitalWrite(led2, HIGH);
  delay(1000); // Wait for 1 second

  // Turn off the third LED
  digitalWrite(led2, LOW);
  delay(1000); // Wait for 1 second
}
