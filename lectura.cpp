#include <iostream>
#include "lectura.h"

Lectura::Lectura(std::string titulo,int minutos, int anio_publicacion, Escritor escritor, char tipo_lectura){
        this->titulo = titulo;
        this->minutos = minutos;
        this->anio_publicacion = anio_publicacion;
        this->escritor = escritor;
        this->tipo_lectura = tipo_lectura;
}

void Lectura::mostrar(){
        std::cout<< "El titulo es: "<< titulo<< std::endl;
        std::cout<< "La lectura lleva: "<< minutos << " minutos"<< std::endl;
        std::cout<< "La lectura fue publicada en: "<< anio_publicacion << std::endl;
        // std::cout<< "El escritor es: " << escritor<< std::endl;
        std::cout<< "El tipo de lectura es: "<< tipo_lectura<< std::endl;
}