//
// Created by User on 5/11/2026.
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

    void leer(ifstream &input);
    void imprimir(ofstream &output);

    MetricaEngagement();
    MetricaEngagement(const class MetricaBasica &origin);
    ~MetricaEngagement()=default;
private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
};


#endif //INC_2025_2_METRICAENGAGEMENT_HPP
