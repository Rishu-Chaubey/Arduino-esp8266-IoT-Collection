# Getting Started

Welcome! This guide will help you set up your Arduino and ESP8266 projects quickly.

## 1. Install Arduino IDE

Download and install the Arduino IDE from:
[https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

## 2. Add ESP8266 Board

- Open Arduino IDE.
- Go to **File → Preferences**.
- In "Additional Boards Manager URLs", add:
http://arduino.esp8266.com/stable/package_esp8266com_index.json
- Click **OK**.
- Go to **Tools → Board → Boards Manager**.
- Search for **esp8266** and install **ESP8266 by ESP8266 Community**.

## 3. Install Libraries

In Arduino IDE:

- Go to **Sketch → Include Library → Manage Libraries**.
- Search and install libraries your projects need, like:
- ESP8266WiFi
- DHT sensor library
- LiquidCrystal I2C

## 4. Connect Your Device

- Connect your Arduino or ESP8266 board to your computer.
- Follow wiring instructions in each project’s README.

## 5. Upload Code

- Open the project `.ino` file in Arduino IDE.
- Select the correct board and port under **Tools**.
- Click the **Upload** button.
- Use Serial Monitor to watch output if needed (**Tools → Serial Monitor**).

Enjoy building your projects! For help, see the troubleshooting guide.  
