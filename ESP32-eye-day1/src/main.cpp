#include <Arduino.h>

// ESP32-S3-Eye has an onboard LED connected to GPIO3
#define LED_PIN 3

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  Serial.println("ESP32-S3-Eye LED Blink Example");
  Serial.println("LED connected to GPIO3");
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(1000);  // Wait for 1 second
  
  // Turn the LED off
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(1000);  // Wait for 1 second
}