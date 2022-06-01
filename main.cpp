#include <iostream>
#include "escritor.h"
#include "parser.h"
#include "menu.h"
#include <cstdlib>
#include "time.h"
using namespace std;
int main() {
    // srand((unsigned int)time(NULL));
    // int random = rand() % 20;
    // cout<<"El numero sorteado es... "<<random<<endl;
    Parser* parser;
    Menu* menu;
    int opcion_recibida;
    parser = nullptr;
    parser->procesar_escritores();
    parser->procesar_lectura();
    //escritor = new Escritor;
   
    opcion_recibida = menu->mostrar_menu();

    // cargar_escritores(escritor);
    while(!menu->salir()){
        menu->procesar_opciones(opcion_recibida);
    }
}
//  Parser parser = Parser(argv);
//  Vehiculo* vehiculo = parser.procesarEntrada();