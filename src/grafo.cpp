#include "../header/grafo.h"
#include <iostream>

Grafo::Grafo() {
    matriz_pesos = nullptr;
    vertices = nullptr;
    cantidad_elementos = 0;
}

Grafo::Grafo(int cantidad){
    matriz_pesos = new int *[cantidad];
    vertices = new Vertice[cantidad];

    for(int i = 0; i < cantidad; i++){
        matriz_pesos[i] = new int [cantidad];
        for(int j = 0; j < cantidad; j++){
            matriz_pesos[i][j] = INFINITO;
        }
    }
    cantidad_elementos = 0;
}

int Grafo::posicion_vertice(Lectura* vertice){
    bool existe = false;
    int i = 0;
    Vertice* nuevo_vertice = new Vertice(vertice);
    while(i < cantidad_elementos && !existe){
        existe = vertices[i].son_iguales(*nuevo_vertice); 
        if(!existe){
            i++;
        }
    }

    delete nuevo_vertice;
    return (i < cantidad_elementos ) ? i : POSICION_NO_ENCONTRADA;
}

void Grafo::agregar_vertice(Lectura* nueva_lectura){

    bool existe = posicion_vertice(nueva_lectura) >= 0;

    if(!existe){
        Vertice* nuevo_vertice = new Vertice(nueva_lectura);
        nuevo_vertice->asignar_vertice(cantidad_elementos);
        vertices[cantidad_elementos++] = *nuevo_vertice;
        delete nuevo_vertice;
    }

}

void Grafo::agregar_arista(Lectura* vertice_origen, Lectura* vertice_destino, int peso){
    int posicion_origen = posicion_vertice(vertice_origen);
    int posicion_destino = posicion_vertice(vertice_destino);
    
    matriz_pesos[posicion_origen][posicion_destino] = peso;
}

int Grafo::peso_arista(Lectura* vertice_origen, Lectura* vertice_destino){
    int posicion_origen = posicion_vertice(vertice_origen);
    int posicion_destino = posicion_vertice(vertice_destino);
    
    return matriz_pesos[posicion_origen][posicion_destino];
}

int Grafo::asignar_peso_arista(Lectura* origen, Lectura* destino, int &peso){
    
    char tipo_lectura_origen = origen->obtener_tipo_lectura();
    char tipo_lectura_destino = destino->obtener_tipo_lectura();

    if(tipo_lectura_origen == tipo_lectura_destino){
        if(tipo_lectura_origen == TIPO_CUENTO){
            peso = 8;
        }else if(tipo_lectura_origen == TIPO_POEMA){
            peso = 1;
        }else if(tipo_lectura_origen == TIPO_NOVELA){
            if((origen->obtener_atributo_diferente() == NOVELA_HISTORICA) ||
             (destino->obtener_atributo_diferente() == NOVELA_HISTORICA)){
                 peso = 60;
             }
             else if((origen->obtener_atributo_diferente() == NOVELA_HISTORICA) &&
             (destino->obtener_atributo_diferente() == NOVELA_HISTORICA)){
                 peso = 80;
             }else{
                 peso = 30;
             }
        }
    }
    else if((tipo_lectura_origen == TIPO_CUENTO && tipo_lectura_destino == TIPO_POEMA) || 
    (tipo_lectura_origen == TIPO_POEMA && tipo_lectura_destino == TIPO_CUENTO)){
        peso = 0;
    }
    else if((tipo_lectura_origen == TIPO_CUENTO && tipo_lectura_destino == TIPO_NOVELA) || 
            (tipo_lectura_origen == TIPO_NOVELA && tipo_lectura_destino == TIPO_CUENTO)){
        if(origen->obtener_atributo_diferente() == NOVELA_HISTORICA || destino->obtener_atributo_diferente() == NOVELA_HISTORICA){
            peso = 15;
        }else{
            peso = 10;
        }
    }
    else if((tipo_lectura_origen == TIPO_POEMA && tipo_lectura_destino == TIPO_NOVELA) || 
            (tipo_lectura_origen == TIPO_NOVELA && tipo_lectura_destino == TIPO_POEMA)){
        if(origen->obtener_atributo_diferente() == NOVELA_HISTORICA || destino->obtener_atributo_diferente() == NOVELA_HISTORICA){
            peso = 20;
        }else{
            peso = 5;
        }
    }

    return peso;
}

Vertice* Grafo::obtener_vertices(){
    return vertices;
}

int Grafo::obtener_cantidad(){
    return cantidad_elementos;
}

int ** Grafo::obtener_matriz(){
    return matriz_pesos;
}