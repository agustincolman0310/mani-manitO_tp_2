#ifndef NODO_H
#define NODO_H
#include <iostream>

template <typename T>

class Nodo{
    //Atributos
private:
    T dato;
    Nodo<T>* siguiente;

    //Metodos
public:
    // PRE: -
    // POST: Construye un nodo con dato y con siguiente apuntando a nullptr.
    Nodo(T dato);

    // PRE: -
    // POST: Siguiente pasa a ser nuevo_nodo.
    void cambiar_siguiente(Nodo* nuevo_nodo);

    // PRE: El nodo no debe estar vacío
    // POST: Devuelve el dato que se encuentra en el nodo.
    T obtener_dato();
    
    Nodo<T>* obtener_siguiente();
};

template < typename T >
Nodo<T>::Nodo(T dato){
    this->dato = dato;
    this->siguiente = nullptr;
};

template < typename T >
void Nodo<T>::cambiar_siguiente(Nodo<T>* nuevo_nodo){
    this->siguiente = nuevo_nodo;
};

template < typename T >
T Nodo<T>::obtener_dato(){
    return dato;
};

template < typename T >
Nodo<T> *Nodo<T>::obtener_siguiente(){
    return siguiente;
};


#endif
