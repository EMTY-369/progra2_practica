//
// Created by alois on 29/10/26.
//

#include "Utils.hpp"

void Utils::abrir_archivo(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout<<"Error al abrir el archivo de entrada"<<endl;
        exit(1);
    }
}

void Utils::abrir_archivo(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout<<"Error al abrir el archivo de salida"<<endl;
        exit(1);
    }
}

char * Utils::asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

char * Utils::leer_cadena(ifstream &input, char del) {
    char buffer[MAX_CAD]{};
    input.getline(buffer, MAX_CAD, del);
    return asignar_cadena(buffer);
}

void Utils::imprimir_linea(int n, char c, ofstream &output) {
    for (int i = 0; i < n; i++) output.put(c);
    output<<endl;
}
