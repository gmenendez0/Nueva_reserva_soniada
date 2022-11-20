#include <iostream>
#include "animal.h"
//#include "lista.h"
#include "buscar_animal.h"
#include "ArbolB.h"

/*
using namespace std;
const int MAX_COMBUSTIBLE = 100;

void comprobar_combustible_cargado(int &combustible_cargado, ArbolB<Animal*> &registro_de_animales){
	while (combustible_cargado > max_combustible_a_agregar || combustible_cargado < 0){
		if (combustible_cargado > max_combustible_a_agregar){
			cout << "El combustible ingresado supera la cantidad maxima de combustible que podes cargar.\n";
			cout << "Introduce una cantidad que no supera la cantidad maxima: ";
			cin >> combustible_cargado;
		}
		
		if (combustible_cargado < 0){
			cout << "Error, no podes cargar una cantidad negativa\n";
			cout << "Cuantos combustibles queres cargar?: ";
			cin >> combustible_cargado;
		}
	}
}

int cargar(int combustible_viejo, ArbolB<Animal*> &registro_de_animales){
	int combustible_final, combustible_cargado;
	
	int max_combustible_a_agregar = MAX_COMBUSTIBLE - combustible_viejo;
	
	cout << "Tenes " << combustible_viejo << " por ciento de combustible\n";
	cout << "entonces podes cargar hasta " << max_combustible_a_agregar << " por ciento de combustible\n";
	cout << "Cuantos combustibles queres cargar?: ";
	cin >> combustible_cargado;
	comprobar_combustible_cargado(combustible_cargado, registro_de_animales);
	
	combustible_final = combustible_cargado + combustible_viejo;
	
	return combustible_final
}


/*
//pre: Debe recibir un nombre y la lista de animales
//post: Exige al usuario que ingrese un nombre de un animal existente

void comprobar_animal_buscado(string &nombre, ArbolB<Animal*> &registro_de_animales){
	//Animal *animal_buscado = registro_de_animales.buscar_animal(nombre);
	
    while(registro_de_animales.buscar_animal(nombre) == nullptr && nombre != SALIR){//-----------------------------------------------
        cout << "El animal ingresado no existe en nuestro registro. ";
        cout << "Intente de nuevo o ingrese 'CONFIRMAR_SALIDA' para volver al menu principal: ";
        getline(cin >> std::ws, nombre);
    }
}

//pre: Debe recibir una lista de animales
//post: Devuelve un puntero al animal buscado por el usuario
Animal* ingresar_nombre(ArbolB<Animal*> &registro_de_animales){
    string nombre;

    cout << "Introduzca el nombre del animal que desea buscar: ";  //----------
    getline(cin >> std::ws, nombre); //---------
    cout << endl;//------------

    comprobar_animal_buscado(nombre, registro_de_animales);

    if(nombre == SALIR) 
		return nullptr;
    
	return 0;
}

void proceso_de_busqueda(ArbolB<Animal*> &registro_de_animales){
	Animal* animal_buscado = ingresar_nombre(registro_de_animales);  //--------
    cout << endl;
    
    if(animal_buscado == nullptr) return ;

    animal_buscado->presentar_animal();
}

//Cuidado con*/
