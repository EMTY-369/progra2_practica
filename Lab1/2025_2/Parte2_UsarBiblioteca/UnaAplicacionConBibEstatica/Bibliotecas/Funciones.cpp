//
// Created by User on 2/09/2026.
//

#include "Funciones.hpp"

void imprimir_reporte(const char * file_name,const struct Cursos * cursos) {
    ofstream output;
    abrir_archivo_salida(file_name, output);
    int i = 0;
    while (cursos[i].codigo != nullptr) {
        output<<cursos[i];
        output<<endl;
        i++;
    }
    output.close();
}

void actualizar_cursos(struct Cursos * cursos) {
    int i=0;
    while (cursos[i].codigo != nullptr) {
        cursos[i]++;
        i++;
    }
}

void cargar_matriculas(const char *file_name, struct Cursos *cursos, struct Alumnos *alumnos) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);

    while (true) {
        struct Alumnos a{};
        struct Cursos c{};
        c.codigo = leer_cadena(input, ',');
        if (input.eof()) break;
        a.codigo = leer_int(input);
        int ubi_c, ubi_a;
        ubi_a = alumnos <= a;
        ubi_c = cursos >= c;
        if (ubi_a!=-1  and ubi_c!=-1) cursos[ubi_c] += alumnos[ubi_a];
    }

    input.close();
}

void cargar_cursos(const char * file_name, struct Cursos *& arr, int &n_cursos) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);
    arr = new struct Cursos[MAX_CURSOS]{};

    while (true) {
        struct Cursos c{};
        input>>c;
        if (input.eof()) break;
        arr[n_cursos] = c;
        n_cursos++;
    }

    input.close();
}

void cargar_alumnos(const char * file_name, struct Alumnos *& arr, int &n_alumnos) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);
    arr = new struct Alumnos[MAX_ALUMNOS]{};

    while (true) {
        struct Alumnos a{};
        input>>a;
        if (input.eof()) break;
        arr[n_alumnos] = a;
        n_alumnos++;
    }

    input.close();
}
