#include "Rescatar_animal.h"
#include "Grafo/Grafo.h"
#include "Arbol_B/Arbol_B.h"
#include "Animal/Gato.h"
#include "Animal/Caballo.h"
#include "Animal/Erizo.h"
#include "Animal/Perro.h"

const int CANTIDAD_DE_VERTICES_NECESITADOS = 64;
const int MAXIMO_POSICIONES_RANDOM_NECESITADAS = 5;
const int TERCERA_POSICION = 2;
const int CUARTA_POSICION = 3;
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
const string ARCHIVO_VERTICES = "../resources/vertices.csv";
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
const int VERTICE_INICIAL_AUTO = 1;

const int PRIMERA_Y_ULTIMA_COLUMNA = 2;
const int PESO_A_VERTICE_NEGRO = 40;
const int PESO_A_VERTICE_GRIS = 1;
const int PESO_A_VERTICE_MARRON_OSCURO = 5;
const int PESO_A_VERTICE_MARRON_CLARO = 2;
const int DOS_POSICIONES = 2;
const int PRIMERA_POSICION_EN_DIAGONAL_AL_PRIMER_VERTICE = 10;
const int TRES_POSICIONES = 3;
const int SEGUNDO_VERTICE = 2;
const int DESFAZAJE_ITERADOR = 1;

const int UN_ANIO = 1;
const int DOS_ANIOS = 2;
const int TRES_ANIOS = 3;
const int CUATRO_ANIOS = 4;

const int VOLVER_AL_MENU = 1;
const int REINTENTAR = 0;
const int MAXIMO_ANIMALES_A_RESCATAR = 4;
const char COLOR_NEGRO = 'N';
const char COLOR_MARRON_OSCURO = 'M';
const char COLOR_MARRON_CLARO = 'C';

void Rescatar_animal::inicializar_aristas_vertices_esquinas(Grafo &grafo_mapa){
    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE, ID_VERTICE_DERECHO_PRIMER_VERTICE, PESO_A_VERTICE_NEGRO);
    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE, ID_VERTICE_INFERIOR_PRIMER_VERTICE, PESO_A_VERTICE_GRIS);

    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE_PRIMER_FILA, ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE_PRIMER_FILA, PESO_A_VERTICE_MARRON_CLARO);
    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE_PRIMER_FILA, ID_VERTICE_INFERIOR_ULTIMO_VERTICE_PRIMER_FILA, PESO_A_VERTICE_NEGRO);

    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE_ULTIMA_FILA, ID_VERTICE_SUPERIOR_PRIMER_VERTICE_ULTIMA_FILA, PESO_A_VERTICE_MARRON_CLARO);
    grafo_mapa.agregar_camino(ID_PRIMER_VERTICE_ULTIMA_FILA, ID_VERTICE_DERECHO_PRIMER_VERTICE_ULTIMA_FILA, PESO_A_VERTICE_MARRON_CLARO);

    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE, ID_VERTICE_SUPERIOR_ULTIMO_VERTICE, PESO_A_VERTICE_MARRON_OSCURO);
    grafo_mapa.agregar_camino(ID_ULTIMO_VERTICE, ID_VERTICE_IZQUIERDO_ULTIMO_VERTICE, PESO_A_VERTICE_GRIS);
}

int Rescatar_animal::determinar_peso(Grafo &grafo_mapa, int id_vertice){
    int peso;

    if(grafo_mapa.devolver_color_vertice(id_vertice) ==  COLOR_NEGRO){
        peso = PESO_A_VERTICE_NEGRO;
    } else if(grafo_mapa.devolver_color_vertice(id_vertice) ==  COLOR_MARRON_OSCURO){
        peso = PESO_A_VERTICE_MARRON_OSCURO;
    } else if(grafo_mapa.devolver_color_vertice(id_vertice) ==  COLOR_MARRON_CLARO){
        peso = PESO_A_VERTICE_MARRON_CLARO;
    } else {
        peso = PESO_A_VERTICE_GRIS;
    }

    return peso;
}

