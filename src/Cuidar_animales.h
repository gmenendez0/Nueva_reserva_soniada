#ifndef NUEVA_RESERVA_SONIADA_CUIDAR_ANIMALES_H
#define NUEVA_RESERVA_SONIADA_CUIDAR_ANIMALES_H

#include "animal.h"
#include "ArbolB.h"

class Cuidar_animales {
public:
    //Pre Debe recibir el arbol de animales
    //Post Pone en marcha las debidas funciones para cumplir el cuidado del animal elegido por el usuario
    void cuidar_animales(ArbolB<Animal*> &registro_de_animales);

private:
    //Pre Debe recibir el arbol de animales
    //Post Pone en marchas las debidas funciones para aplicar cuidados individuales a un animal
    void elegir_animal(ArbolB<Animal*> &registro_de_animales);

    //Pre Debe recibir el arbol de animales, el animal a cuidar y la accion a realizar con el animal
    //Post Realiza la accion elegida con el animal elegido
    void realizar_accion_pedida(Animal* animal_elegido, int accion_a_realizar);

    //Post Pide al usuario una accion a realizar y la devuelve
    int pedir_accion();

    //Pre Debe recibir una accion
    //Post Chequea que la accion sea válida, en caso de no serlo vuelve a pedir una accion al usuario
    void chequear_accion_terciaria(int &accion_a_realizar);

    //Pre Debe recibir el arbol de animales
    //Post Pide al usuario que ingrese un nombre para verificar si ese animal existe en el arbol. Devuelve un puntero al animal buscado por el usuario o a null si el animal no se encontro
    Animal* pedir_nombre(ArbolB<Animal*> &registro_de_animales);

    //Pre -
    //Post Imprime por consola el menu de acciones de cuidado de animal
    int mostrar_menu_secundario();

    //Pre Debe recibir una respuesta
    //Post Chequea si la respuesta es válida, en caso de no serla vuelve a pedir una respuesta al usuario
    void chequear_entrada_secundaria(int &respuesta);

    //Pre Debe recibir una respuesta y dos valores para usar como límites en la comparacion
    //Post Devuelve true en caso de que la respuesta sea válida (que esté entre los límites inclusive), false caso contrario
    bool respuesta_valida(int respuesta, int limite_minimo, int limite_maximo);
};


#endif
