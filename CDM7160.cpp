#include <CDM7160.h>
#include <Wire.h>

CDM7160::CDM7160()
{

}

void CDM7160::begin()
{
  set_register(0x69,0x01,0x06);
}

bool CDM7160::readData()
{
  int data_count = 0;

  RecieveDataI2c(0x69, 0x02, &_buf[2], 1); // Read Status
  if((_buf[2] & 0x80) == 0)  // BUSY時はデータが化ける為取り込まない様対策
  {
    data_count = RecieveDataI2c(0x69, 0x03, &_buf[0], 1); // Read DAL
    data_count += RecieveDataI2c(0x69, 0x04, &_buf[1], 1); // Read DAH
    _co2ppm = (_buf[1] << 8)| _buf[0];
  }
  if(data_count == 2) return true;

  return(false);
}

void CDM7160::calibration()
{

}

void CDM7160::initWait()
{

}

bool CDM7160::getInitEndStatus()
{

}

int CDM7160::getCo2()
{
  return _co2ppm;
}

int CDM7160::getTemperature()
{

}

void CDM7160::set_register(int address, unsigned char r, unsigned char v)
{    
  Wire.beginTransmission(address);    
  Wire.write(r);   
  Wire.write(v);   
  Wire.endTransmission();
}

int CDM7160::RecieveDataI2c(int address, unsigned char reg, char* data, int size)
{
  int i = 0;
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.endTransmission();    // stop transmitting
  Wire.requestFrom(address,size);

  while(Wire.available()){
    data[i] = Wire.read();
    i++;
  }
  return i;
}
