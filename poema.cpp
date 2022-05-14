#include <iostream>
#include "poema.h"
#include "string.h"

Poema::Poema(std::string titulo,int minutos, int anio_publicacion,Escritor escritor, char tipo_lectura, intcant_versos)
    :Novela(titulo,minutos, anio_publicacion,escritor, tipo_lectura, genero ){
        this->cant_versos = cant_versos;
}