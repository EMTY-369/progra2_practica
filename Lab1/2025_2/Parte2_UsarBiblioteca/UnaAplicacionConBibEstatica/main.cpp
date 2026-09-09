#include "Bibliotecas/Funciones.hpp"


int main() {
    struct Alumnos *arr_alumnos;
    struct Cursos *arr_cursos;
    int n_alumnos=0, n_cursos=0;

    cargar_alumnos("ArchivosDeDatos/Alumnos.csv",
                   arr_alumnos, n_alumnos);
    cargar_cursos("ArchivosDeDatos/Cursos.csv",
                  arr_cursos, n_cursos);
    cargar_matriculas("ArchivosDeDatos/Matricula.csv",
                      arr_cursos, arr_alumnos);
    actualizar_cursos(arr_cursos);
    imprimir_reporte("ArchivosDeReporte/reporte.txt",
                     arr_cursos);

    return 0;
}
