//
// Created by User on 19/11/2026.
//

#include "Utils.hpp"

void Utils::abrir_archivo(ifstream &input, const string &file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}

void Utils::abrir_archivo(ofstream &output, const string &file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
}

void Utils::imprimir_linea(int n, char c, ofstream &output) {
    for (int i = 0; i < n; i++) output.put(c);
    output<<endl;
}

void Utils::imprimir_fecha(ofstream &output, int fecha) {
    int aa, mm, dd;
    aa = fecha/10000;
    fecha %= 10000;
    mm = fecha/100;
    dd = fecha%100;
    output<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(2)<<aa<<setfill(' ');
}
