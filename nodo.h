#ifndef NODO_H
#define NODO_H

// typedef char Dato;
template <typename dato>

class Nodo{
    //Atributos
private:
    dato objeto;
    Nodo* siguiente;

    //Metodos
public:
    //PRE: -
    //POST: construye un nodo con d como dato anterior en nullptr
    Nodo(dato d);

    void cambiar_dato(dato d);

    // void cambiar_siguiente(Nodo* n);

    dato obtener_dato();

    Nodo* obtener_siguiente();
};



template < typename dato >
Nodo<dato>::Nodo(dato d){
    objeto = d;
    siguiente = 0;
};

template < typename dato >
dato Nodo<dato>::obtener_dato(){
    return objeto;
};

template < typename dato >
Nodo<dato> *Nodo<dato>::obtener_siguiente(){
    return siguiente;
};

#endif