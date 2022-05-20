#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"
template <typename T>

class Lista {
    // Atributos
private:
    Nodo<T>* primero;
    int cantidad;
    Nodo<T>* cursor;

    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye una Lista vacia
    */
    Lista();

    /*
    Alta
    PRE: e es un Dato valido y 1 <= pos <= obtener_cantidad() + 1
    POS: agrega el elemento en la posicion pos (se empieza por 1)
    */
    void alta(T dato, int pos);

    /*
    Baja
    PRE: 1 <= pos <= obtener_cantidad()
    POS: da de baja al elemento que esta en pos, se empieza por 1
    */
    void baja(int pos);

    /*
    Consulta
    PRE: 1 <= pos <= obtener_cantidad()
    POS: devuelve el elemento que esta en pos, se empieza por 1
    */
    T consulta(int pos);

    /*
    Vacia
    PRE: -
    POS: devuelve true si la Lista esta vacia, false de lo contrario
    */
    bool vacia();

    int obtener_cantidad();

    // Destructor
    ~Lista();

private:

    Nodo<T>* obtener_nodo(int pos);
};

#endif

template <typename T>
int Lista<T>::obtener_cantidad(){
    return cantidad;
}

template <typename T>
bool Lista<T>::vacia(){
    return (cantidad == 0);
}

template <typename T>
Lista<T>::Lista(){
    primero = 0;
    cantidad = 0;
}

template <typename T>
void Lista<T>::alta(T dato, int pos){
    Nodo<T>* nuevo = new Nodo<T>(dato);
    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else {
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

template <typename T>
void Lista<T>::baja(int pos) {
    Nodo<T>* borrar = primero;
    if (pos == 1) {
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}

template <typename T>
T Lista<T>::consulta(int pos) {
    Nodo<T>* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

template <typename T>
Nodo<T>* Lista<T>::obtener_nodo(int pos) {
    Nodo<T>* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}

template <typename T>
Lista<T>::~Lista(){
    while(!vacia()){
        baja(1);
    }
}