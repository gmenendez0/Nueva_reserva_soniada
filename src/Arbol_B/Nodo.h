#ifndef TP3_NODO_H
#define TP3_NODO_H

#include <string>
#include "Animal/Animal.h"

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
        Nodo<Tipo_de_animal>* hijo_auxiliar;

    public:
        //Pre Debe recibir minimo un animal y maximo dos para insertarse como claves del nodo. En caso de recibir solo uno, el segundo tendra un valor por defecto de nulo.
        //    También puede recibir un nodo padre, pero en caso de no hacerlo, el valor de este será nulo por defecto.
        //Post Crea un nuevo nodo no raiz.
        Nodo(Tipo_de_animal primer_dato, Tipo_de_animal segundo_dato = nullptr, Nodo<Tipo_de_animal>* nodo_padre = nullptr);

        //Pre -
        //Post Devuelve la primera clave
        string get_primera_clave();

        //Pre
        //Post Devuelve la segunda clave
        string get_segunda_clave();

        //Pre
        //Post Devuelve true si el nodo es hoja, false caso contrario
        bool es_hoja();

        //Pre
        //Post Devuelve true si el nodo es raiz, false en caso contrario
        bool es_raiz();

        //Pre
        //Post Devuelve tope datos
        int get_tope_datos();

        //Pre
        //Post Setea el primer dato del nodo con el dato recibido
        void set_primer_dato(Tipo_de_animal dato);

        //Pre
        //Post Setea el segundo dato del nodo con el dato recibido
        void set_segundo_dato(Tipo_de_animal dato);

        //Pre
        //Post Devuelve el primer dato
        Tipo_de_animal get_primer_dato();

        //Pre
        //Post Devuelve el segundo dato
        Tipo_de_animal get_segundo_dato();

        //Pre
        //Post Aumenta en 1 tope datos
        void aumentar_tope_datos();

        //Pre
        //Post  Devuelve el primer hijo del nodo
        Nodo<Tipo_de_animal>* get_primer_hijo();

        //Pre
        //Post Devuelve el segundo hijo del nodo
        Nodo<Tipo_de_animal>* get_segundo_hijo();

        //Pre
        //Post Devuelve el tercer hijo del nodo
        Nodo<Tipo_de_animal>* get_tercer_hijo();

        //Pre
        //Post Setea el primer hijo del nodo con el nodo recibido
        void set_primer_hijo(Nodo<Tipo_de_animal>* primer_hijo);

        //Pre
        //Post Setea el segundo hijo del nodo con el nodo recibido
        void set_segundo_hijo(Nodo<Tipo_de_animal>* segundo_hijo);

        //Pre
        //Post Setea el tercer hijo del nodo con el nodo recibido
        void set_tercer_hijo(Nodo<Tipo_de_animal>* tercer_hijo);

        //Pre
        //Post
        Nodo<Tipo_de_animal>* get_nodo_padre();

        //Pre
        //Post Setea el nodo padre del nodo con el nodo recibido
        void set_nodo_padre(Nodo<Tipo_de_animal>* nodo_padre);

        //Pre
        //Post Devuelve el hijo auxiliar
        Nodo<Tipo_de_animal>* get_hijo_auxiliar();

        //Pre
        //Post Setea el hijo auxiliar con el nodo recibido
        void set_hijo_auxiliar(Nodo<Tipo_de_animal>* hijo);

        //Pre
        //Post Devuelve true en caso de que el nodo sea primer hijo del padre, false en caso contrario
        bool es_primer_hijo();

        //Pre
        //Post Devuelve true en caso de que el nodo sea tercer hijo del padre, false en caso contrario
        bool es_tercer_hijo();

        //Pre
        //Post Devuelve un puntero al animal con el nombre recibido en caso de encontrarlo, en caso contrario devuelve nullptr
        Tipo_de_animal buscar_animal_con_mismo_nombre(string nombre_animal);


        //Pre
        //Post Devuelve el dato que esté en la posicion recibida en el vector
        Tipo_de_animal get_dato_buscado(int posicion);
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
    hijo_auxiliar = nullptr;
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

