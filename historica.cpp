#include <iostream>
#include "historica.h"
#include "string.h"

Historica::Historica(char tipo_lectura, string titulo, int minutos, int anio_publicacion, Escritor *escritor, int genero, char* tema)
    : Novela(tipo_lectura, titulo, minutos, anio_publicacion, escritor, genero){
    this->tema = tema;
}

void Historica::mostrar(){
    cout << "El tipo de lectura es: " << tipo_lectura << endl;
    cout << "El título es: " << titulo << endl;
    cout << "La lectura tiene una duración de : " << minutos << " minutos" << endl;
    cout << "La lectura fue publicada en el año: " << anio_publicacion << endl;
    cout << "El escritor es: " << escritor->obtener_nombre_completo() << endl;
    cout << "El género es: " << convertir_genero(genero) << endl;
    cout << "El tema es: " << tema << endl;
    cout << "\n";
}

string Historica::convertir_genero(int genero){
    string genero_historica;
    if (genero == HISTORICA){
        genero_historica = "HISTORICA";
    }
    return genero_historica;
}