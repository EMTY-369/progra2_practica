//
// Created by User on 12/11/2026.
//

#include "ArbolABB.hpp"

void ArbolABB::insertar(class Metrica *tipo) {
    insertarRecursivo(raiz, tipo);
}

void ArbolABB::imprimir(ofstream &output, int &activas, int &expiradas) {
    int tipo = 0;
    imprimirEnOrdenRecursivo(raiz, activas, expiradas, tipo, output);
}

void ArbolABB::destruirArbol() {
    destruirRecursivo(raiz);
    raiz = nullptr;
}

void ArbolABB::eliminarNodosABB() {
    raiz = eliminarNodosABBRecursivo(raiz);
}

ArbolABB::ArbolABB() {
    raiz = nullptr;
}

ArbolABB::~ArbolABB() {
    destruirArbol();
}

void ArbolABB::insertarRecursivo(class NodoABB *&raiz, class Metrica *tipo) {
    if (raiz == nullptr) {
        auto *nuevo = new NodoABB(tipo, nullptr, nullptr);
        raiz = nuevo;
        return;
    } else {
        if (raiz->metrica->obtenerTipoMetrica()>tipo->obtenerTipoMetrica() or (raiz->metrica->obtenerTipoMetrica()==tipo->obtenerTipoMetrica()
            and raiz->metrica->get_id()>tipo->get_id())) {
            insertarRecursivo(raiz->izq, tipo);
        } else insertarRecursivo(raiz->der, tipo);
    }
}

void ArbolABB::imprimirEnOrdenRecursivo(class NodoABB *raiz, int &activas, int &expiradas, int &tipo, ofstream &output) {
    if (raiz != nullptr) {
        imprimirEnOrdenRecursivo(raiz->izq, activas, expiradas, tipo, output);

        int tipo_actual = raiz->metrica->obtenerTipoMetrica();
        if (tipo!=tipo_actual) {
            if (tipo != 0) Utils::imprimir_linea(ANCHO, '-', output);
            raiz->metrica->imprimir_encabezado(output);
            tipo = tipo_actual;
        }

        raiz->metrica->imprimir(output);
        if (raiz->metrica->is_estado()) activas++;
        else expiradas++;

        imprimirEnOrdenRecursivo(raiz->der, activas, expiradas, tipo, output);
    }
}

void ArbolABB::destruirRecursivo(class NodoABB *raiz) {
    if (raiz != nullptr) {
        destruirRecursivo(raiz->izq);
        destruirRecursivo(raiz->der);
        delete raiz;
    }
}

class NodoABB * ArbolABB::minimoArbol(class NodoABB *raiz) {
    if (raiz==nullptr or raiz->izq==nullptr) return raiz;
    else return minimoArbol(raiz->izq);
}

class NodoABB * ArbolABB::eliminarNodosABBRecursivo(class NodoABB *raiz) {
    if (raiz == nullptr) return raiz;
    raiz->izq=eliminarNodosABBRecursivo(raiz->izq);
    raiz->der=eliminarNodosABBRecursivo(raiz->der);

    if (raiz->metrica->is_estado()) {
        return raiz;
    } else {
        if (raiz->izq==nullptr) {
            class NodoABB *hijo = raiz->der;
            delete raiz;
            return hijo;
        } else if (raiz->der==nullptr) {
            class NodoABB *hijo = raiz->izq;
            delete raiz;
            raiz = hijo;
        } else {
            class NodoABB *minNodo = minimoArbol(raiz->der);
            class Metrica *aux = raiz->metrica;
            raiz->metrica = minNodo->metrica;
            minNodo->metrica = aux;
            raiz->der = eliminarNodosABBRecursivo(raiz->der);
        }
    }
    return raiz;
}
