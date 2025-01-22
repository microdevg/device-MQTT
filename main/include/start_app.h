#ifndef START_APP_H

#include "base.h"




/**
 * @brief  Function to connect to WiFi before starting app. If It can't connect, call error function. 
 * 
 * @param app  Aplication
 * @param error Function called when it can't connecte to WiFi.
 */
void    start_app(esp_callback_t app, esp_callback_t error);


#endif 


