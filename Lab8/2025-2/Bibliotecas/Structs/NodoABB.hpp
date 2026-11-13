//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_NODOABB_HPP
#define INC_2025_2_NODOABB_HPP
#include "../Model/MetricaBasica.hpp"
#include "../Model/MetricaEngagement.hpp"
#include "../Model/MetricaCalidad.hpp"


class NodoABB {
public:
    friend class ArbolABB;

    NodoABB();
    NodoABB( Metrica *tipo, NodoABB *izq, NodoABB *der);
    ~NodoABB();
private:
    class NodoABB *izq;
    class NodoABB *der;
    class Metrica *metrica;
};


#endif //INC_2025_2_NODOABB_HPP
