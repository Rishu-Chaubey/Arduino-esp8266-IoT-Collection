# WiFi LED Controller

Control multiple LEDs from any browser using an ESP8266-based web server.

 📋 Table of Contents
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
This project lets you toggle three LEDs connected to an ESP8266 NodeMCU via a simple web interface. A basic HTML page is served by the board; clicking “ON”/“OFF” links sends HTTP GET requests to switch the LEDs.

## Features
- Self-hosted web server on port 80  
- REST endpoints: `/ledon` and `/ledoff`  
- Real-time browser control without external cloud  
- Easy-to-read HTML interface  

## Bill of Materials

| Component         | Quantity | Notes                         |
|-------------------|----------|-------------------------------|
| ESP8266 NodeMCU   | 1        | Built-in WiFi                 |
| LEDs (any color)  | 3        | With 220 Ω resistors          |
| Breadboard & wires| —        | For prototyping               |

## Wiring Diagram

| NodeMCU Pin | LED         | Connection   |
|-------------|-------------|--------------|
| D5          | LED 1 Anode | 220 Ω → LED  |
| D6          | LED 2 Anode | 220 Ω → LED  |
| D7          | LED 3 Anode | 220 Ω → LED  |
| GND         | LED Cathodes| Direct       |

*(Cathode legs of all LEDs tied to GND.)*

## Installation

1. Open `wifi-led-controller.ino` in Arduino IDE.  
2. Install **ESP8266 board package** and libraries (**ESP8266WiFi**).  
3. Update `ssid` and `password` in the sketch.  
4. Select **NodeMCU 1.0** under **Tools → Board** and your COM port.  
5. Click **Upload**.

## Usage

1. Open Serial Monitor at **115200 baud** to see the assigned IP.  
2. In your browser, go to `http:///`.  
3. Click **Turn LEDs ON** or **Turn LEDs OFF** to control all three LEDs.

## Code Walkthrough

### `setup()`
```
WiFi.begin(ssid, password);      // Connect to WiFi
server.begin();                  // Start HTTP server
pinMode(ledPin1, OUTPUT);        // Configure LED pins
…
```

### `loop()`
```
WiFiClient client = server.available();       // Wait for client
if (client) readRequestAndToggleLEDs(client); // Parse GET and switch LEDs
sendHtmlResponse(client);                     // Return control page
```

## Troubleshooting

| Issue                                  | Solution                                          |
|----------------------------------------|---------------------------------------------------|
| Web page fails to load                 | Verify SSID/password; ensure 2.4 GHz network      |
| LEDs do not respond                    | Check resistor orientation and pin assignments    |
| Serial Monitor shows garbage characters| Set baud rate to **115200**                       |

## License
This project is licensed under the MIT License. See [LICENSE](../../LICENSE) for details.
```