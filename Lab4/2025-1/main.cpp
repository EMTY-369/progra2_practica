#include "Bibliotecas/BibliotecaGenerica.hpp"
#include "Bibliotecas/BibliotecaRegistros.hpp"
#include "Bibliotecas/BibliotecaEnteros.hpp"

int main(int argc, char** argv) {
    void *lista;

    crea_lista(lista, lee_num, clasifica_entero, "ArchivosDeDatos/numeros2.txt");
    imprime_lista(lista, imprime_num, "ArchivosDeReporte/Repnum.txt");

    crea_lista(lista, lee_registro, clasifica_resgistro, "ArchivosDeDatos/RegistroDeFaltas1.csv");
    imprime_lista(lista, imprime_registro, "ArchivosDeReporte/Repfalta.txt");
    return 0;
}
