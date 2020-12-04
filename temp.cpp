#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

bool isTurnOn = false;
bool isForcedOn = false;
bool isForcedOff = false;
void loop() {
    // Reset forced variables
    if (cdsValue > MAX) isForcedOff = false;
    if (cdsValue < MIN) isForcedOn = false;

    // Event for LED
    if (isTurnOn) {
        if (digitalRead(button) == HIGH) {
            digitalWrite(led, LOW);
            isTurnOn = false;
            isForcedOff = true;
            // Reset forced variables
            isForcedOn = false;
        }

        if (!isForcedOn && cdsValue > MAX) {
            digitalWrite(led, LOW);
            isTurnOn = false;
        }

    } else {
        if (digitalRead(button) == HIGH) {
            digitalWrite(led, HIGH);
            isTurnOn = true;
            isForcedOn = true;
            // Reset forced variables
            isForcedOff = false;
        }

        if (!isForcedOff && cdsValue < MIN) {
            digitalWrite(led, HIGH);
            isTurnOn = true;
        }
    }
}