#include <Arduino.h>
#include <zDisplay.h>
#include <zSD.h>
#include <zWifi.h>
#include <zBT.h>
#include <zHttpd.h>



// Task für Display
void Task_Display(void *pvParameters)
{

  while (1)
  {
    // store touchscreen cordinates
    uint16_t tx = 0,
             ty = 0;

    // Pressed will be set true is there is a valid touch on the screen
    bool pressed = tft.getTouch(&tx, &ty);

    // Draw a white spot at the detected coordinates
    if (pressed)
    {
      tft.fillCircle(tx, ty, 2, TFT_WHITE);
      Serial.print("x,y = ");
      Serial.print(tx);
      Serial.print(",");
      Serial.println(ty);
    }

    /**
      int coreID = xPortGetCoreID();
      Serial.printf("Task_Display() is running on Core %d\n", coreID);
      vTaskDelay(pdMS_TO_TICKS(100));
    */

  }
}


void setup()
{

  // Init serial
  Serial.begin(115200);
  while (!Serial)
    ;

  // Display und Touchscreen
  Display_init(&tft);

  // SD Card
  SD_init();

  // Wlan
  Wifi_init();

  // Bluetooth
  BT_init();

  //Webserver
  httpd_init();

  //
  // Tasks anlegen
  xTaskCreate(Task_Display, "Display", 10000, NULL, 1, NULL);

  Serial.write(0x0C); 


}

void loop()
{
 
}