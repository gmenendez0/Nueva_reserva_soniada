#ifndef TP3_ARBOLB_H
#define TP3_ARBOLB_H

#include <iostream>
#include <fstream>
#include "nodo.h"
#include "string"

const int ANIMAL_REPETIDO = 1;
const int COMPLETADA = 0;
const int ANIMAL_NO_ENCONTRADO = 1;
const int AUMENTO_DE_NAFTA_CAMIONETA = 5;
const int MAXIMO_NAFTA_CAMIONETA = 100;
const int LIMITE_ANIMALES_ESCAPADOS = 3;
const int EXITO = 0;
const int ERROR = -1;
const std::string NOMBRE_CSV = "animales.csv";

template<typename Tipo_de_animal>
class ArbolB{
    private:
        Nodo<Tipo_de_animal>* raiz;

    private:
        //Pre
        //Post Pone en marcha los metodos correspondientes para insertar en animal en el arbol. Devuelve 1 en caso de insercion erronea por animal repetido, 0 en caso de exito
        int* insertar_en_arbol(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post Evalua las posibilidades de insercion en un nodo hoja y redirige a la adecuada
        void evaluar_posibilidades_nodo_hoja(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        //Pre
        //Post Evalua las posibilidades de insercion en un nodo no hoja y redirige a la adecuada
        void evaluar_posibilidades_nodo_con_hijos(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre El nodo recibido debe tener dos datos
        //Post Devuelve true si el animal recibido es más grande que las dos claves del nodo
        bool animal_es_mas_grande(string nombre_animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        //Pre El nodo recibido debe tener minimo un dato
        //Post Devuelve true si el animal recibido es más grande que la primera clave pero más chico que la segunda del nodo recibido
        bool animal_es_intermedio(string nombre_animal, Nodo<Tipo_de_animal>* nodo_a_insertar);

        //Pre El nodo recibido debe ser hoja.
        //Post Pone en marcha el proceso para splitear un nodo hoja
        void split_hoja(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre El nodo recibido no debe ser hoja
        //Post Pone en marcha el proceso para splitear un nodo no hoja
        void split_nodo_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post Realiza la insercion de un dato en un nodo
        void realizar_insercion(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal);

        //Pre
        //Post Evalua las posibilidades de insercion en un nodo cuando el animal a insertar proviene de un split
        void evaluar_insercion_proveniente_de_split(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        //Pre
        //Post Evalua las posibilidades de insercion en un nodo cuando el animal a insertar no proviene de split
        void evaluar_insercion_no_proveniente_de_split(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        //Pre  El animal a insertar debe venir de un previo split y el nodo a insertar debe tener dos datos.
        //Post Realiza la insercion de un dato en un nodo cuando el animal a insertar proviene de un split y el nodo a insertar tiene dos datos
        void realizar_insercion_proveniente_de_split_dos_datos(Nodo<Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
        resultado_insercion);

        //Pre El nodo recibido para insertar debe tener solo un dato
        //Post Evalua las posibilidades de insercion en un nodo con un solo dato cuando la insercion no proviene de un split
        void evaluar_insercion_no_proveniente_de_split_un_dato(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
        int* resultado_insercion);

        //Pre El nodo recibido para insertar debe tener dos datos
        //Post Evalua las posibilidades de insercion en un nodo con un dos datos cuando la insercion no proviene de un split
        void evaluar_insercion_no_proveniente_de_split_dos_datos(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
        int* resultado_insercion);

        //Pre El nodo a splitear debe ser raiz y hoja.
        //Post Realiza el split de un nodo raiz hoja
        void realizar_split_nodo_hoja_raiz(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor);

        //Pre El nodo a splitear debe ser hoja y tener un dato.
        //Post Realiza el split de un nodo hoja de un dato
        void realizar_split_nodo_hoja_un_dato(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre El nodo a splitear debe tener dos datos y ser hoja
        //Post Realiza el split de un nodo hoja de dos datos.
        void realizar_split_nodo_hoja_dos_datos(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
        dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre El nodo padre del nodo a splitear debe tener un dato.
        //Post Ordena los parentezcos de los nodos segun corresponda cuando el nodo padre del nodo a splitear tiene un dato.
        void ordenar_parentezco_padre_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nodo_menor, Nodo <Tipo_de_animal>* nodo_mayor);

        //Pre El nodo padre del nodo a splitear debe tener dos datos.
        //Post Ordena los parentezcos de los nodos segun corresponda cuando el nodo padre del nodo a splitear tiene dos datos.
        void ordenar_parentezco_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nuevo_nodo_menor, Nodo <Tipo_de_animal>* nuevo_nodo_mayor);

        //Pre El nodo a splitear debe ser raiz y no hoja
        //Post Pone en marcha el split de un nodo raiz no hoja
        void split_nodo_raiz_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor);

        //Pre EL nodo a splitear debe ser no hoja y no raiz
        //Post Pone en marcha el split de un nodo no hoja y no raiz
        void split_nodo_con_hijos_no_raiz(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor, bool
        &animal_a_insertar_proviene_de_split, int* resultado_insercion);

        //Pre
        //Post Evalua el camino a tomar en caso de que haya un animal con el mismo nombre en el arbol. Si este animal está eliminado, lo reemplaza por el ingresante, caso contrario,
        // devuelve error en la insercion.
        void evaluar_repeticion_nombre(Tipo_de_animal animal_coincidente, Tipo_de_animal animal, int* resultado_insercion);

        //Pre
        //Post Devuelve nullptr en caso de que no se haya encontrado un animal con el nombre buscado, caso contrario devuelve el puntero al animal buscado.
        Tipo_de_animal revisar_arbol(string nombre, Nodo <Tipo_de_animal>* nodo_a_revisar);

        //Pre
        //Post Recorre todo el arbol presentando a todos los datos que encuentre.
        void presentar_todos(Nodo<Tipo_de_animal>* nodo_actual);

        //Pre
        //Post Recorre todo el vector de datos de un nodo, presentando los datos que encuentre en el.
        void presentar_datos_nodo(Nodo<Tipo_de_animal>* nodo_actual);

        //Pre
        //Post Devuelve nullptr en caso de que el animal encontrado este eliminado, caso contrario devolvera un puntero a él
        Tipo_de_animal analizar_animal_encontrado(Tipo_de_animal animal_encontrado);

        //Pre
        //Post Pasa el tiempo en todos los animales aumentando su hambre e higene. Además, actualiza  la cantidad de animales que se hayan escapado de la reserva.
        void pasar_tiempo(Nodo <Tipo_de_animal>* nodo_actual, int* animales_escapados);

        //Pre
        //Post Pasa el tiempo en todos los animales de un nodo aumentando su hambre e higene.
        void pasar_tiempo_nodo(Nodo <Tipo_de_animal>* nodo_actual, int* animales_escapados);

        //Pre
        //Post Presenta todos los animales que esten en el arbol sin haber sido eliminados ni haber escapado
        void presentar_cuidables(Nodo <Tipo_de_animal>* nodo_actual);

        //Pre
        //Post Presenta todos los animales que esten en el nodo sin haber sido eliminados ni haber escapado
        void presentar_cuidables_nodo(Nodo <Tipo_de_animal>* nodo_actual);

        //Pre
        //Post Devuelve true en caso de que el animal no este ni eliminado ni haya escapado, false en caso contrario.
        bool animal_esta_presente(Tipo_de_animal animal);

        //Pre
        //Post Avisa al usuario que se escaparon demasiados animales, por lo que la reserva cerrara, finalizando el programa.
        void desarmar_reserva(int* animales_escapados);

        //Pre
        //Post Guarda todos los animales (no eliminados ni escapados) que esten en el arbol en un archivo de texto.
        void guardar_datos_en_archivo(Nodo <Tipo_de_animal>* nodo_actual, std::ofstream &archivo_animales);

        //Post Chequea la correcta apertura del archivo. En caso de error, termina el programa dando aviso del error al usuario
        void chequear_archivo_escritura(std::ofstream &archivo);

        //Post Guarda los datos del nodo (no eliminados ni escapados) en el archivo de texto.
        void realizar_guardado(Nodo <Tipo_de_animal>* nodo_actual, std::ofstream &archivo_animales);

        //Pre
        //Post: Devuelve un string con todos los datos del animal (nombre, edad, especie, personalidad y tamaño).
        string recibir_datos_animal(Tipo_de_animal animal);

        void setear_hijos_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_padre, Nodo<Tipo_de_animal>* primer_hijo, Nodo<Tipo_de_animal>* segundo_hijo, Nodo<Tipo_de_animal>* tercer_hijo,
          Nodo<Tipo_de_animal>* hijo_auxiliar);

        //Setea los parentescos correspondientes al splitear un nodo
        void setear_parentescos_nodo_spliteado(Nodo <Tipo_de_animal>* primer_nuevo_nodo, Nodo<Tipo_de_animal>* segundo_nuevo_nodo, Nodo<Tipo_de_animal>* nodo_a_splitear);

        //Post elimina todos los nodos y datos del arbol, liberando la memoria alocada
        void eliminar_todos(Nodo <Tipo_de_animal>* nodo_actual);

        //Post elimina todos los datos de un nodo, liberando la memoria alocada
        void borrar_datos(Nodo <Tipo_de_animal>* nodo_actual);

    public:
        //Pre -
        //Post Crea un arbol vacio.
        ArbolB();

        //Pre Tiene que recibir un elemento inicializado para insertarse en el arbol usando su nombre como clave
        //Post Devolvera 0 en caso de operacion completada exitosamente y 1 en caso de animal repetido
        int insertar(Tipo_de_animal animal);

        //Pre -
        //Post Devolvera un puntero al animal buscado en caso de encontrarlo, y en caso contrario devuelve nullptr
        Tipo_de_animal buscar_animal(string nombre);

        //Pre -
        //Post Devolvera 0 en caso de eliminacion exitosa, 1 en caso contrario que no se haya encontrado el animal a eliminar
        int eliminar_animal(string nombre);

        //Pre -
        //Post Presentara todos los animales dentro del arbol
        void presentar_todos();

        //Pre -
        //Post Presentara todos los animales dentro del arbol que puedan ser cuidados (que no esten eliminados ni escapados)
        void presentar_cuidables();

        //Post Devuelve true en caso de que el arbol este vacio, caso contrario devuelve false
        bool esta_vacio();

        //Pre -
        //Post: Hace los debidos cambios al pasar el tiempo (cuando el usuario realiza una accion en el menu principal). Aumenta el hambre, decrece la higene (si corresponde) y aumenta la
        // nafta. En caso de que los animales escapados sean 3 o más, termina el programa.
        void pasar_tiempo(int &combustible_auto);

        //Post Guarda todos los datos del arbol en el archivo, salvo los animales que se hayan escapado o hayan sido adoptados.
        void guardar_datos_en_archivo();

        //Post elimina todos los nodos y datos del arbol, liberando la memoria alocada
        void eliminar_todos();
};

template<typename Tipo_de_animal>
ArbolB <Tipo_de_animal>::ArbolB(){
    raiz = nullptr;
}

template<typename Tipo_de_animal>
int ArbolB<Tipo_de_animal>::insertar(Tipo_de_animal animal){
    bool animal_a_insertar_proviene_de_split = false;
    int* puntero_resultado_insercion = new int;
    (*puntero_resultado_insercion) = COMPLETADA;
    int resultado_insercion = (*insertar_en_arbol(animal, this->raiz, animal_a_insertar_proviene_de_split, puntero_resultado_insercion));
    delete puntero_resultado_insercion;

    return resultado_insercion;
}

template<typename Tipo_de_animal>
int* ArbolB<Tipo_de_animal>::insertar_en_arbol(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
     if(nodo_a_insertar == nullptr){
        raiz = new Nodo <Tipo_de_animal>(animal);
    } else if(nodo_a_insertar->buscar_animal_con_mismo_nombre(animal->get_nombre()) != nullptr){
         evaluar_repeticion_nombre(nodo_a_insertar->buscar_animal_con_mismo_nombre(animal->get_nombre()), animal, resultado_insercion);
    } else if(nodo_a_insertar->es_hoja()){
        evaluar_posibilidades_nodo_hoja(animal, nodo_a_insertar, animal_a_insertar_proviene_de_split, resultado_insercion);
    } else{
        evaluar_posibilidades_nodo_con_hijos(animal, nodo_a_insertar, animal_a_insertar_proviene_de_split, resultado_insercion);
    }

    return resultado_insercion;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_repeticion_nombre(Tipo_de_animal animal_coincidente, Tipo_de_animal animal, int* resultado_insercion){
    if(animal_coincidente->esta_eliminado()){
        delete animal_coincidente;
        animal_coincidente = animal;        //? AVERIGUAR COMO HACER QUE ESTO ANDE CORRECTAMENTE
    } else {
        (*resultado_insercion) = ANIMAL_REPETIDO;
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_posibilidades_nodo_hoja(Tipo_de_animal animal, Nodo<Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int*
resultado_insercion){
    if(nodo_a_insertar->get_tope_datos() == UN_DATO){
        realizar_insercion(nodo_a_insertar, animal);
    } else {
        if(animal_es_mas_grande(animal->get_nombre(), nodo_a_insertar)){
            split_hoja(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal, animal_a_insertar_proviene_de_split, resultado_insercion);
            //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
        } else if(animal_es_intermedio(animal->get_nombre(), nodo_a_insertar)) {
            split_hoja(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), animal, nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split, resultado_insercion);
            //quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda SPLIT
        } else {
            split_hoja(nodo_a_insertar, animal, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split, resultado_insercion);
            //Quiere decir que el animal es más chico que las otras dos claves. SPLIT
        }
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_posibilidades_nodo_con_hijos(Tipo_de_animal animal, Nodo <Tipo_de_animal>* nodo_a_insertar, bool &animal_a_insertar_proviene_de_split, int*
resultado_insercion){
    if(animal_a_insertar_proviene_de_split){
        evaluar_insercion_proveniente_de_split(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    } else {
        evaluar_insercion_no_proveniente_de_split(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_insercion(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal){
    if(nodo_a_insertar->get_primera_clave() > animal->get_nombre()){
        //mover el dato que está en la primera posicion del vector a la segunda e insertar el animal nuevo en la primera posicion del vector.
        nodo_a_insertar->set_segundo_dato(nodo_a_insertar->get_primer_dato());
        nodo_a_insertar->set_primer_dato(animal);
        nodo_a_insertar->aumentar_tope_datos();
    } else {
        //insertar el dato en la segunda posicion del vector
        nodo_a_insertar->set_segundo_dato(animal);
        nodo_a_insertar->aumentar_tope_datos();
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_insercion_proveniente_de_split(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split, int*
resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE LA INSERCION PROVIENE DE SPLIT
    if(nodo_a_insertar->get_tope_datos() == UN_DATO){
        //? EL NODO TIENE UN SOLO DATO
        realizar_insercion(nodo_a_insertar, animal);
    } else {
        realizar_insercion_proveniente_de_split_dos_datos(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_insercion_proveniente_de_split_dos_datos(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
int* resultado_insercion){
    //? EL NODO TIENE DOS DATOS
    if(animal_es_mas_grande(animal->get_nombre(), nodo_a_insertar)){
        split_nodo_con_hijos(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal, animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. SPLIT
    } else if(animal_es_intermedio(animal->get_nombre(), nodo_a_insertar)) {
        split_nodo_con_hijos(nodo_a_insertar, nodo_a_insertar->get_primer_dato(), animal, nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda SPLIT
    } else {
        split_nodo_con_hijos(nodo_a_insertar, animal, nodo_a_insertar->get_primer_dato(), nodo_a_insertar->get_segundo_dato(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal es más chico que las otras dos claves. SPLIT
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_insercion_no_proveniente_de_split_un_dato(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
 int* resultado_insercion){
    //? EL NODO TIENE UN SOLO DATO
    if(nodo_a_insertar->get_primera_clave() > animal->get_nombre()){
        insertar_en_arbol(animal, nodo_a_insertar->get_primer_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //se avanza al PRIMER hijo del nodo.
    } else {
        insertar_en_arbol(animal, nodo_a_insertar->get_segundo_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //se avanza al SEGUNDO hijo del nodo.
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_insercion_no_proveniente_de_split_dos_datos(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
 int* resultado_insercion){
    //? EL NODO TIENE DOS DATOS
    if(animal_es_mas_grande(animal->get_nombre(), nodo_a_insertar)){
        insertar_en_arbol(animal, nodo_a_insertar->get_tercer_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal que trato de ingresar es más grande que las dos claves que están en el nodo. Se avanza al tercer hijo del nodo.
    } else if(animal_es_intermedio(animal->get_nombre(), nodo_a_insertar)) {
        insertar_en_arbol(animal, nodo_a_insertar->get_segundo_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal que quiero ingresar es más grande que la primera clave, pero más chico que la segunda. Se avanza al segundo hijo del nodo
    } else {
        insertar_en_arbol(animal, nodo_a_insertar->get_primer_hijo(), animal_a_insertar_proviene_de_split, resultado_insercion);
        //Quiere decir que el animal es más chico que las otras dos claves. Se avanza al primer hijo del nodo
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::evaluar_insercion_no_proveniente_de_split(Nodo <Tipo_de_animal>* nodo_a_insertar, Tipo_de_animal animal, bool &animal_a_insertar_proviene_de_split,
int* resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE LA INSERCION NO PROVIENE DE SPLIT
    if(nodo_a_insertar->get_tope_datos() == UN_DATO){
        evaluar_insercion_no_proveniente_de_split_un_dato(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    } else{
        evaluar_insercion_no_proveniente_de_split_dos_datos(nodo_a_insertar, animal, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_hoja(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    if(nodo_a_splitear->es_raiz()){
        realizar_split_nodo_hoja_raiz(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor);
    } else if(nodo_a_splitear->get_nodo_padre()->get_tope_datos() == UN_DATO){
        realizar_split_nodo_hoja_un_dato(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor, animal_a_insertar_proviene_de_split, resultado_insercion);
    } else{
        realizar_split_nodo_hoja_dos_datos(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_split_nodo_hoja_raiz(Nodo<Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES EL NODO RAIZ
    Nodo<Tipo_de_animal>* nodo_superior = new Nodo<Tipo_de_animal>(dato_intermedio);

    Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_superior);
    Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_superior);
    nodo_superior->set_primer_hijo(nodo_menor);
    nodo_superior->set_segundo_hijo(nodo_mayor);

    this->raiz = nodo_superior;
    delete nodo_a_splitear;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_split_nodo_hoja_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES HOJA Y PORQUE EL PADRE DEL NODO A SPLITEAR NO ESTA LLENO
    Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_a_splitear->get_nodo_padre());
    Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_a_splitear->get_nodo_padre());

    ordenar_parentezco_padre_un_dato(nodo_a_splitear, nodo_menor, nodo_mayor);

    animal_a_insertar_proviene_de_split = true;
    insertar_en_arbol(dato_intermedio, nodo_a_splitear->get_nodo_padre(), animal_a_insertar_proviene_de_split, resultado_insercion);
    delete nodo_a_splitear;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_split_nodo_hoja_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor,
  bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES HOJA Y PORQUE EL PADRE DEL NODO A SPLITEAR ESTA LLENO. HAY QUE PREPARAR TODO PARA EL SPLIT DEL PADRE.
    Nodo<Tipo_de_animal>* nuevo_nodo_menor = new Nodo<Tipo_de_animal>(dato_menor);
    Nodo<Tipo_de_animal>* nuevo_nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor);

    ordenar_parentezco_padre_dos_datos(nodo_a_splitear, nuevo_nodo_menor, nuevo_nodo_mayor);

    animal_a_insertar_proviene_de_split = true;
    insertar_en_arbol(dato_intermedio, nodo_a_splitear->get_nodo_padre(), animal_a_insertar_proviene_de_split, resultado_insercion);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_nodo_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio,
Tipo_de_animal dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    if(nodo_a_splitear->es_raiz()){
        split_nodo_raiz_con_hijos(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor);
    } else {
        split_nodo_con_hijos_no_raiz(nodo_a_splitear, dato_menor, dato_intermedio, dato_mayor, animal_a_insertar_proviene_de_split, resultado_insercion);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::setear_parentescos_nodo_spliteado(Nodo <Tipo_de_animal>* primer_nuevo_nodo, Nodo <Tipo_de_animal>* segundo_nuevo_nodo, Nodo <Tipo_de_animal>* nodo_a_splitear){
    primer_nuevo_nodo->set_primer_hijo(nodo_a_splitear->get_primer_hijo());
    primer_nuevo_nodo->set_segundo_hijo(nodo_a_splitear->get_segundo_hijo());

    segundo_nuevo_nodo->set_primer_hijo(nodo_a_splitear->get_tercer_hijo());
    segundo_nuevo_nodo->set_segundo_hijo(nodo_a_splitear->get_hijo_auxiliar());

    primer_nuevo_nodo->get_primer_hijo()->set_nodo_padre(primer_nuevo_nodo);
    primer_nuevo_nodo->get_segundo_hijo()->set_nodo_padre(primer_nuevo_nodo);

    segundo_nuevo_nodo->get_primer_hijo()->set_nodo_padre(segundo_nuevo_nodo);
    segundo_nuevo_nodo->get_segundo_hijo()->set_nodo_padre(segundo_nuevo_nodo);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_nodo_raiz_con_hijos(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal dato_mayor){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR ES UN NODO RAIZ CON HIJOS
    Nodo<Tipo_de_animal>* nodo_superior = new Nodo<Tipo_de_animal>(dato_intermedio);
    Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_superior);
    Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_superior);

    setear_parentescos_nodo_spliteado(nodo_menor, nodo_mayor, nodo_a_splitear);

    nodo_superior->set_primer_hijo(nodo_menor);
    nodo_superior->set_segundo_hijo(nodo_mayor);

    this->raiz = nodo_superior;
    delete nodo_a_splitear;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::split_nodo_con_hijos_no_raiz(Nodo <Tipo_de_animal>* nodo_a_splitear, Tipo_de_animal dato_menor, Tipo_de_animal dato_intermedio, Tipo_de_animal
dato_mayor, bool &animal_a_insertar_proviene_de_split, int* resultado_insercion){
    //? SI ENTRA POR ACA ES PORQUE EL NODO A SPLITEAR TIENE DOS DATOS Y EL NODO PADRE TIENE UNO SOLO.
    Nodo<Tipo_de_animal>* nodo_menor = new Nodo<Tipo_de_animal>(dato_menor, nullptr, nodo_a_splitear->get_nodo_padre());
    Nodo<Tipo_de_animal>* nodo_mayor = new Nodo<Tipo_de_animal>(dato_mayor, nullptr, nodo_a_splitear->get_nodo_padre());

    setear_parentescos_nodo_spliteado(nodo_menor, nodo_mayor, nodo_a_splitear);

    if(nodo_a_splitear->get_nodo_padre()->get_tope_datos() == UN_DATO){
        ordenar_parentezco_padre_un_dato(nodo_a_splitear, nodo_menor, nodo_mayor);
    } else {
        ordenar_parentezco_padre_dos_datos(nodo_a_splitear, nodo_menor, nodo_mayor);
    }

    ordenar_parentezco_padre_un_dato(nodo_a_splitear, nodo_menor, nodo_mayor);

    insertar_en_arbol(dato_intermedio, nodo_a_splitear->get_nodo_padre(), animal_a_insertar_proviene_de_split, resultado_insercion);
    delete nodo_a_splitear;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::ordenar_parentezco_padre_un_dato(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nodo_menor, Nodo <Tipo_de_animal>* nodo_mayor){
    if(nodo_a_splitear->es_primer_hijo()){
        nodo_a_splitear->get_nodo_padre()->set_primer_hijo(nodo_menor);
        nodo_a_splitear->get_nodo_padre()->set_tercer_hijo(nodo_a_splitear->get_nodo_padre()->get_segundo_hijo());
        nodo_a_splitear->get_nodo_padre()->set_segundo_hijo(nodo_mayor);
    } else {
        nodo_a_splitear->get_nodo_padre()->set_segundo_hijo(nodo_menor);
        nodo_a_splitear->get_nodo_padre()->set_tercer_hijo(nodo_mayor);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::setear_hijos_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_padre, Nodo <Tipo_de_animal>* primer_hijo, Nodo <Tipo_de_animal>* segundo_hijo, Nodo <Tipo_de_animal>*
 tercer_hijo, Nodo <Tipo_de_animal>* hijo_auxiliar){
    nodo_padre->set_hijo_auxiliar(hijo_auxiliar);
    nodo_padre->set_tercer_hijo(tercer_hijo);
    nodo_padre->set_primer_hijo(primer_hijo);
    nodo_padre->set_segundo_hijo(segundo_hijo);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::ordenar_parentezco_padre_dos_datos(Nodo <Tipo_de_animal>* nodo_a_splitear, Nodo <Tipo_de_animal>* nuevo_nodo_menor, Nodo <Tipo_de_animal>* nuevo_nodo_mayor){
    if(nodo_a_splitear->es_primer_hijo()){
        setear_hijos_padre_dos_datos(nodo_a_splitear->get_nodo_padre(), nuevo_nodo_menor, nuevo_nodo_mayor, nodo_a_splitear->get_nodo_padre()->get_segundo_hijo(),nodo_a_splitear->get_nodo_padre()->get_tercer_hijo());
    } else if(nodo_a_splitear->es_tercer_hijo()){
        setear_hijos_padre_dos_datos(nodo_a_splitear->get_nodo_padre(), nodo_a_splitear->get_nodo_padre()->get_primer_hijo(), nodo_a_splitear->get_nodo_padre()->get_segundo_hijo(), nuevo_nodo_menor,nuevo_nodo_mayor);
    } else {
        setear_hijos_padre_dos_datos(nodo_a_splitear->get_nodo_padre(), nodo_a_splitear->get_nodo_padre()->get_primer_hijo(), nuevo_nodo_menor, nuevo_nodo_mayor,nodo_a_splitear->get_nodo_padre()->get_tercer_hijo());
    }
}

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::animal_es_mas_grande(string nombre_animal, Nodo <Tipo_de_animal>* nodo_a_insertar){
    return (nodo_a_insertar->get_primera_clave() < nombre_animal && nodo_a_insertar->get_segunda_clave() < nombre_animal);
}

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::animal_es_intermedio(string nombre_animal, Nodo <Tipo_de_animal>* nodo_a_insertar){
    return (nodo_a_insertar->get_primera_clave() < nombre_animal && nodo_a_insertar->get_segunda_clave() > nombre_animal);
}

//!------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
Tipo_de_animal ArbolB <Tipo_de_animal>::buscar_animal(string nombre){
    return revisar_arbol(nombre, raiz);
}

template<typename Tipo_de_animal>
Tipo_de_animal ArbolB <Tipo_de_animal>::revisar_arbol(string nombre, Nodo <Tipo_de_animal>* nodo_a_revisar){
    if(nodo_a_revisar == nullptr) return nullptr;

    Tipo_de_animal animal_buscado = nodo_a_revisar->buscar_animal_con_mismo_nombre(nombre);
    //! RECORDAR QUE ESTA FUNCION TIENE UN ERROR: DA EL ANIMAL COMO ENCONTRADO A PESAR DE TENER EL ATRIBUTO "ELIMINADO"

    if(animal_buscado != nullptr){
        return analizar_animal_encontrado(animal_buscado);
    } else if(nombre < nodo_a_revisar->get_primera_clave()){
        return revisar_arbol(nombre, nodo_a_revisar->get_primer_hijo());
    } else if((nombre > nodo_a_revisar->get_primera_clave() && nodo_a_revisar->get_tope_datos() == UN_DATO) || (animal_es_intermedio(nombre, nodo_a_revisar))){
        return revisar_arbol(nombre, nodo_a_revisar->get_segundo_hijo());
    } else if(animal_es_mas_grande(nombre, nodo_a_revisar)){
        return revisar_arbol(nombre, nodo_a_revisar->get_tercer_hijo());
    }

    return nullptr;
}

template<typename Tipo_de_animal>
Tipo_de_animal ArbolB <Tipo_de_animal>::analizar_animal_encontrado(Tipo_de_animal animal_encontrado){
    if(animal_encontrado->esta_eliminado() || animal_encontrado->se_escapo()) return nullptr;

    return animal_encontrado;
}

//! ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
int ArbolB <Tipo_de_animal>::eliminar_animal(string nombre){
    Tipo_de_animal animal_a_eliminar = revisar_arbol(nombre, raiz);
    if(animal_a_eliminar == nullptr) return ANIMAL_NO_ENCONTRADO;

    animal_a_eliminar->eliminar();
    return COMPLETADA;
}

//! ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::presentar_todos(){
    this->presentar_todos(raiz);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::presentar_todos(Nodo <Tipo_de_animal>* nodo_actual){
    if(nodo_actual != nullptr) presentar_datos_nodo(nodo_actual);

    if(nodo_actual->get_primer_hijo() != nullptr) presentar_todos(nodo_actual->get_primer_hijo());
    if(nodo_actual->get_segundo_hijo() != nullptr) presentar_todos(nodo_actual->get_segundo_hijo());
    if(nodo_actual->get_tercer_hijo() != nullptr) presentar_todos(nodo_actual->get_tercer_hijo());
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::presentar_datos_nodo(Nodo <Tipo_de_animal>* nodo_actual){
    for(int i = 0; i < nodo_actual->get_tope_datos(); ++i){
        nodo_actual->get_dato_buscado(i)->presentar_animal();
    }
}

//! ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::esta_vacio(){
    return (raiz == nullptr);
}

//! ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::pasar_tiempo(int &combustible_auto){
    int* animales_escapados = new int;
    (*animales_escapados) = 0;

    this->pasar_tiempo(raiz, animales_escapados);
    if((*animales_escapados) >= LIMITE_ANIMALES_ESCAPADOS) desarmar_reserva(animales_escapados);

    combustible_auto = combustible_auto + AUMENTO_DE_NAFTA_CAMIONETA;
    if(combustible_auto > MAXIMO_NAFTA_CAMIONETA) combustible_auto = MAXIMO_NAFTA_CAMIONETA;
    delete animales_escapados;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::pasar_tiempo_nodo(Nodo <Tipo_de_animal>* nodo_actual, int* animales_escapados){
    for(int i = 0; i < nodo_actual->get_tope_datos(); ++i){
        if(nodo_actual->get_dato_buscado(i)->se_escapo()) (*animales_escapados)++;
        if(animal_esta_presente(nodo_actual->get_dato_buscado(i))) nodo_actual->get_dato_buscado(i)->pasar_el_tiempo(animales_escapados);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::pasar_tiempo(Nodo <Tipo_de_animal>* nodo_actual, int* animales_escapados){
    if(nodo_actual != nullptr) pasar_tiempo_nodo(nodo_actual, animales_escapados);

    if(nodo_actual->get_primer_hijo() != nullptr) pasar_tiempo(nodo_actual->get_primer_hijo(), animales_escapados);
    if(nodo_actual->get_segundo_hijo() != nullptr) pasar_tiempo(nodo_actual->get_segundo_hijo(), animales_escapados);
    if(nodo_actual->get_tercer_hijo() != nullptr) pasar_tiempo(nodo_actual->get_tercer_hijo(), animales_escapados);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::desarmar_reserva(int* animales_escapados){
    std::cout << "Se han escapado demasiados animales de la reserva. Debido a esto, se ha decidido desarmar la reserva y suspender su funcionamiento." << std::endl;
    delete animales_escapados;
    exit(EXITO);
}

//! ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::presentar_cuidables(){
    presentar_cuidables(raiz);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::presentar_cuidables(Nodo <Tipo_de_animal>* nodo_actual){
    if(nodo_actual != nullptr) presentar_cuidables_nodo(nodo_actual);

    if(nodo_actual->get_primer_hijo() != nullptr) presentar_cuidables(nodo_actual->get_primer_hijo());
    if(nodo_actual->get_segundo_hijo() != nullptr) presentar_cuidables(nodo_actual->get_segundo_hijo());
    if(nodo_actual->get_tercer_hijo() != nullptr) presentar_cuidables(nodo_actual->get_tercer_hijo());
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::presentar_cuidables_nodo(Nodo <Tipo_de_animal>* nodo_actual){
    for(int i = 0; i < nodo_actual->get_tope_datos(); ++i){
        if(animal_esta_presente(nodo_actual->get_dato_buscado(i))) nodo_actual->get_dato_buscado(i)->presentar_animal();
    }
}

template<typename Tipo_de_animal>
bool ArbolB <Tipo_de_animal>::animal_esta_presente(Tipo_de_animal animal){
    return (!animal->esta_eliminado() && !animal->se_escapo());
}

//! ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::guardar_datos_en_archivo(){
    std::ofstream archivo_animales(NOMBRE_CSV);
    chequear_archivo_escritura(archivo_animales);
    guardar_datos_en_archivo(raiz, archivo_animales);
    archivo_animales.close();
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::chequear_archivo_escritura(std::ofstream &archivo_animales){
    if(!archivo_animales.is_open()){
        std::cout<<"Error al abrir el archivo. Compruebe que exista y que no este corrompido y vuelva a intentar."<< std::endl;
        exit(ERROR);
    }
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::guardar_datos_en_archivo(Nodo <Tipo_de_animal>* nodo_actual, std::ofstream &archivo_animales){
    if(nodo_actual != nullptr) realizar_guardado(nodo_actual, archivo_animales);

    if(nodo_actual->get_primer_hijo() != nullptr) guardar_datos_en_archivo(nodo_actual->get_primer_hijo(), archivo_animales);
    if(nodo_actual->get_segundo_hijo() != nullptr) guardar_datos_en_archivo(nodo_actual->get_segundo_hijo(), archivo_animales);
    if(nodo_actual->get_tercer_hijo() != nullptr) guardar_datos_en_archivo(nodo_actual->get_tercer_hijo(), archivo_animales);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::realizar_guardado(Nodo <Tipo_de_animal>* nodo_actual, std::ofstream &archivo_animales){
    for(int i = 0; i < nodo_actual->get_tope_datos(); ++i){
        if(animal_esta_presente(nodo_actual->get_dato_buscado(i))) {
            archivo_animales << recibir_datos_animal(nodo_actual->get_dato_buscado(i));
        }
    }
}

template<typename Tipo_de_animal>
string ArbolB <Tipo_de_animal>::recibir_datos_animal(Tipo_de_animal animal){
    string datos_animal, nombre, edad, tamanio, especie, personalidad;

    nombre = animal->get_nombre();
    edad = std::to_string(animal->get_edad());
    tamanio = animal->get_tamanio();
    especie = animal->get_especie();
    personalidad = animal->get_personalidad();

    datos_animal = nombre + "," + edad + "," + tamanio + "," + especie + "," + personalidad + "\n";

    return datos_animal;
}

//! --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::eliminar_todos(){
    eliminar_todos(raiz);
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::eliminar_todos(Nodo <Tipo_de_animal>* nodo_actual){
    if(nodo_actual == nullptr) return;

    borrar_datos(nodo_actual);

    eliminar_todos(nodo_actual->get_primer_hijo());
    eliminar_todos(nodo_actual->get_segundo_hijo());
    eliminar_todos(nodo_actual->get_tercer_hijo());

    delete nodo_actual;
}

template<typename Tipo_de_animal>
void ArbolB <Tipo_de_animal>::borrar_datos(Nodo <Tipo_de_animal>* nodo_actual){
    for(int i = 0; i < nodo_actual->get_tope_datos(); ++i){
        delete nodo_actual->get_dato_buscado(i);
    }
}


#endif //TP3_ARBOLB_H
