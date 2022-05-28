#ifndef LISTA_LECTURAS_H_INCLUDED
#define LISTA_LECTURAS_H_INCLUDED

#include "lectura.h"
#include "nodo.h"
// template <typename T>
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
    void baja(int pos);

    void mostrar_lectura(T lectura);

    int obtener_cantidad();

    void insertar_ordenadamente(T data_);
    int buscar_titulo(string titulo_buscado);
    Nodo<T>* obtener_primero();
    void sortear_lectura(int numero);
    void alta(T dato);
    void listar_por_escritor(string nombre_completo);
    void listar_entre_anios(int desde, int hasta);
    void eliminar_por_titulo(string titulo);
    // Destructor
    void listar_por_genero(string genero_recibido);
    void agregar_final(T dato);
    ~Lista_Lecturas();

    
    
    void ordenar(T objeto, Nodo<T>* direccion);
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
Lista_Lecturas::~Lista_Lecturas() {}

//  D Lista_Escritores::consulta(string nombre_completo){
//     Nodo<D> *temp = primero;
//     D escritor = NULL;
//     while (temp) {
//         if ((temp->obtener_dato()->obtener_nombre_completo() == nombre_completo) || (temp->obtener_dato()->obtener_referencia() == nombre_completo)) {
//             escritor = temp->obtener_dato();
//         }
//         temp = temp->obtener_siguiente();
//     }
//     return escritor;
//     // if(temp == nullptr){
//     //     cout<<"El escritor ingresado no se encuentra en la lista!"<<endl;
//     // }
// }
void Lista_Lecturas::listar_por_escritor(string nombre_completo){
    Nodo<T> *temp = primero;

    while(temp){
        if(temp->obtener_dato()->obtener_escritor() == nombre_completo){
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

//  D Lista_Escritores::consulta(string nombre_completo){
//     Nodo<D> *temp = primero;
//     D escritor = NULL;
   
//     while (temp) {
//         if ((temp->obtener_dato()->obtener_nombre_completo() == nombre_completo) || (temp->obtener_dato()->obtener_referencia() == nombre_completo)) {
//             escritor = temp->obtener_dato();
//         }
//         temp = temp->obtener_siguiente();
//     }
//     return escritor;
// }

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
    int cont = 1;
    int cont2 = 0;
 
    while (temp) {
        if (temp->obtener_dato()->obtener_titulo() == titulo_buscado) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->obtener_siguiente();
        cont++;
    }
 
    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;

    return cont;
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

//  D Lista_Escritores::consulta(string nombre_completo){
//     Nodo<D> *temp = primero;
//     D escritor = NULL;
//     while (temp) {
//         if ((temp->obtener_dato()->obtener_nombre_completo() == nombre_completo) || (temp->obtener_dato()->obtener_referencia() == nombre_completo)) {
//             escritor = temp->obtener_dato();
//         }
//         temp = temp->obtener_siguiente();
//     }
//     return escritor;
//     // if(temp == nullptr){
//     //     cout<<"El escritor ingresado no se encuentra en la lista!"<<endl;
//     // }
// }

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


// void Lista_Lecturas::baja(int pos) {
//     Nodo<T>* borrar = primero;
//     if (pos == 1) {
//         primero = primero->obtener_siguiente();
//     }
//     else {
//         Nodo<T>* anterior = obtener_nodo(pos - 1);
//         borrar = anterior->obtener_siguiente();
//         anterior->cambiar_siguiente(borrar->obtener_siguiente());
//     }
//     cantidad--;
//     delete borrar;
// }
#endif
