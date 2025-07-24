# PIR Motion Detector

Detect motion using a PIR sensor and indicate status with LEDs on Arduino or ESP6.

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
This project uses a PIR (Passive Infrared) sensor to detect movement. When motion is detected, a green LED lights; when idle, a red LED lights.

## Features
- Digital motion detection  
- Dual-LED status indication  
- Instant response upon detection  

## Bill of Materials

| Component          | Quantity | Notes                        |
|--------------------|----------|------------------------------|
| Arduino Uno/Nano or ESP8266 NodeMCU | 1 | Microcontroller               |
| PIR Motion Sensor (HC-SR501) | 1 | Digital out                   |
| Green LED           | 1 | With 220 Ω resistor          |
| Red LED             | 1 | With 220 Ω resistor          |
| Breadboard & jumper wires | — | For prototyping              |

## Wiring Diagram

| Sensor / LED        | Signal Pin        | Board Pin        |
|---------------------|-------------------|------------------|
| PIR OUT             | OUT               | D2 (Arduino) / D5 (NodeMCU) |
| Green LED Anode     | —                 | D3 (Arduino) / D6 (NodeMCU) |
| Red LED Anode       | —                 | D4 (Arduino) / D7 (NodeMCU) |
| All Cathodes        | —                 | GND              |

*(Use 220 Ω resistors in series with each LED.)*

## Installation
1. Open `Pir-motion-detector.ino` in Arduino IDE.  
2. No additional libraries required.  
3. Select your board and COM port under **Tools**.  
4. Click **Upload**.

## Usage
- After uploading, the green LED lights when motion is detected; the red LED lights when no motion.  
- Observe the Serial Monitor (optional) for debug prints if added.

## Code Walkthrough

### `setup()`

```
pinMode(pirPin, INPUT);         // PIR sensor input
pinMode(greenLedPin, OUTPUT);   // Green LED output
pinMode(redLedPin, OUTPUT);     // Red LED output
```

### `loop()`

```
int motion = digitalRead(pirPin);  
if (motion == HIGH) {
  digitalWrite(greenLedPin, HIGH);  
  digitalWrite(redLedPin, LOW);
} else {
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, HIGH);
}
delay(150);
```

## Troubleshooting

| Symptom                     | Solution                                        |
|-----------------------------|-------------------------------------------------|
| No LED response             | Check PIR orientation and wait for sensor warm-up (≈30 s) |
| LEDs flicker rapidly        | Adjust PIR sensitivity/pulse time potentiometers |
| Always HIGH output          | Cover PIR lens and retest in dark to calibrate  |

## License
MIT License — see [LICENSE](../../LICENSE) for details.
