#include "Caballo.h"
#include <iostream>

const int SUCIO = 0;
const int AUMENTO_HAMBRE_BASE = 10;
const int PERDIDA_HIGENE_BASE = 10;
const int HIGENE_COMPLETA = 100;
const int HAMBRIENTO = 100;
const int BONUS_DORMILON = 2;
const int PENALIZACION_JUGUETON = 2;
const int BONUS_SOCIABLE = 2;
const int PENALIZACION_TRAVIESO = 2;
const int SATISFECHO = 0;

Caballo::Caballo(std::string nombre, int edad, std::string tamanio, char especie, std::string personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    this->tipo_de_comida = "manzanas";
}

void Caballo::ducharse(){
    if (higene_actual != HIGENE_COMPLETA){
        higene_actual = HIGENE_COMPLETA;
        std::cout << this->nombre << " se baño." << std::endl;
    } else {
        std::cout << this->nombre << " no necesita bañarse." << std::endl;
    }
}

void Caballo::comer(){
    if(hambre_actual != SATISFECHO){
        hambre_actual = SATISFECHO;
        std::cout << this->nombre << " comio " << this->tipo_de_comida << "." << std::endl;
    } else {
        std::cout << this->nombre << " no tiene hambre." << std::endl;
    }
}

void Caballo::pasar_el_tiempo(int* animales_escapados){
    ensuciarse();
    aumentar_hambre();
    if(hambre_actual == HAMBRIENTO || higene_actual == SUCIO){
        escapar();
        (*animales_escapados)++;
    }
}

void Caballo::ensuciarse(){
    if(this->personalidad == "sociable" && !esta_sucio()){
        higene_actual = higene_actual - (PERDIDA_HIGENE_BASE / BONUS_SOCIABLE);
    } else if(this->personalidad == "travieso" && !esta_sucio()) {
        higene_actual = higene_actual - (PERDIDA_HIGENE_BASE * PENALIZACION_TRAVIESO);
    } else if (!esta_sucio()) {
        higene_actual = higene_actual - PERDIDA_HIGENE_BASE;
    }
}

void Caballo::aumentar_hambre(){
    if(this->personalidad == "dormilon" && !esta_hambriento()){
        hambre_actual = hambre_actual + (AUMENTO_HAMBRE_BASE / BONUS_DORMILON);
    } else if(this->personalidad == "jugueton" && !esta_hambriento()) {
        hambre_actual = hambre_actual + (AUMENTO_HAMBRE_BASE * PENALIZACION_JUGUETON);
    } else if (!esta_hambriento()) {
        hambre_actual = hambre_actual + AUMENTO_HAMBRE_BASE;
    }
}

bool Caballo::esta_hambriento(){
    return (hambre_actual == HAMBRIENTO);
}

bool Caballo::esta_sucio(){
    return (higene_actual == SUCIO);
}
