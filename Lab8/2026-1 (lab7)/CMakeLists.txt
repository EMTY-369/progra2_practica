cmake_minimum_required(VERSION 4.3)
project(2026_1__lab7_)

set(CMAKE_CXX_STANDARD 20)

add_executable(2026_1__lab7_ main.cpp
        Bibliotecas/Model/Atencion.cpp
        Bibliotecas/Model/Atencion.hpp
        Bibliotecas/Utils/Utils.cpp
        Bibliotecas/Utils/Utils.hpp
        Bibliotecas/Model/Emergencia.cpp
        Bibliotecas/Model/Emergencia.hpp
        Bibliotecas/Model/Urgencia.cpp
        Bibliotecas/Model/Urgencia.hpp
        Bibliotecas/Model/NoUrgencia.cpp
        Bibliotecas/Model/NoUrgencia.hpp
        Bibliotecas/Model/GestorAtenciones.cpp
        Bibliotecas/Model/GestorAtenciones.hpp)
