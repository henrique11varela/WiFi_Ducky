#include "web.h"
#include "./resources/views/views.h"

/**
 * ROUTES
 */

// server.on("/", root);
// server.send(200, "text/html", pages[0]);

WebServer server(80);
String* pages;

void root()
{
    server.send(200, "text/html", rootView());
}

void routesInit()
{
    server.on("/", root);
    server.begin();
};

void routesLoop()
{
    server.handleClient(); // webserver method that handles all Clients
}
