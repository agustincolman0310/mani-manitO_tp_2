#include "../header/tabla_hashing.h"
#include <string.h>

Tabla_Hashing::Tabla_Hashing(){
    for(int i = 0; i < TAMANIO; i++){
        escritores[i] = nullptr;
    }
}

int Tabla_Hashing::hashing(int clave){
    return (clave % TAMANIO);
}

void Tabla_Hashing::insertar_escritor(Escritor* escritor){
    int numero_clave = obtener_referencia(escritor->obtener_referencia());
    int posicion = hashing(numero_clave);

    if(escritores[posicion] == nullptr){
        escritores[posicion] = new Lista_Escritores();
    }

    escritores[posicion]->alta(escritor);

}

int Tabla_Hashing::obtener_referencia(string referencia){
    string ref;
    int numero;
    for(int i = 1; i < (int) referencia.length() - 1; i++){
        ref += referencia[i];
    }
    numero = stoi(ref);
    return numero;
} 

void Tabla_Hashing::eliminar_escritor(int isni){
    
    int posicion = hashing(isni);
    
    escritores[posicion]->baja(isni);
}

Escritor* Tabla_Hashing::consulta(string referencia){
    if(referencia == "ANONIMO"){
        return NULL;
    }else{
        int numero_clave = obtener_referencia(referencia);
        int posicion = hashing(numero_clave);

        return escritores[posicion]->consulta(referencia);
    }
}

void Tabla_Hashing::mostrar_escritores(){
    for(int i = 0; i < TAMANIO; i++){
        if(escritores[i] != nullptr){
            escritores[i]->listar_escritores();
        }
    }
}

void Tabla_Hashing::vaciar_tabla(){
    for(int i = 0; i < TAMANIO; i++){
        if(escritores[i] != nullptr){
            escritores[i]->vaciar_lista();
            delete escritores[i];
        }
    }
}

void Tabla_Hashing::mostrar_referencias(){
    for(int i = 0; i < TAMANIO; i++){
        if(escritores[i] != nullptr){
            escritores[i]->listar_referencias();
        }

    }
}