//
// Created by User on 5/11/2026.
//

#ifndef INC_2025_2_METRICABASICA_HPP
#define INC_2025_2_METRICABASICA_HPP
#include "Metrica.hpp"

class MetricaBasica : public Metrica {
public:
    double get_horas_transmitidas() const;
    void set_horas_transmitidas(const double horas_transmitidas);
    int get_espectadores_promedio() const;
    void set_espectadores_promedio(const int espectadores_promedio);

    void leer(ifstream &input);
    void imprimir(ofstream &output);
    bool get_estado();

    MetricaBasica();
    MetricaBasica(const class MetricaBasica &origin);
    ~MetricaBasica()=default;

private:
    double horas_transmitidas;
    int espectadores_promedio;
};


#endif //INC_2025_2_METRICABASICA_HPP
