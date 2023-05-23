#include "json.h"

StaticJsonDocument<400> in;

DeserializationError deserialize(uint8_t *payload)
{
    return deserializeJson(in, payload);
}

String readJsonString(String key)
{
    return in[key];
}
bool readJsonBool(String key)
{
    return in[key];
}
