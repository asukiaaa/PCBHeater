#include <SPI.h>
#include "Adafruit_MAX31855.h"

#define DO   9
#define CS   8
#define CLK  7
#define RELAY_PIN 6

#define HEATER_OFF_TEMP 240

Adafruit_MAX31855 thermocouple(CLK, CS, DO);

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(115200);

  Serial.println("start PCB heater");
  delay(500);
}

void loop() {
  Serial.print("Internal Temp = ");
  Serial.println(thermocouple.readInternal());

  double c = thermocouple.readCelsius();
  if (isnan(c)) {
    Serial.println("Something wrong with thermocouple!");
  } else {
    Serial.print("C = ");
    Serial.println(c);
  }

  if ( c > HEATER_OFF_TEMP ) {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("heater off");
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("heater on");
  }

   delay(1000);
}
