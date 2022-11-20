#ifndef TP2_GATO_H
#define TP2_GATO_H

#include "animal.h"

class Gato: public Animal{
    private:
        std::string tipo_de_comida;

    public:
        //Pre: Debe recibir el nombre, la edad, el tamanio, la especie y la personalidad del animal para poder enviarlos al constructor de la clase padre.
        //Post: Llama al constructor de la clase padre y luego crea un perro seteando sus atributos.
        Gato(std::string nombre, int edad, std::string tamanio, char especie, std::string personalidad);

    private:
        //Pre: -
        //Post: Restaura el hambre del animal al valor inicial e imprime por pantalla su nombre y lo que comio
        void comer();

        //Pre: -
        //Post: Pone en marcha los metodos ensuciarse y aumentar_hambre.
        void pasar_el_tiempo(int* animales_escapados);

        //Pre: -
        //Post: Devuelve true si hambre_actual = 100, false en caso contrario.
        bool esta_hambriento();

        //Pre: -
        //Post: Aumenta el hambre del animal el valor correspondiente segun la personalidad del mismo y si ya está hambriento o no.
        void aumentar_hambre();
};


#endif
