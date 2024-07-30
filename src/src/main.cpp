#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <WiFi.h>

#include "car/chassis.h"
#include "web/server.h"

Motors motors;
WebApp webApp;

void setup() {
    // Set up WiFi network
    SPIFFS.begin();
    WiFi.softAP(SSID, PASSWD);

    // Set up components
    motors.initialize();

    webApp.attachMotors(motors);
    webApp.initializeRoutes();

}

void loop() { }