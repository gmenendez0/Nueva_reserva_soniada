#include "Cargar_combustible.h"
#include "iostream"

const int MAXIMO_COMBUSTIBLE = 100;
const int CARACTERES_A_IGNORAR = 100;
const int MINIMO_COMBUSTIBLE_CARGABLE = 1;

bool Cargar_combustible::combustible_invalido(int combustible){
    return (combustible < MINIMO_COMBUSTIBLE_CARGABLE || combustible > MAXIMO_COMBUSTIBLE);
}

void Cargar_combustible::comprobar_combustible_a_cargar(int &combustible_a_cargar){
    while(combustible_invalido(combustible_a_cargar)){
        std::cout << "Usted a ingresado un valor invalido, solo es posible cargar entre 1% y 100% de combustible. Porfavor, vuelva a intentar:  ";
        std::cin.clear();
        std::cin.ignore(CARACTERES_A_IGNORAR, '\n');
        std::cin >> combustible_a_cargar;
    }
}

int Cargar_combustible::pedir_combustible(int combustible_auto){
    int combustible_a_cargar;
    std::cout << "Combustible en su camioneta: " << combustible_auto << "%" << std::endl;
    std::cout << "Ingrese el porcentaje de combustible que desea cargar teniendo en cuenta que la camioneta solo puede llegar a 100% de combustible como maximo: ";
    std::cin >> combustible_a_cargar;

    comprobar_combustible_a_cargar(combustible_a_cargar);

    return combustible_a_cargar;
}

void Cargar_combustible::cargar_combustible(int &combustible_auto){
    combustible_auto += pedir_combustible(combustible_auto);
    if(combustible_auto > MAXIMO_COMBUSTIBLE) combustible_auto = MAXIMO_COMBUSTIBLE;
    std::cout << "Se ha cargado el combustible. Ahora su combustible esta al " << combustible_auto << "%." << std::endl;
}
