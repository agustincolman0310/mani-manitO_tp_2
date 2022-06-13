#ifndef CUENTO_H_INCLUDED
#define CUENTO_H_INCLUDED

#include "lectura.h"
 
class Cuento : public Lectura{
private:
    std::string libro;
public:
    // Constructor
    Cuento(char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, Escritor* escritor, std::string libro);
    /*
    Constructor
    PRE: -
    POST: Muestra los atributos del cuento.
    */
    void mostrar();
    /*
    Constructor
    PRE: -
    POST: Obtiene el genero del cuento.
    */
    string obtener_atributo_diferente();
};

#endif