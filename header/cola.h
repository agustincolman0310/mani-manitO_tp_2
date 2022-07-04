#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "lectura.h"
#include "nodo.h"

typedef Lectura *Dato;
class Cola{
private:
    Nodo<Dato> *primero;
    Nodo<Dato> *ultimo;

public:
    
    /*
    Constructor
    PRE: -
    POST: Construye una Cola vacia.
    */
    Cola();
    
    /*
    Alta
    PRE: e es un Dato valido.
    POST: Agrega el elemento al final de la Cola.
    */
    void alta(Dato elemento);
    
    /*
    Baja
    PRE: La Cola no puede estar vacia.
    POST: Quita el elemento del principio de la Cola.
    */
    void baja();
    
    /*
    PRE: La Cola no puede estar vacia.
    POST: Devuelve el elemento del principio de la Cola.
    */
    Dato consulta();
    
    /*
    PRE: -
    POST: Devuelve true si la Cola esta vacia, false de lo contrario.
    */
    bool vacia();
    
    /*
    PRE: -
    POST: Muestra todos los elementos de la Cola.
    */
    void mostrar_cola();
    // Destructor.
    void vaciar_cola();
};

#endif