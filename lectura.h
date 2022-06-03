#ifndef LECTURA_H_INCLUDED
#define LECTURA_H_INCLUDED
#include "escritor.h"

// #include "string.h"
class Lectura{
protected:
    std::string titulo;
    int minutos;
    int anio_publicacion;
    Escritor* escritor;
    char tipo_lectura;
public:
    //Construye una lectura.
    Lectura(char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, Escritor* escritor);
    /*
    PRE: - 
    POST: Devuelve el tipo de la lectura(C si es cuento, N si es novela y P si es poema). 
    */
    char obtener_tipo_lectura();
    virtual ~Lectura(){};
    /*
    PRE: - 
    POST: Devuelve el escritor de la lectura. 
    */
    Escritor* obtener_escritor();
    /*
    PRE: - 
    POST: Devuelve el año de publicación de la lectura. 
    */
    int obtener_anio_publicacion();
    /*
    PRE: - 
    POST: Devuelve el título de la lectura. 
    */
    string obtener_titulo();
    /*
    PRE: - 
    POST: Devuelve la duración de la lectura. 
    */
    int obtener_tiempo_lectura();
    virtual void mostrar() = 0;
    virtual string obtener_genero() = 0;
};

#endif
