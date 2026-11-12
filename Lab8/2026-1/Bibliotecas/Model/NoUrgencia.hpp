//
// Created by User on 11/11/2026.
//

#ifndef INC_2026_1__LAB7__NOURGENCIA_HPP
#define INC_2026_1__LAB7__NOURGENCIA_HPP
#include "Atencion.hpp"

class NoUrgencia : public Atencion {
public:
    string get_especialidad() const;
    void set_especialidad(const string &especialidad);
    bool is_es_consulta_programada() const;
    void set_es_consulta_programada(const bool es_consulta_programada);

    int obtener_prioridad();
    int obtener_llave();
    NoUrgencia * clonar() const;
    void leer(ifstream &input, int hora);
    void imprimir(ofstream &output);
    NoUrgencia();
    NoUrgencia(const class NoUrgencia &other);
    ~NoUrgencia();
private:
    string especialidad;
    bool es_consulta_programada;
};


#endif //INC_2026_1__LAB7__NOURGENCIA_HPP
