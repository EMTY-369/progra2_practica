#include "Bibliotecas/Funciones.hpp"


int main() {
    struct Tabla erick;

    cargar_tabla_infracciones(erick, "ArchivosDeDatos/infracciones.csv");
    recorrer_tabla(erick);

    return 0;
}
