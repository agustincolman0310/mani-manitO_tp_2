#include <iostream>
#include "parser.h"
#include "menu.h"
#include <cstdlib>
#include "time.h"
#include "constantes.h"
#include "grafo.h"
#include "main_kruskal.h"
using namespace std;

int main() {
    Parser parser;
    parser.procesar_escritores();
    parser.procesar_lectura();
    // Main_Kruskal kruskal(parser.devolver_lecturas());
    // parser.devolver_escritores().mostrar_escritores();

    Menu menu(parser.devolver_lecturas(),parser.devolver_escritores());
    // menu.cargar_cola();
    // kruskal.ejecutar_kruskal();
    // parser.devolver_lecturas().vaciar_lista();
    // parser.devolver_escritores().vaciar_lista();
    int opcion_recibida;
    
    while(opcion_recibida != OPCION_15){
        opcion_recibida = menu.mostrar_menu();
        menu.procesar_opciones(opcion_recibida);
    }
    
    menu.vaciar_listas();


    return 0;
}
