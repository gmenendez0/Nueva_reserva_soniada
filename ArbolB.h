#ifndef TP3_ARBOLB_H
#define TP3_ARBOLB_H

const int ANIMAL_REPETIDO = 1;
const int COMPLETADA = 0;
const int ANIMAL_NO_ENCONTRADO = 1;

#include <iostream>
#include "nodo.h"

template<typename Tipo_de_animal>
class ArbolB{
    private:
        Nodo<Tipo_de_animal>* raiz;

    private:
        //Pre
        //Post
        int* insertar_en_arbol(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post
        void evaluar_posibilidades_nodo_hoja(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        //Pre
        //Post
        void evaluar_posibilidades_nodo_con_hijos(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post
        bool animal_es_mas_grande(string nombre_animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        //Pre
        //Post
        bool animal_es_intermedio(string nombre_animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        //Pre
        //Post
        void split_hoja(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post
        void split_nodo_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post
        void realizar_insercion(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal);

        //Pre
        //Post
        void evaluar_insercion_proveniente_de_split(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        //Pre
        //Post
        void evaluar_insercion_no_proveniente_de_split(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        //Pre
        //Post
        void realizar_insercion_proveniente_de_split_dos_datos(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        //Pre
        //Post
        void evaluar_insercion_no_proveniente_de_split_un_dato(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
        int* resultado_insercion);

        //Pre
        //Post
        void evaluar_insercion_no_proveniente_de_split_dos_datos(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
        int* resultado_insercion);

        //Pre
        //Post
        void realizar_split_nodo_hoja_raiz(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor);

        //Pre
        //Post
        void realizar_split_nodo_hoja_un_dato(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post
        void realizar_split_nodo_hoja_dos_datos(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post
        void ordenar_parentezco_padre_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nodo_menor, Nodo <Tipo_de_animal>* nodo_mayor);

        //Pre
        //Post
        void ordenar_parentezco_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nuevo_nodo_menor, Nodo <Tipo_de_animal>* nuevo_nodo_mayor);

        //Pre
        //Post
        void split_nodo_raiz_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor);

        //Pre
        //Post
        void split_nodo_con_hijos_padre_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor, bool
        &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post
        void split_nodo_con_hijos_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor, bool
        &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post
        void evaluar_repeticion_nombre(Tipo_de_animal animal_coincidente, Tipo_de_animal animal, int* resultado_insercion);

        //Pre
        //Post
        Tipo_de_animal revisar_arbol(string nombre, Nodo <Tipo_de_animal>* nodo_a_revisar);

        //Pre
        //Post
        void presentar_todos(Nodo<Tipo_de_animal>* nodo_actual);

        //Pre
        //Post
        void presentar_datos_nodo(Nodo<Tipo_de_animal>* nodo_actual);

        //Pre
        //Post
        Tipo_de_animal analizar_animal_encontrado(Tipo_de_animal animal_encontrado);

    public:
        //Pre -
        //Post Crea un arbol vacio.
        ArbolB();

        //Pre Tiene que recibir un elemento inicializado para insertarse en el arbol usando su nombre como clave
        //Post Devolvera 0 en caso de operacion completada exitosamente y 1 en caso de animal repetido
        int insertar(Tipo_de_animal animal);

        //Pre -
        //Post Devolvera un puntero al animal buscado en caso de encontrarlo, y en caso contrario devuelve nullptr
        Tipo_de_animal buscar_animal(string nombre);

        Nodo<Tipo_de_animal>* get_raiz();   //? PARA DEBUGGING

        //Pre -
        //Post Devolvera 0 en caso de eliminacion exitosa, 1 en caso contrario que no se haya encontrado el animal a eliminar
        int eliminar_animal(string nombre);

        //Pre -
        //Post Presentara todos los animales dentro del arbol
        void presentar_todos();
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
    } else if(nodo_a_insertar->buscar_animal_con_mismo_nombre(animal->get_nombre()) != nullptr){
         evaluar_repeticion_nombre(nodo_a_insertar->buscar_animal_con_mismo_nombre(animal->get_nombre()), animal, resultado_insercion);
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
        animal_coincidente = animal;        //? AVERIGUAR COMO HACER QUE ESTO ANDE CORRECTAMENTE
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
        if(animal_es_mas_grande(animal->get_nombre(), nodo_a_insertar)){
            split_hoja(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal, animal_a_insertar_proviene_de_split, resultado_insercion);
            //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
        } else if(animal_es_intermedio(animal->get_nombre(), nodo_a_insertar)) {
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
    if(animal_es_mas_grande(animal->get_nombre(), nodo_a_insertar)){
        split_nodo_con_hijos(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal, animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
    } else if(animal_es_intermedio(animal->get_nombre(), nodo_a_insertar)) {
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
    if(animal_es_mas_grande(animal->get_nombre(), nodo_a_insertar)){
        insertar_en_arbol(animal, nodo_a_insertar->get_tercer_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. Se avanza al tercer hijo del nodo.
    } else if(animal_es_intermedio(animal->get_nombre(), nodo_a_insertar)) {
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
    if(nodo_a_splitear->es_raiz()){
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

    if(nodo_a_splitear->es_raiz()){
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

    //? CODIGO REPETIDO (1) SE PUEDE MODULARIZAR AUN MÁS
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

    //? CODIGO REPETIDO (1) SE PUEDE MODULARIZAR AUN MÁS
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

    //? CODIGO REPETIDO (1) SE PUEDE MODULARIZAR AUN MÁS
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
    //? SE PUEDE MODULARIZAR AUN MÁS
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
    //? SE PUEDE MODULARIZAR AUN MÁS
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
Nodo <Tipo_de_animal>* ArbolB <Tipo_de_animal>::get_raiz(){
    return raiz;
}

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::animal_es_mas_grande(string nombre_animal, Nodo <Tipo_de_animal>* nodo_a_insertar){
    return (nodo_a_insertar->get_primera_clave() < nombre_animal && nodo_a_insertar->get_segunda_clave() < nombre_animal);
}

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::animal_es_intermedio(string nombre_animal, Nodo <Tipo_de_animal>* nodo_a_insertar){
    return (nodo_a_insertar->get_primera_clave() < nombre_animal && nodo_a_insertar->get_segunda_clave() > nombre_animal);
}

//!------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
Tipo_de_animal ArbolB <Tipo_de_animal>::buscar_animal(string nombre){
    return revisar_arbol(nombre, raiz);
}

template<typename Tipo_de_animal>
Tipo_de_animal ArbolB <Tipo_de_animal>::revisar_arbol(string nombre, Nodo <Tipo_de_animal>* nodo_a_revisar){
    if(nodo_a_revisar == nullptr) return nullptr;

    Tipo_de_animal animal_buscado = nodo_a_revisar->buscar_animal_con_mismo_nombre(nombre);
    //! RECORDAR QUE ESTA FUNCION TIENE UN ERROR: DA EL ANIMAL COMO ENCONTRADO A PESAR DE TENER EL ATRIBUTO "ELIMINADO"

    if(animal_buscado != nullptr){
        return analizar_animal_encontrado(animal_buscado);
    } else if(nombre < nodo_a_revisar->get_primera_clave()){
        return revisar_arbol(nombre, nodo_a_revisar->get_primer_hijo());
    } else if((nombre > nodo_a_revisar->get_primera_clave() && nodo_a_revisar->get_tope_datos() == UN_DATO) || (animal_es_intermedio(nombre, nodo_a_revisar))){
        return revisar_arbol(nombre, nodo_a_revisar->get_segundo_hijo());
    } else if(animal_es_mas_grande(nombre, nodo_a_revisar)){
        return revisar_arbol(nombre, nodo_a_revisar->get_tercer_hijo());
    }

    return nullptr;
}

template<typename Tipo_de_animal>
Tipo_de_animal ArbolB <Tipo_de_animal>::analizar_animal_encontrado(Tipo_de_animal animal_encontrado){
    if(animal_encontrado->esta_eliminado()) return nullptr;

    return animal_encontrado;
}

//! ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
int ArbolB <Tipo_de_animal>::eliminar_animal(string nombre){
    Tipo_de_animal animal_a_eliminar = revisar_arbol(nombre, raiz);
    if(animal_a_eliminar == nullptr) return ANIMAL_NO_ENCONTRADO;

    animal_a_eliminar->eliminar();
    return COMPLETADA;
}

//! ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::presentar_todos(){
    this->presentar_todos(raiz);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::presentar_todos(Nodo <Tipo_de_animal>* nodo_actual){
    if(nodo_actual != nullptr) presentar_datos_nodo(nodo_actual);

    if(nodo_actual->get_primer_hijo() != nullptr) presentar_todos(nodo_actual->get_primer_hijo());
    if(nodo_actual->get_segundo_hijo() != nullptr) presentar_todos(nodo_actual->get_segundo_hijo());
    if(nodo_actual->get_tercer_hijo() != nullptr) presentar_todos(nodo_actual->get_tercer_hijo());
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::presentar_datos_nodo(Nodo <Tipo_de_animal>* nodo_actual){
    for(int i = 0; i < nodo_actual->get_tope_datos(); ++i){
        nodo_actual->get_dato_buscado(i)->presentar_animal();
    }
}

#endif //TP3_ARBOLB_H
