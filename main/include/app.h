#ifndef START_APP_H

#include "start_app.h"



/**
 * @file app.h
 * @brief Main header file for the ESP32 MQTT project.
 * 
 * This project is designed to run on an ESP32 microcontroller. Its primary function is to connect 
 * to a WiFi network and communicate with an MQTT host. The key features and workflow are as follows:
 * 
 * - **WiFi Connection**:
 *   - The ESP32 attempts to connect to a WiFi network using credentials stored in the flash memory.
 *   - If the stored credentials are invalid or the connection fails, the device starts a 
 *     web-based configuration interface.
 * 
 * - **WiFi Configuration Mode**:
 *   - In configuration mode, the ESP32 creates a WiFi access point with the SSID `WCONFIG`.
 *   - The user can connect to this access point and navigate to the web interface at 
 *     `http://my-esp32.com`.
 *   - Through this web interface, the user can provide the WiFi credentials to be stored in flash.
 * 
 * - **MQTT Communication**:
 *   - Once the ESP32 successfully connects to the WiFi network, it establishes a connection with an 
 *     MQTT host.
 *   - The device can publish messages to specific topics and subscribe to topics for receiving data.
 * 
 * This project demonstrates the integration of WiFi provisioning, persistent storage, and MQTT 
 * communication on an ESP32 platform. It is suitable for IoT applications requiring flexible 
 * network setup and real-time data exchange.
 * 
 * @note Ensure that the hostname `http://my-esp32.com` is properly resolved by the user's device. 
 *       This may require setting up mDNS or manually editing the host's DNS configuration.
 * 
 * @author German Velardez
 * @date [21/01/2025
 * @version 1.0.0
 */




/**
 * @brief My aplication
 * 
 */
void app(void);



#endif START_APP_H