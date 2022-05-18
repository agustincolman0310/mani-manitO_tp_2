#include "parser.h"
using namespace std;

Parser::Parser(std::string nombre_completo, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int referencia) {
    
    this->nombre_completo = nombre_completo;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
    this->referencia = referencia;

}

