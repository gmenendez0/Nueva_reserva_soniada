#ifndef GRAFOS_CAMINOMINIMO_H
#define GRAFOS_CAMINOMINIMO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include <iostream>

const int INFINITO = 99999999;

class CaminoMinimo {
//Atributos
protected:
    int ** matrizAdyacencia;
    Lista<Vertice> * vertices;
    int cantidadVertices;

//Métodos
public:
    CaminoMinimo(Lista<Vertice> * vertices, int** matrizAdyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual void caminoMinimo(int origen, int destino) = 0;

    virtual ~CaminoMinimo() = default;
};


#endif //GRAFOS_CAMINOMINIMO_H
