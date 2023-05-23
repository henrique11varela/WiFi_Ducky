#define WIFI_Kit_32 // heltec stuff
#include "heltec.h"
#include "WiFi.h"
#include "./routes/web.h"
#include "./app/socket.h"
#include "./app/display.h"

/* AccessPointInfo */
const char *ssid = "Woof";
const char *password = "PASSWORD";
IPAddress local_IP(192, 168, 1, 22);
IPAddress gateway(192, 168, 1, 5);
IPAddress subnet(255, 255, 255, 0);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Built in LED setup

  // Access point setup
  Serial.begin(115200);
  Serial.print("Setting up Access Point ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.print("Starting Access Point ... ");
  Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");
  Serial.print("IP address = ");
  Serial.println(WiFi.softAPIP());

  // OLED display ip
  displaySetup();
  displayIp(WiFi.softAPIP().toString());
  
  // Webserver and Websocket setup
  routesInit();
  socketInit();
}

void loop()
{
  routesLoop();
  socketLoop();
}
