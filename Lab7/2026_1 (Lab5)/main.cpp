#include "Bibliotecas/Model/Veterinaria.hpp"

int main() {
    class Veterinaria vet;

    vet.cargarcitas("ArchivosDeDatos/Atenciones.csv");
    vet.ordenar();
    vet.muestracitas("ArchivosDeReporte/Reporte.txt");

    return 0;
}
