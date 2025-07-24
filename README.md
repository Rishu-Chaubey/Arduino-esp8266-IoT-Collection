# Arduino & ESP8266 IoT Circuitry Collection

A comprehensive collection of Arduino and ESP8266 projects designed for both beginners and professionals. Each project includes detailed documentation, circuit diagrams, and step-by-step instructions.

## 🚀 Quick Start

### For Beginners

1. Start with [Getting Started Guide](docs/getting-started.md)
2. Check out [Basic/)
3. Follow the [Installation Guide](docs/installation-guide.md)

### For Professionals

- Jump directly to specific project categories
- All projects include technical specifications
- Advanced integration examples available

## 📁 Project Categories

### 🌐 IoT Projects

- **WiFi LED Controller** - Control LEDs via web interface
- **Multi-sensor Monitoring** - Complete IoT monitoring with ThingSpeak
- **Gas Sensor Project** - Gas detection with alerts
- **IR Controlled RGB** - Remote control RGB LED system

### 🔍 Sensor Projects

- **Ultrasonic Distance (ESP8266)** - Distance measurement with visual feedback
- **Ultrasonic Distance (Arduino)** - Basic distance sensing
- **PIR Motion Detector** - Motion detection with LED indicators

### ⚙️ Motor Control

- **Serial Motor Driver** - Control motors via serial commands
- **Servo Controller** - Precise servo motor control

### 📺 Display Projects

- **I2C LCD Display** - Basic LCD display control

### 💡 Basic Examples

- **ESP8266 LED Blink** - Your first ESP8266 project

## 🛠️ Hardware Requirements

| Component                   | Used In Projects         | Purpose                        |
| --------------------------- | ------------------------ | ------------------------------ |
| ESP8266 NodeMCU             | IoT Projects             | WiFi-enabled microcontroller   |
| Arduino Uno                 | Sensor Projects          | Basic microcontroller platform |
| Ultrasonic Sensor (HC-SR04) | Distance Projects        | Distance measurement           |
| DHT11/DHT22                 | Environmental Monitoring | Temperature & humidity         |
| PIR Sensor                  | Motion Detection         | Motion sensing                 |
| Servo Motor                 | Motor Control            | Precise positioning            |
| LEDs & Resistors            | Multiple Projects        | Visual indicators              |

📚 Documentation
Comprehensive guides to help you set up your hardware, install necessary tools, and troubleshoot common issues:

Getting Started (docs/Getting-Started.md)
Stepby-step instructions for installing the Arduino IDE, adding ESP8266 board support, and uploading your first sketch.

Installation Guide (docs/Installation-guide.md)
Detailed walkthrough of IDE configuration, library installation, and driver setup for Windows, macOS, and Linux.

Hardware Setup (docs/Hardware.md)
Pinout diagrams for Arduino Uno/Nano and ESP8266 NodeMCU, wiring schematics for common sensors (DHT11, HC-SR04, PIR), and power-supply recommendations.

Troubleshooting (docs/Troubleshooting.md)
Solutions for upload errors, Wi-Fi connectivity issues, sensor read failures, and general debugging tips.

📦 Resources
A centralized collection of datasheets, libraries, and external references to support all projects:

Component Datasheets (resources/component-datasheets/)
PDF datasheets for all sensors, modules, and ICs used across projects, including DHT11, HC-SR04, MQ-2, PCF8574, L298N, and more.

Libraries (resources/libraries/)
Custom or version-locked Arduino libraries not available via Library Manager (e.g., specific LiquidCrystal_I2C forks, bespoke sensor drivers).

Useful Links (resources/useful-links.md)
Curated list of external tutorials, official documentation, forum threads, and tool references:

Arduino Official Documentation
https://docs.arduino.cc/

ESP8266 Arduino Core on GitHub
https://github.com/esp8266/Arduino

ThingSpeak API Documentation
https://thingspeak.com/docs

LiquidCrystal_I2C Library
https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

Random Nerd Tutorials
https://randomnerdtutorials.com/

## 🤝 Contributing

We welcome contributions! Please feel free to submit pull requests, report bugs, or suggest improvements.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## ⭐ Getting Help

If you encounter any issues:

1. Check the [troubleshooting guide](docs/troubleshooting.md)
2. Review project-specific README files
3. Open an issue in this repository

---

**Happy making! Explore, modify, and learn by building these diverse Arduino and ESP8266 projects.**
