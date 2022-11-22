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

const int PESO_A_VERTICE_NEGRO = 40;
const int PESO_A_VERTICE_GRIS = 1;
const int PESO_A_VERTICE_MARRON_OSCURO = 5;
const int PESO_A_VERTICE_MARRON_CLARO = 2;

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

void inicializar_aristas_verices_superiores(Grafo &grafo_mapa){
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

void inicializar_aristas(Grafo &grafo_mapa){
    inicializar_aristas_vertices_esquinas(grafo_mapa);
    inicializar_aristas_verices_superiores(grafo_mapa);
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
        exit(1);
    }

    inicializar_vertices(archivo_vertices, grafo_mapa);
    archivo_vertices.close();
}

void llenar_grafo(Grafo &grafo_mapa){
    abrir_archivo_vertices(grafo_mapa);
    inicializar_aristas(grafo_mapa);
}

void adoptar_animal(ArbolB<Animal*> &registro_de_animales) {
    Grafo grafo_mapa;
    grafo_mapa.usar_dijkstra();
    llenar_grafo(grafo_mapa);


    //grafo_mapa.obtener_camino_minimo(1, 2);
}