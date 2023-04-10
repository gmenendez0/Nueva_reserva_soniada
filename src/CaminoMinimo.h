#ifndef GRAFOS_CAMINOMINIMO_H
#define GRAFOS_CAMINOMINIMO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include <iostream>

const int INFINITO = 99999999;

class camino_minimo {
//Atributos
protected:
    int** matriz_adyacencia;
    Lista<Vertice>* vertices;
    int cantidad_vertices;

//Métodos
public:
    camino_minimo(Lista<Vertice>* vertices, int** matriz_adyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual void mostrar_camino_minimo(int origen, int destino) = 0;

    //post: Devuelve el peso del camino mínimo entre el origen y el destino
    virtual int calcular_peso_minimo(int origen, int destino) = 0;

    virtual ~camino_minimo() = default;
};

#endif //GRAFOS_CAMINOMINIMO_H
