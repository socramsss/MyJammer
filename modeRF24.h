#ifndef MODE_RF24_H
#define MODE_RF24_H

#include "RF24.h"
#include <SPI.h>

#define MODE_BLUETOOTH 0
#define MODE_BLUETOOTH_BLE 1
#define MODE_WIFI 2
#define MODE_WIFI_COMMOM 3
#define MODE_ALL_CHANNELS 4
#define MODE_DISABLE 5

class ModeRF24
{
  private:
  int mode = MODE_BLUETOOTH;

  int CalulateValueBlueTooth();

  int CalulateValueBlueToothBle();

  int CalulateWifi();

  int CalulateWifiCommom();

  int CalulateAllChannels();

  protected:
  static const int bluetooth_channels[21]; // {32, 34, 46, 48, 50, 52, 0, 1, 2, 4, 6, 8, 22, 24, 26, 28, 30, 74, 76, 78, 80};

  static const int ble_channels[3]; // {2, 26, 80};

  static const int wifi_common_channels[4]; // {12, 32, 37, 42};

  static const int wifi_channels[13]; // {12, 17, 22, 27, 32, 37, 42, 47, 52, 57, 62, 67, 72};

  int flag = 0;

  int ch = 0;

  public:
    ModeRF24();

    ~ModeRF24();

    int GetChannel();

    void SetMode(int newMode);

    int NextMode();
};
#endif