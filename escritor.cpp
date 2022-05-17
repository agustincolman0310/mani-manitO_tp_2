#include <iostream>
#include "escritor.h"
#include "string.h"

Escritor::Escritor(std::string nombre_completo, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int referencia){
    this->nombre_completo = nombre_completo;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
    this->referencia = referencia;
}

std::string Escritor::obtener_nombre_completo(){
    return nombre_completo;
}
std::string Escritor::obtener_nacionalidad(){
    return nacionalidad;
}
int Escritor::obtener_anio_nacimiento(){
    return anio_nacimiento;
}
int Escritor::obtener_anio_fallecimiento(){
    return anio_fallecimiento;
}
int Escritor::obtener_referencia(){
    return referencia;
}
Escritor::Escritor(){
    nombre_completo = " ";
    nacionalidad = " ";
    anio_nacimiento = 0;
    anio_fallecimiento = 0;
}
