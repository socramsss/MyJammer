#include "radioRF24.h"
#include "modeRF24.h"

#include "RF24.h"
#include <SPI.h>
#include <ezButton.h>
#include "esp_bt.h"
#include "esp_wifi.h"

RadioRF24* radio00;
RadioRF24* radio01;

ModeRF24 modeRF24;

ezButton toggleSwitch(0);

void setup() 
{
  Serial.begin(115200);
  esp_bt_controller_deinit();
  esp_wifi_stop();
  esp_wifi_deinit();
  esp_wifi_disconnect();
  toggleSwitch.setDebounceTime(50);

  radio00 = new RadioRF24(16, 15, 45, HSPI, 16000000);
  radio01 = new RadioRF24(22, 21, 45, VSPI, 16000000);

  radio00->SetPinStatusLed(2);
  radio01->SetPinStatusLed(27);
}

void loop() 
{
  toggleSwitch.loop();

  if (toggleSwitch.isPressed())
    modeRF24.NextMode();

  SetChannel();
}

void SetChannel()
{
  radio00->SetChannel(modeRF24.GetChannel());
  radio01->SetChannel(modeRF24.GetChannel()); 
}
