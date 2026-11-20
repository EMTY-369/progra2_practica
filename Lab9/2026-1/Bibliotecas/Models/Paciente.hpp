//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_1_PACIENTE_HPP
#define INC_2026_1_PACIENTE_HPP
#include "Atencion.hpp"

class Paciente {
public:
    string get_codigo() const;
    void set_codigo(const string &codigo);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    char get_sexo() const;
    void set_sexo(const char sexo);
    int get_edad() const;
    void set_edad(const int edad);
    double get_gastos_por_atencion() const;
    void set_gastos_por_atencion(const double gastos_por_atencion);

    void leer(ifstream & input);
    bool operator<(const class Paciente &other) const;
    void guardarAtencion(const Atencion &a, double tarifa);
    void imprimir(ofstream &output) const;

    Paciente();
    ~Paciente();
private:
    string codigo;
    string nombre;
    char sexo;
    int edad;
    list<class Atencion>atenciones;
    double gastosPorAtencion;
};

void operator>>(ifstream &input, class Paciente &p);
void operator<<(ofstream &output,const class Paciente &p);

#endif //INC_2026_1_PACIENTE_HPP
