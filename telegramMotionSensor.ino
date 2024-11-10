#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Pin definitions
const int pirPin = 32;  // HC-SR501 sensor
const int ledPin = 13;  // LED
const int buzzerPin = 26; // Buzzer (alarm)

// Wi-Fi and Telegram
const char* ssid = "YOUR_SSID";           // Your WiFi network name
const char* password = "YOUR_PASSWORD"; // Your WiFi network password
const char* botToken = "YOUR_BOT_TOKEN";  // Your bot token from Telegram
const char* chat_id = "YOUR_CHAT_ID";     // Your chat ID on Telegram

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

// Timer variables
unsigned long lastTriggerTime = 0;  // Time when movement was last detected
const unsigned long cooldownPeriod = 60000;  // 1 minute (in milliseconds)

void setup() {
  Serial.begin(115200);

  // Pin configuration
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Connect to Wi-Fi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");

  // Configure secure connection for Telegram
  client.setInsecure();  // Disable SSL certificate verification
}

void loop() {
  unsigned long currentTime = millis();  // Current time

  // Check if the sensor detects movement
  if (digitalRead(pirPin) == HIGH) {
    // Check if the time since the last trigger is greater than the cooldownPeriod
    if (currentTime - lastTriggerTime > cooldownPeriod) {
      Serial.println("Movement detected!");

      // Turn on the LED and activate the alarm
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);

      // Send a message to Telegram
      String message = "Movement detected!";
      bot.sendMessage(chat_id, message, "");

      // Update the last trigger time
      lastTriggerTime = currentTime;

      // Wait 30 seconds before turning off the LED and alarm
      delay(30000);

      // Turn off the LED and alarm
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
    } else {
      // Movement detected but ignored (within the 1-minute interval)
      Serial.println("Movement detected, but ignored (within 1-minute interval).");
    }
  }

  delay(500);  // Interval between checks
}
