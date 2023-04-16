#include "Reserva_animal.h"

const int LISTAR_ANIMALES = 1;
const int RESCATAR_ANIMAL = 2;
const int BUSCAR_ANIMAL = 3;
const int CUIDAR_ANIMALES = 4;
const int ADOPTAR_ANIMAL = 5;
const int CARGAR_COMBUSTIBLE = 6;
const int GUARDAR_Y_SALIR = 7;
const int COMBUSTIBLE_LLENO = 100;

Reserva_animal::Reserva_animal() {
    combustible_auto = COMBUSTIBLE_LLENO;
    int resultado_lectura = csv_animales_controllers.abrir_archivo(registro_de_animales);
    if (resultado_lectura == ERROR) exit(ERROR);
}


void Reserva_animal::activar_opcion_elegida(int opcion_elegida) {
    switch (opcion_elegida) {
        case LISTAR_ANIMALES:
            registro_de_animales.pasar_tiempo(combustible_auto);
            registro_de_animales.presentar_todos();
            break;

        case RESCATAR_ANIMAL:
            registro_de_animales.pasar_tiempo(combustible_auto);
            rescatar_animales_controllers.rescatar_animal(registro_de_animales, combustible_auto);
            break;

        case BUSCAR_ANIMAL:
            registro_de_animales.pasar_tiempo(combustible_auto);
            buscar_animal_controllers.proceso_de_busqueda(registro_de_animales);
            break;

        case CUIDAR_ANIMALES:
            registro_de_animales.pasar_tiempo(combustible_auto);
            cuidar_animales_controllers.cuidar_animales(registro_de_animales);
            break;

        case ADOPTAR_ANIMAL:
            registro_de_animales.pasar_tiempo(combustible_auto);
            adoptar_animal_controllers.adoptar_animal(registro_de_animales);
            break;

        case CARGAR_COMBUSTIBLE:
            cargar_combustible_controllers.cargar_combustible(combustible_auto);
            break;

        case GUARDAR_Y_SALIR:
            registro_de_animales.pasar_tiempo(combustible_auto);
            registro_de_animales.guardar_datos_en_archivo();
            registro_de_animales.eliminar_todos();
            break;
    }
}
