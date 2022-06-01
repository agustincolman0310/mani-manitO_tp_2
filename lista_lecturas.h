#ifndef LISTA_LECTURAS_H_INCLUDED
#define LISTA_LECTURAS_H_INCLUDED

#include "lectura.h"
#include "nodo.h"


typedef Lectura* T;


class Lista_Lecturas{
    // Atributos
private:
    Nodo<T>* primero;
    int cantidad;
    Nodo<T>* actual;
    Nodo<T>* ultimo;
    Nodo<T>* obtener_nodo(int pos);
    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye una Lista vacia
    */
    Lista_Lecturas();
    void listar_lecturas();

    /*
    Baja
    PRE: 1 <= pos <= obtener_cantidad()
    POS: da de baja al elemento que esta en pos, se empieza por 1
    */
    // void baja(int pos);

    /*
    Consulta
    PRE: 1 <= pos <= obtener_cantidad()
    POS: devuelve el elemento que esta en pos, se empieza por 1
    */
    // T consulta(int pos);

    /*
    Vacia
    PRE: -
    POS: devuelve true si la Lista esta vacia, false de lo contrario
    */
    bool vacia();
    void baja(string titulo);
    void baja(int pos);
    void vaciar_lista();
    void mostrar_lectura(T lectura);

    int obtener_cantidad();

    void insertar_ordenadamente(T data_);
    int buscar_titulo(string titulo_buscado);
    Nodo<T>* obtener_primero();
    // Nodo<T>* obtener_nodo(int pos);
    void sortear_lectura(int numero);
    void alta(T dato);
    void listar_por_escritor(string nombre_completo);
    void listar_entre_anios(int desde, int hasta);
    void eliminar_por_titulo(string titulo);
    void eliminar_por_dato(string titulo);
    // Destructor
    void listar_por_genero(string genero_recibido);
    void agregar_final(T dato);
    T encontrar_lectura_menor(int &minimo);
    // ~Lista_Lecturas();
    int comparar(T dato);
    
    
    void ordenar(T objeto);
};

// template <typename T>

bool Lista_Lecturas::vacia(){
    return cantidad == 0;
}

int Lista_Lecturas::obtener_cantidad(){
    return cantidad;
}

Lista_Lecturas::Lista_Lecturas(){
    primero = nullptr;
    cantidad = 0;
    actual = nullptr;
    ultimo = nullptr;
}

// Lista_Lecturas::~Lista_Lecturas(){
//     while(!vacia()){
//         actual = primero;
//         primero = primero->obtener_siguiente();
//         delete actual;
//     }
// }
// Lista_Lecturas::~Lista_Lecturas() {}

void Lista_Lecturas::listar_por_escritor(string nombre_completo){
    Nodo<T> *temp = primero;

    while(temp){
        if(temp->obtener_dato()->obtener_escritor()->obtener_nombre_completo() == nombre_completo){
            temp->obtener_dato()->mostrar();
        }
        temp = temp->obtener_siguiente();
    }
}

void Lista_Lecturas::listar_entre_anios(int desde, int hasta){
    Nodo<T> *temp = primero;
    while(temp){
        if((temp->obtener_dato()->obtener_anio_publicacion()) >= desde && (temp->obtener_dato()->obtener_anio_publicacion()) <= hasta ){
            temp->obtener_dato()->mostrar();
        }
        temp = temp->obtener_siguiente();
    }
}

int Lista_Lecturas::comparar(T dato){
    int valor = 0;
    // Nodo<T> *nuevo_nodo = new Nodo<T> (data_);
    Nodo<T> *temp = primero;
    if ((temp->obtener_dato()->obtener_anio_publicacion()) > (dato->obtener_anio_publicacion())) {
        valor = 1;
    }
    else if((temp->obtener_dato()->obtener_anio_publicacion()) < (dato->obtener_anio_publicacion())){
        valor = -1;
    }

    return valor;   
}
void Lista_Lecturas::insertar_ordenadamente(T data_){
    Nodo<T> *nuevo_nodo = new Nodo<T> (data_);
    Nodo<T> *temp = primero;
    if (!primero || (primero->obtener_dato()->obtener_anio_publicacion()) > (data_->obtener_anio_publicacion())) {
        
        nuevo_nodo->cambiar_siguiente(primero);
        primero = nuevo_nodo;
    }
    else {
            while((temp->obtener_siguiente() != NULL) && ((temp->obtener_siguiente()->obtener_dato()->obtener_anio_publicacion()) < (data_->obtener_anio_publicacion()))) {
                temp = temp->obtener_siguiente();
            }
            nuevo_nodo->cambiar_siguiente(temp->obtener_siguiente());
            temp->cambiar_siguiente(nuevo_nodo);
        }        
    cantidad++; 
}

