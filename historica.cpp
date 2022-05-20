#include <iostream>
#include "historica.h"
#include "string.h"

Historica::Historica(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion,int referencia, int genero, char* tema) : Novela( tipo_lectura, titulo, minutos, anio_publicacion, referencia, genero){
        this->tema= tema;
}

void Historica::mostrar(){
    std::cout<< "El titulo es: "<< titulo<< std::endl;
    std::cout<< "La lectura lleva: "<< minutos << " minutos"<< std::endl;
    std::cout<< "La lectura fue publicada en: "<< anio_publicacion << std::endl;
    // std::cout<< "El escritor es: " << escritor<< std::endl;
    std::cout<< "El tipo de lectura es: "<< tipo_lectura<< std::endl;
    std::cout<< "El genero es: "<< genero<< std::endl;
    std::cout<< "El tema es: "<< tema<< std::endl;
}