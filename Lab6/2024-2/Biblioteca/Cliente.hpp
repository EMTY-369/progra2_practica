//
// Created by alois on 29/10/26.
//

#ifndef INC_2024_2_CLIENTE_HPP
#define INC_2024_2_CLIENTE_HPP
#include "Plato.hpp"

class Cliente {
private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;
public:
    int get_dni() const;
    void set_dni(const int dni);
    void get_nombre(char *nombre);
    void set_nombre(const char *nombre);
    void get_distrito(char *distrito);
    void set_distrito(const char *distrito);
    double get_descuento() const;
    void set_descuento(const double descuento);
    double get_total_pagado() const;
    void set_total_pagado(const double total_pagado);

    Cliente();
    Cliente(const class Cliente &cliente);
    ~Cliente();

    void operator=(const class Cliente &other);

    void leer(ifstream &input);
    void actualizar(double gasto);
    void imprimir(ofstream &output) const;
};

void operator>>(ifstream &input, class Cliente &c);
void operator<<(ofstream &output,const class Cliente &c);

#endif //INC_2024_2_CLIENTE_HPP
