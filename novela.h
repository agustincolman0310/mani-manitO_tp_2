#include "lectura.h"
#ifndef NOVELA_H_INCLUDED
#define NOVELA_H_INCLUDED

class Novela : public Lectura{
protected:
    int genero;
public:
    Novela(std::string titulo,int minutos, int anio_publicacion,int referencia, char tipo_lectura, int genero);
    ~Novela(){};
    void mostrar();
};


#endif
