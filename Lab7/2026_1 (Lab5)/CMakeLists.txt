cmake_minimum_required(VERSION 4.3)
project(2026_1__Lab5_)

set(CMAKE_CXX_STANDARD 20)

add_executable(2026_1__Lab5_ main.cpp
        Bibliotecas/Utils/Utils.cpp
        Bibliotecas/Utils/Utils.hpp
        Bibliotecas/Model/Mascota.cpp
        Bibliotecas/Model/Mascota.hpp
        Bibliotecas/Model/Cita.cpp
        Bibliotecas/Model/Cita.hpp
        Bibliotecas/Model/Control.cpp
        Bibliotecas/Model/Control.hpp
        Bibliotecas/Model/Operacion.cpp
        Bibliotecas/Model/Operacion.hpp
        Bibliotecas/Model/Vacuna.cpp
        Bibliotecas/Model/Vacuna.hpp
        Bibliotecas/Model/Veterinaria.cpp
        Bibliotecas/Model/Veterinaria.hpp)
