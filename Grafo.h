#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "Floyd.h"

using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
    int ** matrizDeAdyacencia;
    Lista<Vertice> * vertices;
    CaminoMinimo * algoritmoCaminoMinimo;

/*MÉTODOS*/

    //Pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void caminoMinimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandarMatrizDeAdyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiarMatrizAdyacente(int** nuevaAdyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializarNuevoVertice(int** nuevaAdyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberarMatrizAdyacencia();

    //post: imprime por pantalla los vertices del grafo
    void mostrarVertices();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrarMatrizAdyacencia();
public:

    Grafo();

    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregarVertice(int id_vertice_nuevo, Animal* animal);

    //pre: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //post: muestra por terminal el camino mínimo desde un origen a un destino
    void obtener_camino_minimo(int id_origen, int id_destino);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregarCamino(int id_origen, int id_destino, int peso);

    //post: imprime por pantalla el grafo
    void mostrarGrafo();

    //post: selecciona el algortimo de Floyd para calcular el camino mínimo
    void usarFloyd();

    //post: selecciona el algortimo de Dijkstra para calcular el camino mínimo
    void usarDijkstra();

    ~Grafo();
};


#endif //GRAFOS_GRAFO_H
