# Servo Controller

Control a standard hobby servo’s position using Arduino or ESP8266. Sweep between angles or set positions.

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
This sketch demonstrates how to attach a servo motor to a PWM-capable pin and command it to move to specified angles in your code.

## Features
- Sweep servo from 0° to 180° and back  
- Use `myServo.write(angle)` to set custom positions  
- Delay tuning for smooth or rapid motion  

## Bill of Materials

| Component         | Quantity | Notes                       |
|-------------------|----------|-----------------------------|
| Arduino/ESP8266   | 1        | Uno, Nano, or NodeMCU       |
| SG90 Hobby Servo  | 1        | 5 V power; share common GND |
| Jumper wires      | —        | Signal and power wiring     |
| External 5 V supply (optional) | 1 | For stable servo operation  |

## Wiring Diagram

| Servo Wire    | Connection             |
|---------------|------------------------|
| Signal (orange)| PWM pin (e.g., D9)     |
| VCC (red)     | 5 V (or 3.3 V if supported) |
| GND (brown)   | Common ground (GND)    |

## Installation
1. Open `Servo-Controller.ino` in Arduino IDE.  
2. Ensure the **Servo** library is installed (built-in).  
3. Select your board and COM port under **Tools** → **Board** / **Port**.  
4. Click **Upload**.

## Usage
- The code will sweep the servo from 0° to 180° in 10° increments, then back in 10° steps.  
- Adjust the step size (`angle += 10`) and `delay(100)` for speed control.  
- To set a fixed position, replace the loop logic with `myServo.write();`.

## Code Walkthrough

### `setup()`
```
myServo.attach(9);    // Attach servo signal to pin 9
```

### `loop()`
```
// Sweep up
for(int angle = 0; angle = 0; angle -= 10) {
  myServo.write(angle);
  delay(100);
}
```

## Troubleshooting

| Symptom                   | Solution                                                     |
|---------------------------|--------------------------------------------------------------|
| Servo jitters or stalls   | Provide stable 5 V supply; use external power if needed      |
| Range not full 0–180°     | Calibrate by testing limits and adjust min/max writes        |
| No movement               | Verify signal pin matches `attach()` argument                |

## License
This project is licensed under the MIT License. See [LICENSE](../../LICENSE) for details.
```