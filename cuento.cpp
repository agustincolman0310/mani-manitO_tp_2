#include <iostream>
#include "cuento.h"

Cuento::Cuento(char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, Escritor* escritor, std::string libro)
    :Lectura(tipo_lectura, titulo, minutos, anio_publicacion, escritor){
        this->libro = libro;
}

void Cuento::mostrar(){
    std::cout<< "El tipo de lectura es: "<< tipo_lectura<< std::endl;
    std::cout<< "El titulo es: "<< titulo<< std::endl;
    std::cout<< "La lectura lleva: "<< minutos << " minutos"<< std::endl;
    std::cout<< "La lectura fue publicada en: "<< anio_publicacion << std::endl;
    std::cout<< "El escritor es: " << escritor->obtener_nombre_completo() << std::endl;
    std::cout<< "El poema se encuentra en el libro: "<< libro<< std::endl;
    std::cout<<"\n";

}