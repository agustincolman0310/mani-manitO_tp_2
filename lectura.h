#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED
#include "escritor.h"

// #include "string.h"
class Lectura{
protected:
    std::string titulo;
    int minutos;
    int anio_publicacion;
    string escritor;
    char tipo_lectura;
public:
    Lectura(char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, string escritor);
    char obtener_tipo_lectura();
    ~Lectura(){};
    string obtener_escritor();
    int obtener_anio_publicacion();
    string obtener_titulo();
    int obtener_tiempo_lectura();
    virtual void mostrar() = 0;
    virtual string obtener_genero() = 0;
};

#endif
