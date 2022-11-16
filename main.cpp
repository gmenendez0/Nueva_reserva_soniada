#include <iostream>
#include "animal.h"
#include "gato.h"
#include "ArbolB.h"

int main(){
    //std::cout << "Hello, World!" << std::endl;

    Animal* gato = new Gato("perro", 35, "chico", 'G', "sociable");
    Animal* gato1 = new Gato("perro1", 35, "chico", 'G', "sociable");
    Animal* gato2 = new Gato("perro2", 35, "chico", 'G', "sociable");
    Animal* gato3 = new Gato("perro3", 35, "chico", 'G', "sociable");



    ArbolB<Animal*> arbol;
    arbol.insertar(gato);
    arbol.insertar(gato1);
    arbol.insertar(gato2);
    arbol.insertar(gato3);
    //std::cout << arbol.raiz->get_primer_dato()->presentar_animal() << std::endl;
    arbol.get_raiz()->get_segundo_hijo()->get_segundo_dato()->presentar_animal();

    return 0;
}
