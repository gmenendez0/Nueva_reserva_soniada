#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "Nodo_grafo.h"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const int ID_NO_ENCONTRADO = -1;
const int UNA_POSICION = 1;

template <typename Tipo>
class Lista{
/*ATRIBUTOS*/
private:
    int cantidad_de_elementos;
    Nodo_grafo<Tipo>* primero;
    Nodo_grafo<Tipo>* ultimo;

/*MÉTODOS*/
public:
    Lista();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtener_cantidad_de_elementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtener_posicion(int id);

    //post: devuelve el id que se encuentra en la posicion recibida o ID_NO_ENCONTRADO si no lo encuentra
    int obtener_id(int posicion);

    //post: devuelve el color que se encuentra en la posicion recibida o ID_NO_ENCONTRADO si no lo encuentra
    char obtener_color(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(int id_vertice_nuevo, Animal* animal, char color);

    ~Lista();
};

template < typename Tipo >
Lista<Tipo>::Lista(){
    cantidad_de_elementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista<Tipo>::obtener_cantidad_de_elementos(){
    return cantidad_de_elementos;
}

template < typename Tipo >
int Lista<Tipo>::obtener_posicion(int id) {
    bool elemento_encontrado = false;
    int i = 0;
    Nodo_grafo<Tipo>* auxiliar = primero;

    while(!elemento_encontrado && i < cantidad_de_elementos){
        if(auxiliar->get_id() == id) elemento_encontrado = true;

        i++;
        auxiliar = auxiliar->obtener_siguiente();
    }

    if(!elemento_encontrado) return POSICION_NO_ENCONTRADA;

    return i - UNA_POSICION;
}

template < typename Tipo >
void Lista<Tipo>::agregar(int id_vertice_nuevo, Animal* animal, char color) {
    Nodo_grafo<Tipo>* nuevoNodo = new Nodo_grafo<Tipo>(id_vertice_nuevo, animal, color);

    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignar_siguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidad_de_elementos++;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    Nodo_grafo<Tipo>* siguiente;

    while(primero != nullptr){
        siguiente = primero->obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
int Lista<Tipo>::obtener_id(int posicion) {
    int i = 0;
    Nodo_grafo<Tipo>* auxiliar = primero;

    if(posicion > cantidad_de_elementos) return ID_NO_ENCONTRADO;

    while(i != posicion - 1){
        auxiliar = auxiliar->obtener_siguiente();
        i++;
    }

    return auxiliar->get_id();
}

template<typename Tipo>
char Lista<Tipo>::obtener_color(int posicion) {
    int i = 0;
    Nodo_grafo<Tipo>* auxiliar = primero;

    if(posicion > cantidad_de_elementos) return ID_NO_ENCONTRADO;

    while(i != posicion){
        auxiliar = auxiliar->obtener_siguiente();
        i++;
    }
    return auxiliar->get_color();
}

#endif //GRAFOS_LISTA_H
