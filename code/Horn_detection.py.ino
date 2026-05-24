#include <LiquidCrystal.h>

// LCD pin mapping: RS, E, D4, D5, D6, D7

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

// Pin definitions

const int micPin = A0;

// Sound level potentiometer

const int buzzerPin = 7;

// Buzzer

const int redLEDPin = 6;

// Red LED

const int greenLEDPin = 13;

// Green LED

const int resetPin = A1;

// Slide switch or push button

// Threshold

const int sound Threshold = 600;

// Adjust based on pot range

void setup() {

lcd.begin(16, 2);

pinMode(buzzerPin, OUTPUT);

pinMode(redLEDPin, OUTPUT);

pinMode(greenLEDPin, OUTPUT);

pinMode(resetPin, INPUT);

lcd.setCursor(0,0);

lcd.print("System Ready");

digitalWrite(greenLEDPin, HIGH);

delay(2000);

lcd.clear();

}

void loop() {

int soundLevel = analogRead(micPin);

// Check for horn misuse

if (soundLevel > sound Threshold) {

lcd.clear();

lcd.setCursor(0, 0);

lcd.print("Horn Misuse!");

lcd.setCursor(0, 1);

lcd.print("Level: ");

lcd.print(sound Level);

digitalWrite(buzzerPin, HIGH);

digitalWrite(redLEDPin, HIGH);

digitalWrite(greenLEDPin, LOW);

} else {

lcd.clear();

lcd.setCursor(0, 0);

lcd.print("Monitoring...");

digitalWrite(buzzerPin, LOW);

digitalWrite(redLEDPin, LOW);

digitalWrite(greenLEDPin, HIGH);

}

// Reset logic

if (digitalRead(resetPin) == HIGH) {

lcd.clear();

lcd.setCursor(0, 0);

lcd.print("Calibration Reset");

delay(2000);

lcd.clear();

}

delay(500); // Adjust for responsiveness

}