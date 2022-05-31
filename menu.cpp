// #include <iostream>
// #include "lectura.h"
// #include "cuento.h"
// #include "novela.h"
// #include "poema.h"
// #include "historica.h"
// #include <string>
// #include "lista_lecturas.h"
// using namespace std;
/*

Lista_Escritores escritores;
Lista_Lecturas lecturas;
Cola cola;

int Menu::mostrar_menu(){
    int opcion = 0;
    cout<<"\t1- Agregar nueva lectura.\n"; //agregar_lectura();
    cout<<"\t2- Quitar una lectura.\n"; //quitar_lectura();
    cout<<"\t3- Agregar escritor.\n"; //agregar_escritor();
    cout<<"\t4- Cambiar dato de un escritor.\n"; //modificar_escritor()
    cout<<"\t5- Listar escritores.\n"; //listar_escritores();
    cout<<"\t6- Sortear lecturas random.\n"; //sortear_lectura();
    cout<<"\t7- Listar todas las lecturas.\n"; //listar_lecturas();
    cout<<"\t8- Listar lecturas entre años.\n"; //listar_lecturas_entre();
    cout<<"\t9- Listar lecturas por escritor.\n"; //listar_por_escritor();
    cout<<"\t10- Listar novelas por género.\n";//listar_novela_por_genero();
    cout<<"\t11- Armar cola ordenada por tiempo de lectura.\n";//ordenar_por_tiempo_lectura();
    cout<<"\t12- Salir.\n";
    
    //A partir de acá, otro procedimiento
    cout<<"Ingrese una opción: ";
    cin>>opcion;
    return opcion;

}


void Menu::procesar_opciones(int opcion){
    string titulo, tema, genero, titulo_libro, nombre_completo, referencia, nacionalidad,pasar_total;
    char tipo_lectura;
    int minutos, anio_publicacion, cant_versos, cant_total,anio_nacimiento,anio_fallecimiento, valor, anio_1, anio_2,minimo;
    Lectura* lectura;
    Escritor* escritor;
    switch(opcion){ 
        case 1:  
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5: 
            break;
        case 6:
            break;    
        case 7:
            break;
        case 8:
            break;
        case 9: 
            break;
        case 10:
            break;
        case 11:
            break;
    }
}
void Menu::agregar_lectura(){
    string titulo,nombre_completo,genero,tema,titulo_libro,tema;
    char tipo_lectura;
    int minutos,anio_publicacion,cant_versos;
    Lectura* lectura;
    cout<<"Ingrese el tipo de lectura: \n";
    cin>>tipo_lectura;
    
    cout<< "Ingrese el titulo: \n";
    cin.ignore();
    getline(cin, titulo);
    
    cout<<"Ingrese el nombre completo del escritor: \n";
    //cin.ignore();
    getline(cin, nombre_completo);

    cout<<"Ingrese la cantidad de minutos: \n";
    cin>>minutos;

    cout<<"Ingrese el año publicacion: \n";
    cin>>anio_publicacion;

    if (tipo_lectura == 'N'){
        cout<< "Ingrese el genero: \n";
        cin>>genero;
        lectura = new Novela(tipo_lectura, titulo, minutos, anio_publicacion, nombre_completo, genero);

            if(genero == "HISTORICA"){
            cout<< "Ingrese el tema: \n";
            cin>>tema;  
            lectura = new Historica(tipo_lectura, titulo, minutos, anio_publicacion, nombre_completo, genero, tema);

            }
    }
    else if(tipo_lectura == 'C'){
        cout<< "Ingrese el titulo del libro: \n";
        cin.ignore();
        getline(cin, titulo_libro);

        lectura = new Cuento(tipo_lectura, titulo, minutos, anio_publicacion, nombre_completo , titulo_libro);

    }
    else{
        cout<< "Ingrese la cantidad de versos: \n";
        cin>>cant_versos;
        lectura = new Poema(tipo_lectura, titulo, minutos, anio_publicacion, nombre_completo, cant_versos);
        // lecturas.insertar_ordenadamente(lectura);

    } 
    lecturas.alta(lectura);
    lecturas.listar_lecturas();
}

void Menu::eliminar_lectura(){
    string titulo;
    cout<< "Ingrese el titulo: \n";
    cin.ignore();
    getline(cin, titulo);
    lecturas.eliminar_por_titulo(titulo);
    lecturas.listar_lecturas();
}

void Menu::agregar_escritor(){
    string nombre_completo, nacionalidad;
    int anio_nacimiento, anio_fallecimiento;
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
    minimo = 0;
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


void Menu::salir(){
    sigo_jugando = false;
}

*/


