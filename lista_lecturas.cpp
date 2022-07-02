#include "lista_lecturas.h"

bool Lista_Lecturas::vacia(){
    return cantidad == 0;
}

int Lista_Lecturas::obtener_cantidad(){
    return cantidad;
}

Lista_Lecturas::Lista_Lecturas(){
    primero = nullptr;
    cantidad = 0;
}

void Lista_Lecturas::listar_por_escritor(string nombre_completo){
    Nodo<Lectura*> *temp = primero;
    int contador = 0;
    
    while(temp){
        if((temp->obtener_dato()->obtener_escritor() != nullptr) && convertir_en_mayuscula(temp->obtener_dato()->obtener_escritor()->obtener_nombre_completo()) == convertir_en_mayuscula(nombre_completo)){
            temp->obtener_dato()->mostrar();
            contador++;
        }
        
        temp = temp->obtener_siguiente();
    }
    if(contador == 0){
        cout<<"No hay niguna obra de " << nombre_completo << "...\n";
    }
}

void Lista_Lecturas::modificar_por_escritor(int isni){
    Nodo<Lectura*> *temp = primero;
    string referencia = "(" + to_string(isni) + ")";
    while(temp){
        
        if((temp->obtener_dato()->obtener_escritor() != nullptr) && (temp->obtener_dato()->obtener_escritor()->obtener_referencia()) == referencia){
            temp->obtener_dato()->modificar_escritor();
        }
        temp = temp->obtener_siguiente();
    }
}

string Lista_Lecturas::convertir_en_mayuscula(string cadena){
    int largo_cadena = (int) cadena.length();
    for(int i = 0; i < largo_cadena; i++) 
        cadena[i] = (char) toupper(cadena[i]);
    return cadena;
}

void Lista_Lecturas::listar_entre_anios(int desde, int hasta){
    Nodo<Lectura*> *temp = primero;
    int contador = 0;
    while(temp){
        if((temp->obtener_dato()->obtener_anio_publicacion()) >= desde && (temp->obtener_dato()->obtener_anio_publicacion()) <= hasta ){
            temp->obtener_dato()->mostrar();
            contador++;
        }
        temp = temp->obtener_siguiente();
    }
    if(contador == 0){
        cout<<"No hay ninguna lectura entre esos años... \n";
    }
}

void Lista_Lecturas::alta(Lectura* dato){
    Nodo<Lectura*> *nuevo_nodo = new Nodo<Lectura*> (dato);
    Nodo<Lectura*> *temp = primero;
    if (!primero || (primero->obtener_dato()->obtener_anio_publicacion()) > (dato->obtener_anio_publicacion())) {
        
        nuevo_nodo->cambiar_siguiente(primero);
        primero = nuevo_nodo;
    }
    else {
            while((temp->obtener_siguiente() != NULL) && ((temp->obtener_siguiente()->obtener_dato()->obtener_anio_publicacion()) < (dato->obtener_anio_publicacion()))) {
                temp = temp->obtener_siguiente();
            }
            nuevo_nodo->cambiar_siguiente(temp->obtener_siguiente());
            temp->cambiar_siguiente(nuevo_nodo);
        }        
    cantidad++; 
}

void Lista_Lecturas::listar_por_genero(string genero_recibido){
    Nodo<Lectura*> *temp = primero;
    int contador = 0;
    while (temp) {
        if (toupper(temp->obtener_dato()->obtener_tipo_lectura()) == TIPO_NOVELA ) {
            if(temp->obtener_dato()->obtener_atributo_diferente() == convertir_en_mayuscula(genero_recibido)){
                temp->obtener_dato()->mostrar();
                contador++;
            }
        }
        temp = temp->obtener_siguiente();
    }
    if(contador == 0){
        cout<<"No hay ninguna lectura con ese genero...\n";
    }
}

int Lista_Lecturas::buscar_titulo(string titulo_buscado){
    Nodo<Lectura*> *temp = primero;
    int cont = 0;
    while (convertir_en_mayuscula(temp->obtener_dato()->obtener_titulo()) !=  convertir_en_mayuscula(titulo_buscado)) {
        cont++;
        temp = temp->obtener_siguiente();
    }
    cont++;
    return cont;
}

Lectura* Lista_Lecturas::consulta_titulo(string titulo){
    Nodo<Lectura*> *temp = primero;
    Lectura* lectura = NULL;
    bool lectura_encontrada = false;
    while (temp && !lectura_encontrada) {
        if (convertir_en_mayuscula(temp->obtener_dato()->obtener_titulo()) == convertir_en_mayuscula(titulo)){
            lectura = temp->obtener_dato();
            lectura_encontrada = true;
        }
        temp = temp->obtener_siguiente();
    }
    return lectura;
}

Lectura* Lista_Lecturas::encontrar_lectura_menor(int &minimo){
    Nodo<Lectura*> *temp = primero;
    Lectura* lectura = NULL;
    int minimo_temporal = 0;
    while(temp){
        
        if(minimo < temp->obtener_dato()->obtener_tiempo_lectura() && temp->obtener_dato()->obtener_tiempo_lectura() < minimo_temporal){ 
            minimo_temporal = temp->obtener_dato()->obtener_tiempo_lectura();
            lectura = temp->obtener_dato();
        }
        else if(minimo_temporal == 0 && minimo < temp->obtener_dato()->obtener_tiempo_lectura()){
            minimo_temporal = temp->obtener_dato()->obtener_tiempo_lectura();
            lectura = temp->obtener_dato();
        }
        
        temp = temp->obtener_siguiente(); 
    }
    minimo = minimo_temporal;
    return lectura;
}


void Lista_Lecturas::sortear_lectura(int numero){
    int i = 1;
    Nodo<Lectura*> *temp = primero;
    Lectura* lectura_sorteada = NULL;

    while(temp){
        if(i == numero){
            lectura_sorteada = temp->obtener_dato();
        }
        temp = temp->obtener_siguiente();
        i++;
    }
    lectura_sorteada->mostrar();
}

Nodo<Lectura*>* Lista_Lecturas::obtener_nodo(int pos) {
    Nodo<Lectura*>* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}

void Lista_Lecturas::baja(string titulo) {
    int pos = buscar_titulo(titulo);
    baja(pos);
}

void Lista_Lecturas::baja(int pos) {
    Nodo<Lectura*>* borrar = primero;
    if (pos == 1){
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<Lectura*>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar->obtener_dato();
    delete borrar;
}

void Lista_Lecturas::vaciar_lista(){
    while(!vacia()){
        baja(1);
    }
}

void Lista_Lecturas::listar_lecturas(){
    for(int i=1; i <= obtener_cantidad(); i++){
        obtener_nodo(i)->obtener_dato()->mostrar();
    }   
}

int Lista_Lecturas::procesar_genero(string genero){
    int genero_procesado = 0;
    if(genero == "DRAMA"){
        genero_procesado = DRAMA;
    }else if(genero == "COMEDIA"){
        genero_procesado = COMEDIA;
    }else if(genero == "FICCION"){
        genero_procesado = FICCION;
    }else if(genero == "SUSPENSO"){
        genero_procesado = SUSPENSO;
    }else if(genero == "TERROR"){
        genero_procesado = TERROR;
    }else if(genero == "ROMANTICA"){
        genero_procesado = ROMANTICA;
    }else if(genero == "HISTORICA"){
        genero_procesado = HISTORICA;
    }
    return genero_procesado;
}

Lectura* Lista_Lecturas::obtener_lectura(int pos){
    return obtener_nodo(pos)->obtener_dato();
}