void Lista_Lecturas::listar_por_genero(string genero_recibido){
    Nodo<T> *temp = primero;
//     D escritor = NULL;
    while (temp) {
        if ((temp->obtener_dato()->obtener_tipo_lectura() == 'N') ) {
            if(temp->obtener_dato()->obtener_genero() == genero_recibido)
            temp->obtener_dato()->mostrar();
        }
        temp = temp->obtener_siguiente();
    }
   
}
void Lista_Lecturas::listar_lecturas(){
    Nodo<T> *temp = primero;
    
    if (!primero) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            if(temp != NULL){
                temp->obtener_dato()->mostrar();
            }
            temp = temp->obtener_siguiente();
        }
  }
}
void Lista_Lecturas::eliminar_por_titulo(string titulo){
    Nodo<T> *temp = primero;
    Nodo<T> *temp1 = primero->obtener_siguiente();

    int cont = 0;

    if (primero->obtener_dato()->obtener_titulo() == titulo) {
        primero = temp->obtener_siguiente();
    } else {
        while (temp1) {
            if (temp1->obtener_dato()->obtener_titulo() == titulo) {
                Nodo<T> *aux_node = temp1;
                temp->cambiar_siguiente(temp1->obtener_siguiente());
                delete aux_node;
                cont++;
                cantidad--;
            }
            temp = temp->obtener_siguiente();
            temp1 = temp1->obtener_siguiente();
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}

void Lista_Lecturas::alta(T dato){
    // Nodo<T> *nuevo_nodo = new Nodo<T> (dato);
    insertar_ordenadamente(dato);
    // cantidad++;
}

int Lista_Lecturas::buscar_titulo(string titulo_buscado)
{
    Nodo<T> *temp = primero;
    int cont = 0;
    //int cont2 = 1;
 
    while (temp->obtener_dato()->obtener_titulo() != titulo_buscado) {
        //if (temp->obtener_dato()->obtener_titulo() == titulo_buscado) {
            //cout << "El dato se encuentra en la posición: " << cont << endl;
            // cont2++;
            cont++;
            temp = temp->obtener_siguiente();
    }
    cont++;
 
    // if (cont2 == 0) {
    //     cout << "No existe el dato " << endl;
    // }
    // cout << endl << endl;

    return cont;
}


T Lista_Lecturas::encontrar_lectura_menor(int &minimo){
    Nodo<T> *temp = primero;
    T lectura = NULL;
    int minimo_maximo = 0;
    while(temp){
        
        if(minimo < temp->obtener_dato()->obtener_tiempo_lectura() && temp->obtener_dato()->obtener_tiempo_lectura() < minimo_maximo){ 
            minimo_maximo = temp->obtener_dato()->obtener_tiempo_lectura();
            lectura = temp->obtener_dato();
        }
        else if(minimo_maximo == 0 && minimo < temp->obtener_dato()->obtener_tiempo_lectura()){
            minimo_maximo = temp->obtener_dato()->obtener_tiempo_lectura();
            lectura = temp->obtener_dato();
        }

        temp = temp->obtener_siguiente(); 
    }
    minimo = minimo_maximo;
    return lectura;
}


void Lista_Lecturas::sortear_lectura(int numero){
    int i = 1;
    Nodo<T> *temp = primero;
    T lectura_sorteada = NULL;

    while(temp){
        if(i == numero){
            lectura_sorteada = temp->obtener_dato();
        }
        temp = temp->obtener_siguiente();
        i++;
    }
    lectura_sorteada->mostrar();
}

void Lista_Lecturas::agregar_final(T dato){
    Nodo<T> *new_node = new Nodo<T> (dato);
    Nodo<T> *temp = primero;

    if (!primero) {
        primero = new_node;
    } else {
        while (temp->obtener_siguiente() != NULL) {
            temp = temp->obtener_siguiente();
        }
        temp->cambiar_siguiente(new_node);
    }
}

void Lista_Lecturas::eliminar_por_dato(string titulo)
{
    Nodo<T> *temp = primero;
    Nodo<T> *temp1 = primero->obtener_siguiente();

    int cont = 0;

    if (primero->obtener_dato()->obtener_titulo() == titulo) {
        primero = temp->obtener_siguiente();
    } else {
        while (temp1) {
            if (temp1->obtener_dato()->obtener_titulo() == titulo) {
                Nodo<T> *aux_node = temp1;
                temp->cambiar_siguiente(temp1->obtener_siguiente());
                delete aux_node;
                cont++;
                cantidad--;
            }
            temp = temp->obtener_siguiente();
            temp1 = temp1->obtener_siguiente();
        }
    }
}

Nodo<T>* Lista_Lecturas::obtener_nodo(int pos) {
    Nodo<T>* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}

void Lista_Lecturas::baja(string titulo) {
    int pos = buscar_titulo(titulo);
    
    Nodo<T>* borrar = primero;
    if (pos == 1){
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}

void Lista_Lecturas::baja(int pos) {


    Nodo<T>* borrar = primero;
    if (pos == 1){
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}

void Lista_Lecturas::vaciar_lista(){
    while(!vacia()){
        baja(1);
    }
}
#endif
