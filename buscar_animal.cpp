#include <iostream>
#include "animal.h"
#include "buscar_animal.h"
#include "ArbolB.h"

using namespace std;
const string SALIR = "CONFIRMAR_SALIDA";

//pre: Debe recibir un nombre y la lista de animales
//post: Exige al usuario que ingrese un nombre de un animal existente
void comprobar_animal_buscado(string &nombre, ArbolB<Animal*> &registro_de_animales, Animal* &animal_buscado){
    while(animal_buscado == nullptr && nombre != SALIR){
        cout << "El animal ingresado no existe en nuestro registro. ";
        cout << "Intente de nuevo o ingrese 'CONFIRMAR_SALIDA' para volver al menu principal: ";
        getline(cin >> std::ws, nombre);
        animal_buscado = registro_de_animales.buscar_animal(nombre);
    }
}

Animal* ingresar_nombre(ArbolB<Animal*> &registro_de_animales){
    string nombre;

    cout << "Introduzca el nombre del animal que desea buscar: ";
    getline(cin >> std::ws, nombre);

    Animal* animal_buscado = registro_de_animales.buscar_animal(nombre);
    comprobar_animal_buscado(nombre, registro_de_animales, animal_buscado);

    if(nombre == SALIR) return nullptr;
    
	return animal_buscado;
}

void proceso_de_busqueda(ArbolB<Animal*> &registro_de_animales){
	Animal* animal_buscado = ingresar_nombre(registro_de_animales);
    cout << endl;
    
    if(animal_buscado == nullptr) return;

    animal_buscado->presentar_animal();
}

//Cuidado con
