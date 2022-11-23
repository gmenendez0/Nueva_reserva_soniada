#include "adoptar_animal_controllers.h"
#include "Grafo.h"
#include "ArbolB.h"

const int CANTIDAD_DE_VERTICES_NECESITADOS = 64;
const int MAXIMO_POSICIONES_RANDOM_NECESITADAS = 5;
const int TERCERA_POSICION = 2;
const int CUARTA_POSICION = 3;
const int QUINTA_POSICION = 4;
const int ID_PRIMER_VERTICE = 1;
const int ID_VERTICE_DERECHO_PRIMER_VERTICE = 2;
const int ID_ULTIMO_VERTICE_PRIMER_FILA = 8;
const int ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE_PRIMER_FILA = 7;
const int ID_VERTICE_INFERIOR_PRIMER_VERTICE = 9;
const int ID_VERTICE_INFERIOR_ULTIMO_VERTICE_PRIMER_FILA = 16;
const int ID_ULTIMO_VERTICE = 64;
const int ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE = 63;
const int ID_VERTICE_SUPERIOR_ULTIMO_VERTICE = 56;
const int ID_PRIMER_VERTICE_ULTIMA_FILA = 57;
const int ID_VERTICE_DERECHO_PRIMER_VERTICE_ULTIMA_FILA = 58;
const int ID_VERTICE_SUPERIOR_PRIMER_VERTICE_ULTIMA_FILA = 49;
const string ARCHIVO_VERTICES = "vertices.csv";
const int ANCHO_DEL_MAPA = 8;
const int ID_SEGUNDO_VERTICE = 2;
const int ID_ANTEULTIMO_VERTICE_PRIMERA_FILA = 7;
const int ID_VERTICE_INFERIOR_AL_PRIMER_VERTICE = 9;
const int ID_VERTICE_SUPERIOR_AL_PRIMER_VERTICE_ULTIMA_FILA = 49;
const int ID_VERTICE_SUPERIOR_AL_ULTIMO_VERTICE = 56;
const int ALTO_DEL_MAPA = 8;
const int CANTIDAD_DE_CARACTERES_A_IGNORAR = 100;
const int COORDENADA_MINIMA_PERMITIDA = 1;
const int COORDENADA_MAXIMA_PERMITIDA = 8;

const int PRIMERA_Y_ULTIMA_COLUMNA = 2;
const int PESO_A_VERTICE_NEGRO = 40;
const int PESO_A_VERTICE_GRIS = 1;
const int PESO_A_VERTICE_MARRON_OSCURO = 5;
const int PESO_A_VERTICE_MARRON_CLARO = 2;
const int DOS_POSICIONES = 2;
const int PRIMERA_POSICION_EN_DIAGONAL_AL_PRIMER_VERTICE = 10;
const int TRES_POSICIONES = 3;

void inicializar_aristas_vertices_esquinas(Grafo &grafo_mapa){
    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE, ID_VERTICE_DERECHO_PRIMER_VERTICE, PESO_A_VERTICE_NEGRO);
    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE, ID_VERTICE_INFERIOR_PRIMER_VERTICE, PESO_A_VERTICE_GRIS);

    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE_PRIMER_FILA, ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE_PRIMER_FILA, PESO_A_VERTICE_MARRON_CLARO);
    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE_PRIMER_FILA, ID_VERTICE_INFERIOR_ULTIMO_VERTICE_PRIMER_FILA, PESO_A_VERTICE_NEGRO);

    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE_ULTIMA_FILA, ID_VERTICE_SUPERIOR_PRIMER_VERTICE_ULTIMA_FILA, PESO_A_VERTICE_MARRON_CLARO);
    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE_ULTIMA_FILA, ID_VERTICE_DERECHO_PRIMER_VERTICE_ULTIMA_FILA, PESO_A_VERTICE_MARRON_CLARO);

    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE, ID_VERTICE_SUPERIOR_ULTIMO_VERTICE, PESO_A_VERTICE_MARRON_OSCURO);
    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE, ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE, PESO_A_VERTICE_GRIS);
}

