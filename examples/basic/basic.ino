#include <WioLTEforArduino.h>
#include <CDM7160.h>
#include <Wire.h>

CDM7160 co2;

WioLTE Wio;

void setup() {
  Wio.Init();
  Wio.PowerSupplyGrove(true);

  Wire.begin();
  co2.begin();
}

void loop() {
  if(co2.readData()){
    SerialUSB.print("CO2: ");
    SerialUSB.print(co2.getCo2());
    SerialUSB.println("");
  }
  delay(1000);
}