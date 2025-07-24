# Sensor Projects

A collection of Arduino and ESP8266 projects demonstrating common sensor interfaces. Each example includes wiring diagrams code explanation, and usage instructions.

## Projects in This Category

### 🌊 Ultrasonic Distance (ESP8266)
**Folder:** `ultrasonic-distance-esp8266/`  
**Difficulty:** Beginner  
**Components:** ESP8266, HC-SR04 ultrasonic sensor  
**Description:** Measure distance and display results on Serial Monitor. Includes voltage-divider wiring for 5V echo signals.

### 📏 Ultrasonic Distance (Arduino)
**Folder:** `ultrasonic-distance-arduino/`  
**Difficulty:** Beginner  
**Components:** Arduino Uno/Nano, HC-SR04 ultrasonic sensor  
**Description:** Basic distance sensing with HC-SR04 and Serial output.

### 🚨 PIR Motion Detector
**Folder:** `pir-motion-detector/`  
**Difficulty:** Beginner  
**Components:** Arduino/ESP8266, PIR motion sensor, LEDs  
**Description:** Detects motion and triggers visual alerts.

## Common Hardware Used

- HC-SR04 Ultrasonic Sensor  
- PIR Motion Sensor (HC-SR501)  
- Connecting wires and breadboard  
- Optional LEDs for status indication  

## Prerequisites

- Familiarity with Arduino IDE  
- Basic understanding of digital and analog I/O  
- Power supply (5V for Arduino, 3.3V for ESP8266)  
- Resistors for level shifting when needed  

## Getting Started

1. Select a project folder.  
2. Review the `README.md` inside that folder for hardware list and wiring.  
3. Connect components according to the provided circuit diagram.  
4. Open the `.ino` file in Arduino IDE.  
5. Choose the correct board and port under **Tools**, then upload.  
6. Open Serial Monitor (baud rate in project README) to see sensor readings.

---

For general setup instructions, see the [Getting Started Guide](../docs/getting-started.md).  
