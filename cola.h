#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo.h"

class Cola {
    // Atributos
private:
    Nodo* primero;
    Nodo* ultimo;

    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye una Cola vacia
    */
    Cola();

    /*
    Alta
    PRE: e es un Dato valido
    POS: agrega el elemento al final de la Cola
    */
    void alta(Dato e);

    /*
    Baja
    PRE: la Cola no puede estar vacia
    POS: quita el elemento del principio de la Cola
    */
    void baja();

    /*
    Consulta
    PRE: la Cola no puede estar vacia
    POS: devuelve el elemento del principio de la Cola (pero no modifica)
    */
    Dato consulta();


    /*
    Vacia
    PRE: -
    POS: devuelve true si la Cola esta vacia, false de lo contrario
    */
    bool vacia();

    // Destructor
    ~Cola();
};

#endif // COLA_H_INCLUDED