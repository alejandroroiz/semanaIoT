#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define DBG_OUTPUT_PORT Serial

const char *ssid = "wifi-ssid";
const char *password = "wifi-password";

ESP8266WebServer server(80);

bool ledOn = false;

void setup(void)
{
    DBG_OUTPUT_PORT.begin(115200);
    DBG_OUTPUT_PORT.print("\n");
    DBG_OUTPUT_PORT.setDebugOutput(true);

    //WIFI INIT
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);

    DBG_OUTPUT_PORT.println("");
    DBG_OUTPUT_PORT.print("Connected! IP address: ");
    DBG_OUTPUT_PORT.println(WiFi.softAPIP());

    //called when the url is not defined here
    server.onNotFound([]() {
        server.send(200, "text/html", "<!DOCTYPE html><html><head> <meta charset=\"utf-8\"\/> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <title>Prueba LED<\/title> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><\/head><body> <style>.button, button, input[type=\"submit\"], input[type=\"reset\"], input[type=\"button\"]{display: inline-block; height: 38px; padding: 0 30px; color: #555; text-align: center; font-size: 11px; font-weight: 600; line-height: 38px; letter-spacing: .1rem; text-transform: uppercase; text-decoration: none; white-space: nowrap; background-color: transparent; border-radius: 4px; border: 1px solid #bbb; cursor: pointer; box-sizing: border-box;}.button:hover, button:hover, input[type=\"submit\"]:hover, input[type=\"reset\"]:hover, input[type=\"button\"]:hover, .button:focus, button:focus, input[type=\"submit\"]:focus, input[type=\"reset\"]:focus, input[type=\"button\"]:focus{color: #333; border-color: #888; outline: 0;}.button.button-primary, button.button-primary, input[type=\"submit\"].button-primary, input[type=\"reset\"].button-primary, input[type=\"button\"].button-primary{color: #FFF; background-color: #33C3F0; border-color: #33C3F0;}.button.button-primary:hover, button.button-primary:hover, input[type=\"submit\"].button-primary:hover, input[type=\"reset\"].button-primary:hover, input[type=\"button\"].button-primary:hover, .button.button-primary:focus, button.button-primary:focus, input[type=\"submit\"].button-primary:focus, input[type=\"reset\"].button-primary:focus, input[type=\"button\"].button-primary:focus{color: #FFF; background-color: #1EAEDB; border-color: #1EAEDB;}<\/style> <button onclick=\"toggleLed()\" class=\"button btcolor\">Toggle LED<\/button><\/body><script>function toggleLed(){var xhttp=new XMLHttpRequest(); xhttp.onreadystatechange=function (){if (this.readyState==4 && this.status==200){document.getElementById(\"demo\").innerHTML=this.responseText;}}; xhttp.open(\"GET\", \"\/changeLed\", true); xhttp.send();}<\/script><\/html>");
    });

    pinMode(LED_BUILTIN, OUTPUT); // declare LED as output

    server.on("/changeLed", HTTP_GET, []() {
        if (ledOn)
        {
            digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on (Note that LOW is the voltage level
            ledOn = !ledOn;
        }
        else
        {
            digitalWrite(LED_BUILTIN, LOW); // Turn the LED off
            ledOn = !ledOn;
        }
    });

    server.begin();
    DBG_OUTPUT_PORT.println("HTTP server started");
}

void loop(void)
{
    server.handleClient();
}
