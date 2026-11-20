cmake_minimum_required(VERSION 4.3)
project(2026_2_lab8_adaptado_)

set(CMAKE_CXX_STANDARD 20)

add_executable(2026_2_lab8_adaptado_ main.cpp
        Bibliotecas/Utils/Utils.cpp
        Bibliotecas/Model/StandardPackage.cpp
        Bibliotecas/Model/RefrigeratePackage.cpp
        Bibliotecas/Model/Product.cpp
        Bibliotecas/Model/PackageManager.cpp
        Bibliotecas/Model/Package.cpp)
