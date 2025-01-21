#ifndef BASE_H
#define BASE_H

#include "esp_err.h"



typedef void (*esp_callback_t)(void);

#define SECURE_CALL(f)         if(f)f()        // Si f != NULL -> f()

#endif