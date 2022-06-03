#include "menu.h"
using namespace std;

Cola cola;

Menu::Menu(Lista_Lecturas lecturas, Lista_Escritores escritores){
    this->lecturas = lecturas;
    this->escritores = escritores;
    // seguir_jugando = true; 
}

int Menu::mostrar_menu(){
    int opcion = 0;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"\t###########~MENU~########### \n";
    cout<<"\t[1] Agregar nueva lectura.\n"; 
    cout<<"\t[2] Quitar una lectura.\n";     
    cout<<"\t[3] Agregar escritor.\n"; ;
    cout<<"\t[4] Cambiar dato de un escritor.\n";
    cout<<"\t[5] Listar escritores.\n"; 
    cout<<"\t[6] Sortear lecturas random.\n"; 
    cout<<"\t[7] Listar todas las lecturas.\n"; 
    cout<<"\t[8] Listar lecturas entre años.\n";
    cout<<"\t[9] Listar lecturas por escritor.\n";
    cout<<"\t[10] Listar novelas por género.\n";
    cout<<"\t[11] Armar cola ordenada por tiempo de lectura.\n";
    cout<<"\t[12] Salir.\n";
    cout<<"\t###################### \n";
    cout<<"\t# Ingrese una opción # \n";
    cout<<"\t###################### \n";
    cout<<"\t->";
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
    }
}

void Menu::agregar_lectura(){
    string titulo,nombre_completo,genero,tema,titulo_libro,nuevo_nombre;
    char tipo_lectura;
    int minutos,anio_publicacion,cant_versos,numero_ingresado;
    Lectura* lectura;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"Ingrese el tipo de lectura (C para cuento, P para poema, N para novela): \n";
    cin>>tipo_lectura;
    while(tipo_lectura!= NOVELA && tipo_lectura != POEMA && tipo_lectura != CUENTO){
        cout<<"Juraria que no conozco ese tipo de lectura... "<<CARA_PENSATIVA<<endl;
        cout<<"Ingrese el tipo de lectura nuevamente: \n";
        cin>>tipo_lectura;
    }
    
    cout<< "Ingrese el titulo: \n";
    cin.ignore();
    getline(cin, titulo);
    while(lecturas.consulta_titulo(titulo) != NULL){
        cout<<"Me parece que ese titulo ya se uso!! \n";
        cout<<"Vuelva a ingresar un titulo no usado: \n";
        getline(cin, titulo);
    }
    
    cout<<"Ingrese el nombre completo del escritor: \n";
    //cin.ignore();
    getline(cin, nombre_completo);
    while(escritores.consulta(nombre_completo) == NULL){
        cout<<"Ese escritor no esta en nuestra base de datos... \n";
        cout<<"Si queres agregar un escritor nuevo pulse 1, si desea escribir el nombre de vuelta pulse 2 :\n";
        cin>>numero_ingresado;
        if(numero_ingresado == 1){
            agregar_escritor(nuevo_nombre);
            nombre_completo = nuevo_nombre;
        }
        else if(numero_ingresado == 2){
            cout<<"Ingrese el nombre completo del escritor: \n";
            cin.ignore();
            getline(cin, nombre_completo);
            cout<<nombre_completo;
        }
        else{
            cout<<"Andamos con poca comprension lectora... \n";
        }
    }
    // nombre_completo = nuevo_nombre;
    
    cout<<"Ingrese la cantidad de minutos: \n";
    cin>>minutos;
    while(minutos < 1){
        cout<<"Ingrese una cantidad correcta de minutos: \n";
        cin>>minutos;
    }

    cout<<"Ingrese el año publicacion: \n";
    cin>>anio_publicacion;

    if (toupper(tipo_lectura) == NOVELA){
        cout<< "Ingrese el genero: \n";
        cin>>genero;
        while(lecturas.convertir_en_mayuscula(genero) != "TERROR" && lecturas.convertir_en_mayuscula(genero) != "DRAMA" && lecturas.convertir_en_mayuscula(genero) != "COMEDIA" && lecturas.convertir_en_mayuscula(genero) != "FICCION" && lecturas.convertir_en_mayuscula(genero) != "SUSPENSO" && lecturas.convertir_en_mayuscula(genero) != "ROMANTICA" && lecturas.convertir_en_mayuscula(genero) != "HISTORICA"){
            cout<<"Ingrese un genero valido... \n";
            cin>>genero;
        }
        lectura = new Novela(tipo_lectura, titulo, minutos, anio_publicacion, escritores.consulta(nombre_completo), lecturas.procesar_genero(lecturas.convertir_en_mayuscula(genero)));

        if(lecturas.convertir_en_mayuscula(genero) == "HISTORICA"){
            cout<< "Ingrese el tema: \n";
            cin>>tema;  
            lectura = new Historica(tipo_lectura, titulo, minutos, anio_publicacion, escritores.consulta(nombre_completo), lecturas.procesar_genero(lecturas.convertir_en_mayuscula(genero)), tema);
            }
    }
    else if(toupper(tipo_lectura) == CUENTO){
        cout<< "Ingrese el titulo del libro: \n";
        cin.ignore();
        getline(cin, titulo_libro);

        lectura = new Cuento(tipo_lectura, titulo, minutos, anio_publicacion,escritores.consulta(nombre_completo) , titulo_libro);

    }
    else if(toupper(tipo_lectura) == POEMA){
        cout<< "Ingrese la cantidad de versos: \n";
        cin>>cant_versos;
        lectura = new Poema(tipo_lectura, titulo, minutos, anio_publicacion, escritores.consulta(nombre_completo), cant_versos);

    } 
    lecturas.alta(lectura);
}

