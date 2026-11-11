//
// Created by User on 11/11/2026.
//

#ifndef INC_2026_1__LAB7__URGENCIA_HPP
#define INC_2026_1__LAB7__URGENCIA_HPP
#include "Atencion.hpp"

class Urgencia : public Atencion {
public:
    string get_zona_lesion() const;
    void set_zona_lesion(const string &zona_lesion);
    bool is_necesita_rx() const;
    void set_necesita_rx(const bool necesita_rx);

    int obtener_prioridad();
    Urgencia *clonar() const;
    void leer(ifstream &input, int hora);

    Urgencia();
    Urgencia(const class Urgencia &other);
    ~Urgencia()=default;
private:
    string zona_lesion;
    bool necesita_rx;
};


#endif //INC_2026_1__LAB7__URGENCIA_HPP
