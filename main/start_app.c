#include <string.h>


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



#include "start_app.h"
#include "wifi.h"
#include "memory.h"
#include "wconfig.h"




void clean_credential(){
    printf("Clean credentials");
    set_credential("","");
    esp_restart();

}


void reconnect(){
    printf("Try to reconnect WiFi\n");
}



void    start_app(esp_callback_t app, esp_callback_t error){

    esp_err_t err = ESP_OK;
    char id[30] ={0};
    char pass[30] = {0};
    err = get_credentials(id,pass);



    if(err == ESP_OK  && (strlen(id) )){
        // Try WiFi connect 
        wifi_connect(id,pass,app,reconnect,clean_credential);
    }
    else{
        // Call gui
        int* waiting =  portal_wifi_ap();
        printf("Call gui, You need introduce credentials\n");
         while(*waiting){
            vTaskDelay(500/portTICK_PERIOD_MS);
            printf(".\n");
        }
        printf("Tengo las credenciales, reinciio el sistema\n");
        esp_restart();
    }

}
