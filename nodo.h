#ifndef NODO_H
#define NODO_H

// typedef char Dato;
template <typename T>

class Nodo{
    //Atributos
private:
    T dato;
    Nodo* siguiente;

    //Metodos
public:
    //PRE: -
    //POST: construye un nodo con d como T anterior en nullptr
    Nodo(T d);

    // void cambiar_dato(T d);

    void cambiar_siguiente(Nodo* n);

    T obtener_dato();

    Nodo* obtener_siguiente();
};

#endif

template < typename T >
Nodo<T>::Nodo(T d){
    dato = d;
    siguiente = 0;
};

template < typename T >
void Nodo<T>::cambiar_siguiente(Nodo<T>* n){
    siguiente = n;
};

template < typename T >
T Nodo<T>::obtener_dato(){
    return dato;
};

template < typename T >
Nodo<T> *Nodo<T>::obtener_siguiente(){
    return siguiente;
};