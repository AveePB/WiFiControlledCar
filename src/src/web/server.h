#pragma once
#ifndef SERVER_H
#define SERVER_H
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <WiFi.h>

#include "car/chassis.h"

// Web params
extern const char* HTML_CONTENT;
extern const char* SSID;
extern const char* PASSWD;
extern const int PORT;

// Server routes
extern const char* STOP_URL;
extern const char* FORWARD_URL;
extern const char* BACKWARD_URL;
extern const char* LEFT_URL;
extern const char* RIGHT_URL;

class WebApp {
    public:
        WebApp();
        void initializeRoutes();
        void attachMotors(Motors m);
    
    private:
        AsyncWebServer server;
        Motors motors;
        
        void handleRoot(AsyncWebServerRequest* req);
        void handleMotorControl(AsyncWebServerRequest* req);
};

#endif