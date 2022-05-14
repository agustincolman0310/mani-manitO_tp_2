#include <iostream>
#include "escritor.h"
#include "string.h"

Escritor::Escritor(std::string nombre, std::string apellido, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int referencia){
    this->nombre = nombre;
    this->apellido = apellido;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
    this->referencia = referencia;
}


