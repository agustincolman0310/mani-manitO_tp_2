#include <iostream>
#include "novela.h"
#include "string.h"


Novela::Novela(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion, std::string referencia, std::string genero)
    :Lectura(tipo_lectura, titulo, minutos, anio_publicacion, referencia){
        this->genero = genero;
}

void Novela::mostrar(){
    std::cout<< "El tipo de lectura es: "<< tipo_lectura<< std::endl;
    std::cout<< "El titulo es: "<< titulo<< std::endl;
    std::cout<< "La lectura lleva: "<< minutos << " minutos"<< std::endl;
    std::cout<< "La lectura fue publicada en: "<< anio_publicacion << std::endl;
    // std::cout<< "El escritor es: " << escritor<< std::endl;
    std::cout<< "El genero es: "<< genero<< std::endl;
    std::cout<<"\n";

}