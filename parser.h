#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "lista_escritores.h"
#include "lista_lecturas.h"
#include <iostream>
#include <string>
#include "parser.h"
#include <fstream>
#include "lista.h"
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
    Lista_Escritores lista_escritores_1;
    Lista_Lecturas lista_lecturas_1;



public:
    Parser();
    // ~Parser(){};
    void procesar_escritores();
    void procesar_lectura();
    Lista_Escritores devolver_escritores(); 
    Lista_Lecturas devolver_lecturas();
};




#endif