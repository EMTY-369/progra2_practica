//
// Created by alois on 27/10/26.
//

#ifndef INC_2026_1__LAB5__UTILS_HPP
#define INC_2026_1__LAB5__UTILS_HPP
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
#define ANCHO 70


class Utils {
public:
    static char *asignar_cadena(const char* buffer);
    static char *leer_cadena(ifstream &input, char del);
    static void abrir_archivo(ifstream &input, const char *file_name);
    static void abrir_archivo(ofstream &output, const char *file_name);
    static void imprimir_fecha(ofstream &output, int fecha);
    static void imprimir_linea(int n, char c, ofstream &output);
};


#endif //INC_2026_1__LAB5__UTILS_HPP
