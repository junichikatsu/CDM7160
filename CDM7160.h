
#ifndef _CDM7160_H_
#define _CDM7160_H_

#include <WioLTEforArduino.h>

class CDM7160 {
public:

  CDM7160();
  void begin();
  bool readData();
  void calibration();
  void initWait();
  bool getInitEndStatus();
  int getCo2();
  int getTemperature();

private:
  void set_register(int address, unsigned char r, unsigned char v);
  int RecieveDataI2c(int address, unsigned char reg, char* data, int size);
  char _buf[9];
  int _co2ppm;
  int _temperature;
};

#endif
