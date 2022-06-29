#include <iostream>
#include "cuento.h"

Cuento::Cuento(char tipo_lectura, string titulo, int minutos, int anio_publicacion, Escritor *escritor, string libro)
    : Lectura(tipo_lectura, titulo, minutos, anio_publicacion, escritor){
    this->libro = libro;
}

void Cuento::mostrar(){
    cout << "El tipo de lectura es: " << tipo_lectura << endl;
    cout << "El titulo es: " << titulo << endl;
    cout << "La lectura tiene una duracion de: " << minutos << " minutos" << endl;
    cout << "La lectura fue publicada en: " << anio_publicacion << endl;
    if(escritor != NULL){
        cout<< "El escritor es: " << escritor->obtener_nombre_completo() << endl;
    }else{
        escritor->modificar_nombre();
        cout << "El escritor es: ANONIMO" << endl;
    }
    cout << "El Cuento se encuentra en el libro: " << libro << endl;
    cout << "\n";
}

string Cuento::obtener_atributo_diferente(){
    return libro;
}

void Cuento::modificar_referencia(){
    escritor = NULL;
}
