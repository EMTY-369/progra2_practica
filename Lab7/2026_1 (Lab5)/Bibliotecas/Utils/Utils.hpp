//
// Created by User on 4/11/2026.
//

#ifndef INC_2026_1__LAB5__UTILS_HPP
#define INC_2026_1__LAB5__UTILS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#define MAX_ELE 30
#define MAX_STR 30
#define ANCHO   90

class Utils {
public:
    static void abrir_archivo(ifstream &input, const string &file_name);
    static void abrir_archivo(ofstream &output, const string &file_name);
    static void imprimir_linea(int n, char c,ofstream & output);
    static void imprimir_fecha(int fecha, ofstream & output);
};


#endif //INC_2026_1__LAB5__UTILS_HPP
