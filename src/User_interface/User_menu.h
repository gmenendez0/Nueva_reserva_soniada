#ifndef NUEVA_RESERVA_SONIADA_USER_MENU_H
#define NUEVA_RESERVA_SONIADA_USER_MENU_H

class User_menu {
private:
    int cantidad_acciones_ejecutadas;

public:
    User_menu();

    //Pre Debe recibir la cantidad de acciones ejecutadas por el usuario
    //Post Imprime por consola el menu de acciones para el usuario
    int mostrar_menu();

    //Pre
    //Post Imprime el mensaje de despedida al usuario
    void imprimir_mensaje_despedida();

private:
    //Pre Debe recibir la cantidad de acciones ejecutadas por el usuario
    //Post Imprime por consola el menu de acciones para el usuario
    int imprimir_menu();

    //Pre Debe recibir una respuesta
    //Post Chequea si la respuesta es válida, en caso de no serla vuelve a pedir una respuesta al usuario
    void chequear_entrada(int &respuesta);

    //Pre Debe recibir una respuesta
    //Post Devuelve true en caso de que la respuesta sea válida (valores 1 - 7 inclusive), false caso contrario
    bool respuesta_es_valida(int respuesta);
};


#endif
