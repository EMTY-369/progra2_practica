#include "Funciones.hpp"

void *insertar_fila(struct Tabla &t) {
    void **fila, **lista_filas = static_cast<void **>(t.filas);
    t.cant_fil++;
    if (t.cant_fil >= t.cap_fil) incrementar_espacios(lista_filas, t.cant_fil, t.cap_fil, INC_FIL);
    fila = new void *[t.cant_col]{};
    lista_filas[t.cant_fil - 1] = fila;
    t.filas = lista_filas;
    return lista_filas[t.cant_fil - 1];
}

void incrementar_espacios(void ** &lista_col, int &cant_col, int &cap_col, int inc) {
    cap_col += inc;
    if (lista_col == nullptr) {
        lista_col = new void *[cap_col]{};
    } else {
        void **aux_col = new void *[cap_col]{};
        for (int i = 0; i < cant_col; i++) aux_col[i] = lista_col[i];
        delete [] lista_col;
        lista_col = aux_col;
    }
}

void insertar_columna(struct Tabla &t, void *col) {
    void **lista_col = static_cast<void **>(t.columnas);
    if (t.cant_col+1>=t.cap_col) incrementar_espacios(lista_col, t.cant_col, t.cap_col, INC_COL);
    lista_col[t.cant_col] = col;
    t.cant_col++;
    t.columnas = lista_col;
}

void inicializar_tabla(struct Tabla &t) {
    t.filas = nullptr;
    t.columnas = nullptr;
    t.cant_col = 0;
    t.cant_fil = 0;
    t.cap_col = 0;
    t.cap_fil = 0;
}