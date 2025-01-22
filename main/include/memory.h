#ifndef MEMORY_H
#define MEMORY_H

#include "base.h"
#include "nvs_flash.h"



/**
 * @brief Init memory flash with nvs library.
 * 
 * @return esp_err_t  
 */
esp_err_t memory_init();




/**
 * @brief Deinit memory flash with nvs library.
 * 
 */
void memory_deinit();


/**
 * @brief Save id and password credentials in flash.
 * 
 * @param id  WiFi ID
 * @param pass WiFi PASSWORD
 * @return esp_err_t 
 */
esp_err_t set_credential(const char* id, const char* pass);



/**
 * @brief Get the credentials from memory flash
 * 
 * @param id buffer for saving credential id
 * @param pass buffer for saving credential id
 * @return esp_err_t 
 */
esp_err_t get_credentials(char* id,char* pass);


#endif