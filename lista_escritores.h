#ifndef LIST_ESCRITORES_H
#define LIST_ESCRITORES_H

#include "nodo.h"
#include "lista.h"
#include "escritor.h"
#include <iostream>
using namespace std;

// typedef Escritor* D;

class Lista_Escritores{
    public:
        Lista_Escritores();
        ~Lista_Escritores(){};
        Nodo<Escritor*>* obtener_nodo(int pos);
        // // PRE: dato debe ser del tipo D.
        // // POST: Si la lista está vacía agrega el dato en la primera posición, caso contrario
        // // el dato es agregado al final de la lista. 
        // // void agregar_final(D dato, Nodo<D> *nuevo_nodo);
       
        // // PRE: -
        // // POST: Devuelve la cantidad de elementos que tiene la lista.
        int obtener_cantidad();

        // //PRE: La lista no debe estar vacia.
        // //POST: Muestra los elementos de la lista.
        void listar_escritores();

        // // PRE: La lista no debe estar vacía.
        // // POST: En caso de existir el objeto con el atributo nombre_completo que se pasa, lo devuelve; de lo contrario 
        // // retorna NULL
        Escritor* consulta(string nombre_completo);
        // void desplazar_actual(string referencia);

        // // PRE: La lista no debe estar vacía, el escritor debe estar en ella y nueva_fecha debe ser mayor a 0.
        // // POST: Modifica la fecha de fallecimiento del escritor que se le pasa, asignandole nueva_fecha.
        void modificar_anio_fallecimiento(string nombre_escritor, int nueva_fecha);


        // string devolver_nombre_escritor(string nombre_completo);

        // // PRE: La lista no debe estar vacía y pos debe estar entre 1 y obtener_cantidad().
        // // POST: Elimina el elemento que está en pos.
        void baja(int pos);

        // // PRE: La lista debe contar con elementos.
        // // POST: Da de baja todos los elementos de la lista.
        void vaciar_lista();

        // // PRE: -
        // // POST: Devuelve true si la cantidad de elementos es igual a 0.
        bool vacia();
        void alta(Escritor* dato, int posicion);
        void alta(Escritor* dato);
        string convertir_en_mayuscula(string cadena);
        // void prueba_alta(Escritor* dato);
        // void prueba_baja();
    private:
        Lista<Escritor*> lista_escritores;
        Nodo<Escritor*>* primero;
        Nodo<Escritor*>* actual;
        int cantidad;

};



// Lista_Escritores::~Lista_Escritores() {}
#endif