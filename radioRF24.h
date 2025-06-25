#ifndef RADIO_RF24_H
#define RADIO_RF24_H

#include "RF24.h"
#include <SPI.h>

class RadioRF24
{
  private:
    SPIClass *spiXSPI = nullptr;

    RF24 radio;

  protected:
    bool connected = false;

    int pinLed = -1;

    int currentChannel = 0;

  public:
    RadioRF24();

    RadioRF24(int cePin, int csnPin, int channel, int xspi, int spiSpeed = 10000000);

    ~RadioRF24();

    void SetPinStatusLed(int pin);

    void SetChannel(int channel);
};
#endif