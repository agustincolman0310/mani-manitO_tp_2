#include "vertice.h"

Vertice::Vertice(Lectura* vertice) {
    this->vertice = vertice;
    this->numero_vertice = -1;
}

Vertice::Vertice() {
    this->vertice = nullptr;
    this->numero_vertice = -1;
}

Lectura* Vertice::obtener_vertice() {
    return vertice;
}

bool Vertice::son_iguales(Vertice nuevo_vertice){
    return (nuevo_vertice.obtener_vertice()->obtener_titulo() == vertice->obtener_titulo());
}

void Vertice::asignar_vertice(int numero){
    numero_vertice = numero;
}

Vertice::~Vertice() {};
