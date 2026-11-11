//
// Created by User on 5/11/2026.
//

#ifndef INC_2025_2_STREAMERGRATUITO_HPP
#define INC_2025_2_STREAMERGRATUITO_HPP
#include "Streamer.hpp"

class StreamerGratuito : public Streamer {
public:
    int get_fecha_fin_trial() const;
    void set_fecha_fin_trial(const int fecha_fin_trial);
    class MetricaBasica * get_metricas_basicas() const;
    void set_metricas_basicas(class MetricaBasica * const metricas_basicas);
    int get_cantidad_metricas_basicas() const;
    void set_cantidad_metricas_basicas(const int cantidad_metricas_basicas);

    void leer(ifstream &input);
    void imprimir_info(bool cond, ofstream &output, int &n_activas, int &n_expiradas);
    void imprimir(ofstream &output, int &n_activas, int &n_expiradas);
    void actualizar(const string &tipo,ifstream & input);

    StreamerGratuito();
    ~StreamerGratuito();
private:
    int fecha_fin_trial;
    class MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;
};


#endif //INC_2025_2_STREAMERGRATUITO_HPP
