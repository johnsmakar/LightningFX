/*
 * LightningFX
 * This program simulates the irregular flashing effect of lightning 
 * Compatiblity: ESP32
 * 
 * Written by John Makar
 */
#include <analogWrite.h>

//#define DEBUG                           // Un-comment to Debug
#define DEBUG_BAUD 9600

#define LED 2                             // Onboard Led PIN

constexpr uint16_t minB = 0;              // Minimum LED Brightness (0-255)
constexpr uint16_t maxB = 255;            // Maximum LED Brightness (0-255)

constexpr uint16_t minDuration = 50;      // Minimum flash duration
constexpr uint16_t maxDuration = 150;     // Maximum flash duration

constexpr uint16_t minDelay = 1;          // Minimum delay between indivdual flash
constexpr uint16_t maxDelay = 150;        // Maximum delay between indivdual flash

constexpr uint16_t minFlashes = 3;        // Minimum number of flashes
constexpr uint16_t maxFlashes = 15;       // Maximum number of flashes

constexpr uint16_t minDelayLength = 1000; // Minimum delay between flash sequence
constexpr uint16_t maxDelayLength = 5000; // Maximum delay between flash sequence

void setup()
{
  #ifdef DEBUG
  Serial.begin(DEBUG_BAUD);
  while (!Serial);
  Serial.println("\nDEBUG MODE...");
  #endif
  
  pinMode(LED, OUTPUT);
}

void loop()
{
  uint8_t numFlashes = random(minFlashes, maxFlashes);
  uint16_t delayLength = random(minDelayLength, maxDelayLength);  // Frequency between flashes

  Serial.printf("Number of flashes: %d\n", numFlashes);

  for (uint8_t i = 0 ; i <= numFlashes; i++) {
    int intensity = random(minB, maxB);
    Serial.println(intensity);
    analogWrite(LED, intensity);               // Set LED brightness
    delay(random(minDuration, maxDuration));   // Flash duration

    analogWrite(LED, 0);                       // Turn off LED
    delay(random(minDelay, maxDelay));         // Delay until next flash
  }
  
  Serial.printf("Next sequence in millisecond(s): %d\n", delayLength);
    
  delay(delayLength);
}
