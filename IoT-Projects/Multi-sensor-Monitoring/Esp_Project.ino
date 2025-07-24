// -----------------------------------------------
// Multi-Sensor ESP8266 IoT Project with LCD & ThingSpeak
// Measures: IR detection, Gas levels, and Temperature
// Displays on LCD and uploads to ThingSpeak IoT cloud
// -----------------------------------------------

// --- Include Necessary Libraries ---
#include <Servo.h>                // Servo motor control
#include <LiquidCrystal_I2C.h>    // I2C LCD display
#include <DHT.h>                  // DHT11 temperature/humidity sensor
#include <ESP8266WiFi.h>          // ESP8266 WiFi functions
#include <ThingSpeak.h>           // ThingSpeak IoT cloud functions

// --- Pin Definitions ---
const int IR_SENSOR_PIN  = D4;    // IR sensor digital input pin
const int GAS_SENSOR_PIN = A0;    // Gas sensor analog pin (A0)
const int DHT_PIN        = D3;    // DHT11 data pin
const int SERVO_PIN      = D5;    // Servo motor control pin

// --- Hardware Setup ---
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address 0x27, 16 columns, 2 rows
Servo myServo;                      // Servo motor object
DHT dht(DHT_PIN, DHT11);            // DHT11 sensor on D3

// --- WiFi and ThingSpeak Setup ---
WiFiClient client;
long myChannelNumber = 3009691;
char myWriteAPIKey[] = "Y1YQRO29W7SB96XR";

// --- WiFi Credentials ---
const char* WIFI_SSID = "Tantraniketan_4G";
const char* WIFI_PASS = "tantraniketan@2024";

// -----------------------------------------------
//                 SETUP SECTION
// -----------------------------------------------
void setup() {
  Serial.begin(9600);

  // --- Initialize Hardware ---
  pinMode(IR_SENSOR_PIN, INPUT);
  dht.begin();
  myServo.attach(SERVO_PIN);

  lcd.init();         // Initialize LCD
  lcd.backlight();    // Turn on LCD backlight
  lcd.print("Initializing...");

  // --- Connect to WiFi ---
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi Connected!");
  lcd.clear();
  lcd.print("WiFi Connected");

  // --- Connect to ThingSpeak ---
  ThingSpeak.begin(client);
}

// -----------------------------------------------
//                 MAIN LOOP
// -----------------------------------------------
void loop() {
  // --- Read Sensors ---
  int   irValue   = digitalRead(IR_SENSOR_PIN);  // IR: 0 or 1 (object/no object)
  int   gasLevel  = analogRead(GAS_SENSOR_PIN);  // Gas: analog value 0-1023
  float temp      = dht.readTemperature();       // Temperature in Celsius

  // --- Display on LCD ---
  lcd.clear();
  // Line 1: Temperature and IR Sensor
  lcd.setCursor(0, 0);
  lcd.print("T:"); lcd.print(temp);
  lcd.setCursor(10, 0);
  lcd.print("IR:"); lcd.print(irValue);

  // Line 2: Gas Sensor
  lcd.setCursor(0, 1);
  lcd.print("G:"); lcd.print(gasLevel);

  // --- Debug Output ---
  Serial.println("------------------");
  Serial.print("IR Sensor: "); Serial.println(irValue);
  Serial.print("Gas Level: "); Serial.println(gasLevel);
  Serial.print("Temperature: "); Serial.println(temp);

  // --- Upload to ThingSpeak ---
  ThingSpeak.setField(1, irValue);
  ThingSpeak.setField(2, gasLevel);
  ThingSpeak.setField(3, temp);

  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  delay(5000); // Wait before next update (5 seconds)
}
