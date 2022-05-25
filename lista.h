#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"
template <typename T>

class Lista {
    // Atributos
private:
    Nodo<T>* primero;
    int cantidad;
    Nodo<T>* actual;
    // Nodo<T>* ultimo;
    Nodo<T>* obtener_nodo(int pos);
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

    // void insertar_ordenadamente(T dat);

    void insertar_principio(T dat);

    void add_head(T data_);

    // void insertar_final(T dat);

    void insertar_ordenadamente(T data_);

    void insertar_en_final(T data_);


    Nodo<T>* obtener_primero();
    // Destructor
    ~Lista();
};


template <typename T>
int Lista<T>::obtener_cantidad(){
    return cantidad;
}

template <typename T>
Lista<T>::~Lista(){
    while(!vacia()){
        actual = primero;
        primero = primero->obtener_siguiente();
        delete actual;
    }
}

template <typename T>
Nodo<T>* Lista<T>::obtener_nodo(int pos){
    Nodo<T>* aux = primero;
    int contador = 1;
    while(contador < pos){
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}

template <typename T>
T Lista<T>::consulta(int pos){
    // Nodo<T>* aux = obtener_nodo(pos);
    // return aux->obtener_dato();
    Nodo<T>* aux = primero;
    int contador = 1;
    while(contador < pos){
        aux->cambiar_siguiente(aux);
        // aux->obtener_dato();
        contador++;
    }
    return aux->obtener_dato();
}

template <typename T>
bool Lista<T>::vacia(){
    return (cantidad == 0);
}

template <typename T>
Lista<T>::Lista(){
    primero = nullptr;
    cantidad = 0;
    actual = nullptr;
    // ultimo = nullptr;
}

// template <typename T>
// void Lista<T>::insertar_final(T dat){
//     Nodo<T>* nuevo = new Nodo<T>(dat);

//     if(primero == nullptr){
//         nuevo->cambiar_siguiente(primero);
//         primero = nuevo;
//         std::cout<<"Apunta a: "<< primero->obtener_siguiente();
//         std::cout<<"INSERTADO PRIMERO"<<std::endl;

//     }else{
//         nuevo->cambiar_siguiente(ultimo);
//         ultimo = nuevo;
//         std::cout<<"Apunta a2: "<< primero->obtener_siguiente();
//         std::cout<<"INSERTADO"<<std::endl;
//     }
//     // cantidad++;
// }
// template <typename T>
// void Lista<T>::insertar_principio(T dat){
//     this->primero = new Nodo<T>(dat);
//     cantidad++;
// }

template <typename T>
void Lista<T>::add_head(T data_)
{
    Nodo<T> *new_node = new Nodo<T> (data_);
    Nodo<T> *temp = primero;

    if (vacia()) {
        primero = new_node;
    } else {
        new_node->cambiar_siguiente(primero);
        // temp->cambiar_siguiente(new_node);
        primero = new_node;

        while (temp != NULL) {
            temp->cambiar_siguiente(temp);
        }
    }
    // cantidad++;
    // cout<<"La cantidad total es: "<< cantidad <<endl;
}

// typedef Lectura* T;

template <typename T>
void Lista<T>::insertar_en_final(T data_)
{
    Nodo<T> *nuevo_nodo = new Nodo<T>(data_);
    Nodo<T> *temp = primero;

    if (!primero) {
        primero = nuevo_nodo;
            cout<<"Insertado en el primer if"<<endl;
        
    } else {
        while (temp->obtener_siguiente() != NULL) {
            temp = temp->obtener_siguiente();
            cout<<"Insertado en el while"<<endl;
        }
        temp->cambiar_siguiente(nuevo_nodo);
    }
    cantidad++;
    // cout<<"La cantidad total es: "<< cantidad <<endl;
}





#endif