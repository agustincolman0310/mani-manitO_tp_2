# mani-manitas_tp_2

Integrantes:
-Cabaleiro, Ignacio
-Colman, Agustín
-Vazquez, Luciano



/*void cargar_lecturas(Lectura* lectura){
    
    fstream archivo_lecturas(PATH_LECTURA, ios::in);
    /*Poema* poema;
    Cuento* cuento;
    Novela* novela;
    Historica* historica; // no se si está bien
    if(!archivo_lecturas.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH_LECTURA << "\", se va a crear el archivo" << endl;
        archivo_lecturas.open(PATH_LECTURA, ios::out);
        archivo_lecturas.close();
        archivo_lecturas.open(PATH_LECTURA, ios::in);
    }   
    string titulo, minutos, anio_publicacion, tipo_lectura, genero, tema, libro, cant_versos, referencia_autor; 
    while(getline(archivo_lecturas, tipo_lectura)){
        getline(archivo_lecturas, titulo);
        getline(archivo_lecturas, minutos);
        getline(archivo_lecturas, anio_publicacion);
        if(tipo_lectura == "N"){
            getline(archivo_lecturas, genero);
            if(genero == "HISTORICA"){
                getline(archivo_lecturas, tema); 
            }
            novela -> genero = genero;
            //historica -> tema = tema;
        }
        else if(tipo_lectura == "C"){
            getline(archivo_lecturas, libro);  
        }
        else if(tipo_lectura == "P"){
            getline(archivo_lecturas, cant_versos);  
           // poema-> cant_versos = stoi(cant_versos);  
        }
        getline(archivo_lecturas, referencia_autor);
        
        
        lectura = new lectura;
    
        lectura -> tipo_lectura = tipo_lectura;
        lectura -> titulo = titulo;
        lectura -> minutos = stoi(minutos);
        lectura -> anio_publicacion = stoi(anio_publicacion);
        lectura -> escritor = stoi(referencia);
    }
    archivo_lecturas.close();
    
}*/