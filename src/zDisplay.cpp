#include <zDisplay.h>

TFT_eSPI tft = TFT_eSPI();

/** 
 *@brief Initialisiert das Display und das Touchpad 
 *@param tft  
 */ 
void Display_init(TFT_eSPI *tft)
{
    // Init Display
    tft->init();
    tft->fillScreen(TFT_BLACK);
    
    // Touchpad kalibrieren
    uint16_t calData[5] = { 281, 3516, 189, 3486, 2 };
    tft->setTouch(calData);
}