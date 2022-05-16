#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "lectura.h"
#include <string>
#include <iostream>

class Parser {
private:
   std::string tipo_lectura() const;


public:
    Parser(int numero_seleccionado);
    ~Parser(){};
    Escritor* procesar_escritores() const;
    Lectura* procesar_lectura() const;
};






#endif