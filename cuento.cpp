#include <iostream>
#include "cuento.h"


Cuento::Cuento(std::string titulo, int minutos, int anio_publicacion, Escritor escritor, char tipo_lectura, std::string libro)
    :Lectura(titulo, minutos, anio_publicacion, escritor, tipo_lectura){
        this->libro = libro;
}

void Cuento::mostrar(){
    std::cout<< "El titulo es: "<< titulo<< std::endl;
    std::cout<< "La lectura lleva: "<< minutos << " minutos"<< std::endl;
    std::cout<< "La lectura fue publicada en: "<< anio_publicacion << std::endl;
    // std::cout<< "El escritor es: " << escritor<< std::endl;
    std::cout<< "El tipo de lectura es: "<< tipo_lectura<< std::endl;
    std::cout<< "El poema se encuentra en el libro: "<< libro<< std::endl;
}