#include <iostream>
#include "animal.h"
#include "gato.h"
#include "ArbolB.h"

int main(){
    ArbolB<Animal*> arbol;
    std::cout << "Hello, World!" << std::endl;

    Animal* gato = new Gato("a", 35, "chico", 'G', "sociable");
    Animal* gato1 = new Gato("b", 35, "chico", 'G', "sociable");
    Animal* gato2 = new Gato("f", 35, "chico", 'G', "sociable");
    Animal* gato3 = new Gato("g", 35, "chico", 'G', "sociable");
    Animal* gato10 = new Gato("h", 35, "chico", 'G', "sociable");
    Animal* gato11 = new Gato("i", 35, "chico", 'G', "sociable");
    Animal* gato4 = new Gato("c", 35, "chico", 'G', "sociable");
    Animal* gato5 = new Gato("j", 35, "chico", 'G', "sociable");
    Animal* gato6 = new Gato("k", 35, "chico", 'G', "sociable");
    Animal* gato7 = new Gato("l", 35, "chico", 'G', "sociable");
    Animal* gato8 = new Gato("m", 35, "chico", 'G', "sociable");
    Animal* gato9 = new Gato("n", 35, "chico", 'G', "sociable");
    Animal* gato12 = new Gato("o", 35, "chico", 'G', "sociable");
    Animal* gato13 = new Gato("p", 35, "chico", 'G', "sociable");
    Animal* gato14 = new Gato("q", 35, "chico", 'G', "sociable");
    Animal* gato15 = new Gato("r", 35, "chico", 'G', "sociable");



    arbol.insertar(gato);
    arbol.insertar(gato2);
    arbol.insertar(gato3);
    arbol.insertar(gato1);
    arbol.insertar(gato10);
    arbol.insertar(gato11);
    arbol.insertar(gato4);
    arbol.insertar(gato5);
    arbol.insertar(gato6);
    arbol.insertar(gato7);
    arbol.insertar(gato8);
    arbol.insertar(gato9);
    arbol.insertar(gato12);
    arbol.insertar(gato13);
    arbol.insertar(gato14);
    arbol.insertar(gato15);


    /*arbol.get_raiz()->get_primer_hijo()->get_primer_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_hijo()->get_primer_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_hijo()->get_segundo_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_hijo()->get_segundo_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();

    arbol.get_raiz()->get_segundo_hijo()->get_primer_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_segundo_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_segundo_hijo()->get_primer_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_segundo_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_segundo_hijo()->get_segundo_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_segundo_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_segundo_hijo()->get_segundo_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();

    if(arbol.buscar_animal("f") != nullptr){
        std::cout << arbol.buscar_animal("f")->get_nombre();
    }

    if(arbol.eliminar_animal("f") == 0){
        std::cout << "hola";
    }*/

    arbol.presentar_todos();

    return 0;
}
