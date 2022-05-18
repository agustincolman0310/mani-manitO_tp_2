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
    Escritor(){};
    //Escritor(string nombre_completo, string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int referencia);
    
    void obtener_nombre_completo(string nombre_completo);
    void obtener_nacionalidad(string nacionalidad);
    void obtener_anio_nacimiento(int anio_nacimiento);
    void obtener_anio_fallecimiento(int anio_fallecimiento);
    void obtener_referencia(string referencia);
    string devolver_referencia();
    string devolver_nombre_completo();
    string devolver_nacionalidad();
    int devolver_anio_nacimiento();
    int devolver_anio_fallecimiento();
    void mostrar();
};


#endif