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
    Kruskal(Grafo grafo, Vertice* vertices);

    void recorrer();

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    // void caminoMinimo(int origen, int destino);

    ~Kruskal(){};

private:
    int encontrar(int i);
    int unir(int i, int j);
};


#endif //GRAFOS_FLOYD_H