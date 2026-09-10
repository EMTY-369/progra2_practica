//
// Created by User on 10/09/2026.
//

#include "Funciones.hpp"

void abrir_archivo_entrada(const char *filename, ifstream &input) {
    input.open(filename, ios::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo de entrada" << endl;
        exit(1);
    }
}