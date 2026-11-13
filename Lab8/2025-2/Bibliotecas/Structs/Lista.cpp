//
// Created by User on 12/11/2026.
//

#include "Lista.hpp"

void Lista::Destruir(class Nodo *recorrido) {
    if (recorrido == nullptr) return;
    else Destruir(recorrido->siguiente);

    class Nodo *eliminar = recorrido;
    if (recorrido->anterior == nullptr) listaDoblementeLigada = nullptr;
    delete eliminar;
}

void Lista::imprimir_recursivo(class Nodo *recorrido, int &activas, int &expiradas, int tipo, ofstream &output) {
    if (recorrido == nullptr) return;
    int tipo_actual = recorrido->metrica->obtenerTipoMetrica();
    if (tipo!=tipo_actual) {
        if (tipo != 0) Utils::imprimir_linea(ANCHO, '-', output);
        recorrido->metrica->imprimir_encabezado(output);
    }

    recorrido->metrica->imprimir(output);
    if (recorrido->metrica->is_estado()) activas++;
    else expiradas++;
    imprimir_recursivo(recorrido->siguiente, activas, expiradas, tipo_actual, output);
}

void Lista::eliminarNodosRecursivo(class Nodo *recorrido) {
    if (recorrido == nullptr) return;

    if (not recorrido->metrica->is_estado()) {
        class Nodo *eliminar = recorrido;

        if (recorrido != listaDoblementeLigada) recorrido->anterior->siguiente = recorrido->siguiente;
        else {
            if (listaDoblementeLigada->siguiente!=nullptr) listaDoblementeLigada = listaDoblementeLigada->siguiente;
            else listaDoblementeLigada = nullptr;
        }

        if (recorrido->siguiente != nullptr) recorrido->siguiente->anterior = recorrido->anterior;

        recorrido = recorrido->siguiente;
        delete eliminar;
        eliminarNodosRecursivo(recorrido);
    } else eliminarNodosRecursivo(recorrido->siguiente);
}

void Lista::insertar(class Metrica *tipo) {
    insertarRecursivo(listaDoblementeLigada, tipo);
}

void Lista::imprimir(int &activas, int &expiradas, ofstream &output) {
    imprimir_recursivo(listaDoblementeLigada, activas, expiradas,0, output);
}

void Lista::eliminarNodos() {
    eliminarNodosRecursivo(listaDoblementeLigada);
}

void Lista::eliminarLista() {
    Destruir(listaDoblementeLigada);
}

Lista::Lista() {
    listaDoblementeLigada = nullptr;
}

Lista::~Lista() {
    Destruir(listaDoblementeLigada);
}

void Lista::insertarRecursivo(class Nodo *recorrido, class Metrica *tipo) {
    if (recorrido!=nullptr and recorrido->siguiente!=nullptr and
        (recorrido->metrica->obtenerTipoMetrica()<tipo->obtenerTipoMetrica() or (recorrido->metrica->obtenerTipoMetrica()==tipo->obtenerTipoMetrica()
            and recorrido->metrica->get_descripcion()<tipo->get_descripcion()))) insertarRecursivo(recorrido->siguiente, tipo);
    else {
        auto *nuevo = new Nodo(tipo, nullptr, nullptr);
        if (recorrido == nullptr) listaDoblementeLigada = nuevo;
        else if (recorrido->metrica->obtenerTipoMetrica()<tipo->obtenerTipoMetrica() or (recorrido->metrica->obtenerTipoMetrica()==tipo->obtenerTipoMetrica()
            and recorrido->metrica->get_descripcion()<tipo->get_descripcion())) {
            recorrido->siguiente=nuevo;
            nuevo->anterior = recorrido;
        }
        else {
            nuevo->siguiente = recorrido;
            if (recorrido!=listaDoblementeLigada) {
                nuevo->anterior = recorrido->anterior;
                recorrido->anterior->siguiente = nuevo;
            } else listaDoblementeLigada = nuevo;
            recorrido->anterior = nuevo;
        }
    }
}
