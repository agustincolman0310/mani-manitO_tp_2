#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "lectura.h"
#include "escritor.h"
#include <string>
#include <iostream>

class Parser {
private:
    string tipo_lectura;
    string nombre_completo;
    string nacionalidad;
    string referencia;
    int anio_nacimiento;
    int anio_fallecimiento;
    


public:
    Parser(int numero_seleccionado);
    ~Parser(){};
    void procesar_escritores(Escritor escritor);
    void procesar_lectura(Lectura lectura);
};






#endif