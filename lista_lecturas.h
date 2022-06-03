#ifndef LISTA_LECTURAS_H_INCLUDED
#define LISTA_LECTURAS_H_INCLUDED

#include "lectura.h"
#include "nodo.h"
#include "constantes.h"
#include "lista.h"
#include "string.h"

class Lista_Lecturas{
    // Atributos
private:
    Nodo<Lectura*>* primero;
    int cantidad;
    Nodo<Lectura*>* actual;
    Nodo<Lectura*>* ultimo;
    Nodo<Lectura*>* obtener_nodo(int pos);
    Lista<Lectura*> lista_lecturas;


public:
    string convertir_en_mayuscula(string cadena);
    /*
    Constructor
    PRE: -
    POST: construye una Lista vacia
    */
    Lista_Lecturas();

    /*
    PRE: La lista no debe estar vacía.
    POST: Muestra el contenido de la lista.
    */
    void listar_lecturas();
    /*
    PRE: -
    POST: Devuelve true si la cantidad de elementos en la lista es igual a 0.
    */
    bool vacia();
    /*
    PRE: La lista no debe estar vacía.
    POST: En caso de existir, elimina la lectura que tiene el título que se pasa.
    */
    void baja(string titulo);
    // void baja(int pos);
    void vaciar_lista();
    // void mostrar_lectura(T lectura);
    /*
    PRE: La lista no debe estar vacía.
    POST: En caso de existir, devuelve la lectura que tiene el título que se pasa;
    de lo contrario, devuelve NULL.
    */
    Lectura* consulta_titulo(string titulo);
    /*
    PRE: La lista debe ser válida.
    POST: Devuelve la cantidad de elementos que tiene la lista.
    */
    int obtener_cantidad();
    /*
    PRE: La lista debe ser válida.
    POST: Devuelve la posición del elemento que tiene el título que se pasa por parámetro.
    */
    int buscar_titulo(string titulo_buscado);
    /*
    PRE: numero deber ser mayor a 0.
    POST: Muestra la lectura que se encuentra en la posición numero.
    */
    void sortear_lectura(int numero);
    /*
    PRE: dato debe ser válido.
    POST: Muestra la lectura que se encuentra en la posición numero.
    */
    void alta(Lectura* dato);
    /*
    PRE: El escritor con nombre_completo debe estar es la lista de escritores.
    POST: Muestra las lecturas que tienen por escritor a nombre_completo.
    */
    void listar_por_escritor(string nombre_completo);
    /*
    PRE: Tanto desde como hasta deben ser números mayores a 0 y hasta debe ser mayor a desde. 
    POST: Muestra las lecturas que tienen fueron publicadas entre esas fechas.
    */
    void listar_entre_anios(int desde, int hasta);
    /*
    PRE: genero_recibido debe ser válido. 
    POST: Muestra las novelas que tienen como genero a genero_recibido.
    */
    void listar_por_genero(string genero_recibido);
    // void agregar_final(T dato);
    Lectura* encontrar_lectura_menor(int &minimo);
    /*
    PRE: - 
    POST: En caso de existir, devuelve el número que tiene genero en el enum de generos, de lo contrario
    devuelve 0.  .
    */
    int procesar_genero(string genero);
    ~Lista_Lecturas(){};
    // int comparar(T dato);
    void baja(int pos);
};

#endif
