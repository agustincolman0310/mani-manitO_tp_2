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

/*MÉTODOS*/

    int posicion_vertice(Lectura* vertice);



public:
    int asignar_peso_arista(Lectura* origen, Lectura* destino, int &peso);

    void agregar_arista(Lectura* vertice_origen, Lectura* vertice_destino, int peso);

    Grafo();

    Grafo(int cantidad);
    
    int peso_arista(Lectura* vertice_origen, Lectura* vertice_destino);

    void agregar_vertice(Lectura* nueva_lectura);

    Vertice* obtener_vertices();

    int obtener_cantidad();

    int ** obtener_matriz();

    ~Grafo(){};
};


#endif //GRAFOS_GRAFO_H
