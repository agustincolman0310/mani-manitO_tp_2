#include <iostream>
#include "../header/poema.h"

Poema::Poema(char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, Escritor* escritor, int cant_versos)
    :Lectura(tipo_lectura, titulo, minutos, anio_publicacion, escritor){
        this->cant_versos = cant_versos;
}

void Poema::mostrar(){
    cout << "š El tipo de lectura es: "<< MAGENTA<<tipo_lectura<<BLANCO<< endl;
    cout << "š El titulo es: " << titulo << endl;
    cout << "ā³ La lectura tiene una duracion de: " << VERDE << minutos << BLANCO << " minutos" << endl;
    cout << "š La lectura fue publicada en el aĆ±o: " << AZUL << anio_publicacion << BLANCO << endl;
    if(escritor != nullptr){
        cout<< "šļø  El escritor es: " << escritor->obtener_nombre_completo() << endl;
    }else{
        cout << "šļø  El escritor es: ANONIMO" << endl;
    }
    cout<< "š El Poema tiene: "<< cant_versos<< " versos"<< endl;
    cout<<"\n";
}

string Poema::obtener_atributo_diferente(){
    return to_string(cant_versos);
}

