#include "Arduino.h"
#include "./components.h"

/**
 * Button element
 * 
 * @param id
 * @param classes
 * @param textContent
 * @param attributes
 * @return Button element as a string
*/
String buttonComponent(String id, String classes, String textContent, String attributes)
{
    return "<button id=\"" + id + "\" class=\"" + classes + "\" " + attributes + ">" + textContent + "</button>";
};