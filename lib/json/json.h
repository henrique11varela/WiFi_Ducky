#if !defined(JsonH)
#define JsonH

#include "ArduinoJson.h"

DeserializationError deserialize(uint8_t *payload);

String readJsonString(String key);
bool readJsonBool(String key);

#endif // JsonH
