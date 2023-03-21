# WebServer

```cpp
#include "WebServer.h" //WebServer to host website

WebServer server(80);// WebServer init

// HTML
String website = "<!DOCTYPE html><html><head><title>Page Title</title></head><body><h1>WebServer Running</h1></body></html>";

void setup()
{
  //start WebServer
  server.on("/", []()
            { server.send(200, "text/html", website); });
  server.begin();
}

void loop()
{
  server.handleClient(); // webserver method that handles all Clients
}
```