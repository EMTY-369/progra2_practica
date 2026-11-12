//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_LISTA_HPP
#define INC_2025_2_LISTA_HPP
#include "Nodo.hpp"

class Lista {
public:
    void insertar(class Metrica *tipo);
    void imprimir(int &activas, int &expiradas, ofstream &output);
    void eliminarNodos();
    void eliminarLista();

    Lista();
    ~Lista();
private:
    void insertarRecursivo(class Nodo *recorrido, class Metrica *tipo);
    void Destruir(class Nodo *recorrido);
    void imprimir_recursivo(class Nodo *recorrido, int &activas, int &expiradas,int tipo, ofstream & output);
    void eliminarNodosRecursivo(class Nodo * recorrido);

    class Nodo *listaDoblementeLigada;
};


#endif //INC_2025_2_LISTA_HPP
