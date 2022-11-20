#ifndef CUIDAR_ANIMALES_CONTROLLERS_H
#define CUIDAR_ANIMALES_CONTROLLERS_H

#include "animal.h"
#include "ArbolB.h"

//Pre Debe recibir el arbol de animales
//Post Pone en marcha las debidas funciones para cumplir el cuidado del animal elegido por el usuario
void cuidar_animales(ArbolB<Animal*> &registro_de_animales);

#endif
