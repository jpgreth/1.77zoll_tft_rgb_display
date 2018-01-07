/***
 * Test für das 1,77 Zoll SPI TFT-Display
 * v1.0 - 2018-01-06
 * Jan Greth <github@greth.me>
 ***/

/* Pinnung
 *  Display (Pin) - Arduino Nano
 *  GND  (1) - GND  
 *  VCC  (2) - 5V
 *  SCK  (3) - D13
 *  SDA  (4) - D11
 *  RES  (5) - D8
 *  RS   (6) - D9
 *  CS   (7) - D10
 *  LEDA (8) - 3.3V
 *  
 *  LEDA kann auch an 5V doch dann wird das Display sehr schnell sehr heiß - was ich nicht für optimal halte.
 *  Beim Betrieb mit 3.3V ist das Dispklay nur minimal dunkler und bleibt kalt.
 */

#define TFT_PIN_CS   10 // Arduino-Pin an Display CS   
#define TFT_PIN_DC   9  // Arduino-Pin an 
#define TFT_PIN_RST  8  // Arduino Reset-Pin

#include <SPI.h>             // SPI für die Kommunikation
#include <Adafruit_GFX.h>    // Adafruit Grafik-Bibliothek wird benötigt
#include <Adafruit_ST7735.h> // Adafruit ST7735-Bibliothek wird benötigt

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_PIN_CS, TFT_PIN_DC, TFT_PIN_RST);  // ST7735-Bibliothek Setup

void setup(void) {

  /***
   * ST7735-Chip initialisieren (INITR_BLACKTAB / INITR_REDTAB / INITR_GREENTAB)
   * Muss bei AZ-Delivery 1.77'' 160x128px RGB TFT INITR_GREENTAB sein ansonsten Pixelfehler rechts und unten.
   * Hinweis: https://github.com/adafruit/Adafruit-ST7735-Library/blob/master/examples/soft_spitftbitmap/soft_spitftbitmap.ino#L52
   * Zeile 52-65  
   ***/
   
  tft.initR(INITR_GREENTAB);   
  
}

void loop() {

  /***  
   * Die tft Funktionen kommen aus der Adafruit Grafik-Bibliothek (Adafruit_GFX) die möglichen Funktionen finden sich unter:
   * https://learn.adafruit.com/adafruit-gfx-graphics-library?view=all
   * bzw.
   * https://cdn-learn.adafruit.com/downloads/pdf/adafruit-gfx-graphics-library.pdf
   ***/

  // fillScreen(farbe);
  tft.fillScreen(ST7735_BLACK);

  // drawRect(pos_links,pos_oben,breite,hoehe,farbe);
  tft.drawRect(0,0,128,160,ST7735_BLUE); 
  
  // setTextSize(groesse);
  tft.setTextSize(1);
 
  // setCursor(links,oben);
  tft.setCursor(30,10);
 
    // setTextColor(farbe);
  tft.setTextColor(ST7735_WHITE);
  
  // print(text);
  tft.print("Hello World!");

  // drawLine(links_start,oben_start,links_ende,oben_ende,farbe);
  tft.drawLine(1,25,127,25,ST7735_BLUE);

  // Hier kommt PacMan!
  int ol = 35;
  int ul = 115;

  do {
    tft.fillCircle(64,75,40, ST7735_YELLOW);
    tft.fillTriangle(65,75, 110,ol, 110,ul, ST7735_BLACK);
    tft.fillCircle(64,60,3, ST7735_BLACK);
    ol = ol + 10;
    ul = ul - 10;
    delay(500);
  } while(ol < 75);

  do {
    tft.fillCircle(64,75,40, ST7735_YELLOW);
    tft.fillTriangle(65,75, 110,ol, 110,ul, ST7735_BLACK);
    tft.fillCircle(64,60,3, ST7735_BLACK);
    ol = ol - 10;
    ul = ul + 10;
    delay(500);
  } while(ol >= 35);

  // setCursor(von links,von oben);
  tft.setCursor(25,135);
  // setTextColor(farbe);
  tft.setTextColor(ST7735_GREEN);
  // print(text);
  tft.print("www.greth.me");

  // 5 Sekunden warten
  delay(5000); 
}


