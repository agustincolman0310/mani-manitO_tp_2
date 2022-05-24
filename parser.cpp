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
#include "menu.cpp"
#include "constantes.h"
#include "lista_lecturas.h"

using namespace std;

Lista_Lecturas lista_lecturas;
Lista <Escritor> lista_escritores;


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
    // int n = 1;
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
        Escritor* escritor = new Escritor(nombre_completo, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento), referencia);
        lista_escritores.insertar_en_final(*escritor);
        
        // escritor.mostrar_atributos();
    }   
    archivo_escritores.close();
    // lista_escritores.consulta(5).mostrar_atributos();
}


void Parser::procesar_lectura(){
    Lectura* lectura;
    fstream archivo_lecturas(RUTA_ARCHIVO_LECTURAS, ios::in);  
    if(!archivo_lecturas.is_open()){
        cout << "No se encontro un archivo con nombre " << RUTA_ARCHIVO_LECTURAS << ", se va a crear el archivo" << endl;
        archivo_lecturas.open(RUTA_ARCHIVO_LECTURAS, ios::out);
        archivo_lecturas.close();
        archivo_lecturas.open(RUTA_ARCHIVO_LECTURAS, ios::in);
    }   
    string tipo_lectura, titulo, minutos, anio_publicacion, genero, tema, cant_versos, titulo_libro, linea_espacio, referencia;
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
            lectura = new Novela(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), referencia, genero);
            // lista_lecturas.insertar_ordenadamente(novela);
           // novela->mostrar();
            if(genero == "HISTORICA"){
                lectura = new Historica(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), referencia, genero, tema);
               // lista_lecturas.insertar_ordenadamente(novela_historica);
               // novela_historica->mostrar();
            }
        }
        else if(tipo_lectura == "C"){
            lectura = new Cuento(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), referencia, titulo_libro);
            //lista_lecturas.insertar_ordenadamente(cuento);
            //cuento->mostrar();
        }
        else{
            lectura = new Poema(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), referencia, stoi(cant_versos));
            //lista_lecturas.insertar_ordenadamente(poema);
            //poema->mostrar();
        }
        lista_lecturas.insertar_ordenadamente(lectura);
        // lectura->mostrar();
    }   
        // lista_lecturas.mostrar_lectura(lectura);
        
    // lista_lecturas.~Lista_Lecturas();
    archivo_lecturas.close();
}



void mostrar_menu(int opcion){
    
    cout<<"\t1- Agregar nueva lectura.\n"; //agregar_lectura();
    cout<<"\t2- Quitar una lectura.\n"; //quitar_lectura();
    cout<<"\t3- Agregar escritor.\n"; //agregar_escritor();
    cout<<"\t4- Cambiar dato de un escritor.\n"; //modificar_escritor()
    cout<<"\t5- Listar escritores.\n"; //listar_escritores();
    cout<<"\t6- Sortear lecturas random.\n"; //sortear_lectura();
    cout<<"\t7- Listar todas las lecturas.\n"; //listar_lecturas();
    cout<<"\t8- Listar lecturas entre años.\n"; //listar_lecturas_entre();
    cout<<"\t9- Listar lecturas por escritor.\n"; //listar_por_escritor();
    cout<<"\t10- Listar novelas por género.\n";//listar_novela_por_genero();
    cout<<"\t11- Armar cola ordenada por tiempo de lectura.\n";//ordenar_por_tiempo_lectura();
    cout<<"\t12- Salir.\n";
    
    //A partir de acá, otro procedimiento
    cin>>opcion;

}


void Parser::procesar_opciones(int opcion){
    string titulo, tema, genero, titulo_libro, nombre_completo, referencia;
    char tipo_lectura;
    int minutos, anio_publicacion, cant_versos;
    Lectura* lectura;
    int posicion;
    switch(opcion){ 
        case 1: 
            cout<<"Ingrese el tipo de lectura: \n";
            cin>>tipo_lectura;
            cout<< "Ingrese el titulo: \n";
            cin>>titulo;
            cout<<"Ingrese el nombre completo del escritor : \n";
            cin>>nombre_completo; 
            cout<<"Ingrese la cantidad de minutos: \n";
            cin>>minutos;
            cout<<"Ingrese el año publicacion: \n";
            cin>>anio_publicacion;

            if (tipo_lectura == 'N'){
                cout<< "Ingrese el genero: \n";
                cin>>genero;
                lectura = new Novela(tipo_lectura, titulo, minutos, anio_publicacion, referencia, genero);

                 if(genero == "HISTORICA"){
                    cout<< "Ingrese el tema: \n";
                    cin>>tema;  
                    lectura = new Historica(tipo_lectura, titulo, minutos, anio_publicacion, referencia, genero, tema);

                 }
            }
            else if(tipo_lectura == 'C'){
                cout<< "Ingrese el titulo del ibro : \n";
                cin>>titulo_libro;
                lectura = new Cuento(tipo_lectura, titulo, minutos, anio_publicacion, referencia, titulo_libro);

            }
            else{
                cout<< "Ingrese la cantidad de versos : \n";
                cin>>cant_versos;
                lectura = new Poema(tipo_lectura, titulo, minutos, anio_publicacion, referencia, cant_versos);

            } 
            lista_lecturas.insertar_ordenadamente(lectura);
            break;

        case 2:
            cout<< "Ingrese el titulo: \n";
            cin>>titulo;
            posicion = lista_lecturas.buscar_titulo(titulo);
            lista_lecturas.baja(posicion);
            break;
        
        case 3:
            cout<<"Ingresa el nombre completo del escritor : \n";

    }

    
}
