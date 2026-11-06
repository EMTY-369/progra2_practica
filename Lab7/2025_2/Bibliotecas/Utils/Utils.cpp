//
// Created by User on 5/11/2026.
//

#include "Utils.hpp"

void Utils::abrir_archivo(ifstream &input, const string &file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}

void Utils::abrir_archivo(ofstream &output, const string &file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}

int Utils::leer_fecha(ifstream &input) {
    int dd, mm, aa;
    char c;
    input>>aa>>c>>mm>>c>>dd;

    return aa*10000+mm*100+dd;
}

void Utils::imprimir_linea(int n, char c, ofstream &output) {
    for (int i = 0; i < n; i++) output.put(c);
    output.put('\n');
}