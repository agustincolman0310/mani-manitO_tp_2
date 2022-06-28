#ifndef TABLA_HASHING_H_INCLUDED
#define TABLA_HASHING_H_INCLUDED

#include "lista_escritores.h"
#include "constantes.h"
#include "escritor.h"
int const TAMANIO = 25;

class Tabla_Hashing{

private:
    Lista_Escritores* escritores[TAMANIO];
public:
    Tabla_Hashing();
    ~Tabla_Hashing(){};
    void insertar_escritor(Escritor* escritor);
    void eliminar_escritor(string referencia);
    Escritor* consulta(string referencia);
    void mostrar_escritores();
    void vaciar_tabla();
    Escritor* consulta_escritor(string nombre_completo);
private:
    int hashing(int clave);
    int obtener_referencia(string referencia);
};





#endif