# Hardware Setup Guide

This guide covers essential hardware setup information, wiring diagrams, pinouts, and hardware notes for Arduino and ESP8266 projects.

---

## Arduino Uno Pinout Reference

The Arduino Uno is the most common board for beginners. Here's a breakdown of its pins:

### Power Pins

- **Vin**: Input voltage (7-12V recommended)
- **5V**: Regulated 5V output (max 500mA when powered via USB)
- **3.3V**: Regulated 3.3V output (max 50mA)
- **GND**: Ground pins (multiple available)

### Digital I/O Pins (0-13)

- **Pins 0-1**: Reserved for USB serial communication (RX/TX)
- **Pins 2-13**: General purpose digital I/O
- **Pins 3, 5, 6, 9, 10, 11**: PWM capable (marked with ~)
- **Pin 13**: Built-in LED

### Analog Input Pins (A0-A5)

- **A0-A5**: Analog input (0-5V range, 10-bit resolution)
- **A4 (SDA)**: I2C data line
- **A5 (SCL)**: I2C clock line

### Communication Pins

- **SPI**: Pins 10 (SS), 11 (MOSI), 12 (MISO), 13 (SCK)
- **I2C**: A4 (SDA), A5 (SCL)

---

## ESP8266 NodeMCU Pinout Reference

The NodeMCU is a popular ESP8266 development board with built-in WiFi.

### GPIO Pin Mapping

| NodeMCU Pin | ESP8266 GPIO | Function    | Notes                     |
| ----------- | ------------ | ----------- | ------------------------- |
| D0          | GPIO16       | Digital I/O | No PWM/interrupt support  |
| D1          | GPIO5        | Digital I/O | Best for general use      |
| D2          | GPIO4        | Digital I/O | Best for general use      |
| D3          | GPIO0        | Digital I/O | Boot mode pin, has pullup |
| D4          | GPIO2        | Digital I/O | Built-in LED, has pullup  |
| D5          | GPIO14       | Digital I/O | SPI Clock (SCLK)          |
| D6          | GPIO12       | Digital I/O | SPI MISO                  |
| D7          | GPIO13       | Digital I/O | SPI MOSI                  |
| D8          | GPIO15       | Digital I/O | SPI CS, has pulldown      |

### Power Pins

- **3V3**: 3.3V output
- **GND**: Ground
- **Vin**: Input voltage (USB or external)

### Boot Mode Pins

- **GPIO0 (D3)**: Must be HIGH for normal boot, LOW for flash mode
- **GPIO2 (D4)**: Must be HIGH during boot
- **GPIO15 (D8)**: Must be LOW during boot

---

## Common Sensor Connections

### DHT11/DHT22 Temperature & Humidity Sensor

**Pinout:**

- Pin 1 (VCC): 3.3V or 5V
- Pin 2 (Data): Digital pin (with 10kΩ pullup resistor)
- Pin 3 (NC): Not connected
- Pin 4 (GND): Ground

**Arduino Wiring:**

```
DHT11 VCC  → Arduino 5V
DHT11 Data → Arduino Pin 2 (+ 10kΩ resistor to VCC)
DHT11 GND  → Arduino GND
```

**ESP8266 Wiring:**

```
DHT11 VCC  → ESP8266 3V3
DHT11 Data → ESP8266 D2 (+ 10kΩ resistor to VCC)
DHT11 GND  → ESP8266 GND
```

### HC-SR04 Ultrasonic Distance Sensor

**Pinout:**

- VCC: 5V power
- Trig: Trigger pin (input)
- Echo: Echo pin (output)
- GND: Ground

**Arduino Wiring:**

```
HC-SR04 VCC  → Arduino 5V
HC-SR04 Trig → Arduino Pin 9
HC-SR04 Echo → Arduino Pin 10
HC-SR04 GND  → Arduino GND
```

**ESP8266 Wiring:**

```
HC-SR04 VCC  → External 5V (or ESP8266 Vin if USB powered)
HC-SR04 Trig → ESP8266 D5
HC-SR04 Echo → ESP8266 D6 (through voltage divider if using 5V)
HC-SR04 GND  → ESP8266 GND
```

### I2C 16x2 LCD Display

**Pinout:**

- VCC: 5V power
- GND: Ground
- SDA: I2C data line
- SCL: I2C clock line

**Arduino Wiring:**

```
LCD VCC → Arduino 5V
LCD GND → Arduino GND
LCD SDA → Arduino A4
LCD SCL → Arduino A5
```

**ESP8266 Wiring:**

```
LCD VCC → ESP8266 3V3 (or external 5V)
LCD GND → ESP8266 GND
LCD SDA → ESP8266 D2 (GPIO4)
LCD SCL → ESP8266 D1 (GPIO5)
```

---

## Voltage Level Considerations

### Important Notes:

- **Arduino Uno**: 5V logic levels
- **ESP8266**: 3.3V logic levels
- **Never connect 5V directly to ESP8266 GPIO pins**

### Voltage Divider for ESP8266

When connecting 5V sensors to ESP8266, use a voltage divider:

```
5V Signal → 10kΩ resistor → ESP8266 GPIO pin
                        ↓
                   6.8kΩ resistor → GND
```

This creates approximately 3.3V output: 5V × (6.8kΩ / 16.8kΩ) ≈ 2.02V

---

## Power Supply Guidelines

### Arduino Uno

- **USB Power**: 5V, up to 500mA
- **External Power**: 7-12V via barrel jack (recommended 9V)
- **Current per Pin**: 20mA recommended, 40mA absolute maximum

### ESP8266

- **Operating Voltage**: 3.3V
- **Peak Current**: Up to 300mA during WiFi transmission
- **Sleep Current**: 20µA in deep sleep mode

---

## Breadboard Setup Tips

1. **Power Rails**: Connect power and ground to breadboard rails
2. **Common Ground**: Always connect all grounds together
3. **Decoupling Capacitors**: Use 100nF capacitors near ICs
4. **Wire Management**: Use different colored wires for different purposes:
   - Red: Power (+)
   - Black: Ground (-)
   - Yellow: Data/Signal
   - Blue: Input signals
   - Green: Output signals

---

## Safety Notes

⚠️ **Important Safety Guidelines:**

- Double-check all connections before applying power
- Never exceed voltage ratings of components
- Use current-limiting resistors for LEDs
- Ensure proper grounding in all circuits
- Disconnect power when making circuit changes
- Check for short circuits with a multimeter
