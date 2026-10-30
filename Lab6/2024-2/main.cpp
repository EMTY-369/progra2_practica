#include "Biblioteca/Restaurante.hpp"

int main() {
    class Restaurante r;
    r<"ArchivosDeDatos/Clientes.csv";
    r<="ArchivosDeDatos/PlatosOfrecidos.csv";
    r<<="ArchivosDeDatos/Pedidos.csv";

    r>>"ArchivosDeReporte/ReporteDeVentasDelDia.txt";

    return 0;
}
