#include "menu_controllers.h"

using std::cout;
using std::cin;
using std::endl;

const int CANTIDAD_DE_CARACTERES_A_IGNORAR = 100;
const int LISTAR_ANIMALES = 1;
const int RESCATAR_ANIMAL = 2;
const int BUSCAR_ANIMAL = 3;
const int CUIDAR_ANIMALES = 4;
const int ADOPTAR_ANIMAL = 5;
const int CARGAR_COMBUSTIBLE = 6;
const int GUARDAR_Y_SALIR = 7;
const int UNA_ACCION = 1;

//Pre Debe recibir una respuesta
//Post Devuelve true en caso de que la respuesta sea válida (valores 1 - 7 inclusive), false caso contrario
bool respuesta_es_valida(int respuesta){
    return (respuesta >= LISTAR_ANIMALES && respuesta <= GUARDAR_Y_SALIR);
}

//Pre Debe recibir una respuesta
//Post Chequea si la respuesta es válida, en caso de no serla vuelve a pedir una respuesta al usuario
void chequear_entrada(int &respuesta){
    while(!respuesta_es_valida(respuesta)){
        cout << "Usted a ingresado un valor invalido. Porfavor, vuelva a intentar:  ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> respuesta;
        cout << endl;
    }
}

//Pre Debe recibir la cantidad de acciones ejecutadas por el usuario
//Post Imprime por consola el menu de acciones para el usuario
int imprimir_menu(int cantidad_acciones){
    int respuesta;

    if(cantidad_acciones == UNA_ACCION){
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

//Pone en marcha el menu de acciones para el usuario
int mostrar_menu(int &cantidad_acciones){
    int respuesta = imprimir_menu(cantidad_acciones);
    cantidad_acciones++;

    return respuesta;
}

//Pre
//Post Imprime el mensaje de despedida al usuario
void imprimir_mensaje_despedida(){
    cout << "Guardando y saliendo..." << endl;
}

void activar_opcion_elegida(int opcion_elegida, ArbolB<Animal*> &registro_de_animales){
    switch(opcion_elegida){
        case LISTAR_ANIMALES:
            //pasar_el_tiempo(registro_de_animales);
            registro_de_animales.presentar_todos();
            break;

        case RESCATAR_ANIMAL:
            //pasar_el_tiempo(registro_de_animales);
            //rescatar_animal(registro_de_animales);
            break;

        case BUSCAR_ANIMAL:
            //pasar_el_tiempo(registro_de_animales);
            //proceso_de_busqueda(registro_de_animales);
            break;

        case CUIDAR_ANIMALES:
            //pasar_el_tiempo(registro_de_animales);
            //cuidar_animales(registro_de_animales);
            break;

        case ADOPTAR_ANIMAL:
            //pasar_el_tiempo(registro_de_animales);
            //adoptar_animal(registro_de_animales);
            break;

        case CARGAR_COMBUSTIBLE:
            break;

        case GUARDAR_Y_SALIR:
            //pasar_el_tiempo(registro_de_animales);
            //guardar_cambios(registro_de_animales);
            imprimir_mensaje_despedida();
            break;
    }
}
