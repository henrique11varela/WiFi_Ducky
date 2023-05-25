#include "web.h"
#include "WebServer.h"        //WebServer to host website
#include "./resources/views/views.h"


/**
 * ROUTES
 */
// server.on("/", root);
// server.send(200, "text/html", viewFunction);

WebServer server(80);
String* pages;

/**
 * 
*/
void root()
{
    server.send(200, "text/html", rootView());
}

/**
 * Webserver setup function
*/
void routesInit()
{
    server.on("/", root);
    server.begin();
};

/**
 * Webserver loop function
*/
void routesLoop()
{
    server.handleClient(); // webserver method that handles all Clients
}
