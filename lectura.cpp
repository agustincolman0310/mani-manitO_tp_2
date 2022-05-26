#include <iostream>
#include "lectura.h"

Lectura::Lectura( char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, Escritor* escritor){
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
        std::cout<< "El autor es: "<< escritor->obtener_nombre_completo() << std::endl;
}

int Lectura::obtener_anio_publicacion(){
            return this->anio_publicacion;
}

string Lectura::obtener_titulo(){
        return titulo;
}