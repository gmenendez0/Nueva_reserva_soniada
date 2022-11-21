#include "Vertice.h"

Vertice::Vertice(int id, Animal* animal) {
    this->id = id;
    this->animal = animal;
}

int Vertice::get_id() {
    return id;
}

Animal* Vertice::get_animal(){
    return animal;
}

Vertice::~Vertice() {

}
