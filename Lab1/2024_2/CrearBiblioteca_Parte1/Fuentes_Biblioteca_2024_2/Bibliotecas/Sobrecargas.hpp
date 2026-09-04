//
// Created by User on 3/09/2026.
//

#ifndef FUENTES_BIBLIOTECA_2024_2_SOBRECARGAS_HPP
#define FUENTES_BIBLIOTECA_2024_2_SOBRECARGAS_HPP
#include "Utils/FuncionesAuxiliares.hpp"
void operator>>(ifstream &, struct Plato &);
void operator>>(ifstream &, struct Repartidor &);
void operator>>(ifstream &, struct Pedido &);
bool operator<=(struct Pedido &, struct Plato *);
void operator<=(struct Repartidor *, struct Pedido &);
void operator!(struct OrdenDeCompra &);
void operator!(struct Repartidor &);
void operator<<(ofstream &, struct Plato &);
void operator<<(ofstream &, struct Repartidor &);

#endif //FUENTES_BIBLIOTECA_2024_2_SOBRECARGAS_HPP
