#ifndef NUEVA_RESERVA_SONIADA_USER_MENU_H
#define NUEVA_RESERVA_SONIADA_USER_MENU_H

#include "Rescatar_animal.h"
#include "Buscar_animal.h"
#include "Cuidar_animales.h"
#include "Adoptar_animal.h"
#include "Cargar_combustible.h"

class User_menu {
private:
    Rescatar_animal rescatar_animales_controllers;
    Buscar_animal buscar_animal_controllers;
    Cuidar_animales cuidar_animales_controllers;
    Adoptar_animal adoptar_animal_controllers;
    Cargar_combustible cargar_combustible_controllers;
    int cantidad_acciones_ejecutadas;

public:
    User_menu();

    //Pre Debe recibir la cantidad de acciones ejecutadas por el usuario
    //Post Imprime por consola el menu de acciones para el usuario
    int mostrar_menu();

    //Pre Debe recibir una opcion elegida y el arbol de los animales
    //Post Activa las debidas funciones para ejecutar al accion del usuario
    void activar_opcion_elegida(int opcion_elegida, ArbolB<Animal*> &registro_de_animales, int &combustible_auto);

private:
    //Pre
    //Post Imprime el mensaje de despedida al usuario
    void imprimir_mensaje_despedida();

    //Pre Debe recibir la cantidad de acciones ejecutadas por el usuario
    //Post Imprime por consola el menu de acciones para el usuario
    int imprimir_menu();

    //Pre Debe recibir una respuesta
    //Post Chequea si la respuesta es válida, en caso de no serla vuelve a pedir una respuesta al usuario
    void chequear_entrada(int &respuesta);

    //Pre Debe recibir una respuesta
    //Post Devuelve true en caso de que la respuesta sea válida (valores 1 - 7 inclusive), false caso contrario
    bool respuesta_es_valida(int respuesta);

};


#endif
