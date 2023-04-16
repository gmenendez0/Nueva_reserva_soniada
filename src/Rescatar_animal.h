#ifndef NUEVA_RESERVA_SONIADA_RESCATAR_ANIMAL_H
#define NUEVA_RESERVA_SONIADA_RESCATAR_ANIMAL_H


#include "animal.h"
#include "ArbolB.h"
#include "Grafo.h"

class Rescatar_animal {
public:
    //Post Pone en marcha las funciones correspondientes para poder efectuar el rescate de un animal. Combustible auto debe estar inicializado.
    void rescatar_animal(ArbolB<Animal*> &registro_de_animales, int &combustible_auto);

private:
    //Post Libera la memoria de los animales no rescatados
    void liberar_animales_no_rescatados(Animal* animales_a_rescatar[], string nombre_animal_rescatado);

    //Pre
    //Post Libera la memoria de todos los animales creados para ser rescatados
    void liberar_animales_creados(Animal* animales_a_rescatar[]);

    //Pre
    //Post Realiza el rescate del animal, insertandolo en el arbol con un nombre adecuado
    string realizar_rescate(int combustible_necesitado, Animal* animal_a_rescatar, ArbolB<Animal*> &registro_de_animales, int &combustible_auto);

    //Pre
    //Post Vuelve a pedir un nombre apropiado en caso de que el nombre ingresado no sea valido.
    void repedir_nombre(Animal* animal_a_rescatar);

    //Pre
    //Post Pide un nombre para el nuevo animal
    void pedir_nombre(Animal* animal_a_rescatar);

    //Pre
    //Post Genera animales para ser rescatados
    void generar_animales_random(Animal* animales_a_rescatar[]);

    //Pre
    //Post Devuelve true en caso de que haya habido un error a la hora de moverse a donde el usuario quiso
    bool hubo_un_error(int resultado_inspeccion, Animal* animal_a_rescatar);

    //Pre
    //Post Despliega el menu de opciones de error para el usuario y redirige al lugar correspondiente
    void desplegar_menu_error(ArbolB <Animal*> &registro_de_animales, int &combustible_auto);

    //Pre
    //Post Chequea la respuesta del usuario del menu de error. En caso de ser invalida la vuelve a pedir
    void chequear_respuesta_menu_error(int &respuesta);

    //Pre
    //Post Devuelve true en caso de respuesta válida (0 O 1), false caso contrario
    bool respuesta_valida_menu_error(int respuesta);

    //Pre
    //Post Devuelve -1 en caso de combustible insuficiente. Si el combustible es suficiente, devuelve la cantidad de combustible que se gastara.
    int revisar_combustible(int coordenada_x, int coordenada_y, int combustible_auto, Grafo &grafo_mapa);

    //Pre
    //Post Devuelve nullptr en caso de que no haya ningun animal en la coordenada seleccionada, caso contrario devuelve un puntero al animal
    Animal* revisar_coordenadas(Grafo &grafo_mapa, int coordenada_x, int coordenada_y);

    //Pre
    //Post Pide al usuario que ingrese un par de coordendas
    void pedir_coordenadas(int &coordenada_usuario_x, int &coordenada_usuario_y);

    //Pre
    //Post Chequea la validez de las coordenadas ingresadas, en caso de no serlas las repide
    void revisar_respuesta(int &respuesta);

    //Pre
    //Post Devuelve true si el usuario ingreso una opcion invalida (fuera del rango 1-8), false en caso contrario.
    bool respuesta_fuera_de_rango(int respuesta);

    //Pre
    //Post Presenta al usuario el funcionamiento del rescate de animales.
    void presentar();

    //Pre
    //Post Imprime el grafo por pantalla
    void imprimir_grafo(Grafo &grafo_mapa);

    //Pre
    //Post Realiza la impresion adecuada del contenido del vertice
    void realizar_impresion(Grafo &grafo_mapa, int &iterador_vertices);

    //Pre: El grafo debe tener forma CUADRADA.
    //Post: Llena el grafo con todos sus vertices y aristas.
    void llenar_grafo(Grafo &grafo_mapa, Animal* animales_a_rescatar[]);

    //Pre
    //Post Abre el archivo de vertices y si no se puede, exitea el programa de manera controlada
    void abrir_archivo_vertices(Grafo &grafo_mapa, Animal* animales_a_rescatar[]);

    //Pre
    //Post Inicializa todos los vertices del grafo.
    void inicializar_vertices(std::ifstream &archivo_vertices, Grafo &grafo_mapa, Animal* animales_a_rescatar[]);

    //Pre
    //Post Inicializa el vector de coordenadas random
    void inicializar_posiciones_random(int posiciones_random[]);

    //Pre
    //Post Devuelve true en caso de que el id de vertice coincida con una de las posiciones random
    bool coincide_con_posicion_random(int id_vertice, int posiciones_random[]);

    //Pre
    //Post Inicializa todas las aristas
    void inicializar_aristas(Grafo &grafo_mapa);

    //Pre
    //Post Inicializa las aristas de los vertices centrales
    void inicializar_aristas_vertices_centrales(Grafo &grafo_mapa);

    //Pre
    //Post Inicializa las aristas de la columna izquierda del to.do
    void inicializar_aristas_vertices_izquierdos(Grafo &grafo_mapa);

    //Pre
    //Post Inicializa las aristas de la columna derecha del to.do
    void inicializar_aristas_vertices_derechos(Grafo &grafo_mapa);

    //Pre
    //Post Inicializa las aristas de la fila del fondo
    void inicializar_aristas_vertices_inferiores(Grafo &grafo_mapa);

    //Pre
    //Post Inicializa las aristas de la fila de la cima
    void inicializar_aristas_vertices_superiores(Grafo &grafo_mapa);

    //Pre
    //Post Devuelve el peso de la arista que conectaria al vertice del id recibido.
    int determinar_peso(Grafo &grafo_mapa, int id_vertice);

    //Pre
    //Post Inicializa las aristas de las 4 esquinas
    void inicializar_aristas_vertices_esquinas(Grafo &grafo_mapa);
};

#endif
