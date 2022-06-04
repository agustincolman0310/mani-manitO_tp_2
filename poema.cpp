#include <iostream>
#include "poema.h"

Poema::Poema(char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, Escritor* escritor, int cant_versos)
    :Lectura(tipo_lectura, titulo, minutos, anio_publicacion, escritor){
        this->cant_versos = cant_versos;
}

void Poema::mostrar(){
    std::cout<< "El tipo de lectura es: "<< tipo_lectura<< std::endl;
    std::cout<< "El titulo es: "<< titulo<< std::endl;
    std::cout<< "La lectura tiene una duracion de: "<< minutos << " minutos"<< std::endl;
    std::cout<< "La lectura fue publicada en: "<< anio_publicacion << std::endl;
    std::cout<< "El escritor es: " << escritor->obtener_nombre_completo() << std::endl;
    std::cout<< "El Poema tiene: "<< cant_versos<< " versos"<< std::endl;
    std::cout<<"\n";
}

string Poema::obtener_genero(){
    return to_string(cant_versos);
}