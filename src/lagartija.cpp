#include "lagartija.h"
#include <iostream>

const int AUMENTO_HAMBRE_BASE = 10;
const int HAMBRIENTO = 100;
const int BONUS_DORMILON = 2;
const int PENALIZACION_JUGUETON = 2;
const int SATISFECHO = 0;

Lagartija::Lagartija(std::string nombre, int edad, std::string tamanio, char especie, std::string personalidad) : Animal(nombre, edad, tamanio, especie, personalidad){
    this->tipo_de_comida = "insectos";
}

void Lagartija::comer(){
    if(hambre_actual != SATISFECHO){
        hambre_actual = SATISFECHO;
        std::cout << this->nombre << " comio " << this->tipo_de_comida << "." << std::endl;
    } else {
        std::cout << this->nombre << " no tiene hambre." << std::endl;
    }
}

void Lagartija::pasar_el_tiempo(int* animales_escapados){
    aumentar_hambre();
    if(hambre_actual == HAMBRIENTO) {
        (*animales_escapados)++;
        escapar();
    }
}

void Lagartija::aumentar_hambre(){
    if(this->personalidad == "dormilon" && !esta_hambriento()){
        hambre_actual = hambre_actual + (AUMENTO_HAMBRE_BASE / BONUS_DORMILON);
    } else if(this->personalidad == "jugueton" && !esta_hambriento()) {
        hambre_actual = hambre_actual + (AUMENTO_HAMBRE_BASE * PENALIZACION_JUGUETON);
    } else if (!esta_hambriento()) {
        hambre_actual = hambre_actual + AUMENTO_HAMBRE_BASE;
    }
}

bool Lagartija::esta_hambriento(){
    return (hambre_actual == HAMBRIENTO);
}
