#ifndef WIFI_H
#define WIFI_H

#include  "base.h"







/**
 * @brief Initializes WiFi connection in STATION MODE by default.
 * 
 * @param WIFI_ID Name of the WiFi network
 * @param PASS Password of the WiFi network
 * @param cb_conn Callback function called when the device successfully connects to the network
 * @param cb_desconn Callback function called when the device disconnects from the network
 * @param cb_failed Callback function called when the connection attempts to the network fail
 * @return esp_err_t 
 */
esp_err_t wifi_connect(const char* WIFI_ID, const char * PASS,
                       esp_callback_t cb_conn, 
                       esp_callback_t cb_desconn,
                       esp_callback_t cb_failed);

/**
 * @brief Releases resources allocated for WiFi.
 * 
 * @return esp_err_t 
 */
esp_err_t wifi_disconnect(void);

#endif