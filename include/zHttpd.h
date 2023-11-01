#ifndef ZHTTPD
#define ZHTTPD
#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>


extern AsyncWebServer httpd;

void httpd_init();

#endif