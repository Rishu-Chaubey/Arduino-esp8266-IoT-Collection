# Troubleshooting Guide

This guide covers common problems and their solutions for Arduino and ESP8266 projects.

---

## Upload Errors

### "Failed uploading: no upload port provided"

**Symptoms:** Upload fails immediately with no port error.

**Solutions:**

1. **Check Board and Port Selection:**

   - Go to Tools → Board and select correct board
   - Go to Tools → Port and select correct COM port
   - In Arduino IDE 2.x: Use board selector dropdown

2. **Board Not Detected:**

   - Try different USB cable (must be data cable, not charging-only)
   - Try different USB port
   - Restart Arduino IDE
   - Restart computer

3. **Driver Issues:**
   - Install CH340/CP2102 drivers for ESP8266 boards
   - Install FTDI drivers for Arduino Nano (old version)

### "esptool.py fatal error" (ESP8266)

**Symptoms:** ESP8266 upload fails with timeout or connection error.

**Solutions:**

1. **Hold Flash Button Method:**

   - Hold FLASH button on ESP8266 during upload
   - Hold FLASH, press RESET, release RESET, release FLASH
   - Try upload immediately after this sequence

2. **Check Upload Settings:**

   - Board: NodeMCU 1.0 (ESP-12E Module)
   - Upload Speed: 115200 (try 9600 if problems persist)
   - Flash Size: 4MB (3M FS: 1M OTA)
   - CPU Frequency: 80MHz

3. **Hardware Check:**
   - Ensure stable power supply
   - Check USB cable quality
   - Try different computer/USB port

### "avrdude: stk500_recv(): programmer is not responding"

**Symptoms:** Arduino board not responding during upload.

**Solutions:**

1. **Basic Checks:**

   - Press reset button on Arduino before upload
   - Check if anything is connected to pins 0 and 1 (remove if present)
   - Verify correct board selection

2. **Hardware Issues:**
   - Check USB cable and connection
   - Try different USB port
   - Verify board is getting power (LED should be on)

---

## Board Detection Issues

### Arduino Not Detected by Computer

**Symptoms:** No COM port appears, board not in device manager.

**Solutions:**

1. **USB Connection:**

   - Use different USB cable (data-capable)
   - Try different USB port
   - Connect directly to computer (not through hub)

2. **Driver Issues:**

   - **Windows:** Install drivers from Arduino website
   - **Arduino Uno R3:** Usually automatic
   - **Arduino Nano (old):** May need FTDI drivers
   - **Clone boards:** Install CH340 drivers

3. **Hardware Check:**
   - Check if power LED lights up
   - Try different computer to isolate issue
   - Check for physical damage to USB connector

### ESP8266 Not Detected

**Symptoms:** NodeMCU or ESP8266 board not appearing in ports.

**Solutions:**

1. **Driver Installation:**

   ```
   Download and install:
   - CP2102 drivers (most NodeMCU boards)
   - CH340 drivers (some clone boards)
   ```

2. **Boot Mode Check:**

   - Ensure GPIO0 is not permanently connected to GND
   - Check that board is in normal mode (not flash mode)

3. **Power Issues:**
   - Verify 3.3V power supply is stable
   - Check if board LED indicators are working

---

## WiFi Connection Issues (ESP8266)

### Cannot Connect to WiFi Network

**Symptoms:** ESP8266 fails to connect to WiFi, connection timeouts.

**Solutions:**

