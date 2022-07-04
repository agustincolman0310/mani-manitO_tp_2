#include <fstream>
#include <iostream>
#include "../header/escritor.h"
using namespace std;

Escritor::Escritor(string nombre_completo, string nacionalidad, int anio_nacimiento, int anio_fallecimiento, string referencia){
    this->nombre_completo = nombre_completo;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
    this->referencia = referencia;
}

void Escritor::mostrar_atributos(){
    cout << "🔢 N° referencia: " << this->referencia << endl;
    cout << "🏷️  Nombre completo: " << this->nombre_completo << endl;
    if (this->nacionalidad == NACIONALIDAD_DESCONOCIDA){
        cout << "🌎 Nacionalidad: Desconocida " << endl;
    }
    else{
        cout << "🌎 Nacionalidad: " << this->nacionalidad << endl;
    }
    if (this->anio_nacimiento == ANIO_DESCONOCIDO){
        cout << "📅 Año nacimiento: Desconocido" << endl;
    }
    else{
        cout << "📅 Año nacimiento: " << this->anio_nacimiento << endl;
    }
    if (this->anio_fallecimiento == ANIO_DESCONOCIDO){
        cout << "🪦 Año fallecimiento: Desconocido" << endl;
    }
    else{
        cout << "🪦 Año fallecimiento: " << this->anio_fallecimiento << endl;
    }
    cout << "\n";
}

int Escritor::obtener_anio_nacimiento(){
    return anio_nacimiento;
}

string Escritor::obtener_nombre_completo(){
    return nombre_completo;
}

void Escritor::modificar_anio_fallecimiento(int anio_nuevo){
    anio_fallecimiento = anio_nuevo;
}

string Escritor::obtener_referencia(){
    return referencia;
}

void Escritor::mostrar_referencia(){
    cout << endl;
    cout << "🔢 " << CYAN << "Refencia: " << BLANCO << referencia << endl;
    cout << "🖊️  " << AZUL << "Autor: " << BLANCO << nombre_completo << endl;
    cout << endl;
}