#include "Vertice.h"

Vertice::Vertice(int id, Animal* animal, char color) {
    this->id = id;
    this->animal = animal;
    this->color = color;
}

int Vertice::get_id() {
    return id;
}

Animal* Vertice::get_animal(){
    return animal;
}

char Vertice::get_color(){
    return color;
}

