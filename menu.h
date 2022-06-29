#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "lista_escritores.h"
#include "lista_lecturas.h"
#include "tabla_hashing.h"
#include <iostream>
#include <string>
#include "cuento.h"
#include "novela.h"
#include "poema.h"
#include "historica.h"
#include "constantes.h"
#include "cola.h"
#include "main_kruskal.h"

class Menu{
private:
    Tabla_Hashing escritores;
    Lista_Lecturas lecturas;
    Cola cola;
    /*
    PRE: El título que desea ingresarse, no debe existir en la lista de Lecturas y el Escritor
    debe existir en la lista de Escritores.
    POST: Inserta de manera ordenada la nueva lectura en la lista de Lecturas.
    */
    void agregar_lectura();
    /*
    PRE: El título ingresado, debe existir en la lista de Lecturas.
    POST: Da de la lectura que coincide con el título ingresado.
    */
    void eliminar_lectura();
    /*
    PRE: El Escritor que se desea dar de alta, no debe estar en la lista de Escritores.
    POST: Inserta el nuevo Escritor en el final la lista de Escritores.
    */
    void agregar_escritor(string &nombre_completo);
    /*
    PRE: El nombre del Escritor al que se le desea modificar el dato, debe existir en la lista de Escritores.
    POST: Modifica el dato del Escritor.
    */
    void cambiar_dato_escritor();
    /*
    PRE: La lista de Escritores debe estar cargada.
    POST: Muestra por pantalla todos los Escritores que hay hasta el momento.
    */
    void imprimir_escritores();
    /*
    PRE: La lista de Lecturas debe estar cargada.
    POST: Imprime por pantalla una lectura de manera aleatoria.
    */
    void sortear_lectura_random();
    /*
    PRE: -
    POST: Muestra por pantalla todas las Lecturas que hay hasta el momento.
    */
    void imprimir_lecturas();
    /*
    PRE: El año 1 debe ser menos al año 2.
    POST: Imprime por pantalla las lecturas que esten entre dos años ingresados.
    */
    void listar_entre_anios();
    /*
    PRE: El escritor debe estar en la lista de escritores.
    POST: Imprime por pantalla las lecturas que sean del escritor ingresado.
    */
    void listar_por_escritor();
    /*
    PRE: El genero debe ser uno de los estipulados por el enum de generos.
    POST: Imprime por pantalla las lecturas que tengan el genero ingresado.
    */
    void listar_por_genero();
    /*
    PRE: La cola tiene que estar cargada.
    POST: Elimina el primer elemento de la cola.
    */
    void baja_cola();
    /*
    PRE: La cola debe contener algun elemento.
    POST: Imprime por pantalla la cola de lecturas.
    */
    void mostrar_cola();
    /*
    PRE: -
    POST: Imprime por pantalla el recorrido minimo por Kruskal.
    */
    void mostrar_tiempo_minimo();

    void eliminar_escritor();
    
public:
    // Constructor
    Menu(Lista_Lecturas lecturas, Tabla_Hashing escritores);
    /*
    PRE: opcion debe ser un número entre 1 y 13.
    POST: Dependiendo de la opción elegida, hace una cosa u otra.
    */
    void procesar_opciones(int opcion);
    /*
    PRE: -
    POST: Se encarga de liberar la memoria utilizada por las listas.
    */
    void vaciar_listas();
    /*
    PRE: -
    POST: Muestra el menu por pantalla y retorna la opcion que eligio el usuario.
    */
    int mostrar_menu();
    /*
    PRE: -
    POST: Carga los elementos de la lista de Lecturas(ordenado por tiempo de lectura) en la Cola..
    */
    void cargar_cola();
};

#endif