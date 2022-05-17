#ifndef ESCRITOR_H_INCLUDED
#define ESCRITOR_H_INCLUDED

#include <string>
class Escritor{
private:
    std::string nombre_completo;
    std::string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;
    int referencia;
public:
    Escritor();
    Escritor(std::string nombre_completo, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int referencia);
   
    std::string obtener_nombre_completo();
    std::string obtener_nacionalidad();
    int obtener_anio_nacimiento();
    int obtener_anio_fallecimiento();
    int obtener_referencia();

    void mostrar();
};


#endif

