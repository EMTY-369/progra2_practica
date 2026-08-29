
#include "Bibliotecas/Funciones.hpp"



int main() {
    struct Mascota *arr_mascotas;
    struct Veterinario *arr_veterinarios;
    struct SistemaHuellitas *sistema;
    int n_mascotas=0, n_veterinarios=0;

    cargarDatos("ArchivosDeDatos/Mascotas.csv",
                "ArchivosDeDatos/Veterinarios.csv",
                arr_mascotas, arr_veterinarios,
                n_mascotas, n_veterinarios);
    //registrarAtenciones(sistema, );

    return 0;
}
