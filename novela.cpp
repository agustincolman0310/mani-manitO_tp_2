#include <iostream>
#include "novela.h"
#include "string.h"


Novela::Novela(char tipo_lectura, std::string titulo,int minutos, int anio_publicacion, Escritor* escritor, int genero)
    :Lectura(tipo_lectura, titulo, minutos, anio_publicacion, escritor){
        this->genero = genero;
}

void Novela::mostrar(){
    std::cout<< "El tipo de lectura es: "<< tipo_lectura<< std::endl;
    std::cout<< "El titulo es: "<< titulo<< std::endl;
    std::cout<< "La lectura lleva: "<< minutos << " minutos"<< std::endl;
    std::cout<< "La lectura fue publicada en: "<< anio_publicacion << std::endl;
    if(escritor != NULL){
        cout<< "El escritor es: " << escritor->obtener_nombre_completo() << std::endl;
    }
    else{
        escritor->modificar_nombre();
        cout<< "El escritor es: ANONIMO" << std::endl;
    }
    std::cout<< "El genero es: "<< convertir_genero(genero)<< std::endl;
    std::cout<<"\n";
}

string Novela::convertir_genero(int genero){                                                                                                                                                                                                                                                                                                                                                                                    
    string genero_convertido;
    if(genero == DRAMA){
        genero_convertido = "DRAMA";
    }else if(genero == COMEDIA){
        genero_convertido = "COMEDIA";
    }else if(genero == FICCION){
        genero_convertido = "FICCION";
    }else if(genero == SUSPENSO){
        genero_convertido = "SUSPENSO";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    }else if(genero == TERROR){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
        genero_convertido = "TERROR";
    }else if(genero == ROMANTICA){
        genero_convertido = "ROMANTICA";
    }else if(genero == HISTORICA){
        genero_convertido = "HISTORICA";
    }
    return genero_convertido;
}

string Novela::obtener_atributo_diferente(){
    return convertir_genero(genero);
}

void Novela::modificar_referencia(){
    escritor = NULL;
}

