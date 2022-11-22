#include "Grafo.h"
#include "Dijkstra.h"
#include <iostream>

Grafo::Grafo() {
    matriz_de_adyacencia = nullptr;
    vertices = new Lista<Vertice>();
    algortimo_camino_minimo = nullptr;
}

void Grafo::agregar_vertice(int id_vertice_nuevo, Animal* animal) {
    agrandar_matriz_de_adyacencia();
    vertices->agregar(id_vertice_nuevo, animal);
}

void Grafo::mostrar_grafo() {
    std::cout << "La matriz de adyacencia muestra el peso de viajar de un vertice adyacente a otro, o infinito si no son adyacentes" << std::endl;
    mostrar_vertices();
    mostrar_matriz_adyacencia();
}

bool Grafo::posicion_no_encontrada(int posicion_origen, int posicion_destino){
    return (!(posicion_destino == POSICION_NO_ENCONTRADA || posicion_origen == POSICION_NO_ENCONTRADA));
}

void Grafo::agregar_camino(int id_origen, int id_destino, int peso) {
    int posicion_origen = vertices->obtener_posicion(id_origen);
    int posicion_destino = vertices->obtener_posicion(id_destino);

    if(posicion_origen == POSICION_NO_ENCONTRADA) cout << "El vertice " << id_origen << " no existe en el grafo" << endl;

    if(posicion_destino == POSICION_NO_ENCONTRADA) cout << "El vertice " << id_destino << " no existe en el grafo" << endl;

    if(posicion_no_encontrada(posicion_origen, posicion_destino)) matriz_de_adyacencia[posicion_origen][posicion_destino] = peso;

}

void Grafo::obtener_camino_minimo(int id_origen, int id_destino) {
    int posicion_origen = vertices->obtener_posicion(id_origen);
    int posicion_destino = vertices->obtener_posicion(id_destino);

    if(posicion_origen == POSICION_NO_ENCONTRADA) cout << "El vertice " << id_origen << " no existe en el grafo" << endl;

    if(posicion_destino == POSICION_NO_ENCONTRADA) cout << "El vertice " << id_destino << " no existe en el grafo" << endl;

    mostrar_camino_minimo(posicion_origen, posicion_destino);
}

void Grafo::agrandar_matriz_de_adyacencia() {
    int** matriz_auxiliar;
    int nueva_cantidad_de_vertices = vertices->obtener_cantidad_de_elementos() + 1;

    matriz_auxiliar = new int*[nueva_cantidad_de_vertices];
    for(int i = 0; i < nueva_cantidad_de_vertices; i++){
        matriz_auxiliar[i] = new int[nueva_cantidad_de_vertices];
    }

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_adyacente) {
    for(int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++){
        for(int j = 0; j < vertices->obtener_cantidad_de_elementos(); j++){
            nueva_adyacente[i][j] = matriz_de_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_nuevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++){
        nueva_adyacente[vertices->obtener_cantidad_de_elementos()][i] = INFINITO;
        nueva_adyacente[i][vertices->obtener_cantidad_de_elementos()] = INFINITO;
    }
    nueva_adyacente[vertices->obtener_cantidad_de_elementos()][vertices -> obtener_cantidad_de_elementos()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++){
        delete[] matriz_de_adyacencia[i];
    }
    delete[] matriz_de_adyacencia;
}

Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = nullptr;
    delete vertices;
    delete algortimo_camino_minimo;
}

void Grafo::mostrar_vertices() {
    cout << "Lista de vértices: [";
    for(int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++){
        cout << vertices->obtener_id(i + 1);
        if(i + 1 != vertices->obtener_cantidad_de_elementos()) cout << ", ";
    }
    cout << "]" << endl;
}

//!no es necesario imprimir
void Grafo::realizar_impresion_matriz_adyacencia(int i, int j) {
    if(j == vertices->obtener_cantidad_de_elementos() * 2 - 1){
        cout << endl;
    } else if(j % 2 == 0){
        if(matriz_de_adyacencia[i][j/2] == INFINITO){
            cout << "∞";
        } else {
            cout << matriz_de_adyacencia[i][j/2];
        }
    } else{
        cout << "|";
    }
}

void Grafo::mostrar_matriz_adyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vertices->obtener_cantidad_de_elementos(); i++){
        for(int j = 0; j < vertices->obtener_cantidad_de_elementos() * 2; j++) {
            realizar_impresion_matriz_adyacencia(i, j);
        }
    }
    cout << endl;
}

void Grafo::mostrar_camino_minimo(int origen, int destino) {
    algortimo_camino_minimo->mostrar_camino_minimo(origen, destino);
}

/*void Grafo::usar_floyd() {
    delete algortimo_camino_minimo;
    algortimo_camino_minimo = new Floyd(vertices, matriz_de_adyacencia);
}*/

void Grafo::usar_dijkstra() {
    delete algortimo_camino_minimo;
    algortimo_camino_minimo = new Dijkstra(vertices, matriz_de_adyacencia);
}
