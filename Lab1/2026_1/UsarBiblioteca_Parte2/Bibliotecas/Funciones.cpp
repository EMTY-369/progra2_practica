//
// Created by alois on 28/8/26.
//

#include "Funciones.hpp"

void cargar_veterinarios(ifstream & input, struct Veterinario *&veterinarios, int &n_veterinarios) {
    while (true) {
        input >> veterinarios[n_veterinarios];
        if (input.eof()) break;
        n_veterinarios++;
    }
}

void cargar_mascotas(ifstream &input, struct Mascota *&mascotas, int &n_mascotas) {
    while (true) {
        input >> mascotas[n_mascotas];
        if (input.eof()) break;
        n_mascotas++;
    }
}


void cargarDatos(const char * file_mascota, const char * file_veterinario, struct Mascota *&arr_mascotas, struct Veterinario *&arr_veterinarios,
                 int &n_mascotas, int &n_veterinarios) {
    ifstream inputM, inputV;
    abrir_archivo_entrada(file_mascota, inputM);
    abrir_archivo_entrada(file_veterinario, inputV);

    arr_mascotas = new struct Mascota[MAX_MASCOTAS];
    arr_veterinarios = new struct Veterinario[MAX_VETERINARIOS];

    cargar_mascotas(inputM, arr_mascotas, n_mascotas);
    cargar_veterinarios(inputV, arr_veterinarios, n_veterinarios);
}
