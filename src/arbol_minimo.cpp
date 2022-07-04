#include "../header/arbol_minimo.h"

Arbol_Minimo::Arbol_Minimo(Lista_Lecturas vertices){
    this->vertices = vertices;
    cantidad_vertices = vertices.obtener_cantidad();
}

void Arbol_Minimo::inicializar_aristas(Grafo grafo){
    
    Lectura* origen;
    Lectura* destino;
    int peso;

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++){
            peso = 0;
            origen = grafo.obtener_vertices()[i].obtener_vertice();
            destino = grafo.obtener_vertices()[j].obtener_vertice();

            if(origen->obtener_titulo() != destino->obtener_titulo()){
                grafo.asignar_peso_arista(origen, destino, peso);
            }
            grafo.agregar_arista(grafo.obtener_vertices()[i].obtener_vertice(),grafo.obtener_vertices()[j].obtener_vertice(), peso);
        }
    }
}

void Arbol_Minimo::ejecutar_kruskal(){
    Grafo grafo(cantidad_vertices);

    for (int pos = 1; pos <= cantidad_vertices; pos++){
        grafo.agregar_vertice(vertices.obtener_lectura(pos));
    }

    inicializar_aristas(grafo);

    Kruskal kruskal(grafo, grafo.obtener_vertices());

    kruskal.recorrer();

    kruskal.liberar_matriz();
}