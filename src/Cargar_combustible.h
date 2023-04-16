#ifndef NUEVA_RESERVA_SONIADA_CARGAR_COMBUSTIBLE_H
#define NUEVA_RESERVA_SONIADA_CARGAR_COMBUSTIBLE_H


class Cargar_combustible {
public:
    //Pre
    //Post Pide al usuario una cantidad de combustible a cargar y lo suma a la cantidad de nafta que hay en el auto (sin excederse de la capacidad maxima)
    void cargar_combustible(int &combustible_auto);

private:
    //Pre
    //Post Devuelve true en caso de combustible inválido (fuera de rangos de 1-100), false caso contrario
    bool combustible_invalido(int combustible);

    //Pre
    //Post Chequea si el combustible es inválido, en caso de serlo vuelve a pedir un combustible al usuario
    void comprobar_combustible_a_cargar(int &combustible_a_cargar);

    //Pre
    //Post Pide al usuario una cantidad de combustible a cargar y lo suma a la cantidad de nafta que hay en el auto (sin excederse de la capacidad maxima)
    int pedir_combustible(int combustible_auto);
};


#endif
