#ifndef ZBT
#define ZBT
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>


#define SERVICE_UUID        "15012e01-1cd5-4f96-a737-9296aa5de242"
#define CHARACTERISTIC_UUID "a92055cb-8da1-4dff-a2fa-60afec43a7da"
#define bleServerName "zDisplay"

extern bool connected_state;


void BT_init();



#endif
