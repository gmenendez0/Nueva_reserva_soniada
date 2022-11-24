#include "Dijkstra.h"

const int UN_VERTICE = 1;

Dijkstra::Dijkstra(Lista<Vertice>* vertices, int** matriz_adyacencia) : camino_minimo(vertices, matriz_adyacencia) {
    vertices_visitados = new bool[cantidad_vertices];
    distancia = new int[cantidad_vertices];
    recorrido = new int[cantidad_vertices];
}

int Dijkstra::calcular_peso_minimo(int origen, int destino){
    inicializar_visitados(origen);
    inicializar_distancia(matriz_adyacencia[origen]);
    inicializar_recorrido(origen);

    int minimo_vertice;
    bool destino_arribado = origen == destino;
    int vertices_recorridos = UN_VERTICE;

    while(!destino_arribado){
        minimo_vertice = vertice_minima_distancia();
        destino_arribado = minimo_vertice == destino;

        if(!destino_arribado){
            vertices_visitados[minimo_vertice] = true;
            actualizar_distancia(minimo_vertice);
        }
        vertices_recorridos++;
    }

    return distancia[destino];
}

void Dijkstra::mostrar_camino_minimo(int origen, int destino) {
    calcular_peso_minimo(origen, destino);
    mostrar_recorrido(origen, destino);
}

int Dijkstra::vertice_minima_distancia() {
    int minima_distancia = INFINITO;
    int minimo_vertice;

    for(int i = 0; i < cantidad_vertices; i++){
        if(!vertices_visitados[i] && distancia[i] <= minima_distancia){
            minima_distancia = distancia[i];
            minimo_vertice = i;
        }
    }

    return minimo_vertice;
}

void Dijkstra::inicializar_visitados(int origen) {
    for(int i = 0; i < cantidad_vertices; i++){
        vertices_visitados[i] = false;
    }
    vertices_visitados[origen] = true;
}

void Dijkstra::inicializar_recorrido(int origen) {
    for(int i = 0; i < cantidad_vertices; i++){
        recorrido[i] = origen;
    }
}

Dijkstra::~Dijkstra() {
    delete[] vertices_visitados;
    delete[] distancia;
    delete[] recorrido;
}

void Dijkstra::inicializar_distancia(const int* distancia_origen) {
    for(int i = 0; i < cantidad_vertices; i++)
        distancia[i] = distancia_origen[i];
}

void Dijkstra::actualizar_distancia(int vertice) {
    for(int i = 0; i < cantidad_vertices; i++){
        if(!vertices_visitados[i] && distancia[vertice] != INFINITO && distancia[i] > matriz_adyacencia[vertice][i] + distancia[vertice]){ //! modularizar
            distancia[i] = matriz_adyacencia[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}

void Dijkstra::mostrar_recorrido_factible(int origen, int destino) {
    cout << "El camino minimo que une " <<  vertices->obtener_id(origen + UNA_POSICION) << " con " << vertices->obtener_id(destino + UNA_POSICION);
    cout << " tiene un costo de: " << distancia[destino] << " y es el siguiente: ";
    cout << vertices->obtener_id(destino + UNA_POSICION);
    do{
        destino = recorrido[destino];
        cout << " <- " << vertices->obtener_id(destino + UNA_POSICION);
    }while(origen != destino);
}

void Dijkstra::mostrar_recorrido(int origen, int destino) {
    if(distancia[destino] == INFINITO){
        cout << "No hay un camino que conecte " <<  vertices->obtener_id(origen + UNA_POSICION) << " con " << vertices->obtener_id(destino + UNA_POSICION);
    }else{
        mostrar_recorrido_factible(origen, destino);
    }
    cout << endl;
}



