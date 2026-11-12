cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(2026_1 main.cpp
        Bibliotecas/Structs/Par.cpp
        Bibliotecas/Structs/Par.hpp
        Bibliotecas/Structs/NodoListaDoble.cpp
        Bibliotecas/Structs/NodoListaDoble.hpp
        Bibliotecas/Structs/ListaDoble.cpp
        Bibliotecas/Structs/ListaDoble.hpp
        Bibliotecas/Model/GestorAtenciones.hpp
        Bibliotecas/Model/Atencion.cpp
        Bibliotecas/Utils/Utils.cpp
        Bibliotecas/Model/GestorAtenciones.cpp
        Bibliotecas/Model/Emergencia.cpp
        Bibliotecas/Model/NoUrgencia.cpp
        Bibliotecas/Model/Urgencia.cpp)
