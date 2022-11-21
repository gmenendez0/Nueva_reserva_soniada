#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "Nodo_grafo.h"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const int NOMBRE_NO_ENCONTRADO = -1;

template < typename Tipo >
class Lista{
/*ATRIBUTOS*/
private:
    int cantidadDeElementos;
    Nodo_grafo<Tipo>* primero;
    Nodo_grafo<Tipo>* ultimo;

/*MÉTODOS*/
public:
    Lista();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtenerCantidadDeElementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtenerPosicion(int id);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    int obtener_id(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(int id_vertice_nuevo, Animal* animal);

    ~Lista();
};

template < typename Tipo >
Lista<Tipo>::Lista(){
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista<Tipo>::obtenerCantidadDeElementos(){
    return cantidadDeElementos;
}

template < typename Tipo >
int Lista<Tipo>::obtenerPosicion(int id) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo_grafo<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidadDeElementos){
        if(auxiliar -> get_id() == id){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista<Tipo>::agregar(int id_vertice_nuevo, Animal* animal) {
    Nodo_grafo<Tipo>* nuevoNodo = new Nodo_grafo<Tipo>(id_vertice_nuevo, animal);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidadDeElementos++;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    Nodo_grafo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
int Lista<Tipo>::obtener_id(int posicion) {
    int i = 0;
    Nodo_grafo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }

    return auxiliar -> get_id();
}

#endif //GRAFOS_LISTA_H
