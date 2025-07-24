# Installation Guide

This guide details how to set up the libraries, dependencies, and toolchains needed to work with the projects in this repository.

---

## 1. Setting Up the Arduino IDE

- Download the latest version from the [Arduino Official Website](https://www.arduino.cc/en/software).
- Install following on-screen instructions for your operating system (Windows, macOS, Linux).

---

## 2. Installing Board Packages

### A. Arduino Boards (Uno, Nano, etc.)

- Arduino IDE comes with official Arduino board support pre-installed.

### B. ESP8266 Boards

1. Open **Arduino IDE**.
2. Go to **File → Preferences**.
3. In the "Additional Boards Manager URLs" field, add:

http://arduino.esp8266.com/stable/package_esp8266com_index.json

4. Click **OK**.
5. Go to **Tools → Board → Boards Manager**.
6. Search for `esp8266` and click **Install** under "ESP8266 by ESP8266 Community".

---

## 3. Installing Required Libraries

Many projects require extra libraries. Use the **Library Manager** in Arduino IDE for most:

1. Go to **Sketch → Include Library → Manage Libraries...**
2. Search by name and click **Install**.

### Common Libraries

| Library Name       | Description             | Installation Method        |
| ------------------ | ----------------------- | -------------------------- |
| ESP8266WiFi        | WiFi support on ESP8266 | Built into ESP8266 package |
| DHT sensor library | DHT11/22 temp/humidity  | Library Manager            |
| LiquidCrystal_I2C  | I2C LCD support         | Library Manager            |
| Servo              | Servo motor control     | Library Manager            |

Check the README of each project for extra libraries (e.g., Adafruit_Sensor, ThingSpeak, IRremote) and repeat above steps.

---

## 4. Installing Toolchains and Drivers

### A. USB Drivers

For most boards (Uno, Nano, NodeMCU), your computer may auto-install drivers. If not:

- **Arduino Uno/Nano**: Download drivers from Arduino website.
- **ESP8266 NodeMCU/Wemos D1 Mini**: Some require the [CP210x](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) or [CH340](https://sparks.gogo.co.nz/ch340.html) driver.

Make sure the correct USB port appears in **Tools → Port** after installing drivers.

### B. PlatformIO (Optional Advanced Toolchain)

- Install [VS Code](https://code.visualstudio.com/download).
- Add the [PlatformIO extension](https://platformio.org/install/ide?install=vscode).
- PlatformIO will handle hardware support and libraries automatically via the `platformio.ini` file in each project directory.

---

## 5. Verifying Installation

- Open Arduino IDE.
- Go to **Tools → Board** and select your hardware board.
- Open an example sketch (e.g., File → Examples → 01.Basics → Blink).
- Upload to the board and confirm it runs.

---

## 6. Troubleshooting

See the [troubleshooting guide](troubleshooting.md) if you have upload, library, or connection issues.

---

**Your development environment is now ready. Continue with wiring your projects and uploading your sketches!**
