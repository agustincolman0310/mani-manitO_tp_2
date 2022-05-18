#include <iostream>
#include "archivos.h"
#include <fstream>
#include <string>
using namespace std;

const int MOSTRAR_ESCRITORES = 1;
const int ELIMINAR_ESCRITOR = 2;
const int AGREGAR_ESCRITOR = 3;
const int BUSCAR_ESCRITOR = 4;
const int ERROR = -1;
const string PATH_ESCRITORES = "escritores.txt";
const string PATH_LECTURA = "lectura.txt";

void mostrar_menu(){
    cout << endl << endl << endl;
    cout << "MENU" << endl
    << '\t' << "1_ Ver todos los escritores" << endl
    << '\t' << "2_ Eliminar un escritor" << endl
    << '\t' << "3_ Agregar un escritor" << endl
    << '\t' << "4_ Buscar un escritor " << endl
    << '\t' << "5_ Guardar escritores y salir" << endl;
}

int pedir_opcion(){
    int opcion_elegida = ERROR;
    cout << "Ingrese el número de su acción elegida : ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

void validar_opcion_elegida(int &opcion_elegida){
    bool es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= OPCIONES_VALIDAS;
    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= OPCIONES_VALIDAS;
    }
}

void cargar_escritores(Escritor escritor){  
    fstream archivo_escritores("escritores.txt", ios::in);  
    if(!archivo_escritores.is_open()){
        cout << "No se encontro un archivo con nombre " << "escritores.txt" << ", se va a crear el archivo" << endl;
        archivo_escritores.open("escritores.txt", ios::out);
        archivo_escritores.close();
        archivo_escritores.open("escritores.txt", ios::in);
    }   
    string referencia, nombre_completo, nacionalidad, anio_nacimiento, anio_fallecimiento, linea_espacio;
    while(getline(archivo_escritores, referencia)){
        getline(archivo_escritores,nombre_completo);
        getline(archivo_escritores,nacionalidad);
        getline(archivo_escritores,anio_nacimiento);
        getline(archivo_escritores,anio_fallecimiento);
        getline(archivo_escritores, linea_espacio); 
    
        escritor.obtener_referencia(referencia);
        escritor.obtener_nombre_completo(nombre_completo);
        escritor.obtener_nacionalidad(nacionalidad);
        escritor.obtener_anio_fallecimiento(stoi(anio_fallecimiento));
        escritor.obtener_anio_nacimiento(stoi(anio_nacimiento));
            
        cout << "N° referencia: " << escritor.devolver_referencia() << endl;
        cout << "Nombre completo: " << escritor.devolver_nombre_completo() << endl;
        cout << "Nacionalidad: " << escritor.devolver_nacionalidad() << endl;
        cout << "Año nacimiento: " << escritor.devolver_anio_nacimiento() << endl;
        cout << "Año fallecimiento: " << escritor.devolver_anio_fallecimiento() << endl;
        cout << "\n";
    }   
    archivo_escritores.close();
}

