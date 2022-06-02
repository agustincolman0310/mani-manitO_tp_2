#ifndef LISTA_LECTURAS_H_INCLUDED
#define LISTA_LECTURAS_H_INCLUDED

#include "lectura.h"
#include "nodo.h"
#include "constantes.h"


typedef Lectura* T;


class Lista_Lecturas{
    // Atributos
private:
    Nodo<T>* primero;
    int cantidad;
    Nodo<T>* actual;
    Nodo<T>* ultimo;
    Nodo<T>* obtener_nodo(int pos);
    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye una Lista vacia
    */
    Lista_Lecturas();
    void listar_lecturas();

    /*
    Baja
    PRE: 1 <= pos <= obtener_cantidad()
    POS: da de baja al elemento que esta en pos, se empieza por 1
    */
    // void baja(int pos);

    /*
    Consulta
    PRE: 1 <= pos <= obtener_cantidad()
    POS: devuelve el elemento que esta en pos, se empieza por 1
    */
    // T consulta(int pos);

    /*
    Vacia
    PRE: -
    POS: devuelve true si la Lista esta vacia, false de lo contrario
    */
    bool vacia();
    void baja(string titulo);
    void baja(int pos);
    void vaciar_lista();
    void mostrar_lectura(T lectura);

    int obtener_cantidad();

    void insertar_ordenadamente(T dato);
    int buscar_titulo(string titulo_buscado);
    Nodo<T>* obtener_primero();
    // Nodo<T>* obtener_nodo(int pos);
    void sortear_lectura(int numero);
    void alta(T dato);
    void listar_por_escritor(string nombre_completo);
    void listar_entre_anios(int desde, int hasta);
    void eliminar_por_titulo(string titulo);
    void eliminar_por_dato(string titulo);
    // Destructor
    void listar_por_genero(string genero_recibido);
    void agregar_final(T dato);
    T encontrar_lectura_menor(int &minimo);
    int procesar_genero(string genero);
    // ~Lista_Lecturas();
    int comparar(T dato);
    
    
    void ordenar(T objeto);
};

// template <typename T>

#endif
