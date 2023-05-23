#include "display.h"

SSD1306Wire factory_display(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64); // OLED


void displaySetup()
{
    factory_display.init(); // OLED init
};

void displayIp(String ip)
{
    factory_display.drawString(0, 0, ip);
    factory_display.display();
}

void displayMessage(String message)
{
    factory_display.drawString(0, 16, message);
    factory_display.display();
}