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
#include "lista_escritores.h"
#include <cstdlib>
#include "time.h"
#include "cola.h"
// srand(time(NULL));

using namespace std;

Lista_Escritores escritores;
Lista_Lecturas lecturas;
Cola cola;

Parser::Parser( std::string nombre_completo, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, string referencia) {
    
    this->nombre_completo = nombre_completo;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
    this->referencia = referencia;
    // this->escritores = escritores;
    // this->lecturas = lecturas;

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
        escritores.agregar_final(escritor);
        // lista_escritores.insertar_ordenadamente(escritor);
        
        // escritor.mostrar_atributos();
    }   
    archivo_escritores.close();
    // lista_escritores.listar_escritores();
    // lista_escritores.consulta(5).mostrar_atributos();
    
}


void Parser::procesar_lectura(){
    // Lectura* lectura
    // Escritor* escritor;
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
           // novela->mostrar();
           Lectura* nueva_novela; 
            if(genero == "HISTORICA"){
                nueva_novela = new Historica(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), escritores.devolver_nombre_escritor(referencia), genero, tema);
            //    lista_lecturas.insertar_ordenadamente(nueva_novela_historica);
                // lista_lecturas.alta(nueva_novela);
               // novela_historica->mostrar();
            }
            else{
                nueva_novela = new Novela(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), escritores.devolver_nombre_escritor(referencia), genero);
                // lista_lecturas.insertar_ordenadamente(novela_nueva);
                // lista_lecturas.alta(nueva_novela);
            }
        lecturas.alta(nueva_novela);
        }
        else if(tipo_lectura == "C"){
            Lectura* nuevo_cuento = new Cuento(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), escritores.devolver_nombre_escritor(referencia), titulo_libro);
            // lista_lecturas.insertar_ordenadamente(nuevo_cuento);
            lecturas.alta(nuevo_cuento);
            //cuento->mostrar();
        }
        else{
            Lectura *nuevo_poema = new Poema(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion),escritores.devolver_nombre_escritor(referencia) , stoi(cant_versos));
            // lista_lecturas.insertar_ordenadamente(nuevo_poema);
            lecturas.alta(nuevo_poema);
            //poema->mostrar();
        }
        // lista_lecturas.insertar_ordenadamente(lectura);
        // lectura->mostrar();
    }   
        // lista_lecturas.mostrar_lectura(lectura);
        
    // lista_lecturas.~Lista_Lecturas();
    // lecturas.listar_lecturas();
    archivo_lecturas.close();
    // cout<<lecturas.obtener_cantidad()<<endl;
}



int Parser::mostrar_menu(){
    int opcion = 0;
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
    cout<<"Ingrese una opción: ";
    cin>>opcion;
    return opcion;

}


