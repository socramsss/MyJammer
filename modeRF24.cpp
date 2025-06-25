#include "modeRF24.h"

const int ModeRF24::bluetooth_channels[21] = { 32, 34, 46, 48, 50, 52, 0, 1, 2, 4, 6, 8, 22, 24, 26, 28, 30, 74, 76, 78, 80};
const int ModeRF24::ble_channels[3] = {2, 26, 80};
const int ModeRF24::wifi_common_channels[4] = {12, 32, 37, 42};
const int ModeRF24::wifi_channels[13] = {12, 17, 22, 27, 32, 37, 42, 47, 52, 57, 62, 67, 72};

ModeRF24::ModeRF24()
{
  mode = MODE_DISABLE;
  flag = 0;
  ch = 0;
}

ModeRF24::~ModeRF24()
{

}

int ModeRF24::GetChannel()
{
  int ret = 0;
  switch (mode) 
  {
    case MODE_BLUETOOTH:
      ret = CalulateValueBlueTooth();
      break;
    case MODE_BLUETOOTH_BLE:
      ret = CalulateValueBlueToothBle();
      break;
    case MODE_WIFI:
      ret = CalulateWifi();
      break;
    case MODE_WIFI_COMMOM:
      ret = CalulateWifiCommom();
      break;
    case MODE_ALL_CHANNELS:
      ret = CalulateAllChannels();
      break;
    case  MODE_DISABLE:
      ret = -1;
      break;
    default:
      ret = 0;
      break;
  }

  return ret;
}

void ModeRF24::SetMode(int newMode)
{
  if(newMode >= MODE_BLUETOOTH && newMode <= MODE_DISABLE)
    mode = newMode;
  else
    mode = MODE_BLUETOOTH;

  flag = 0;
  ch = 0;
}

int ModeRF24::NextMode()
{
  SetMode(mode + 1);

  Serial.print("Selecionado modo: ");

  switch (mode) 
  {
    case MODE_BLUETOOTH:
      Serial.println("Bluetoth");
      break;
    case MODE_BLUETOOTH_BLE:
      Serial.println("Bluetoth BLE");
      break;
    case MODE_WIFI:
      Serial.println("WIFI");
      break;
    case MODE_WIFI_COMMOM:
      Serial.println(" WIFI Comuns");
      break;
    case MODE_ALL_CHANNELS:
      Serial.println("Todos Canais");
      break;
    case  MODE_DISABLE:
      Serial.println("Desativado");
      break;
    default:
      Serial.println("...throw...");
      break;
  }

  return mode;
}

int ModeRF24::CalulateValueBlueTooth()
{
  int comp = sizeof(bluetooth_channels) / sizeof(bluetooth_channels[0]);

  if (flag == 0)
    ch++;
  else
    ch--;

  if ((ch > (comp - 1)) && (flag == 0)) 
  {
    flag = 1;
    ch = (comp - 2);
  } 
  else 
  {
    if ((ch < 0) && (flag == 1))
    {
      flag = 0;
      ch = 1;
    }
  }

  return bluetooth_channels[ch];
}

int ModeRF24::CalulateValueBlueToothBle()
{
 int comp = sizeof(ble_channels) / sizeof(ble_channels[0]);

  if (flag == 0)
    ch++;
  else
    ch--;

  if ((ch > (comp - 1)) && (flag == 0)) 
  {
    flag = 1;
    ch = (comp - 2);
  } 
  else 
  {
    if ((ch < 0) && (flag == 1))
    {
      flag = 0;
      ch = 1;
    }
  }

  return ble_channels[ch];
}

int ModeRF24::CalulateWifi()
{
 int comp = sizeof(wifi_channels) / sizeof(wifi_channels[0]);

  if (flag == 0)
    ch++;
  else
    ch--;

  if ((ch > (comp - 1)) && (flag == 0)) 
  {
    flag = 1;
    ch = (comp - 2);
  } 
  else 
  {
    if ((ch < 0) && (flag == 1))
    {
      flag = 0;
      ch = 1;
    }
  }

  return wifi_channels[ch];
}

int ModeRF24::CalulateWifiCommom()
{
 int comp = sizeof(wifi_common_channels) / sizeof(wifi_common_channels[0]);

  if (flag == 0)
    ch++;
  else
    ch--;

  if ((ch > (comp - 1)) && (flag == 0)) 
  {
    flag = 1;
    ch = (comp - 2);
  } 
  else 
  {
    if ((ch < 0) && (flag == 1))
    {
      flag = 0;
      ch = 1;
    }
  }

  return wifi_common_channels[ch];
}

int ModeRF24::CalulateAllChannels()
{
  int comp = 81;

  if (flag == 0)
    ch++;
  else
    ch--;

  if ((ch > (comp - 1)) && (flag == 0)) 
  {
    flag = 1;
    ch = (comp - 2);
  } 
  else 
  {
    if ((ch < 0) && (flag == 1))
    {
      flag = 0;
      ch = 1;
    }
  }

  return ch;
}