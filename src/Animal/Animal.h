#ifndef TP2_ANIMAL_H
#define TP2_ANIMAL_H
#include <string>

using std::string;

class Animal{
    protected:
        string nombre;
        int edad;
        string tamanio;
        char especie;
        string personalidad;
        int higene_actual;
        int hambre_actual;
        int espacio_minimo_requerido;
        bool eliminado;
        bool escapo;
        string tipo_de_comida;

    protected:
        //Pre: Debe recibir el nombre, la edad, el tamanio, la especie y la personalidad del animal.
        //Post: Inicializa el animal con los valores recibidos.
        Animal(string nombre, int edad, string tamanio, char especie, string personalidad);

        void escapar();

    private:
        //Pre: Debe recibir el tamaño del animal
        //Post: Setea el espacio minimo requerido para que el animal pueda vivir
        void set_espacio_minimo_requerido(string tamanio);

        string get_mensaje_adopcion();

        string get_mensaje_escape();

    public:
        //Pre: -
        //Post: Imprime en pantalla una presentacion de todos los atributos del animal.
        void presentar_animal();

        virtual void pasar_el_tiempo(int* animales_escapados) = 0;

        virtual void comer() = 0;

        //Post Si el metodo ducharse() no está implementada dentro de una clase hija, esta arrojara un error especificando que esa especie de animal no necesita duchas
        virtual void ducharse();

        //Destructor
        virtual ~Animal() = default;

        //Post Devuelve el nombre del animal
        string get_nombre();

        //Post Devuelve la edad del animal
        int get_edad();

        //Post Devuelve el tamaño del animal
        string get_tamanio();

        //Post Devuelve la inicial de la especie del animal
        char get_especie();

        //Post Devuelve la personalidad del animal
        string get_personalidad();

        //Post Devuelve el espacio minimo requerido para que el animal pueda vivir
        int get_espacio_minimo_requerido();

        //post Devuelve true si el animal fue eliminado, caso contrario false
        bool esta_eliminado();

        //post Setea el atributo eliminado en true
        void eliminar();

        //post Devuelve true si el animal se escapo, caso contrario false
        bool se_escapo();

        //POST setea el nombre del animal
        void set_nombre(string nombre);

        //Pre: -
        //Post: Devuelve la especie del animal en forma completa.
        string get_especie_completa();
};

#endif
