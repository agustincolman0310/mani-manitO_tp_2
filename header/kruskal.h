#ifndef GRAFOS_KRUSKAL_H
#define GRAFOS_KRUSKAL_H

#include "vertice.h"
using namespace std;
#include "constantes.h"
#include "grafo.h"

class Kruskal{
private:

    int ** matriz_pesos;
    Vertice* vertices;
    int cantidad_vertices;
    int * vector;

public:
    //Constructor
    Kruskal(Grafo grafo, Vertice* vertices);
    
    /*
    PRE: -
    POST: Recorre todo el vector de vertices y va sumando el costo de las aristas que no generan
    circuito en el grafo.
    */
    void recorrer();
    
    /*
    PRE: -
    POST: Libera la memoria utilizada en el algoritmo.
    */
    void liberar_matriz();
private:
    
    /*
    PRE: i debe ser mayor o igual a 0
    POST: 
    */
    int encontrar(int i);
    
    /*
    PRE: i y j deben ser > 0.
    POST: Devuelve 1 si i y j son distintos, 0 en caso contrario.
    */
    int unir(int i, int j);
};


#endif //GRAFOS_FLOYD_H