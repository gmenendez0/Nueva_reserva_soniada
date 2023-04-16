#include "User_menu.h"

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

void User_menu::activar_opcion_elegida(int opcion_elegida, ArbolB<Animal*> &registro_de_animales, int &combustible_auto){
    switch(opcion_elegida){
        case LISTAR_ANIMALES:
            registro_de_animales.pasar_tiempo(combustible_auto);
            registro_de_animales.presentar_todos();
            break;

        case RESCATAR_ANIMAL:
            registro_de_animales.pasar_tiempo(combustible_auto);
            rescatar_animales_controllers.rescatar_animal(registro_de_animales, combustible_auto);
            break;

        case BUSCAR_ANIMAL:
            registro_de_animales.pasar_tiempo(combustible_auto);
            buscar_animal_controllers.proceso_de_busqueda(registro_de_animales);
            break;

        case CUIDAR_ANIMALES:
            registro_de_animales.pasar_tiempo(combustible_auto);
            cuidar_animales_controllers.cuidar_animales(registro_de_animales);
            break;

        case ADOPTAR_ANIMAL:
            registro_de_animales.pasar_tiempo(combustible_auto);
            adoptar_animal_controllers.adoptar_animal(registro_de_animales);
            break;

        case CARGAR_COMBUSTIBLE:
            cargar_combustible_controllers.cargar_combustible(combustible_auto);
            break;

        case GUARDAR_Y_SALIR:
            registro_de_animales.pasar_tiempo(combustible_auto);
            registro_de_animales.guardar_datos_en_archivo();
            registro_de_animales.eliminar_todos();
            imprimir_mensaje_despedida();
            break;
    }
}
