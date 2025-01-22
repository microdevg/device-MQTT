#ifndef BASE_H
#define BASE_H

#include "esp_err.h"



/**
 * @brief void void function callback
 * 
 */
typedef void (*esp_callback_t)(void);


/**
 * @brief Function callback with params
 * 
 */
typedef void (* callback_data_t)(char* data, char* topic);



/**
 * @brief NULL Check before run
 * 
 */
#define SECURE_CALL(f)         if(f)f()        // Si f != NULL -> f()

#endif