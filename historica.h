#ifndef HISTORICA_H_INCLUDED
#define HISTORICA_H_INCLUDED
#include "novela.h"

class Historica : public Novela{
private:
    std::string tema;
public:
    Historica(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion, std::string referencia, std::string genero, std::string tema);
    ~Historica(){};
    void mostrar();
};

#endif