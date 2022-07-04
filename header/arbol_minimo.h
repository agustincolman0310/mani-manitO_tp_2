#ifndef ARBOL_MINIMO_H_INCLUDED
#define ARBOL_MINIMO_H_INCLUDED

#include "vertice.h"
#include "lista_lecturas.h"
#include "constantes.h"
#include "grafo.h"
#include "kruskal.h"
#include "lectura.h"

using namespace std;

class Arbol_Minimo{
private:
    Lista_Lecturas vertices;
    int cantidad_vertices;

public:
    //Constructor
    Arbol_Minimo(Lista_Lecturas vertices);
    /*
    PRE: grafo debe estar inicializado.
    POST: Le carga al grafo los vertices y con esos vertices, inicializa las aristas.
    */
    void inicializar_aristas(Grafo grafo);
    /*
    PRE: -
    POST: Se encarga de hacer las acciones pertinentes del método de Kruskal (agrega vertices, inicializa aristas, lo construye y lo libera). 
    */
    void ejecutar_kruskal();
};


#endif //ARBOL_MINIMO_H