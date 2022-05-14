#include <iostream>
#include "novela.h"
#include "string.h"


Lectura::Lectura(std::string titulo,int minutos, int anio_publicacion,Escritor escritor, char tipo_lectura){
        this->titulo = titulo;
        this->minutos = minutos;
        this->anio_publicacion = anio_publicacion;
        this->escritor = escritor;
        this->tipo_lectura = tipo_lectura;
}
