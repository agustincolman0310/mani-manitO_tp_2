#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H

#include <string>
#include "lectura.h"

using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    Lectura* vertice;
    int numero_vertice;

/*MÉTODOS*/
public:
    //Constructor que recibe un vertice
    Vertice(Lectura* vertice);
    //Constructor por defecto
    Vertice();
    /*
    PRE: - 
    POST: Devuelve la lectura declarada que tiene el vertice. 
    */ 
    Lectura* obtener_vertice();
    /*
    PRE: nuevo_vertice debe estar inicializado.
    POST: Devuelve true si el vertice pasado por parametro ya fue declarado anteriormente.
    */
    bool son_iguales(Vertice nuevo_vertice);
    /*
    PRE: numero debe ser >= 0.
    POST: Se encarga de asignarle al vertice una posición. 
    */
    void asignar_vertice(int numero);
    //Destructor
    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
