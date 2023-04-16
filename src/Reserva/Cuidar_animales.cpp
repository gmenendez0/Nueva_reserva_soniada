#include "Cuidar_animales.h"

using std::cout;
using std::cin;
using std::endl;

const int ELEGIR_ANIMAL = 1;
const int ALIMENTAR = 1;
const int VOLVER = 3;
const int REGRESAR_AL_INICIO = 2;
const int CANTIDAD_DE_CARACTERES_A_IGNORAR = 100;
const int BANIAR = 2;

bool Cuidar_animales::respuesta_valida(int respuesta, int limite_minimo, int limite_maximo){
    return (respuesta >= limite_minimo && respuesta <= limite_maximo);
}

void Cuidar_animales::chequear_entrada_secundaria(int &respuesta){
    while(!respuesta_valida(respuesta, ELEGIR_ANIMAL, REGRESAR_AL_INICIO)){
        cout << "Usted a ingresado un valor invalido. Porfavor, vuelva a intentar:  ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> respuesta;
        cout << endl;
    }
}

int Cuidar_animales::mostrar_menu_secundario(){
    int respuesta;

    cout << endl;
    cout << "Usted ha elegido la opcion de cuidar animales. Seleccione que tipo de cuidado desea aplicar:" << endl;
    cout << "1. Elegir animal" << endl;
    cout << "2. Regresar a inicio" << endl;
    cout << "Ingrese una opcion: ";
    cin >> respuesta;
    cout << endl;

    chequear_entrada_secundaria(respuesta);

    return respuesta;
}

Animal* Cuidar_animales::pedir_nombre(Arbol_B<Animal*> &registro_de_animales){
    string nombre;

    cout << "Ingrese el nombre del animal que desea cuidar: ";
    std::getline(cin >> std::ws, nombre);
    cout << endl;

    return registro_de_animales.buscar_animal(nombre);
}

void Cuidar_animales::chequear_accion_terciaria(int &accion_a_realizar){
    while(!respuesta_valida(accion_a_realizar, ALIMENTAR, VOLVER)){
        cout << "Usted a ingresado un valor invalido. Porfavor, vuelva a intentar:  ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> accion_a_realizar;
        cout << endl;
    }
}

int Cuidar_animales::pedir_accion(){
    int accion_a_realizar;

    cout << endl;
    cout << "Que accion desea realizar?" << endl;
    cout << "1. Alimentar" << endl;
    cout << "2. Bañar" << endl;
    cout << "3. Regresar a inicio" << endl;
    cout << "Ingrese una opcion: ";
    cin >> accion_a_realizar;
    cout << endl;

    chequear_accion_terciaria(accion_a_realizar);

    return accion_a_realizar;
}

void Cuidar_animales::realizar_accion_pedida(Animal* animal_elegido, int accion_a_realizar){
    if(accion_a_realizar == ALIMENTAR){
        animal_elegido->comer();
    } else if(accion_a_realizar == BANIAR){
        animal_elegido->ducharse();
    }
}

void Cuidar_animales::elegir_animal(Arbol_B<Animal*> &registro_de_animales){
    registro_de_animales.presentar_cuidables();

    Animal* animal_buscado = pedir_nombre(registro_de_animales);
    while(animal_buscado == nullptr){
        cout << "El nombre ingresado no corresponde a ningun animal registrado. Porfavor, vuelva a intentar." << endl;
        animal_buscado = pedir_nombre(registro_de_animales);
    }

    int accion_a_realizar = pedir_accion();
    realizar_accion_pedida(animal_buscado, accion_a_realizar);
}

void Cuidar_animales::cuidar_animales(Arbol_B<Animal*> &registro_de_animales){
    if(registro_de_animales.esta_vacio()){
        std::cout << "No hay animales registrados para cuidar." << std::endl << std::endl;
        return;
    }

    int respuesta = mostrar_menu_secundario();

    switch(respuesta){
        case ELEGIR_ANIMAL:
            elegir_animal(registro_de_animales);
            break;

        case REGRESAR_AL_INICIO:
            break;
    }
}
