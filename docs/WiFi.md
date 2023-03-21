# WiFi

## Connect to WiFi

```cpp
#include <WiFi.h>

// SSID and password of Wifi connection:
const char* ssid = "TYPE_YOUR_SSID_HERE";
const char* password = "TYPE_YOUR_PASSWORD_HERE";

void setup() {
  Serial.begin(115200);                 
 
  WiFi.begin(ssid, password); //Connect to wifi

  Serial.println("Establishing connection to WiFi with SSID: " + String(ssid));
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.print("Connected to network with IP address: ");
  Serial.println(WiFi.localIP());
}
```

## Access Point

``` cpp
#include "WiFi.h" //wifi module

// Access Point info setup
const char *ssid = "TYPE_YOUR_SSID_HERE";
const char *password = "TYPE_YOUR_PASSWORD_HERE";
IPAddress local_IP(192, 168, 1, 22);
IPAddress gateway(192, 168, 1, 5);
IPAddress subnet(255, 255, 255, 0);

void setup()
{
    // Access point init
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(ssid, password);
    //WiFi.softAPIP(); returns IP
}
```