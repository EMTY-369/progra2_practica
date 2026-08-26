//
// Created by alois on 25/8/26.
//

#ifndef CREARBIBLIOTECA_PARTE1_FUNCIONES_HPP
#define CREARBIBLIOTECA_PARTE1_FUNCIONES_HPP
#include "Utils.hpp"
#include "../Estructuras/SistemaHuellitas.hpp"

void abrir_archivo_entrada(const char * file_name, ifstream & input);
char * leer_cadena( ifstream & input, char del);
char * asignar_cadena(char * buffer);
int leer_fecha( ifstream & input);


#endif //CREARBIBLIOTECA_PARTE1_FUNCIONES_HPP
