#include "Bibliotecas/BibliotecaGenerica.hpp"
#include "Bibliotecas/BibliotecaRegistros.hpp"
#include "Bibliotecas/BibliotecasEnteros.hpp"

int main() {
    void *arreglo1[MAX]{}, *arreglo2[MAX]{};
    void *lista1, *lista2;

    procesa_arreglo(arreglo1, lee_num, "ArchivosDeDatos/numeros1.txt");
    crea_lista(arreglo1, lista1, compara_num);
    procesa_arreglo(arreglo2, lee_num, "ArchivosDeDatos/numeros2.txt");
    crea_lista(arreglo2, lista2, compara_num);
    fusiona_listas(lista1, lista2, verifica_num);
    imprime_lista(lista1, imprime_num, "ArchivosDeReporte/Repnum.txt");

    procesa_arreglo(arreglo1, lee_registro, "ArchivosDeDatos/Atenciones1.csv");
    crea_lista(arreglo1, lista1, compara_reg);
    procesa_arreglo(arreglo2, lee_registro, "ArchivosDeDatos/Atenciones2.csv");
    crea_lista(arreglo2, lista2, compara_reg);
    fusiona_listas(lista1, lista2, verifica_reg);
    imprime_lista(lista1, imprime_registro, "ArchivosDeReporte/Repregistro.txt");

    return 0;
}
