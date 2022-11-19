#ifndef MENU_CONTROLLERS_H
#define MENU_CONTROLLERS_H

#include "animal.h"
#include "ArbolB.h"

//Pre Debe recibir la cantidad de acciones ejecutadas por el usuario
//Post Imprime por consola el menu de acciones para el usuario
int mostrar_menu(int &cantidad_acciones);

//Pre Debe recibir una opcion elegida y la lista con los animales
//Post Activa las debidas funciones para ejecutar al accion del usuario
void activar_opcion_elegida(int opcion_elegida, ArbolB<Animal*> &registro_de_animales, int &combustible_auto);

#endif
