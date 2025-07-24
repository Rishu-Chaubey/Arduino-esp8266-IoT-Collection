#include <ESP8266WiFi.h>

// WiFi credentials
const char *ssid = "Tantraniketan_4G";
const char *password = "tantraniketan@2024";

// Create a WiFi server on port 80
WiFiServer server(80);

// Define pins for LEDs
const int ledPin1 = D5;
const int ledPin2 = D6;
const int ledPin3 = D7;

void setup()
{
    // Start serial communication at 9600 baud for debugging
    Serial.begin(9600);

    // Configure LED pins as output
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);

    // Connect to WiFi network
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Connected to WiFi successfully!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // Start the server
    server.begin();
}

void loop()
{
    // Listen for incoming clients
    WiFiClient client = server.available();

    // If no client is connected, return early
    if (!client)
    {
        return;
    }

    Serial.println("New client connected");

    String request = "";
    String currentLine = "";

    // While the client is connected
    while (client.connected())
    {
        if (client.available())
        {
            char c = client.read(); // Read a byte from the client
            request += c;           // Append to the request string

            // Check for end of line (HTTP header lines end with '\n')
            if (c == '\n')
            {
                // If currentLine is empty, headers are finished
                if (currentLine.length() == 0)
                {
                    // Debug: print the full HTTP request
                    Serial.println("HTTP Request:");
                    Serial.println(request);

                    // Handle LED control requests
                    if (request.indexOf("GET /ledon") >= 0)
                    {
                        // Turn all LEDs ON immediately
                        digitalWrite(ledPin1, HIGH);
                        digitalWrite(ledPin2, HIGH);
                        digitalWrite(ledPin3, HIGH);
                    }
                    else if (request.indexOf("GET /ledoff") >= 0)
                    {
                        // Turn all LEDs OFF immediately
                        digitalWrite(ledPin1, LOW);
                        digitalWrite(ledPin2, LOW);
                        digitalWrite(ledPin3, LOW);
                    }

                    // Send HTTP response headers
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();

                    // Send the HTML content
                    client.println("<!DOCTYPE HTML>");
                    client.println("<html>");
                    client.println("<head><title>ESP8266 LED Control</title></head>");
                    client.println("<body>");
                    client.println("<h1>ESP8266 WiFi LED Control</h1>");
                    client.println("<p><a href=\"/ledon\">Turn LEDs ON</a></p>");
                    client.println("<p><a href=\"/ledoff\">Turn LEDs OFF</a></p>");
                    client.println("</body>");
                    client.println("</html>");

                    break; // Exit the while loop after responding
                }
                else
                {
                    // Reset currentLine for the next header line
                    currentLine = "";
                }
            }
            else if (c != '\r')
            {
                // Append character to currentLine (ignore carriage returns)
                currentLine += c;
            }
        }
    }

    // Give the client time to receive the data before closing
    delay(1);

    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
}
