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
    Vertice(Lectura* vertice);
    Vertice();

    //post: obtiene el nombre del vertice
    Lectura* obtener_vertice();
    bool son_iguales(Vertice nuevo_vertice);
    void asignar_vertice(int numero);
    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
