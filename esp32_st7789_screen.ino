  #include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// Software SPI pins — all within 12-14, 25-27, 32-33
#define TFT_SCLK  13   // SCL
#define TFT_MOSI  12   // SDA (MOSI)
#define TFT_CS    26   // CS
#define TFT_DC    25   // DC
#define TFT_RST   14   // RES
// BLK tied to 3.3V directly (no GPIO needed)

// Software SPI constructor: CS, DC, MOSI, SCLK, RST
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  Serial.begin(115200);
  Serial.println("ST7789 Software SPI Test!");

  // Software SPI runs at ~10-15 MHz equivalent — plenty for a test
  tft.init(240, 320, SPI_MODE2);
  tft.setRotation(1);       // 0-3 if image is sideways/upside-down
  tft.setSPISpeed(27000000); // Lower this if you get flicker/noise

  // --- Test Pattern ---

  tft.fillScreen(ST77XX_BLACK);
  delay(500);

  tft.fillScreen(ST77XX_RED);
  delay(500);

  tft.fillScreen(ST77XX_GREEN);
  delay(500);

  tft.fillScreen(ST77XX_BLUE);
  delay(1000);

  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(20, 100);
  tft.println("ESP32 + ST7789");
  
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(60, 150);
  tft.println("SoftSPI Works!");

  tft.drawRect(10, 10, 220, 50, ST77XX_CYAN);
  tft.fillCircle(120, 200, 30, ST77XX_MAGENTA);
}

void loop() {
  // Test runs once in setup
}