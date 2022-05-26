#ifndef ESCRITOR_H_INCLUDED
#define ESCRITOR_H_INCLUDED
using namespace std;
#include <string>

class Escritor{
private:
    string nombre_completo;
    string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;
    string referencia;
public:
    
    Escritor(string nombre_completo, string nacionalidad, int anio_nacimiento, int anio_fallecimiento, string referencia);
    void mostrar_atributos();
    int obtener_anio_nacimiento();
    Escritor(){};
    string obtener_nombre_completo();
    string obtener_referencia();
    void modificar_anio_fallecimiento(int anio_nuevo);
    // void obtener_nombre_completo(string nombre_completo);
    // void obtener_nacionalidad(string nacionalidad);
    // void obtener_anio_nacimiento(int anio_nacimiento);
    // void obtener_anio_fallecimiento(int anio_fallecimiento);
    // void obtener_referencia(string referencia);
    // string devolver_referencia();
    // string devolver_nombre_completo();
    // string devolver_nacionalidad();
    // int devolver_anio_nacimiento();
    // int devolver_anio_fallecimiento();
    // void mostrar();
};
#endif