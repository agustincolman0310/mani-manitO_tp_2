#include <iostream>
#include "lectura.h"

Lectura::Lectura(char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, Escritor *escritor){
        this->titulo = titulo;
        this->minutos = minutos;
        this->anio_publicacion = anio_publicacion;
        this->escritor = escritor;
        this->tipo_lectura = tipo_lectura;
}

int Lectura::obtener_anio_publicacion(){
        return this->anio_publicacion;
}

string Lectura::obtener_titulo(){
        return titulo;
}

Escritor *Lectura::obtener_escritor(){
        return escritor;
}

char Lectura::obtener_tipo_lectura(){
        return tipo_lectura;
}

int Lectura::obtener_tiempo_lectura(){
        return minutos;
}

void Lectura::modificar_escritor(){
        // escritor->modificar_escritor();

        escritor = nullptr;
        // cout << "El escritor apunta  a NULL" << endl;
}
