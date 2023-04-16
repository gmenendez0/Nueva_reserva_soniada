#ifndef NUEVA_RESERVA_SONIADA_ADOPTAR_ANIMAL_H
#define NUEVA_RESERVA_SONIADA_ADOPTAR_ANIMAL_H


#include "animal.h"
#include "ArbolB.h"

class Adoptar_animal {
public:
    //Pre Debe recibir el registro de animales
    //Post Pone en marcha todas las funciones para que el usuario pueda adoptar un animal. En caso de adoptarlo, se lo marca como eliminado
    void adoptar_animal(ArbolB<Animal*> &registro_de_animales);

private:
    //Pre
    //Post Pide al usuario que ingrese el nombre del animal que desea adoptar y luego pone en marcha la funcion para realizar la baja (en caso de no querer cancelar adopcion)
    void pedir_animal(ArbolB<Animal*> &registro_de_animales, int espacio_disponible);

    //Post pregunta al usuario por el espacio disponible para el nuevo anima y devuelve la respuesta
    int consultar_espacio_disponible();

    //Pre Debe recibir una respuesta
    //Post Chequea que la respuesta sea válida y vuelve a pedirla en caso de que no lo sea
    void chequear_espacio_disponible(int &respuesta);

    //Pre Debe recibir una respuesta
    //Devuelve true en caso de que la respuesta tenga un valor válido o false en caso contrario
    bool respuesta_invalida(int respuesta);
};


#endif
