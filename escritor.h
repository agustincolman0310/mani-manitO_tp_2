#ifndef ESCRITOR_H_INCLUDED
#define ESCRITOR_H_INCLUDED

#include <string>
class Escritor{
private:
    std::string nombre;
    std::string apellido;
    std::string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;
    int referencia;
public:
    Escritor();
    Escritor(std::string nombre, std::string apellido, std::string nacionalidad, int anio_nacimiento, int anio_fallecimiento, int referencia);
   
    std::string obtener_nombre();
    std::string obtener_apellido();
    std::string obtener_nacionalidad();
    int obtener_anio_nacimiento();
    int obtener_anio_falllecimiento();

    void mostrar();
};


#endif

