//
// Created by alois on 28/10/26.
//

#ifndef INC_2025_1_EMPRESA_HPP
#define INC_2025_1_EMPRESA_HPP

#include "Multa.hpp"
#define NUM_PLACAS 10
#define NUM_MULTAS 100

class Empresa {
private:
    int dni;
    char *nombre;
    char *placas[NUM_PLACAS];
    int numPlacas;
    class Multa multas[NUM_MULTAS];
    int numMultas;
public:
    int get_dni() const;
    void set_dni(const int dni);
    void get_nombre(char *nombre);
    void set_nombre(const char *nombre);
    int get_num_placas() const;
    void set_num_placas(const int num_placas);
    int get_num_multas() const;
    void set_num_multas(const int num_multas);
    void get_placaI(char *placa, int i);
    void set_placaI(const char* placa, int i);

    void leer(ifstream & input);
    void imprimir_multas(ofstream & output);

    Empresa();
    ~Empresa();

    void operator=(Empresa &e);
    void operator+=(const class Multa &m);
};

void operator>>(ifstream &input,class Empresa &e);
void operator<<(ofstream &output,class Empresa &e);

#endif //INC_2025_1_EMPRESA_HPP
