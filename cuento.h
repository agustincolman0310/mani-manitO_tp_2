#ifndef CUENTO_H_INCLUDED
#define CUENTO_H_INCLUDED

#include "lectura.h"
 
class Cuento : public Lectura{
private:
    std::string libro;
public:
    Cuento(std::string titulo, int minutos, int anio_publicacion, int referencia, char tipo_lectura, std::string libro);
    ~Cuento(){};
    void mostrar();
};

#endif