#include <iostream>
#include "../header/cuento.h"

Cuento::Cuento(char tipo_lectura, string titulo, int minutos, int anio_publicacion, Escritor *escritor, string libro)
    : Lectura(tipo_lectura, titulo, minutos, anio_publicacion, escritor){
    this->libro = libro;
}

void Cuento::mostrar(){
    cout << "š El tipo de lectura es: "<< MAGENTA<<tipo_lectura<<BLANCO<< endl;
    cout << "š El titulo es: " << titulo << endl;
    cout << "ā³ La lectura tiene una duracion de: " << VERDE << minutos << BLANCO << " minutos" << endl;
    cout << "š La lectura fue publicada en el aĆ±o: " << AZUL << anio_publicacion << BLANCO << endl;
    if(escritor != nullptr){
        cout<< "šļø  El escritor es: " << escritor->obtener_nombre_completo() << endl;
    }else{
        cout << "šļø  El escritor es: ANONIMO" << endl;
    }
    cout << "š El Cuento se encuentra en el libro: " << libro << endl;
    cout << "\n";
}

string Cuento::obtener_atributo_diferente(){
    return libro;
}