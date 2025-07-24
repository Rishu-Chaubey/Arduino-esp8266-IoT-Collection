/*
  NodeMCU + Ultrasonic Sensor + DHT + ThingSpeak Example
  ------------------------------------------------------
  Measures distance (ultrasonic), temperature, and humidity.
  Prints to Serial, uploads data to ThingSpeak IoT Cloud.
*/

// --- Library Includes ---
#include <Adafruit_Sensor.h>      // Sensor base class (needed for DHT)
#include <DHT.h>                  // DHT temp/humidity sensor
#include <ESP8266WiFi.h>          // WiFi functions for ESP8266/NodeMCU
#include <ThingSpeak.h>           // ThingSpeak IoT upload

// --- Pin Definitions ---
const int trigPin = D1;    // GPIO5 (D1 on NodeMCU)
const int echoPin = D2;    // GPIO4 (D2 on NodeMCU)
const int DHT_PIN = D3;    // GPIO0 (D3 on NodeMCU), change as needed

// --- ThingSpeak & WiFi ---
char ssid[]     = "Tantraniketan_4G";
char password[] = "tantraniketan@2024";
WiFiClient client;
unsigned long myChannelNumber = 3009667;
const char myWriteAPIKey[] = "7AGIP34I6GZVROZ0";

// --- DHT setup ---
#define DHTTYPE DHT11         // Or DHT22
DHT dht(DHT_PIN, DHTTYPE);

// ----------------------
//    SETUP SECTION
// ----------------------
void setup() {
  Serial.begin(9600);

  // Pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start DHT sensor
  dht.begin();

  // Connect to WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start ThingSpeak
  ThingSpeak.begin(client);
}

// ----------------------
//      MAIN LOOP
// ----------------------
void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time (duration of return pulse)
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm (speed of sound = 34300 cm/s)
  float distanceCM = duration * 0.0343 / 2;

  // Read temperature & humidity from DHT sensor
  float temp = dht.readTemperature();
  float humid = dht.readHumidity();

  // --- Print values to Serial Monitor ---
  Serial.println("-----------------------------");
  Serial.print("Distance: ");
  Serial.print(distanceCM, 1);
  Serial.println(" cm");

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  
  Serial.print("Humidity: ");
  Serial.print(humid);
  Serial.println(" %");

  // --- Upload to ThingSpeak fields ---
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, humid);
  ThingSpeak.setField(3, distanceCM);

  // Upload all at once for efficiency
  int result = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(result == 200){
    Serial.println("Channel update successful.");
  } else {
    Serial.print("Problem updating channel. HTTP error code ");
    Serial.println(result);
  }

  delay(20000);   // Wait 20 seconds for ThingSpeak rate limit (minimum 15sec)
}
