#include <iostream>
#include "lectura.h"
#include "cuento.h"
#include "novela.h"
#include "poema.h"
#include "historica.h"
#include <string>
#include "lista_lecturas.h"
using namespace std;

// Lista_Lecturas lista_lecturas;

void mostrar_menues(){
    string titulo, tema, genero, titulo_libro, nombre_completo, referencia;
    char tipo_lectura;
    int minutos, anio_publicacion, cant_versos;
    int opcion;
    Lectura* lectura;
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
    }
}

// void procesar_opcion(lista_lecturas){
//     lista_lecturas.insertar_ordenadamente(tata);
// }