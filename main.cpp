#include <iostream>
#include "animal.h"
#include "gato.h"
#include "ArbolB.h"

int main(){
    ArbolB<Animal*> arbol;
    std::cout << "Hello, World!" << std::endl;

    //!-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    /*Animal* gato = new Gato("1", 35, "chico", 'G', "sociable");
    Animal* gato1 = new Gato("1", 35, "chico", 'G', "sociable");
    Animal* gato2 = new Gato("6", 35, "chico", 'G', "sociable");
    Animal* gato3 = new Gato("7", 35, "chico", 'G', "sociable");
    Animal* gato10 = new Gato("8", 35, "chico", 'G', "sociable");
    Animal* gato11 = new Gato("9", 35, "chico", 'G', "sociable");
    Animal* gato4 = new Gato("3", 35, "chico", 'G', "sociable");

    arbol.insertar(gato);
    int resultado = arbol.insertar(gato2);
    arbol.insertar(gato3);
    arbol.insertar(gato4);
    arbol.get_raiz()->get_primer_hijo()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_hijo()->get_segundo_dato()->presentar_animal();
    arbol.get_raiz()->get_primer_dato()->presentar_animal();
    arbol.get_raiz()->get_segundo_hijo()->get_primer_dato()->presentar_animal();
    //arbol.get_raiz()->get_segundo_hijo()->get_segundo_dato()->presentar_animal();
    std::cout << resultado;

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
    arbol.get_raiz()->get_segundo_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();*/

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
    arbol.insertar(gato8);  //splitea el nodo hoja de la derecha del todo

    std::cout << arbol.get_raiz()->get_tope_datos();

    arbol.get_raiz()->get_primer_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal(); //a bien
    arbol.get_raiz()->get_primer_hijo()->get_primer_dato()->presentar_animal(); //b bien
    arbol.get_raiz()->get_primer_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal(); //c bien

    arbol.get_raiz()->get_primer_dato()->presentar_animal(); //f bien

    arbol.get_raiz()->get_segundo_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();     //g bien
    arbol.get_raiz()->get_segundo_hijo()->get_primer_dato()->presentar_animal();    //funciona mal  h
    arbol.get_raiz()->get_segundo_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal();    //i bien

    arbol.get_raiz()->get_segundo_dato()->presentar_animal();                   //j MAL

    arbol.get_raiz()->get_tercer_hijo()->get_primer_hijo()->get_primer_dato()->presentar_animal();    //k mal
    arbol.get_raiz()->get_tercer_hijo()->get_primer_dato()->presentar_animal();     //l mal
    arbol.get_raiz()->get_tercer_hijo()->get_segundo_hijo()->get_primer_dato()->presentar_animal(); //m mal





    return 0;
}
