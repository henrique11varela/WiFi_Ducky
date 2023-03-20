#define WIFI_Kit_32 //heltec stuff
#include "heltec.h"
#include "WiFi.h" //wifi module
#include "WebServer.h" //WebServer to host website
#include "WebSocketsServer.h" //Websocket for instant comunication
#include "ArduinoJson.h" //JSON comunication

SSD1306Wire factory_display(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64); //OLED

// Access Point info
const char *ssid = "Woof";
const char *password = "PASSWORD";
IPAddress local_IP(192, 168, 1, 22);
IPAddress gateway(192, 168, 1, 5);
IPAddress subnet(255, 255, 255, 0);

// WebServer and WebSocket init
WebServer server(80);
WebSocketsServer webSocket(81);

// HTML
String website = "";
String part1 = "<!DOCTYPE html><html><head><title>Page Title</title></head><body style='background-color: #EEEEEE;'><span style='color: #003366;'><h1>Lets generate a random number</h1><p>The random number is: ";
String part2 = "</p></span></body></html>";

int counter = 0;
int interval = 5000; // virtual delay
unsigned long previousMillis = 0; // Tracks the time since last event fired

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


  website = part1 + String(counter) + part2;

  //start WebServer
  server.on("/", []()
            { server.send(200, "text/html", website); });
  server.begin();
}

void loop()
{
  server.handleClient(); // webserver method that handles all Clients

  unsigned long currentMillis = millis();
  if ((unsigned long)(currentMillis - previousMillis) >= interval)
  {
    counter++;
    website = part1 + String(counter) + part2;
    previousMillis = currentMillis;
  }
}