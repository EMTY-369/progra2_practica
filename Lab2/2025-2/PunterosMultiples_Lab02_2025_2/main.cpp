#include "Bibliotecas/Funciones.hpp"


int main() {
    char ***categorias{};
    cargar_categorias("ArchivosDeDatos/categorias.csv", categorias);

    char ***streamers{};
    int **fechasPromedios{};
    long long **tiempoRepSeguidores{};
    cargar_streamers("ArchivosDeDatos/streamers.csv", streamers, fechasPromedios, tiempoRepSeguidores);

    char ***comentarios{};
    char ***etiquetas{};
    cargar_comentarios("ArchivosDeDatos/comentarios.csv", comentarios, etiquetas);

    imprimir_reporte("ArchivosDeReporte/Reporte.txt",
                     categorias, streamers, fechasPromedios, tiempoRepSeguidores, comentarios, etiquetas);

    return 0;
}
