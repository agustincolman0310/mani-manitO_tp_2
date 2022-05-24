#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED
#include "escritor.h"

// #include "string.h"
class Lectura{
protected:
    std::string titulo;
    int minutos;
    int anio_publicacion;
    std::string referencia;
    char tipo_lectura;
public:
    Lectura(char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, std::string referencia);
    char obtener_tipo_lectura();
    ~Lectura(){};
    int obtener_anio_publicacion();
    string Lectura::obtener_titulo();
    virtual void mostrar() = 0;
};

#endif
