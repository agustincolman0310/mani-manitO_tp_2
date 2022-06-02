#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
// #include "lectura.h"
// #include "escritor.h"
#include "lista_escritores.h"
#include "lista_lecturas.h"
#include <iostream>
#include <string>
#include "cuento.h"
#include "novela.h"
#include "poema.h"
#include "historica.h"
#include "constantes.h"
#include "cola.h"
// #include "parser.h"

class Menu{
private:
    bool seguir_jugando;
    Lista_Escritores escritores;
    Lista_Lecturas lecturas;
    Cola cola;
    void agregar_lectura();
    void eliminar_lectura();
    void agregar_escritor(string &nombre_completo);
    void cambiar_dato_escritor();
    void imprimir_escritores();
    void lectura_random();
    void imprimir_lecturas();
    void listar_entre_anios();
    void listar_por_escritor();
    void listar_por_genero();
    void cola_ordenada();
    // void vaciar_listas();
    //bool salir();
    //void procesar_opciones(int opcion);
    
public:
    Menu(Lista_Lecturas lecturas, Lista_Escritores escritores);
    void procesar_opciones(int opcion);
    void vaciar_listas();
    // ~Menu(){};
    int mostrar_menu();
    bool salir();
    
};



#endif