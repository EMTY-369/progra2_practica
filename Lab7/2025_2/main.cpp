#include "Bibliotecas/Model/GestorStreamers.hpp"

int main() {
    class GestorStreamers erick;
    erick.cargar_datos_streamers("ArchivosDeDatos/streamers.csv");
    erick.actualizar_datos_metricas("ArchivosDeDatos/metricas.csv");
    erick.generar_reportes();

    return 0;
}
