#include <TFT_eSPI.h>  // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Custom pins from User_Setup.h

void setup() {
  Serial.begin(115200);
  Serial.println("ST7789 Hardware SPI Test!");

  tft.init();
  tft.setRotation(3);       // 0-3 if image is sideways/upside-down

  // --- Test Pattern ---

  tft.fillScreen(TFT_BLACK);
  delay(500);

  tft.fillScreen(TFT_RED);
  delay(500);

  tft.fillScreen(TFT_GREEN);
  delay(500);

  tft.fillScreen(TFT_BLUE);
  delay(1000);

  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(3);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(20, 100);
  tft.println("ESP32 + ST7789");

  tft.setTextSize(2);
  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(60, 150);
  tft.println("TFT_eSPI Works!");

  tft.drawRect(10, 10, 220, 50, TFT_CYAN);
  tft.fillCircle(120, 200, 30, TFT_MAGENTA);
}

void loop() {
  // Test runs once in setup
}
