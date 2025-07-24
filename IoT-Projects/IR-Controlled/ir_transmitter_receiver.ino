// IR Remote Receiver with LED Indicator
// Uses IRremote library to decode IR signals and control an LED

#include <IRremote.h>

// --- Pin Definitions ---
const int irReceiverPin = 11;  // IR receiver connected to digital pin 11
const int redLedPin = 8;       // Red LED connected to digital pin 8

// --- IR Receiver Setup ---
IRrecv irrecv(irReceiverPin);  // Create IR receiver object on pin 11
decode_results results;        // Variable to store IR decode results

void setup() {
  Serial.begin(9600);          // Initialize serial communication for debug output

  irrecv.enableIRIn();         // Start the IR receiver

  pinMode(redLedPin, OUTPUT);  // Set LED pin as output
  digitalWrite(redLedPin, LOW);// Initialize LED to off
}

void loop() {
  if (irrecv.decode(&results)) {          // Check if IR data has been received
    unsigned long value = results.value;  // Get the decoded IR raw data

    Serial.print("IR Code received (HEX): ");
    Serial.println(value, HEX);            // Print the code in hexadecimal format

    irrecv.resume();                      // Prepare to receive the next value

    // Turn off LED before checking code
    digitalWrite(redLedPin, LOW);

    // Compare received IR code with known hex values
    if (value == 0xF30CBF00 || value == 0xEF10BF00 || value == 0xEE11BF00) {
      digitalWrite(redLedPin, HIGH);     // Turn on LED if code matches any known code
      delay(1000);                       // Keep LED on for 1 second
    } else {
      digitalWrite(redLedPin, LOW);      // Turn off LED if code does not match
      delay(1000);                       // Wait for 1 second
    }
  }
}
