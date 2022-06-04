#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "lista_escritores.h"
#include "lista_lecturas.h"
#include <iostream>
#include <string>
#include "parser.h"
#include <fstream>
#include "historica.h"
#include "cuento.h"
#include "novela.h"
#include "poema.h"
#include "constantes.h"
#include <cstdlib>
#include "time.h"

using namespace std;

class Parser {
private:
    Lista_Escritores lista_escritores;
    Lista_Lecturas lista_lecturas;
    
public:
    //Constructor
    Parser();
    /*
    PRE: Debe existir un archivo .txt llamado escritores.txt.
    POST: Se encarga de leer el archivo de escritores y crear la lista de escritor.
    */
    void procesar_escritores();
    /*
    PRE: Debe existir un archivo .txt llamado lecturas.txt.
    POST: Se encarga de leer el archivo de lectura y crear la lista de las lecturas.
    */
    void procesar_lectura();
    /*
    PRE: Recibe una lista cargada.
    POST: Se encarga de devolver la lista_escritores.
    */
    Lista_Escritores devolver_escritores(); 
    /*
    PRE: Recibe una lista cargada.
    POST: Se encarga de devolver las lista_lecturas.
    */
    Lista_Lecturas devolver_lecturas();
};




#endif