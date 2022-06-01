#ifndef LIST_ESCRITORES_H
#define LIST_ESCRITORES_H

#include "nodo.h"
#include "escritor.h"
#include <iostream>
using namespace std;

typedef Escritor* D;

class Lista_Escritores{
    public:
        Lista_Escritores();
        // ~Lista_Escritores();

        void agregar_final(D dato);
        void add_sort(D);
        int obtener_cantidad() const;
        void listar_escritores();
        void insertar_ordenadamente(D data_);
        D consulta(string nombre_completo);
        void desplazar_actual(string referencia);
        void modificar_anio_fallecimiento(string nombre_escritor, int nueva_fecha);
        string devolver_nombre_escritor(string nombre_completo);
        void baja(int pos);
        void vaciar_lista();
        bool vacia();

    private:
        Nodo<D> *primero;
        Nodo<D>* obtener_nodo(int pos);
        
        int cantidad;
};


// Lista_Escritores::~Lista_Escritores() {}
#endif