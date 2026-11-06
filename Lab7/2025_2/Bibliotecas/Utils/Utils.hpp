//
// Created by User on 5/11/2026.
//

#ifndef INC_2025_2_UTILS_HPP
#define INC_2025_2_UTILS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#define ANCHO 120
#define INC 5
#define MAX_ELE 15
#define MAX_STREAMERS 70

class Utils {
public:
    static void abrir_archivo(ifstream &input, const string &file_name);
    static void abrir_archivo(ofstream &output, const string &file_name);
    static int leer_fecha(ifstream &input);
    static void imprimir_linea(int n, char c, ofstream &output);
};


#endif //INC_2025_2_UTILS_HPP
