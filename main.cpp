#include <iostream>
#include "parser.h"
#include "menu.h"
#include <cstdlib>
#include "time.h"
#include "constantes.h"

using namespace std;
int main() {
    
    Parser parser;
    parser.procesar_escritores();
    parser.procesar_lectura();
 
    Menu menu(parser.devolver_lecturas(),parser.devolver_escritores());
    menu.cargar_cola();

    int opcion_recibida;

    while(opcion_recibida != OPCION_13){
        opcion_recibida = menu.mostrar_menu();
        menu.procesar_opciones(opcion_recibida);
    }

    menu.vaciar_listas();


    return 0;
}
