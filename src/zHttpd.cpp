#include <zHttpd.h>

AsyncWebServer httpd(80);


void httpd_init()
{
  
  httpd.on("/hello_server", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(200, "text/plain", "Hallo AsyncWebServer!");
  });
  
  httpd.begin();
}