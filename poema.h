#ifndef POEMA_H_INCLUDED
#define POEMA_H_INCLUDED
#include "lectura.h"

class Poema : public Lectura{
private:
    int cant_versos;
public:
    // Construye un poema.
    Poema(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion, Escritor* escritor, int cant_versos);
    /*
    PRE: - 
    POST: Muestra los atributos del poema. 
    */ 
    void mostrar();
    /*
    PRE: - 
    POST: Devuelve la cantidad de versos que tiene el poema, en forma de string. 
    */
    string obtener_atributo_diferente();

    void modificar_referencia();
};

#endif