1. **Network Settings:**

   - Verify SSID and password are correct
   - Ensure network is 2.4GHz (ESP8266 doesn't support 5GHz)
   - Check if network is broadcasting (not hidden)

2. **Code Debugging:**

   ```
   Serial.print("Connecting to WiFi");
   while (WiFi.status() != WL_CONNECTED) {
     delay(1000);
     Serial.print(".");
   }
   Serial.println("\nConnected!");
   ```

3. **Network Issues:**
   - Try connecting to mobile hotspot for testing
   - Check router firewall settings
   - Ensure MAC filtering is disabled

### WiFi Keeps Disconnecting

**Solutions:**

1. **Power Supply:** Ensure stable 3.3V supply (WiFi draws significant current)
2. **Distance:** Move closer to router
3. **Add Reconnection Code:**
   ```
   if (WiFi.status() != WL_CONNECTED) {
     WiFi.reconnect();
   }
   ```

---

## Sensor Issues

### DHT11/DHT22 Reading Errors

**Symptoms:** NaN readings, incorrect values, or no response.

**Solutions:**

1. **Wiring Check:**

   - Verify 10kΩ pullup resistor on data pin
   - Check power connections (3.3V or 5V)
   - Ensure common ground

2. **Code Timing:**

   - Add delay between readings (at least 2 seconds for DHT11)
   - Check library version and update if needed

3. **Hardware Issues:**
   - Try different sensor (sensors can fail)
   - Check for loose connections

### Ultrasonic Sensor (HC-SR04) Issues

**Symptoms:** Incorrect distance readings or no readings.

**Solutions:**

1. **Power Supply:**

   - Ensure 5V power (required for reliable operation)
   - Check current capacity of power supply

2. **Timing Issues:**

   - Verify trigger pulse duration (10µs minimum)
   - Check echo pin reading logic
   - Add timeout for echo pin reading

3. **Environmental Factors:**
   - Check for acoustic interference
   - Ensure target object reflects sound well
   - Consider temperature effects on sound speed

### I2C LCD Display Issues

**Symptoms:** Blank display, garbled text, or no response.

**Solutions:**

1. **I2C Address:**

   - Scan for I2C devices to find correct address
   - Common addresses: 0x27, 0x3F

   ```
   // I2C Scanner code
   Wire.begin();
   Wire.beginTransmission(address);
   byte error = Wire.endTransmission();
   ```

2. **Wiring:**

   - Verify SDA and SCL connections
   - Check pullup resistors (usually built into module)
   - Ensure proper power supply

3. **Contrast Adjustment:**
   - Adjust potentiometer on I2C backpack
   - Try different library (LiquidCrystal_I2C)

---

## Power Issues

### Circuit Not Working Despite Correct Wiring

**Solutions:**

1. **Voltage Check:**

   - Measure actual voltages with multimeter
   - Verify power reaches all components
   - Check for voltage drops across long wires

2. **Current Limitations:**

   - Calculate total current draw
   - Arduino USB port limited to 500mA
   - Use external power for high-current devices

3. **Ground Issues:**
   - Ensure all grounds are connected
   - Check for ground loops
   - Verify breadboard power rail continuity

### ESP8266 Resetting Randomly

**Solutions:**

1. **Power Supply:** Use dedicated 3.3V regulator with adequate current capacity
2. **Decoupling:** Add 100µF and 10µF capacitors near ESP8266
3. **Code Issues:** Check for watchdog timer issues, add delay() in loops

---

## Code-Related Issues

### Compilation Errors

**Common Solutions:**

1. **Library Issues:**

   - Install missing libraries via Library Manager
   - Check library compatibility with board
   - Update Arduino IDE and libraries

2. **Syntax Errors:**
   - Check for missing semicolons
   - Verify bracket matching
   - Case sensitivity in function names

### Memory Issues

**Symptoms:** Sketch too large, random behavior, crashes.

**Solutions:**

1. **Optimize Code:**

   - Use F() macro for string constants
   - Reduce variable sizes where possible
   - Remove unused libraries

2. **Check Memory Usage:**
   - Arduino IDE shows memory usage after compilation
   - Leave at least 25% RAM free for stack

---

## General Troubleshooting Steps

1. **Start Simple:** Test with minimal code and connections
2. **Check Basics:** Power, ground, and connections first
3. **Use Serial Monitor:** Debug with Serial.print() statements
4. **Isolate Issues:** Test components individually
5. **Check Documentation:** Verify pinouts and specifications
6. **Community Help:** Search forums and GitHub issues

Remember: 90% of problems are wiring or power-related!
