#ifndef ESCRITOR_H_INCLUDED
#define ESCRITOR_H_INCLUDED
using namespace std;
#include <string>
#include "constantes.h"

class Escritor{
private:
    string nombre_completo;
    string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;
    string referencia;

public:
    void modificar_escritor();
    // Constructor
    Escritor(string nombre_completo, string nacionalidad, int anio_nacimiento, int anio_fallecimiento, string referencia);
    /*
    PRE: -
    POST: Muestra los atributos del Escritor.
    */
    void mostrar_atributos();
    /*
    PRE: -
    POST: Obtiene el año de nacimiento.
    */
    int obtener_anio_nacimiento();
    // Destructor
    ~Escritor(){};
    /*
    PRE: -
    POST: Obtiene el nombre completo del escritor.
    */
    string obtener_nombre_completo();
    /*
    PRE: -
    POST: Obtiene la referencia del escritor.
    */
    string obtener_referencia();
    /*
    PRE: anio_nuevo debe ser un número mayor a 0.
    POST: anio_fallecimiento pasa a ser anio_nuevo.
    */
    void modificar_anio_fallecimiento(int anio_nuevo);
};
#endif