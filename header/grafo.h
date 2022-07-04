#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include "lista_lecturas.h"
#include "vertice.h"
#include "lectura.h"
#include "constantes.h"
#include "lista_lecturas.h"
// const int INFINITO = 99999999;

using namespace std;

class Grafo {

/*ATRIBUTOS*/
private:
    int ** matriz_pesos;
    Vertice* vertices;
    int cantidad_elementos;
    int posicion_vertice(Lectura* vertice);

public:
    // CONSTRUCTOR
    Grafo();
    
    /*
    PRE: -
    POST: Determina los valores iniciales del grafo.
    */
    Grafo(int cantidad);
    
    /*
    PRE: origen y destino deben ser lecturas válidas. 
    POST: Dependiendo del tipo de lectura de origen y destino, le asigna el número correspondiente a peso
    y lo devuelve.
    */ 
    int asignar_peso_arista(Lectura* origen, Lectura* destino, int &peso);
    
    /*
    PRE: - 
    POST: Inserta peso en la posición de vertice_origen y vertice_destino.
    */ 
    void agregar_arista(Lectura* vertice_origen, Lectura* vertice_destino, int peso);
    
    /*
    PRE: -
    POST: Devuelve el peso que se encuentra en la posición de vertice_origen y vertice_destino.
    */
    int peso_arista(Lectura* vertice_origen, Lectura* vertice_destino);
    
    /*
    PRE: -
    POST: Le asigna un vertice a la lectura pasada por parametro.
    */
    void agregar_vertice(Lectura* nueva_lectura);
    
    /*
    PRE: El vector de vertices no debe estar vacio.
    POST: Devuelve el vector de vertices.
    */
    Vertice* obtener_vertices();
    
    /*
    PRE: -
    POST: Devuelve la cantidad de vertices cargados.
    */
    int obtener_cantidad();
    
    /*
    PRE: matriz_pesos no debe estar vacia.
    POST: Devuelve la matriz de pesos.
    */
    int ** obtener_matriz();
};


#endif //GRAFOS_GRAFO_H
