#include <Adafruit_Sensor.h>   // Base class for sensors, required by DHT library
#include <ESP8266WiFi.h>       // ESP8266 WiFi Control
#include <DHT.h>               // DHT sensor library
#include <ThingSpeak.h>        // ThingSpeak library for IoT data logging

// Initialize DHT sensor on pin D6 and type DHT11
#define DHTPIN D6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// WiFi client for ThingSpeak connection
WiFiClient client;

// ThingSpeak channel info
long myChannelNumber = 3009691;
const char myWriteAPIKey[] = "Y1YQRO29W7SB96XR";

void setup() {
  Serial.begin(9600);               // Initialize serial communication
  Serial.println("Connecting to WiFi...");

  // Start WiFi connection
  WiFi.begin("Tantraniketan_4G", "tantraniketan@2024");

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print("..");
  }

  Serial.println();
  Serial.println("NodeMCU connected to WiFi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  dht.begin();                     // Initialize DHT sensor
  ThingSpeak.begin(client);        // Initialize ThingSpeak
}

void loop() {
  // Read humidity and temperature from DHT11 sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to avoid using invalid data)
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  // Print temperature and humidity to serial monitor
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  // Write temperature and humidity data to ThingSpeak fields 1 and 2
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);

  delay(2000);  // Wait 2 seconds before next reading (ThingSpeak rate limit minimum)
}
