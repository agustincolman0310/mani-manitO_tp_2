#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "escritor.h"
#include <string>

using namespace std;

const int OPCIONES_VALIDAS = 13;
const string PATH_CONTACTOS = "escritores.txt";
const int SALIR = 12;
//const int CANTIDAD_NUMEROS_EN_TELEFONO = 11;

//Precondiciones: -
//Postcondiciones: Carga la agenda con los datos del archivo de contactos
void cargar_escritores(Escritor* escritor);

//Precondiciones: -
//Postcondiciones: imprime por pantalla el menu
void mostrar_menu();

//Precondiciones: -
//Postcondiciones: Le solicita al usuario que ingrese el numero de la opcion que desea seleccionar
int pedir_opcion();


