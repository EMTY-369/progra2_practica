#include "Bibliotecas/MinisterioDeTransporte.hpp"

int main() {
    class MinisterioDeTransporte m;

    m < "ArchivosDeDatos/TablaDeInfracciones.csv";
    m <= "ArchivosDeDatos/EmpresasRegistradas.csv";
    m <<= "ArchivosDeDatos/InfraccionesCometidas.csv";
    m >> "ArchivosDeReporte/ReporteParaElMinisterio.txt";
    return 0;
}
