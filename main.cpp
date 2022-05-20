#include <iostream>
#include "escritor.h"
#include "parser.h"
using namespace std;
int main() {

    Parser* parser;
    parser = nullptr;
    parser->procesar_lectura();
    // Escritor* escritor = parser->procesar_escritores();
    //escritor = new Escritor;
    // mostrar_menu();
    //cargar_escritores(escritor);
    

    return 0;
}
//  Parser parser = Parser(argv);
//  Vehiculo* vehiculo = parser.procesarEntrada();