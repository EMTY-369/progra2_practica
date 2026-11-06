//
// Created by User on 5/11/2026.
//

#ifndef INC_2025_2_STREAMERPAGO_HPP
#define INC_2025_2_STREAMERPAGO_HPP
#include "Streamer.hpp"

class StreamerPago : public Streamer {
public:
    int get_fecha_inicio_plan() const;
    void set_fecha_inicio_plan(const int fecha_inicio_plan);
    class MetricaBasica * get_metricas_basicas() const;
    void set_metricas_basicas(class MetricaBasica * const metricas_basicas);
    int get_cantidad_metricas_basicas() const;
    void set_cantidad_metricas_basicas(const int cantidad_metricas_basicas);
    class MetricaEngagement * get_metricas_engagements() const;
    void set_metricas_engagements(class MetricaEngagement * const metricas_engagements);
    int get_cantidad_metricas_engagement() const;
    void set_cantidad_metricas_engagement(const int cantidad_metricas_engagement);
    class MetricaCalidad * get_metricas_calidades() const;
    void set_metricas_calidades(class MetricaCalidad * const metricas_calidades);
    int get_cantidad_metricas_calidades() const;
    void set_cantidad_metricas_calidades(const int cantidad_metricas_calidades);

    void leer(ifstream &input);
    void imprimir(ofstream &output);
    void actualizar(const string &tipo, ifstream & input);

    StreamerPago();
    ~StreamerPago();
private:
    int fecha_inicio_plan;
    class MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;
    class MetricaEngagement *metricas_engagements;
    int cantidad_metricas_engagement;
    class MetricaCalidad *metricas_calidades;
    int cantidad_metricas_calidades;
};


#endif //INC_2025_2_STREAMERPAGO_HPP
