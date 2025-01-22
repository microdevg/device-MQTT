#ifndef MEMORY_H
#define MEMORY_H

#include "base.h"
#include "nvs_flash.h"




esp_err_t memory_init();

void memory_deinit();

esp_err_t set_credential(const char* id, const char* pass);


esp_err_t get_credentials(char* id,char* pass);


#endif