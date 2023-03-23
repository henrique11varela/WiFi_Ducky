#pragma once
#include <WString.h>
// HTML
String html = "<!DOCTYPE html><html><head> <title>WiFi Ducky</title> <style> .btn { background-color: pink; border-radius: 2rem; width: 100%; aspect-ratio: 1; font-size: 4rem; display: flex; justify-content: center; align-items: center; } .grid { margin: 2rem; display: grid; grid-template-columns: repeat(2, 1fr); gap: 2rem; } </style></head><body> <div class='grid'> <a href='/ledOn'> <div class='btn'>Led On</div> </a> <a href='/ledOff'> <div class='btn'>Led Off</div> </a> </div></body></html>";