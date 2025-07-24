# Motor Control Projects

This category contains Arduino and ESP8266 examples for controlling DC motors and servos. Each project wiring diagrams, code explanations, and usage instructions.

## Projects in This Category

### ⚙️ Serial Motor Driver  
**Folder:** `serial-motor-driver/`  
**Difficulty:** Beginner  
**Components:** Arduino/ESP8266, Motor driver (L298N or similar), DC motor  
**Description:** Control motor direction via serial commands (‘F’, ‘B’, ‘L’, ‘R’, ‘S’). Ideal for basic robotics.

### 🤖 Servo Controller  
**Folder:** `servo-controller/`  
**Difficulty:** Beginner  
**Components:** Arduino/ESP8266, Servo motor, Power supply  
**Description:** Sweep a servo between positions or set angle via serial or code. Useful for actuators and robotics arms.

## Common Hardware Used

- L298N or L293D motor driver modules  
- DC motors (3–12 V)  
- Hobby servos (SG90, MG90S)  
- External power supply (if motor current exceeds board limits)  
- Jumper wires and breadboard

## Prerequisites

- Familiarity with Arduino IDE and serial monitor  
- Understanding of PWM signals for speed control  
- Proper power budgeting for motors (use external supplies when needed)  
- Knowledge of basic wiring for motor drivers

## Wiring Overview

1. **Serial Motor Driver**:  
   - Connect IN1–IN4 pins to Arduino/ESP8266 digital outputs.  
   - Driver EN pins to PWM-capable pins for speed control (optional).  
   - Motor outputs to DC motors; external supply to driver V<sub>IN</sub> and GND common.

2. **Servo Controller**:  
   - Connect servo signal wire to defined PWM pin.  
   - Power servo from 5 V (external if needed) and share GND with microcontroller.

Refer to each project’s README for detailed pin mappings and diagrams.

## Getting Started

1. Navigate to the project folder (e.g., `motor-control/serial-motor-driver/`).  
2. Open the `*.ino` sketch in Arduino IDE.  
3. Select the appropriate board and port under **Tools**.  
4. Upload the code.  
5. Use Serial Monitor (baud rate specified in sketch) or hardware buttons to control motors.  

For general setup, see [Getting Started](../docs/getting-started.md) and [Hardware Setup](../docs/hardware-setup.md).
