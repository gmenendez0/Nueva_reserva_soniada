#ifndef NUEVA_RESERVA_SONIADA_CSV_HANDLER_H
#define NUEVA_RESERVA_SONIADA_CSV_HANDLER_H


#include "Animal/Animal.h"
#include "Arbol_B/Arbol_B.h"

class CSV_Handler {
public:
    //Pre Debe recibir un arbol de animales vacio y debe haber CREADO un archivo "animales.csv" en el directorio del programa para poder ser leido
    //Post Devuelve 0 si pudo abrir el archivo y -1 si no pudo
    int abrir_archivo(Arbol_B<Animal*> &registro_de_animales);

    //Pre: Debe recibir todas las caracteristicas de un animal.
    //Post: Revisa a que especie pertenece el nuevo animal y llama a la funcion correspondiente para crearlo
    void revisar_especie(string nombre, int edad, string tamanio, char especie, string personalidad, Arbol_B<Animal*> &registro_de_animales);

private:
    //Pre: Debe recibir un archivo csv con los datos de los animales y una arbol vacio de animales
    //Post: Devuelve el arbol inicializado con los datos leidos del archivo
    void inicializar_registro(std::ifstream &archivo_animales, Arbol_B<Animal*> &registro_de_animales);

    //Pre: Debe recibir todas las caracteristicas de un animal y la lista de animales
    //Post: Da de alta un animal en el arbol con los datos recibidos.
    template <typename Tipo_de_animal>
    void crear_animal(string nombre, int edad, string tamanio, char especie, string personalidad, Arbol_B<Animal*> &registro_de_animales);


};


#endif
