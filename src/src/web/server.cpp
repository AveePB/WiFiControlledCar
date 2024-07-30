#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <WiFi.h>

#include "car/chassis.h"
#include "web/server.h"

// Web params
const char* HTML_CONTENT = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP32 Car Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial; text-align: center; margin: 20px; }
    button { padding: 16px 20px; margin: 10px; font-size: 24px; }
  </style>
</head>
<body>
  <h1>ESP32 2WD Car Control</h1>
  <button onmousedown="sendRequest('forward')" onmouseup="sendRequest('stop')">Forward</button>
  <button onmousedown="sendRequest('left')" onmouseup="sendRequest('stop')">Left</button>
  <button onmousedown="sendRequest('backward')" onmouseup="sendRequest('stop')">Backward</button>
  <button onmousedown="sendRequest('right')" onmouseup="sendRequest('stop')">Right</button>

  <script>
    function sendRequest(action) {
      var xhr = new XMLHttpRequest();
      xhr.open("GET", "/" + action, true);
      xhr.send();
    }
  </script>
</body>
</html>
)rawliteral";

const char* SSID = "ESP32-2WD-CAR";
const char* PASSWD = "P0lsl_2024";
const int PORT = 80;

// Server routes
const char* STOP_URL = "/stop";
const char* FORWARD_URL = "/forward";
const char* BACKWARD_URL = "/backward";
const char* LEFT_URL = "/left";
const char* RIGHT_URL = "/right";

WebApp::WebApp(): server(PORT) { }

void WebApp::initializeRoutes() {

    server.on("/", HTTP_GET, [this](AsyncWebServerRequest *request) {
        handleRoot(request); 
    });

    server.on(STOP_URL, HTTP_GET, [this](AsyncWebServerRequest *request) {
        handleMotorControl(request); 
    });

    server.on(FORWARD_URL, HTTP_GET, [this](AsyncWebServerRequest *request) {
        handleMotorControl(request); 
    });

    server.on(BACKWARD_URL, HTTP_GET, [this](AsyncWebServerRequest *request) {
        handleMotorControl(request); 
    });

    server.on(LEFT_URL, HTTP_GET, [this](AsyncWebServerRequest *request) {
        handleMotorControl(request); 
    });

    server.on(RIGHT_URL, HTTP_GET, [this](AsyncWebServerRequest *request) {
        handleMotorControl(request); 
    });
}

void WebApp::attachMotors(Motors m) {
    motors = m;
}

void WebApp::handleRoot(AsyncWebServerRequest* req) {
    req->send(200, "text/html", HTML_CONTENT);
}

void WebApp::handleMotorControl(AsyncWebServerRequest* req) {
    String url = req->url();

    if (url == STOP_URL)
        motors.stop();
    
    else if (url == FORWARD_URL)
        motors.moveForward();

    else if (url == BACKWARD_URL)
        motors.moveBackward();

    else if (url == LEFT_URL)
        motors.turnLeft();

    else if (url == RIGHT_URL)
        motors.turnRight();
    
    req->send(200, "text/plain", "OK");
}