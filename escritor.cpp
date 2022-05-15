#include <iostream>
#include "escritor.h"
#include "string.h"

Escritor::Escritor(std::string nombre, std::string apellido, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int referencia){
    this->nombre = nombre;
    this->apellido = apellido;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
    this->referencia = referencia;
}

std::string Escritor::obtener_nombre(){
    return nombre;
}
std::string Escritor::obtener_apellido(){
    return apellido;
}
std::string Escritor::obtener_nacionalidad(){
    return nacionalidad;
}
int Escritor::obtener_anio_nacimiento(){
    return anio_nacimiento;
}
int Escritor::obtener_anio_falllecimiento(){
    return anio_fallecimiento;
}

Escritor::Escritor(){
    nombre = " ";
    apellido = " ";
    nacionalidad = " ";
    anio_nacimiento = 0;
    anio_fallecimiento = 0;
}
