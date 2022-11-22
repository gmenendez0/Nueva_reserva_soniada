#include <iostream>
#include "animal.h"

const int HIGENE_INICIAL = 100;
const int HAMBRE_INICIAL = 0;
const char PERRO = 'P';
const char GATO = 'G';
const char CONEJO = 'O';
const char CABALLO = 'C';
const char ERIZO = 'E';
const char LAGARTIJA = 'L';
const char ROEDOR = 'R';

const int ESPACIO_MINIMO_DIMINUTO = 1;
const int ESPACIO_MINIMO_PEQUENIO = 1;
const int ESPACIO_MINIMO_MEDIANO = 10;
const int ESPACIO_MINIMO_GRANDE = 20;
const int ESPACIO_MINIMO_GIGANTE = 50;


using std::cout;
using std::string;
using std::endl;

Animal::Animal(std::string nombre, int edad, std::string tamanio, char especie, std::string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    this->higene_actual = HIGENE_INICIAL;
    this->hambre_actual = HAMBRE_INICIAL;
    this->eliminado = false;
    this->escapo = false;

    set_espacio_minimo_requerido(tamanio);
}

void Animal::presentar_animal(){
    cout << "Animal: " << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Tamaño: " << this->tamanio << endl;
    cout << "Especie: " << get_especie_completa() << endl;
    cout << "Personalidad: " << this->personalidad << endl;
    cout << "Higiene: " << this->higene_actual << endl;
    cout << "Hambre: " << this->hambre_actual << endl;
    cout << "Adoptado: " << get_mensaje_adopcion() << endl;
    cout << "Escapo: " << get_mensaje_escape() << endl;
    cout << endl;
}

string Animal::get_especie_completa(){
    string especie_completa;

    switch(this->especie){
        case PERRO:
            especie_completa = "Perro";
            break;

        case GATO:
            especie_completa = "Gato";
            break;

        case CONEJO:
            especie_completa = "Conejo";
            break;

        case ROEDOR:
            especie_completa = "Roedor";
            break;

        case ERIZO:
            especie_completa = "Erizo";
            break;

        case LAGARTIJA:
            especie_completa = "Lagartija";
            break;

        case CABALLO:
            especie_completa = "Caballo";
            break;
    }

    return especie_completa;
}

void Animal::ducharse(){
    cout << "La especie de " << nombre << ", " << get_especie_completa() << " no require baño!"<< endl;
}

string Animal::get_nombre(){
    return this->nombre;
}

int Animal::get_edad(){
    return this->edad;
}

string Animal::get_tamanio(){
    return this->tamanio;
}

char Animal::get_especie(){
    return this->especie;
}

string Animal::get_personalidad(){
    return this->personalidad;
}

int Animal::get_espacio_minimo_requerido(){
    return this->espacio_minimo_requerido;
}

void Animal::set_espacio_minimo_requerido(string tamanio){
    if(tamanio == "diminuto"){
        this->espacio_minimo_requerido = ESPACIO_MINIMO_DIMINUTO;
    } else if(tamanio == "pequeño"){
        this->espacio_minimo_requerido = ESPACIO_MINIMO_PEQUENIO;
    } else if( tamanio == "mediano"){
        this->espacio_minimo_requerido = ESPACIO_MINIMO_MEDIANO;
    } else if( tamanio == "grande"){
        this->espacio_minimo_requerido = ESPACIO_MINIMO_GRANDE;
    } else if( tamanio == "gigante"){
        this->espacio_minimo_requerido = ESPACIO_MINIMO_GIGANTE;
    }
}

bool Animal::esta_eliminado(){
    return eliminado;
}

void Animal::eliminar(){
    eliminado = true;
}

bool Animal::se_escapo(){
    return escapo;
}

void Animal::escapar(){
    std::cout << "El animal " << nombre << " se ha escapado! Recorda que los animales requieren cuidado para vivir en la reserva." << std::endl;
    escapo = true;
}

string Animal::get_mensaje_adopcion(){
    if(eliminado) return "Si";

    return "No";
}

string Animal::get_mensaje_escape(){
    if(escapo) return "Si";

    return "No";
}
