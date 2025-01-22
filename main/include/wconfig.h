#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H


#include "base.h"


#define WIFI_ID_KEY             "whost_id"
#define WIFI_PASS_KEY           "whost_pass"







/**
 * @brief  Open web server portal
 * 
 * @return int*   web this var is 1, you have the credential in memory.
 */
int *  portal_wifi_ap();



#endif