#include "archivo_controllers.h"
#include <iostream>
#include "animal.h"
#include "gato.h"
#include "conejo.h"
#include "caballo.h"
#include "lagartija.h"
#include "perro.h"
#include "roedor.h"
#include "erizo.h"
#include "ArbolB.h"

const int PRIMERA_POSICION_VECTOR = 0;

using std::cout;
using std::string;
using std::endl;

//Pre: Debe recibir todas las caracteristicas de un animal y la lista de animales
//Post: Da de alta un animal en el arbol con los datos recibidos.
template <typename Tipo_de_animal>
void crear_animal(string nombre, int edad, string tamanio, char especie, string personalidad, ArbolB<Animal*> &registro_de_animales){
    Animal* nuevo_animal = new Tipo_de_animal(nombre, edad, tamanio, especie, personalidad);
    registro_de_animales.insertar(nuevo_animal);
}

void revisar_especie(string nombre, int edad, string tamanio, char especie, string personalidad, ArbolB<Animal*> &registro_de_animales){

    if(especie == 'G'){
        crear_animal<Gato>(nombre, edad, tamanio, especie, personalidad, registro_de_animales);
    } else if(especie == 'O'){
        crear_animal<Conejo>(nombre, edad, tamanio, especie, personalidad, registro_de_animales);
    } else if(especie == 'C'){
        crear_animal<Caballo>(nombre, edad, tamanio, especie, personalidad, registro_de_animales);
    } else if(especie == 'P'){
        crear_animal<Perro>(nombre, edad, tamanio, especie, personalidad, registro_de_animales);
    } else if(especie == 'L'){
        crear_animal<Lagartija>(nombre, edad, tamanio, especie, personalidad, registro_de_animales);
    } else if(especie == 'R'){
        crear_animal<Roedor>(nombre, edad, tamanio, especie, personalidad, registro_de_animales);
    } else {
        crear_animal<Erizo>(nombre, edad, tamanio, especie, personalidad, registro_de_animales);
    }
}

//Pre: Debe recibir un archivo csv con los datos de los animales y una arbol vacio de animales
//Post: Devuelve el arbol inicializado con los datos leidos del archivo
void inicializar_registro(std::ifstream &archivo_animales, ArbolB<Animal*> &registro_de_animales){
    string especie;
    string edad;
    string nombre;
    string personalidad;
    string tamanio;

    while(getline(archivo_animales, nombre, ',')){
        getline(archivo_animales, edad, ',');
        getline(archivo_animales, tamanio, ',');
        getline(archivo_animales, especie, ',');
        getline(archivo_animales, personalidad, '\n');

        revisar_especie(nombre, std::stoi(edad), tamanio, especie[PRIMERA_POSICION_VECTOR], personalidad, registro_de_animales);
    }
}

int abrir_archivo(ArbolB<Animal*> &registro_de_animales){
    std::ifstream archivo_animales(NOMBRE_CSV);
    if(!archivo_animales.is_open()){
        cout<<"Error al abrir el archivo. Compruebe que exista y que no este corrompido y vuelva a intentar."<<endl;
        return ERROR;
    }

    inicializar_registro(archivo_animales, registro_de_animales);
    archivo_animales.close();

    return EXITO;
}



