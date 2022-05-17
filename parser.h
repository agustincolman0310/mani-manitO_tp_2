#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "lectura.h"
#include <string>
#include <iostream>

class Parser {
private:
    std::string tipo_lectura() const;
    std::string nombre_completo;
    std::string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;
    int referencia;


public:
    Parser(int numero_seleccionado);
    ~Parser(){};
    Escritor procesar_escritores() const;
    Lectura* procesar_lectura() const;
};






#endif