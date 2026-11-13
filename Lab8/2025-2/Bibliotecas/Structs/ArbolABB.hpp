//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_ARBOLABB_HPP
#define INC_2025_2_ARBOLABB_HPP
#include "NodoABB.hpp"

class ArbolABB {
public:
    void insertar(class Metrica *tipo);
    void imprimir(ofstream &output, int &activas, int &expiradas);
    void destruirArbol();
    void eliminarNodosABB();

    ArbolABB();
    ~ArbolABB();
private:
    void insertarRecursivo(class NodoABB *&raiz, class Metrica * tipo);
    void imprimirEnOrdenRecursivo(class NodoABB * raiz, int &activas, int &expiradas, int &tipo, ofstream &output);
    void destruirRecursivo(class NodoABB * raiz);
    class NodoABB * minimoArbol(class NodoABB * raiz);
    class NodoABB * eliminarNodosABBRecursivo(class NodoABB * raiz);

    class NodoABB *raiz;
};


#endif //INC_2025_2_ARBOLABB_HPP
