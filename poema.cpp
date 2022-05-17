#include <iostream>
#include "poema.h"


Poema::Poema(std::string titulo, int minutos, int anio_publicacion, int referencia, char tipo_lectura, int cant_versos)
    :Lectura(titulo, minutos, anio_publicacion, referencia, tipo_lectura ){
        this->cant_versos = cant_versos;
}

void Poema::mostrar(){
    std::cout<< "El titulo es: "<< titulo<< std::endl;
    std::cout<< "La lectura lleva: "<< minutos << " minutos"<< std::endl;
    std::cout<< "La lectura fue publicada en: "<< anio_publicacion << std::endl;
    // std::cout<< "El escritor es: " << escritor<< std::endl;
    std::cout<< "El tipo de lectura es: "<< tipo_lectura<< std::endl;
    std::cout<< "El poema tiene: "<< cant_versos<< " versos"<< std::endl;
}