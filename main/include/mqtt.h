#ifndef MQTT_H


#define MQTT_H

#include "base.h"





/**
 * @brief 
 * 
 * @param uri 
 * @param conn 
 * @param disconn 
 * @param data_received 
 * @return esp_err_t 
 */
esp_err_t mqtt_init(const char* uri, esp_callback_t conn, esp_callback_t disconn,callback_data_t data_received);

/**
 * @brief 
 * 
 * @param msg 
 * @param topic 
 * @param qos 
 * @param retain 
 * @return esp_err_t 
 */
esp_err_t mqtt_publish(const char* msg, const char* topic,int qos, int retain);


/**
 * @brief Publish message with queue.
 * 
 * @param msg buffer cstring
 * @param topic  topic
 * @param qos   Level of service: 0, 1 and 2 are valid.
 * @param retain    retain : 0   not retain: 0
 * @return esp_err_t 
 */
esp_err_t mqtt_publish_on_queue(const char* msg, const char* topic,int qos, int retain);

/**
 * @brief  Subscribe to a topic
 * 
 * @param topic  topic (cstring)
 * @param qos    Level of service: 0 ,1 and 2 are valid.
 * @return esp_err_t 
 */
esp_err_t mqtt_subcribe( char* topic, int qos);
#endif