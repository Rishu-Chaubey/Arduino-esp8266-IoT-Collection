// Pin declarations
int led = 12;        // LED to turn ON when PIR detects motion
int pir = 13;        // PIR sensor input pin
int redled = 7;      // Red LED to turn ON when no motion detected

void setup() {
  pinMode(led, OUTPUT);      // Set motion LED as output
  pinMode(redled, OUTPUT);   // Set red LED as output
  pinMode(pir, INPUT);       // Set PIR sensor pin as input
}

void loop() {
  // Read PIR sensor value from the input pin (DO NOT reassign 'pir' variable)
  int pirState = digitalRead(pir);

  // If motion detected
  if (pirState == HIGH) {
    digitalWrite(led, HIGH);      // Turn ON motion LED
    digitalWrite(redled, LOW);    // Turn OFF red LED
  }
  // If no motion detected
  else {
    digitalWrite(led, LOW);       // Turn OFF motion LED
    digitalWrite(redled, HIGH);   // Turn ON red LED
  }
  
  delay(150);  // Small delay to stabilize loop
}
