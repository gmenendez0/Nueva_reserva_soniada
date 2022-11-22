#include "adoptar_animal_controllers.h"
#include "Grafo.h"
#include "ArbolB.h"

const int CANTIDAD_DE_VERTICES_NECESITADOS = 64;
const int MAXIMO_POSICIONES_RANDOM_NECESITADAS = 5;
const int UNA_POSICION = 1;
const int TERCERA_POSICION = 2;
const int CUARTA_POSICION = 3;
const int QUINTA_POSICION = 4;
const int ID_PRIMER_VERTICE = 1;
const int ID_VERTICE_DERECHO_PRIMER_VERTICE = 2;
const int ID_ULTIMO_VERTICE_PRIMER_FILA = 8;
const int ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE_PRIMER_FILA = 7;
const int ID_VERTICE_INFERIOR_PRIMER_VERTICE = 9;
const int ID_VERTICE_INFERIOR_ULTIMO_VERTICE_PRIMER_FILA = 16;
const int ID_ULTIMO_VERTICE = 64;
const int ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE = 63;
const int ID_VERTICE_SUPERIOR_ULTIMO_VERTICE = 56;
const int ID_PRIMER_VERTICE_ULTIMA_FILA = 57;
const int ID_VERTICE_DERECHO_PRIMER_VERTICE_ULTIMA_FILA = 58;
const int ID_VERTICE_SUPERIOR_PRIMER_VERTICE_ULTIMA_FILA = 49;

bool coincide_con_posicion_random(int i, int posiciones_random[]){
    return (i == posiciones_random[PRIMERA_POSICION] || i == posiciones_random[SEGUNDA_POSICION] || i == posiciones_random[TERCERA_POSICION] || i == posiciones_random[CUARTA_POSICION] || i ==
    posiciones_random[QUINTA_POSICION]);
}

void inicializar_vertices(Grafo &grafo_mapa, int posiciones_random[]){
    for(int i = ID_PRIMER_VERTICE; i <= CANTIDAD_DE_VERTICES_NECESITADOS; ++i){
        if(coincide_con_posicion_random(i, posiciones_random)){
            cout << "entre por posicion random";
        } else {
            grafo_mapa.agregar_vertice(i, nullptr);
        }
    }
}

void inicializar_posiciones_random(int posiciones_random[]){
    for(int i = 0; i < MAXIMO_POSICIONES_RANDOM_NECESITADAS; ++i){
        posiciones_random[i] = UNA_POSICION + (rand() % CANTIDAD_DE_VERTICES_NECESITADOS);
    }
}

void inicializar_aristas_vertices_esquinas(Grafo &grafo_mapa){
    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE, ID_VERTICE_DERECHO_PRIMER_VERTICE, 40);
    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE, ID_VERTICE_INFERIOR_PRIMER_VERTICE, 1);

    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE_PRIMER_FILA, ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE_PRIMER_FILA, 2);
    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE_PRIMER_FILA, ID_VERTICE_INFERIOR_ULTIMO_VERTICE_PRIMER_FILA, 40);

    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE_ULTIMA_FILA, ID_VERTICE_SUPERIOR_PRIMER_VERTICE_ULTIMA_FILA, 2);
    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE_ULTIMA_FILA, ID_VERTICE_DERECHO_PRIMER_VERTICE_ULTIMA_FILA, 2);

    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE, ID_VERTICE_SUPERIOR_ULTIMO_VERTICE, 5);
    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE, ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE, 1);
}

void inicializar_aristas_verices_superiores(Grafo &grafo_mapa){
}

void inicializar_aristas(Grafo &grafo_mapa){
    inicializar_aristas_vertices_esquinas(grafo_mapa);
    inicializar_aristas_verices_superiores(grafo_mapa);
}

void llenar_grafo(Grafo &grafo_mapa){
    int posiciones_random[MAXIMO_POSICIONES_RANDOM_NECESITADAS];
    inicializar_posiciones_random(posiciones_random);
    inicializar_vertices(grafo_mapa, posiciones_random);
    inicializar_aristas(grafo_mapa);
}

void adoptar_animal(ArbolB<Animal*> &registro_de_animales) {
    Grafo grafo_mapa;
    grafo_mapa.usar_dijkstra();
    llenar_grafo(grafo_mapa);


    //grafo_mapa.obtener_camino_minimo(1, 2);



}