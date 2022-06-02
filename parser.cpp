#include "parser.h"
#include <string>
using namespace std;

 Parser::Parser() {
      this->lista_escritores_1 = lista_escritores_1;
      this->lista_lecturas_1 = lista_lecturas_1;
 }
/*string Parser::a_mayuscula(string cadena){
    for(int i = 0; i < cadena.lenght(); i++) cadena[i] = toupper(cadena[i];)
    return cadena;
}*/

void Parser::procesar_escritores(){

    fstream archivo_escritores(RUTA_ARCHIVO_ESCRITORES, ios::in);  
    if(!archivo_escritores.is_open()){
        cout << "No se encontro un archivo con nombre " << RUTA_ARCHIVO_ESCRITORES << ", se va a crear el archivo" << endl;
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
            anio_nacimiento = "-1";
        }
        if(anio_fallecimiento.empty()){
            anio_fallecimiento = "-1";
        }
        else{
            getline(archivo_escritores,linea_espacio);
        }
       
        Escritor* escritor = new Escritor(nombre_completo, nacionalidad, stoi(anio_nacimiento), stoi(anio_fallecimiento), referencia);
        // delete escritor;
        lista_escritores_1.agregar_final(escritor);
        
    }   
    archivo_escritores.close();
    lista_escritores_1.listar_escritores();
    lista_escritores_1.vaciar_lista();
}


void Parser::procesar_lectura(){
    Lectura* nueva_lectura;
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
            // Lectura* nueva_novela;
            if(genero == "HISTORICA"){
                
                nueva_lectura = new Historica(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), lista_escritores_1.consulta(referencia), genero, tema);
            
            }
            else{
                nueva_lectura = new Novela(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), lista_escritores_1.consulta(referencia), genero);
            }


        // lista_lecturas_1.alta(nueva_novela);

        }
        else if(tipo_lectura == "C"){

            nueva_lectura = new Cuento(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion), lista_escritores_1.consulta(referencia), titulo_libro);
            // lista_lecturas_1.alta(nuevo_cuento);
        }
        else{
            nueva_lectura= new Poema(tipo_lectura[0], titulo, stoi(minutos), stoi(anio_publicacion),lista_escritores_1.consulta(referencia) , stoi(cant_versos));
            // lista_lecturas_1.alta(nuevo_poema);

        }
    lista_lecturas_1.alta(nueva_lectura);
    }   
    archivo_lecturas.close();
    // delete nueva_lectura;
    // lista_lecturas_1.listar_lecturas();

}

Lista_Lecturas Parser::devolver_lecturas(){
    return lista_lecturas_1;
}

Lista_Escritores Parser::devolver_escritores(){
    return lista_escritores_1;
}

// Parser::~Parser(){};