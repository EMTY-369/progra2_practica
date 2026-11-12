//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_UTILS_HPP
#define INC_2025_2_UTILS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
#define ANCHO 130
#define FECHA_ACTUAL 20251112

class Utils {
public:
    static void abrir_archivo(ifstream &input, const string &file_name);
    static void abrir_archivo(ofstream &output, const string &file_name);
    static int leer_fecha(ifstream &input);
    static void imprimir_linea(int n, char c, ofstream &output);
};


#endif //INC_2025_2_UTILS_HPP