int determinar_peso(Grafo &grafo_mapa, int id_vertice){
    int peso;

    if(grafo_mapa.devolver_color_vertice(id_vertice) ==  'N'){
        peso = PESO_A_VERTICE_NEGRO;
    } else if(grafo_mapa.devolver_color_vertice(id_vertice) ==  'M'){
        peso = PESO_A_VERTICE_MARRON_OSCURO;
    } else if(grafo_mapa.devolver_color_vertice(id_vertice) ==  'C'){
        peso = PESO_A_VERTICE_MARRON_CLARO;
    } else {
        peso = PESO_A_VERTICE_GRIS;
    }

    return peso;
}

void inicializar_aristas_vertices_superiores(Grafo &grafo_mapa){
    int peso_camino_derecho;
    int peso_camino_izquierdo;
    int peso_camino_inferior;

    for(int i = ID_SEGUNDO_VERTICE; i <= ID_ANTEULTIMO_VERTICE_PRIMERA_FILA; ++i){
        peso_camino_derecho = determinar_peso(grafo_mapa, i + UNA_POSICION);
        peso_camino_izquierdo = determinar_peso(grafo_mapa, i - UNA_POSICION);
        peso_camino_inferior = determinar_peso(grafo_mapa, i + ANCHO_DEL_MAPA);

        grafo_mapa.agregar_camino(i, i + UNA_POSICION, peso_camino_derecho);
        grafo_mapa.agregar_camino(i, i - UNA_POSICION, peso_camino_izquierdo);
        grafo_mapa.agregar_camino(i, i + ANCHO_DEL_MAPA, peso_camino_inferior);
    }
}

void inicializar_aristas_vertices_inferiores(Grafo &grafo_mapa){
    int peso_camino_derecho;
    int peso_camino_izquierdo;
    int peso_camino_superior;

    for(int i = ID_VERTICE_DERECHO_PRIMER_VERTICE_ULTIMA_FILA; i <= ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE; ++i){
        peso_camino_derecho = determinar_peso(grafo_mapa, i + UNA_POSICION);
        peso_camino_izquierdo = determinar_peso(grafo_mapa, i - UNA_POSICION);
        peso_camino_superior = determinar_peso(grafo_mapa, i - ANCHO_DEL_MAPA);

        grafo_mapa.agregar_camino(i, i + UNA_POSICION, peso_camino_derecho);
        grafo_mapa.agregar_camino(i, i - UNA_POSICION, peso_camino_izquierdo);
        grafo_mapa.agregar_camino(i, i - ANCHO_DEL_MAPA, peso_camino_superior);
    }
}

void inicializar_aristas_vertices_derechos(Grafo &grafo_mapa){
    int peso_camino_superior;
    int peso_camino_inferior;
    int peso_camino_izquierdo;

    for(int i = ID_VERTICE_INFERIOR_ULTIMO_VERTICE_PRIMER_FILA; i <= ID_VERTICE_SUPERIOR_AL_ULTIMO_VERTICE; i = i+ANCHO_DEL_MAPA){
        peso_camino_superior = determinar_peso(grafo_mapa, i - ANCHO_DEL_MAPA);
        peso_camino_inferior = determinar_peso(grafo_mapa, i + ANCHO_DEL_MAPA);
        peso_camino_izquierdo = determinar_peso(grafo_mapa, i - UNA_POSICION);

        grafo_mapa.agregar_camino(i, i - ANCHO_DEL_MAPA, peso_camino_superior);
        grafo_mapa.agregar_camino(i, i + ANCHO_DEL_MAPA, peso_camino_inferior);
        grafo_mapa.agregar_camino(i, i - UNA_POSICION, peso_camino_izquierdo);
    }
}

void inicializar_aristas_vertices_izquierdos(Grafo &grafo_mapa){
    int peso_camino_superior;
    int peso_camino_inferior;
    int peso_camino_derecho;

    for(int i = ID_VERTICE_INFERIOR_AL_PRIMER_VERTICE; i <= ID_VERTICE_SUPERIOR_AL_PRIMER_VERTICE_ULTIMA_FILA; i = i+ANCHO_DEL_MAPA){
        peso_camino_superior = determinar_peso(grafo_mapa, i - ANCHO_DEL_MAPA);
        peso_camino_inferior = determinar_peso(grafo_mapa, i + ANCHO_DEL_MAPA);
        peso_camino_derecho = determinar_peso(grafo_mapa, i + UNA_POSICION);

        grafo_mapa.agregar_camino(i, i - ANCHO_DEL_MAPA, peso_camino_superior);
        grafo_mapa.agregar_camino(i, i + ANCHO_DEL_MAPA, peso_camino_inferior);
        grafo_mapa.agregar_camino(i, i + UNA_POSICION, peso_camino_derecho);
    }
}

