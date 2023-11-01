#ifndef ZDISPLAY
#define ZDSIPLAY


/**
 * Display Configuration
 * Wenn TFT-eSPI benutzt wird dann
 * müssen die Werte in der Datei "..\TFT_eSPI\User_Setup.h" gesetzt 
 * werden oder der Bibilothek anders bekannt gemacht werden
 * 
 ************************* Start: "..\TFT_eSPI\User_Setup.h" ***************************/
#define ILI9341_DRIVER
#define TFT_WIDTH  240
#define TFT_HEIGHT 320

// LED back-light pin
#define TFT_BL   27            
#define TFT_BACKLIGHT_ON HIGH 

// TFT Pins (HSPI)
#define USE_HSPI_PORT
#define TFT_MISO 12
#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_CS   15  // Chip select control pin//choose what you want
#define TFT_DC    2  // Data Command control pin//choose what you want
#define TFT_RST  -1  // Set TFT_RST to -1 ( if display RESET is connected to ESP32 board RST)

/**
 * Touchscreen Configuration
 * Touch Pins (HSPI)
 */
#define TOUCH_DO 12 
#define TOUCH_DIN 13 
#define TOUCH_CLK 14
#define TOUCH_CS 33 


// Define the SPI clock frequency, this affects the graphics rendering speed. Too
// fast and the TFT driver will not keep up and display corruption appears.
// With an ILI9341 display 40MHz works OK, 80MHz sometimes fails
//#define SPI_FREQUENCY  15999999
#define SPI_FREQUENCY  40000000

// Optional reduced SPI frequency for reading TFT
#define SPI_READ_FREQUENCY  20000000

// The XPT2046 requires a lower SPI clock rate of 2.5MHz so we define that here:
#define SPI_TOUCH_FREQUENCY  600000


/**
 * Font configuration 
 */
#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
//#define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

// Comment out the #define below to stop the SPIFFS filing system and smooth font code being loaded
// this will save ~20kbytes of FLASH
#define SMOOTH_FONT

/**********************************************  ENDE:"..\TFT_eSPI\User_Setup.h" *************************************************/



#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <SD.h>

extern TFT_eSPI tft; // in zDisplay.cpp

/** 
 *@brief Initialisiert das Display und das Touchpad 
 *@param tft  
 */ 
void Display_init(TFT_eSPI *tft);

#endif