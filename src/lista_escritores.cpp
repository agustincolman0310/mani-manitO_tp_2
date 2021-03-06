#include "../header/lista_escritores.h"
#include "../header/nodo.h"

Nodo<Escritor*>* Lista_Escritores::obtener_nodo(int pos) {
    Nodo<Escritor*>* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}

Lista_Escritores::Lista_Escritores(){
    cantidad = 0;
    primero = nullptr;
}

int Lista_Escritores::obtener_cantidad(){
    return cantidad;
}

void Lista_Escritores::alta(Escritor* dato, int posicion){
    Nodo<Escritor*>* nuevo = new Nodo<Escritor*>(dato);
    if (posicion == 1){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else{
        Nodo<Escritor*>* aux = obtener_nodo(posicion - 1);
        nuevo -> cambiar_siguiente(aux -> obtener_siguiente());
        aux -> cambiar_siguiente(nuevo);
    }
    cantidad++;
}

void Lista_Escritores::alta(Escritor* dato){
    int posicion_final = obtener_cantidad() + 1;
    alta(dato, posicion_final);
}

bool Lista_Escritores::vacia(){
    return cantidad == 0;
}

void Lista_Escritores::listar_escritores(){
    for(int i=1; i <= obtener_cantidad(); i++){
        obtener_nodo(i)->obtener_dato()->mostrar_atributos();
    }
}

string Lista_Escritores::convertir_en_mayuscula(string cadena){
    int largo_cadena = (int) cadena.length();
    for(int i = 0; i < largo_cadena; i++){
        cadena[i] = (char) toupper(cadena[i]);
    }
    return cadena;
}

Escritor* Lista_Escritores::consulta(string atributo){
    Nodo<Escritor*> *temp = primero;
    Escritor* escritor = NULL;
    
    while (temp) {
        if (temp->obtener_dato()->obtener_referencia() == atributo) {
            escritor = temp->obtener_dato();
        }
        temp = temp->obtener_siguiente();
    }
    return escritor;


}

int Lista_Escritores::buscar_referencia(string referencia){
    Nodo<Escritor*> *temp = primero;
    int cont = 0;
    while ((temp->obtener_dato()->obtener_referencia() !=  referencia))  {
        cont++;
        temp = temp->obtener_siguiente();
    }
    cont++;
    return cont;
}

void Lista_Escritores::baja_nodo(int pos) {
    Nodo<Escritor*>* borrar = primero;
    if (pos == 1){
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<Escritor*>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar->obtener_dato();
    delete borrar;
    borrar = nullptr;
}

void Lista_Escritores::baja(int isni){
    string referencia = "(" + to_string(isni) + ")";
    int posicion = buscar_referencia(referencia);
    baja_nodo(posicion);
}

void Lista_Escritores::vaciar_lista(){
    while(!vacia()){
        baja_nodo(1);
    }
}

void Lista_Escritores::listar_referencias(){
    for(int i=1; i <= obtener_cantidad(); i++){
        obtener_nodo(i)->obtener_dato()->mostrar_referencia();
    }
}