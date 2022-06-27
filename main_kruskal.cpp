#include "main_kruskal.h"

Main_Kruskal::Main_Kruskal(Lista_Lecturas vertices){
    this->vertices = vertices;
    cantidad_vertices = vertices.obtener_cantidad();
}

void Main_Kruskal::inicializar_aristas(Grafo grafo){
    
    Lectura* origen;
    Lectura* destino;
    int peso;

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++){
            peso = 0;
            origen = grafo.obtener_vertices()[i].obtener_vertice();
            //cout<<origen->obtener_titulo()<<endl;
            destino = grafo.obtener_vertices()[j].obtener_vertice();
            // cout<<destino<<endl;
            if(origen->obtener_titulo() != destino->obtener_titulo()){
                // cout << peso << endl;
                grafo.asignar_peso_arista(origen, destino, peso);
            }
            // cout << peso << endl;
            grafo.agregar_arista(grafo.obtener_vertices()[i].obtener_vertice(),grafo.obtener_vertices()[j].obtener_vertice(), peso);
        }
    }
}

void Main_Kruskal::ejecutar_kruskal(){
    cout << cantidad_vertices << endl;
    // vertices.listar_lecturas();
    Grafo grafo(cantidad_vertices);
    for (int pos = 1; pos <= cantidad_vertices; pos++){
        
        // vertices.obtener_nodo(pos)->obtener_dato()->mostrar();
        grafo.agregar_vertice(vertices.obtener_lectura(pos));
        // cout << vertices.obtener_lectura(pos)->obtener_titulo() << endl;
        // cout << grafo.obtener_vertices()[pos-1].obtener_vertice()->obtener_titulo() << endl;
    }
    // cout << cantidad_vertices << endl;

    inicializar_aristas(grafo);

   
    cout <<"Vertices del grafo"<<endl;
    
    cout << " " << endl;

    for (int i = 0; i < cantidad_vertices; i++){
        
        cout << grafo.obtener_vertices()[i].obtener_vertice()->obtener_titulo() << " " << endl;
    }
    
    cout << " " << endl;

    Kruskal kruskal(grafo, grafo.obtener_vertices());

    kruskal.recorrer();
}