void inicializar_aristas_vertices_centrales(Grafo &grafo_mapa){
    int peso_camino_superior;
    int peso_camino_inferior;
    int peso_camino_derecho;
    int peso_camino_izquierdo;
    int iterador = PRIMERA_POSICION_EN_DIAGONAL_AL_PRIMER_VERTICE;

    for(int j = 0; j < (ANCHO_DEL_MAPA - PRIMERA_Y_ULTIMA_COLUMNA); ++j){
        for(int i = 0; i <= (ANCHO_DEL_MAPA - TRES_POSICIONES); i++){
            peso_camino_superior = determinar_peso(grafo_mapa, iterador - ANCHO_DEL_MAPA);
            peso_camino_inferior = determinar_peso(grafo_mapa, iterador + ANCHO_DEL_MAPA);
            peso_camino_derecho = determinar_peso(grafo_mapa, iterador + UNA_POSICION);
            peso_camino_izquierdo = determinar_peso(grafo_mapa, iterador - UNA_POSICION);


            grafo_mapa.agregar_camino(iterador, iterador - ANCHO_DEL_MAPA, peso_camino_superior);
            grafo_mapa.agregar_camino(iterador, iterador + ANCHO_DEL_MAPA, peso_camino_inferior);
            grafo_mapa.agregar_camino(iterador, iterador - UNA_POSICION, peso_camino_izquierdo);
            grafo_mapa.agregar_camino(iterador, iterador + UNA_POSICION, peso_camino_derecho);
            iterador++;
        }
        iterador = iterador + DOS_POSICIONES;
    }
}


void inicializar_aristas(Grafo &grafo_mapa){
    inicializar_aristas_vertices_esquinas(grafo_mapa);
    inicializar_aristas_vertices_superiores(grafo_mapa);
    inicializar_aristas_vertices_inferiores(grafo_mapa);
    inicializar_aristas_vertices_derechos(grafo_mapa);
    inicializar_aristas_vertices_izquierdos(grafo_mapa);
    inicializar_aristas_vertices_centrales(grafo_mapa);
}


bool coincide_con_posicion_random(int i, int posiciones_random[]){
    return (i == posiciones_random[PRIMERA_POSICION] || i == posiciones_random[SEGUNDA_POSICION] || i == posiciones_random[TERCERA_POSICION] || i == posiciones_random[CUARTA_POSICION] || i ==
    posiciones_random[QUINTA_POSICION]);
}

void inicializar_posiciones_random(int posiciones_random[]){
    for(int i = 0; i < MAXIMO_POSICIONES_RANDOM_NECESITADAS; ++i){
        posiciones_random[i] = UNA_POSICION + (rand() % CANTIDAD_DE_VERTICES_NECESITADOS);
    }
}

void inicializar_vertices(std::ifstream &archivo_vertices, Grafo &grafo_mapa){
    int posiciones_random[MAXIMO_POSICIONES_RANDOM_NECESITADAS];
    inicializar_posiciones_random(posiciones_random);

    string id_vertice;
    string color;

    while(getline(archivo_vertices, id_vertice, ',')){
        getline(archivo_vertices, color, '\n');

        if(coincide_con_posicion_random(stoi(id_vertice), posiciones_random)){
            //grafo_mapa.agregar_vertice(stoi(id_vertice), animal, color[0]);
            grafo_mapa.agregar_vertice(stoi(id_vertice), nullptr, color[PRIMERA_POSICION]); //! DESPUES ESTO SE DEBE ELIMINAR
        } else {
            grafo_mapa.agregar_vertice(stoi(id_vertice), nullptr, color[PRIMERA_POSICION]);
        }
    }
}

