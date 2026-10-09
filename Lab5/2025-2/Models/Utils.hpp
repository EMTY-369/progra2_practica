//
// Created by User on 8/10/2026.
//

#ifndef INC_2025_2_UTILS_HPP
#define INC_2025_2_UTILS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MAX_CAD 100
#define MAX_S 205

class Utils{
    public:
    static void abrir_archivo(ifstream &input, const char *file_name);
    static void abrir_archivo(ofstream &output, const char *file_name);
    static char *leer_cadena(ifstream &input, char del);
    static char *asignar_cadena(const char *buffer);
};


#endif //INC_2025_2_UTILS_HPP
