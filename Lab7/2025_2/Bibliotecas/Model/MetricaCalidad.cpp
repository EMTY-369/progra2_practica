//
// Created by User on 5/11/2026.
//

#include "MetricaCalidad.hpp"

int MetricaCalidad::get_bitrate_promedio_kbps() const {
    return bitrate_promedio_kbps;
}

void MetricaCalidad::set_bitrate_promedio_kbps(const int bitrate_promedio_kbps) {
    this->bitrate_promedio_kbps = bitrate_promedio_kbps;
}

double MetricaCalidad::get_porcentaje_frames_perdidos() const {
    return porcentaje_frames_perdidos;
}

void MetricaCalidad::set_porcentaje_frames_perdidos(const double porcentaje_frames_perdidos) {
    this->porcentaje_frames_perdidos = porcentaje_frames_perdidos;
}

int MetricaCalidad::get_fps_promedio() const {
    return fps_promedio;
}

void MetricaCalidad::set_fps_promedio(const int fps_promedio) {
    this->fps_promedio = fps_promedio;
}

void MetricaCalidad::leer(ifstream &input) {
    Metrica::leer(input);
    input>>bitrate_promedio_kbps;
    input.get();
    input>>porcentaje_frames_perdidos;
    input.get();
    input>>fps_promedio;
    input.get();
}

MetricaCalidad::MetricaCalidad() {
    bitrate_promedio_kbps=0;
    porcentaje_frames_perdidos=0;
    fps_promedio=0;
}

MetricaCalidad::MetricaCalidad(const class MetricaCalidad &origin) {
    *this=origin;
}
