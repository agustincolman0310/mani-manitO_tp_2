#include <string>
#include <iostream>
#include "parser.h"
using namespace std;

/*Parser::Parser(std::string nombre_completo, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int referencia) {
    
    this->nombre_completo = nombre_completo;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
    this->referencia = referencia;

}*/


void Parser::procesar_escritores(Escritor escritor){
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
        if(!anio_nacimiento.empty()){
            getline(archivo_escritores,anio_fallecimiento);              
        }
        else{
            anio_nacimiento = "-1";
        }
        if(anio_fallecimiento.empty()){
            anio_fallecimiento = "-1";
        }
        else{
            getline(archivo_escritores,linea_espacio);
        }
        escritor(nombre_completo, nacionalidad, anio_nacimiento, anio_fallecimiento, referencia);
            
        mostrar_atributos(nombre_completo, nacionalidad, anio_nacimiento, anio_fallecimiento, referencia);
    }   
    archivo_escritores.close();

}


void Parser::procesar_lectura(Lectura lectura){
    fstream archivo_escritores("lecturas.txt", ios::in);  
    if(!archivo_lecturas.is_open()){
        cout << "No se encontro un archivo con nombre " << "lecturas.txt" << ", se va a crear el archivo" << endl;
        archivo_lecturas.open("lecturas.txt", ios::out);
        archivo_lecturas.close();
        archivo_lecturas.open("lecturas.txt", ios::in);
    }   
    string tipo_lectura, titulo, minutos, anio_publicacion, genero, tema, cant_versos, titulo_libro, linea_espacio, referencia;
    while(getline(archivo_lecturas, tipo_lectura)){
        getline(archivo_lecturas, titulo);
        getline(archivo_lecturas,anio_publicacion);
        if(tipo_lectura == "N"){
            getline(archivo_lecturas, genero);
            if(genero == "HISTORICA"){
                getline(archivo_lecturas, tema);
                Historica historica;
            }
        }
        else if(tipo_lectura == "C"){
            getline(archivo_lecturas, titulo_libro);
        }
        else{
            getline(archivo_lecturas, cant_versos);
        }
        getline(archivo_lecturas, referencia)
        getline(archivo_lecturas, linea_espacio); 
       
    }   
    archivo_lecturas.close();
}
