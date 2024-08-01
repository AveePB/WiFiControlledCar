#include <WiFi.h>
#include <WebServer.h>
#include "car/chassis.h"
#include "web/ClientHandler.h"

// Constants
const int PORT = 80;
const char* SSID = "Esp32_2WD";
const char* PASSWD = "P0lsl2024";

// IP addresses
IPAddress localIP(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnetMask(255,255,255,0);

// Components
WebServer server(PORT);
Motors motors;

void setup() {
    // Initialize motors
    motors.initialize();

    // Initialize WiFi
    WiFi.softAP(SSID, PASSWD);
    WiFi.softAPConfig(localIP, gateway, subnetMask);
    delay(1000);

    // Initialize server
    server.on("/", []{
        ClientHandler::handleRoot(&server);
    });

    server.on("/stop", []() { 
        ClientHandler::handleMovement(&server, &motors, Movement::Stop);
    });

    server.on("/forward", []() { 
        ClientHandler::handleMovement(&server, &motors, Movement::Forward);
    });

    server.on("/backward", []() { 
        ClientHandler::handleMovement(&server, &motors, Movement::Backward);
    });

    server.on("/left", []() { 
        ClientHandler::handleMovement(&server, &motors, Movement::Left);
    });

    server.on("/right", []() { 
        ClientHandler::handleMovement(&server, &motors, Movement::Right);
    });

    server.onNotFound([]{
        ClientHandler::handleNotFound(&server);
    });

    server.begin();
}

void loop() {
    server.handleClient();
}