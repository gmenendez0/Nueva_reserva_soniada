#ifndef NUEVA_RESERVA_SONIADA_RESERVA_ANIMAL_H
#define NUEVA_RESERVA_SONIADA_RESERVA_ANIMAL_H

#include "Reserva/Rescatar_animal.h"
#include "Reserva/Buscar_animal.h"
#include "Reserva/Cuidar_animales.h"
#include "Reserva/Adoptar_animal.h"
#include "Reserva/Cargar_combustible.h"
#include "Reserva/CSV_Handler.h"

class Reserva_animal {

private:
    Rescatar_animal rescatar_animales_controllers;
    Buscar_animal buscar_animal_controllers;
    Cuidar_animales cuidar_animales_controllers;
    Adoptar_animal adoptar_animal_controllers;
    Cargar_combustible cargar_combustible_controllers;
    CSV_Handler csv_animales_controllers;

    Arbol_B<Animal*> registro_de_animales;
    int combustible_auto;

public:
    Reserva_animal();

    //Pre Debe recibir una opcion elegida y el arbol de los animales
    //Post Activa las debidas funciones para ejecutar al accion del usuario
    void activar_opcion_elegida(int opcion_elegida);
};


#endif
