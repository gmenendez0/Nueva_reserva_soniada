#ifndef TP3_ARBOLB_H
#define TP3_ARBOLB_H

#include <iostream>
#include "nodo.h"

template<typename Tipo_de_animal>
class ArbolB{
    private:
        Nodo<Tipo_de_animal>* raiz;

    private:
        void insertar_en_arbol(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        void evaluar_posibilidades_nodo_hoja(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        void evaluar_posibilidades_nodo_con_hijos(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        bool animal_nuevo_es_mas_grande(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        bool animal_nuevo_es_intermedio(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

    public:
        //Pre -
        //Post Crea un arbol vacio.
        ArbolB();

        void insertar(Tipo_de_animal animal);
};

template<typename Tipo_de_animal>
ArbolB <Tipo_de_animal>::ArbolB(){
    raiz = nullptr;
}

template<typename Tipo_de_animal>
void ArbolB<Tipo_de_animal>::insertar(Tipo_de_animal animal){
    insertar_en_arbol(animal, raiz);
}

template<typename Tipo_de_animal>
void ArbolB<Tipo_de_animal>::insertar_en_arbol(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar){
    if(nodo_a_insertar == nullptr){
        nodo_a_insertar = new Nodo<Tipo_de_animal>(animal);
    } else if(nodo_a_insertar->es_hoja()){
        evaluar_posibilidades_nodo_hoja(animal, nodo_a_insertar);
    } else{
        evaluar_posibilidades_nodo_con_hijos(animal, nodo_a_insertar);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_posibilidades_nodo_hoja(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar){
    if(nodo_a_insertar->get_tope_datos() == UN_DATO){
        if(nodo_a_insertar->get_primera_clave() > animal->get_nombre()){
            //mover el dato que está en la primera posicion del vector a la segunda e insertar el animal nuevo en la primera posicion del vector.
        } else {
            //insertar el dato en la segunda posicion del vector
        }
    } else {
        if(animal_nuevo_es_mas_grande(animal, nodo_a_insertar)){
            //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
        } else if(animal_nuevo_es_intermedio(animal, nodo_a_insertar)) {
            //quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda SPLIT
        } else {
            //Quiere decir que el animal es más chico que las otras dos claves. SPLIT
        }
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_posibilidades_nodo_con_hijos(Tipo_de_animal animal, Nodo <Tipo_de_animal>* nodo_a_insertar){
    if(animal_a_insertar_proviene_de_split){
        //? SI ENTRA POR ACA ES PORQUE LA INSERCION PROVIENE DE SPLIT
        if(nodo_a_insertar->get_tope_datos() == UN_DATO){
            //? EL NODO TIENE UN SOLO DATO
            if(nodo_a_insertar->get_primera_clave() > animal->get_nombre()){
                //el número ingresante se ubicará en la primera clave y la anterior primera clave, en la segunda.
            } else {
                //el número ingresante se ubicará en la segunda clave
            }
        } else {
            //? EL NODO TIENE DOS DATOS
            if(animal_nuevo_es_mas_grande(animal, nodo_a_insertar)){
                //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
            } else if(animal_nuevo_es_intermedio(animal, nodo_a_insertar)) {
                //quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda SPLIT
            } else {
                //Quiere decir que el animal es más chico que las otras dos claves. SPLIT
            }
        }
    } else {
        //? SI ENTRA POR ACA ES PORQUE LA INSERCION NO PROVIENE DE SPLIT
        if(nodo_a_insertar->get_tope_datos() == UN_DATO){
            //? EL NODO TIENE UN SOLO DATO
            if(nodo_a_insertar->get_primera_clave() > animal->get_nombre()){
                //se avanza al PRIMER hijo del nodo.
            } else {
                //se avanza al SEGUNDO hijo del nodo.
            }
        } else {
            //? EL NODO TIENE DOS DATOS
            if(animal_nuevo_es_mas_grande(animal, nodo_a_insertar)){
                //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. Se avanza al tercer hijo del nodo.
            } else if(animal_nuevo_es_intermedio(animal, nodo_a_insertar)) {
                //Quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda. Se avanza al segundo hijo del nodo
            } else {
                //Quiere decir que el animal es más chico que las otras dos claves. Se avanza al primer hijo del nodo
            }
        }
    }
}

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::animal_nuevo_es_mas_grande(Tipo_de_animal animal, Nodo <Tipo_de_animal>* nodo_a_insertar){
    return (nodo_a_insertar->get_primera_clave() < animal->get_nombre() && nodo_a_insertar->get_segunda_clave() < animal->get_nombre());
}

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::animal_nuevo_es_intermedio(Tipo_de_animal animal, Nodo <Tipo_de_animal>* nodo_a_insertar){
    return (nodo_a_insertar->get_primera_clave() < animal->get_nombre() && nodo_a_insertar->get_segunda_clave() > animal->get_nombre());
}

#endif //TP3_ARBOLB_H
