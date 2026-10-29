//
// Created by alois on 28/10/26.
//

#ifndef INC_2025_1_MULTA_HPP
#define INC_2025_1_MULTA_HPP
#include "Infraccion.hpp"

class Multa {
private:
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;
public:
    void get_placa(char *placa);
    void set_placa(const char *placa);
    int get_fecha_de_infraccion() const;
    void set_fecha_de_infraccion(const int fecha_de_infraccion);
    int get_fecha_de_pago() const;
    void set_fecha_de_pago(const int fecha_de_pago);
    int get_codigo_infraccion() const;
    void set_codigo_infraccion(const int codigo_ifraccion);
    double get_multa() const;
    void set_multa(const double multa);

    void leer(ifstream & input);

    Multa();
    Multa(const class Multa &other);
    ~Multa();

    void operator=(const class Multa &other);
};

void operator>>(ifstream &input, class Multa &m);
void operator<<(ofstream &output,class Multa &m);

#endif //INC_2025_1_MULTA_HPP
