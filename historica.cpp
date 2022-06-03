#include <iostream>
#include "historica.h"
#include "string.h"

Historica::Historica(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion, Escritor* escritor,int genero, std::string tema) 
    : Novela( tipo_lectura, titulo, minutos, anio_publicacion, escritor, genero){
        this->tema= tema;
}

void Historica::mostrar(){
    std::cout<< "El tipo de lectura es: "<< tipo_lectura<< std::endl;
    std::cout<< "El título es: "<< titulo<< std::endl;
    std::cout<< "La lectura tiene una duración de : "<< minutos << " minutos"<< std::endl;
    std::cout<< "La lectura fue publicada en el año: "<< anio_publicacion << std::endl;
    std::cout<< "El escritor es: " << escritor->obtener_nombre_completo() << std::endl;
    std::cout<< "El género es: "<< convertir_genero(genero) << std::endl;
    std::cout<< "El tema es: "<< tema<< std::endl;
    std::cout<<"\n";
}

string Historica::convertir_genero(int genero){
    string genero_historica;
    if(genero == HISTORICA){
        genero_historica = "HISTORICA";
    }
    return genero_historica;
}