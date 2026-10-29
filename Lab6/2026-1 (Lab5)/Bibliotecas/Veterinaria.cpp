//
// Created by alois on 28/10/26.
//

#include "Veterinaria.hpp"

Veterinaria::Veterinaria() {
    listaMascotas = nullptr;
    numMascotas = 0;
}

Veterinaria::~Veterinaria() {
    delete[] listaMascotas;
}

void Veterinaria::operator<=(const char *file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);
    this->listaMascotas = new Mascota[10]{};

    while (true) {
        class Mascota m;
        input >> m;
        if (input.eof()) break;
        listaMascotas[numMascotas++] = m;
    }
}

void Veterinaria::operator<<=(const char *file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        char nombreM[50]{};
        int dni, index;
        input.getline(nombreM, 50, ',');
        if (input.eof()) break;
        input >> dni;
        input.get();
        class VacunaAplicada v;
        input >> v;
        index = buscar_mascota(nombreM);
        if (index == -1) continue;
        listaMascotas[index] += v;
    }
}

void Veterinaria::operator<<(const char *file_name) {
    ofstream output;
    Utils::abrir_archivo(output, file_name);

    imprimir_encabezado(output);
    int dni;
    bool imprimir = true;
    for (int i = 0; i < numMascotas; i++) {
        if (i==0) dni = listaMascotas[i].get_dni();
        else {
            if (listaMascotas[i].get_dni() == dni) imprimir = false;
            else {
                Utils::imprimir_linea(ANCHO, '-',output);
                imprimir = true;
                dni = listaMascotas[i].get_dni();
            }
        }
        if (imprimir) output<<endl<<"DNI : "<<listaMascotas[i].get_dni()<<endl<<endl;
        output << listaMascotas[i];
        listaMascotas[i].imprimir_vacunas(output);
    }
}

int Veterinaria::buscar_mascota(const char *nombre) {

    for (int i = 0; i < numMascotas; i++) {
        char nombreM[40]{};
        listaMascotas[i].get_nombre(nombreM);
        if (strcmp(nombreM, nombre) == 0) return i;
    }
    return -1;
}

void Veterinaria::imprimir_encabezado(ofstream &output) {
    Utils::imprimir_linea(ANCHO,'=',output);
    output<<"REPORTE DE CARTILLAS - VETERINARIA HUELLITAS Y PLUMITAS"<<endl;
    Utils::imprimir_linea(ANCHO,'=',output);
}

