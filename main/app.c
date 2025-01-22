#include "app.h"
#include "mqtt.h"


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



#define MQTT_URL                        "mqtt://broker.hivemq.com"
#define MQTT_TOPIC_SUB                  "DEV-IOT-CMD"
#define MQTT_TOPIC_PUB                  "DEV-IOT-MSG"






int enable = 0;


void mqtt_connected(){
    printf("MQTT connected\n");
    mqtt_publish("Dev-iot connected",MQTT_TOPIC_PUB,2,0);
    mqtt_subcribe(MQTT_TOPIC_SUB,2);
    enable = 1;
    }

void mqtt_data_cb(char* data, char* topic){ 
    printf("\n[MQTT]%s > %s\n",topic,data);
    }
    
void mqtt_disconnected_cb(){  
    printf("\n[MQTT] Se desconecto del servidor\n");
    enable = 0;
    }





void app(){



    printf("Hello app \n");

    printf("\nWiFi connected, Connecting MQTT\n");

    mqtt_init(          MQTT_URL, 
                        mqtt_connected,
                        mqtt_disconnected_cb,
                        mqtt_data_cb);

    int counter = 0;
    char buffer[100]={"counter : %d\n"};
    
    while(1){
        sprintf(buffer,"counter:%d\n",counter++);
        if(enable) mqtt_publish(buffer,MQTT_TOPIC_PUB,2,0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}