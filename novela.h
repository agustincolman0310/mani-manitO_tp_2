#include "lectura.h"
#ifndef NOVELA_H_INCLUDED
#define NOVELA_H_INCLUDED

class Novela : public Lectura{
protected:
    int genero;
public:
    Novela(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion,int referencia, int genero);
    ~Novela(){};
    void mostrar();
};


#endif
