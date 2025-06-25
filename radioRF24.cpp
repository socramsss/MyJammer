#include "radioRF24.h"

RadioRF24::RadioRF24()
{

}

RadioRF24::RadioRF24(int cePin, int csnPin, int channel, int xspi, int spiSpeed)
  : radio(cePin, csnPin, spiSpeed)
{
    spiXSPI = new SPIClass(xspi);
    spiXSPI->begin();

    if (radio.begin(spiXSPI)) 
    {
      Serial.println("Conectado SPI !!!");
      radio.setAutoAck(false);
      radio.stopListening();
      radio.setRetries(0, 0);
      radio.setPALevel(RF24_PA_MAX, true);
      radio.setDataRate(RF24_2MBPS);
      radio.setCRCLength(RF24_CRC_DISABLED);
      radio.printPrettyDetails();
      radio.startConstCarrier(RF24_PA_MAX, channel);
      currentChannel = channel;
      connected = true;
    } 
    else 
    {
      Serial.println("SPI não conectado !!!");
      connected = false;
    }
}

RadioRF24::~RadioRF24()
{
  if (spiXSPI)
    delete spiXSPI;
}

 void RadioRF24::SetPinStatusLed(int pin)
 {
  if(pin >= 0)
  {
      pinMode(pin, OUTPUT);
      if(connected)
        digitalWrite(pin, HIGH);
      else
        digitalWrite(pin, LOW);

      pinLed = pin;
  }
 }

void RadioRF24::SetChannel(int channel)
{
  if(channel >= 0 && channel <= 80 )
  {
    if(currentChannel == -1)
    {
      radio.powerUp();
      radio.startConstCarrier(RF24_PA_MAX, channel);
    }
    currentChannel = channel;
    radio.setChannel(currentChannel);
  }
  else
  {
    if(channel == -1)
    {
      radio.powerDown();
      currentChannel = channel;
    }
  }
}