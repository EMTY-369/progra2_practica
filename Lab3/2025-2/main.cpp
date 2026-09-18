#include "Bibliotecas/Funciones.hpp"


int main() {
    void *streamers, *comentarios;

    cargar_streamers(streamers);
    cargar_comentarios(comentarios);
    actualizar_comentarios(streamers, comentarios);
    imprimir_streamers(streamers);

    return 0;
}
