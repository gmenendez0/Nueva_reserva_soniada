#include <iostream>
#include "animal.h"
#include "gato.h"
#include "ArbolB.h"

int main(){
    //std::cout << "Hello, World!" << std::endl;

    Animal* gato = new Gato("perro", 35, "chico", 'G', "sociable");
    Animal* gato1 = new Gato("perro", 35, "chico", 'G', "sociable");

    ArbolB<Animal*> arbol;
    arbol.insertar(gato);
    arbol.insertar(gato1);

    return 0;
}
