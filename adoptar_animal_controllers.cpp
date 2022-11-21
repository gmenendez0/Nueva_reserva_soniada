#include "adoptar_animal_controllers.h"
#include "Grafo.h"
#include "ArbolB.h"

void adoptar_animal(ArbolB<Animal*> &registro_de_animales) {
    Grafo grafo;
    grafo.agregarVertice(1, registro_de_animales.buscar_animal("Narnia"));
    grafo.agregarVertice(2, registro_de_animales.buscar_animal("Cani"));
    grafo.agregarVertice(3, nullptr);

    grafo.agregarCamino(1, 2, 9);
    grafo.agregarCamino(2, 3, 10);

    grafo.mostrarGrafo();

    grafo.usarDijkstra();
    grafo.obtener_camino_minimo(1, 3);

}