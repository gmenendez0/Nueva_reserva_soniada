#ifndef GRAFOS_DIJKSTRA_H
#define GRAFOS_DIJKSTRA_H


#include "CaminoMinimo.h"

class Dijkstra : public camino_minimo{
//Atributos
private:
    bool* vertices_visitados;
    int* distancia;
    int* recorrido;

//Métodos
    //post: pone todos los valores del vector de verticesVisitados en "false" menos el origen
    void inicializar_visitados(int origen);

    //post: pone las distancias exactamente igual que la distanciaOrigen
    void inicializar_distancia(const int* distancia_origen);

    //post: llena el vector de recorrido con el origen
    void inicializar_recorrido(int origen);

    //post: devuelve el número de vértices con menor distancia al origen
    int vertice_minima_distancia();

    //post: actualiza el vector de distancias y el de recorrido con los valores que impone vertice.
    void actualizar_distancia(int vertice);

    //pre: para que tenga sentido, debe ejecutarse un recorrido previamente
    //post: muestra por pantalla el resultado del recorrido.
    void mostrar_recorrido(int origen, int destino);

    //post: muestra el estado instantaneo del vector de recorrido, distancia y visitados.
    void mostrar_iteracion(int iteracion);

    //post imprime por pantalla el recorrido de un vertice a otro si este recorrido existe y es factible.
    void mostrar_recorrido_factible(int origen, int destino);

public:
    Dijkstra(Lista<Vertice>* vertices, int** matriz_adyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void mostrar_camino_minimo(int origen, int destino) override;

    ~Dijkstra() override;
};


#endif //GRAFOS_DIJKSTRA_H
