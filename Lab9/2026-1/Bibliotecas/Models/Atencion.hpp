//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_1_ATENCION_HPP
#define INC_2026_1_ATENCION_HPP
#include "Triaje.hpp"
#include "Hora.hpp"

class Atencion {
public:
    int get_codigo_medico() const;
    void set_codigo_medico(const int codigo_medico);
    string get_codigo_triaje() const;
    void set_codigo_triaje(const string &codigo_triaje);
    class Hora get_duracion() const;
    void set_duracion(const class Hora &duracion);
    class Triaje get_triaje() const;
    void set_triaje(const class Triaje &triaje);
    int get_fecha() const;
    void set_fecha(const int fecha);
    string get_codigo_paciente() const;
    void set_codigo_paciente(const string &codigo_paciente);
    class Hora get_hora_ingreso() const;
    void set_hora_ingreso(const class Hora &hora_ingreso);
    class Hora get_hora_alta() const;
    void set_hora_alta(const class Hora &hora_alta);

    void leer(ifstream &input);
    bool operator<(const class Atencion &other) const;
    void calcularDuracion();
    void imprimir(ofstream & output) const;

    Atencion();
    ~Atencion() = default;
private:
    int fecha;
    string codigoPaciente;
    class Hora horaIngreso;
    class Hora horaAlta;
    int codigoMedico;
    string codigoTriaje;
    class Hora duracion;
    class Triaje triaje;
};

void operator>>(ifstream &input,class Atencion &a);
void operator<<(ofstream &output,const class Atencion &a);

#endif //INC_2026_1_ATENCION_HPP
