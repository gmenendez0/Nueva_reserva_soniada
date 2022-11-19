#ifndef __BUSCAR_ANIMAL_H__
#define __BUSCAR_ANIMAL_H__

//#include "lista.h"
//#include "animal.h"
#include "animal.h"
#include "ArbolB.h"

//Pre: Debe recibir el arbol.
//Post: Pide al usuario que ingrese un nombre y comprueba que el animal exista en la lista, si no lo vuelve a pedir hasta que el usuario cancela la operacion.
Animal* ingresar_nombre(ArbolB<Animal*> &registro_de_animales);


//Pre: Debe recibir el arbol.
//Post: Pone en marcha las debidas funciones para buscar al animal que el usuario ingresa.
void proceso_de_busqueda(ArbolB<Animal*> &registro_de_animales);

#endif //__BUSCAR_ANIMAL_H__
