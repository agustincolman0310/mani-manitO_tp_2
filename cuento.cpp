#include <iostream>
#include "cuento.h"


Cuento::Cuento(std::string titulo, int minutos, int anio_publicacion, Escritor escritor, char tipo_lectura, std::string libro)
    :Lectura(titulo, minutos, anio_publicacion, escritor, tipo_lectura){
        this->libro = libro;
}
