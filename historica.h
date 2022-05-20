#ifndef HISTORICA_H_INCLUDED
#define HISTORICA_H_INCLUDED
#include "novela.h"

class Historica : public Novela{
private:
    char* tema;
public:
    Historica(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion,int referencia, int genero, char* tema);
    ~Historica(){};
    void mostrar();
};

#endif