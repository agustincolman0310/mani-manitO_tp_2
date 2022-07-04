#ifndef TABLA_HASHING_H_INCLUDED
#define TABLA_HASHING_H_INCLUDED

#include "lista_escritores.h"
#include "constantes.h"
#include "escritor.h"
int const TAMANIO = 25;

class Tabla_Hashing{

private:
    Lista_Escritores* escritores[TAMANIO];
public:
    
    //Constructor por defecto
    Tabla_Hashing();
    ~Tabla_Hashing(){};
    
    /*
    PRE: Recibe el escritor a insertar. 
    POST: Agrega al escritor en la posición de la tabla que le corresponde, según su referencia. 
    */ 
    void insertar_escritor(Escritor* escritor);
    
    /*
    PRE: El número isni debe ser de largo 4 y positivo. 
    POST: Elimina de la tabla al escritor que tiene como referencia el número isni pasado por parámetro. 
    */ 
    void eliminar_escritor(int isni);
    
    /*
    PRE: - 
    POST: Devuelve nullptr si referencia es "ANONIMO", de lo contrario devuelve el escritor de la tabla
    que tiene la referencia pasada por parámetro. 
    */ 
    Escritor* consulta(string referencia);
    
    /*
    PRE: La tabla de escritores no debe estar vacia.
    POST: Muestra por pantalla al escritor junto con sus atributos.
    */
    void mostrar_escritores();
    
    /*
    PRE: La tabla de escritores no debe estar vacia. 
    POST: Se encarga de vaciar la tabla y liberar memoria.  
    */ 
    void vaciar_tabla();
     
     /*
    PRE: La tabla de escritores no debe estar vacia. 
    POST: Muestra por pantalla el ISNI y el nombre completo del escritor. 
    */ 
    void mostrar_referencias();
private:
    
    /*
    PRE: clave debe ser un número válido. 
    POST: Su resultado es el módulo de la función de h(k). 
    */ 
    int hashing(int clave);
    
    /*
    PRE: El ISNI debe venir en formato : (ISNI).
    POST: Devuelve el ISNI en tipo de dato entero -> ISNI. 
    */
    int obtener_referencia(string referencia);
};





#endif