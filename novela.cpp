#include <iostream>
#include "novela.h"
#include "string.h"


Novela::Novela(std::string titulo,int minutos, int anio_publicacion,Escritor escritor, char tipo_lectura, int genero)
    :Lectura(titulo,minutos, anio_publicacion,escritor, tipo_lectura){
        this->genero = genero;
}