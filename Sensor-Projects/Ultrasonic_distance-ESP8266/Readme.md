# Ultrasonic Distance (ESP8266)

Measure distance using an HC-SR ultrasonic sensor on an ESP8266 NodeMCU and display readings via Serial Monitor.

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
This project uses an HC-SR04 ultrasonic sensor connected to an ESP8266 NodeMCU to measure distance in centimeters. Results are printed on the Serial Monitor.

## Features
- Precise distance measurement from 2 cm to 400 cm  
- Simple Serial output at 9600 baud  
- Easy-to-modify trigger/echo pins  

## Bill of Materials

| Component             | Quantity | Notes                               |
|-----------------------|----------|-------------------------------------|
| ESP8266 NodeMCU       | 1        | 3.3 V logic                         |
| HC-SR04 Ultrasonic    | 1        | Trigger/Echo handling via GPIO      |
| Jumper wires & breadboard | —    | For prototyping                     |

## Wiring Diagram

| HC-SR04 Pin | ESP8266 Pin | Connection Notes           |
|-------------|-------------|----------------------------|
| VCC         | 5 V or VIN  | 5 V power (NodeMCU VIN)    |
| GND         | GND         | Ground                     |
| TRIG        | D1 (GPIO5)  | Trigger pulse output       |
| ECHO        | D2 (GPIO4)  | Echo input (level shift)   |

> **Note:** Use a voltage divider (2 kΩ + 3.3 kΩ) on ECHO if powering sensor from 5 V.

## Installation
1. Open `ULTRASONIC-DISTANCE_ESP8266.ino` in Arduino IDE.  
2. Install **ESP8266 board package** under Boards Manager.  
3. No additional libraries required.  
4. Select **NodeMCU 1.0** under **Tools → Board** and the correct port.  
5. Click **Upload**.

## Usage
1. After upload, open Serial Monitor at **9600 baud**.  
2. Observe distance readings printed as:
   ```
   Distance: XX.X cm
   ```
3. Adjust sensor orientation or mounting as needed.

## Code Walkthrough

### `setup()`
```
Serial.begin(9600);              // Start Serial Monitor
pinMode(trigPin, OUTPUT);       // Trigger pin as output
pinMode(echoPin, INPUT);        // Echo pin as input
```

### `loop()`
```
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

long duration = pulseIn(echoPin, HIGH);            // Measure echo duration
float distanceCm = duration * 0.0343 / 2;          // Convert to cm

Serial.print("Distance: ");
Serial.print(distanceCm, 1);
Serial.println(" cm");
delay(250);
```

## Troubleshooting

| Symptom                        | Solution                                                   |
|--------------------------------|------------------------------------------------------------|
| No readings or “0 cm”          | Check TRIG/ECHO wiring; ensure correct pins in code.       |
| Unstable or fluctuating values | Add `delay(250)` between readings; ensure sensor stable.   |
| “Echo” pin voltage too high    | Add voltage divider on ECHO if sensor powered at 5 V.      |

## License
MIT License — see [LICENSE](../../LICENSE) for details.
```