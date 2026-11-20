//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_1_TRIAJE_HPP
#define INC_2026_1_TRIAJE_HPP
#include "../Utils/Utils.hpp"

class Triaje {
public:
    string get_codigo_triaje() const;
    void set_codigo_triaje(const string &codigo_triaje);
    string get_codigo_paciente() const;
    void set_codigo_paciente(const string &codigo_paciente);
    int get_frecuencia_cardiaca() const;
    void set_frecuencia_cardiaca(const int frecuencia_cardiaca);
    int get_presion_sistolica() const;
    void set_presion_sistolica(const int presion_sistolica);
    int get_presion_diastolica() const;
    void set_presion_diastolica(const int presion_diastolica);
    double get_temperatura() const;
    void set_temperatura(const double temperatura);
    int get_saturacion_de_oxigeno() const;
    void set_saturacion_de_oxigeno(const int saturacion_de_oxigeno);

    void leer(ifstream & input);
    void imprimir(ofstream & output) const;

    Triaje();
    Triaje(const class Triaje &other);
    ~Triaje() = default;
private:
    string codigoTriaje;
    string codigoPaciente;
    int frecuenciaCardiaca;
    int presionSistolica;
    int presionDiastolica;
    double temperatura;
    int saturacionDeOxigeno;
};

void operator>>(ifstream &input,class Triaje &t);
void operator<<(ofstream &output,const class Triaje &t);

#endif //INC_2026_1_TRIAJE_HPP
