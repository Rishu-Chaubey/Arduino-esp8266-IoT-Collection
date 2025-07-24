# Basic Examples

A set of simple starter sketches ideal for beginners to verify hardware setup and learn fundamental Arduino/ESP6 concepts.

## Included Examples

### ⚡ ESP8266 LED Blink  
**Folder:** `esp8266-led-blink/`  
**Difficulty:** Very Beginner  
**Components:** ESP8266 board, LED, 220 Ω resistor  
**Description:** Blink an LED connected to D6 to confirm board functionality and learn basic `setup()`/`loop()` structure.

## How to Use

1. Open the `esp8266-led-blink.ino` sketch in Arduino IDE.  
2. Ensure you have the ESP8266 board package installed (see [Getting Started Guide](../docs/getting-started.md)).  
3. Connect an LED (with 220 Ω resistor) to pin D6 and GND.  
4. Select your ESP8266 board and port under **Tools → Board** and **Tools → Port**.  
5. Click **Upload**, then observe the LED blinking on and off every second.  

## Customization

- Change the blink interval by modifying the `delay()` durations.  
- Try blinking multiple LEDs by extending the code.

---

For detailed setup instructions, see the [Getting Started Guide](../docs/getting-started.md) and [Hardware Setup](../docs/hardware-setup.md).  
