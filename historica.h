#ifndef HISTORICA_H_INCLUDED
#define HISTORICA_H_INCLUDED
#include "novela.h"

class Historica : public Novela{
private:
    std::string tema;
public:
    // Constructor.
    Historica(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion, Escritor* escritor, int genero, std::string tema);
    // Destructor.
    ~Historica(){};
    /*
    PRE: -
    POST: Muestra los atributos de la Novela historica.
    */
    void mostrar();
    /*
    PRE: genero tiene que ser un numero mayor a 0 y debe estar en el enum.
    POST: Transforma el genero recibido en un string.
    */
    string convertir_genero(int genero);
};

#endif