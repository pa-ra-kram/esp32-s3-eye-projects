#include <Arduino.h>
#include <WiFi.h>

// ESP32-S3-Eye specific pins
#define LED_PIN 3          // Built-in LED
#define BUTTON_PIN 0       // Boot button

// WiFi credentials (update these)
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  delay(2000); // Give time for serial monitor to connect
  
  Serial.println("\n=== ESP32-S3-Eye Basic Demo ===");
  Serial.println("Board: ESP32-S3-Eye");
  Serial.println("Framework: Arduino");
  
  // Initialize GPIO
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Test PSRAM (using Arduino-compatible functions)
  Serial.println("\n--- PSRAM Test ---");
  if (psramFound()) {
    Serial.printf("PSRAM found: %d bytes\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM: %d bytes\n", ESP.getFreePsram());
  } else {
    Serial.println("PSRAM not found!");
  }
  
  // Display chip information
  Serial.println("\n--- Chip Information ---");
  Serial.printf("Chip Model: %s\n", ESP.getChipModel());
  Serial.printf("Chip Revision: %d\n", ESP.getChipRevision());
  Serial.printf("CPU Frequency: %d MHz\n", ESP.getCpuFreqMHz());
  Serial.printf("Flash Size: %d bytes\n", ESP.getFlashChipSize());
  Serial.printf("Free Heap: %d bytes\n", ESP.getFreeHeap());
  
  // WiFi connection test
  Serial.println("\n--- WiFi Test ---");
  Serial.println("Attempting to connect to WiFi...");
  WiFi.begin(ssid, password);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected successfully!");
    Serial.printf("IP Address: %s\n", WiFi.localIP().toString().c_str());
    Serial.printf("Signal Strength: %d dBm\n", WiFi.RSSI());
  } else {
    Serial.println("\nWiFi connection failed!");
    Serial.println("Please check your WiFi credentials in the code.");
  }
  
  Serial.println("\n--- Setup Complete ---");
  Serial.println("LED will blink every second");
  Serial.println("Press the BOOT button to see button state");
  Serial.println("========================\n");
}

void loop() {
  static unsigned long lastBlink = 0;
  static unsigned long lastButtonCheck = 0;
  static bool ledState = false;
  static bool lastButtonState = HIGH;
  
  unsigned long currentTime = millis();
  
  // Blink LED every second
  if (currentTime - lastBlink >= 1000) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    Serial.printf("LED: %s | Uptime: %lu seconds | Free Heap: %d bytes\n", 
                  ledState ? "ON" : "OFF", 
                  currentTime / 1000, 
                  ESP.getFreeHeap());
    lastBlink = currentTime;
  }
  
  // Check button state every 50ms
  if (currentTime - lastButtonCheck >= 50) {
    bool buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) {
      if (buttonState == LOW) {
        Serial.println("BOOT button pressed!");
        
        // Display current status when button is pressed
        Serial.println("\n--- Current Status ---");
        Serial.printf("WiFi Status: %s\n", WiFi.status() == WL_CONNECTED ? "Connected" : "Disconnected");
        if (WiFi.status() == WL_CONNECTED) {
          Serial.printf("IP: %s\n", WiFi.localIP().toString().c_str());
        }
        Serial.printf("Free Heap: %d bytes\n", ESP.getFreeHeap());
        if (psramFound()) {
          Serial.printf("Free PSRAM: %d bytes\n", ESP.getFreePsram());
        }
        Serial.println("--------------------\n");
      }
      lastButtonState = buttonState;
    }
    lastButtonCheck = currentTime;
  }
  
  // Small delay to prevent excessive CPU usage
  delay(10);
}