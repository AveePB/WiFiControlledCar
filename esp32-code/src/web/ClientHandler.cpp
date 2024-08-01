#include <WebServer.h>
#include "web/ClientHandler.h"
#include "car/chassis.h"

const char* HTML_PAGE = R"html(
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

void ClientHandler::handleRoot(WebServer* ws) { 
    ws->send(200, "text/html", HTML_PAGE);
}

void ClientHandler::handleNotFound(WebServer* ws) { 
    ws->send(404, "text/plain", "Not Found 404");
}

void ClientHandler::handleMovement(WebServer* ws, Motors* motors, Movement movement) { 
    if (movement == Movement::Stop)
        motors->stop();

    else if (movement == Movement::Forward)
        motors->moveForward();    

    else if (movement == Movement::Backward)
        motors->moveBackward();

    else if (movement == Movement::Left)
        motors->turnLeft();

    else if (movement == Movement::Right)
        motors->turnRight();

    ws->send(200, "text/html", HTML_PAGE);
}
