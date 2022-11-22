#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H

#include <string>
#include "animal.h"

using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    Animal* animal;
    int id;
    char color;

/*MÉTODOS*/
public:
    Vertice(int id, Animal* animal, char color);

    //post: obtiene el id del vertice
    int get_id();

    //post devuelve el animal que contiene el vertice
    Animal* get_animal();

    //post: devuelve el color del vertice
    char get_color();

    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