void Menu::eliminar_lectura(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    string titulo;
    cout<< "Ingrese el titulo: \n";
    cin.ignore();
    getline(cin, titulo);
    while(lecturas.consulta_titulo(titulo) == NULL){
        cout<<"Me parece que ese titulo no existe!! \n";
        cout<< "Ingrese el titulo: \n";
        getline(cin, titulo);
    }
    lecturas.baja(titulo);
}

void Menu::agregar_escritor(string &nombre_completo){
    string nacionalidad, referencia, pasar_total;
    int anio_nacimiento, anio_fallecimiento, cant_total;
    Escritor* escritor;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"Ingresa el nombre completo del escritor: \n";
    cin.ignore();
    getline(cin, nombre_completo);

    while(escritores.consulta(nombre_completo) != NULL){
        cout<<"Este escritor ya se encuentra en su lista."<<endl;
        cout<<"Ingresa el nombre completo del escritor: \n";
        getline(cin, nombre_completo);
    }
    cout<<"Ingresa la nacionalidad del escritor: \n";
    cin>>nacionalidad;
    
    cout<<"Ingresa el año de nacimiento del escritor: \n";
    cin>>anio_nacimiento;

    cout<<"Ingresa el año de fallecimiento del escritor: \n";
    cin>>anio_fallecimiento;
    
    while(anio_nacimiento > anio_fallecimiento && anio_fallecimiento != -1){
        cout<<"¿Te parece que el año de fallecimiento sea menor al de nacimiento? "<<CARA_PENSATIVA<<endl;
        cout<<"Ingresa el año de fallecimiento del escritor: \n";
        cin>>anio_fallecimiento;
    }
    cant_total = escritores.obtener_cantidad() + 1;
    
    pasar_total = to_string(cant_total);
    referencia = "(" + pasar_total + ")";
    escritor = new Escritor(nombre_completo, nacionalidad, anio_nacimiento, anio_fallecimiento, referencia);
    escritores.alta(escritor);
}

void Menu::cambiar_dato_escritor(){
    string nombre_completo;
    int anio_fallecimiento;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"Ingresa el nombre completo del escritor que queres modificar: \n";   
    cin.ignore();
    getline(cin, nombre_completo);
    while(escritores.consulta(nombre_completo) == NULL){
        cout<<"Nombre no encontrado... \n";
        cout<<"Ingresa nuevamente el nombre completo del escritor que queres modificar: \n";   
        getline(cin, nombre_completo);
    }
    cout<<"Ingrese la fecha de fallecimiento nueva: \n";
    cin>>anio_fallecimiento;
    escritores.modificar_anio_fallecimiento(nombre_completo,anio_fallecimiento);
}

void Menu::imprimir_escritores(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"Imprimiendo... \n";
    escritores.listar_escritores();
}

void Menu::lectura_random(){
    int valor;
    srand((unsigned int)time(NULL));
    valor = 1 + rand() % lecturas.obtener_cantidad();
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"La lectura sorteada es la " <<valor<< "...\n";
    cout<<"Imprimiendo... \n";
    lecturas.sortear_lectura(valor);

}

void Menu::imprimir_lecturas(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"Imprimiendo... \n";
    lecturas.listar_lecturas();
}

void Menu::listar_entre_anios(){
    int anio_1, anio_2;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"Ingresa desde: ";
    cin>>anio_1;
    cout<<"Hasta: ";
    cin>>anio_2;
    while(anio_1 > anio_2){
        cout<<"El primer año ingresado debe ser mayor al segundo... \n";
        cout<<"Ingresa desde: ";
        cin>>anio_1;
        cout<<"Hasta: ";
        cin>>anio_2;
    }

    lecturas.listar_entre_anios(anio_1,anio_2);
}

void Menu::listar_por_escritor(){
    string nombre_completo;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"Ingresa el nombre del escritor: \n";
    cin.ignore();
    getline(cin, nombre_completo);
    lecturas.listar_por_escritor(nombre_completo);

}

void Menu::listar_por_genero(){
    string genero;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"Ingresa el genero: \n";
    cin>>genero;
    lecturas.procesar_genero(genero);
    lecturas.listar_por_genero(genero);
}

void Menu::cola_ordenada(){
    int minimo = 0;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
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

void Menu::vaciar_listas(){

    escritores.vaciar_lista();
    lecturas.vaciar_lista();
}
