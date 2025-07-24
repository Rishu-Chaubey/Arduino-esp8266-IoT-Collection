
# IR Controlled RGB LEDs

Use an IR remote to change RGB LED colors and monitor soil moisture with ESP8266 NodeMCU.

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
This project lets you cycle through preset RGB LED colors using IR remote buttons. It also reads soil moisture levels and prints them to Serial Monitor.

## Features
- Decode IR commands to set LED color  
- Predefined color mappings for 3 IR codes  
- Soil moisture sensor reading on A0  
- Serial output of decoded IR values and moisture percentage  

## Bill of Materials

| Component              | Quantity | Notes                             |
|------------------------|----------|-----------------------------------|
| ESP8266 NodeMCU        | 1        | 3.3 V logic                       |
| IR Receiver Module     | 1        | VS1838B or similar                |
| Common-anode RGB LED   | 1        | 3 × 220 Ω resistors               |
| Soil Moisture Sensor   | 1        | Analog output                     |
| Breadboard & jumper wires | —     | —                                 |

## Wiring Diagram

| Component            | Signal Pin        | NodeMCU Pin    |
|----------------------|-------------------|----------------|
| IR Receiver OUT      | OUT               | D1 (GPIO5)     |
| RGB LED Red Anode    | R through 220 Ω   | D2 (GPIO4)     |
| RGB LED Green Anode  | G through 220 Ω   | D3 (GPIO0)     |
| RGB LED Blue Anode   | B through 220 Ω   | D4 (GPIO2)     |
| Soil Moisture SIG    | Analog out        | A0             |
| GND                  | –                 | GND            |
| VCC                  | –                 | 3V3            |

## Installation
1. Open `ir_transmitter_receiver.ino` in Arduino IDE.  
2. Install **IRremote** library via Library Manager.  
3. Select **NodeMCU 1.0** under **Tools → Board**, and correct COM port.  
4. Click **Upload**.

## Usage
1. Point your IR remote at the receiver and press one of the mapped buttons.  
2. Watch the RGB LED change color according to the IR code:  
   - `0xF30CBF00` → Blue  
   - `0xEF10BF00` → Red  
   - `0xEE11BF00` → Green  
3. Open Serial Monitor at **9600 baud** to view raw IR codes and soil moisture readings.

## Code Walkthrough

### `setup()`
```
irrecv.enableIRIn();          // Start IR receiver
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
Serial.begin(9600);
```

### `loop()`
```
if (irrecv.decode(&results)) {
  unsigned long code = results.value;
  Serial.println(code, HEX);
  irrecv.resume();

  // Set RGB LED based on code
  if (code == 0xF30CBF00) setColor(0,0,255);
  else if (code == 0xEF10BF00) setColor(255,0,0);
  else if (code == 0xEE11BF00) setColor(0,255,0);

  // Read and print soil moisture
  int moisture = analogRead(A0);
  Serial.print("Soil Moisture: ");
  Serial.println(moisture);
}
```

#### Helper: `setColor(r,g,b)`
```
digitalWrite(redPin,   (r>0));
digitalWrite(greenPin, (g>0));
digitalWrite(bluePin,  (b>0));
```

## Troubleshooting

| Symptom                       | Solution                                           |
|-------------------------------|----------------------------------------------------|
| No IR code printed            | Check IR receiver orientation; verify library init |
| LED color not matching button | Confirm mapping in code matches your remote codes  |
| Moisture reading stuck at 0   | Ensure sensor powered and in contact with soil     |

## License
MIT License — see [LICENSE](../../LICENSE)
```