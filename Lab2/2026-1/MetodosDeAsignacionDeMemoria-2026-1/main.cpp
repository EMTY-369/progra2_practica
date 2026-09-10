#include "Bibliotecas/Funciones.hpp"


int main() {
    int *fechas{}, ***datosEnteros{};
    char ****datosDeTexto{};
    double ***datosDePuntoFlotante{};

    cargar_informacion("ArchivosDeDatos/ER_Final_Dataset_For_Students_Programacion_2.csv",
                       fechas, datosEnteros, datosDeTexto, datosDePuntoFlotante);
    completar_informacion(fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
    reporteDeAtenciones("ArchivosDeReporte/reporteFinalCSM.txt", fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);

    return 0;
}
