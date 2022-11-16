#include <iostream>
#include "animal.h"
#include "gato.h"
#include "ArbolB.h"

int main(){
    ArbolB<Animal*> arbol;
    //std::cout << "Hello, World!" << std::endl;

    //!-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    Animal* gato = new Gato("1", 35, "chico", 'G', "sociable"); //se prueba el caso de arbol vacio
    Animal* gato1 = new Gato("2", 35, "chico", 'G', "sociable"); //se prueba el caso de insercion a nodo hoja no lleno
    Animal* gato2 = new Gato("3", 35, "chico", 'G', "sociable"); //se prueba el caso de split de nodo raiz
    //Animal* gato3 = new Gato("4", 35, "chico", 'G', "sociable"); //se prueba el caso de insercion a nodo hijo derecho cuando este solo tiene una primera clave y se ingresa una clave mayor
    arbol.insertar(gato2);
    arbol.insertar(gato);
    arbol.insertar(gato1);
    //arbol.insertar(gato3);
    arbol.get_raiz()->get_primer_hijo()->get_primer_dato()->presentar_animal(); //1
    arbol.get_raiz()->get_primer_dato()->presentar_animal();                    //2
/*    arbol.get_raiz()->get_segundo_dato()->presentar_animal();                    //2*/
    arbol.get_raiz()->get_segundo_hijo()->get_primer_dato()->presentar_animal(); //3
/*
    arbol.get_raiz()->get_segundo_hijo()->get_segundo_dato()->presentar_animal(); //4
*/

    return 0;
}
