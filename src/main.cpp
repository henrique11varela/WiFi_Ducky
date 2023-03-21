#define WIFI_Kit_32 //heltec stuff
#include "heltec.h"
#include "WiFi.h" //wifi module
#include "WebServer.h" //WebServer to host website
#include "html.h"

SSD1306Wire factory_display(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64); //OLED

/* AccessPointInfo */
const char *ssid = "Woof";
const char *password = "PASSWORD";
IPAddress local_IP(192, 168, 1, 22);
IPAddress gateway(192, 168, 1, 5);
IPAddress subnet(255, 255, 255, 0);

/* WebServer and WebSocket init */
WebServer server(80);

void turnLedOn(){
  digitalWrite(LED_BUILTIN, HIGH);
  server.send(200, "text/html", html);
}
void turnLedOff(){
  digitalWrite(LED_BUILTIN, LOW);
  server.send(200, "text/html", html);
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Built in LED setup
  factory_display.init(); //OLED init

  // Access point setup
  Serial.begin(115200);
  Serial.print("Setting up Access Point ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.print("Starting Access Point ... ");
  Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");
  Serial.print("IP address = ");
  Serial.println(WiFi.softAPIP());

  //OLED display ip
  factory_display.drawString(0, 0, "192.168.1.22");
  factory_display.display();

  //start WebServer
  server.on("/", []()
            { server.send(200, "text/html", html); });
  server.on("/ledOn", turnLedOn);
  server.on("/ledOff", turnLedOff);
  server.begin();
}

void loop()
{
  server.handleClient(); // webserver method that handles all Clients
}