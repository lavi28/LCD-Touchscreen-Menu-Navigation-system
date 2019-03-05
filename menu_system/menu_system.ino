#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

// The FT6202 uses I2C
Adafruit_FT6206 ctp = Adafruit_FT6206();

// The display sues SPI, plus #9 and #10
#define TFT_CS	10
#define TFT_DC	9
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  // put your setup code here, to run once:
  setupDisplay();
  tft.fillScreen(ILI9341_YELLOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(5);
  delay(500);
}

void setupDisplay()
{
  tft.begin();
  if(!ctp.begin(40)) {
	while(1);
  }
  // set origin = left, top landscape (USB left upper)
  tft.setRotation(1);
}
