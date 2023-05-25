#include "./views.h"
#include "../components/components.h"

/**
 * master view
 * @param html 
 * @param css 
 * @param js 
 * @return webpage as a string
*/
String masterView(String html, String css, String js){
    String output = "<!DOCTYPE html><html><head> <title>WiFi Ducky</title> <style>" + css + "</style></head><body> " + html + " <script> const Socket = new WebSocket(`ws://${window.location.hostname}:81/`); const gridEl = document.querySelector(\".grid\"); Socket.addEventListener(\"open\", () => {" + js + "}); Socket.addEventListener(\"close\", () => { console.log(\"WebSocket closed\") }); Socket.addEventListener(\"message\", (e) => { const obj = JSON.parse(e.data); console.log(obj); }); function sendCommand(obj) { console.log(\"Sent: \" + JSON.stringify(obj)); Socket.send(JSON.stringify(obj)); } </script></body></html>";
    return output;
};

/**
 * root webpage
*/
String rootView()
{
    String html = "<div class=\"grid\"> " + buttonComponent("ledBtn", "btn", "Led off", "data-selector=\"led\" data-led-state=\"off\"") + buttonComponent("strBtn", "btn", "String send", "data-selector=\"screen_text\"") + " </div>";

    String css = ".btn { background-color: pink; border-radius: 2rem; width: 100%; aspect-ratio: 1; font-size: 4rem; display: flex; justify-content: center; align-items: center; } .grid { margin: 2rem; display: grid; grid-template-columns: repeat(2, 1fr); gap: 2rem; }";

    String js = "const gridEl = document.querySelector(\".grid\"); const ledBtn = gridEl.querySelector(\"#ledBtn\"); ledBtn.onclick = function () { sendCommand({ \"msg\": \"led\", \"type\": \"bool\", \"led\": this.getAttribute(\"data-led-state\") == \"off\" ? true : false }); this.setAttribute(\"data-led-state\", this.getAttribute(\"data-led-state\") == \"off\" ? \"on\" : \"off\"); this.textContent = \"Led: \" + this.getAttribute(\"data-led-state\"); }; const strBtn = gridEl.querySelector(\"#strBtn\"); strBtn.onclick = function () { sendCommand({ \"msg\": \"screenTXT\", \"type\": \"string\", \"screenTXT\": \"aaaa example\" }); };";

    return masterView(html, css, js);
}



