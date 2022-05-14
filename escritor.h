#ifndef ESCRITOR_H_INCLUDED
#define ESCRITOR_H_INCLUDED

#include "string.h"
class Escritor{
private:
    std::string nombre;
    std::string apellido;
    std::string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;
    int referencia;
public:
    Escritor(std::string nombre, std::string apellido, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int referencia);
    Escritor();
    void mostrar();
};


#endif

