#include "memory.h"





#define NVS_NAMESPACE    "CREDENTIALS"
#define SSID_KEY         "WIFI_ID"
#define PASS_KEY         "WIFI_PASS"
#define WID_LEN             30
#define WPASS_LEN           30

static nvs_handle_t my_handle;




esp_err_t memory_init(){
    esp_err_t err = ESP_OK;
    ESP_ERROR_CHECK(nvs_flash_init());
    // Initialize NVS
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition was truncated and needs to be erased
        // Retry nvs_flash_init
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    
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
    }
    return err;

}


void memory_deinit(){
        nvs_close(my_handle);
}



esp_err_t get_credentials(char* id,char* pass){

    esp_err_t err = ESP_OK;
    err = memory_init();

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


esp_err_t set_credential(const char* id, const char* pass){


    esp_err_t err = ESP_OK;
    err = memory_init();


      // Guardar SSID
    err = nvs_set_str(my_handle, SSID_KEY, id);
    if (err != ESP_OK)
    {
        printf("Failed to save SSID!\n");
    }
    else
    {
        printf("guardado correctamente");
    }

    // Guardar Contraseña
    err = nvs_set_str(my_handle, PASS_KEY, pass);
    if (err != ESP_OK)
    {
        printf("Failed to save Password!\n");
    }

    // Confirmar cambios
    err = nvs_commit(my_handle);
    if (err != ESP_OK)
    {
        printf("Failed to commit NVS updates!\n");
    }
    else
    {
        printf("guardado correctamente2");
    }
    memory_deinit();

    return err;

}