#ifndef LIST_ESCRITORES_H
#define LIST_ESCRITORES_H

#include "nodo.h"
#include "escritor.h"
#include <iostream>
using namespace std;

class Lista_Escritores{

    private:
        Nodo<Escritor*>* primero;
        Nodo<Escritor*>* obtener_nodo(int pos);
        int cantidad;

    public:
        // Constructor
        Lista_Escritores();
        // Destructor
        ~Lista_Escritores(){};
        
        // PRE: -
        // POST: Devuelve la cantidad de elementos que tiene la lista.
        int obtener_cantidad();

        //PRE: La lista no debe estar vacia.
        //POST: Muestra los elementos de la lista.
        void listar_escritores();

        // PRE: La lista no debe estar vacía.
        // POST: En caso de existir el objeto con el atributo nombre_completo que se pasa, lo devuelve; de lo contrario 
        // retorna NULL
        Escritor* consulta(string atributo);

        // PRE: La lista no debe estar vacía, el escritor debe estar en ella y nueva_fecha debe ser mayor a 0.
        // POST: Modifica la fecha de fallecimiento del escritor que se le pasa, asignandole nueva_fecha.
        void modificar_anio_fallecimiento(string nombre_escritor, int nueva_fecha);

        // PRE: La lista no debe estar vacía y pos debe estar entre 1 y obtener_cantidad().
        // POST: Elimina el elemento que está en pos.
        void baja_nodo(int pos);

        // PRE: La lista debe contar con elementos.
        // POST: Da de baja todos los elementos de la lista.
        void vaciar_lista();

        // PRE: -
        // POST: Devuelve true si la cantidad de elementos es igual a 0.
        bool vacia();

        // PRE: dato debe ser valido y posición un numero > 0.
        // POST: Da de alta en la posicion que se le pasa por parametro.
        void alta(Escritor* dato, int posicion);

        // PRE: dato debe ser válido.
        // POST: Da de alta en la posición final.
        void alta(Escritor* dato);
        
        // PRE: -
        // POST: Devuelve el string convertido en mayúscula.
        string convertir_en_mayuscula(string cadena);

        int buscar_referencia(string referencia);

        void baja(int isni);
};

#endif