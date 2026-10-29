//
// Created by alois on 28/10/26.
//

#ifndef INC_2025_1_UTILS_HPP
#define INC_2025_1_UTILS_HPP
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#define MAX_CADENA 170

class Utils {
public:
    static void abrir_archivo(ifstream &input, const char *filename);
    static void abrir_archivo(ofstream &output, const char *filename);
    static char *asignar_cadena(const char *buffer);
    static char *leer_cadena(ifstream &input, char del);
    static void imprimir_fecha(ofstream &output, int fecha);
    static void imprimir_linea(int n, char c, ofstream &output);
};


#endif //INC_2025_1_UTILS_HPP
