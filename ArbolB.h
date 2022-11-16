#ifndef TP3_ARBOLB_H
#define TP3_ARBOLB_H

#include <iostream>
#include "nodo.h"

template<typename Tipo_de_animal>
class ArbolB{
    private:
        Nodo<Tipo_de_animal>* raiz;

    private:
        void insertar_en_arbol(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split);

        void evaluar_posibilidades_nodo_hoja(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split);

        void evaluar_posibilidades_nodo_con_hijos(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split);

        bool animal_nuevo_es_mas_grande(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        bool animal_nuevo_es_intermedio(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        void split_hoja(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split);

        void split_nodo_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split);

        bool nodo_es_raiz(Nodo<Tipo_de_animal>* nodo);

    public:
        //Pre -
        //Post Crea un arbol vacio.
        ArbolB();

        void insertar(Tipo_de_animal animal);

        Nodo<Tipo_de_animal>* get_raiz();
};

template<typename Tipo_de_animal>
ArbolB <Tipo_de_animal>::ArbolB(){
    raiz = nullptr;
}

template<typename Tipo_de_animal>
void ArbolB<Tipo_de_animal>::insertar(Tipo_de_animal animal){
    bool animal_a_insertar_proviene_de_split = false;
    insertar_en_arbol(animal, this->raiz, animal_a_insertar_proviene_de_split);
}

template<typename Tipo_de_animal>
void ArbolB<Tipo_de_animal>::insertar_en_arbol(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split){
    if(nodo_a_insertar == nullptr){
        raiz = new Nodo <Tipo_de_animal>(animal);
    } else if(nodo_a_insertar->es_hoja()){
        evaluar_posibilidades_nodo_hoja(animal, nodo_a_insertar, animal_a_insertar_proviene_de_split);
    } else{
        evaluar_posibilidades_nodo_con_hijos(animal, nodo_a_insertar, animal_a_insertar_proviene_de_split);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_posibilidades_nodo_hoja(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split){
    if(nodo_a_insertar->get_tope_datos() == UN_DATO){
        if(nodo_a_insertar->get_primera_clave() > animal->get_nombre()){
            //mover el dato que está en la primera posicion del vector a la segunda e insertar el animal nuevo en la primera posicion del vector.
            nodo_a_insertar->set_segundo_dato(nodo_a_insertar->get_primer_dato());
            nodo_a_insertar->set_primer_dato(animal);
            nodo_a_insertar->aumentar_tope_datos();
        } else {
            //insertar el dato en la segunda posicion del vector
            nodo_a_insertar->set_segundo_dato(animal);
            nodo_a_insertar->aumentar_tope_datos();
        }
    } else {
        if(animal_nuevo_es_mas_grande(animal, nodo_a_insertar)){
            split_hoja(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal, animal_a_insertar_proviene_de_split);
            //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
        } else if(animal_nuevo_es_intermedio(animal, nodo_a_insertar)) {
            split_hoja(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), animal, nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split);
            //quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda SPLIT
        } else {
            split_hoja(nodo_a_insertar, animal, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split);
            //Quiere decir que el animal es más chico que las otras dos claves. SPLIT
        }
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_posibilidades_nodo_con_hijos(Tipo_de_animal animal, Nodo <Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split){
    if(animal_a_insertar_proviene_de_split){
        //? SI ENTRA POR ACA ES PORQUE LA INSERCION PROVIENE DE SPLIT
        if(nodo_a_insertar->get_tope_datos() == UN_DATO){
            //? EL NODO TIENE UN SOLO DATO
            if(nodo_a_insertar->get_primera_clave() > animal->get_nombre()){
                //el número ingresante se ubicará en la primera clave y la anterior primera clave, en la segunda.
                nodo_a_insertar->set_segundo_dato(nodo_a_insertar->get_primer_dato());
                nodo_a_insertar->set_primer_dato(animal);
                nodo_a_insertar->aumentar_tope_datos();
            } else {
                //el número ingresante se ubicará en la segunda clave
                nodo_a_insertar->set_segundo_dato(animal);
                nodo_a_insertar->aumentar_tope_datos();
            }
        } else {
            //? EL NODO TIENE DOS DATOS
            if(animal_nuevo_es_mas_grande(animal, nodo_a_insertar)){
                //split_nodo_con_hijos(animal, nodo_a_insertar, animal_a_insertar_proviene_de_split);
                //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
            } else if(animal_nuevo_es_intermedio(animal, nodo_a_insertar)) {
                //split_nodo_con_hijos(animal, nodo_a_insertar, animal_a_insertar_proviene_de_split);
                //quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda SPLIT
            } else {
                //split_nodo_con_hijos(animal, nodo_a_insertar, animal_a_insertar_proviene_de_split);
                //Quiere decir que el animal es más chico que las otras dos claves. SPLIT
            }
        }
    } else {
        //? SI ENTRA POR ACA ES PORQUE LA INSERCION NO PROVIENE DE SPLIT
        if(nodo_a_insertar->get_tope_datos() == UN_DATO){
            //? EL NODO TIENE UN SOLO DATO
            if(nodo_a_insertar->get_primera_clave() > animal->get_nombre()){
                insertar_en_arbol(animal, nodo_a_insertar->get_primer_hijo(), animal_a_insertar_proviene_de_split);
                //se avanza al PRIMER hijo del nodo.
            } else {
                insertar_en_arbol(animal, nodo_a_insertar->get_segundo_hijo(), animal_a_insertar_proviene_de_split);
                //se avanza al SEGUNDO hijo del nodo.
            }
        } else {
            //? EL NODO TIENE DOS DATOS
            if(animal_nuevo_es_mas_grande(animal, nodo_a_insertar)){
                insertar_en_arbol(animal, nodo_a_insertar->get_tercer_hijo(), animal_a_insertar_proviene_de_split);
                //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. Se avanza al tercer hijo del nodo.
            } else if(animal_nuevo_es_intermedio(animal, nodo_a_insertar)) {
                insertar_en_arbol(animal, nodo_a_insertar->get_segundo_hijo(), animal_a_insertar_proviene_de_split);
                //Quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda. Se avanza al segundo hijo del nodo
            } else {
                insertar_en_arbol(animal, nodo_a_insertar->get_primer_hijo(), animal_a_insertar_proviene_de_split);
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

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_hoja(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor, bool &animal_a_insertar_proviene_de_split){

    if(nodo_es_raiz(nodo_a_splitear)){
        //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES EL NODO HOJA
        Nodo<Tipo_de_animal>* nodo_superior = new Nodo<Tipo_de_animal>(dato_intermedio);

        Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_superior);
        Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_superior);
        nodo_superior->set_primer_hijo(nodo_menor);
        nodo_superior->set_segundo_hijo(nodo_mayor);

        this->raiz = nodo_superior;
        delete nodo_a_splitear;
    }else{
        //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES HOJA Y PORQUE EL PADRE DEL NODO A SPLITEAR NO ESTA LLENO
        if(nodo_a_splitear->get_nodo_padre()->get_tope_datos() == UN_DATO){
            Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_a_splitear->get_nodo_padre());
            Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_a_splitear->get_nodo_padre());

            if(nodo_a_splitear->es_primer_hijo()){
                nodo_a_splitear->get_nodo_padre()->set_primer_hijo(nodo_menor);
                nodo_a_splitear->get_nodo_padre()->set_tercer_hijo(nodo_a_splitear->get_nodo_padre()->get_segundo_hijo());
                nodo_a_splitear->get_nodo_padre()->set_segundo_hijo(nodo_mayor);
            } else {
                //el primer hijo no hace falta modificarlo
                nodo_a_splitear->get_nodo_padre()->set_segundo_hijo(nodo_menor);
                nodo_a_splitear->get_nodo_padre()->set_tercer_hijo(nodo_mayor);
            }

            animal_a_insertar_proviene_de_split = true;
            insertar_en_arbol(dato_intermedio, nodo_a_splitear->get_nodo_padre(), animal_a_insertar_proviene_de_split);
        } else {
            //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES HOJA Y PORQUE EL PADRE DEL NODO A SPLITEAR ESTA LLENO. HAY QUE PREPARAR TODO PARA EL SPLIT DEL PADRE.
            //! ACA FALTA ASOCIAR NODO MENOR Y NODO MAYOR COMO HIJOS DE nodo_a_splitear->get_nodo_padre(). Cual es el problema con esto?
            //! EL PROBLEMA ESTA EN QUE SI YO QUIERO METER NODO MENOR Y NODO MAYOR COMO HIJOS DE nodo_a_splitear->get_nodo_padre() Y ESTE YA TIENE DOS HIJOS, ME VA A FALTAR UN PUNTERO PARA
            //! ALMACENAR UN HIJO, TENDRIA 3 PUNTEROS PARA 4 HIJOS

            //! ESTO LO PODEMOS SOLUCIONAR PRIMERO INSERTANDO LA CLAVE INTERMEDIA EN EL NODO PADRE Y DESPUES SPLITEANDO EL NODO A SPLITEAR
            Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_a_splitear->get_nodo_padre());
            Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_a_splitear->get_nodo_padre());

            if(nodo_a_splitear->es_primer_hijo()){

            } else if(nodo_a_splitear->es_segundo_hijo()){

            } else {
                //nodo_a_splitear->get_nodo_padre()->set_primer_hijo();
                //nodo_a_splitear->get_nodo_padre()->set_segundo_hijo();
                //nodo_a_splitear->get_nodo_padre()->set_tercer_hijo();
                //nodo_a_splitear->get_nodo_padre()->set_hijo_auxiliar();
            }

            insertar_en_arbol(dato_intermedio, nodo_a_splitear->get_nodo_padre(), animal_a_insertar_proviene_de_split);

            animal_a_insertar_proviene_de_split = true;
        }
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_nodo_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio,
Tipo_de_animal dato_mayor, bool &animal_a_insertar_proviene_de_split){
    //Cuando yo voy a splitear un nodo con hijos:
    //1)
}

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::nodo_es_raiz(Nodo<Tipo_de_animal>* nodo){
    return (nodo->get_nodo_padre() == nullptr);
}

template<typename Tipo_de_animal>
Nodo <Tipo_de_animal>* ArbolB <Tipo_de_animal>::get_raiz(){
    return raiz;
}


#endif //TP3_ARBOLB_H
