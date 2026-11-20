//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_2_LAB8_ADAPTADO__UTILS_HPP
#define INC_2026_2_LAB8_ADAPTADO__UTILS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
using namespace std;
#define ANCHO 120


class Utils {
public:
    static void abrir_archivo(ifstream &input, const string &file_name);
    static void abrir_archivo(ofstream &output, const string &file_name);
};


#endif //INC_2026_2_LAB8_ADAPTADO__UTILS_HPP
