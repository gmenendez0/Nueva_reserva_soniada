#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>
#include "animal.h"

using namespace std;

template < typename Tipo >
class Nodo_grafo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo_grafo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo_grafo(int id_vertice_nuevo, Animal* animal);

    //post: devuelve el nodo siguiente.
    Nodo_grafo<Tipo>* obtener_siguiente();

    //post: devuelve el id del vertice que contiene el nodo.
    int get_id();

    //post: le asigna como siguiente el nodo recibido
    void asignar_siguiente(Nodo_grafo<Tipo>* siguiente);

    ~Nodo_grafo();
};

template<typename Tipo>
Nodo_grafo<Tipo>::Nodo_grafo(int id_vertice_nuevo, Animal* animal) {
    elemento = new Tipo(id_vertice_nuevo, animal);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo_grafo<Tipo>* Nodo_grafo<Tipo>::obtener_siguiente() {
    return siguiente;
}

template<typename Tipo>
int Nodo_grafo<Tipo>::get_id() {
    return elemento->get_id();
}

template<typename Tipo>
void Nodo_grafo<Tipo>::asignar_siguiente(Nodo_grafo<Tipo>* siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo_grafo<Tipo>::~Nodo_grafo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
