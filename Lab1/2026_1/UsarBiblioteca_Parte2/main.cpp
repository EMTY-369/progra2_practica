
#include "Bibliotecas/Funciones.hpp"

int main() {
    struct SistemaHuellitas sistema{};

    cargarDatos("ArchivosDeDatos/Mascotas.csv",
                "ArchivosDeDatos/Veterinarios.csv",
                sistema.mascotas, sistema.veterinarios,
                sistema.numMascotas, sistema.numVeterinarios);
    registrarAtenciones("ArchivosDeDatos/Atenciones.csv",
                        sistema.atenciones, sistema.numAtenciones);

    int fecha_actural = 20251010;
    listaMascotasAEsterilizar(sistema.mascotas, sistema.numMascotas, fecha_actural,
                              "ArchivosDeReporte/ListaMascotasAEsterilizar.txt");

    imprimirMascotasConAtenciones(sistema, "ArchivosDeReporte/MascotasConAtenciones.txt");

    return 0;
}
