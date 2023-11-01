#include <zSD.h>


/**
 * @brief initialisiert den SD karten slot
 */
void SD_init()
{

  // Kann der SD Karten Slot angesprochen werden ?
  if (!SD.begin(SD_CS))
  {
    Serial.println("Kann SD Slot nicht initalisieren.");
    return;
  }
  
  // Ist Karte eingesteckt und kann gelesen werden ?
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE)
  {
    Serial.println("Keine SD Karte vorhanden oder Karte defekt.");
    return;
  }

}