//
// Created by alois on 28/10/26.
//

#ifndef INC_2025_1_INFRACCION_HPP
#define INC_2025_1_INFRACCION_HPP
#include "Utils.hpp"

class Infraccion {
private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
public:
    int get_codigo() const;
    void set_codigo(const int codigo);
    void get_descripcion(char *descripcion);
    void set_descripcion(const char *descripcion);
    void get_gravedad(char *gravedad);
    void set_gravedad(const char *gravedad);
    double get_multa() const;
    void set_multa(const double multa);

    void leer(ifstream & input);

    Infraccion();
    Infraccion(const class Infraccion &other);
    ~Infraccion();

    void operator=(const class Infraccion &other);
};

void operator>>(ifstream &input,class Infraccion &i);
void operator<<(ofstream &output,class Infraccion &i);

#endif //INC_2025_1_INFRACCION_HPP
