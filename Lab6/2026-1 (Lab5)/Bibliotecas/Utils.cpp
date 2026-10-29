//
// Created by alois on 27/10/26.
//

#include "Utils.hpp"

char * Utils::asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char * Utils::leer_cadena(ifstream &input, char del) {
    char buffer[50]{};
    input.getline(buffer, 50, del);
    return asignar_cadena(buffer);
}

void Utils::abrir_archivo(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if(!input.is_open()) {
        cout << "ya fue" << endl;
        exit(1);
    }
}

void Utils::abrir_archivo(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if(!output.is_open()) {
        cout << "ya fue" << endl;
        exit(1);
    }
}

void Utils::imprimir_fecha(ofstream &output, int fecha) {
    int aa, mm, dd;
    aa=fecha/10000;
    fecha=fecha%10000;
    mm=fecha/100;
    dd=fecha%100;

    output<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(2)<<aa<<setfill(' ');
}

void Utils::imprimir_linea(int n, char c, ofstream &output) {
    for(int i=0; i<n; i++) output.put(c);
    output.put('\n');
}
