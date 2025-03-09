#include "arduino_secrets.h"
// Define LED pin
#define LED_PIN 13  // Built-in LED on the Arduino Nano 33 IoT

// Define Morse code timing constants
#define DOT 250      // Duration of a dot in milliseconds
#define DASH 750     // Duration of a dash in milliseconds
#define GAP 250      // Time between dot/dash signals
#define LETTER_PAUSE 1000  // Pause between letters

// Function to blink the LED for a specified duration
void blink(int duration) {
    digitalWrite(LED_PIN, HIGH); // Turn LED on
    delay(duration);             // Keep it on for the given duration
    digitalWrite(LED_PIN, LOW);  // Turn LED off
    delay(GAP);                  // Short pause before next signal
}

// Function to blink a letter in Morse code
void blinkLetter(char letter) {
    switch (letter) {
        case 'K': blink(DASH); blink(DOT); blink(DASH); break;  // Morse code for 'K'
        case 'A': blink(DOT); blink(DASH); break;              // Morse code for 'A'
        case 'V': blink(DOT); blink(DOT); blink(DOT); blink(DASH); break; // Morse code for 'V'
        case 'E': blink(DOT); break;                           // Morse code for 'E'
        case 'N': blink(DASH); blink(DOT); break;             // Morse code for 'N'
    }
    delay(LETTER_PAUSE); // Pause before the next letter
}

// Function to blink the name "KAVEEN" in Morse code
void blinkName() {
    char name[] = "KAVEEN";
    for (char c : name) {   // Iterate through each letter
        blinkLetter(c);      // Blink corresponding Morse code
    }
}

// Setup function - runs once at startup
void setup() {
    pinMode(LED_PIN, OUTPUT); // Set LED pin as output
}

// Loop function - runs continuously
void loop() {
    blinkName();   // Blink the name in Morse code
    delay(15000);   // Pause before repeating the sequence
}