void Parser::procesar_opciones(int opcion){

    // opcion = mostrar_menu(opcion);
    string titulo, tema, genero, titulo_libro, nombre_completo, referencia, nacionalidad,pasar_total;
    char tipo_lectura;
    int minutos, anio_publicacion, cant_versos, cant_total,anio_nacimiento,anio_fallecimiento, valor, anio_1, anio_2,minimo;
    Lectura* lectura;
    Escritor* escritor;
    // int posicion;
    switch(opcion){ 
        case 1: 
            cout<<"Ingrese el tipo de lectura: \n";
            cin>>tipo_lectura;
            cout<< "Ingrese el titulo: \n";
            cin.ignore();
            getline(cin, titulo);
            cout<<"Ingrese el nombre completo del escritor: \n";
            //cin.ignore();
            getline(cin, nombre_completo);
            cout<<"Ingrese la cantidad de minutos: \n";
            cin>>minutos;
            cout<<"Ingrese el año publicacion: \n";
            cin>>anio_publicacion;

            if (tipo_lectura == 'N'){
                cout<< "Ingrese el genero: \n";
                cin>>genero;
                lectura = new Novela(tipo_lectura, titulo, minutos, anio_publicacion, nombre_completo, genero);

                 if(genero == "HISTORICA"){
                    cout<< "Ingrese el tema: \n";
                    cin>>tema;  
                    lectura = new Historica(tipo_lectura, titulo, minutos, anio_publicacion, nombre_completo, genero, tema);

                 }
            }
            else if(tipo_lectura == 'C'){
                cout<< "Ingrese el titulo del libro: \n";
                cin.ignore();
                getline(cin, titulo_libro);

                lectura = new Cuento(tipo_lectura, titulo, minutos, anio_publicacion, nombre_completo , titulo_libro);

            }
            else{
                cout<< "Ingrese la cantidad de versos: \n";
                cin>>cant_versos;
                lectura = new Poema(tipo_lectura, titulo, minutos, anio_publicacion, nombre_completo, cant_versos);
                // lecturas.insertar_ordenadamente(lectura);

            } 
            lecturas.alta(lectura);
            lecturas.listar_lecturas();
            break;

        case 2:
            cout<< "Ingrese el titulo: \n";
            cin>>titulo;
            lecturas.eliminar_por_titulo(titulo);
            lecturas.listar_lecturas();
            break;
        
        case 3:
            cout<<"Ingresa el nombre completo del escritor: \n";
            cin.ignore();
            getline(cin, nombre_completo);
            cout<<"Ingresa la nacionalidad del escritor: \n";
            cin>>nacionalidad;
            cout<<"Ingresa el año de nacimiento del escritor: \n";
            cin>>anio_nacimiento;
            cout<<"Ingresa el año de fallecimiento del escritor: \n";
            cin>>anio_fallecimiento;

            cant_total = escritores.obtener_cantidad() + 1;
            
            pasar_total = to_string(cant_total);
            referencia = "(" + pasar_total + ")";
            escritor = new Escritor(nombre_completo, nacionalidad, anio_nacimiento, anio_fallecimiento, referencia);
            escritores.agregar_final(escritor);
            escritores.listar_escritores();
            break;

        case 4:
            cout<<"Ingresa el nombre del escritor que queres modificar: \n";   
            cin.ignore();
            getline(cin, nombre_completo);
            
            cout<<"Ingrese la fecha de fallecimiento nueva: \n";
            cin>>anio_fallecimiento;
            escritores.modificar_anio_fallecimiento(nombre_completo,anio_fallecimiento);
            escritores.listar_escritores();
            break;
        
        case 5: 
            escritores.listar_escritores();
            break;
        
        case 6:
            srand((unsigned int)time(NULL));
            valor = 1 + rand() % lecturas.obtener_cantidad();
            cout<<"El numero random es: "<< valor<<endl;
            lecturas.sortear_lectura(valor);
            break;
            case 7:
            lecturas.listar_lecturas();
            break;
            
        case 8:
            cout<<"Ingresa desde: ";
            cin>>anio_1;
            cout<<"Hasta: ";
            cin>>anio_2;
            lecturas.listar_entre_anios(anio_1,anio_2);
            break;
        case 9: 
            cout<<"Ingresa el nombre del escritor: \n";
            cin.ignore();
            getline(cin, nombre_completo);
            lecturas.listar_por_escritor(nombre_completo);
            break;

        case 10:
            cout<<"Ingresa el genero: \n";
            cin>>genero;
            lecturas.listar_por_genero(genero);
            break;
    
        case 11:
            minimo = 0;
            for(int i = 0; i < lecturas.obtener_cantidad(); i++){
                cola.alta(lecturas.encontrar_lectura_menor(minimo));
            
            }   
            cola.consulta()->mostrar();
            cola.baja();
            cout<<"Primera baja"<<endl;
            cola.consulta()->mostrar();
            cola.baja();
            cout<<"Segunda baja"<<endl;
            cola.consulta()->mostrar();
            cola.baja();
            cout<<"Tercera baja"<<endl;

            break;
    }



}