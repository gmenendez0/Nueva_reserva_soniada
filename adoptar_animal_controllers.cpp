#include "adoptar_animal_controllers.h"
#include "Grafo.h"
#include "ArbolB.h"

const int CANTIDAD_DE_VERTICES_NECESITADOS = 64;

/*void llenar_grafo(Grafo &grafo){
    for(int i = 0; i < CANTIDAD_DE_VERTICES_NECESITADOS; ++i){
        grafo.agregar_vertice(i, nullptr);
    }
}*/

void adoptar_animal(ArbolB<Animal*> &registro_de_animales) {
    Grafo grafo;
    grafo.agregar_vertice(1, registro_de_animales.buscar_animal("Narnia"));
    grafo.agregar_vertice(2, registro_de_animales.buscar_animal("Cani"));
    grafo.agregar_camino(1, 2, 9);

    grafo.mostrar_grafo();



}