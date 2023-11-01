#ifndef ZSD
#define ZSD
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>


/**
 * SD Karten Slot Konfiguration
 * SD Karten Pins (VSPI)
 */
#define SD_MISO 19 
#define SD_MOSI 23
#define SD_SCLK 18
#define SD_CS   5               


/**
 * @brief initialisiert den SD karten slot
 */
void SD_init();

#endif