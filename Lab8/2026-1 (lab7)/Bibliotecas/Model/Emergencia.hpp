//
// Created by User on 11/11/2026.
//

#ifndef INC_2026_1__LAB7__EMERGENCIA_HPP
#define INC_2026_1__LAB7__EMERGENCIA_HPP
#include "Atencion.hpp"

class Emergencia : public Atencion{
public:
    bool is_requiere_rcp() const;
    void set_requiere_rcp(const bool requiere_rcp);
    int get_minutos_sin_pulso() const;
    void set_minutos_sin_pulso(const int minutos_sin_pulso);

    int obtener_prioridad();
    Emergencia* clonar() const;
    void leer(ifstream &input, int hora);

    Emergencia();
    Emergencia(const class Emergencia &other);
    ~Emergencia()=default;
private:
    bool requiere_rcp;
    int minutos_sin_pulso;
};

#endif //INC_2026_1__LAB7__EMERGENCIA_HPP
