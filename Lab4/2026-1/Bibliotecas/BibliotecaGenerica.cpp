//
// Created by User on 30/09/2026.
//

#include "BibliotecaGenerica.hpp"

void imprimir_linea(int n, char c,ofstream &output) {
    for (int i = 0; i < n; i++) output.put(c);
    output.put('\n');
}

void imprime_lista(const void *lista, void(* imprime)(ofstream &, const void *), const char *file_name) {
    void **listaTAD = (void **)lista;
    void **recorrido = (void **)listaTAD[INICIO];
    ofstream output;
    abrir_archivo_salida(output, file_name);
    while (recorrido != nullptr) {
        imprime(output, recorrido[DATO]);
        recorrido = (void **)recorrido[SIGUIENTE];
    }
}

void fusiona_listas(void *&lista1, void *lista2, bool(* verifica)(const void*, const void*)) {
    void **listaTAD1 = (void **)lista1, **listaTAD2 = (void **)lista2;
    void **recorrido = (void **)listaTAD1[INICIO], **cabeza2 = (void **)listaTAD2[INICIO];
    void **aux = nullptr, *dato1, *dato2;

    while (listaTAD2[INICIO] != nullptr and recorrido != nullptr) {
        dato1 = recorrido[DATO];
        dato2 = cabeza2[DATO];
        if (verifica(dato1, dato2)) {
            listaTAD2[INICIO] = (void **)cabeza2[SIGUIENTE]; cabeza2[SIGUIENTE] = recorrido;
            if (aux == nullptr) {
                listaTAD1[INICIO] = cabeza2; aux = cabeza2;
            } else {
                aux[SIGUIENTE] = cabeza2; aux = (void **)aux[SIGUIENTE];
            }
            cabeza2 = (void **)listaTAD2[INICIO];
            *(int *)listaTAD1[LONGITUD] += 1; *(int *)listaTAD2[LONGITUD] -= 1;
        } else {
            aux = recorrido;
            recorrido = (void **)recorrido[SIGUIENTE];
        }
    }

    while (listaTAD2[INICIO] != nullptr) {
        listaTAD2[INICIO] = (void **)cabeza2[SIGUIENTE];
        aux[SIGUIENTE] = cabeza2;
        cabeza2[SIGUIENTE] = nullptr; cabeza2 = (void **)listaTAD2[INICIO];
        aux = (void **)aux[SIGUIENTE];
        *(int *)listaTAD1[LONGITUD] += 1;
    }
}

void inserta_lista(void *&lista, void **arr) {
    void **listaTAD = (void **)lista, **final=nullptr;

    for (int n = 0; arr[n]; n++) {
        void **nuevo_nodo = new void *[2]{};
        nuevo_nodo[DATO] = arr[n];
        nuevo_nodo[SIGUIENTE] = nullptr;

        if (listaTAD[INICIO]==nullptr) {
            listaTAD[INICIO] = nuevo_nodo;
        } else final[SIGUIENTE] = nuevo_nodo;
        final = nuevo_nodo;
        *(int *)listaTAD[LONGITUD] += 1;
    }
}

void crea_lista(void **arr,void *&lista, int (* cmp)(const void *,const void *) ) {
    int n;
    for (n = 0; arr[n]; n++) {}
    qsort(arr,n, sizeof (void *), cmp);
    genera_lista(lista);
    inserta_lista(lista, arr);
}

void procesa_arreglo(void **arr, void*(* lee)(ifstream &), const char *file_name) {
    ifstream input;
    abrir_archivo_entrada(input, file_name);
    int i=0;
    while (true) {
        void *dato = lee(input);
        if (input.eof()) break;
        arr[i] = dato;
        i++;
    }
}

void genera_lista(void *&lista) {
    void **listaTAD = new void *[2]{};
    int *ptr_long = new int;
    *ptr_long = 0;
    listaTAD[INICIO] = nullptr;
    listaTAD[LONGITUD] = ptr_long;
    lista = listaTAD;
}