void Rescatar_animal::inicializar_aristas_vertices_superiores(Grafo &grafo_mapa){
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

void Rescatar_animal::inicializar_aristas_vertices_inferiores(Grafo &grafo_mapa){
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

void Rescatar_animal::inicializar_aristas_vertices_derechos(Grafo &grafo_mapa){
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

void Rescatar_animal::inicializar_aristas_vertices_izquierdos(Grafo &grafo_mapa){
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

void Rescatar_animal::inicializar_aristas_vertices_centrales(Grafo &grafo_mapa){
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

void Rescatar_animal::inicializar_aristas(Grafo &grafo_mapa){
    inicializar_aristas_vertices_esquinas(grafo_mapa);
    inicializar_aristas_vertices_superiores(grafo_mapa);
    inicializar_aristas_vertices_inferiores(grafo_mapa);
    inicializar_aristas_vertices_derechos(grafo_mapa);
    inicializar_aristas_vertices_izquierdos(grafo_mapa);
    inicializar_aristas_vertices_centrales(grafo_mapa);
}

bool Rescatar_animal::coincide_con_posicion_random(int id_vertice, int posiciones_random[]){
    bool coincide = false;

    for(int j = 0; j < MAXIMO_ANIMALES_A_RESCATAR; ++j){
        if(id_vertice == posiciones_random[j]) coincide = true;
    }

    return coincide;
}

void Rescatar_animal::inicializar_posiciones_random(int posiciones_random[]){
    for(int i = 0; i < MAXIMO_POSICIONES_RANDOM_NECESITADAS; ++i){
        posiciones_random[i] = SEGUNDO_VERTICE + (rand() % CANTIDAD_DE_VERTICES_NECESITADOS);
    }
}

void Rescatar_animal::inicializar_vertices(std::ifstream &archivo_vertices, Grafo &grafo_mapa, Animal* animales_a_rescatar[]){
    int posiciones_random[MAXIMO_POSICIONES_RANDOM_NECESITADAS];
    inicializar_posiciones_random(posiciones_random);

    string id_vertice;
    string color;
    int iterador_animal = 0;

    while(getline(archivo_vertices, id_vertice, ',')){
        getline(archivo_vertices, color, '\n');

        if(coincide_con_posicion_random(stoi(id_vertice), posiciones_random)){
            grafo_mapa.agregar_vertice(stoi(id_vertice), animales_a_rescatar[iterador_animal], color[PRIMERA_POSICION]);
            iterador_animal++;
        } else {
            grafo_mapa.agregar_vertice(stoi(id_vertice), nullptr, color[PRIMERA_POSICION]);
        }
    }
}

void Rescatar_animal::leer_archivo_vertices(Grafo &grafo_mapa, Animal* animales_a_rescatar[]){
    std::ifstream archivo_vertices(ARCHIVO_VERTICES);
    if(!archivo_vertices.is_open()){
        cout<<"Error al abrir el archivo de vertices. Compruebe que exista y que no este corrompido y vuelva a intentar."<<endl;
        exit(ERROR);
    }

    inicializar_vertices(archivo_vertices, grafo_mapa, animales_a_rescatar);
    archivo_vertices.close();
}

void Rescatar_animal::llenar_grafo(Grafo &grafo_mapa, Animal* animales_a_rescatar[]){
    leer_archivo_vertices(grafo_mapa, animales_a_rescatar);
    inicializar_aristas(grafo_mapa);
}

void Rescatar_animal::realizar_impresion(Grafo &grafo_mapa, int &iterador_vertices){
    iterador_vertices++;
    if(iterador_vertices == VERTICE_INICIAL_AUTO){
        cout << "R" << " ";
    } else if(grafo_mapa.devolver_animal_vertice(iterador_vertices) == nullptr){
        cout << grafo_mapa.devolver_color_vertice(iterador_vertices) << " ";
    } else {
        cout << "A" << " ";
    }
}

void Rescatar_animal::imprimir_grafo(Grafo &grafo_mapa){
    int iterador_vertices = 0;

    cout << "  1 2 3 4 5 6 7 8";
    for(int j = 0; j < ALTO_DEL_MAPA; ++j){
        cout << endl;
        cout << j + DESFAZAJE_ITERADOR << " ";
        for(int i = 0; i < ANCHO_DEL_MAPA; ++i){
            realizar_impresion(grafo_mapa, iterador_vertices);
        }
    }

    cout << endl << endl;
}

void Rescatar_animal::presentar(){
    cout << "Bienvenido al sistema de rescate de animales. Se ha detectado posible movimiento animal en las posiciones que han sido marcadas con una A en el mapa." << endl;
    cout << "Para averiguar mas caracteristicas sobre el posible animal y poder rescatarlo, dirigete hacia el. Recorda que para dirigirte a un animal, tenes que contar con combustible "
            "suficiente." << endl;
    cout << "Quedate tranquilo que nosotros nos ocuparemos de encontrar la via optima para gastar el menor combustible posible. Buena suerte!" << endl << endl;
    cout << "Las señalizaciones significan lo siguiente:" << endl;
    cout << "R: Posicion de la camioneta Reserva." << endl;
    cout << "A: Animal en la zona." << endl;
    cout << "C: Tierra, con un costo de llegada de 2 de combustible." << endl;
    cout << "N: Acantilado, con un costo de llegada de 40 de combustible." << endl;
    cout << "M: Montaña, con un costo de llegada de 5 de combustible." << endl;
    cout << "G: Camino, con un costo de llegada de 1 de combustible." << endl;
    cout << endl;
}

bool Rescatar_animal::respuesta_fuera_de_rango(int respuesta){
    return (respuesta < COORDENADA_MINIMA_PERMITIDA || respuesta > COORDENADA_MAXIMA_PERMITIDA);
}

void Rescatar_animal::revisar_respuesta(int &respuesta){
    while(respuesta_fuera_de_rango(respuesta)){
        cout << "Coordenada invalida. Porfavor vuelva a intentar con valores validos (1-8): ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> respuesta;
        cout << endl;
    }
}

void Rescatar_animal::pedir_coordenadas(int &coordenada_usuario_x, int &coordenada_usuario_y){
    cout << "Ingrese la coordenada X a donde desea desplazarse: ";
    cin >> coordenada_usuario_x;
    revisar_respuesta(coordenada_usuario_x);

    cin.clear();
    cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');

    cout << "Ingrese la coordenada Y a donde desea desplazarse: ";
    cin >> coordenada_usuario_y;
    revisar_respuesta(coordenada_usuario_y);
}

Animal* Rescatar_animal::revisar_coordenadas(Grafo &grafo_mapa, int coordenada_x, int coordenada_y){
    if(coordenada_x == VERTICE_INICIAL_AUTO && coordenada_y == VERTICE_INICIAL_AUTO) {
        cout << "No se puede viajar a esa coordenada." << endl;
        return nullptr;
    }

    int vertice_buscado = ((ANCHO_DEL_MAPA * coordenada_y) - ALTO_DEL_MAPA ) + coordenada_x;
    Animal* animal_buscado = grafo_mapa.devolver_animal_vertice(vertice_buscado);

    if(animal_buscado == nullptr) cout << "No encontramos ningun animal en el area seleccionada." << endl;

    return animal_buscado;
}

int Rescatar_animal::revisar_combustible(int coordenada_x, int coordenada_y, int combustible_auto, Grafo &grafo_mapa){
    int vertice_buscado = ((ANCHO_DEL_MAPA * coordenada_y) - ALTO_DEL_MAPA ) + coordenada_x;
    //grafo_mapa.obtener_camino_minimo(VERTICE_INICIAL_AUTO, vertice_buscado);  //! For debug only.

    if(coordenada_x == VERTICE_INICIAL_AUTO && coordenada_y == VERTICE_INICIAL_AUTO){
        cout << "No se puede viajar a esa coordenada." << endl;
        return ERROR;
    }

    int combustible_necesitado = grafo_mapa.obtener_peso_minimo(VERTICE_INICIAL_AUTO, vertice_buscado);
    if(combustible_necesitado > combustible_auto) {
        cout << "No se puede viajar a esa coordenada porque no hay suficiente combustible." << endl;
        return ERROR;
    }

    return combustible_necesitado;
}

bool Rescatar_animal::respuesta_valida_menu_error(int respuesta){
    return (respuesta == VOLVER_AL_MENU || respuesta == REINTENTAR);
}

void Rescatar_animal::chequear_respuesta_menu_error(int &respuesta){
    while(!respuesta_valida_menu_error(respuesta)){
        cout << "Respuesta invalida, vuelva a intentar con valores validos (0 volver a intentar, 1 volver al menu principal): ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> respuesta;
        cout << endl;
    }
}

void Rescatar_animal::desplegar_menu_error(Arbol_B <Animal*> &registro_de_animales, int &combustible_auto){
    int respuesta;
    cout << "Vemos que, por una razon u otra, no pudiste llegar a donde deseabas. ¿Queres volver a intentarlo (0) o preferis volver al menu principal (1)? ";
    cin >> respuesta;
    chequear_respuesta_menu_error(respuesta);
    if(respuesta == VOLVER_AL_MENU) return;

    rescatar_animal(registro_de_animales, combustible_auto);
}

bool Rescatar_animal::hubo_un_error(int resultado_inspeccion, Animal* animal_a_rescatar){
    return (resultado_inspeccion == ERROR || animal_a_rescatar == nullptr);
}

void Rescatar_animal::generar_animales_random(Animal* animales_a_rescatar[]){
    animales_a_rescatar[PRIMERA_POSICION] = new Gato("nombre_predefinido", UN_ANIO, "pequeño", 'G', "travieso");
    animales_a_rescatar[SEGUNDA_POSICION] = new Perro("nombre_predefinido", DOS_ANIOS, "diminuto", 'P', "sociable");
    animales_a_rescatar[TERCERA_POSICION] = new Erizo("nombre_predefinido", TRES_ANIOS, "mediano", 'E', "dormilon");
    animales_a_rescatar[CUARTA_POSICION] = new Caballo("nombre_predefinido", CUATRO_ANIOS, "grande", 'C', "travieso");
}

void Rescatar_animal::pedir_nombre(Animal* animal_a_rescatar){
    string nombre;
    cout << "Felicitaciones! Encontramos un " << animal_a_rescatar->get_especie_completa() << " en el lugar! ¿Cual es su nombre? ";
    getline(cin >> ws, nombre);
    animal_a_rescatar->set_nombre(nombre);
}

void Rescatar_animal::repedir_nombre(Animal* animal_a_rescatar){
    string nombre;
    cout << endl << "Ya existe un animal con ese nombre en el registro. Por favor, ingresa otro nombre: ";
    getline(cin >> ws, nombre);
    animal_a_rescatar->set_nombre(nombre);
}

string Rescatar_animal::realizar_rescate(int combustible_necesitado, Animal* animal_a_rescatar, Arbol_B<Animal*> &registro_de_animales, int &combustible_auto){
    pedir_nombre(animal_a_rescatar);
    int resultado_insercion = registro_de_animales.insertar(animal_a_rescatar);
    while(resultado_insercion == ANIMAL_REPETIDO) {
        repedir_nombre(animal_a_rescatar);
        resultado_insercion = registro_de_animales.insertar(animal_a_rescatar);
    }
    combustible_auto = combustible_auto - combustible_necesitado;
    cout << endl << "Animal rescatado con exito! Su auto ahora tiene " << combustible_auto << " de combustible" << endl << endl;
    return animal_a_rescatar->get_nombre();
}


void Rescatar_animal::liberar_animales_creados(Animal* animales_a_rescatar[]){
    for(int i = 0; i < MAXIMO_ANIMALES_A_RESCATAR; ++i){
        delete animales_a_rescatar[i];
    }
}


void Rescatar_animal::liberar_animales_no_rescatados(Animal* animales_a_rescatar[], string nombre_animal_rescatado){
    for(int i = 0; i < MAXIMO_ANIMALES_A_RESCATAR; ++i){
        if(animales_a_rescatar[i]->get_nombre() != nombre_animal_rescatado) delete animales_a_rescatar[i];
    }
}

void Rescatar_animal::rescatar_animal(Arbol_B<Animal*> &registro_de_animales, int &combustible_auto) {
    int coordenada_usuario_x, coordenada_usuario_y;
    Animal* animales_a_rescatar[MAXIMO_ANIMALES_A_RESCATAR];
    generar_animales_random(animales_a_rescatar);
    Grafo grafo_mapa;
    llenar_grafo(grafo_mapa, animales_a_rescatar);
    grafo_mapa.usar_dijkstra();

    presentar();
    imprimir_grafo(grafo_mapa);
    pedir_coordenadas(coordenada_usuario_x, coordenada_usuario_y);
    int resultado_inspeccion = revisar_combustible(coordenada_usuario_x, coordenada_usuario_y, combustible_auto, grafo_mapa);
    Animal* animal_a_rescatar = revisar_coordenadas(grafo_mapa, coordenada_usuario_x, coordenada_usuario_y);

    if(hubo_un_error(resultado_inspeccion, animal_a_rescatar)) {
        liberar_animales_creados(animales_a_rescatar);
        desplegar_menu_error(registro_de_animales, combustible_auto);
    } else {
        string nombre_animal_rescatado = realizar_rescate(resultado_inspeccion, animal_a_rescatar, registro_de_animales, combustible_auto);
        liberar_animales_no_rescatados(animales_a_rescatar, nombre_animal_rescatado);
    }
}