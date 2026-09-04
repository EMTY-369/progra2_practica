//
// Created by User on 2/09/2026.
//

#include "Fuciones.hpp"

void abrir_archivo_salida(const char * file_name, ofstream & output) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error al abrir el archivo de salida" << endl;
        exit(1);
    }
}

void abrir_archivo_entrada(const char * file_name, ifstream & input) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo de entrada" << endl;
        exit(1);
    }
}

char * asignar_cadena(char * origen) {
    char *cadena;
    cadena=new char[strlen(origen)+1];
    strcpy(cadena,origen);
    return cadena;
}


