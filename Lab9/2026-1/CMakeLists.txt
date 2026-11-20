cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(2026_1 main.cpp
        Bibliotecas/Utils/Utils.cpp
        Bibliotecas/Utils/Utils.hpp
        Bibliotecas/Models/Triaje.cpp
        Bibliotecas/Models/Triaje.hpp
        Bibliotecas/Models/Hora.cpp
        Bibliotecas/Models/Hora.hpp
        Bibliotecas/Models/Atencion.cpp
        Bibliotecas/Models/Atencion.hpp
        Bibliotecas/Models/SistemaDeAtencion.cpp
        Bibliotecas/Models/SistemaDeAtencion.hpp
        Bibliotecas/Models/Paciente.cpp
        Bibliotecas/Models/Paciente.hpp
        Bibliotecas/Models/Medico.cpp
        Bibliotecas/Models/Medico.hpp)
