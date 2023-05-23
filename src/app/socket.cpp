#include "WebSocketsServer.h" //WebSocket to communicate
#include "./socket.h"
#include "./json.h"
#include "./display.h"

WebSocketsServer socket(81);

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
    DeserializationError error = deserialize(payload);
    if (error)
    {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
    String msg = readJsonString("msg");
    String type = readJsonString("type");

    if (type == "bool")
    {
      bool b_value = readJsonBool(msg);
      if (msg == "led")
      {
        digitalWrite(LED_BUILTIN, b_value);
        String str = b_value ? "true" : "false";
        String objString = "{\"msg\":\"led\",\"type\":\"bool\",\"led\":" + str + "}";
        socket.broadcastTXT(objString);
      }
      Serial.println(b_value);
    }
    else if (type == "string")
    {
      String s_value = readJsonString(msg);
      if (msg == "screenTXT")
      {
        displayMessage(s_value);
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

void socketInit()
{
  socket.begin();
  socket.onEvent(socketEventHandler);
}

void socketLoop(){
  socket.loop();
}