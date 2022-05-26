#include <iostream>
#include "escritor.h"
#include "parser.h"
#include <cstdlib>
#include  <time.h>
using namespace std;
int main() {
    // srand(time(NULL));
    // int random = rand() % 20;
    // cout<<"El numero sorteado es... "<<random<<endl;
    Parser* parser;
    // int opcion_recibida;
    parser = nullptr;
    parser->procesar_escritores();
    parser->procesar_lectura();
    //escritor = new Escritor;
   
    //opcion_recibida = parser->mostrar_menu();
    // parser->procesar_opciones(opcion_recibida);
    // cargar_escritores(escritor);
    
}
//  Parser parser = Parser(argv);
//  Vehiculo* vehiculo = parser.procesarEntrada();