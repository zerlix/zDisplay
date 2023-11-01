#include <zBT.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

bool connected_state = false;   

BLEAdvertising* pAdvertising = NULL;
BLEServer* pServer = NULL;
BLEService *pService = NULL;
BLECharacteristic* pCharacteristic = NULL;


class MyServerCallbacks: public BLEServerCallbacks  
{
    
    void onConnect(BLEServer *pServer)
    {
      connected_state = true;    
    }

    void onDisconnect(BLEServer *pServer)
    {
      connected_state = false;
    }

};



void BT_init()
{
  BLEDevice::init(bleServerName);  
  pServer = BLEDevice::createServer();  
  pServer->setCallbacks(new MyServerCallbacks());  
  pService = pServer->createService(SERVICE_UUID); 

  pCharacteristic = pService->createCharacteristic(  //Create ble feature（Characterristic_UUID）
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristic->setValue("Hello World");

  pService->start();

  pAdvertising = BLEDevice::getAdvertising();  //A bleadvertising class pointer padvertising is defined, which points to bledevice:: getadvertising()
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  pAdvertising->start();  //Start broadcasting

}

