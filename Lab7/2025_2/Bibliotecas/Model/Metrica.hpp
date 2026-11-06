//
// Created by User on 5/11/2026.
//

#ifndef INC_2025_2_METRICA_HPP
#define INC_2025_2_METRICA_HPP
#include "../Utils/Utils.hpp"


class Metrica {
public:
    int get_id() const;
    void set_id(const int id);
    string get_descripcion() const;
    void set_descripcion(const string &descripcion);
    int get_fecha_calculo() const;
    void set_fecha_calculo(const int fecha_calculo);
    int get_fecha_expiracion() const;
    void set_fecha_expiracion(const int fecha_expiracion);
    bool is_estado() const;
    void set_estado(const bool estado);

    void leer(ifstream &input);
    void imprimir(ofstream &output, bool cond) const;

    Metrica();
    Metrica(const class Metrica &origin);
    ~Metrica()=default;

private:
    int id;
    string descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;
};


#endif //INC_2025_2_METRICA_HPP
