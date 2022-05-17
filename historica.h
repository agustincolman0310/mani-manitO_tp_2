#ifndef HISTORICA_H_INCLUDED
#define HISTORICA_H_INCLUDED
#include "novela.h"

class Historica : public Novela{
private:
    char* tema;
public:
    Historica(std::string titulo,int minutos, int anio_publicacion,int referencia, char tipo_lectura, int genero, char* tema);
    ~Historica(){};
    void mostrar();
};

#endif