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
    // system("clear");
    Parser parser;
    parser.procesar_escritores();
    parser.procesar_lectura();
    // Main_Kruskal kruskal(parser.devolver_lecturas());
    // parser.devolver_escritores().mostrar_escritores();

    Menu menu(parser.devolver_lecturas(),parser.devolver_escritores());
    int opcion_recibida;
    
    while(opcion_recibida != OPCION_14){
        opcion_recibida = menu.mostrar_menu();
        // if(opcion_recibida == OPCION_11){
        //     menu.cargar_cola();
        // }
        menu.procesar_opciones(opcion_recibida);
        // system("clear");
    }
    
    menu.vaciar_listas();


    return 0;
}
