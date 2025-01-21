#include <stdio.h>
#include "wconfig.h"
#include "app.h"



void error(void){
    printf("Error fatal\n");
}





void app_main(void)
{
   
   start_app( app, error);



    

    // Leo llamo a esp_host
    // esp_host verifica que las credenciales esten en memoria

}