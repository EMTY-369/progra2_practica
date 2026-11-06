//
// Created by User on 5/11/2026.
//

#ifndef INC_2025_2_METRICACALIDAD_HPP
#define INC_2025_2_METRICACALIDAD_HPP
#include "Metrica.hpp"

class MetricaCalidad : public Metrica{
public:
    int get_bitrate_promedio_kbps() const;
    void set_bitrate_promedio_kbps(const int bitrate_promedio_kbps);
    double get_porcentaje_frames_perdidos() const;
    void set_porcentaje_frames_perdidos(const double porcentaje_frames_perdidos);
    int get_fps_promedio() const;
    void set_fps_promedio(const int fps_promedio);

    void leer(ifstream &input);
    void imprimir(ofstream &output);

    MetricaCalidad();
    MetricaCalidad(const class MetricaCalidad &origin);
    ~MetricaCalidad()=default;
private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;
};


#endif //INC_2025_2_METRICACALIDAD_HPP
