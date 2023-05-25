#include "./json.h"

StaticJsonDocument<400> in;

/**
 * Deserializes a JSON string
 * 
 * @param payload JSON string payload
 * @return Deserialization error
*/
DeserializationError deserialize(uint8_t *payload)
{
    return deserializeJson(in, payload);
}

/**
 * Returns JsonDoc[key]
 * 
 * @param key Json key
 * @return JsonDoc[key]
*/
String readJsonString(String key)
{
    return in[key];
}

/**
 * Returns JsonDoc[key]
 * 
 * @param key Json key
 * @return JsonDoc[key]
*/
bool readJsonBool(String key)
{
    return in[key];
}
