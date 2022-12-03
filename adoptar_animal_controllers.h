#ifndef ADOPTAR_ANIMAL_CONTROLLERS_H
#define ADOPTAR_ANIMAL_CONTROLLERS_H

#include "animal.h"
#include "ArbolB.h"

//Pre Debe recibir el registro de animales
//Post Pone en marcha todas las funciones para que el usuario pueda adoptar un animal. En caso de adoptarlo, se lo marca como eliminado
void adoptar_animal(ArbolB<Animal*> &registro_de_animales);

#endif
