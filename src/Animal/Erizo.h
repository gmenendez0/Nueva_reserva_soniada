#ifndef TP2_ERIZO_H
#define TP2_ERIZO_H

#include <string>
#include "Animal/Animal.h"

class Erizo: public Animal{
    public:
        //Pre: Debe recibir el nombre, la edad, el tamanio, la especie y la personalidad del animal para poder enviarlos al constructor de la clase padre.
        //Post: Llama al constructor de la clase padre y luego crea un perro seteando sus atributos.
        Erizo(std::string nombre, int edad, std::string tamanio, char especie, std::string personalidad);

    private:
        //Pre: -
        //Post: Si es necesario, baña al animal y en caso de no serlo, lo aclara con un mensaje por terminal.
        void ducharse();

        //Pre: -
        //Post: Restaura el hambre del animal al valor inicial e imprime por pantalla su nombre y lo que comio
        void comer();

        //Pre: -
        //Post: Pone en marcha los metodos ensuciarse y aumentar_hambre.
        void pasar_el_tiempo(int* animales_escapados);

        //Pre: -
        //Post: Devuelve true si higene_actual = 0, false en caso contrario.
        bool esta_sucio();

        //Pre: -
        //Post: Devuelve true si hambre_actual = 100, false en caso contrario.
        bool esta_hambriento();

        //Pre: -
        //Post: Decrece la higene del animal el valor correspondiente segun la personalidad del mismo y si ya está sucio o no.
        void ensuciarse();

        //Pre: -
        //Post: Aumenta el hambre del animal el valor correspondiente segun la personalidad del mismo y si ya está hambriento o no.
        void aumentar_hambre();
};


#endif
