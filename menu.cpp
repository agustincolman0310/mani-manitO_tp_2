#include "menu.h"
using namespace std;


// Lista_Escritores escritores;
// Lista_Lecturas lecturas;
Cola cola;

Menu::Menu(Lista_Lecturas lecturas, Lista_Escritores escritores){
    this->lecturas = lecturas;
    this->escritores = escritores;
    // seguir_jugando = true;
    
}

int Menu::mostrar_menu(){
    int opcion = 0;
    cout<<"\t1- Agregar nueva lectura.\n"; 
    cout<<"\t2- Quitar una lectura.\n";     
    cout<<"\t3- Agregar escritor.\n"; ;
    cout<<"\t4- Cambiar dato de un escritor.\n";
    cout<<"\t5- Listar escritores.\n"; 
    cout<<"\t6- Sortear lecturas random.\n"; 
    cout<<"\t7- Listar todas las lecturas.\n"; 
    cout<<"\t8- Listar lecturas entre años.\n";
    cout<<"\t9- Listar lecturas por escritor.\n";
    cout<<"\t10- Listar novelas por género.\n";
    cout<<"\t11- Armar cola ordenada por tiempo de lectura.\n";
    cout<<"\t12- Salir.\n";
    cout<<"Ingrese una opción: ";
    cin>>opcion;
    return opcion;
}

void Menu::procesar_opciones(int opcion){ 
    string nombre_completo;
    switch(opcion){ 
        case OPCION_1:  
            agregar_lectura();
            break;
        case OPCION_2:
            eliminar_lectura();
            break;
        case OPCION_3:
            agregar_escritor(nombre_completo);
            break;
        case OPCION_4:
            cambiar_dato_escritor();
            break;
        case OPCION_5:
            imprimir_escritores(); 
            break;
        case OPCION_6:
            lectura_random();
            break;    
        case OPCION_7:
            imprimir_lecturas();
            break;
        case OPCION_8:
            listar_entre_anios();
            break;
        case OPCION_9:
            listar_por_escritor(); 
            break;
        case OPCION_10:
            listar_por_genero();
            break;
        case OPCION_11:
            cola_ordenada();
            break;
        case OPCION_12:
            salir();
            break;
    }
}

void Menu::agregar_lectura(){
    string titulo,nombre_completo,genero,tema,titulo_libro, nuevo_nombre;
    char tipo_lectura;
    int minutos,anio_publicacion,cant_versos;
    Lectura* lectura;
    cout<<"Ingrese el tipo de lectura: \n";
    cin>>tipo_lectura;
    
    cout<< "Ingrese el titulo: \n";
    cin.ignore();
    getline(cin, titulo);
    
    cout<<"Ingrese el nombre completo del escritor: \n";
    cin.ignore();
    getline(cin, nombre_completo);
    
    if(escritores.consulta(nombre_completo) == NULL){
        agregar_escritor(nuevo_nombre);
    }
    nombre_completo = nuevo_nombre;
    
    cout<<"Ingrese la cantidad de minutos: \n";
    cin>>minutos;

    cout<<"Ingrese el año publicacion: \n";
    cin>>anio_publicacion;

    if (tipo_lectura == NOVELA){
        cout<< "Ingrese el genero: \n";
        cin>>genero;
        lectura = new Novela(tipo_lectura, titulo, minutos, anio_publicacion, escritores.consulta(nombre_completo), genero);

            if(genero == "HISTORICA"){
            cout<< "Ingrese el tema: \n";
            cin>>tema;  
            lectura = new Historica(tipo_lectura, titulo, minutos, anio_publicacion, escritores.consulta(nombre_completo), genero, tema);

            }
    }
    else if(tipo_lectura == CUENTO){
        cout<< "Ingrese el titulo del libro: \n";
        cin.ignore();
        getline(cin, titulo_libro);

        lectura = new Cuento(tipo_lectura, titulo, minutos, anio_publicacion,escritores.consulta(nombre_completo) , titulo_libro);

    }
    else if(tipo_lectura == POEMA){
        cout<< "Ingrese la cantidad de versos: \n";
        cin>>cant_versos;
        lectura = new Poema(tipo_lectura, titulo, minutos, anio_publicacion, escritores.consulta(nombre_completo), cant_versos);

    } 
    lecturas.alta(lectura);
    lecturas.listar_lecturas();
}

