#include <SoftwareSerial.h>
#include "pms5003.h"

SoftwareSerial pmsSerial(2, 3);
struct pms5003data data;
 
void setup() {
  // our debugging output
  Serial.begin(115200);
 
  // sensor baud rate is 9600
  pmsSerial.begin(9600);
}
 
void loop() {
  if (readPMSdata(&pmsSerial, &data)) {
    // reading data was successful!
    Serial.println();
    Serial.println("---------------------------------------");
    Serial.println("Concentration Units (standard)");
    Serial.print("PM 1.0: "); Serial.print(data.pm10_standard);
    Serial.print("\t\tPM 2.5: "); Serial.print(data.pm25_standard);
    Serial.print("\t\tPM 10: "); Serial.println(data.pm100_standard);
  }
}
