// Gas Sensor with Servo and LCD Display
// Reads gas sensor analog value and shows status on LCD,
// controls a red LED and has a servo motor attached.

// Include necessary libraries
#include <LiquidCrystal_I2C.h>  // I2C LCD library
#include <Servo.h>              // Servo motor library

// Create Servo and LCD object
Servo si;
LiquidCrystal_I2C lcd(0x27, 16, 2);   // LCD address 0x27, 16 cols, 2 rows

// Pin definitions
const int gasSensorPin = A0;           // Gas sensor analog pin
const int redLedPin = 7;               // Red LED digital pin
const int servoPin = 5;                // Servo PWM pin

void setup() {
  Serial.begin(9600);
  
  // Attach servo to its pin
  si.attach(servoPin);
  
  // Setup pins
  pinMode(gasSensorPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  
  // Initialize LCD display
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Read gas sensor analog value
  int gasValue = analogRead(gasSensorPin);

  // Print the gas sensor value to Serial Monitor
  Serial.println(gasValue);

  // Short delay to stabilize reading
  delay(500);

  // Logic based on gas sensor readings
  if (gasValue < 85) {
    // Gas level very high: danger!
    lcd.setCursor(0, 0);
    lcd.print("Gas Detected!    ");  // Clear leftover chars by padding with spaces
    lcd.setCursor(0, 1);
    lcd.print("Value: ");
    lcd.print(gasValue);
    lcd.print("    ");
    
    digitalWrite(redLedPin, HIGH);    // Turn on red LED
    
    // Optionally move servo to a warning position
    si.write(90);                     // Example: rotate servo to 90 degrees
    
    delay(1000);
    
    lcd.clear();
  }
  else if (gasValue >= 85 && gasValue <= 800) {
    // Moderate gas level detected
    lcd.setCursor(0, 0);
    lcd.print("Gas Detected!    ");
    lcd.setCursor(0, 1);
    lcd.print("Value: ");
    lcd.print(gasValue);
    lcd.print("    ");
    
    digitalWrite(redLedPin, LOW);     // Turn off red LED
    
    // Optionally reset servo position
    si.write(0);                      // Example: rotate servo back to 0 degrees
    
    delay(1000);
    
    lcd.clear();
  }
  else {
    // Gas value is outside considered range: treat as safe/no gas
    lcd.setCursor(0, 0);
    lcd.print("Gas Level Safe  ");
    lcd.setCursor(0, 1);
    lcd.print("Value: ");
    lcd.print(gasValue);
    lcd.print("    ");

    digitalWrite(redLedPin, LOW);     // Ensure LED is off
    
    // Set servo to default position
    si.write(0);
    
    delay(1000);
    
    lcd.clear();
  }
}
