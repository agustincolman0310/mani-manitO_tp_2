#include "lista_escritores.h"
#include "nodo.h"

Nodo<Escritor*>* Lista_Escritores::obtener_nodo(int pos) {
    Nodo<Escritor*>* aux = primero;
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
    actual = nullptr;
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
    for(int i = 0; i < largo_cadena; i++) 
        cadena[i] = (char) toupper(cadena[i]);
    return cadena;
}

 Escritor* Lista_Escritores::consulta(string nombre_completo){
    Nodo<Escritor*> *temp = primero;
    Escritor* escritor = NULL;
    
    while (temp) {
        if ((convertir_en_mayuscula(temp->obtener_dato()->obtener_nombre_completo()) == convertir_en_mayuscula(nombre_completo)) || (convertir_en_mayuscula(temp->obtener_dato()->obtener_referencia()) == convertir_en_mayuscula(nombre_completo))) {
            escritor = temp->obtener_dato();
        }
        temp = temp->obtener_siguiente();
    }
    return escritor;
}

void Lista_Escritores::modificar_anio_fallecimiento(string nombre_escritor, int nuevo_anio){
    if(consulta(nombre_escritor) != NULL)
        consulta(nombre_escritor)->modificar_anio_fallecimiento(nuevo_anio);
    else
        cout<<"El escritor no se encuentra el escritor en la lista"<<endl;
}

void Lista_Escritores::baja(int pos) {
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
}

void Lista_Escritores::vaciar_lista(){
    while(!vacia()){
        baja(1);
    }

}