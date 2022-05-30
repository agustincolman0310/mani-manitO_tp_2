#ifndef NODO_H
#define NODO_H
#include <iostream>
// typedef char Dato;
template <typename T>

class Nodo{
    //Atributos
private:
    T dato;
    Nodo<T>* siguiente;

    //Metodos
public:
    //PRE: -
    //POST: construye un nodo con d como T anterior en nullptr
    Nodo(T dato);

    void imprimir();

    // void cambiar_dato(T d);

    void cambiar_siguiente(Nodo* nueva_posicion);

    T obtener_dato();

    Nodo<T>* obtener_siguiente();
};

template < typename T >
Nodo<T>::Nodo(T dato){
    this->dato = dato;
    this->siguiente = nullptr;
};

template < typename T >
void Nodo<T>::cambiar_siguiente(Nodo<T>* nueva_posicion){
    this->siguiente = nueva_posicion;
};

template < typename T >
T Nodo<T>::obtener_dato(){
    return dato;
};

template < typename T >
void Nodo<T>::imprimir(){
    std::cout << dato << std::endl;
}
template < typename T >
Nodo<T> *Nodo<T>::obtener_siguiente(){
    return this->siguiente;
};

#endif
