#include <iostream>
#include "animal.h"
#include "gato.h"
#include "ArbolB.h"

int main(){
    ArbolB<Animal*> arbol;
    //std::cout << "Hello, World!" << std::endl;

    //!-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    Animal* gato = new Gato("1", 35, "chico", 'G', "sociable");
    Animal* gato1 = new Gato("2", 35, "chico", 'G', "sociable");
    Animal* gato2 = new Gato("6", 35, "chico", 'G', "sociable");
    Animal* gato3 = new Gato("7", 35, "chico", 'G', "sociable");
    Animal* gato10 = new Gato("8", 35, "chico", 'G', "sociable");
    Animal* gato11 = new Gato("9", 35, "chico", 'G', "sociable");
    Animal* gato4 = new Gato("3", 35, "chico", 'G', "sociable");

    arbol.insertar(gato);
    arbol.insertar(gato2);
    arbol.insertar(gato3);
    arbol.insertar(gato1);
    arbol.insertar(gato10);
    arbol.insertar(gato11);
    arbol.insertar(gato4);

    arbol.get_raiz()->get_primer_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_dato()->presentar_animal();

    arbol.get_raiz()->get_segundo_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_segundo_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_segundo_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();
    return 0;
}
