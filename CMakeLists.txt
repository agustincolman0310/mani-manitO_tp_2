cmake_minimum_required(VERSION 3.22)
project(mani_manitO_tp_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(mani_manitO_tp_2
        archivos.cpp
        archivos.h
        cola.cpp
        cola.h
        constantes.h
        cuento.cpp
        cuento.h
        escritor.cpp
        escritor.h
        historica.cpp
        historica.h
        lectura.cpp
        lectura.h
        lista.h
        lista_escritores.h
        lista_lecturas.h
        main.cpp
        menu.cpp
        nodo.h
        novela.cpp
        novela.h
        parser.cpp
        parser.h
        parser_ejemplo.cpp
        parser_ejemplo.h
        poema.cpp
        poema.h
        utiles.cpp
        utiles.h)
