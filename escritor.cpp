#include <fstream>
#include <iostream>
#include "escritor.h"
using namespace std;

void Escritor::obtener_nombre_completo(string _nombre_completo){
    this->nombre_completo = _nombre_completo;
}
string Escritor::devolver_nombre_completo(){
    return nombre_completo;
}
void Escritor::obtener_nacionalidad(string _nacionalidad){
    this->nacionalidad = _nacionalidad;
}
string Escritor::devolver_nacionalidad(){
    return nacionalidad;
}
void Escritor::obtener_anio_nacimiento(int _anio_nacimiento){
    this->anio_nacimiento = _anio_nacimiento;
}
int Escritor::devolver_anio_nacimiento(){
    return anio_nacimiento;
}
void Escritor::obtener_anio_fallecimiento(int _anio_fallecimiento){
    this->anio_fallecimiento = _anio_fallecimiento;
}    
int Escritor::devolver_anio_fallecimiento(){
    return anio_fallecimiento;
}
void Escritor::obtener_referencia(string referencia){
    this->referencia = referencia;
}
string Escritor::devolver_referencia(){
    return referencia;
}

