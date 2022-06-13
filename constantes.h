#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED
using namespace std;
const char TIPO_NOVELA = 'N';
const char TIPO_CUENTO = 'C';
const char TIPO_POEMA = 'P';
const string NOVELA = "N";
const string CUENTO = "C";
const string POEMA = "P";
const string NOVELA_HISTORICA = "HISTORICA";
const string NACIONALIDAD_DESCONOCIDA = "¿?";
const string ANIO_NO_ENCONTRADO = "-1";
const string RUTA_ARCHIVO_ESCRITORES = "escritores.txt";
const string RUTA_ARCHIVO_LECTURAS = "lectura.txt";
const int ANIO_DESCONOCIDO = -1;
const int PRIMER_CARACTER = 0;
#define CARA_PENSATIVA "\U0001f914"
#define VERDE   "\033[32m"
#define BLANCO   "\033[37m"
#define MAGENTA "\033[35m"
#define AMARILLO  "\033[33m"


enum Generos{
    DRAMA = 1,
    COMEDIA,
    FICCION,
    SUSPENSO,
    TERROR,
    ROMANTICA, 
    HISTORICA,
};

enum Opciones{
    OPCION_1 = 1,
    OPCION_2,
    OPCION_3,
    OPCION_4,
    OPCION_5,
    OPCION_6,
    OPCION_7,
    OPCION_8,
    OPCION_9,
    OPCION_10,
    OPCION_11,
    OPCION_12,
    OPCION_13,
};

#endif