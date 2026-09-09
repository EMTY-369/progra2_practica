#include "Bibliotecas/Funciones.hpp"


int main() {
    int *fechas{}, ***datosEnteros{};
    char ****datosDeTexto{};
    double ***datosDePuntoFlotante{};

    cargar_informacion("ArchivosDeDatos/ER_Final_Dataset_For_Students_Programacion_2.csv",
                       fechas, datosEnteros, datosDeTexto, datosDePuntoFlotante);

    return 0;
}
