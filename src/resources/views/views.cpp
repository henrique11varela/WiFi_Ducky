#include "./views.h"

String rootView(){
    return "<!DOCTYPE html><html><head> <title>WiFi Ducky</title> <style> .btn { background-color: pink; border-radius: 2rem; width: 100%; aspect-ratio: 1; font-size: 4rem; display: flex; justify-content: center; align-items: center; } .grid { margin: 2rem; display: grid; grid-template-columns: repeat(2, 1fr); gap: 2rem; } </style></head><body> <div class=\"grid\"></div> <script> const Socket = new WebSocket(`ws://${window.location.hostname}:81/`); const gridEl = document.querySelector(\".grid\"); Socket.addEventListener(\"open\", () => { console.log(\"WebSocket open\"); const uiArr = []; uiArr.push(document.createElement(\"button\")); uiArr.at(-1).textContent = \"Led off\"; uiArr.at(-1).setAttribute(\"data-selector\", \"led\"); uiArr.at(-1).setAttribute(\"data-led-state\", \"off\"); uiArr.at(-1).classList.add(\"btn\"); uiArr.at(-1).onclick = function () { sendCommand( { \"msg\": \"led\", \"type\": \"bool\", \"led\": this.getAttribute(\"data-led-state\") == \"off\" ? true : false } ); this.setAttribute(\"data-led-state\", this.getAttribute(\"data-led-state\") == \"off\" ? \"on\" : \"off\"); this.textContent = \"Led: \" + this.getAttribute(\"data-led-state\"); }; uiArr.push(document.createElement(\"button\")); uiArr.at(-1).textContent = \"String send\"; uiArr.at(-1).setAttribute(\"data-selector\", \"screen_text\"); uiArr.at(-1).classList.add(\"btn\"); uiArr.at(-1).onclick = function () { sendCommand( { \"msg\": \"screenTXT\", \"type\": \"string\", \"screenTXT\": \"aaaa example\" } ); }; uiArr.forEach(function (el) { gridEl.append(el); }); }); Socket.addEventListener(\"close\", () => { console.log(\"WebSocket closed\") }); Socket.addEventListener(\"message\", (e) => { const obj = JSON.parse(e.data); console.log(obj); }); function sendCommand(obj) { console.log(\"Sent: \" + JSON.stringify(obj)); Socket.send(JSON.stringify(obj)); } </script></body></html>";
}

/*
header
nav
main
footer
*/