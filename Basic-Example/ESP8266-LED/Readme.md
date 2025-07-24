
# ESP8266 LED Blink

A minimal starter sketch to verify your ESP8266 NodeU setup by blinking the onboard (or external) LED.

## 📋 Table of Contents
- [Overview](#overview)
- [Bill of Materials](#bill-of-materials)
- [Wiring](#wiring)
- [Installation](#installation)
- [Usage](#usage)
- [Code Walkthrough](#code-walkthrough)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Overview
This sketch toggles an LED on pin D6 every second. Use it to confirm your board, USB connection, and pin mappings are correct before moving on to more complex projects.

## Bill of Materials

| Component         | Quantity | Notes                           |
|-------------------|----------|---------------------------------|
| ESP8266 NodeMCU   | 1        | Any ESP8266 development board   |
| LED (optional)    | 1        | Onboard LED if present, or external LED with resistor |
| 220 Ω resistor    | 1        | Required if using external LED |
| Jumper wires      | —        | For external LED connection     |

## Wiring
- Onboard LED: No wiring required.  
- External LED:  
  - Connect LED anode to D6  
  - Connect LED cathode to one end of 220 Ω resistor  
  - Connect other end of resistor to GND  

## Installation
1. Open `esp8266-led-blink.ino` in Arduino IDE.  
2. Ensure **ESP8266 board package** is installed (see Getting Started Guide).  
3. Under **Tools → Board**, select your ESP8266 model.  
4. Under **Tools → Port**, select the correct COM port.  
5. Click **Upload**.

## Usage
- After uploading, the LED will turn ON for 1 second, then OFF for 1 second in a continuous loop.  
- Modify the `delay(1000)` values in the code to change the blink interval.

## Code Walkthrough

```
void setup() {
  pinMode(D6, OUTPUT);        // Configure D6 as output for the LED
}

void loop() {
  digitalWrite(D6, HIGH);     // Turn LED on
  delay(1000);                // Wait 1 second
  digitalWrite(D6, LOW);      // Turn LED off
  delay(1000);                // Wait 1 second
}
```

- **`setup()`** runs once: sets D6 as an output pin.  
- **`loop()`** runs repeatedly: toggles the LED state with 1 s delays.

## Troubleshooting

| Symptom                    | Solution                                      |
|----------------------------|-----------------------------------------------|
| LED does not blink         | Verify board selection and COM port in IDE.   |
| External LED stays off     | Check resistor and LED polarity wiring.       |
| Upload fails               | Ensure correct USB driver and cable are used. |

## License
This project is licensed under the MIT License. See [LICENSE](../../LICENSE) for details.  
```