#include <iostream>
#include <cstdlib>
#include "time.h"
#include "../header/parser.h"
#include "../header/menu.h"
#include "../header/constantes.h"

using namespace std;

int main() {
    //system("clear");
    Parser parser;
    parser.procesar_escritores();
    parser.procesar_lectura();

    Menu menu(parser.devolver_lecturas(),parser.devolver_escritores());

    menu.bienvenida();

    int opcion_recibida;

    do{
        opcion_recibida = menu.mostrar_menu();
        menu.procesar_opciones(opcion_recibida);
    }
    while(opcion_recibida != OPCION_14);
    
    menu.vaciar_listas();

    return 0;
}
