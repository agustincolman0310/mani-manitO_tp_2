#ifndef CUENTO_H_INCLUDED
#define CUENTO_H_INCLUDED
#include "string.h"

class Cuento : public Lectura{
private:
    std::string libro;
public:
    Cuento(std::string titulo, int minutos, int anio_publicacion, Escritor escritor, char tipo_lectura, std::string libro);
    ~Cuento(){};
    void mostrar();
};


#endif