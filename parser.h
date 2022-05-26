#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "lectura.h"
#include "escritor.h"
// #include "lista_escritores.h"
// #include "lista_lecturas.h"
#include <iostream>
#include <string>
using namespace std;

class Parser {
private:
    string tipo_lectura;
    string nombre_completo;
    string nacionalidad;
    string referencia;
    int anio_nacimiento;
    int anio_fallecimiento;
    // Lista_Escritores escritores;
    // Lista_Lecturas lecturas;


public:
    Parser(string nombre_completo, string nacionalidad, int anio_nacimiento, int anio_fallecimiento, string referencia);
    ~Parser(){};
    void procesar_escritores();
    void procesar_lectura();
    void procesar_opciones(int opcion);
    int mostrar_menu();
};




#endif