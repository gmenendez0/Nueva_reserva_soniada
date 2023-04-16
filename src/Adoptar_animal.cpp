#include "Adoptar_animal.h"
#include "animal.h"
#include "ArbolB.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

const int MINIMO_DE_METROS_REQUERIDOS = 1;
const int CANTIDAD_DE_CARACTERES_A_IGNORAR = 100;
const int NINGUN_ANIMAL = 0;

bool Adoptar_animal::respuesta_invalida(int respuesta){
    return respuesta < MINIMO_DE_METROS_REQUERIDOS;
}

void Adoptar_animal::chequear_espacio_disponible(int &respuesta){
    while(respuesta_invalida(respuesta)){
        cout << "Usted a ingresado un valor invalido. Porfavor, vuelva a intentar:  ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> respuesta;
    }
}

int Adoptar_animal::consultar_espacio_disponible(){
    int respuesta;
    cout << "Porfavor, ingrese el espacio disponible (en m2) en donde vaya a vivir el animal: ";
    cin >> respuesta;

    chequear_espacio_disponible(respuesta);

    return respuesta;
}

void Adoptar_animal::pedir_animal(ArbolB<Animal*> &registro_de_animales, int espacio_disponible){
    string respuesta;
    cout << "Porfavor, ingrese el nombre del animal que desea adoptar o 'cancelar adopcion' para abortar la adopcion: ";
    getline(cin >> std::ws, respuesta);

    if(respuesta == "cancelar adopcion"){
        cout << "La adopcion ha sido cancelada" << endl << endl;
        return;
    }

    int resultado_baja = registro_de_animales.adoptar_animal(respuesta, espacio_disponible);
    if(resultado_baja != COMPLETADA){
        cout << "El animal ingresado no se encuentra en la lista de animales adoptables." << endl;
        pedir_animal(registro_de_animales, espacio_disponible);
    }

    cout << "La adopcion ha sido completada" << endl << endl;
}

void Adoptar_animal::adoptar_animal(ArbolB<Animal*> &registro_de_animales){
    if(registro_de_animales.esta_vacio()){
        cout << "No hay animales para adoptar en la reserva." << endl << endl;
        return;
    }

    int espacio_disponible = consultar_espacio_disponible();
    int cantidad_de_adoptables = registro_de_animales.mostrar_animales_adoptables(espacio_disponible);
    if(cantidad_de_adoptables > NINGUN_ANIMAL) {
        pedir_animal(registro_de_animales, espacio_disponible);
    } else {
        cout << "No hay animales adoptables." << endl << endl;
    }
}