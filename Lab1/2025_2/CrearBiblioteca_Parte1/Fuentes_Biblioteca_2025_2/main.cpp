#include "Bibliotecas/Sobrecargas.hpp"


int main() {
    struct Cursos cursos[7]{}; struct Alumnos alumnos[10]{};

    ifstream input1, input2, input3;
    abrir_archivo_entrada("ArchivosDeDatos/Cursos.csv", input1);
    abrir_archivo_entrada("ArchivosDeDatos/Alumnos.csv", input2);
    abrir_archivo_entrada("ArchivosDeDatos/Matricula.csv", input3);

    ofstream output;
    abrir_archivo_salida("ArchivosDeReporte/prueba.txt", output);

    for (int i = 0; i < 7; i++) {
        input1>>cursos[i];
    }
    for (int i = 0; i < 10; i++) {
        input2>>alumnos[i];
        cout<<left<<setw(16)<<alumnos[i].codigo<<setw(40)<<alumnos[i].nombre<<alumnos[i].tipo<<endl<<right;
    }

    for (int i = 0; i < 15; i++) {
        struct Alumnos a{};
        struct Cursos c{};
        int ubi_c, ubi_a;
        c.codigo = leer_cadena(input3, ',');
        a.codigo = leer_int(input3);
        ubi_c = cursos>=c;
        ubi_a = alumnos<=a;
        if (ubi_c!=-1 and ubi_a!=-1) cursos[ubi_c]+=alumnos[ubi_a];
    }

    for (int i = 0; i < 7; i++) {
        cursos[i]++;
        output<<cursos[i];
    }
    return 0;
}
