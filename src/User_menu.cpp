#include "User_menu.h"

using std::cout;
using std::cin;
using std::endl;

const int CANTIDAD_DE_CARACTERES_A_IGNORAR = 100;
const int LISTAR_ANIMALES = 1;
const int GUARDAR_Y_SALIR = 7;

User_menu::User_menu() {
    cantidad_acciones_ejecutadas = 0;
}

bool User_menu::respuesta_es_valida(int respuesta){
    return (respuesta >= LISTAR_ANIMALES && respuesta <= GUARDAR_Y_SALIR);
}

void User_menu::chequear_entrada(int &respuesta){
    while(!respuesta_es_valida(respuesta)){
        cout << "Usted a ingresado un valor invalido. Porfavor, vuelva a intentar:  ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> respuesta;
        cout << endl;
    }
}

int User_menu::imprimir_menu(){
    int respuesta;

    if(cantidad_acciones_ejecutadas == 0){
        cout << "Bienvenido al sistema de rescate de animales." << endl << "¿Qué desea realizar?" << endl << endl;
    } else {
        cout << "¿Algo más?" << endl << endl;
    }

    cout << "1. Listar animales" << endl;
    cout << "2. Rescatar animal" << endl;
    cout << "3. Buscar animal" << endl;
    cout << "4. Cuidar animales" << endl;
    cout << "5. Adoptar animal" << endl;
    cout << "6. Cargar combustible" << endl;
    cout << "7. Guardar y salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> respuesta;
    cout << endl;

    chequear_entrada(respuesta);

    return respuesta;
}

int User_menu::mostrar_menu(){
    int respuesta = imprimir_menu();
    cantidad_acciones_ejecutadas++;

    return respuesta;
}

void User_menu::imprimir_mensaje_despedida(){
    cout << "Guardando y saliendo..." << endl;
}

