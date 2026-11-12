//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_METRICAENGAGEMENT_HPP
#define INC_2025_2_METRICAENGAGEMENT_HPP
#include "Metrica.hpp"

class MetricaEngagement : public Metrica {
public:
    int get_mensajes_chat() const;
    void set_mensajes_chat(const int mensajes_chat);
    int get_usuarios_unicos_chat() const;
    void set_usuarios_unicos_chat(const int usuarios_unicos_chat);
    int get_clips_generados() const;
    void set_clips_generados(const int clips_generados);

    void leer(ifstream &input) override;
    int obtenerTipoMetrica() override;
    void imprimir_encabezado(ofstream &output) override;
    void imprimir(ofstream &output) override;

    MetricaEngagement();
    MetricaEngagement(const MetricaEngagement &other);
    ~MetricaEngagement() override = default;
private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
};


#endif //INC_2025_2_METRICAENGAGEMENT_HPP
