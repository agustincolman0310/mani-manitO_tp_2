#include <iostream>
#include "parser.h"
#include "menu.h"
#include <cstdlib>
#include "time.h"
#include "constantes.h"

using namespace std;
int main() {
    //cout<<"Vamos a procesar archivos"<<endl;
    Parser parser;
    // parser = nullptr;
    parser.procesar_escritores();
    //cout << "Procesar escritores" << endl;

    parser.procesar_lectura();
    //cout << "Procesar lecturas" << endl;
    
    //escritor = new Escritor;
    // cout<< "2" <<endl;
    Menu menu(parser.devolver_lecturas(),parser.devolver_escritores());
    int opcion_recibida;

    // cargar_escritores(escritor);
    //menu.procesar_opciones(opcion_recibida);
    while(opcion_recibida != OPCION_12){
        opcion_recibida = menu.mostrar_menu();
        menu.procesar_opciones(opcion_recibida);
     }
    menu.vaciar_listas();
    return 0;
}