void abrir_archivo_vertices(Grafo &grafo_mapa){
    std::ifstream archivo_vertices(ARCHIVO_VERTICES);
    if(!archivo_vertices.is_open()){
        cout<<"Error al abrir el archivo de vertices. Compruebe que exista y que no este corrompido y vuelva a intentar."<<endl;
        exit(ERROR);
    }

    inicializar_vertices(archivo_vertices, grafo_mapa);
    archivo_vertices.close();
}

//Pre: El grafo debe tener forma CUADRADA.
void llenar_grafo(Grafo &grafo_mapa){
    abrir_archivo_vertices(grafo_mapa);
    inicializar_aristas(grafo_mapa);
}

void realizar_impresion(Grafo &grafo_mapa, int &iterador_vertices, int coordenada_x, int coordenada_y){
    iterador_vertices++;
    if(grafo_mapa.devolver_animal_vertice(iterador_vertices) == nullptr){
        cout << grafo_mapa.devolver_color_vertice(iterador_vertices) << " ";
    } else {
        cout << " encontre un animal";
        //Imprimiria una A indicando un animal y después guardar la J como coordenada Y y la I como coordenada X.
    }
}

void imprimir_grafo(Grafo &grafo_mapa){
    int iterador_vertices = 0;

    cout << "  0 1 2 3 4 5 6 7";
    for(int j = 0; j < ALTO_DEL_MAPA; ++j){
        cout << endl;
        cout << j << " ";
        for(int i = 0; i < ANCHO_DEL_MAPA; ++i){
            realizar_impresion(grafo_mapa, iterador_vertices, i, j);
        }
    }

    cout << endl << endl;
}

void presentar(){
    cout << "Bienvenido al sistema de rescate de animales. Se ha detectado posible movimiento animal en las posiciones que han sido marcadas con una A en el mapa." << endl;
    cout << "Para averiguar mas caracteristicas sobre el posible animal y poder rescatarlo, dirigete hacia el. Recorda que para dirigirte a un animal, tenes que contar con combustible "
            "suficiente." << endl;
    cout << "Quedate tranquilo que nosotros nos ocuparemos de encontrar la via optima para gastar el menor combustible posible. Buena suerte!" << endl;
    cout << endl;
}

bool respuesta_fuera_de_rango(int respuesta){
    return (respuesta < COORDENADA_MINIMA_PERMITIDA || respuesta > COORDENADA_MAXIMA_PERMITIDA);
}

void revisar_respuesta(int &respuesta){
    while(respuesta_fuera_de_rango(respuesta)){
        cout << "Coordenada invalida. Porfavor vuelva a intentar con valores validos (1-8): ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> respuesta;
        cout << endl;
    }
}

void pedir_coordenadas(int &coordenada_usuario_x, int &coordenada_usuario_y){
    cout << "Ingrese la coordenada X a donde desea desplazarse: ";
    cin >> coordenada_usuario_x;
    revisar_respuesta(coordenada_usuario_x);

    cin.clear();
    cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');

    cout << "Ingrese la coordenada Y a donde desea desplazarse: ";
    cin >> coordenada_usuario_y;
    revisar_respuesta(coordenada_usuario_y);
}

Animal* revisar_coordenadas(Grafo grafo_mapa, int coordenada_x, int coordenada_y){
    int vertice_buscado = (ANCHO_DEL_MAPA * ALTO_DEL_MAPA) - (ALTO_DEL_MAPA * coordenada_y) + coordenada_x;
    int combustible_necesitado = grafo_mapa.obtener_camino_minimo(1, vertice_buscado)


    Animal* animal_buscado = grafo_mapa.devolver_animal_vertice(vertice_buscado);

}

void rescatar_animal(ArbolB<Animal*> &registro_de_animales, int &combustible_auto) {
    int coordenada_usuario_x, coordenada_usuario_y;
    //generar_animales_random();
    Grafo grafo_mapa;
    llenar_grafo(grafo_mapa);
    grafo_mapa.usar_dijkstra();

    presentar();
    imprimir_grafo(grafo_mapa);
    pedir_coordenadas(coordenada_usuario_x, coordenada_usuario_y);
    Animal* animal_a_rescatar = revisar_coordenadas(grafo_mapa, coordenada_usuario_x, coordenada_usuario_y);
}
