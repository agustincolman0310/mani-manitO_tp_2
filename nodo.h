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
    // POST: Imprime el dato por pantalla.
    void imprimir();

    // PRE: -
    // POST: Siguiente pasa a ser nuevo_nodo.
    void cambiar_siguiente(Nodo* nuevo_nodo);

    // PRE: El nodo no debe estar vacío
    // POST: Devuelve el dato que se encuentra en el nodo.
    T obtener_dato();

    void eliminar_dato();

    
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

template < typename T >
void Nodo<T>::eliminar_dato(){
    delete dato;
};
#endif
/*
#include <iostream>
template <typename Dato>class Nodo{
private:    Dato dato;    Nodo* siguiente;
public:
    //PRE: dato debe ser un dato válido.    //POST: Construye un nodo con el dato "dato" y anterior es nullptr.    Nodo(Dato dato);
    //PRE: p_nodo es un puntero válido y el objeto Nodo es un objeto válido.    //POST: Cambia hacia donde apunta el Nodo.    void cambiar_siguiente(Nodo* p_nodo);
    //PRE: El objeto Nodo debe ser un objeto válido.    // POST: Le asigna dato al dato del nodo.    void asignar_dato(Dato _dato);
    //PRE: El objeto Nodo debe ser un objeto válido.    //POST: Devuelve el dato del nodo.    Dato obtener_dato();
    //PRE: El objeto Nodo debe ser un objeto válido.    //POST: Devuelve el Nodo siguiente.    Nodo* obtener_siguiente();
};
////////////////////////////////////////////////
template <typename Dato>Nodo<Dato>::Nodo(Dato dato){    this -> dato = dato;    siguiente = 0;}
template <typename Dato>void Nodo<Dato>::cambiar_siguiente(Nodo<Dato>* p_nodo){    siguiente = p_nodo;}
template <typename Dato>Dato Nodo<Dato>::obtener_dato(){    return dato;}
template <typename Dato>void Nodo<Dato>:: asignar_dato(Dato _dato) {    dato = _dato;}
template <typename Dato>Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){    return siguiente;}*/