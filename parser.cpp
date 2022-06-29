#include "parser.h"
#include <string>
using namespace std;

 Parser::Parser() {
      this->tabla_escritores = tabla_escritores;
      this->lista_lecturas = lista_lecturas;
 }

void Parser::procesar_escritores(){

    fstream archivo_escritores(RUTA_ARCHIVO_ESCRITORES, ios::in);  
    if(!archivo_escritores.is_open()){
        cout << "No se encontró un archivo con nombre " << RUTA_ARCHIVO_ESCRITORES << ", se va a crear el archivo" << endl;
        archivo_escritores.open(RUTA_ARCHIVO_ESCRITORES, ios::out);
        archivo_escritores.close();
        archivo_escritores.open(RUTA_ARCHIVO_ESCRITORES, ios::in);
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
            anio_nacimiento = ANIO_NO_ENCONTRADO;
        }
        if(anio_fallecimiento.empty()){
            anio_fallecimiento = ANIO_NO_ENCONTRADO;
        }
        else{
            getline(archivo_escritores,linea_espacio);
        }
        Escritor* escritor = new Escritor(nombre_completo, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento), referencia);

        tabla_escritores.insertar_escritor(escritor);
    }   
    archivo_escritores.close();
}


void Parser::procesar_lectura(){
    Lectura* nueva_lectura;
    fstream archivo_lecturas(RUTA_ARCHIVO_LECTURAS, ios::in);  
    if(!archivo_lecturas.is_open()){
        cout << "No se encontró un archivo con nombre " << RUTA_ARCHIVO_LECTURAS << ", se va a crear el archivo" << endl;
        archivo_lecturas.open(RUTA_ARCHIVO_LECTURAS, ios::out);
        archivo_lecturas.close();
        archivo_lecturas.open(RUTA_ARCHIVO_LECTURAS, ios::in);
    }
    string tipo_lectura, titulo, minutos, anio_publicacion, genero, tema, cant_versos, titulo_libro, linea_espacio, referencia;
    while(getline(archivo_lecturas, tipo_lectura)){
        getline(archivo_lecturas, titulo);
        getline(archivo_lecturas, minutos);
        getline(archivo_lecturas, anio_publicacion);
        if(tipo_lectura == NOVELA){
            getline(archivo_lecturas, genero);
            if(genero == NOVELA_HISTORICA){
                getline(archivo_lecturas, tema);
            }
        }
        else if(tipo_lectura == CUENTO){
            getline(archivo_lecturas, titulo_libro);
        }
        else{
            getline(archivo_lecturas, cant_versos);
        }
        
        getline(archivo_lecturas, referencia);
        getline(archivo_lecturas, linea_espacio); 
        
        if(tipo_lectura == NOVELA){ 
            if(genero == NOVELA_HISTORICA){
                nueva_lectura = new Historica(tipo_lectura[PRIMER_CARACTER], titulo, stoi(minutos), stoi(anio_publicacion), tabla_escritores.consulta(referencia), lista_lecturas.procesar_genero(genero), const_cast<char*>(tema.c_str()));
           } else{
                nueva_lectura = new Novela(tipo_lectura[PRIMER_CARACTER], titulo, stoi(minutos), stoi(anio_publicacion), tabla_escritores.consulta(referencia), lista_lecturas.procesar_genero(genero));
            }                                                                                                                                                           
        }
        else if(tipo_lectura == CUENTO){
            nueva_lectura = new Cuento(tipo_lectura[PRIMER_CARACTER], titulo, stoi(minutos), stoi(anio_publicacion), tabla_escritores.consulta(referencia), titulo_libro);
        }
        else{
            nueva_lectura = new Poema(tipo_lectura[PRIMER_CARACTER], titulo, stoi(minutos), stoi(anio_publicacion), tabla_escritores.consulta(referencia) , stoi(cant_versos));

        }
    lista_lecturas.alta(nueva_lectura);
    }   
    archivo_lecturas.close();
}

Lista_Lecturas Parser::devolver_lecturas(){
    return lista_lecturas;
}

Tabla_Hashing Parser::devolver_escritores(){
    return tabla_escritores;
}