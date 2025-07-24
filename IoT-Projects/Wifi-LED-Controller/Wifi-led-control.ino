// Define LED pins
int led1 = 13;
int led2 = 12;
int led3 = 11;

// Variable to store received character from Serial
char val;

void setup()
{
  Serial.begin(9600);    // Initialize Serial communication at 9600 baud
  pinMode(led1, OUTPUT); // Set LED pins as output
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  // Check if data is available on Serial
  while (Serial.available() > 0)
  {
    val = Serial.read(); // Read a character

    Serial.println(val); // Echo the received character back to Serial (optional)
    delay(15);           // Short delay for stability

    // Control LED1
    if (val == 'A')
    {
      digitalWrite(led1, HIGH); // Turn ON LED1
    }
    else if (val == 'a')
    {
      digitalWrite(led1, LOW); // Turn OFF LED1
    }

    // Control LED2
    if (val == 'B')
    {
      digitalWrite(led2, HIGH); // Turn ON LED2
    }
    else if (val == 'b')
    {
      digitalWrite(led2, LOW); // Turn OFF LED2
    }

    // Control LED3
    if (val == 'C')
    {
      digitalWrite(led3, HIGH); // Turn ON LED3
    }
    else if (val == 'c')
    {
      digitalWrite(led3, LOW); // Turn OFF LED3
    }
  }
}
