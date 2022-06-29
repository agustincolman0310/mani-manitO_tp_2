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
    Main_Kruskal(Lista_Lecturas vertices);
    // Main_Kruskal();

    void inicializar_aristas(Grafo grafo);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    // void caminoMinimo(int origen, int destino);
    void ejecutar_kruskal();
    // ~Main_Kruskal(){};
};


#endif //MAIN_KRUSKAL_H