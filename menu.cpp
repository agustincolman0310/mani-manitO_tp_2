#include "menu.h"
using namespace std;

Cola cola;

Menu::Menu(Lista_Lecturas lecturas, Tabla_Hashing escritores){
    this->lecturas = lecturas;
    this->escritores = escritores;
}

int Menu::mostrar_menu(){
    int opcion = 0;
    cout<<"🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦\n";
    //cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"🟦\t-------------------|"<<VERDE "MENU"<<BLANCO"|-------------------                  🟦\n";
    cout<<"🟦\t["<<MAGENTA<<"1"<<BLANCO"] Agregar nueva lectura.                                    🟦\n"; 
    cout<<"🟦\t["<<MAGENTA<<"2"<<BLANCO"] Quitar una lectura.                                       🟦\n";     
    cout<<"🟦\t["<<MAGENTA<<"3"<<BLANCO"] Agregar escritor.                                         🟦\n";
    cout<<"🟦\t["<<MAGENTA<<"4"<<BLANCO"] Cambiar dato de un escritor.                              🟦\n";
    cout<<"🟦\t["<<MAGENTA<<"5"<<BLANCO"] Listar escritores.                                        🟦\n"; 
    cout<<"🟦\t["<<MAGENTA<<"6"<<BLANCO"] Sortear lecturas random.                                  🟦\n"; 
    cout<<"🟦\t["<<MAGENTA<<"7"<<BLANCO"] Listar todas las lecturas.                                🟦\n"; 
    cout<<"🟦\t["<<MAGENTA<<"8"<<BLANCO"] Listar lecturas entre años.                               🟦\n";
    cout<<"🟦\t["<<MAGENTA<<"9"<<BLANCO"] Listar lecturas por escritor.                             🟦\n";
    cout<<"🟦\t["<<MAGENTA<<"10"<<BLANCO"] Listar novelas por género.                               🟦\n";
    cout<<"🟦\t["<<MAGENTA<<"11"<<BLANCO"] Quitar lectura de menor tiempo.                          🟦\n";
    cout<<"🟦\t["<<MAGENTA<<"12"<<BLANCO"] Mostrar orden y tiempo mínimo en leer todas las lecturas.🟦\n";
    cout<<"🟦\t["<<MAGENTA<<"13"<<BLANCO"] Eliminar escritor.                                       🟦\n";
    cout<<"🟦\t["<<MAGENTA<<"14"<<BLANCO"] Salir.                                                   🟦\n";
    cout<<"🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦\n";
    cout<<"\t⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜\n";
    cout<<"\t⬜"<<AMARILLO<<" Ingrese una opción "<<BLANCO"⬜\n";
    cout<<"\t⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜\n";
    cout<<"\t▶️  ";
    cin>>opcion;
    return opcion;
}

