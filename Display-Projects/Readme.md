# Display Projects

A collection of Arduino and ESP8266 examples demonstrating how to interface with displays such as I2 LCDs and OLEDs. Each project includes wiring diagrams, code explanations, and usage instructions.

## Projects in This Category

### 📺 I2C LCD Display  
**Folder:** `i2c-lcd-display/`  
**Difficulty:** Beginner  
**Components:** Arduino/ESP8266, I2C 16×2 LCD module, pull-up resistors (if needed)  
**Description:** Display text and sensor data on a 16×2 LCD over I2C, minimizing pin usage.

*(Future Projects: Add OLED display examples here)*

## Common Hardware Used

- I2C 16×2 LCD modules (often with PCF8574 backpack)  
- Optional OLED displays (SSD1306)  
- Jumper wires and breadboard  
- Potentiometer for LCD contrast adjustment  

## Prerequisites

- Arduino IDE with LiquidCrystal_I2C library installed  
- Basic understanding of I2C protocol and pull-up resistors  
- Shared ground between microcontroller and display  

## Wiring Overview

1. Connect **VCC** to 5 V (or 3.3 V if supported).  
2. Connect **GND** to ground.  
3. Connect **SDA** and **SCL** to microcontroller I2C pins (e.g., A4/A5 on Uno, D2/D1 on NodeMCU).  
4. Adjust contrast via potentiometer on the I2C backpack.

Refer to each project’s README for exact pin mappings and example code.

## Getting Started

1. Navigate to `display-projects/i2c-lcd-display/`.  
2. Open `i2c-lcd-display.ino` in Arduino IDE.  
3. Select the correct board and port under **Tools**.  
4. Upload the sketch and observe the displayed message.  
5. Modify `lcd.print()` statements to display your own data.

For general setup, see [Getting Started](../docs/getting-started.md) and [Hardware Setup](../docs/hardware-setup.md).  
