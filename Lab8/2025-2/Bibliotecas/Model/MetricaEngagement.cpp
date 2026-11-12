//
// Created by User on 12/11/2026.
//

#include "MetricaEngagement.hpp"

int MetricaEngagement::get_mensajes_chat() const {
    return mensajes_chat;
}

void MetricaEngagement::set_mensajes_chat(const int mensajes_chat) {
    this->mensajes_chat = mensajes_chat;
}

int MetricaEngagement::get_usuarios_unicos_chat() const {
    return usuarios_unicos_chat;
}

void MetricaEngagement::set_usuarios_unicos_chat(const int usuarios_unicos_chat) {
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEngagement::get_clips_generados() const {
    return clips_generados;
}

void MetricaEngagement::set_clips_generados(const int clips_generados) {
    this->clips_generados = clips_generados;
}

void MetricaEngagement::leer(ifstream &input) {
    Metrica::leer(input);

    input>>mensajes_chat;
    input.get();
    input>>usuarios_unicos_chat;
    input.get();
    input>>clips_generados;
    input.get();
}

int MetricaEngagement::obtenerTipoMetrica() {
    return 2;
}

void MetricaEngagement::imprimir_encabezado(ofstream &output) {
    output<<"[METRICAS ENGAGE]"<<endl;
    Metrica::imprimir_encabezado(output);
    output<<"Msgs"<<setw(12)<<"Chatters"<<setw(12)<<"Clips"<<endl;
}

void MetricaEngagement::imprimir(ofstream &output) {
    Metrica::imprimir(output);
    output<<setw(6)<<mensajes_chat<<setw(9)<<usuarios_unicos_chat<<setw(12)<<clips_generados<<endl;
}

MetricaEngagement::MetricaEngagement() {
    mensajes_chat = 0;
    usuarios_unicos_chat = 0;
    clips_generados = 0;
}

MetricaEngagement::MetricaEngagement(const MetricaEngagement &other)  : Metrica(other) {
    mensajes_chat = 0;
    usuarios_unicos_chat = 0;
    clips_generados = 0;
    *this = other;
}
