//
// Created by User on 30/09/2026.
//

#ifndef INC_2026_1_HELPERS_HPP
#define INC_2026_1_HELPERS_HPP
#include "Utils.hpp"
void abrir_archivo_entrada(ifstream &input, const char * file_name);
void abrir_archivo_salida(ofstream &output, const char *file_name);
int leer_fecha(ifstream & input);
int leer_int( ifstream & input);
char* leer_cadena(ifstream &input, char del);
char* asignar_cadena(char *buffer);
int leer_hora( ifstream & input);
void imprimir_linea(int n, char c,ofstream &output);
void imprimir_fecha(int fecha,ofstream &output);
void imprimir_hora(int time,ofstream &output);
#endif //INC_2026_1_HELPERS_HPP
