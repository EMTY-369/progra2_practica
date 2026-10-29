//
// Created by alois on 28/10/26.
//

#ifndef INC_2025_1_MINISTERIODETRANSPORTE_HPP
#define INC_2025_1_MINISTERIODETRANSPORTE_HPP
#include "Empresa.hpp"
#define NUM_INF 130
#define ANCHO 200

class MinisterioDeTransporte {
private:
    class Infraccion *infracciones;
    int numInf;
    class Empresa empresas[50];
    int numEmp;

public:
    MinisterioDeTransporte();
    ~MinisterioDeTransporte();

    void operator<(const char* file_name);
    void operator<=(const char* file_name);
    void operator<<=(const char* file_name);
    void operator>>(const char* file_name);

    int buscar_infraccion(int cod);
    int buscar_empresa(const char *placa);
    void imprimir_infracciones(ofstream & output);
    void imprimir_empresas(ofstream & output);
};


#endif //INC_2025_1_MINISTERIODETRANSPORTE_HPP
