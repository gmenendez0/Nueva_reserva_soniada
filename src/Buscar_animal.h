#ifndef NUEVA_RESERVA_SONIADA_BUSCAR_ANIMAL_H
#define NUEVA_RESERVA_SONIADA_BUSCAR_ANIMAL_H


#include "animal.h"
#include "ArbolB.h"

class Buscar_animal {
public:
    //Pre: Debe recibir el arbol.
    //Post: Pide al usuario que ingrese un nombre y comprueba que el animal exista en la lista, si no lo vuelve a pedir hasta que el usuario cancela la operacion.
    Animal* ingresar_nombre(ArbolB<Animal*> &registro_de_animales);


    //Pre: Debe recibir el arbol.
    //Post: Pone en marcha las debidas funciones para buscar al animal que el usuario ingresa.
    void proceso_de_busqueda(ArbolB<Animal*> &registro_de_animales);

private:
    //pre:
    //post: Exige al usuario que ingrese un nombre de un animal existente
    void comprobar_animal_buscado(string &nombre, ArbolB<Animal*> &registro_de_animales, Animal* &animal_buscado);
};

#endif
