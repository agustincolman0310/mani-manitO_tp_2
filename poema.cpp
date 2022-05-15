#include <iostream>
#include "poema.h"


Poema::Poema(std::string titulo,int minutos, int anio_publicacion,Escritor escritor, char tipo_lectura, int cant_versos)
    :Lectura(titulo,minutos, anio_publicacion,escritor, tipo_lectura ){
        this->cant_versos = cant_versos;
}