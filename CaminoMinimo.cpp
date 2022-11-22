#include "CaminoMinimo.h"

camino_minimo::camino_minimo(Lista<Vertice>* vertices, int** matriz_adyacencia) {
    this->vertices = vertices;
    this->matriz_adyacencia = matriz_adyacencia;
    cantidad_vertices = vertices->obtener_cantidad_de_elementos();
}
