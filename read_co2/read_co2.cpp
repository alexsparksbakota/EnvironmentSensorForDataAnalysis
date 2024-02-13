#include "read_co2.h"
#include <Arduino.h>

float read_co2_data(int analog_pin) {
  int sensorValue = analogRead(analog_pin);
  float conc = sensorValue*50/16;
  return conc;
}
