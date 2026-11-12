//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_METRICACALIDAD_HPP
#define INC_2025_2_METRICACALIDAD_HPP
#include "Metrica.hpp"

class MetricaCalidad : public Metrica {
public:
    int get_bitrate_promedio_kbps() const;
    void set_bitrate_promedio_kbps(const int bitrate_promedio_kbps);
    double get_porcentaje_frames_perdidos() const;
    void set_porcentaje_frames_perdidos(const double porcentaje_frames_perdidos);
    int get_fps_promedio() const;
    void set_fps_promedio(const int fps_promedio);

    void leer(ifstream &input) override;
    int obtenerTipoMetrica() override;
    void imprimir_encabezado(ofstream &output) override;
    void imprimir(ofstream &output) override;

    MetricaCalidad();
    MetricaCalidad(const MetricaCalidad &other);
    ~MetricaCalidad() override = default;
private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;
};


#endif //INC_2025_2_METRICACALIDAD_HPP
