#include "Bibliotecas/Sobrecargas.hpp"



int main() {
    struct Plato platos[13]{}; struct Repartidor repartidor[13]{}; struct Pedido pedido[30]{};

    ifstream inputP, inputR, inputO;
    abrir_archivo_entrada("ArchivosDeDatos/PlatosOfrecidos.csv", inputP);
    abrir_archivo_entrada("ArchivosDeDatos/RepartidoresContratados.csv", inputR);
    abrir_archivo_entrada("ArchivosDeDatos/OrdenesDeCompra.txt", inputO);

    ofstream outputP, outputR;
    abrir_archivo_salida("ArchivosDeReporte/prueba_platos.txt", outputP);
    abrir_archivo_salida("ArchivosDeReporte/prueba_repartidor.txt", outputR);

    for (int i = 0; i < 10; i++) {
        inputP >> platos[i];
        inputR >> repartidor[i];
    }
    strcpy(repartidor[10].codigo, "FIN");
    strcpy(platos[10].codigo, "FIN");
    for (int i = 0; i < 26; i++) {
        inputO >> pedido[i];
        cout<<(pedido[i]<=platos) << "  ";
        repartidor<=pedido[i];
    }
    for (int i = 0; i < 10; i++) {
        !repartidor[i];
        for (int j = 0; j < repartidor[i].cantidadDeOrdenes; j++) {
            !repartidor[i].ordenesDeCompra[j];
        }
    }

    for (int i = 0; i < 10; i++) {
        outputP << platos[i];
        outputR << repartidor[i];
    }

    return 0;
}