void Menu::eliminar_lectura(){
    string titulo;
    cout<< "Ingrese el titulo: \n";
    cin.ignore();
    getline(cin, titulo);
    lecturas.baja(titulo);
    lecturas.listar_lecturas();
}

void Menu::agregar_escritor(string &nombre_completo){
    string nacionalidad, referencia, pasar_total;
    int anio_nacimiento, anio_fallecimiento, cant_total;
    Escritor* escritor;
    cout<<"Ingresa el nombre completo del escritor: \n";
    cin.ignore();
    getline(cin, nombre_completo);

    cout<<"Ingresa la nacionalidad del escritor: \n";
    cin>>nacionalidad;

    cout<<"Ingresa el año de nacimiento del escritor: \n";
    cin>>anio_nacimiento;

    cout<<"Ingresa el año de fallecimiento del escritor: \n";
    cin>>anio_fallecimiento;

    cant_total = escritores.obtener_cantidad() + 1;
    
    pasar_total = to_string(cant_total);
    referencia = "(" + pasar_total + ")";
    escritor = new Escritor(nombre_completo, nacionalidad, anio_nacimiento, anio_fallecimiento, referencia);
    escritores.agregar_final(escritor);
    escritores.listar_escritores();
}

void Menu::cambiar_dato_escritor(){
    string nombre_completo;
    int anio_fallecimiento;
    cout<<"Ingresa el nombre del escritor que queres modificar: \n";   
    cin.ignore();
    getline(cin, nombre_completo);
    
    cout<<"Ingrese la fecha de fallecimiento nueva: \n";
    cin>>anio_fallecimiento;
    escritores.modificar_anio_fallecimiento(nombre_completo,anio_fallecimiento);
    escritores.listar_escritores();
}

void Menu::imprimir_escritores(){
    escritores.listar_escritores();
}

void Menu::lectura_random(){
    int valor;
    srand((unsigned int)time(NULL));
    valor = 1 + rand() % lecturas.obtener_cantidad();
    cout<<"El numero random es: "<< valor<<endl;
    lecturas.sortear_lectura(valor);
}

void Menu::imprimir_lecturas(){
    lecturas.listar_lecturas();
}

void Menu::listar_entre_anios(){
    int anio_1, anio_2;
    cout<<"Ingresa desde: ";
    cin>>anio_1;
    cout<<"Hasta: ";
    cin>>anio_2;
    lecturas.listar_entre_anios(anio_1,anio_2);
}

void Menu::listar_por_escritor(){
    string nombre_completo;
    cout<<"Ingresa el nombre del escritor: \n";
    cin.ignore();
    getline(cin, nombre_completo);
    lecturas.listar_por_escritor(nombre_completo);
}

void Menu::listar_por_genero(){
    string genero;
    cout<<"Ingresa el genero: \n";
    cin>>genero;
    lecturas.listar_por_genero(genero);
}

void Menu::cola_ordenada(){
    int minimo = 0;
    for(int i = 0; i < lecturas.obtener_cantidad(); i++){
        cola.alta(lecturas.encontrar_lectura_menor(minimo));
    }
    cola.consulta()->mostrar();
    cola.baja();
    cout<<"Primera baja"<<endl;
    cola.consulta()->mostrar();
    cola.baja();
    cout<<"Segunda baja"<<endl;
    cola.consulta()->mostrar();
    cola.baja();
    cout<<"Tercera baja"<<endl;
}


bool Menu::salir(){
    return(seguir_jugando = false);
}

void Menu::vaciar_listas(){
    escritores.vaciar_lista();
    lecturas.vaciar_lista();
}
