#ifndef TP3_NODO_H
#define TP3_NODO_H

#include <string>
#include "animal.h"

using std::string;

const int MAXIMO_DATOS = 2;
const int PRIMERA_POSICION = 0;
const int SEGUNDA_POSICION = 1;
const int DOS_DATOS = 2;
const int UN_DATO = 1;

template<typename Tipo_de_animal>
class Nodo{
    private:
        Tipo_de_animal datos[MAXIMO_DATOS];
        int tope_datos;
        Nodo<Tipo_de_animal>* nodo_padre;
        Nodo<Tipo_de_animal>* primer_hijo;
        Nodo<Tipo_de_animal>* segundo_hijo;
        Nodo<Tipo_de_animal>* tercer_hijo;

    public:
        //Pre Debe recibir minimo un animal y maximo dos para insertarse como claves del nodo. En caso de recibir solo uno, el segundo tendra un valor por defecto de nulo.
        //    También puede recibir un nodo padre, pero en caso de no hacerlo, el valor de este será nulo por defecto.
        //Post Crea un nuevo nodo no raiz.
        Nodo(Tipo_de_animal primer_dato, Tipo_de_animal segundo_dato = nullptr, Nodo<Tipo_de_animal>* nodo_padre = nullptr);

        string get_primera_clave();

        string get_segunda_clave();

        bool es_hoja();

        int get_tope_datos();
};

template<typename Tipo_de_animal>
Nodo <Tipo_de_animal>::Nodo(Tipo_de_animal primer_dato, Tipo_de_animal segundo_dato, Nodo <Tipo_de_animal>* nodo_padre){
    datos[PRIMERA_POSICION] = primer_dato;
    datos[SEGUNDA_POSICION] = segundo_dato;
    tope_datos = UN_DATO;
    if(segundo_dato != nullptr) tope_datos = DOS_DATOS;

    this->nodo_padre = nodo_padre;
    primer_hijo = nullptr;
    segundo_hijo = nullptr;
    tercer_hijo = nullptr;

    std::cout << tope_datos;
}

template<typename Tipo_de_animal>
string Nodo <Tipo_de_animal>::get_primera_clave(){
    if(datos[PRIMERA_POSICION] != nullptr) return datos[PRIMERA_POSICION]->get_nombre();

    return "__vacio";
}

template<typename Tipo_de_animal>
string Nodo <Tipo_de_animal>::get_segunda_clave(){
    if(datos[SEGUNDA_POSICION] != nullptr) return datos[SEGUNDA_POSICION]->get_nombre();

    return "__vacio";
}

template<typename Tipo_de_animal>
bool Nodo <Tipo_de_animal>::es_hoja(){
    return (primer_hijo == nullptr && segundo_hijo == nullptr && tercer_hijo == nullptr);
}

template<typename Tipo_de_animal>
int Nodo <Tipo_de_animal>::get_tope_datos(){
    return tope_datos;
}

#endif
