#include "lista_escritores.h"
#include "nodo.h"

Nodo<D>* Lista_Escritores::obtener_nodo(int pos) {
    Nodo<D>* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}
Lista_Escritores::Lista_Escritores()
{
    cantidad = 0;
    primero = nullptr;
}

int Lista_Escritores::obtener_cantidad() const{
    return cantidad;
}

bool Lista_Escritores::vacia(){
    return cantidad == 0;
}

void Lista_Escritores::agregar_final(D dato){
    Nodo<D> *new_node = new Nodo<D> (dato);
    Nodo<D> *temp = primero;

    if (!primero) {
        primero = new_node;

    } else {
        while (temp->obtener_siguiente() != nullptr) {
            temp = temp->obtener_siguiente();
        }
        temp->cambiar_siguiente(new_node);

    }
    cantidad++;
    // delete new_node;
}


void Lista_Escritores::listar_escritores()
{
    Nodo<D> *temp = primero;
    if (!primero) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->obtener_dato()->mostrar_atributos();
            // if (!temp->next) cout << "NULL";
                temp = temp->obtener_siguiente();
        }
  }
//   cout << endl << endl;
}

// void Lista_Escritores::desplazar_actual(string referencia){
//     actual = ultimo;
//     anterior = nullptr;

//     while (actual->obtener_objeto()->obtener_referencia() != referencia and actual->obtener_objeto()->obtener_nombre_y_apellido() != referencia and actual->obtener_siguiente() != nullptr){

//         anterior = actual;
//         actual = actual->obtener_siguiente();
//     }
// }

 D Lista_Escritores::consulta(string nombre_completo){
    Nodo<D> *temp = primero;
    D escritor = NULL;
   
    while (temp) {
        if ((temp->obtener_dato()->obtener_nombre_completo() == nombre_completo) || (temp->obtener_dato()->obtener_referencia() == nombre_completo)) {
            escritor = temp->obtener_dato();
        }
        temp = temp->obtener_siguiente();
    }
    return escritor;
}

string Lista_Escritores::devolver_nombre_escritor(string nombre_completo){
    Escritor* escritor = consulta(nombre_completo);
    return escritor->obtener_nombre_completo();
}

void Lista_Escritores::modificar_anio_fallecimiento(string nombre_escritor, int nuevo_anio){
    if(consulta(nombre_escritor) != NULL)
        consulta(nombre_escritor)->modificar_anio_fallecimiento(nuevo_anio);
    else
        cout<<"El escritor no se encuentra el escritor en la lista"<<endl;
}

void Lista_Escritores::baja(int pos) {


    Nodo<D>* borrar = primero;
    if (pos == 1){
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<D>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}

void Lista_Escritores::vaciar_lista(){
    while(!vacia()){
        baja(1);
    }
}