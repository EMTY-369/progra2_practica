//
// Created by User on 12/11/2026.
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

    void leer(ifstream &input) override;
    int obtenerTipoMetrica() override;
    void imprimir_encabezado(ofstream &output) override;
    void imprimir(ofstream &output) const override;

    MetricaBasica();
    MetricaBasica(const MetricaBasica &other);
    ~MetricaBasica() override = default;
private:
    double horas_transmitidas;
    int espectadores_promedio;
};


#endif //INC_2025_2_METRICABASICA_HPP
