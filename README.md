# WiFi_Ducky

This project controls a pc "Rubber Ducky" style but controlled remotely with WiFi.

For this, the [**Heltec WiFi Kit 32 V3**](Heltec_WIFI_Kit_32_V3/README.md) works as a webserver to host a simple webpage that is used as a remote controller.

Since the [**Heltec WiFi Kit 32 V3**](Heltec_WIFI_Kit_32_V3/README.md) is a ESP32-S3 based board, it does not have the USB capabilities to emulate a keyboard. So to get around that, I added a second board to do that.

The [**Arduino Pro Micro**](Arduino_Pro_Micro/README.md) will work as a keyboard emulator and receive orders from the [**Heltec WiFi Kit 32 V3**](Heltec_WIFI_Kit_32_V3/README.md)

## Documentation

[OLED Documentation](notes/OLED.md)  
[WiFi Documentation](notes/WiFi.md)  
[WebServer Documentation](notes/WebServer.md)  

TODO:
 - [ ] [USB?](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/peripherals/usb_device.html)
