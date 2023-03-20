#define WIFI_Kit_32
#include "heltec.h"
#include "WiFi.h"

SSD1306Wire factory_display(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64);

void setup() {
  // Serial monitor speed = 115200
  pinMode(LED_BUILTIN, OUTPUT); //Built in LED setup
  factory_display.init();
}

void loop() {

}