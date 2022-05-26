#include "lectura.h"
#ifndef NOVELA_H_INCLUDED
#define NOVELA_H_INCLUDED

class Novela : public Lectura{
protected:
    std::string genero;
public:
    Novela(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion, Escritor* escritor, std::string genero);
    //~Novela(){};
    void mostrar();
};


#endif
