//
// Created by User on 11/11/2026.
//

#ifndef INC_2026_1__LAB7__UTILS_HPP
#define INC_2026_1__LAB7__UTILS_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
#define INC 5
#define ANCHO 150

class Utils {
public:
    static void abrir_archivo(const string &file_name, ifstream &input);
    static void abrir_archivo(const string &file_name, ofstream &output);
    static void imprimir_linea(int n, char c, ofstream &output);
};


#endif //INC_2026_1__LAB7__UTILS_HPP
