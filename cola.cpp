#include "cola.h"
#include <iostream>

using namespace std;
// Constructor
Cola::Cola() {
    primero = 0;
    ultimo = 0;
}

// alta
void Cola::alta(Dato e) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(e);
    if (primero)
        ultimo->cambiar_siguiente(nuevo);
    else
        primero = nuevo;
    ultimo = nuevo;
}


// baja
void Cola::baja() {
    Nodo<Dato>* borrar = primero;
    primero = primero->obtener_siguiente();
    if (! primero)
        ultimo = 0;
    delete borrar;
}

// consulta
Dato Cola::consulta() {
    return primero->obtener_dato();
}


// vacia
bool Cola::vacia() {
    return (ultimo == 0);
}


//Destructor
Cola::~Cola() {
    while (! vacia())
        baja();
}