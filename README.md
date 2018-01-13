CDM7160(Co2センサー)用ライブラリ
=====

CDM7160をWio LTEに接続するためのライブラリです。


## How To Use

Include library(`#include <CDM7160.h>`), and write a code like below.

```
CDM7160 co2;

WioLTE Wio;

void setup() {
  Wio.Init();
  Wio.PowerSupplyGrove(true);
  co2.begin();
}

void loop() {
  if(co2.readData()){
    SerialUSB.print("  CO2: ");
    SerialUSB.print(co2.getCo2());
    SerialUSB.println("");
  }
  delay(1000);
```

## LICENSE

MIT


