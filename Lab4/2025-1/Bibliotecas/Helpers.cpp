//
// Created by User on 1/10/2026.
//

#include "Helpers.hpp"
void imprime_fecha(int fecha,ofstream &output) {
    int aa, mm, dd;
    aa = fecha/10000;
    fecha %= 10000;
    mm = fecha/100;
    dd = fecha%100;
    output<<setfill('0')<<setw(2)<<aa<<"/"<<setw(2)<<mm<<"/"<<setw(2)<<dd<<setfill(' ');
}

void imprimir_linea(int n, char c, ofstream &output) {
    for (int i = 0; i < n; i++) output.put(c);
    output.put('\n');
}

char * signar_cadena(char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char * leer_cadena(ifstream &input, char del) {
    char buffer[MAX_CAD]{};
    input.get(buffer, MAX_CAD, del);
    return signar_cadena(buffer);
}

int leer_int(ifstream &input) {
    int dato;
    input>>dato;
    input.get();
    return dato;
}
int leer_fecha(ifstream &input) {
    int dd, mm, aa;
    dd = leer_int(input);
    mm = leer_int(input);
    aa = leer_int(input);
    return dd + mm*100 + aa*10000;
}

void abrir_archivo_salida(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "Error al abrir archivo_salida" << endl;
        exit(1);
    }
}

void abrir_archivo_entrada(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "Error al abrir el archivo de entrada" << endl;
        exit(1);
    }
}