
# Gas Sensor Alarm with Servo Gate

Detect and respond to gas concentration levels using an MQ-2 sensor, LCD display, LED indicator, and servo motor on Arduino or ESP8266.

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
This project monitors gas levels via an MQ-2 sensor (analog A0). When gas concentration exceeds defined thresholds, it:
1. Displays the ADC value on a 16×2 I2C LCD  
2. Illuminates a red LED as an alert  
3. Activates a servo arm to close or open a gate  

## Features
- Real-time gas level reading (0–1023 ADC)  
- Threshold alerts: low, medium, high  
- Visual feedback on LCD and LED  
- Servo-driven mechanical response  

## Bill of Materials

| Component             | Qty | Notes                         |
|-----------------------|-----|-------------------------------|
| Arduino Uno or ESP8266| 1   | NodeMCU for Wi-Fi capability  |
| MQ-2 Gas Sensor       | 1   | Analog output on A0           |
| 16×2 I2C LCD Module   | 1   | I2C address 0x27              |
| Red LED               | 1   | Alert indicator (with 220 Ω)  |
| SG90 Servo Motor      | 1   | Controlled by D5 (or D8)      |
| 220 Ω Resistor        | 1   | For LED                       |
| Breadboard & Wires    | —   | Prototyping                   |

## Wiring Diagram

| Sensor / Device      | Signal Pin      | Board Pin        |
|----------------------|-----------------|------------------|
| MQ-2 Analog Output   | A0              | A0               |
| LCD SDA              | SDA             | A4 (Uno) / D2    |
| LCD SCL              | SCL             | A5 (Uno) / D1    |
| Red LED Anode        | —               | Pin 7            |
| Red LED Cathode      | —               | GND              |
| Servo Signal         | —               | Pin D5 (ESP) / 9 |
| Servo VCC/GND        | VCC / GND       | 5 V / GND        |

## Installation
1. Open `gas_sensor_project.ino` in Arduino IDE.  
2. Install libraries: `LiquidCrystal_I2C`, `Servo`.  
3. Select board and port under **Tools**.  
4. Click **Upload**.

## Usage
- After uploading, open Serial Monitor at **9600 baud** to view live ADC values.  
- The LCD displays “G: [value]”.  
- When `value < 85`, LED and servo alert active; between 85–800 LED off, servo resets.

## Code Walkthrough

### `setup()`
```
pinMode(gasSensorPin, INPUT);
pinMode(redLedPin, OUTPUT);
servo.attach(servoPin);
lcd.init(); lcd.backlight();
```

### `loop()`
```
int gasValue = analogRead(gasSensorPin);
lcd.clear(); lcd.setCursor(0,0);
lcd.print("G:"); lcd.print(gasValue);
if (gasValue < 85) {
  digitalWrite(redLedPin, HIGH);
  servo.write(90);
} else {
  digitalWrite(redLedPin, LOW);
  servo.write(0);
}
delay(1000);
```

## Troubleshooting

| Symptom                      | Solution                                           |
|------------------------------|----------------------------------------------------|
| LCD shows no value           | Check I2C address with scanner; update if needed  |
| ADC readings volatile        | Ensure sensor warm-up (24 h burn-in)               |
| Servo jittering              | Provide stable 5 V supply and common ground        |

## License
This project is licensed under the MIT License. See [LICENSE](../../LICENSE).  
