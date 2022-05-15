#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED
#include "escritor.h"
// #include "string.h"
class Lectura{
protected:
    std::string titulo;
    int minutos;
    int anio_publicacion;
    Escritor escritor;
    char tipo_lectura;
public:
    Lectura(std::string titulo, int minutos, int anio_publicacion, Escritor escritor, char tipo_lectura);
    ~Lectura(){};
    virtual void mostrar() = 0;
};

#endif
