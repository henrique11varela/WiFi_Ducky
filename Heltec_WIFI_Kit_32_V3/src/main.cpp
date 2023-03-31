#define WIFI_Kit_32 // heltec stuff
#include "heltec.h"
#include "WiFi.h"             //wifi module
#include "WebServer.h"        //WebServer to host website
#include "WebSocketsServer.h" //WebSocket to communicate
#include "ArduinoJson.h"
#include "html.h"

SSD1306Wire factory_display(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64); // OLED

/* AccessPointInfo */
const char *ssid = "Woof";
const char *password = "PASSWORD";
IPAddress local_IP(192, 168, 1, 22);
IPAddress gateway(192, 168, 1, 5);
IPAddress subnet(255, 255, 255, 0);

/* WebServer and WebSocket init */
WebServer server(80);
WebSocketsServer socket(81);
StaticJsonDocument<400> in;

void socketEventHandler(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
  switch (type)
  {
  case WStype_DISCONNECTED:
    Serial.println("Disconnected!");
    break;
  case WStype_CONNECTED:
    Serial.println("connected!");
    break;
  case WStype_TEXT:
  {
    DeserializationError error = deserializeJson(in, payload);
    if (error)
    {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
    String msg = in["msg"];
    String type = in["type"];

    if (type == "bool")
    {
      bool b_value = in[msg];
      if (msg == "led")
      {
        digitalWrite(LED_BUILTIN, b_value);
        String str = b_value ? "true" : "false";
        String objString = "{\"msg\":\"led\",\"type\":\"bool\",\"led\":" + str + "}";
        socket.broadcastTXT(objString);
      }/* asdasdasd */
      Serial.println(b_value);
    }
    else if (type == "string")
    {
      String s_value = in[msg];
      if (msg == "screenTXT")
      {
        factory_display.drawString(0, 16, s_value);
        factory_display.display();
      }
      Serial.println(s_value);
    }
  }
  break;
  default:
    Serial.print("shit happened! ");
    Serial.println(type);
    break;
  }
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Built in LED setup
  factory_display.init();       // OLED init

  // Access point setup
  Serial.begin(115200);
  Serial.print("Setting up Access Point ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.print("Starting Access Point ... ");
  Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");
  Serial.print("IP address = ");
  Serial.println(WiFi.softAPIP());

  // OLED display ip
  factory_display.drawString(0, 0, "192.168.1.22");
  factory_display.display();

  // start WebServer
  server.on("/", []()
            { server.send(200, "text/html", html); });
  server.begin();
  socket.begin();
  socket.onEvent(socketEventHandler);
}

void loop()
{
  server.handleClient(); // webserver method that handles all Clients
  socket.loop();
}
