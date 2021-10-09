#include <Arduino.h>
#include <SPI.h>

#define WATER_LEVEL_FULL_PIN 3
#define WATER_LEVEL_EMPTY_PIN 4

bool water_level_full, water_level_empty;

void setup() {

}

void loop() {
    water_level_full = digitalRead(WATER_LEVEL_FULL_PIN);
    water_level_empty = digitalRead(WATER_LEVEL_EMPTY_PIN);
}