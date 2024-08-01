#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H
#include <WebServer.h>
#include "car/chassis.h"

extern const char* HTML_PAGE;

class ClientHandler {
    public:
        static void handleRoot(WebServer* ws);
        static void handleNotFound(WebServer* ws);        
        static void handleMovement(WebServer* ws, Motors* motors, Movement movement);
};

#endif