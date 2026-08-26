//
// Created by alois on 25/8/26.
//

#include "Funciones.hpp"

#include <cstring>

void abrir_archivo_entrada(const char * file_name, ifstream & input) {
    input.open(file_name, ios::in);
    if(not input.is_open()) {
        cout << file_name << " no encontrado" << endl;
        exit(1);
    }
}

char * asignar_cadena(char * buffer) {
    char *cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char * leer_cadena( ifstream & input, char del) {
    char buffer[50]{};
    input.getline(buffer, 50, del);
    return asignar_cadena(buffer);
}

int leer_fecha( ifstream & input) {
    int aa, dd, mm;
    char c;
    input>>dd>>c>>mm>>c>>aa;
    return aa*10000 + mm*100 + dd;
}

