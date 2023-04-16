#include "Animal/Animal.h"
#include "User_interface/User_menu.h"
#include "Reserva/Reserva_animal.h"

const int GUARDAR_Y_SALIR = 7;

int main(){
    srand((unsigned)time(nullptr));

    User_menu user_menu;
    Reserva_animal reserva;

    int opcion_elegida = user_menu.mostrar_menu();
    reserva.activar_opcion_elegida(opcion_elegida);

    while(opcion_elegida != GUARDAR_Y_SALIR){
        opcion_elegida = user_menu.mostrar_menu();
        reserva.activar_opcion_elegida(opcion_elegida);
    }

    user_menu.imprimir_mensaje_despedida();

    return 0;
}
