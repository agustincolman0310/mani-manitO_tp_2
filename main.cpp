#include <iostream>
#include "archivos.h"
#include "escritor.h"
int main() {

    Escritor* escritor;
    escritor = new Escritor;
    // mostrar_menu();
    cargar_escritores(escritor);
    

    return 0;
}
