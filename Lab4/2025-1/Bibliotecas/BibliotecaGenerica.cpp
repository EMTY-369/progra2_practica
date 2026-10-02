//
// Created by User on 1/10/2026.
//

#include "BibliotecaGenerica.hpp"


void imprime_lista(const void *lista, void (*imprime)(ofstream &, const void *), const char *file_name) {
    ofstream output;
    abrir_archivo_salida(output, file_name);
    void **listaTAD = (void **)lista;
    void **recorrido = (void **)listaTAD[INICIO1];
    while (recorrido != nullptr) {
        imprime(output, recorrido[DATO]);
        recorrido = (void **)recorrido[SIGUIENTE];
    }
}

void genera_lista(void *&lista) {
    void **listaTAD = new void *[2]{}, **nodo1 = new void *[2]{}, **nodo2 = new void *[2]{};
    listaTAD[INICIO1] = nodo1;
    listaTAD[INICIO2] = nodo2;
    nodo1[DATO] = nullptr;
    nodo1[SIGUIENTE] = listaTAD[INICIO2];
    nodo2[DATO] = nullptr;
    nodo2[SIGUIENTE] = nullptr;
    lista = listaTAD;
}

void insertar_lista(void *&lista, void *dato, void* (* clasifica)(void**, const void*)){
    void **listaTAD = (void **)lista;
    void **destino = (void **)clasifica(listaTAD, dato);
    if ((destino==listaTAD[INICIO1] or destino==listaTAD[INICIO2]) and destino[DATO]==nullptr) {
        destino[DATO] = dato;
        return;
    }

    void **nuevo_nodo = new void *[2]{};
    nuevo_nodo[DATO] = dato;
    nuevo_nodo[SIGUIENTE] = nullptr;

    while (destino[SIGUIENTE]!=nullptr and destino[SIGUIENTE]!=listaTAD[INICIO2])
        destino = (void **)destino[SIGUIENTE];
    nuevo_nodo[SIGUIENTE] = destino[SIGUIENTE];
    destino[SIGUIENTE] = nuevo_nodo;
}

void crea_lista(void *&lista, void* (* lee)(ifstream &), void* (* clasifica)(void**, const void*), const char *file_name) {
    ifstream input;
    abrir_archivo_entrada(input, file_name);
    genera_lista(lista);
    while (true) {
        void *dato = lee(input);
        if (input.eof()) break;
        insertar_lista(lista, dato, clasifica);
    }
}
