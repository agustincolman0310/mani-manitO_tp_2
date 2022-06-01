#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class Menu{
private:
    bool seguir_jugando;
    
    void agregar_lectura();
    void eliminar_lectura();
    void agregar_escritor();
    void cambiar_dato_escritor();
    void imprimir_escritores();
    void lectura_random();
    void imprimir_lecturas();
    void listar_entre_anios();
    void listar_por_escritor();
    void listar_por_genero();
    void cola_ordenada();
    // void vaciar_listas();
    //bool salir();
    //void procesar_opciones(int opcion);

    
public:
    Menu();
    void procesar_opciones(int opcion);
    void vaciar_listas();

    ~Menu(){};
    int mostrar_menu();
    bool salir();
    
};



#endif