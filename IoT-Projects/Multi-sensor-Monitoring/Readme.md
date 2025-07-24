# Multi-Sensor Monitoring (ThingSpeak)

Measure IR detection, gas level, and temperature; results on a 16×2 I2C LCD and upload data to ThingSpeak.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Bill of Materials](#bill-of-materials)
- [Wiring Summary](#wiring-summary)
- [ThingSpeak Setup](#thingspeak-setup)
- [Installation](#installation)
- [Usage](#usage)
- [Code Walkthrough](#code-walkthrough)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Overview
This project integrates three sensors on an ESP8266 NodeMCU:
- IR obstacle detection (digital on D4)  
- MQ‐2 gas concentration (analog on A0)  
- DHT11 temperature (digital on D3)  
Data is displayed locally on an I2C LCD and pushed to ThingSpeak every 20 s.

## Features
- Obstacle detection with IR sensor  
- Gas level measurement (0–1023 analog)  
- Temperature reading in °C  
- Local display on 16×2 I2C LCD  
- Cloud data logging via ThingSpeak (3 fields)  
- Servo alert (optional) for threshold breaches  

## Bill of Materials

| Component              | Quantity | Notes                         |
|------------------------|----------|-------------------------------|
| ESP8266 NodeMCU        | 1        | 3.3 V logic                   |
| IR sensor module       | 1        | Digital output on D4          |
| MQ-2 gas sensor        | 1        | Analog output on A0           |
| DHT11 sensor           | 1        | 10 kΩ pull-up on data pin     |
| 16×2 I2C LCD module    | 1        | I2C address 0x27              |
| SG90 servo (optional)  | 1        | Control on D5 for alerts      |
| Breadboard & jumper wires | —     | For prototyping               |

## Wiring Summary

| Sensor/Device | Signal Pin | NodeMCU Pin |
|---------------|------------|-------------|
| IR OUT        | D4         | D4          |
| Gas AOUT      | A0         | A0          |
| DHT11 DATA    | –          | D3          |
| LCD SDA       | SDA        | D2 (GPIO4)  |
| LCD SCL       | SCL        | D1 (GPIO5)  |
| Servo SIG     | –          | D5          |
| LCD VCC/GND   | VCC/GND    | 3V3/GND     |

## ThingSpeak Setup
1. Create a new channel at ThingSpeak.com.  
2. Note **Channel ID** and **Write API Key**.  
3. Update `myChannelNumber` and `myWriteAPIKey` in the sketch.

## Installation
1. Open `Esp_Project.ino` (or `humidity_temp_ir.ino`) in Arduino IDE.  
2. Install libraries: `ESP8266WiFi`, `ThingSpeak`, `LiquidCrystal_I2C`, `DHT`.  
3. Edit Wi-Fi SSID/PASSWORD and ThingSpeak credentials in code.  
4. Select **NodeMCU 1.0** under **Tools → Board**, and correct COM port.  
5. Click **Upload**.

## Usage
- After upload, open Serial Monitor at **9600 baud** to view logs.  
- The LCD shows live readings; data posts to ThingSpeak every 20 s.  
- (Optional) Attach a servo on D5 to activate on high gas or IR detection.

## Code Walkthrough

### `setup()`
```
WiFi.begin(ssid, pass);           // Connect to Wi-Fi
dht.begin();                      // Initialize DHT11
lcd.init(); lcd.backlight();      // Initialize LCD
ThingSpeak.begin(client);         // Start ThingSpeak
```

### `loop()`
```
int irVal = digitalRead(IR_SENSOR_PIN);
int gasVal = analogRead(GAS_SENSOR_PIN);
float temp  = dht.readTemperature();

lcd.clear();
lcd.setCursor(0,0);
lcd.print("T:"); lcd.print(temp);
lcd.setCursor(10,0);
lcd.print("IR:"); lcd.print(irVal);
lcd.setCursor(0,1);
lcd.print("G:"); lcd.print(gasVal);

ThingSpeak.setField(1, irVal);
ThingSpeak.setField(2, gasVal);
ThingSpeak.setField(3, temp);
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
delay(20000);
```

## Troubleshooting

| Symptom                                  | Solution                                               |
|------------------------------------------|--------------------------------------------------------|
| LCD shows garbled text                   | Check I2C address; scan bus and update address if needed|
| `nan` temperature/humidity               | Ensure pull-up on DHT11 data line; power cycle sensor   |
| ThingSpeak HTTP 401/404 errors           | Verify API Key and Channel ID                          |
| IR not detecting                          | Confirm IR sensor orientation and ambient IR filters   |

## License
MIT License — see [LICENSE](../../LICENSE) for details.
```