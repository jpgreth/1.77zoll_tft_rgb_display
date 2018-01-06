# Test für das 1.77 Zoll SPI TFT-Display mit ST7735 Chipsatz

Das hier verwendete habe ich von https://shop.diy-dreams.de/collections/displays/products/1-77-zoll-spi-tft-display

## Verkabelung

| Display (Pin) | Arduino Nano |
|--------|--------|
|GND  (1) | GND|
|VCC  (2) | 5V|
|SCK  (3) | D13|
|SDA  (4) | D11|
|RES  (5) | D8|
|RS   (6) | D9|
|CS   (7) | D10|
|LEDA (8) | 3.3V|


LEDA kann auch an 5V betrieben werden, doch dann wird das Display sehr schnell sehr heiß - was ich nicht für optimal halte. Beim Betrieb mit 3.3V ist das Dispklay nur minimal dunkler und bleibt kalt.

Bei der Initialisierung  des ST7735-Chips, muss beim AZ-Delivery 1.77" 160x128px RGB TFT als Wert "INITR_GREENTAB" gesetzt sein, ansonsten bekommt man Pixelfehler rechts und unten.
Hinweis: https://github.com/adafruit/Adafruit-ST7735-Library/blob/master/examples/soft_spitftbitmap/soft_spitftbitmap.ino#L52 (Zeile 52-65)
