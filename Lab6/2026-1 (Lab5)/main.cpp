#include "Bibliotecas/Veterinaria.hpp"

int main() {
    class Veterinaria vt;
    vt <= "ArchivosDeDatos/mascotas.csv";
    vt <<= "ArchivosDeDatos/vacunasAplicadas.csv";
    vt << "ArchivosDeReporte/reporte.txt";
    return 0;
}
