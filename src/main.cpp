#include "ArbolB.h"
#include "archivo_controllers.h"
#include "animal.h"
#include "menu_controllers.h"

const int UNA_ACCION = 1;
const int GUARDAR_Y_SALIR = 7;
const int COMBUSTIBLE_LLENO = 100;

int main(){
    srand((unsigned)time(nullptr));
    ArbolB<Animal*> registro_de_animales;
    int combustible_auto = COMBUSTIBLE_LLENO;

    int resultado_lectura = abrir_archivo(registro_de_animales);
    if (resultado_lectura) return ERROR;

    int cantidad_acciones = UNA_ACCION;

    int opcion_elegida = mostrar_menu(cantidad_acciones);
    activar_opcion_elegida(opcion_elegida, registro_de_animales, combustible_auto);

    while(opcion_elegida != GUARDAR_Y_SALIR){
        opcion_elegida = mostrar_menu(cantidad_acciones);
        activar_opcion_elegida(opcion_elegida, registro_de_animales, combustible_auto);
    }

    registro_de_animales.eliminar_todos();
    return 0;
}
