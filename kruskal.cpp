#include "kruskal.h"

        
Kruskal::Kruskal(Grafo grafo, Vertice* vertices){
    this->vertices = vertices;
    this->matriz_pesos = grafo.obtener_matriz();
    cantidad_vertices = grafo.obtener_cantidad();
    vector = new int[cantidad_vertices + 1];
    for(int i = 0; i < cantidad_vertices + 1 ; i++){
        vector[i] = 0;
    }

}

int Kruskal::encontrar(int i){
    while(vector[i] > 0){
        i = vector[i];
    }
    
    return i;
}

int Kruskal::unir(int i, int j){
    if(i != j){
        vector[j] = i;
        return 1;
    }
    return 0;
}

void Kruskal::recorrer(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout << "Las lecturas son: ";
    int i = 0, j = 0, minimo = 0, costo_minimo = 0, aux_1 = 1, aux_2 = 0, aux_3 = 0, aux_4 = 0, aux_5 = 0;
    for(int i = 0; i < cantidad_vertices; i++){
        //cout << "Los vertices son: " << vertices[i].obtener_vertice()->obtener_titulo() <<  endl;
        cout << vertices[i].obtener_vertice()->obtener_titulo() << " - ";
    }
    cout << endl;
    cout << "Tiempo mínimo para leer todas las lecturas: \n" << endl;
    
    while( aux_1 < cantidad_vertices){
        for( i = 1, minimo = INFINITO; i <= cantidad_vertices; i++){
            for(j = 1; j <= cantidad_vertices; j++){
                if(matriz_pesos[i-1][j-1] < minimo){
                    minimo = matriz_pesos[i-1][j-1];
                    aux_2 = aux_3 = i;
                    aux_4 = aux_5 = j;
                }
            }
        }
    
        aux_3 = encontrar(aux_3);
        
        aux_5 = encontrar(aux_5);

        if(unir(aux_3, aux_5) > 0){
            aux_1++;
            cout << "Pasar de la lectura " << vertices[aux_2-1].obtener_vertice()->obtener_titulo()
            << " a la lectura " << vertices[aux_4-1].obtener_vertice()->obtener_titulo() << ", lleva un tiempo de: "<< ROJO << minimo << BLANCO << " minutos" << endl;
            costo_minimo += minimo;
        }
         matriz_pesos[aux_2-1][aux_4-1] = matriz_pesos[aux_4-1][aux_2-1] = INFINITO;
    }
    cout << " " << endl;
    
    cout<<"El costo mínimo total es: "<< costo_minimo << endl;
}

void Kruskal::liberar_matriz(){
    delete [] vertices;
    delete [] vector;
    if(matriz_pesos != nullptr){
        for(int i = 0; i < cantidad_vertices; i++){
            delete [] matriz_pesos[i];
        }   
        delete [] matriz_pesos;
    }
    matriz_pesos = nullptr;
}