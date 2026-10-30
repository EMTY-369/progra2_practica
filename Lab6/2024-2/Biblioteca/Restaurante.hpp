//
// Created by alois on 29/10/26.
//

#ifndef INC_2024_2_RESTAURANTE_HPP
#define INC_2024_2_RESTAURANTE_HPP
#include "Cliente.hpp"
#define ANCHO 170

class Restaurante {
private:
    class Cliente *clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    class Plato *platos;
    int cantidadDePlatos;
    int capacidadDePlatos;

public:
    Restaurante();
    ~Restaurante();

    void operator<(const char *file_name);
    void operator<=(const char *file_name);
    void operator<<=(const char *file_name);
    void operator>>(const char *file_name);

    void incrementar_clientes(int incremento);
    void incrementar_platos(int incremento);
    int buscar_cliente(int dni);
    void leer_actualizar_info(int pos_cliente, ifstream &input);
    int buscar_plato(char * plato);
    void imprimir_platos(ofstream & output);
    void imprimir_clientes(ofstream & output);
};


#endif //INC_2024_2_RESTAURANTE_HPP
