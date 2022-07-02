#include <iostream>
#include "poema.h"

Poema::Poema(char tipo_lectura, std::string titulo, int minutos, int anio_publicacion, Escritor* escritor, int cant_versos)
    :Lectura(tipo_lectura, titulo, minutos, anio_publicacion, escritor){
        this->cant_versos = cant_versos;
}

void Poema::mostrar(){
    cout << "☕ El tipo de lectura es: "<< MAGENTA<<tipo_lectura<<BLANCO<< endl;
    cout << "📖 El titulo es: " << titulo << endl;
    cout << "⏳ La lectura tiene una duracion de: " << minutos << " minutos" << endl;
    cout << "📌 La lectura fue publicada en: " << anio_publicacion << endl;
    if(escritor != nullptr){
        cout<< "🖊️ El escritor es: " << escritor->obtener_nombre_completo() << endl;
    }else{
        cout << "🖊️ El escritor es: ANONIMO" << endl;
    }
    cout<< "📜 El Poema tiene: "<< cant_versos<< " versos"<< endl;
    cout<<"\n";
}

string Poema::obtener_atributo_diferente(){
    return to_string(cant_versos);
}

