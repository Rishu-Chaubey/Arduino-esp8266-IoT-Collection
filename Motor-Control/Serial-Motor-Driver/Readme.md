
# Serial Motor Driver

Control DC motors via serial commands using an Arduino or ESP8266 and a motor module (L298N/L293D).

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
Send single-character commands over Serial (`F`, `B`, `L`, `R`, `S`) to drive two DC motors forward, backward, turn, or stop.

## Features
- Forward/backward motion  
- Left/right turns by stopping one motor  
- Stop command  
- Easy expansion for speed control via PWM

## Bill of Materials

| Component       | Quantity | Notes                           |
|-----------------|----------|---------------------------------|
| Arduino/ESP8266 | 1        | Uno, Nano, NodeMCU, etc.        |
| L298N/L293D     | 1        | Dual H-bridge driver module     |
| DC Motors       | 2        | 3–12 V motors                   |
| Jumper wires    | —        | For wiring between board & driver |
| External 5–12 V power supply | 1 | To power motors (if needed)   |

## Wiring Diagram

| Motor Driver Pin | Function                 | Board Pin   |
|------------------|--------------------------|-------------|
| IN1              | Motor A direction input  | D13         |
| IN2              | Motor A direction input  | D12         |
| IN3              | Motor B direction input  | D11         |
| IN4              | Motor B direction input  | D10         |
| ENA              | Motor A enable (PWM)     | (optional)  |
| ENB              | Motor B enable (PWM)     | (optional)  |
| GND              | Ground (common)          | GND         |
| VCC              | Logic supply (5 V)       | 5 V         |
| Motor A terminals| To DC motor A            | Motor A out |
| Motor B terminals| To DC motor B            | Motor B out |

## Installation
1. Open `motor-driver.ino` in Arduino IDE.  
2. No additional libraries required.  
3. Under **Tools → Board**, select your board and port.  
4. Click **Upload**.

## Usage
1. Open Serial Monitor at **9600 baud**.  
2. Send:
   - `F` to move forward  
   - `B` to move backward  
   - `L` to turn left  
   - `R` to turn right  
   - `S` to stop  

3. Observe motor behavior in response to commands.

## Code Walkthrough

### `setup()`
```
Serial.begin(9600);              // Initialize Serial
pinMode(IN1, OUTPUT);           // Configure motor driver pins
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
```

### `loop()`
```
if (Serial.available() > 0) {
  char cmd = Serial.read();     // Read incoming command
  switch (cmd) {
    case 'F': // Forward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 'B': // Backward
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case 'L': // Left turn
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 'R': // Right turn
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 'S': // Stop
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    default:
      Serial.println("Invalid command.");
  }
}
```

## Troubleshooting

| Symptom                        | Solution                                   |
|--------------------------------|--------------------------------------------|
| Motors do not spin             | Check power supply to driver and motors    |
| Only one motor moves           | Verify IN pins wiring and pin assignments  |
| No serial response             | Ensure Serial Monitor baud rate is 9600    |

## License
This project is licensed under the MIT License. See [LICENSE](../../LICENSE).
```