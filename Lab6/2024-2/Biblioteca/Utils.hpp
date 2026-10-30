//
// Created by alois on 29/10/26.
//

#ifndef INC_2024_2_UTILS_HPP
#define INC_2024_2_UTILS_HPP
#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <cstring>

#define MAX_CAD 60

class Utils {
public:
     static void abrir_archivo(ifstream &input, const char *file_name);
     static void abrir_archivo(ofstream &output, const char *file_name);
     static char *asignar_cadena(const char *buffer);
     static char *leer_cadena(ifstream &input, char del);
     static void imprimir_linea(int n, char c, ofstream &output);
};


#endif //INC_2024_2_UTILS_HPP
