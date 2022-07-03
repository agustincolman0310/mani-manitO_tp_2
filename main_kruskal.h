#ifndef MAIN_KRUSKAL_H
#define MAIN_KRUSKAL_H

#include "vertice.h"
#include "lista_lecturas.h"
using namespace std;
#include "constantes.h"
#include "grafo.h"
#include "kruskal.h"
#include "lectura.h"

class Main_Kruskal{
private:
    Lista_Lecturas vertices;
    int cantidad_vertices;

public:
    //Constructor
    Main_Kruskal(Lista_Lecturas vertices);
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


#endif //MAIN_KRUSKAL_H