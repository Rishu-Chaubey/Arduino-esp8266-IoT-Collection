
# I2C LCD Display

Interface a 16×2 I2C LCD with Arduino ESP8266 to show text and sensor data using only two wires.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Bill of Materials](#bill-of-materials)
- [Wiring Diagram](#wiring-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Code Walkthrough](#code-walkthrough)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Overview
This project demonstrates how to control a 16×2 character LCD over I2C, reducing GPIO usage and simplifying wiring. You can display fixed messages or dynamic sensor readings.

## Features
- Uses I2C bus (SDA/SCL)  
- Backlight control  
- Simple API: `lcd.setCursor()` and `lcd.print()`  

## Bill of Materials

| Component        | Quantity | Notes                              |
|------------------|----------|------------------------------------|
| 16×2 I2C LCD     | 1        | PCF8574 I2C backpack, address 0x27 |
| Arduino/ESP8266  | 1        | Uno, Nano, or NodeMCU              |
| Jumper wires     | —        | SDA, SCL, VCC, GND                 |
| Potentiometer    | 1        | Contrast adjustment (optional)     |

## Wiring Diagram

| LCD Pin | Function        | Arduino Uno Pin | ESP8266 Pin    |
|---------|-----------------|-----------------|----------------|
| VCC     | Power (5 V/3.3 V)| 5 V (or 3.3 V)  | 3V3            |
| GND     | Ground          | GND             | GND            |
| SDA     | I2C Data        | A4              | D2 (GPIO4)     |
| SCL     | I2C Clock       | A5              | D1 (GPIO5)     |

> **Tip:** If your module’s address differs, run an I2C scanner sketch and update `LiquidCrystal_I2C lcd(address, 16, 2)` accordingly.

## Installation
1. Open `I2C_Display.ino` in Arduino IDE.  
2. Install **LiquidCrystal_I2C** library via Library Manager.  
3. Select your board and port under **Tools → Board/Port**.  
4. Click **Upload**.

## Usage
- On power-up, the sketch initializes the display and prints “Hello, World!”  
- Modify `lcd.print("Your Message")` to show custom text or variables.  
- Use `lcd.clear()` before printing new values in loops.

## Code Walkthrough

### `setup()`
```
lcd.init();        // Initialize the I2C LCD
lcd.backlight();   // Turn on backlight
lcd.setCursor(0, 0);
lcd.print("Hello, World!");
```

### `loop()`
```
lcd.setCursor(0, 1);
lcd.print(millis() / 1000);  // Display uptime in seconds
delay(1000);
lcd.clear();
```

## Troubleshooting

| Symptom                      | Solution                                                |
|------------------------------|---------------------------------------------------------|
| No display or backlight off  | Ensure VCC/GND wiring; call `lcd.backlight()`           |
| I2C address not found        | Scan bus and update the constructor address             |
| Garbled characters           | Adjust contrast potentiometer on the LCD backpack       |

## License
This project is licensed under the MIT License. See [LICENSE](../../LICENSE) for details.
```