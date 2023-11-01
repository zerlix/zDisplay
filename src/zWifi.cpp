#include <zWifi.h>

void Wifi_init() 
{
  // wlan settings
  WiFi.setHostname("zDisplay");
  WiFi.setAutoReconnect(true);
  

  // wlan verbindung erstellen 
  WiFi.begin(WIFI_SSID,  WIFI_PASSWORD);
  
  // Warten bis die wlan verbindung steht
  Serial.print("Connecting.");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  
  // wlan information ausgeben
  Serial.println("\nWiFi is connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
}