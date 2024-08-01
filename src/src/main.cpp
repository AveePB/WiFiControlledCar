#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "car/chassis.h"

// Constants
const int BAUD_RATE = 9600;
const int PORT = 80;
const char* SSID = "Esp32_2WD";
const char* PASSWD = "P0lsl2024";
const char* htmlPage = R"html(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP32 Car Control</title>
    <style>
        body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            background-color: #f0f0f0;
            font-family: Arial, sans-serif;
        }
        .container {
            text-align: center;
            background-color: #ffffff;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        .button {
            display: inline-block;
            width: 100px;
            height: 100px;
            margin: 10px;
            font-size: 18px;
            cursor: pointer;
            background-color: #4CAF50;
            color: white;
            border: none;
            border-radius: 10px;
            transition: background-color 0.3s;
            user-select: none; /* Prevent text selection on touch devices */
        }
        .button:disabled {
            background-color: #a5d6a7;
            cursor: not-allowed;
        }
        .button:hover:not(:disabled) {
            background-color: #45a049;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Control Your ESP32 Car</h1>
        <div>
            <button class="button" id="forward">Forward</button>
        </div>
        <div>
            <button class="button" id="left">Left</button>
            <button class="button" id="backward">Backward</button>
            <button class="button" id="right">Right</button>
        </div>
    </div>

    <script>
        let commandInterval;
        let activeButton = null;

        function sendCommand(command) {
            fetch(`/${command}`)
                .then(response => response.text())
                .then(data => console.log(data))
                .catch(error => console.error('Error:', error));
        }

        function startCommand(command, button) {
            if (activeButton !== button) {
                if (activeButton) {
                    stopCommand();
                }
                activeButton = button;
                sendCommand(command);  // Send initial command
                commandInterval = setInterval(() => sendCommand(command), 100);  // Continue sending command every 100ms
                disableButtons(button);  // Disable all buttons except the active one
            }
        }

        function stopCommand() {
            if (activeButton) {
                clearInterval(commandInterval);
                sendCommand('stop');  // Send stop command when button is released
                enableButtons();  // Enable all buttons
                activeButton = null;
            }
        }

        function disableButtons(exceptButton) {
            document.querySelectorAll('.button').forEach(button => {
                if (button !== exceptButton) {
                    button.disabled = true;
                }
            });
        }

        function enableButtons() {
            document.querySelectorAll('.button').forEach(button => {
                button.disabled = false;
            });
        }

        // Setup event listeners
        document.querySelectorAll('.button').forEach(button => {
            button.addEventListener('mousedown', () => startCommand(button.id, button));
            button.addEventListener('mouseup', stopCommand);
            button.addEventListener('mouseleave', stopCommand); // Handle mouse leaving the button
            button.addEventListener('touchstart', (e) => { 
                e.preventDefault(); 
                startCommand(button.id, button); 
            });
            button.addEventListener('touchend', stopCommand);
        });
    </script>
</body>
</html>
)html";


// URLs
const char* STOP_URL = "/stop";
const char* FORWARD_URL = "/forward";
const char* BACKWARD_URL = "/backward";
const char* LEFT_URL = "/left";
const char* RIGHT_URL = "/right";

// IP addresses
IPAddress localIP(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnetMask(255,255,255,0);

// Components
WebServer server(PORT);
Motors motors;

// Function declarations
void handleRoot();
void handleMovement();
void handleNotFound();

void setup() {
    // Initialize serial communication
    Serial.begin(BAUD_RATE);

    motors.initialize();

    // Initialize WiFi
    WiFi.softAP(SSID, PASSWD);
    WiFi.softAPConfig(localIP, gateway, subnetMask);
    delay(1000);

    // Initialize server
    server.on("/", handleRoot);
    server.on(STOP_URL, []() { 
        handleMovement();
        motors.stop();
    });
    server.on(FORWARD_URL, []() { 
        handleMovement();
        motors.moveForward();
    });

    server.on(BACKWARD_URL, []() { 
        handleMovement();
        motors.moveBackward();
    });
    server.on(LEFT_URL, []() { 
        handleMovement();
        motors.turnLeft();
    });
    server.on(RIGHT_URL, []() { 
        handleMovement();
        motors.turnRight();
    });
    server.onNotFound(handleNotFound);
    server.begin();
}

void loop() {
    server.handleClient();
}

void handleRoot() {
    Serial.println("Client tries to access the root endpoint");
    server.send(200, "text/html", htmlPage);
}

void handleMovement() {
    Serial.println("Client tries to access the movement endpoint");
    server.send(200, "text/html", htmlPage);
}

void handleNotFound() {
    Serial.println("Client tries to access the invalid endpoint");
    server.send(404, "text/plain", "Not Found 404");
}