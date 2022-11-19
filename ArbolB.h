#ifndef TP3_ARBOLB_H
#define TP3_ARBOLB_H

const int ANIMAL_REPETIDO = 1;
const int COMPLETADA = 0;

#include <iostream>
#include "nodo.h"

template<typename Tipo_de_animal>
class ArbolB{
    private:
        Nodo<Tipo_de_animal>* raiz;

    private:
        int* insertar_en_arbol(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        void evaluar_posibilidades_nodo_hoja(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        void evaluar_posibilidades_nodo_con_hijos(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        bool animal_nuevo_es_mas_grande(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        bool animal_nuevo_es_intermedio(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        void split_hoja(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        void split_nodo_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        bool nodo_es_raiz(Nodo<Tipo_de_animal>* nodo);

        void realizar_insercion(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal);

        void evaluar_insercion_proveniente_de_split(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        void evaluar_insercion_no_proveniente_de_split(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        void realizar_insercion_proveniente_de_split_dos_datos(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        void evaluar_insercion_no_proveniente_de_split_un_dato(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
        int* resultado_insercion);

        void evaluar_insercion_no_proveniente_de_split_dos_datos(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
        int* resultado_insercion);

        void realizar_split_nodo_hoja_raiz(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor);

        void realizar_split_nodo_hoja_un_dato(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        void realizar_split_nodo_hoja_dos_datos(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        void ordenar_parentezco_padre_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nodo_menor, Nodo <Tipo_de_animal>* nodo_mayor);

        void ordenar_parentezco_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nuevo_nodo_menor, Nodo <Tipo_de_animal>* nuevo_nodo_mayor);

        void split_nodo_raiz_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor);

        void split_nodo_con_hijos_padre_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor, bool
        &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        void split_nodo_con_hijos_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor, bool
        &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        void evaluar_repeticion_nombre(Tipo_de_animal animal_coincidente, Tipo_de_animal animal, int* resultado_insercion);

    public:
        //Pre -
        //Post Crea un arbol vacio.
        ArbolB();

        int insertar(Tipo_de_animal animal);

        Nodo<Tipo_de_animal>* get_raiz();
};

template<typename Tipo_de_animal>
ArbolB <Tipo_de_animal>::ArbolB(){
    raiz = nullptr;
}

template<typename Tipo_de_animal>
int ArbolB<Tipo_de_animal>::insertar(Tipo_de_animal animal){
    bool animal_a_insertar_proviene_de_split = false;
    int* puntero_resultado_insercion = new int;
    (*puntero_resultado_insercion) = COMPLETADA;
    int resultado_insercion = (*insertar_en_arbol(animal, this->raiz, animal_a_insertar_proviene_de_split, puntero_resultado_insercion));
    delete puntero_resultado_insercion;

    return resultado_insercion;
}

template<typename Tipo_de_animal>
int* ArbolB<Tipo_de_animal>::insertar_en_arbol(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
     if(nodo_a_insertar == nullptr){
        raiz = new Nodo <Tipo_de_animal>(animal);
    } else if(nodo_a_insertar->hay_animal_con_mismo_nombre(animal) != nullptr){
         evaluar_repeticion_nombre(nodo_a_insertar->hay_animal_con_mismo_nombre(animal), animal, resultado_insercion);
    } else if(nodo_a_insertar->es_hoja()){
        evaluar_posibilidades_nodo_hoja(animal, nodo_a_insertar, animal_a_insertar_proviene_de_split, resultado_insercion);
    } else{
        evaluar_posibilidades_nodo_con_hijos(animal, nodo_a_insertar, animal_a_insertar_proviene_de_split, resultado_insercion);
    }

    return resultado_insercion;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_repeticion_nombre(Tipo_de_animal animal_coincidente, Tipo_de_animal animal, int* resultado_insercion){
    if(animal_coincidente->esta_eliminado()){
        delete animal_coincidente;
        animal_coincidente = animal; //? AVERIGUAR PORQUE ESTO NO FUNCIONA CORRECTAMENTE
    } else {
        (*resultado_insercion) = ANIMAL_REPETIDO;
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_posibilidades_nodo_hoja(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int*
resultado_insercion){
    if(nodo_a_insertar->get_tope_datos() == UN_DATO){
        realizar_insercion(nodo_a_insertar, animal);
    } else {
        if(animal_nuevo_es_mas_grande(animal, nodo_a_insertar)){
            split_hoja(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal, animal_a_insertar_proviene_de_split, resultado_insercion);
            //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
        } else if(animal_nuevo_es_intermedio(animal, nodo_a_insertar)) {
            split_hoja(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), animal, nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split, resultado_insercion);
            //quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda SPLIT
        } else {
            split_hoja(nodo_a_insertar, animal, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split, resultado_insercion);
            //Quiere decir que el animal es más chico que las otras dos claves. SPLIT
        }
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_posibilidades_nodo_con_hijos(Tipo_de_animal animal, Nodo <Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int*
resultado_insercion){
    if(animal_a_insertar_proviene_de_split){
        evaluar_insercion_proveniente_de_split(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    } else {
        evaluar_insercion_no_proveniente_de_split(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_insercion(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal){
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
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_insercion_proveniente_de_split(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE LA INSERCION PROVIENE DE SPLIT
    if(nodo_a_insertar->get_tope_datos() == UN_DATO){
        //? EL NODO TIENE UN SOLO DATO
        realizar_insercion(nodo_a_insertar, animal);
    } else {
        realizar_insercion_proveniente_de_split_dos_datos(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_insercion_proveniente_de_split_dos_datos(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
int* resultado_insercion){
    //? EL NODO TIENE DOS DATOS
    if(animal_nuevo_es_mas_grande(animal, nodo_a_insertar)){
        split_nodo_con_hijos(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal, animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
    } else if(animal_nuevo_es_intermedio(animal, nodo_a_insertar)) {
        split_nodo_con_hijos(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), animal, nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda SPLIT
    } else {
        split_nodo_con_hijos(nodo_a_insertar, animal, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal es más chico que las otras dos claves. SPLIT
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_insercion_no_proveniente_de_split_un_dato(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
 int* resultado_insercion){
    //? EL NODO TIENE UN SOLO DATO
    if(nodo_a_insertar->get_primera_clave() > animal->get_nombre()){
        insertar_en_arbol(animal, nodo_a_insertar->get_primer_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //se avanza al PRIMER hijo del nodo.
    } else {
        insertar_en_arbol(animal, nodo_a_insertar->get_segundo_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //se avanza al SEGUNDO hijo del nodo.
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_insercion_no_proveniente_de_split_dos_datos(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
 int* resultado_insercion){
    //? EL NODO TIENE DOS DATOS
    if(animal_nuevo_es_mas_grande(animal, nodo_a_insertar)){
        insertar_en_arbol(animal, nodo_a_insertar->get_tercer_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. Se avanza al tercer hijo del nodo.
    } else if(animal_nuevo_es_intermedio(animal, nodo_a_insertar)) {
        insertar_en_arbol(animal, nodo_a_insertar->get_segundo_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda. Se avanza al segundo hijo del nodo
    } else {
        insertar_en_arbol(animal, nodo_a_insertar->get_primer_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal es más chico que las otras dos claves. Se avanza al primer hijo del nodo
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_insercion_no_proveniente_de_split(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
int* resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE LA INSERCION NO PROVIENE DE SPLIT
    if(nodo_a_insertar->get_tope_datos() == UN_DATO){
        evaluar_insercion_no_proveniente_de_split_un_dato(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    } else{
        evaluar_insercion_no_proveniente_de_split_dos_datos(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_hoja(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    if(nodo_es_raiz(nodo_a_splitear)){
        realizar_split_nodo_hoja_raiz(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor);
    } else if(nodo_a_splitear->get_nodo_padre()->get_tope_datos() == UN_DATO){
        realizar_split_nodo_hoja_un_dato(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor, animal_a_insertar_proviene_de_split, resultado_insercion);
    } else{
        realizar_split_nodo_hoja_dos_datos(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_split_nodo_hoja_raiz(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES EL NODO RAIZ
    Nodo<Tipo_de_animal>* nodo_superior = new Nodo<Tipo_de_animal>(dato_intermedio);

    Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_superior);
    Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_superior);
    nodo_superior->set_primer_hijo(nodo_menor);
    nodo_superior->set_segundo_hijo(nodo_mayor);

    this->raiz = nodo_superior;
    delete nodo_a_splitear;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_split_nodo_hoja_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES HOJA Y PORQUE EL PADRE DEL NODO A SPLITEAR NO ESTA LLENO
    Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_a_splitear->get_nodo_padre());
    Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_a_splitear->get_nodo_padre());

    ordenar_parentezco_padre_un_dato(nodo_a_splitear, nodo_menor, nodo_mayor);

    animal_a_insertar_proviene_de_split = true;
    insertar_en_arbol(dato_intermedio, nodo_a_splitear->get_nodo_padre(), animal_a_insertar_proviene_de_split, resultado_insercion);
    delete nodo_a_splitear;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_split_nodo_hoja_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor,
  bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES HOJA Y PORQUE EL PADRE DEL NODO A SPLITEAR ESTA LLENO. HAY QUE PREPARAR TODO PARA EL SPLIT DEL PADRE.
    Nodo<Tipo_de_animal>* nuevo_nodo_menor = new Nodo<Tipo_de_animal>(dato_menor);
    Nodo<Tipo_de_animal>* nuevo_nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor);

    ordenar_parentezco_padre_dos_datos(nodo_a_splitear, nuevo_nodo_menor, nuevo_nodo_mayor);

    animal_a_insertar_proviene_de_split = true;
    insertar_en_arbol(dato_intermedio, nodo_a_splitear->get_nodo_padre(), animal_a_insertar_proviene_de_split, resultado_insercion);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_nodo_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio,
Tipo_de_animal dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){

    if(nodo_es_raiz(nodo_a_splitear)){
        split_nodo_raiz_con_hijos(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor);
    } else if(nodo_a_splitear->get_nodo_padre()->get_tope_datos() == UN_DATO){
        split_nodo_con_hijos_padre_un_dato(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor, animal_a_insertar_proviene_de_split, resultado_insercion);
    } else {
        split_nodo_con_hijos_padre_dos_datos(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_nodo_raiz_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES UN NODO RAIZ CON HIJOS
    Nodo<Tipo_de_animal>* nodo_superior = new Nodo<Tipo_de_animal>(dato_intermedio);
    Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_superior);
    Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_superior);

    //! CODIGO REPETIDO (1)
    nodo_menor->set_primer_hijo(nodo_a_splitear->get_primer_hijo());
    nodo_menor->set_segundo_hijo(nodo_a_splitear->get_segundo_hijo());

    nodo_mayor->set_primer_hijo(nodo_a_splitear->get_tercer_hijo());
    nodo_mayor->set_segundo_hijo(nodo_a_splitear->get_hijo_auxiliar());

    nodo_menor->get_primer_hijo()->set_nodo_padre(nodo_menor);
    nodo_menor->get_segundo_hijo()->set_nodo_padre(nodo_menor);

    nodo_mayor->get_primer_hijo()->set_nodo_padre(nodo_mayor);
    nodo_mayor->get_segundo_hijo()->set_nodo_padre(nodo_mayor);

    nodo_superior->set_primer_hijo(nodo_menor);
    nodo_superior->set_segundo_hijo(nodo_mayor);

    this->raiz = nodo_superior;
    delete nodo_a_splitear;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_nodo_con_hijos_padre_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR TIENE DOS DATOS Y EL NODO PADRE TIENE UNO SOLO.
    Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_a_splitear->get_nodo_padre());
    Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_a_splitear->get_nodo_padre());

    //! CODIGO REPETIDO (1)
    nodo_menor->set_primer_hijo(nodo_a_splitear->get_primer_hijo());
    nodo_menor->set_segundo_hijo(nodo_a_splitear->get_segundo_hijo());

    nodo_mayor->set_primer_hijo(nodo_a_splitear->get_tercer_hijo());
    nodo_mayor->set_segundo_hijo(nodo_a_splitear->get_hijo_auxiliar());

    nodo_menor->get_primer_hijo()->set_nodo_padre(nodo_menor);
    nodo_menor->get_segundo_hijo()->set_nodo_padre(nodo_menor);

    nodo_mayor->get_primer_hijo()->set_nodo_padre(nodo_mayor);
    nodo_mayor->get_segundo_hijo()->set_nodo_padre(nodo_mayor);

    ordenar_parentezco_padre_un_dato(nodo_a_splitear, nodo_menor, nodo_mayor);

    insertar_en_arbol(dato_intermedio, nodo_a_splitear->get_nodo_padre(), animal_a_insertar_proviene_de_split, resultado_insercion);
    delete nodo_a_splitear;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_nodo_con_hijos_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR TIENE 2 DATOS Y EL PADRE DEL NODO A SPLITEAR TAMBIEN TIENE 2 DATOS.
    Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_a_splitear->get_nodo_padre());
    Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_a_splitear->get_nodo_padre());

    //! CODIGO REPETIDO (1)
    nodo_menor->set_primer_hijo(nodo_a_splitear->get_primer_hijo());
    nodo_menor->set_segundo_hijo(nodo_a_splitear->get_segundo_hijo());

    nodo_mayor->set_primer_hijo(nodo_a_splitear->get_tercer_hijo());
    nodo_mayor->set_segundo_hijo(nodo_a_splitear->get_hijo_auxiliar());

    nodo_menor->get_primer_hijo()->set_nodo_padre(nodo_menor);
    nodo_menor->get_segundo_hijo()->set_nodo_padre(nodo_menor);

    nodo_mayor->get_primer_hijo()->set_nodo_padre(nodo_mayor);
    nodo_mayor->get_segundo_hijo()->set_nodo_padre(nodo_mayor);

    ordenar_parentezco_padre_dos_datos(nodo_a_splitear, nodo_menor, nodo_mayor);

    insertar_en_arbol(dato_intermedio, nodo_a_splitear->get_nodo_padre(), animal_a_insertar_proviene_de_split, resultado_insercion);
    delete nodo_a_splitear;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::ordenar_parentezco_padre_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nodo_menor, Nodo <Tipo_de_animal>* nodo_mayor){
    if(nodo_a_splitear->es_primer_hijo()){
        nodo_a_splitear->get_nodo_padre()->set_primer_hijo(nodo_menor);
        nodo_a_splitear->get_nodo_padre()->set_tercer_hijo(nodo_a_splitear->get_nodo_padre()->get_segundo_hijo());
        nodo_a_splitear->get_nodo_padre()->set_segundo_hijo(nodo_mayor);
    } else {
        //el primer hijo no hace falta modificarlo
        nodo_a_splitear->get_nodo_padre()->set_segundo_hijo(nodo_menor);
        nodo_a_splitear->get_nodo_padre()->set_tercer_hijo(nodo_mayor);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::ordenar_parentezco_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nuevo_nodo_menor, Nodo <Tipo_de_animal>* nuevo_nodo_mayor){
    if(nodo_a_splitear->es_primer_hijo()){
        nodo_a_splitear->get_nodo_padre()->set_hijo_auxiliar(nodo_a_splitear->get_nodo_padre()->get_tercer_hijo());
        nodo_a_splitear->get_nodo_padre()->set_tercer_hijo(nodo_a_splitear->get_nodo_padre()->get_segundo_hijo());
        nodo_a_splitear->get_nodo_padre()->set_primer_hijo(nuevo_nodo_menor);
        nodo_a_splitear->get_nodo_padre()->set_segundo_hijo(nuevo_nodo_mayor);
    } else if(nodo_a_splitear->es_tercer_hijo()){
        nodo_a_splitear->get_nodo_padre()->set_primer_hijo(nodo_a_splitear->get_nodo_padre()->get_primer_hijo());
        nodo_a_splitear->get_nodo_padre()->set_segundo_hijo(nodo_a_splitear->get_nodo_padre()->get_segundo_hijo());
        nodo_a_splitear->get_nodo_padre()->set_hijo_auxiliar(nuevo_nodo_mayor);
        nodo_a_splitear->get_nodo_padre()->set_tercer_hijo(nuevo_nodo_menor);
    } else {
        nodo_a_splitear->get_nodo_padre()->set_primer_hijo(nodo_a_splitear->get_nodo_padre()->get_primer_hijo());
        nodo_a_splitear->get_nodo_padre()->set_hijo_auxiliar(nodo_a_splitear->get_nodo_padre()->get_tercer_hijo());
        nodo_a_splitear->get_nodo_padre()->set_segundo_hijo(nuevo_nodo_menor);
        nodo_a_splitear->get_nodo_padre()->set_tercer_hijo(nuevo_nodo_mayor);
    }
}

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::nodo_es_raiz(Nodo<Tipo_de_animal>* nodo){
    return (nodo->get_nodo_padre() == nullptr);
}

template<typename Tipo_de_animal>
Nodo <Tipo_de_animal>* ArbolB <Tipo_de_animal>::get_raiz(){
    return raiz;
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
