#include <string.h>


#include "nvs_flash.h"


#include "start_app.h"
#include "wifi.h"




#define NVS_NAMESPACE    "CREDENTIALS"
#define SSID_KEY         "WIFI_ID"
#define PASS_KEY         "WIFI_PASS"
#define WID_LEN             30
#define WPASS_LEN           30


static nvs_handle_t my_handle;




esp_err_t get_credentials(char* id,char* pass){

    esp_err_t err = ESP_OK;

    // Inicio memoria

    ESP_ERROR_CHECK(nvs_flash_init());
     if (err != ESP_OK)
    {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        return err;
    }
    // Obtengo las credenciales

    err = nvs_open(NVS_NAMESPACE, NVS_READWRITE, &my_handle);

    if (err != ESP_OK)
    {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        return err;
    }

    // Leer SSID
    size_t value_len =0;
    // Primero con parametro id en NULL, se lee el size del string
    err = nvs_get_str(my_handle, SSID_KEY, NULL, &value_len);
    // Luego se lee el string
    err = nvs_get_str(my_handle, SSID_KEY,id, &value_len);


    if (err != ESP_OK)
    {
        printf("Failed to read SSID!\n");
        return err;
    }

    // Leer Contraseña
    
    err = nvs_get_str(my_handle, PASS_KEY, NULL, &value_len);
    err = nvs_get_str(my_handle, PASS_KEY, pass, &value_len);
    if (err != ESP_OK)
    {
        printf("Failed to read Password!\n");
        return err;
    }

   
    printf("NVS leída correctamente SSID:%s  password:%s", id, pass);
      


    nvs_close(my_handle);
    return err;

}


void    start_app(esp_callback_t app, esp_callback_t error){

    esp_err_t err = ESP_OK;

    char id[WID_LEN] ={0};
    char pass[WPASS_LEN] = {0};

    err = get_credentials(id,pass);




    if(err == ESP_OK  && (strlen(id) )){
        // Try WiFi connect 
        wifi_connect(id,pass,app,NULL,NULL);
    }
    else{
        // Call gui
        printf("Call gui, You need introduce credentials\n");
    }




}
