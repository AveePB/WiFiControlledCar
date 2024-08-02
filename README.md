# WiFi Controlled Car (2WD)

This project focuses on combining multiple IoT skills to gain valuable experience. The ESP32 hosts a web application that is used to control the 2WD car.

![Image](image_url_here)

## Electronic Components

The car is built using two decks and a few electronic components:

- **ESP32**: a microcontroller;
- **2 x 6V DC Motors (48:1)**: motors with wheels;
- **L298N**: a motor driver;
- **4 x Li-ion batteries**: a power source;

## GPIO Pins

The ESP32 microcontroller possesses a variety of pins, most of them are the GPIO:

- **1**: controls the backward rotation of the left motor ***(IN3)***; <- L
- **3**: controls the forward rotation of the right motor ***(IN2)***; <- R
- **19**: controls the speed of the right motor ***(ENA)***; <- R
- **21**: controls the backward rotation of the right motor ***(IN1)***; <- R
- **22**: controls the forward rotation of the left motor ***(IN4)***; <- L
- **23**: controls the speed of the left motor ***(ENA)***; <- L

## Controlling the Car

The car is controlled using the web app hosted on the ESP32 board. You need to connect to the WiFi network in order to access the control panel.

### What to do:

1. Connect to the WiFi network ***(Esp32_2WD)*** using the password ***(P0lsl2024)***;
2. Access the web page using the IP address ***(192.168.1.1)***. You can use any web browser or device;
3. Enjoy your ride and be a responsible driver.
