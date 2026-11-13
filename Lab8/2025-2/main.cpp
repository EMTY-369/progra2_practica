#include "Bibliotecas/Model/AdministrarMetricas.hpp"

int main() {
    class AdministrarMetricas kick;
    kick.cargarArchivo("ArchivosDeDatos/metricas.csv");
    kick.cargarArchivoArbolABB("ArchivosDeDatos/metricas.csv");
    kick.generarReporte("ArchivosDeReporte/reporte.txt");
    // kick.generarReporteArbolABB("ArchivosDeReporte/reporteArbolABB.txt");
    kick.eliminarNodos();
    kick.generarReporte("ArchivosDeReporte/reporteNodosEliminados.txt");
    kick.eliminarLista();
    return 0;
}
