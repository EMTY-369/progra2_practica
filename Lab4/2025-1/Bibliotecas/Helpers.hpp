//
// Created by User on 1/10/2026.
//

#ifndef INC_2025_1_HELPERS_HPP
#define INC_2025_1_HELPERS_HPP
#include "Utils.hpp"
void abrir_archivo_entrada(ifstream & input, const char *file_name);
void abrir_archivo_salida(ofstream &output, const char *file_name);
int leer_fecha(ifstream &input);
int leer_int(ifstream &input);
char * leer_cadena(ifstream &input, char del);
char * signar_cadena(char *buffer);
void imprimir_linea(int n, char c, ofstream &output);
void imprime_fecha(int fecha,ofstream &output);

#endif //INC_2025_1_HELPERS_HPP
