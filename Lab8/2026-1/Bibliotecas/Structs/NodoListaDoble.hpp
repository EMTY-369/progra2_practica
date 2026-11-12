//
// Created by User on 11/11/2026.
//

#ifndef INC_2026_1_NODOLISTADOBLE_HPP
#define INC_2026_1_NODOLISTADOBLE_HPP
#include "Par.hpp"

class NodoListaDoble {
public:
    friend class ListaDoble;
    NodoListaDoble();
    ~NodoListaDoble();
private:
    class Par dato;
    class NodoListaDoble *anterior;
    class NodoListaDoble *siguiente;
};


#endif //INC_2026_1_NODOLISTADOBLE_HPP
