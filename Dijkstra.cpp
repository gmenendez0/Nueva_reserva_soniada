#include "Dijkstra.h"

Dijkstra::Dijkstra(Lista<Vertice> *vertices, int **matrizAdyacencia) : CaminoMinimo(vertices, matrizAdyacencia) {
    verticesVisitados = new bool[cantidadVertices];
    distancia = new int[cantidadVertices];
    recorrido = new int[cantidadVertices];
}

void Dijkstra::caminoMinimo(int origen, int destino) {
    inicializarVisitados(origen);
    inicializarDistancia(matrizAdyacencia[origen]);
    inicializarRecorrido(origen);

    int minimoVertice;

    bool destinoArribado = origen == destino;
    int verticesRecorridos = 1;
    while(!destinoArribado){
        mostrarIteracion(verticesRecorridos - 1);
        minimoVertice = verticeMinimaDistancia();
        destinoArribado = minimoVertice == destino;

        if(!destinoArribado){
            verticesVisitados[minimoVertice] = true;
            actualizarDistancia(minimoVertice);
        }
        verticesRecorridos++;
    }

    mostrarRecorrido(origen, destino);
}

int Dijkstra::verticeMinimaDistancia() {
    int minimaDistancia = INFINITO;
    int minimoVertice;

    for(int i = 0; i < cantidadVertices; i++){
        if(!verticesVisitados[i] && distancia[i] <= minimaDistancia){
            minimaDistancia = distancia[i];
            minimoVertice = i;
        }
    }

    return minimoVertice;
}

void Dijkstra::inicializarVisitados(int origen) {
    for(int i = 0; i < cantidadVertices; i++)
        verticesVisitados[i] = false;
    verticesVisitados[origen] = true;
}

void Dijkstra::inicializarRecorrido(int origen) {
    for(int i = 0; i < cantidadVertices; i++)
        recorrido[i] = origen;
}

Dijkstra::~Dijkstra() {
    delete[] verticesVisitados;
    delete[] distancia;
    delete[] recorrido;
}

void Dijkstra::inicializarDistancia(const int * distanciaOrigen) {
    for(int i = 0; i < cantidadVertices; i++)
        distancia[i] = distanciaOrigen[i];
}

void Dijkstra::actualizarDistancia(int vertice) {
    for(int i = 0; i < cantidadVertices; i++){
        if(!verticesVisitados[i] && distancia[vertice] != INFINITO && distancia[i] > matrizAdyacencia[vertice][i] + distancia[vertice]){
            distancia[i] = matrizAdyacencia[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}

void Dijkstra::mostrarRecorrido(int origen, int destino) {
    if(distancia[destino] == INFINITO){
        cout << "No hay un camino que conecte " <<  vertices->obtener_id(origen + 1) << " con " << vertices->obtener_id(destino + 1);
    }else{
        cout << "El camino minimo que une " <<  vertices->obtener_id(origen + 1) << " con " << vertices->obtener_id(destino + 1);
        cout << " tiene un costo de: " << distancia[destino] << " y es el siguiente: ";
        cout << vertices->obtener_id(destino + 1);
        do{
            destino = recorrido[destino];
            cout << " <- " << vertices->obtener_id(destino + 1);
        }while(origen != destino);
    }
    cout << endl;
}

void Dijkstra::mostrarIteracion(int iteracion) {
    cout << endl << "Iteración " << iteracion << endl;

    cout << "Visitados: [";
    for(int i = 0; i < cantidadVertices; i++){
        cout << verticesVisitados[i];
        if(i + 1 != cantidadVertices){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Distancia: [";
    for(int i = 0; i < cantidadVertices; i++){
        if(distancia[i] != INFINITO) {
            cout << distancia[i];
        } else {
            cout << "∞";
        }
        if(i + 1 != cantidadVertices){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Recorrido: [";
    for(int i = 0; i < cantidadVertices; i++){
        cout << vertices -> obtener_id(recorrido[i] + 1);
        if(i + 1 != cantidadVertices){
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
}



