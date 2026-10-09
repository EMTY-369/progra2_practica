//
// Created by User on 8/10/2026.
//

#include "Utils.hpp"

char* Utils::asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

char* Utils::leer_cadena(ifstream &input, char del) {
    char buffer[MAX_CAD]{};
    input.getline(buffer, MAX_CAD, del);
    return asignar_cadena(buffer);
}

void Utils::abrir_archivo(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo" << file_name << endl;
        exit(1);
    }
}

void Utils::abrir_archivo(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error al abrir archivo " << file_name << endl;
        exit(1);
    }
}