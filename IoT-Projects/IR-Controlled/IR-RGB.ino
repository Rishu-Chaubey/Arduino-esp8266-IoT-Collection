/*
  IR Remote Controlled RGB LEDs
  -----------------------------
  Uses IRremote library to decode IR commands and control three LEDs:
  - Blue LED on pin 13
  - Red LED on pin 11
  - Green LED on pin 12

  When certain IR codes are received:
  - 0xF30CBF00 turns on blue LED only
  - 0xEF10BF00 turns on red LED only
  - (You can add more codes for green or other colors)
*/

#include <IRremote.h>             // Include IRremote library

// Pin Definitions
const int RECV_PIN = 9;           // IR receiver connected to digital pin 9
const int bluePin = 13;           // Blue LED pin
const int redPin = 11;            // Red LED pin
const int greenPin = 12;          // Green LED pin

// IR Receiver object
IRrecv irrecv(RECV_PIN);
decode_results results;           // Object to store decoded IR data

void setup() {
  Serial.begin(9600);             // Initialize serial for debugging

  // Initialize LED pins as outputs
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Turn all LEDs off at start
  digitalWrite(bluePin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);

  // Start the IR receiver
  irrecv.enableIRIn();
}

void loop() {
  // Check if an IR code has been received
  if (irrecv.decode(&results)) {
    unsigned long value = results.value;  // Store received IR code

    // Print the received code to Serial Monitor in HEX format
    Serial.print("Received IR code: 0x");
    Serial.println(value, HEX);

    // Compare received IR code with predefined actions
    if (value == 0xF30CBF00) {         // Example: Blue LED code
      digitalWrite(bluePin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
    }
    else if (value == 0xEF10BF00) {    // Example: Red LED code
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
    }
    // You can add more else if statements for other codes and LEDs
    // Example:
    // else if (value == 0xEE11BF00) {  // Green LED code
    //   digitalWrite(bluePin, LOW);
    //   digitalWrite(redPin, LOW);
    //   digitalWrite(greenPin, HIGH);
    // }

    // Prepare to receive the next IR code
    irrecv.resume();
  }

  delay(100); // Short delay to avoid flooding Serial output
}
