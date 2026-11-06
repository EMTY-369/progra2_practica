//
// Created by User on 4/11/2026.
//

#include "Utils.hpp"

void Utils::abrir_archivo(ifstream &input, const string &file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout<<"Error opening: "<<file_name<<endl;
        exit(1);
    }
}

void Utils::abrir_archivo(ofstream &output, const string &file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout<<"Error opening: "<<file_name<<endl;
        exit(1);
    }
}

void Utils::imprimir_linea(int n, char c, ofstream &output) {
    for (int i=0; i<n; i++) output.put(c);
    output.put('\n');
}

void Utils::imprimir_fecha(int fecha, ofstream &output) {
    int dd, mm, aa;
    aa = fecha/10000;
    fecha %= 10000;
    mm = fecha/100;
    dd = fecha%100;

    output<<setfill('0')<<setw(2)<<aa<<"."<<setw(2)<<mm<<"."<<setw(2)<<dd<<setfill(' ');
}
