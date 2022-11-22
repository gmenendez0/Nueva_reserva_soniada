#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "CaminoMinimo.h"

using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
    int** matriz_de_adyacencia;
    Lista<Vertice>* vertices;
    camino_minimo* algortimo_camino_minimo;

/*MÉTODOS*/

    //Pre: tienen que existir tanto el origen como el destino. Además se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void mostrar_camino_minimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_de_adyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacente(int** nueva_adyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_nuevo_vertice(int** nueva_adyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

    //post: imprime por pantalla los vertices del grafo
    void mostrar_vertices();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrar_matriz_adyacencia();

    void realizar_impresion_matriz_adyacencia(int i, int j);

    bool posicion_no_encontrada(int posicion_origen, int posicion_destino);
public:

    Grafo();

    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregar_vertice(int id_vertice_nuevo, Animal* animal);

    //pre: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //post: muestra por terminal el camino mínimo desde un origen a un destino
    void obtener_camino_minimo(int id_origen, int id_destino);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregar_camino(int id_origen, int id_destino, int peso);

    //post: imprime por pantalla el grafo
    void mostrar_grafo();

    //post: selecciona el algortimo de Floyd para calcular el camino mínimo
    //void usar_floyd();

    //post: selecciona el algortimo de Dijkstra para calcular el camino mínimo
    void usar_dijkstra();

    ~Grafo();
};


#endif //GRAFOS_GRAFO_H
