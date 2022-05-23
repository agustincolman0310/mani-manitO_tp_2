#include <iostream>
#include <string>
#include "parser.h"
#include <fstream>
#include "lista.h"
#include "escritor.h"
#include "historica.h"
#include "lectura.h"
#include "cuento.h"
#include "novela.h"
#include "poema.h"
#include "constantes.h"

using namespace std;

Lista <Escritor> lista_escritores;
Lista <Lectura> lista_lectura;

Parser::Parser(std::string nombre_completo, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, string referencia) {
    
    this->nombre_completo = nombre_completo;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
    this->referencia = referencia;

}


void Parser::procesar_escritores(){
    // Escritor escritor;
    fstream archivo_escritores(RUTA_ARCHIVO_ESCRITORES, ios::in);  
    if(!archivo_escritores.is_open()){
        cout << "No se encontro un archivo con nombre " << RUTA_ARCHIVO_ESCRITORES << ", se va a crear el archivo" << endl;
        archivo_escritores.open(RUTA_ARCHIVO_ESCRITORES, ios::out);
        archivo_escritores.close();
        archivo_escritores.open(RUTA_ARCHIVO_ESCRITORES, ios::in);
    }   
    string referencia, nombre_completo, nacionalidad, anio_nacimiento, anio_fallecimiento, linea_espacio;
    int n = 1;
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
        // escritor.
        Escritor escritor(nombre_completo, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento), referencia);
        lista_escritores.alta(escritor,n);
        n++;
        // escritor.mostrar_atributos();
    }   
    archivo_escritores.close();
    lista_escritores.consulta(5).mostrar_atributos();
}


void Parser::procesar_lectura(){
    // Lectura* lectura;
    fstream archivo_lecturas(RUTA_ARCHIVO_LECTURAS, ios::in);  
    if(!archivo_lecturas.is_open()){
        cout << "No se encontro un archivo con nombre " << RUTA_ARCHIVO_LECTURAS << ", se va a crear el archivo" << endl;
        archivo_lecturas.open(RUTA_ARCHIVO_LECTURAS, ios::out);
        archivo_lecturas.close();
        archivo_lecturas.open(RUTA_ARCHIVO_LECTURAS, ios::in);
    }   
    string tipo_lectura, titulo, minutos, anio_publicacion, genero, tema, cant_versos, titulo_libro, linea_espacio, referencia;
    int n = 1;
    while(getline(archivo_lecturas, tipo_lectura)){
        getline(archivo_lecturas, titulo);
        getline(archivo_lecturas, minutos);
        getline(archivo_lecturas, anio_publicacion);
        if(tipo_lectura == "N"){
            getline(archivo_lecturas, genero);
            if(genero == "HISTORICA"){
                getline(archivo_lecturas, tema);
            }
        }
        else if(tipo_lectura == "C"){
            getline(archivo_lecturas, titulo_libro);
        }
        else{
            getline(archivo_lecturas, cant_versos);
        }

        getline(archivo_lecturas, referencia);
        getline(archivo_lecturas, linea_espacio); 

        if(tipo_lectura == "N"){
            Novela novela(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), referencia, genero);
            //novela.mostrar();
            if(genero == "HISTORICA"){
                Historica historica(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), referencia, genero, tema);
                //historica.mostrar();
            }
        }
        else if(tipo_lectura == "C"){
            Cuento cuento(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), referencia, titulo_libro);
            //cuento.mostrar();
        }
        else{
            Poema poema(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), referencia, stoi(cant_versos));
            //poema.mostrar();
        }
        
    }   
    archivo_lecturas.close();
}
