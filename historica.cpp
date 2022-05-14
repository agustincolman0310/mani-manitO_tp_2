#include <iostream>
#include "novela.h"
#include "string.h"


Historica::Historica(std::string titulo,int minutos, int anio_publicacion,Escritor escritor, char tipo_lectura, int genero, char* tema)
    :Novela(titulo, minutos, anio_publicacion, escritor, tipo_lectura, genero){
        this->tema= tema;
}
