#include <iostream>
#include "archivos.h"
#include <fstream>

using namespace std;

const int MOSTRAR_ESCRITORES = 1;
const int ELIMINAR_ESCRITOR = 2;
const int AGREGAR_ESCRITOR = 3;
const int BUSCAR_ESCRITOR = 4;
const int ERROR = -1;
const string PATH_ESCRITORES = "escritores.txt";

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

void cargar_escritores(Escritor* escritor){
    
    fstream archivo_escritores(PATH_ESCRITORES, ios::in);

    if(!archivo_escritores.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH_ESCRITORES << "\", se va a crear el archivo" << endl;
        archivo_escritores.open(PATH_ESCRITORES, ios::out);
        archivo_escritores.close();
        archivo_escritores.open(PATH_ESCRITORES, ios::in);
    }

    string referencia, nombre_completo, nacionalidad, anio_nacimiento, anio_fallecimiento;

    while(getline(archivo_escritores,referencia)){
        getline(archivo_escritores,nombre_completo);
        getline(archivo_escritores,nacionalidad);
        getline(archivo_escritores,anio_nacimiento);
        getline(archivo_escritores,anio_fallecimiento);
        
        
        escritor = new Escritor;
        escritor -> referencia = stoi(referencia);
        escritor -> nombre_completo = nombre_completo;
        escritor -> nacionalidad = nacionalidad;
        escritor -> anio_nacimiento = stoi(anio_nacimiento);
        escritor -> anio_fallecimiento = stoi(anio_fallecimiento);
    }

    archivo_escritores.close();
}

void cargar_lecturas(Lectura* lectura){
    
    fstream archivo_escritores(PATH_LECTURA, ios::in);
    /*Poema* poema;
    Cuento* cuento;
    Novela* novela;
    Historica* historica;*/ // no se si está bien
    if(!archivo_lecturas.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH_LECTURA << "\", se va a crear el archivo" << endl;
        archivo_lecturas.open(PATH_LECTURA, ios::out);
        archivo_lecturas.close();
        archivo_lecturas.open(PATH_LECTURA, ios::in);
    }

    string titulo, minutos, anio_publicacion, tipo_lectura, genero, tema, libro, cant_versos, referencia_autor;

    while(getline(archivo_lecturas, tipo_lectura)){
        getline(archivo_lecturas, titulo);
        getline(archivo_lecturas, minutos);
        getline(archivo_lecturas, anio_publicacion);
        if(tipo_lectura = 'N'){
            getline(archivo_lecturas, genero);
            if(genero == 'HISTORICA'){
                getline(archivo_lecturas, tema); 
            }
            novela -> genero = genero;
            //historica -> tema = tema;
        }
        else if(tipo_lectura = 'C'){
            getline(archivo_lecturas, libro);  
        }
        else if(tipo_lectura = 'P'){
            getline(archivo_lecturas, cant_versos);  
           // poema-> cant_versos = stoi(cant_versos);

        }
        getline(archivo_lecturas, referencia_autor);
        
        
        lectura = new lectura;
    
        lectura -> tipo_lectura = tipo_lectura;
        lectura -> titulo = titulo;
        lectura -> minutos = stoi(minutos);
        lectura -> anio_publicacion = stoi(anio_publicacion);
        lectura -> referencia = stoi(referencia);
    }
    archivo_lecturas.close();
}