template<typename Tipo_de_animal>
void Nodo <Tipo_de_animal>::set_primer_dato(Tipo_de_animal dato){
    datos[PRIMERA_POSICION] = dato;
}

template<typename Tipo_de_animal>
void Nodo <Tipo_de_animal>::set_segundo_dato(Tipo_de_animal dato){
    datos[SEGUNDA_POSICION] = dato;
}

template<typename Tipo_de_animal>
Tipo_de_animal Nodo <Tipo_de_animal>::get_primer_dato(){
    return datos[PRIMERA_POSICION];
}

template<typename Tipo_de_animal>
Tipo_de_animal Nodo <Tipo_de_animal>::get_segundo_dato(){
    return datos[SEGUNDA_POSICION];
}

template<typename Tipo_de_animal>
void Nodo <Tipo_de_animal>::aumentar_tope_datos(){
    tope_datos++;
}

template<typename Tipo_de_animal>
Nodo <Tipo_de_animal>* Nodo <Tipo_de_animal>::get_primer_hijo(){
    return primer_hijo;
}

template<typename Tipo_de_animal>
Nodo <Tipo_de_animal>* Nodo <Tipo_de_animal>::get_segundo_hijo(){
    return segundo_hijo;
}

template<typename Tipo_de_animal>
Nodo <Tipo_de_animal>* Nodo <Tipo_de_animal>::get_tercer_hijo(){
    return tercer_hijo;
}

template<typename Tipo_de_animal>
Nodo <Tipo_de_animal>* Nodo <Tipo_de_animal>::get_nodo_padre(){
    return nodo_padre;
}

template<typename Tipo_de_animal>
void Nodo <Tipo_de_animal>::set_nodo_padre(Nodo<Tipo_de_animal>* nodo_padre){
    this->nodo_padre = nodo_padre;
}

template<typename Tipo_de_animal>
void Nodo <Tipo_de_animal>::set_primer_hijo(Nodo <Tipo_de_animal>* primer_hijo){
    this->primer_hijo = primer_hijo;
}

template<typename Tipo_de_animal>
void Nodo <Tipo_de_animal>::set_segundo_hijo(Nodo <Tipo_de_animal>* segundo_hijo){
    this->segundo_hijo = segundo_hijo;
}

template<typename Tipo_de_animal>
void Nodo <Tipo_de_animal>::set_tercer_hijo(Nodo <Tipo_de_animal>* tercer_hijo){
    this->tercer_hijo = tercer_hijo;
}

template<typename Tipo_de_animal>
Nodo <Tipo_de_animal>* Nodo <Tipo_de_animal>::get_hijo_auxiliar(){
    return hijo_auxiliar;
}

template<typename Tipo_de_animal>
void Nodo <Tipo_de_animal>::set_hijo_auxiliar(Nodo <Tipo_de_animal>* hijo){
    hijo_auxiliar = hijo;
}

template<typename Tipo_de_animal>
bool Nodo <Tipo_de_animal>::es_primer_hijo(){
    return(datos[PRIMERA_POSICION]->get_nombre() < nodo_padre->get_primer_dato()->get_nombre());
}

template<typename Tipo_de_animal>
bool Nodo <Tipo_de_animal>::es_tercer_hijo(){
    return (datos[PRIMERA_POSICION]->get_nombre() > nodo_padre->get_segundo_dato()->get_nombre());
}

template<typename Tipo_de_animal>
Tipo_de_animal Nodo <Tipo_de_animal>::buscar_animal_con_mismo_nombre(string nombre_animal){
    Tipo_de_animal animal_presente = nullptr;

    for(int i = 0; i < tope_datos; ++i){
        if(datos[i]->get_nombre() == nombre_animal){
            animal_presente = datos[i];
        }
    }

    return animal_presente;
}

template<typename Tipo_de_animal>
Tipo_de_animal Nodo <Tipo_de_animal>::get_dato_buscado(int posicion){
    return datos[posicion];
}

template<typename Tipo_de_animal>
bool Nodo <Tipo_de_animal>::es_raiz(){
    return (nodo_padre == nullptr);
}

#endif
