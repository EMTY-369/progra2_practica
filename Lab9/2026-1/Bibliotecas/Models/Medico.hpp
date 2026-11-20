//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_1_MEDICO_HPP
#define INC_2026_1_MEDICO_HPP
#include "Atencion.hpp"

class Medico {
public:
    int get_codigo() const;
    void set_codigo(const int codigo);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    double get_tarifa() const;
    void set_tarifa(const double tarifa);
    string get_especialidad_nombre() const;
    void set_especialidad_nombre(const string &especialidad_nombre);
    double get_pagos_por_atencion() const;
    void set_pagos_por_atencion(const double pagos_por_atencion);

    void leer(ifstream &input);
    bool operator<(const class Medico &other) const;
    void guardarAtencion(const Atencion &a);
    void imprimir(ofstream & output) const;

    Medico();
    ~Medico();
private:
    int codigo;
    string nombre;
    double tarifa;
    string especialidadNombre;
    vector<class Atencion> atenciones;
    double pagosPorAtencion;
};

void operator>>(ifstream &input,class Medico &m);
void operator<<(ofstream &output,const class Medico &m);

#endif //INC_2026_1_MEDICO_HPP
