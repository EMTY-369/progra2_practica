#include "Bibliotecas/Funciones.hpp"


int main() {
    void *pacientes;

    cargar_pacientes("ArchivosDeDatos/pacientes.csv", pacientes);
    cargar_visitas("ArchivosDeDatos/visitas.csv", pacientes);
    generar_reporte("ArchivosDeReporte/reporte.txt", pacientes);

    return 0;
}
