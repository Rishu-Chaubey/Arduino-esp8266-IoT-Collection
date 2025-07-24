# Ultrasonic Distance (Arduino)

Measure distance using an HC-SR04 ultrasonic sensor an Arduino Uno or Nano and display readings via Serial Monitor.

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
This project uses an HC-SR04 ultrasonic sensor connected to an Arduino board to measure distance in centimeters. Results are printed on the Serial Monitor.

## Features
- Accurate distance measurement from 2 cm to 400 cm  
- Simple Serial output at 9600 baud  
- Easily adaptable trigger/echo pins  

## Bill of Materials

| Component             | Quantity | Notes                           |
|-----------------------|----------|---------------------------------|
| Arduino Uno or Nano   | 1        | 5 V logic                       |
| HC-SR04 Ultrasonic    | 1        | VCC=5 V, echo needs no divider  |
| Jumper wires & breadboard | —    | For prototyping                 |

## Wiring Diagram

| HC-SR04 Pin | Arduino Pin | Connection Notes             |
|-------------|-------------|------------------------------|
| VCC         | 5 V          | Power                        |
| GND         | GND         | Ground                       |
| TRIG        | 13          | Trigger pulse output         |
| ECHO        | 12          | Echo input                   |

## Installation
1. Open `Ultrasonic.ino` in Arduino IDE.  
2. No extra libraries required.  
3. Under **Tools → Board**, select your Arduino model and the correct COM port.  
4. Click **Upload**.

## Usage
1. After upload, open Serial Monitor at **9600 baud**.  
2. Distance readings will appear as:
   ```
   123.4 cm
   ```
3. Adjust sensor mounting as needed for stable readings.

## Code Walkthrough

### `setup()`
```
Serial.begin(9600);         // Start Serial Monitor
pinMode(trigPin, OUTPUT);  // Trigger pin as output
pinMode(echoPin, INPUT);   // Echo pin as input
```

### `loop()`
```
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

long duration = pulseIn(echoPin, HIGH);            // Measure echo duration
float distanceCm = (duration * 0.0343) / 2;         // Convert to cm

Serial.print(distanceCm, 1);
Serial.println(" cm");
delay(250);
```

## Troubleshooting

| Symptom                        | Solution                                                    |
|--------------------------------|-------------------------------------------------------------|
| No readings or “0 cm”          | Verify TRIG/ECHO wiring and pin assignments in code.        |
| Fluctuating values             | Ensure sensor is stable; add delay between measurements.    |

## License
MIT License — see [LICENSE](../../LICENSE) for details.
```