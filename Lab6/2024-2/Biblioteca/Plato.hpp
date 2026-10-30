//
// Created by alois on 29/10/26.
//

#ifndef INC_2024_2_PLATO_HPP
#define INC_2024_2_PLATO_HPP
#include "Utils.hpp"

class Plato {
private:
    char *codigo;
    char *nombre;
    double precio;
    char *categoria;
    int preparados;
    double descuento;
    int atendidos;
    int noAtentidos;
    double totalEsperado;
    double totalBruto;
    double totalNeto;

public:
    void get_codigo(char *codigo);
    void set_codigo(const char *codigo);
    void get_nombre(char *nombre);
    void set_nombre(const char *nombre);
    double get_precio() const;
    void set_precio(const double precio);
    void get_categoria(char *categoria);
    void set_categoria(const char *categoria);
    int get_preparados() const;
    void set_preparados(const int preparados);
    double get_descuento() const;
    void set_descuento(const double descuento);
    int get_atendidos() const;
    void set_atendidos(const int atendidos);
    int get_no_atentidos() const;
    void set_no_atentidos(const int no_atentidos);
    double get_total_esperado() const;
    void set_total_esperado(const double total_esperado);
    double get_total_bruto() const;
    void set_total_bruto(const double total_bruto);
    double get_tota_neto() const;
    void set_tota_neto(const double tota_neto);

    Plato();
    Plato(const class Plato &other);
    ~Plato();

    void operator=(const class Plato &other);

    void leer(ifstream & input);
    double actualizar(int cant, double desct_c);
    void imprimir(ofstream & output) const;
};

void operator>>(ifstream &input, class Plato &p);
void operator<<(ofstream &output, const class Plato &p);


#endif //INC_2024_2_PLATO_HPP
