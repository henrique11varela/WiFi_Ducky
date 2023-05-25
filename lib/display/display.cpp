#define WIFI_Kit_32 // heltec stuff
#include "heltec.h"
#include "display.h"

/**
 * The object that represents the screen
*/
SSD1306Wire factory_display(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64); // OLED

/**
 * Initializes OLED screen
*/
void displaySetup()
{
    factory_display.init(); // OLED init
};

/**
 * Displays the {message} on line {line}
 * 
 * @param line The line it writes to
 * @param message The string to display 
*/
void displayMessage(int line,  String message)
{
    factory_display.drawString(0, line * 16, message);
    factory_display.display();
}