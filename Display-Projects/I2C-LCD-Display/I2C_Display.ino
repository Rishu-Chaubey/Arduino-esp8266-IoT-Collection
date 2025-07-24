#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address 0x27, 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();        // Initialize the LCD
  lcd.backlight();   // Turn on the LCD backlight
}

void loop() {
  lcd.setCursor(0, 0);            // Set cursor to column 0, row 0
  lcd.print("Your Message");      // Print your message on the LCD
  
  delay(1000);                   // Wait for 1 second before refreshing (optional)
  
  // Optional: clear the display if you want to refresh the message
  // lcd.clear();
}
