#include "Bibliotecas/Funciones.hpp"

void reporteDeAtenciones(const char *file_name, int * fechas, char **** datos_de_texto, int *** datos_enteros, double *** datos_de_punto_flotante);

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