void Menu::procesar_opciones(int opcion){ 
    switch(opcion){ 
        case OPCION_1:  
            agregar_lectura();
        break;
        case OPCION_2:
            eliminar_lectura();
        break;
        case OPCION_3:
            agregar_escritor();
        break;
        case OPCION_4:
            cambiar_dato_escritor();
        break;
        case OPCION_5:
            imprimir_escritores(); 
        break;
        case OPCION_6:
            sortear_lectura_random();
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
            baja_cola();
        break;
        case OPCION_12:
            mostrar_tiempo_minimo();
        break;
        case OPCION_13:
            eliminar_escritor();
        break;
    }
}
void Menu::validar_datos_lectura(char &tipo_lectura, string &titulo, string &referencia, int &minutos, int &anio_publicacion){
    int isni;
    cout<<"Ingrese el tipo de lectura ("<<MAGENTA<<"C"<<BLANCO" para cuento, "<<MAGENTA<< "P" <<BLANCO<< " para poema, "<< MAGENTA<< "N" <<BLANCO<< " para novela): \n";
    cin>>tipo_lectura;
    while(tipo_lectura!= TIPO_NOVELA && tipo_lectura != TIPO_POEMA && tipo_lectura != TIPO_CUENTO){
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

    cout << "Autores disponibles: " << endl;
    escritores.mostrar_referencias();
    cout<<"Ingrese el ISNI del autor: \n";
    cin >> isni;
    referencia = "(" + to_string(isni) + ")";
    
    cout<<"Ingrese la cantidad de minutos: \n";
    cin>>minutos;
    while(minutos < 1){
        cout<<"Ingrese una cantidad correcta de mínutos: \n";
        cin>>minutos;
    }

    cout<<"Ingrese el año publicacion: \n";
    cin>>anio_publicacion;
}

void Menu::agregar_lectura(){
    string titulo, referencia, genero, tema, titulo_libro, nuevo_nombre;
    char tipo_lectura;
    int minutos, anio_publicacion, cant_versos;
    Lectura* lectura;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    validar_datos_lectura(tipo_lectura, titulo, referencia, minutos, anio_publicacion);
    if (toupper(tipo_lectura) == TIPO_NOVELA){
        cout<< "Ingrese el genero: \n";
        cin>>genero;
        while(lecturas.convertir_en_mayuscula(genero) != "TERROR" && lecturas.convertir_en_mayuscula(genero) != "DRAMA" && lecturas.convertir_en_mayuscula(genero) != "COMEDIA" && lecturas.convertir_en_mayuscula(genero) != "FICCION" && lecturas.convertir_en_mayuscula(genero) != "SUSPENSO" && lecturas.convertir_en_mayuscula(genero) != "ROMANTICA" && lecturas.convertir_en_mayuscula(genero) != "HISTORICA"){
            cout<<"Ingrese un genero válido... \n";
            cin>>genero;
        }
        lectura = new Novela(tipo_lectura, titulo, minutos, anio_publicacion, escritores.consulta(referencia), lecturas.procesar_genero(lecturas.convertir_en_mayuscula(genero)));

        if(lecturas.convertir_en_mayuscula(genero) == NOVELA_HISTORICA){
            cout<< "Ingrese el tema: \n";
            cin>>tema;  
            lectura = new Historica(tipo_lectura, titulo, minutos, anio_publicacion, escritores.consulta(referencia), lecturas.procesar_genero(lecturas.convertir_en_mayuscula(genero)), const_cast<char*>(tema.c_str()));
            }
    }
    else if(toupper(tipo_lectura) == TIPO_CUENTO){
        cout<< "Ingrese el título del libro: \n";
        cin.ignore();
        getline(cin, titulo_libro);

        lectura = new Cuento(tipo_lectura, titulo, minutos, anio_publicacion,escritores.consulta(referencia) , titulo_libro);

    }
    else if(toupper(tipo_lectura) == TIPO_POEMA){
        cout<< "Ingrese la cantidad de versos: \n";
        cin>>cant_versos;
        lectura = new Poema(tipo_lectura, titulo, minutos, anio_publicacion, escritores.consulta(referencia), cant_versos);

    } 
    lecturas.alta(lectura);
}

void Menu::eliminar_lectura(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    string titulo;
    cout<< "Ingrese el título: \n";
    cin.ignore();
    getline(cin, titulo);
    while(lecturas.consulta_titulo(titulo) == NULL){
        cout<<"El título ingresado no existe \n";
        cout<< "Ingrese el titulo: \n";
        getline(cin, titulo);
    }
    lecturas.baja(titulo);
}

void Menu::agregar_escritor(){
    string nombre_completo, nacionalidad, referencia;
    int anio_nacimiento, anio_fallecimiento, isni;
    Escritor* escritor;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout << "Ingrese el número de ISNI (número de 4 digitos): \n" ;
    cin >> isni;
    referencia = "(" + to_string(isni) + ")";

    cout<<"Ingrese el nombre completo del escritor: \n";
    cin.ignore();
    getline(cin, nombre_completo);

    cout<<"Ingrese la nacionalidad del escritor: \n";
    cin>>nacionalidad;
    
    cout<<"Ingrese el año de nacimiento del escritor: \n";
    cin>>anio_nacimiento;

    cout<<"Ingrese el año de fallecimiento del escritor: \n";
    cin>>anio_fallecimiento;
    
    while(anio_nacimiento > anio_fallecimiento && anio_fallecimiento != -1){
        cout<<"¿Te parece que el año de fallecimiento sea menor al de nacimiento? "<<CARA_PENSATIVA<<endl;
        cout<<"Ingrese el año de fallecimiento del escritor: \n";
        cin>>anio_fallecimiento;
    }
    escritor = new Escritor(nombre_completo, nacionalidad, anio_nacimiento, anio_fallecimiento, referencia);
    escritores.insertar_escritor(escritor);
}

void Menu::cambiar_dato_escritor(){
    string referencia;
    int anio_fallecimiento, isni;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    escritores.mostrar_referencias();

    cout << "Ingresá el ISNI del escritor que queres modificar: \n";   
    cin >> isni;

    referencia = "("+ to_string(isni) + ")";

    cout<<"Ingrese la fecha de fallecimiento nueva: \n";
    cin>>anio_fallecimiento;
    
    Escritor* consulta = escritores.consulta(referencia);
    consulta->modificar_anio_fallecimiento(anio_fallecimiento);
}

void Menu::imprimir_escritores(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"\tImprimiendo... \n";
    cout<<"\n";
    escritores.mostrar_escritores();
}

void Menu::sortear_lectura_random(){
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

void Menu::baja_cola(){
    string respuesta;
    cargar_cola();
    
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    cout<<"¿Leyó "<< cola.consulta()->obtener_titulo() << " ? (Ingrese SI de haberla leído, NO de lo contrario.)"<<endl;
    cin>>respuesta;
    
    while(!cola.vacia() && respuesta != "NO"){

        if(respuesta == "SI"){
            cola.baja();
        }
        if(!cola.vacia()){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
            cout<<"¿Leyó "<< cola.consulta()->obtener_titulo() << " ? (Ingrese SI de haberla leído, NO de lo contrario.)"<<endl;
            cin>>respuesta;
        }
    }
    if(respuesta == "NO"){
        cout<<endl;
        cout << "Tus lecturas pendientes son... " << endl;
        cola.mostrar_cola();
    }
    cola.vaciar_cola();
}

void Menu::cargar_cola(){
    int minimo = 0;
    int cantidad = lecturas.obtener_cantidad();
    for(int i = 0; i < cantidad ; i++){
        cola.alta(lecturas.encontrar_lectura_menor(minimo));
    }
}

void Menu::vaciar_listas(){
    escritores.vaciar_tabla();
    lecturas.vaciar_lista();
}

void Menu::mostrar_tiempo_minimo(){
    Main_Kruskal kruskal(lecturas);
    kruskal.ejecutar_kruskal();
}

void Menu::eliminar_escritor(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    int isni;
    escritores.mostrar_referencias();
    cout<< "Ingrese el ISNI del escritor que quiere eliminar: \n";
    cin >> isni;
    lecturas.modificar_por_escritor(isni);
    escritores.eliminar_escritor(isni);
}